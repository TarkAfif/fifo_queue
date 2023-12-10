#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
  uint8_t*      u8_FIFO_Ptr;
  uint8_t       u8_FIFO_Size;
  uint8_t       u8_FIFO_Tail;
  bool          (*vFn_FIFO_Push)(void* FIFO_Ctx, uint8_t indata);
  uint8_t       (*u8Fn_FIFO_Pull)(void* FIFO_Ctx);
  void          (*vFn_FIFO_Reset)(void* FIFO_Ctx);
  uint8_t       (*u8Fn_FIFO_GetActualSize)(void* FIFO_Ctx);
} st_FIFO_CtxTypeDef;


void vFn_FIFO_Create(void* FIFO_Ctx, uint8_t* inFIFO, uint8_t size);

#endif
