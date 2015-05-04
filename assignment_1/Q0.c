/* CS261- Assignment 1 - Q. 0*/
/* Name: Edward Goynes
 * Date: 9/30/11
 * Solution description: Solution to ploblem 1 <:
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     printf("%d\n", *iptr);

     printf("%p\n", iptr);

     printf("%p\n", &iptr);
}

int main(){

    int x=1;

    printf("%p\n",&x);

    fooA(&x);

    printf("%d\n", x);

    return 0;
}
