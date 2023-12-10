#include "fifo.h"

bool vFn_FIFO_Push(void* FIFO_Ctx, uint8_t indata)
{
  st_FIFO_CtxTypeDef* FIFO = (st_FIFO_CtxTypeDef*)FIFO_Ctx;
  if(FIFO->u8Fn_FIFO_GetActualSize(FIFO_Ctx) < FIFO->u8_FIFO_Size)
  {
    *(FIFO->u8_FIFO_Ptr + FIFO->u8_FIFO_Tail) = indata;
    FIFO->u8_FIFO_Tail++;
    return true;
  }
  else
  {
    return false;
  }
}

uint8_t u8Fn_FIFO_Pull(void* FIFO_Ctx)
{
  st_FIFO_CtxTypeDef* FIFO = (st_FIFO_CtxTypeDef*)FIFO_Ctx;
  uint8_t retvalue = 0;;
  if(FIFO->u8Fn_FIFO_GetActualSize(FIFO_Ctx))
  {
    retvalue = *FIFO->u8_FIFO_Ptr;
    *FIFO->u8_FIFO_Ptr = 0;
    for(uint8_t index = 1; index < FIFO->u8_FIFO_Tail ; index++)
    {
      *(FIFO->u8_FIFO_Ptr + index - 1) = *(FIFO->u8_FIFO_Ptr + index); 
    }
    FIFO->u8_FIFO_Tail--;
    *(FIFO->u8_FIFO_Ptr + FIFO->u8_FIFO_Tail) = 0;
    return retvalue;
  }
  else
  {
    return 0;
  }
  
}

void vFn_FIFO_Reset(void* FIFO_Ctx)
{
  st_FIFO_CtxTypeDef* FIFO = (st_FIFO_CtxTypeDef*)FIFO_Ctx;
  FIFO->u8_FIFO_Tail = 0;
  for(uint8_t index = 0; index < FIFO->u8_FIFO_Size; index++)
  {
    *(FIFO->u8_FIFO_Ptr + index) = 0;
  }
}

uint8_t u8Fn_FIFO_GetActualSize(void* FIFO_Ctx)
{
  st_FIFO_CtxTypeDef* FIFO = (st_FIFO_CtxTypeDef*)FIFO_Ctx;
  return FIFO->u8_FIFO_Tail;
}

void vFn_FIFO_Create(void* FIFO_Ctx, uint8_t* inFIFO, uint8_t size)
{
  st_FIFO_CtxTypeDef* FIFO = (st_FIFO_CtxTypeDef*)FIFO_Ctx;
  FIFO->u8_FIFO_Ptr = inFIFO;
  FIFO->u8_FIFO_Size = size;
  FIFO->u8Fn_FIFO_Pull = u8Fn_FIFO_Pull;
  FIFO->vFn_FIFO_Push = vFn_FIFO_Push;
  FIFO->vFn_FIFO_Reset = vFn_FIFO_Reset;
  FIFO->u8Fn_FIFO_GetActualSize = u8Fn_FIFO_GetActualSize;
}