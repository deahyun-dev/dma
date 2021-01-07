#ifndef MY_EMUL_H
#define MY_EMUL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "xparameters.h" // bsp parameter include



//* device name & magic numbers 
#define ADC_NODE "/dev/ADC_AXI"
#define Pulser_NODE "/dev/Pulser_AXI"
#define RxBF_NODE "/dev/RxBF_AXI"
#define Bladder_NODE "/dev/Bladder_RTC"
#define CLK_NODE "/dev/clk_wiz"
#define DMA_NODE "/dev/dma"

#ifdef __KERNEL__

//for <stdint.h>
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef char char8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef int sint32;
typedef s32* INTPTR;
typedef u32* UINTPTR;

//for xil_printf
#include <linux/kernel.h>

//for usleep
#include <linux/delay.h>

//for xil_io.h
#include <asm/io.h> //iowrite, ioread
// #include <xil_io.h>

#define Xil_In8(BaseAddress)  ioread8(BaseAddress)
#define Xil_In16(BaseAddress) ioread16(BaseAddress)
#define Xil_In32(BaseAddress) ioread32(BaseAddress)
#define Xil_In64(BaseAddress) ioread64(BaseAddress)

#define Xil_Out8(BaseAddress, Data)  iowrite8((u8)Data, BaseAddress)
#define Xil_Out16(BaseAddress, Data) iowrite16((u16)Data, BaseAddress)
#define Xil_Out32(BaseAddress, Data) iowrite32((u32)Data, BaseAddress)
#define Xil_Out64(BaseAddress, Data) iowrite64((u64)Data, BaseAddress)

#ifdef ADC_AXI_H
//*************************** ADC  ************************************
//* for ADC ioctl parameters


//* magic number for xil_inout at API
#define ADC_IOCTL_NUMBER 'A'

#define ADC_In8         _IOR(ADC_IOCTL_NUMBER, 0, ADC_param)
#define ADC_In16        _IOR(ADC_IOCTL_NUMBER, 1, ADC_param)
#define ADC_In32        _IOR(ADC_IOCTL_NUMBER, 2, ADC_param)
#define ADC_Out8        _IOW(ADC_IOCTL_NUMBER, 3, ADC_param)
#define ADC_Out16       _IOW(ADC_IOCTL_NUMBER, 4, ADC_param)
#define ADC_Out32       _IOW(ADC_IOCTL_NUMBER, 5, ADC_param)
#define ADC_MEMCPY      _IOR(ADC_IOCTL_NUMBER, 6, ADC_param)
#define ADC_BASE_ADDR   _IOW(ADC_IOCTL_NUMBER, 100, UINTPTR)

#endif

#ifdef CLK_RST_H

//* magic number for xil_inout at API
#define CLK_IOCTL_NUMBER 'C'

#define CLK_In8      _IOR(CLK_IOCTL_NUMBER, 0, CLK_param)
#define CLK_In16     _IOR(CLK_IOCTL_NUMBER, 1, CLK_param)
#define CLK_In32     _IOR(CLK_IOCTL_NUMBER, 2, CLK_param)
#define CLK_Out8     _IOW(CLK_IOCTL_NUMBER, 3, CLK_param)
#define CLK_Out16    _IOW(CLK_IOCTL_NUMBER, 4, CLK_param)
#define CLK_Out32    _IOW(CLK_IOCTL_NUMBER, 5, CLK_param)
#define CLK_BASE_ADDR   _IOW(CLK_IOCTL_NUMBER, 100, UINTPTR)
  
#endif


#ifdef PULSER_AXI_H
//*************************** Pulser  ************************************


//* magic number for xil_inout at API
#define PULSER_IOCTL_NUMBER 'P'

#define Pulser_In8      _IOR(PULSER_IOCTL_NUMBER, 0, Pulser_param)
#define Pulser_In16     _IOR(PULSER_IOCTL_NUMBER, 1, Pulser_param)
#define Pulser_In32     _IOR(PULSER_IOCTL_NUMBER, 2, Pulser_param)
#define Pulser_Out8     _IOW(PULSER_IOCTL_NUMBER, 3, Pulser_param)
#define Pulser_Out16    _IOW(PULSER_IOCTL_NUMBER, 4, Pulser_param)
#define Pulser_Out32    _IOW(PULSER_IOCTL_NUMBER, 5, Pulser_param)
#define Pulser_BASE_ADDR   _IOW(PULSER_IOCTL_NUMBER, 100, UINTPTR)

#endif

#ifdef BLADDER_RTC_H
//*************************** Bladder ************************************


//* magic number for xil_inout at API
#define BLADDER_IOCTL_NUMBER 'B'

#define Bladder_In8      _IOR(BLADDER_IOCTL_NUMBER, 0, Bladder_param)
#define Bladder_In16     _IOR(BLADDER_IOCTL_NUMBER, 1, Bladder_param)
#define Bladder_In32     _IOR(BLADDER_IOCTL_NUMBER, 2, Bladder_param)
#define Bladder_Out8     _IOW(BLADDER_IOCTL_NUMBER, 3, Bladder_param)
#define Bladder_Out16    _IOW(BLADDER_IOCTL_NUMBER, 4, Bladder_param)
#define Bladder_Out32    _IOW(BLADDER_IOCTL_NUMBER, 5, Bladder_param)
#define Bladder_BASE_ADDR   _IOW(BLADDER_IOCTL_NUMBER, 100, UINTPTR)

#endif

#ifdef RXBF_AXI_H
//*************************** RxBF  ************************************


//* magic number for xil_inout at API
#define RXBF_IOCTL_NUMBER 'R'

#define RxBF_In8         _IOR(RXBF_IOCTL_NUMBER, 0, RxBF_param)
#define RxBF_In16        _IOR(RXBF_IOCTL_NUMBER, 1, RxBF_param)
#define RxBF_In32        _IOR(RXBF_IOCTL_NUMBER, 2, RxBF_param)
#define RxBF_Out8        _IOW(RXBF_IOCTL_NUMBER, 3, RxBF_param)
#define RxBF_Out16       _IOW(RXBF_IOCTL_NUMBER, 4, RxBF_param)
#define RxBF_Out32       _IOW(RXBF_IOCTL_NUMBER, 5, RxBF_param)
#define RxBF_BASE_ADDR   _IOW(RXBF_IOCTL_NUMBER, 100, UINTPTR)

#endif

#ifdef DMA_H

//* magic number for xil_inout at API
#define DMA_IOCTL_NUMBER 'M'

#define DMA_In32        _IOR(DMA_IOCTL_NUMBER, 0, DMA_param)
#define DMA_Out32       _IOW(DMA_IOCTL_NUMBER, 1, DMA_param)
#define DMA_BD_READ     _IOW(DMA_IOCTL_NUMBER, 2, DMA_param)
#define DMA_BD_WRITE    _IOW(DMA_IOCTL_NUMBER, 3, DMA_param)
#define DMA_ALLOC_BUF   _IOR(DMA_IOCTL_NUMBER, 99, DMA_param)
#define DMA_BASE_ADDR   _IOW(DMA_IOCTL_NUMBER, 100, UINTPTR)

#endif

#else //* ndef __KERNEL__ == API
#include <unistd.h> // for usleep
#include "xil_types.h" //for u8 ~ u64 in user space
#include <sys/ioctl.h> // for ioctl
#include <fcntl.h> // fopen, close

#ifdef ADC_AXI_H
//*************************** ADC  ************************************
//* for ADC ioctl parameters


//* magic number for xil_inout at API
#define ADC_IOCTL_NUMBER 'A'

#define ADC_In8      _IOR(ADC_IOCTL_NUMBER, 0, ADC_param)
#define ADC_In16     _IOR(ADC_IOCTL_NUMBER, 1, ADC_param)
#define ADC_In32     _IOR(ADC_IOCTL_NUMBER, 2, ADC_param)
#define ADC_Out8     _IOW(ADC_IOCTL_NUMBER, 3, ADC_param)
#define ADC_Out16    _IOW(ADC_IOCTL_NUMBER, 4, ADC_param)
#define ADC_Out32    _IOW(ADC_IOCTL_NUMBER, 5, ADC_param)
#define ADC_MEMCPY   _IOR(ADC_IOCTL_NUMBER, 6, ADC_param)
#define ADC_BASE_ADDR   _IOW(ADC_IOCTL_NUMBER, 100, UINTPTR)

//* ioctl connect

#define Xil_In8(fd, param)      ioctl(fd, ADC_In8, param)
#define Xil_In16(fd, param)     ioctl(fd, ADC_In16, param)
#define Xil_In32(fd, param)     ioctl(fd, ADC_In32, param)
#define Xil_Out8(fd, param)     ioctl(fd, ADC_Out8, param)
#define Xil_Out16(fd, param)    ioctl(fd, ADC_Out16, param)
#define Xil_Out32(fd, param)    ioctl(fd, ADC_Out32, param)
#define Xil_MEMCPY(fd, param)   ioctl(fd, ADC_MEMCPY, param)
  
#endif

#ifdef PULSER_AXI_H
//*************************** Pulser  ************************************



//* magic number for xil_inout at API
#define PULSER_IOCTL_NUMBER 'P'

#define Pulser_In8      _IOR(PULSER_IOCTL_NUMBER, 0, Pulser_param)
#define Pulser_In16     _IOR(PULSER_IOCTL_NUMBER, 1, Pulser_param)
#define Pulser_In32     _IOR(PULSER_IOCTL_NUMBER, 2, Pulser_param)
#define Pulser_Out8     _IOW(PULSER_IOCTL_NUMBER, 3, Pulser_param)
#define Pulser_Out16    _IOW(PULSER_IOCTL_NUMBER, 4, Pulser_param)
#define Pulser_Out32    _IOW(PULSER_IOCTL_NUMBER, 5, Pulser_param)
#define Pulser_BASE_ADDR   _IOW(PULSER_IOCTL_NUMBER, 100, UINTPTR)
//* ioctl connect

#define Xil_In8(fd, param)      ioctl(fd, Pulser_In8, param)
#define Xil_In16(fd, param)     ioctl(fd, Pulser_In16, param)
#define Xil_In32(fd, param)     ioctl(fd, Pulser_In32, param)
#define Xil_Out8(fd, param)     ioctl(fd, Pulser_Out8, param)
#define Xil_Out16(fd, param)    ioctl(fd, Pulser_Out16, param)
#define Xil_Out32(fd, param)    ioctl(fd, Pulser_Out32, param)

#endif

#ifdef BLADDER_RTC_H
//*************************** Pulser  ************************************


//* magic number for xil_inout at API
#define BLADDER_IOCTL_NUMBER 'B'

#define Bladder_In8      _IOR(BLADDER_IOCTL_NUMBER, 0, Bladder_param)
#define Bladder_In16     _IOR(BLADDER_IOCTL_NUMBER, 1, Bladder_param)
#define Bladder_In32     _IOR(BLADDER_IOCTL_NUMBER, 2, Bladder_param)
#define Bladder_Out8     _IOW(BLADDER_IOCTL_NUMBER, 3, Bladder_param)
#define Bladder_Out16    _IOW(BLADDER_IOCTL_NUMBER, 4, Bladder_param)
#define Bladder_Out32    _IOW(BLADDER_IOCTL_NUMBER, 5, Bladder_param)
#define Bladder_BASE_ADDR   _IOW(BLADDER_IOCTL_NUMBER, 100, UINTPTR)
//* ioctl connect

#define Xil_In8(fd, param)      ioctl(fd, Bladder_In8, param)
#define Xil_In16(fd, param)     ioctl(fd, Bladder_In16, param)
#define Xil_In32(fd, param)     ioctl(fd, Bladder_In32, param)
#define Xil_Out8(fd, param)     ioctl(fd, Bladder_Out8, param)
#define Xil_Out16(fd, param)    ioctl(fd, Bladder_Out16, param)
#define Xil_Out32(fd, param)    ioctl(fd, Bladder_Out32, param)

#endif

#ifdef RXBF_AXI_H

//* magic number for xil_inout at API
#define RXBF_IOCTL_NUMBER 'R'

#define RxBF_In8         _IOR(RXBF_IOCTL_NUMBER, 0, RxBF_param)
#define RxBF_In16        _IOR(RXBF_IOCTL_NUMBER, 1, RxBF_param)
#define RxBF_In32        _IOR(RXBF_IOCTL_NUMBER, 2, RxBF_param)
#define RxBF_Out8        _IOW(RXBF_IOCTL_NUMBER, 3, RxBF_param)
#define RxBF_Out16       _IOW(RXBF_IOCTL_NUMBER, 4, RxBF_param)
#define RxBF_Out32       _IOW(RXBF_IOCTL_NUMBER, 5, RxBF_param)
#define RxBF_BASE_ADDR   _IOW(RXBF_IOCTL_NUMBER, 100, UINTPTR)

//* ioctl connect

#define Xil_In8(fd, param)      ioctl(fd, RxBF_In8, param)
#define Xil_In16(fd, param)     ioctl(fd, RxBF_In16, param)
#define Xil_In32(fd, param)     ioctl(fd, RxBF_In32, param)
#define Xil_Out8(fd, param)     ioctl(fd, RxBF_Out8, param)
#define Xil_Out16(fd, param)    ioctl(fd, RxBF_Out16, param)
#define Xil_Out32(fd, param)    ioctl(fd, RxBF_Out32, param)

#endif

#ifdef CLK_RST_H

//* magic number for xil_inout at API
#define CLK_IOCTL_NUMBER 'C'

#define CLK_In8      _IOR(CLK_IOCTL_NUMBER, 0, CLK_param)
#define CLK_In16     _IOR(CLK_IOCTL_NUMBER, 1, CLK_param)
#define CLK_In32     _IOR(CLK_IOCTL_NUMBER, 2, CLK_param)
#define CLK_Out8     _IOW(CLK_IOCTL_NUMBER, 3, CLK_param)
#define CLK_Out16    _IOW(CLK_IOCTL_NUMBER, 4, CLK_param)
#define CLK_Out32    _IOW(CLK_IOCTL_NUMBER, 5, CLK_param)
#define CLK_BASE_ADDR   _IOW(CLK_IOCTL_NUMBER, 100, UINTPTR)

//* ioctl connect

#define Xil_In8(fd, param)      ioctl(fd, CLK_In8, param)
#define Xil_In16(fd, param)     ioctl(fd, CLK_In16, param)
#define Xil_In32(fd, param)     ioctl(fd, CLK_In32, param)
#define Xil_Out8(fd, param)     ioctl(fd, CLK_Out8, param)
#define Xil_Out16(fd, param)    ioctl(fd, CLK_Out16, param)
#define Xil_Out32(fd, param)    ioctl(fd, CLK_Out32, param)
  
#endif

#ifdef DMA_H

//* magic number for xil_inout at API
#define DMA_IOCTL_NUMBER 'M'

#define DMA_In32        _IOR(DMA_IOCTL_NUMBER, 0, DMA_param)
#define DMA_Out32       _IOW(DMA_IOCTL_NUMBER, 1, DMA_param)
#define DMA_BD_READ     _IOW(DMA_IOCTL_NUMBER, 2, DMA_param)
#define DMA_BD_WRITE    _IOW(DMA_IOCTL_NUMBER, 3, DMA_param)
#define DMA_BASE_ADDR   _IOW(DMA_IOCTL_NUMBER, 100, UINTPTR)
#define DMA_ALLOC_BUF   _IOR(DMA_IOCTL_NUMBER, 99, DMA_param)
#define Xil_In32(fd, param)     ioctl(fd, DMA_In32, param)
#define Xil_Out32(fd, param)    ioctl(fd, DMA_Out32, param)

#endif


#endif

#define DMA_BUF_SIZE 0x1000 * 2


// #define RxBF_IOCTL_NUMBER 'R'
// //* rxbf_axi_l 

// /* ------------------ RxBF Parameter Read/Write API Macros ------------------ */

// //* redefine for driver magic number

// #define mRxBF_Parameter_Write_AD_OFFSET _IOW(RxBF_IOCTL_NUMBER, 0, RxBF_param)
// #define mRxBF_Parameter_Read_AD_OFFSET _IOR(RxBF_IOCTL_NUMBER, 1, RxBF_param)
// #define mRxBF_Parameter_Write_Element_X _IOW(RxBF_IOCTL_NUMBER, 2, RxBF_param)
// #define mRxBF_Parameter_Read_Element_X _IOR(RxBF_IOCTL_NUMBER, 3, RxBF_param)
// #define mRxBF_Parameter_Write_Element_Y _IOW(RxBF_IOCTL_NUMBER, 4, RxBF_param)
// #define mRxBF_Parameter_Read_Element_Y _IOR(RxBF_IOCTL_NUMBER, 5, RxBF_param)
// #define mRxBF_Parameter_Write_Scan_X _IOW(RxBF_IOCTL_NUMBER, 6, RxBF_param)
// #define mRxBF_Parameter_Read_Scan_X _IOR(RxBF_IOCTL_NUMBER, 7, RxBF_param)
// #define mRxBF_Parameter_Write_Scan_Y _IOW(RxBF_IOCTL_NUMBER, 8, RxBF_param)
// #define mRxBF_Parameter_Read_Scan_Y  _IOR(RxBF_IOCTL_NUMBER, 9, RxBF_param)
// #define mRxBF_Parameter_Write_Focal_Depth _IOW(RxBF_IOCTL_NUMBER, 10, RxBF_param)
// #define mRxBF_Parameter_Read_Focal_Depth _IOR(RxBF_IOCTL_NUMBER, 11, RxBF_param)
// #define mRxBF_Parameter_Write_Tx_Delay_Cntr _IOW(RxBF_IOCTL_NUMBER, 12, RxBF_param)
// #define mRxBF_Parameter_Read_Tx_Delay_Cntr _IOR(RxBF_IOCTL_NUMBER, 13, RxBF_param)

// /* --------------- RxBF Delay Parameter Read/Write API Macros --------------- */

// #define mRxBF_Delay_Write_Focal_X _IOW(RxBF_IOCTL_NUMBER, 14, RxBF_param)
// #define mRxBF_Delay_Read_Focal_X _IOR(RxBF_IOCTL_NUMBER, 15, RxBF_param)

// #define mRxBF_Delay_Write_Focal_Y _IOW(RxBF_IOCTL_NUMBER, 16, RxBF_param)
// #define mRxBF_Delay_Read_Focal_Y _IOR(RxBF_IOCTL_NUMBER, 17, RxBF_param)

// #define mRxBF_Delay_Write_Image_Incr_X _IOW(RxBF_IOCTL_NUMBER, 18, RxBF_param)
// #define mRxBF_Delay_Read_Image_Incr_X _IOR(RxBF_IOCTL_NUMBER, 19, RxBF_param)

// #define mRxBF_Delay_Write_Image_Incr_Y _IOW(RxBF_IOCTL_NUMBER, 20, RxBF_param)
// #define mRxBF_Delay_Read_Image_Incr_Y _IOR(RxBF_IOCTL_NUMBER, 21, RxBF_param)

// /* -------------------- Apodization Read/Write API Macros ------------------- */

// #define mRxBF_Apodization_Write_Coeff _IOW(RxBF_IOCTL_NUMBER, 22, RxBF_param)
// #define mRxBF_Apodization_Read_Coeff _IOR(RxBF_IOCTL_NUMBER, 23, RxBF_param)
// #define mRxBF_Apodization_Write_Timing _IOW(RxBF_IOCTL_NUMBER, 24, RxBF_param)
// #define mRxBF_Apodization_Read_Timing _IOR(RxBF_IOCTL_NUMBER, 25, RxBF_param)

// /* --------------------- Aperture Read/Write API Macros --------------------- */
// #define mRxBF_Aperture_Write_Timing _IOW(RxBF_IOCTL_NUMBER, 26, RxBF_param)
// #define mRxBF_Aperture_Read_Timing _IOR(RxBF_IOCTL_NUMBER, 27, RxBF_param)

// //* redefine for user

// //* 14개
// #define mRxBF_AXI_Parameter_Write_AD_OFFSET(fd, param)      ioctl(fd, mRxBF_Parameter_Write_AD_OFFSET, param)
// #define mRxBF_AXI_Parameter_Read_AD_OFFSET(fd, param)       ioctl(fd, mRxBF_Parameter_Read_AD_OFFSET, param)
// #define mRxBF_AXI_Parameter_Write_Element_X(fd, param)      ioctl(fd, mRxBF_Parameter_Write_Element_X, param)
// #define mRxBF_AXI_Parameter_Read_Element_X(fd, param)       ioctl(fd, mRxBF_Parameter_Read_Element_X, param)
// #define mRxBF_AXI_Parameter_Write_Element_Y(fd, param)      ioctl(fd, mRxBF_Parameter_Write_Element_Y, param)
// #define mRxBF_AXI_Parameter_Read_Element_Y(fd, param)       ioctl(fd, mRxBF_Parameter_Read_Element_Y, param)
// #define mRxBF_AXI_Parameter_Write_Scan_X(fd, param)         ioctl(fd, mRxBF_Parameter_Write_Scan_X, param)
// #define mRxBF_AXI_Parameter_Read_Scan_X(fd, param)          ioctl(fd, mRxBF_Parameter_Read_Scan_X, param)
// #define mRxBF_AXI_Parameter_Write_Scan_Y(fd, param)         ioctl(fd, mRxBF_Parameter_Write_Scan_Y, param)
// #define mRxBF_AXI_Parameter_Read_Scan_Y(fd, param)          ioctl(fd, mRxBF_Parameter_Read_Scan_Y, param)
// #define mRxBF_AXI_Parameter_Write_Focal_Depth(fd, param)    ioctl(fd, mRxBF_Parameter_Write_Focal_Depth, param)
// #define mRxBF_AXI_Parameter_Read_Focal_Depth(fd, param)     ioctl(fd, mRxBF_Parameter_Read_Focal_Depth, param)
// #define mRxBF_AXI_Parameter_Write_Tx_Delay_Cntr(fd, param)  ioctl(fd, mRxBF_Parameter_Write_Tx_Delay_Cntr, param)
// #define mRxBF_AXI_Parameter_Read_Tx_Delay_Cntr(fd, param)   ioctl(fd, mRxBF_Parameter_Read_Tx_Delay_Cntr, param)

// // /* --------------- RxBF Delay Parameter Read/Write API Macros --------------- */

// #define mRxBF_AXI_Delay_Write_Focal_X(fd, param)        ioctl(fd, mRxBF_Delay_Write_Focal_X, param)
// #define mRxBF_AXI_Delay_Read_Focal_X(fd, param)         ioctl(fd, mRxBF_Delay_Read_Focal_X, param)
// #define mRxBF_AXI_Delay_Write_Focal_Y(fd, param)        ioctl(fd, mRxBF_Delay_Write_Focal_Y, param)
// #define mRxBF_AXI_Delay_Read_Focal_Y(fd, param)         ioctl(fd, mRxBF_Delay_Read_Focal_Y, param)
// #define mRxBF_AXI_Delay_Write_Image_Incr_X(fd, param)   ioctl(fd, mRxBF_Delay_Write_Image_Incr_X, param)
// #define mRxBF_AXI_Delay_Read_Image_Incr_X(fd, param)    ioctl(fd, mRxBF_Delay_Read_Image_Incr_X, param)
// #define mRxBF_AXI_Delay_Write_Image_Incr_Y(fd, param)   ioctl(fd, mRxBF_Delay_Write_Image_Incr_Y, param)
// #define mRxBF_AXI_Delay_Read_Image_Incr_Y(fd, param)    ioctl(fd, mRxBF_Delay_Read_Image_Incr_Y, param)

// // /* -------------------- Apodization Read/Write API Macros ------------------- */

// #define mRxBF_AXI_Apodization_Write_Coeff(fd, param)   ioctl(fd, mRxBF_Apodization_Write_Coeff, param)
// #define mRxBF_AXI_Apodization_Read_Coeff(fd, param)    ioctl(fd, mRxBF_Apodization_Read_Coeff, param)
// #define mRxBF_AXI_Apodization_Write_Timing(fd, param)  ioctl(fd, mRxBF_Apodization_Write_Timing, param)
// #define mRxBF_AXI_Apodization_Read_Timing(fd, param)   ioctl(fd, mRxBF_Apodization_Read_Timing, param)

// // /* --------------------- Aperture Read/Write API Macros --------------------- */
// #define mRxBF_AXI_Aperture_Write_Timing(fd, param) ioctl(fd, mRxBF_Aperture_Write_Timing, param)
// #define mRxBF_AXI_Aperture_Read_Timing(fd, param)  ioctl(fd, mRxBF_Aperture_Read_Timing, param)


// /**************************** Macros *****************************/

// /* -------------------------------------------------------------------------- */
// /*                               Address Offset                               */
// /* -------------------------------------------------------------------------- */

// /* ----------------- RxBF Parameter Instance Address Offsets ---------------- */

// #define RXBF_PARAM_AD_OFFSET_ADDR_OFFSET 0
// #define RXBF_PARAM_ELEMENT_X_ADDR_OFFSET 32
// #define RXBF_PARAM_ELEMENT_Y_ADDR_OFFSET 96
// #define RXBF_PARAM_SCAN_X_ADDR_OFFSET 162
// #define RXBF_PARAM_SCAN_Y_ADDR_OFFSET 160
// #define RXBF_PARAM_FOCAL_DEPTH_ADDR_OFFSET 166
// #define RXBF_PARAM_TX_DELAY_CNTR_ADDR_OFFSET 164

// /* -------------- RxBF Delay parameter instance address offsets ------------- */

// #define RXBF_DELAY_POSITION_FOCAL_X_ADDR_OFFSET 0
// #define RXBF_DELAY_POSITION_FOCAL_Y_ADDR_OFFSET 256
// #define RXBF_DELAY_POSITION_IMAGE_INCR_X_ADDR_OFFSET 512
// #define RXBF_DELAY_POSITION_IMAGE_INCR_Y_ADDR_OFFSET 768

// /* -------------------------------------------------------------------------- */
// /*                            Constraint Parameters                           */
// /* -------------------------------------------------------------------------- */

// /* ------------------- RxBF Value Constraints by Hardware ------------------- */

// #define RXBF_AXI_PARAMETER_AD_OFFSET_MAX 127
// #define RXBF_AXI_PARAMETER_AD_OFFSET_MIN -128

// #define RXBF_AXI_PARAMETER_ELEMENT_X_MAX 8191
// #define RXBF_AXI_PARAMETER_ELEMENT_X_MIN -8192

// #define RXBF_AXI_PARAMETER_ELEMENT_Y_MAX 32767
// #define RXBF_AXI_PARAMETER_ELEMENT_Y_MIN -32768

// #define RXBF_AXI_PARAMETER_SCAN_X_MAX 8191
// #define RXBF_AXI_PARAMETER_SCAN_X_MIN -8192

// #define RXBF_AXI_PARAMETER_SCAN_Y_MAX 32767
// #define RXBF_AXI_PARAMETER_SCAN_Y_MIN -32768

// #define RXBF_AXI_PARAMETER_FOCAL_DEPTH_MAX 32767
// #define RXBF_AXI_PARAMETER_FOCAL_DEPTH_MIN -32768

// #define RXBF_AXI_PARAMETER_TX_DELAY_CNTR_MAX 1023
// #define RXBF_AXI_PARAMETER_TX_DELAY_CNTR_MIN -1024

// #define RXBF_AXI_PARAMETER_FOCAL_X_MAX 16383
// #define RXBF_AXI_PARAMETER_FOCAL_X_MIN -16384

// #define RXBF_AXI_PARAMETER_FOCAL_Y_MAX 16383
// #define RXBF_AXI_PARAMETER_FOCAL_Y_MIN -16384

// #define RXBF_AXI_PARAMETER_IMAGE_INCR_X_MAX 65535
// #define RXBF_AXI_PARAMETER_IMAGE_INCR_X_MIN 0

// #define RXBF_AXI_PARAMETER_IMAGE_INCR_Y_MAX 32767
// #define RXBF_AXI_PARAMETER_IMAGE_INCR_Y_MIN -32768

// #define RXBF_AXI_APODIZATION_COEFF_MAX 127
// #define RXBF_AXI_APODIZATION_COEFF_MIN 0

// #define RXBF_AXI_APODIZATION_TIMING_MAX 65535
// #define RXBF_AXI_APODIZATION_TIMING_MIN 0

// #define RXBF_AXI_APERTURE_TIMING_MAX 65535
// #define RXBF_AXI_APERTURE_TIMING_MIN 0

// /* ----------------------- Apodization Register Offset ---------------------- */
// #define RXBF_AXI_APOD_COEFF_OFFSET 2
// #define RXBF_AXI_APOD_TIMING_OFFSET 0
// #define RXBF_AXI_APOD_INDEX_OFFSET 4
// #define RXBF_AXI_APOD_CHANNEL_OFFSET 32

// /* ----------------- Maximum constraints of parameter number ---------------- */
// #define RXBF_AXI_CHANNEL_MAX_NUM 32
// #define RXBF_AXI_SCANLINE_MAX_NUM 128
// #define RXBF_AXI_APODIZATION_COEFF_NUM 8

// /* -------------------- Register Number of RxBF Instances ------------------- */
// #define RXBF_AXI_PARAMETER_REG_NUM 42
// #define RXBF_AXI_DELAY_REG_NUM 256
// #define RXBF_AXI_APODIZATION_REG_NUM 256
// #define RXBF_AXI_APERTURE_REG_NUM 16

// /* ----------------- Floating point quantization parameters ----------------- */
// #define RXBF_PARAM_ELEMENT_X_INT 10
// #define RXBF_PARAM_ELEMENT_X_FRC 3

// #define RXBF_PARAM_ELEMENT_Y_INT 12
// #define RXBF_PARAM_ELEMENT_Y_FRC 3

// #define RXBF_PARAM_SCAN_X_INT 10
// #define RXBF_PARAM_SCAN_X_FRC 3

// #define RXBF_PARAM_SCAN_Y_INT 12
// #define RXBF_PARAM_SCAN_Y_FRC 3

// #define RXBF_PARAM_FOCAL_DEPTH_INT 13
// #define RXBF_PARAM_FOCAL_DEPTH_FRC 2

// #define RXBF_PARAM_DELAY_CTRL_INT 9
// #define RXBF_PARAM_DELAY_CTRL_FRC 1

// #define RXBF_DELAY_FOCAL_X_INT 13
// #define RXBF_DELAY_FOCAL_X_FRC 1

// #define RXBF_DELAY_FOCAL_Y_INT 13
// #define RXBF_DELAY_FOCAL_Y_FRC 1

// #define RXBF_DELAY_IMAGE_INCR_X_INT 1
// #define RXBF_DELAY_IMAGE_INCR_X_FRC 15

// #define RXBF_DELAY_IMAGE_INCR_Y_INT 0
// #define RXBF_DELAY_IMAGE_INCR_Y_FRC 15


//* for ADC & Pulser

#ifdef __cplusplus
}
#endif

#endif	/* end of protection macro */



