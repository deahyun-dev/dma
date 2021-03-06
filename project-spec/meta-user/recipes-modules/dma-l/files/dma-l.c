/*  dma-l.c - The simplest kernel module.

* Copyright (C) 2013 - 2016 Xilinx, Inc
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.

*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License along
*   with this program. If not, see <http://www.gnu.org/licenses/>.

*/

#define DMA_H

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/io.h>
#include <linux/interrupt.h>

#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>

#include <linux/dma-mapping.h>
#include <asm/page.h>
// #include <kernel/dma/direct.h>

/********************************************************************************************************/

//header files
#include <linux/uaccess.h> // copy_from_user
#include <linux/miscdevice.h> // for user interface with fops
#include <linux/fs.h> // for file_operation
#include <asm/io.h> //iowrite, ioread
#include "my_emul.h"

/********************************************************************************************************/

/* Standard module information, edit as appropriate */
MODULE_LICENSE("GPL");
MODULE_AUTHOR
    ("Xilinx Inc.");
MODULE_DESCRIPTION
    ("dma-l - loadable module template generated by petalinux-create -t modules");

#define DRIVER_NAME "dma-l"
#define DEVICE_NAME "dma" //* put device name(IP name)
/********************************************************************************************************/

void __iomem* base_addr; //virtual address
UINTPTR dma_addr;
UINTPTR dma_virt_addr;
dma_addr_t dma_phy_addr;

typedef struct{
    //* parameters
    u32 addr;
    u32 val;
    int offset;
}__attribute__((packed)) DMA_param;



typedef u32 XAxiDma_Bd[16U];

typedef struct {
	UINTPTR ChanBase;		/**< physical base address*/

	int IsRxChannel;	/**< Is this a receive channel */
	volatile int RunState;	/**< Whether channel is running */
	int HasStsCntrlStrm; 	/**< Whether has stscntrl stream */
	int HasDRE;
	int DataWidth;
	int Addr_ext;
	u32 MaxTransferLen;

	UINTPTR FirstBdPhysAddr;	/**< Physical address of 1st BD in list */
	UINTPTR FirstBdAddr;	/**< Virtual address of 1st BD in list */
	UINTPTR LastBdAddr;		/**< Virtual address of last BD in the list */
	u32 Length;		/**< Total size of ring in bytes */
	UINTPTR Separation;		/**< Number of bytes between the starting
				     address of adjacent BDs */
	XAxiDma_Bd *FreeHead;	/**< First BD in the free group */
	XAxiDma_Bd *PreHead;	/**< First BD in the pre-work group */
	XAxiDma_Bd *HwHead;	/**< First BD in the work group */
	XAxiDma_Bd *HwTail;	/**< Last BD in the work group */
	XAxiDma_Bd *PostHead;	/**< First BD in the post-work group */
	XAxiDma_Bd *BdaRestart;	/**< BD to load when channel is started */
	XAxiDma_Bd *CyclicBd;	/**< Useful for Cyclic DMA operations */
	int FreeCnt;		/**< Number of allocatable BDs in free group */
	int PreCnt;		/**< Number of BDs in pre-work group */
	int HwCnt;		/**< Number of BDs in work group */
	int PostCnt;		/**< Number of BDs in post-work group */
	int AllCnt;		/**< Total Number of BDs for channel */
	int RingIndex;		/**< Ring Index */
	int Cyclic;		/**< Check for cyclic DMA Mode */
} XAxiDma_BdRing;

typedef struct XAxiDma {
	UINTPTR RegBase;		/* Virtual base address of DMA engine */

	int HasMm2S;		/* Has transmit channel */
	int HasS2Mm;		/* Has receive channel */
	int Initialized;	/* Driver has been initialized */
	int HasSg;

	XAxiDma_BdRing TxBdRing;     /* BD container management for TX channel */
	XAxiDma_BdRing RxBdRing[16]; /* BD container management for RX channel */
	int TxNumChannels;
	int RxNumChannels;
	int MicroDmaMode;
	int AddrWidth;		  /**< Address Width */
} XAxiDma;

DMA_param param; //* paramters & file discripter
XAxiDma Inst;
XAxiDma *InstPtr = &Inst;
// emulation

//file operation

#define BUF_SIZE 100
ssize_t cur_len;     // 현재 버퍼에 저장된 데이터 크기

int dma_l_open(struct inode *inode, struct file *filp){
    // printk(KERN_ALERT "dma_l_device open function called\n");
    return 0;
}

int dma_l_release(struct inode *inode, struct file *filp){
    // printk(KERN_ALERT "dma_l_device release function called\n");
    return 0;
}

ssize_t dma_l_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos) {
    printk(KERN_ALERT "dma_l_device write function called\n");
    ssize_t retval;
 
    if(count > BUF_SIZE){ //buffer size check. BUF_SIZE 100
        retval = -ENOMEM;
        goto out;
    }
 
    cur_len = retval = count;

    char kernel_buffer[BUF_SIZE];
    printk("check1\n");
    // 사용자가 전달한 데이터를 버퍼에 저장.
    if(copy_from_user(kernel_buffer, buf, retval)){ // buf : userspace에서 넘긴 val_str, kernel_buffer : kernel space buffer
        retval = -EFAULT;
        goto out;
    }
    printk("check2\n");
    

    printk("receive data from user : %s", kernel_buffer);

    unsigned long value = simple_strtoul(kernel_buffer, NULL, 10); // str to unsined long conversion
    

    //dma_l_set_register(base_addr, 0, value); // device control by driver function
 
    printk("drv_buffer_write: [%dbyte -> %dbyte]\n", count, retval);
 
out:
    return retval;

}

ssize_t dma_l_read(struct file *filp, char *buf, size_t count, loff_t *f_pos) {
    printk("dma_l_device read function called\n");    
    return count;
}

long dma_l_unlocked_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){

	int ret;
	

    switch(cmd){
		case DMA_In32:
            // printk("ioread\n");
            ret = copy_from_user((void*)&param, (void*)arg, sizeof(param));
			param.val = Xil_In32(param.addr);
			ret = copy_to_user((void*)arg, (void*)&param, sizeof(param));
            break;	
        
		case DMA_Out32:
            // printk("iowrite\n");
            ret = copy_from_user((void*)&param, (void*)arg, sizeof(param));
			Xil_Out32(param.addr, param.val);
            break;

        case DMA_BASE_ADDR:
            ret = copy_from_user((void*)InstPtr, (void*)arg, sizeof(param));

            InstPtr->RegBase = base_addr;
			
            ret = copy_to_user((void*)arg, (void*)InstPtr, sizeof(param));
            break;

        case DMA_ALLOC_BUF:
            ret = copy_from_user((void*)&param, (void*)arg, sizeof(param));
			param.addr = dma_virt_addr;
            param.val = (u32)dma_phy_addr;
            ret = copy_to_user((void*)arg, (void*)&param, sizeof(param));

            break;

        case DMA_BD_WRITE:
            ret = copy_from_user((void*)&param, (void*)arg, sizeof(param));
            dma_addr = param.addr;
			*(dma_addr) = (u32)param.val; 
            break;

        case DMA_BD_READ:
            ret = copy_from_user((void*)&param, (void*)arg, sizeof(param));
            dma_addr = param.addr;
			param.val = (u32)(*dma_addr);
            ret = copy_to_user((void*)arg, (void*)&param, sizeof(param));
            break;

        default:
            printk("DMA default\n");
            break;
    }
    return 0;
}

static struct file_operations dma_l_fops ={ // system call
    .open = dma_l_open,
    .release = dma_l_release,
    .read = dma_l_read,   //dummy
    .write = dma_l_write, //for test
    .unlocked_ioctl = dma_l_unlocked_ioctl, //ioctl로 모든 driver function mapping
};

// misc device structure
 static struct miscdevice dma_l_miscdev = {
    .minor      = MISC_DYNAMIC_MINOR,   //부번호 동적할당
    .name       = DEVICE_NAME,    // device file name -> /dev/dma_l
    .fops       = &dma_l_fops, // system call for user space
};

/********************************************************************************************************/
unsigned myint = 0xdeadbeef;
char *mystr = "default";

module_param(myint, int, S_IRUGO);
module_param(mystr, charp, S_IRUGO);

struct dma_l_local {
    int irq;
    unsigned long mem_start;
    unsigned long mem_end;
    void __iomem *base_addr;
};

static irqreturn_t dma_l_irq(int irq, void *lp)
{
    printk("dma-l interrupt\n");
    return IRQ_HANDLED;
}

static int dma_l_probe(struct platform_device *pdev)
{
    struct resource *r_irq; /* Interrupt resources */
    struct resource *r_mem; /* IO mem resources */
    struct device *dev = &pdev->dev;
    struct dma_l_local *lp = NULL;

    int rc = 0;
    dev_info(dev, "Device Tree Probing\n");
    /* Get iospace for the device */
    r_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    if (!r_mem) {
        dev_err(dev, "invalid address\n");
        return -ENODEV;
    }
    lp = (struct dma_l_local *) kmalloc(sizeof(struct dma_l_local), GFP_KERNEL);
    if (!lp) {
        dev_err(dev, "Cound not allocate dma-l device\n");
        return -ENOMEM;
    }
    dev_set_drvdata(dev, lp);
    lp->mem_start = r_mem->start;
    lp->mem_end = r_mem->end;

    if (!request_mem_region(lp->mem_start,
                lp->mem_end - lp->mem_start + 1,
                DRIVER_NAME)) {
        dev_err(dev, "Couldn't lock memory region at %p\n",
            (void *)lp->mem_start);
        rc = -EBUSY;
        goto error1;
    }

    lp->base_addr = ioremap(lp->mem_start, (lp->mem_end - lp->mem_start + 1)); // lp->base_addr : virtual address
    base_addr = lp->base_addr;

    if (!lp->base_addr) {
        dev_err(dev, "dma-l: Could not allocate iomem\n");
        rc = -EIO;
        goto error2;
    }

    /********************************************************************************************************/

    //misc device registration for user space
    int ret = 0;
    ret = misc_register(&dma_l_miscdev); // misc device 등록. 플랫폼 디바이스 등록과는 independant. fops를 userspace에 넘겨주기 위한 key
                                          // user는 생성된 /dev/dma_l file을 열고 file_operation을 통해 driver 함수 사용 가능
    if (ret){
        printk("misc_register() failed");
        return -1;
    }

    /********************************************************************************************************/


    /* Get IRQ for the device */
    r_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
    if (!r_irq) {
        dev_info(dev, "no IRQ found\n");
        dev_info(dev, "dma-l at 0x%08x mapped to 0x%08x\n",
            (unsigned int __force)lp->mem_start,
            (unsigned int __force)lp->base_addr);
        return 0;
    }
    lp->irq = r_irq->start;
    rc = request_irq(lp->irq, &dma_l_irq, 0, DRIVER_NAME, lp);
    if (rc) {
        dev_err(dev, "testmodule: Could not allocate interrupt %d.\n",
            lp->irq);
        goto error3;
    }

    dev_info(dev,"dma-l at 0x%08x mapped to 0x%08x, irq=%d\n",
        (unsigned int __force)lp->mem_start,
        (unsigned int __force)lp->base_addr,
        lp->irq);

        dma_virt_addr = dma_alloc_coherent(dev, DMA_BUF_SIZE, &dma_phy_addr, GFP_KERNEL | __GFP_DMA);
        printk("virt addr %08x", dma_virt_addr);
        printk("phy addr %08x", dma_phy_addr);    
        
        // *dma_virt_addr = 1;

        // printk("virt addr write test %08x", *dma_virt_addr);

    return 0;
error3:
    free_irq(lp->irq, lp);
error2:
    release_mem_region(lp->mem_start, lp->mem_end - lp->mem_start + 1);
error1:
    kfree(lp);
    dev_set_drvdata(dev, NULL);
    return rc;
}

static int dma_l_remove(struct platform_device *pdev)
{
    struct device *dev = &pdev->dev;
    struct dma_l_local *lp = dev_get_drvdata(dev);
    free_irq(lp->irq, lp);
    iounmap(lp->base_addr);
    release_mem_region(lp->mem_start, (lp->mem_end - lp->mem_start + 1));

    kfree(lp);
    dev_set_drvdata(dev, NULL);
    return 0;
}

/**********************************************************************/

//platform deivce & driver setting

static const struct platform_device_id dma_l_id_table[] = {
    {DEVICE_NAME}
};

#ifdef CONFIG_OF
static struct of_device_id dma_l_of_match[] = {
    { .compatible = "xlnx,axi-dma-7.1", "xlnx,axi-dma-1.00.a", }, //*compatible name in device tree(pl.dtsi)
    { /* end of list */ },
};
MODULE_DEVICE_TABLE(of, dma_l_of_match);
#else
# define dma_l_of_match
#endif

static struct platform_driver dma_l_driver = {
    .driver = {
        .name = DEVICE_NAME, // driver name = device name
        .owner = THIS_MODULE,
        .of_match_table = dma_l_of_match,
    },
    .probe      = dma_l_probe,
    .remove     = dma_l_remove,
    .id_table   = dma_l_id_table, // for device hot plug
};

/**********************************************************************/

static int __init dma_l_init(void)
{
    printk("<1>Hello module world.\n");
    printk("<1>Module parameters were (0x%08x) and \"%s\"\n", myint,
           mystr);

    return platform_driver_register(&dma_l_driver);
}

static void __exit dma_l_exit(void)
{
    platform_driver_unregister(&dma_l_driver);
    printk(KERN_ALERT "Goodbye module world.\n");
}

module_init(dma_l_init);
module_exit(dma_l_exit);


