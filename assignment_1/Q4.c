/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct student{
	int id;
	int score;
};


void generate(struct student* students){
     int i,j;

     for(i=0; i<10; i++)
     {
         students[i].id = rand()%11;
         students[i].score = rand()%101;
     }

}
void output(struct student* students){
    int i;

    for(i=0; i<10; i++)
    {
       printf( "%d %d \n" ,students[i].id, students[i].score);
    }
    printf("\n");
}


void sort(struct student* students, int n){
          int i,k,j=0;

     for(i=0 ; i<(n*n); i++)
     {
         if(students[j].score > students[j+1].score)
         {
         k = students[j].score;
         students[j].score = students[j+1].score;
         students[j+1].score = k;
         }
         j++;

         if(j == (n-2))
            j=0;
     }
}

int main(){
    srand(time(NULL));
    int i,n = 20;


    struct student *stud = (struct student *) malloc(n * (sizeof(struct student)));

    generate(stud);

    output(stud);

    sort(stud, n);

    output(stud);

    return 0;
}
