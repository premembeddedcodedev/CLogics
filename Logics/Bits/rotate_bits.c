#include <stdio.h>

#define INT_BITS 32

#define ROTATE_LEFT(pos, data) ((data << pos)|(data >> (INT_BITS - pos)))

/*In first operation first bits will go away, those first bits will be restored in 2nd operation in below statement*/
#define ROTATE_RIGHT(pos, data) ((data >> pos)|(data << (INT_BITS - pos)))

int main()
{
    int pos = 2; // Number of rotation
    int data = 7; //data which will be rotate
    printf("%d Rotate Left by %d is ", data, pos);
    printf("%X \n", ROTATE_LEFT(pos, data));
    printf("%d Rotate Right by %d is ",data, pos);
    printf("%X \n", ROTATE_RIGHT(pos, data));

    return 0;
}
