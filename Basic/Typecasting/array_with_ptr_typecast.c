/*
 * here storing integer to char pointer
 * only manipulating char size in memory using pointer
 * 2nd offset of array will not effect because of pointer
 * */

#include<stdio.h>

int main()
{
        int a =  512;

        char *p = (char *) &a;

        p[0] = 0xFF; // it will effect only char sized memory location of the integer
        p[1] = 2; // it will not impact

        printf("a: %d\n", a);

        return 0;
}
