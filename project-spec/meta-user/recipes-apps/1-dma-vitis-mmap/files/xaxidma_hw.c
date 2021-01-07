#define DMA_H
#include "xaxidma_hw.h"

u32 XAxiDma_In32(UINTPTR addr){

  int DMA_fd = open(DMA_NODE, O_RDWR);
  param.addr = addr;
  Xil_In32(DMA_fd, &param);
  close(DMA_fd);
  return (u32)param.val;

}

void XAxiDma_Out32(UINTPTR addr, u32 val){

  int DMA_fd = open(DMA_NODE, O_RDWR);
  param.addr = addr;
  param.val = val;
  Xil_Out32(DMA_fd, &param);
  close(DMA_fd);
  return;

}


