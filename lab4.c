/*************************************************************************
Lab 4 Part one
************************************************************************/

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint64_t num = 0x1018fcfefc181000;
    int cur = 0;
    int tmp = 0;
    for(int i = 0; i < 8; i++)
    {
        cur = num & 0xFF;//last two byte
        num = num >>8;
        for(int j = 0; j<8; j++)
        {
            tmp = cur & 0x01;
            cur = cur >> 1;
            if(tmp == 1)
            {
                printf("*");//1->*
            }
            else
            {
                printf(" ");//0->space
            }
        }
        printf("\n");
    }
    return 0;
}
