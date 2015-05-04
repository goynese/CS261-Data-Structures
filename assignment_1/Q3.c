/* CS261- Assignment 1 - Q.3*/
/* Name: Edward Goynes
 * Date: 10/1/11
 * Solution description: Utilized bubble sort to sort the array from least to greatest. Noticed 
 Bubble Sort worst case big (0) of n squared.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     int i,k,j=0;

     for(i=0 ; i<(n*n); i++)
     {
         if(number[j] > number[j+1])
         {
         k = number[j];
         number[j] = number[j+1];
         number[j+1] = k;
         }

         j++;

         if(j == (n-1))
            j=0;
     }
}

void print_array(int *number, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("%d \n", number[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int n=20,i;

    int *number = (int *)malloc(n * sizeof(int));

    for(i=0; i<n; i++)
    {
        *(number+i) = rand();
    }

    print_array(number, n);

    sort(number,n);

    print_array(number, n);

    free(number);

    return 0;
}
