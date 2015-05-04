/* CS261- Assignment 1 - Q.2*/
/* Name: Edward Goynes
 * Date: 10/1/11
 * Solution description: Playing with pointers. 
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    *a = *a*2;
    /*Here I was unsure that it would work from all the * symbols. But it did what the syntax says, Thankfully*/
    *b = *b/2;

    c = *a+*b;

    return c;
}

int main(){

    int x=5,y=6,z=7, foo_return=0 ;
    printf("X is %d, Y is %d, Z is %d\n", x,y,z);

    foo_return = foo(&x,&y,z);

    printf("X is %d, Y is %d, Z is %d\n", x,y,z);

    printf("The value returned by foo is %d \n", foo_return);
    /*I had the most difficult time printing out the return value of foo_return
    this is because I had a &d instead of %d and could not tell the difference. This
    took a long time for me to notice. */

    /*Is the return value different than the value of z?  Why?*/
        /* The return value of C is different than z because in the
        function it ressigns the value of c to a + b. Then it returns that*/
    return 0;
}


