#include <stdio.h>

//This is just pointer storing individual array elements but we can pass arrays or structure pointers to array of pointers

void main()
{
    int arr[3] = { 1, 2, 3 };
    int i, *ptr[3];
  
    for (i = 0; i < 3; i++) {
        ptr[i] = &arr[i]; //passing address of each member of the array
    }
  
    for (i = 0; i < 3; i++)
        printf("Value of arr[%d] = %d\n", i, *ptr[i]);
}
