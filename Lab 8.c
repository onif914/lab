/******************************************************************************

Author :Bing Jiang
Date: 03/26/2019

*******************************************************************************/

#include <stdio.h>
void swap(int*, int*);
void sortArray(int*, int);


int main()
{
    
    //Part 1: Memory Address
    double var_d = 2.345678;
    int var_i = 1;
    char var_c = 'a';
    char var_string[] = {'n','o','p','e','\0'};
    printf("Double var: %lf \t size: %d byte \t address: %p\n", var_d,sizeof(var_d),&var_d);
    printf("Integar var: %d \t\t size: %d byte \t address: %p\n", var_i,sizeof(var_i),&var_i);
    printf("Char var: %c \t\t size: %d byte \t address: %p\n", var_c,sizeof(var_c),&var_c);
    printf("String var: %s \t size: %d byte \t address: %p\n\n", var_string,sizeof(var_string),var_string);
    
    double *pd;
    pd = &var_d;
    int *pi;
    pi = &var_i;
    int *pc;
    pc = &var_c;
    printf("Pointer to double is %p, size: %d byte, address: %p.\n", pd, sizeof(pd),&pd);
    printf("Pointer to Integer is %p, size: %d byte, address: %p.\n", pi, sizeof(pi),&pi);
    printf("Pointer to char is %p, size: %d byte, address: %p.\n\n", pc, sizeof(pc),&pc);
    
    *pd = 8.765432;
    *pi = 99;
    *pc = 'f';
    var_string[0]='Y';
    printf("Double var: %lf \t size: %d byte \t address: %p\n", var_d,sizeof(var_d),&var_d);
    printf("Integar var: %d \t\t size: %d byte \t address: %p\n", var_i,sizeof(var_i),&var_i);
    printf("Char var: %c \t\t size: %d byte \t address: %p\n", var_c,sizeof(var_c),&var_c);
    printf("String var: %s \t size: %d byte \t address: %p\n\n", var_string,sizeof(var_string),var_string);
    
    //Part 2
    int x = 9999;
    int y = 1233;
    printf("Before swap, x = %d, y = %d\n", x,y);
    swap(&x,&y);
    printf("After swap, x = %d, y = %d\n\n", x,y);
    
    
    //Part 3:bubble sort in ascending order
    int iarray[10] = {4,57,2,88,9,0,38,1,999,254};
    printf("Before sort:\n4,57,2,88,9,0,38,1,999,254\n");
    sortArray(iarray, 10);
    printf("After sort:\n");
    for(int i = 0; i <10; i++)
        printf("%d ",iarray[i]);
    printf("\n");
    
    return 0;
}

void swap(int* a, int* b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int* iArray, int length)
{
    if(length <= 1) return;
    int p1 = 0;
    int p2 = 1;
    for(int p1 = 0; p1 < length; p1++)
    {
        for(int p2 = p1+1; p2<length; p2++)
        {
            if(iArray[p1]>iArray[p2])
            {
                swap(&iArray[p1], &iArray[p2]);
            }
        }
    }
}
