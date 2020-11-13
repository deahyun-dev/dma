/*
* Copyright (C) 2013 - 2016  Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge,
* publish, distribute, sublicense, and/or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in this
* Software without prior written authorization from Xilinx.
*
*/

#include <stdio.h>
#include "xaxidma.h"
#include "xparameters.h"
#include "xdebug.h"

/******************** Constant Definitions **********************************/

/*
 * Device hardware build related constants.
 */

#define DMA_DEV_ID		XPAR_AXIDMA_0_DEVICE_ID

#ifdef XPAR_AXI_7SDDR_0_S_AXI_BASEADDR
#define DDR_BASE_ADDR		XPAR_AXI_7SDDR_0_S_AXI_BASEADDR
#elif defined (XPAR_MIG7SERIES_0_BASEADDR)
#define DDR_BASE_ADDR	XPAR_MIG7SERIES_0_BASEADDR
#elif defined (XPAR_MIG_0_BASEADDR)
#define DDR_BASE_ADDR	XPAR_MIG_0_BASEADDR
#elif defined (XPAR_PSU_DDR_0_S_AXI_BASEADDR)
#define DDR_BASE_ADDR	XPAR_PSU_DDR_0_S_AXI_BASEADDR
#elif defined (XPAR_PS7_DDR_0_S_AXI_BASEADDR)
#define DDR_BASE_ADDR	XPAR_PS7_DDR_0_S_AXI_BASEADDR
#endif



#ifndef DDR_BASE_ADDR
#warning CHECK FOR THE VALID DDR ADDRESS IN XPARAMETERS.H, \
			DEFAULT SET TO 0x01000000
#define MEM_BASE_ADDR		0x01000000
#else
#define MEM_BASE_ADDR		(DDR_BASE_ADDR + 0x1000000)
#endif

#define TX_BD_SPACE_BASE	(MEM_BASE_ADDR)
#define TX_BD_SPACE_HIGH	(MEM_BASE_ADDR + 0x00000FFF)
#define RX_BD_SPACE_BASE	(MEM_BASE_ADDR + 0x00001000)
#define RX_BD_SPACE_HIGH	(MEM_BASE_ADDR + 0x00001FFF)
#define TX_BUFFER_BASE		(MEM_BASE_ADDR + 0x00100000)
#define RX_BUFFER_BASE		(MEM_BASE_ADDR + 0x00300000)
#define RX_BUFFER_HIGH		(MEM_BASE_ADDR + 0x004FFFFF)


#define MAX_PKT_LEN		0x20
#define MARK_UNCACHEABLE        0x701

#define TEST_START_VALUE	0xC


/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


// /************************** Function Prototypes ******************************/
// #if defined(XPAR_UARTNS550_0_BASEADDR)
// static void Uart550_Setup(void);
// #endif

// static int RxSetup(XAxiDma * AxiDmaInstPtr);
// static int TxSetup(XAxiDma * AxiDmaInstPtr);
// static int SendPacket(XAxiDma * AxiDmaInstPtr);
// static int CheckData(void);
// static int CheckDmaResult(XAxiDma * AxiDmaInstPtr);

/************************** Variable Definitions *****************************/
/*
 * Device instance definitions
 */
XAxiDma AxiDma;

/*
 * Buffer for transmit packet. Must be 32-bit aligned to be used by DMA.
 */
u32 *Packet = (u32 *) TX_BUFFER_BASE;

/*****************************************************************************/
/**
*
* Main function
*
* This function is the main entry of the tests on DMA core. It sets up
* DMA engine to be ready to receive and send packets, then a packet is
* transmitted and will be verified after it is received via the DMA loopback
* widget.
*
* @param	None
*
* @return
*		- XST_SUCCESS if test passes
*		- XST_FAILURE if test fails.
*
* @note		None.
*
******************************************************************************/
int main(void)
{
	int Status;
	XAxiDma_Config *Config;


	printf("\r\n--- Entering main() --- \r\n");

#ifdef __aarch64__
	Xil_SetTlbAttributes(TX_BD_SPACE_BASE, MARK_UNCACHEABLE);
	Xil_SetTlbAttributes(RX_BD_SPACE_BASE, MARK_UNCACHEABLE);
#endif

	// Config = XAxiDma_LookupConfig(DMA_DEV_ID);
	// if (!Config) {
	// 	printf("No config found for %d\r\n", DMA_DEV_ID);

	// 	return XST_FAILURE;
	// }

	// /* Initialize DMA engine */
	// Status = XAxiDma_CfgInitialize(&AxiDma, Config);
	// if (Status != XST_SUCCESS) {
	// 	printf("Initialization failed %d\r\n", Status);
	// 	return XST_FAILURE;
	// }

	// if(!XAxiDma_HasSg(&AxiDma)) {
	// 	printf("Device configured as Simple mode \r\n");

	// 	return XST_FAILURE;
	// }

	// Status = TxSetup(&AxiDma);
	// if (Status != XST_SUCCESS) {
	// 	return XST_FAILURE;
	// }

	// Status = RxSetup(&AxiDma);
	// if (Status != XST_SUCCESS) {
	// 	return XST_FAILURE;
	// }

	// /* Send a packet */
	// Status = SendPacket(&AxiDma);
	// if (Status != XST_SUCCESS) {
	// 	return XST_FAILURE;
	// }

	// /* Check DMA transfer result */
	// Status = CheckDmaResult(&AxiDma);

	// if (Status != XST_SUCCESS) {
	// 	printf("AXI DMA SG Polling Example Failed\r\n");
	// 	return XST_FAILURE;
	// }

	// printf("Successfully ran AXI DMA SG Polling Example\r\n");
	// printf("--- Exiting main() --- \r\n");

	// if (Status != XST_SUCCESS) {
	// 	return XST_FAILURE;
	// }

	return XST_SUCCESS;
}


// /*****************************************************************************/
// /**
// *
// * This function sets up RX channel of the DMA engine to be ready for packet
// * reception
// *
// * @param	AxiDmaInstPtr is the pointer to the instance of the DMA engine.
// *
// * @return	XST_SUCCESS if the setup is successful, XST_FAILURE otherwise.
// *
// * @note		None.
// *
// ******************************************************************************/
// static int RxSetup(XAxiDma * AxiDmaInstPtr)
// {
// 	XAxiDma_BdRing *RxRingPtr;
// 	int Delay = 0;
// 	int Coalesce = 1;
// 	int Status;
// 	XAxiDma_Bd BdTemplate;
// 	XAxiDma_Bd *BdPtr;
// 	XAxiDma_Bd *BdCurPtr;
// 	u32 BdCount;
// 	u32 FreeBdCount;
// 	UINTPTR RxBufferPtr;
// 	int Index;

// 	RxRingPtr = XAxiDma_GetRxRing(&AxiDma);

// 	/* Disable all RX interrupts before RxBD space setup */

// 	XAxiDma_BdRingIntDisable(RxRingPtr, XAXIDMA_IRQ_ALL_MASK);

// 	/* Set delay and coalescing */
// 	XAxiDma_BdRingSetCoalesce(RxRingPtr, Coalesce, Delay);

// 	/* Setup Rx BD space */
// 	BdCount = XAxiDma_BdRingCntCalc(XAXIDMA_BD_MINIMUM_ALIGNMENT,
// 				RX_BD_SPACE_HIGH - RX_BD_SPACE_BASE + 1);

// 	Status = XAxiDma_BdRingCreate(RxRingPtr, RX_BD_SPACE_BASE,
// 				RX_BD_SPACE_BASE,
// 				XAXIDMA_BD_MINIMUM_ALIGNMENT, BdCount);

// 	if (Status != XST_SUCCESS) {
// 		printf("RX create BD ring failed %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	/*
// 	 * Setup an all-zero BD as the template for the Rx channel.
// 	 */
// 	XAxiDma_BdClear(&BdTemplate);

// 	Status = XAxiDma_BdRingClone(RxRingPtr, &BdTemplate);
// 	if (Status != XST_SUCCESS) {
// 		printf("RX clone BD failed %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	/* Attach buffers to RxBD ring so we are ready to receive packets */

// 	FreeBdCount = XAxiDma_BdRingGetFreeCnt(RxRingPtr);

// 	Status = XAxiDma_BdRingAlloc(RxRingPtr, FreeBdCount, &BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("RX alloc BD failed %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	BdCurPtr = BdPtr;
// 	RxBufferPtr = RX_BUFFER_BASE;
// 	for (Index = 0; Index < FreeBdCount; Index++) {
// 		Status = XAxiDma_BdSetBufAddr(BdCurPtr, RxBufferPtr);

// 		if (Status != XST_SUCCESS) {
// 			printf("Set buffer addr %x on BD %x failed %d\r\n",
// 			    (unsigned int)RxBufferPtr,
// 			    (UINTPTR)BdCurPtr, Status);

// 			return XST_FAILURE;
// 		}

// 		Status = XAxiDma_BdSetLength(BdCurPtr, MAX_PKT_LEN,
// 				RxRingPtr->MaxTransferLen);
// 		if (Status != XST_SUCCESS) {
// 			printf("Rx set length %d on BD %x failed %d\r\n",
// 			    MAX_PKT_LEN, (UINTPTR)BdCurPtr, Status);

// 			return XST_FAILURE;
// 		}

// 		/* Receive BDs do not need to set anything for the control
// 		 * The hardware will set the SOF/EOF bits per stream status
// 		 */
// 		XAxiDma_BdSetCtrl(BdCurPtr, 0);
// 		XAxiDma_BdSetId(BdCurPtr, RxBufferPtr);

// 		RxBufferPtr += MAX_PKT_LEN;
// 		BdCurPtr = (XAxiDma_Bd *)XAxiDma_BdRingNext(RxRingPtr, BdCurPtr);
// 	}

// 	/* Clear the receive buffer, so we can verify data
// 	 */
// 	memset((void *)RX_BUFFER_BASE, 0, MAX_PKT_LEN);

// 	Status = XAxiDma_BdRingToHw(RxRingPtr, FreeBdCount,
// 						BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("RX submit hw failed %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	/* Start RX DMA channel */
// 	Status = XAxiDma_BdRingStart(RxRingPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("RX start hw failed %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	return XST_SUCCESS;
// }

// /*****************************************************************************/
// /**
// *
// * This function sets up the TX channel of a DMA engine to be ready for packet
// * transmission
// *
// * @param	AxiDmaInstPtr is the instance pointer to the DMA engine.
// *
// * @return	XST_SUCCESS if the setup is successful, XST_FAILURE otherwise.
// *
// * @note		None.
// *
// ******************************************************************************/
// static int TxSetup(XAxiDma * AxiDmaInstPtr)
// {
// 	XAxiDma_BdRing *TxRingPtr;
// 	XAxiDma_Bd BdTemplate;
// 	int Delay = 0;
// 	int Coalesce = 1;
// 	int Status;
// 	u32 BdCount;

// 	TxRingPtr = XAxiDma_GetTxRing(&AxiDma);

// 	/* Disable all TX interrupts before TxBD space setup */

// 	XAxiDma_BdRingIntDisable(TxRingPtr, XAXIDMA_IRQ_ALL_MASK);

// 	/* Set TX delay and coalesce */
// 	XAxiDma_BdRingSetCoalesce(TxRingPtr, Coalesce, Delay);

// 	/* Setup TxBD space  */
// 	BdCount = XAxiDma_BdRingCntCalc(XAXIDMA_BD_MINIMUM_ALIGNMENT,
// 				TX_BD_SPACE_HIGH - TX_BD_SPACE_BASE + 1);

// 	Status = XAxiDma_BdRingCreate(TxRingPtr, TX_BD_SPACE_BASE,
// 				TX_BD_SPACE_BASE,
// 				XAXIDMA_BD_MINIMUM_ALIGNMENT, BdCount);
// 	if (Status != XST_SUCCESS) {
// 		printf("failed create BD ring in txsetup\r\n");

// 		return XST_FAILURE;
// 	}

// 	/*
// 	 * We create an all-zero BD as the template.
// 	 */
// 	XAxiDma_BdClear(&BdTemplate);

// 	Status = XAxiDma_BdRingClone(TxRingPtr, &BdTemplate);
// 	if (Status != XST_SUCCESS) {
// 		printf("failed bdring clone in txsetup %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	/* Start the TX channel */
// 	Status = XAxiDma_BdRingStart(TxRingPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("failed start bdring txsetup %d\r\n", Status);

// 		return XST_FAILURE;
// 	}

// 	return XST_SUCCESS;
// }

// /*****************************************************************************/
// /**
// *
// * This function transmits one packet non-blockingly through the DMA engine.
// *
// * @param	AxiDmaInstPtr points to the DMA engine instance
// *
// * @return	- XST_SUCCESS if the DMA accepts the packet successfully,
// *		- XST_FAILURE otherwise.
// *
// * @note     None.
// *
// ******************************************************************************/
// static int SendPacket(XAxiDma * AxiDmaInstPtr)
// {
// 	XAxiDma_BdRing *TxRingPtr;
// 	u8 *TxPacket;
// 	u8 Value;
// 	XAxiDma_Bd *BdPtr;
// 	int Status;
// 	int Index;

// 	TxRingPtr = XAxiDma_GetTxRing(AxiDmaInstPtr);

// 	/* Create pattern in the packet to transmit */
// 	TxPacket = (u8 *) Packet;

// 	Value = TEST_START_VALUE;

// 	for(Index = 0; Index < MAX_PKT_LEN; Index ++) {
// 		TxPacket[Index] = Value;

// 		Value = (Value + 1) & 0xFF;
// 	}

// 	/* Flush the buffers before the DMA transfer, in case the Data Cache
// 	 * is enabled
// 	 */
// 	Xil_DCacheFlushRange((UINTPTR)TxPacket, MAX_PKT_LEN);
// 	Xil_DCacheFlushRange((UINTPTR)RX_BUFFER_BASE, MAX_PKT_LEN);

// 	/* Allocate a BD */
// 	Status = XAxiDma_BdRingAlloc(TxRingPtr, 1, &BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		return XST_FAILURE;
// 	}

// 	/* Set up the BD using the information of the packet to transmit */
// 	Status = XAxiDma_BdSetBufAddr(BdPtr, (UINTPTR) Packet);
// 	if (Status != XST_SUCCESS) {
// 		printf("Tx set buffer addr %x on BD %x failed %d\r\n",
// 		    (UINTPTR)Packet, (UINTPTR)BdPtr, Status);

// 		return XST_FAILURE;
// 	}

// 	Status = XAxiDma_BdSetLength(BdPtr, MAX_PKT_LEN,
// 				TxRingPtr->MaxTransferLen);
// 	if (Status != XST_SUCCESS) {
// 		printf("Tx set length %d on BD %x failed %d\r\n",
// 		    MAX_PKT_LEN, (UINTPTR)BdPtr, Status);

// 		return XST_FAILURE;
// 	}

// #if (XPAR_AXIDMA_0_SG_INCLUDE_STSCNTRL_STRM == 1)
// 	Status = XAxiDma_BdSetAppWord(BdPtr,
// 	    XAXIDMA_LAST_APPWORD, MAX_PKT_LEN);

// 	/* If Set app length failed, it is not fatal
// 	 */
// 	if (Status != XST_SUCCESS) {
// 		printf("Set app word failed with %d\r\n", Status);
// 	}
// #endif

// 	/* For single packet, both SOF and EOF are to be set
// 	 */
// 	XAxiDma_BdSetCtrl(BdPtr, XAXIDMA_BD_CTRL_TXEOF_MASK |
// 						XAXIDMA_BD_CTRL_TXSOF_MASK);

// 	XAxiDma_BdSetId(BdPtr, (UINTPTR)Packet);

// 	/* Give the BD to DMA to kick off the transmission. */
// 	Status = XAxiDma_BdRingToHw(TxRingPtr, 1, BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("to hw failed %d\r\n", Status);
// 		return XST_FAILURE;
// 	}



// 	return XST_SUCCESS;
// }

// /*****************************************************************************/
// /*
// *
// * This function checks data buffer after the DMA transfer is finished.
// *
// * @param	None
// *
// * @return	- XST_SUCCESS if validation is successful
// *		- XST_FAILURE if validation is failure.
// *
// * @note		None.
// *
// ******************************************************************************/
// static int CheckData(void)
// {
// 	u8 *RxPacket;
// 	int Index = 0;
// 	u8 Value;


// 	RxPacket = (u8 *) RX_BUFFER_BASE;
// 	Value = TEST_START_VALUE;

// 	/* Invalidate the DestBuffer before receiving the data, in case the
// 	 * Data Cache is enabled
// 	 */
// 	Xil_DCacheInvalidateRange((UINTPTR)RxPacket, MAX_PKT_LEN);

// 	for(Index = 0; Index < MAX_PKT_LEN; Index++) {
// 		if (RxPacket[Index] != Value) {
// 			printf("Data error %d: %x/%x\r\n",
// 			    Index, (unsigned int)RxPacket[Index],
// 			    (unsigned int)Value);

// 			return XST_FAILURE;
// 		}
// 		Value = (Value + 1) & 0xFF;
// 	}

// 	return XST_SUCCESS;
// }

// /*****************************************************************************/
// /**
// *
// * This function waits until the DMA transaction is finished, checks data,
// * and cleans up.
// *
// * @param	None
// *
// * @return	- XST_SUCCESS if DMA transfer is successful and data is correct,
// *		- XST_FAILURE if fails.
// *
// * @note		None.
// *
// ******************************************************************************/
// static int CheckDmaResult(XAxiDma * AxiDmaInstPtr)
// {
// 	XAxiDma_BdRing *TxRingPtr;
// 	XAxiDma_BdRing *RxRingPtr;
// 	XAxiDma_Bd *BdPtr;
// 	int ProcessedBdCount;
// 	int FreeBdCount;
// 	int Status;

// 	TxRingPtr = XAxiDma_GetTxRing(AxiDmaInstPtr);
// 	RxRingPtr = XAxiDma_GetRxRing(AxiDmaInstPtr);

// 	/* Wait until the one BD TX transaction is done */
// 	while ((ProcessedBdCount = XAxiDma_BdRingFromHw(TxRingPtr,
// 						       XAXIDMA_ALL_BDS,
// 						       &BdPtr)) == 0) {
// 	}

// 	/* Free all processed TX BDs for future transmission */
// 	Status = XAxiDma_BdRingFree(TxRingPtr, ProcessedBdCount, BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("Failed to free %d tx BDs %d\r\n",
// 		    ProcessedBdCount, Status);
// 		return XST_FAILURE;
// 	}

// 	/* Wait until the data has been received by the Rx channel */
// 	while ((ProcessedBdCount = XAxiDma_BdRingFromHw(RxRingPtr,
// 						       XAXIDMA_ALL_BDS,
// 						       &BdPtr)) == 0) {
// 	}

// 	/* Check received data */
// 	if (CheckData() != XST_SUCCESS) {

// 		return XST_FAILURE;
// 	}

// 	/* Free all processed RX BDs for future transmission */
// 	Status = XAxiDma_BdRingFree(RxRingPtr, ProcessedBdCount, BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("Failed to free %d rx BDs %d\r\n",
// 		    ProcessedBdCount, Status);
// 		return XST_FAILURE;
// 	}

// 	/* Return processed BDs to RX channel so we are ready to receive new
// 	 * packets:
// 	 *    - Allocate all free RX BDs
// 	 *    - Pass the BDs to RX channel
// 	 */
// 	FreeBdCount = XAxiDma_BdRingGetFreeCnt(RxRingPtr);
// 	Status = XAxiDma_BdRingAlloc(RxRingPtr, FreeBdCount, &BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("bd alloc failed\r\n");
// 		return XST_FAILURE;
// 	}

// 	Status = XAxiDma_BdRingToHw(RxRingPtr, FreeBdCount, BdPtr);
// 	if (Status != XST_SUCCESS) {
// 		printf("Submit %d rx BDs failed %d\r\n", FreeBdCount, Status);
// 		return XST_FAILURE;
// 	}

// 	return XST_SUCCESS;
// }