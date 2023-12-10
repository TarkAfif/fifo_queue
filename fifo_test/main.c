#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

#define cst_data_size 10
typedef struct
{
    st_FIFO_CtxTypeDef  st_FIFO_Ctx;
    uint8_t             u8_Fifo_Data[cst_data_size];
} stFIFO_Test_TypeDef;

stFIFO_Test_TypeDef stFIFO_Test;
int main()
{
    uint8_t cmd = 0, data = 0;
    vFn_FIFO_Create(&stFIFO_Test.st_FIFO_Ctx, stFIFO_Test.u8_Fifo_Data, cst_data_size);
    stFIFO_Test.st_FIFO_Ctx.vFn_FIFO_Reset(&stFIFO_Test.st_FIFO_Ctx);
    while(1)
    {
        printf("Hello get cmd \n");
        if(scanf("%s", &cmd))
        {
            printf("\n");
            switch (cmd)
            {
            case '1': // push byte
                printf("Push data \n");
                scanf("%x", &data);
                printf("\n");
                stFIFO_Test.st_FIFO_Ctx.vFn_FIFO_Push(&stFIFO_Test.st_FIFO_Ctx, data);
                printf("get data %x \n", data);
                break;
            case '2': //pull byte
                printf("pull data \n");
                printf("get data %x \n", stFIFO_Test.st_FIFO_Ctx.u8Fn_FIFO_Pull(&stFIFO_Test.st_FIFO_Ctx));
                break;
            case '3': // print data set
                printf("print data set\n");
                for(uint8_t index = 0; index < cst_data_size; index++)
                {
                    printf("print data index %i: %x \n", index, stFIFO_Test.u8_Fifo_Data[index]);
                }
                break;
            case '4': // get size
                printf("get data size \n");
                printf("data size is %x \n", stFIFO_Test.st_FIFO_Ctx.u8Fn_FIFO_GetActualSize(&stFIFO_Test.st_FIFO_Ctx));
                break;
            case '5': // reset ctx
                printf("reset context \n");
                stFIFO_Test.st_FIFO_Ctx.vFn_FIFO_Reset(&stFIFO_Test.st_FIFO_Ctx);
                break;
            case '6': // run auto-test
                printf("run auto tests here \n");
                break;
            default: // do nothing
                printf("hello dummy ! \n");
                break;
            }
            cmd = 0;
        }
        printf("\n");

    }

    return 1;
}
