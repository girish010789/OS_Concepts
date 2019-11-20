//Trying to modify read-only memory
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *str;

   /* Stored in read only part of data segment */
   str = "girish";

   /* Problem:  trying to modify read only memory */
   *(str+1) = 'n';
   return 0;
}


//Trying to initialize a value on to the memory that has been freed. 
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // allocating memory to p
    int* p = malloc(8);
    *p = 100;

    // deallocated the space allocated to p
    free(p);

    // core dump/segmentation fault
    //  as now this statement is illegal
    *p = 110;
    return 0;
}


//Trying to access array out of bounds
#include <stdio.h>
int main()
{
   int arr[2];
   arr[3] = 10;  // Accessing out of bound
   return 0;
}


//Trying to pass value instead of address in scanf
// C program to demonstrate segmentation
// fault when value is passed to scanf
#include <stdio.h>

int main()
{
   int n = 2;
   scanf("%d",n);
   return 0;
}

//Trying to dereference a pointer value which is not pointing to a memory address

// C program to demonstrate segmentation
// fault when uninitialized pointer is accessed.
#include <stdio.h>

int main()
{
   int *p;
   *p = 23;
//   printf("%d",*p);
   printf("%d",p);
   return 0;
}

