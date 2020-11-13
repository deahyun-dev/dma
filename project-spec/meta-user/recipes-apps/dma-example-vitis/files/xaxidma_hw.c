#include "xaxidma_hw.h"

u32 DMA_Xil_In32(UINTPTR addr){

  int DMA_fd = open(DMA_NODE, O_RDWR);
  param.addr = addr;
  Xil_In32(DMA_fd, &param);
  return (u32)param.val;

}

void DMA_Xil_Out32(UINTPTR addr, u32 val){

  int DMA_fd = open(DMA_NODE, O_RDWR);
  param.addr = addr;
  param.val = val;
  Xil_Out32(DMA_fd, &param);
  
  return;

}