//Swap data in memory location using pointers

#include <stdio.h>
#include <string.h>

void swap(int* a, int* b);

int main(void) {
        int x = 1;
        int y = 2;
        printf("the value of x and y before swap is %d, %d\n", x,y);
        swap(&x,&y);
        printf("the value of x and y after swap is %d, %d\n", x,y);
}

void swap(int* a, int* b) {
        int temp;
        temp = *a;
        *a= *b;
        *b = temp;
}

//pointers for dynamic memory allocation

int* p = malloc(sizeof(int));   //dynamically allocate a memory of size int in a heap
*p = 23;
printf("The value of the integer variable before change is %d ", *p);
*p = *p + 23;
printf("The value of the integer variable after change is %d ", *p);
free(p);  //free up the memory once used to avoid memory leak
