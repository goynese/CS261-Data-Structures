/* CS261- Assignment 1 - Q.1*/
/* Name: Edward Goynes
 * Date: 10/4/11
 * Solution description: Create some students, output them, then delocate them.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>

# define EQ(a, b) (a == b)



struct student{
	int id;
	int score;
};

struct student* allocate(){
     struct student *stud = (struct student *) malloc(10*(sizeof(struct student)));

     return stud;
}

void generate(struct student* students){
     int i,j;

     for(i=0; i<10; i++)
     {
         students[i].id = rand()%11;
         students[i].score = rand()%101;
        /*
         for(j=0; j<10; j++)
         {
             if(students[i].id == students[j].id)
             i--;
         }
        */
     }

}

void output(struct student* students){
    int i;

    for(i=0; i<10; i++)
    {
       printf( "%d %d \n" ,students[i].id, students[i].score);
    }

}

void summary(struct student* students){
     int i,j=0,avg,min,max;

     for(i=0; i<10; i++)
     {
         avg = students[i].score;
         avg = j+avg;
     }

     min = students[0].score;

     for(i=0; i<10; i++)
     {
         if(students[i].score < min)
         {
             min = students[i].score;
         }
     }

     max = students[0].score;

      for(i=0; i<10; i++)
     {
         if(students[i].score > max)
         {
             max = students[i].score;
         }
     }

     printf("The minimum score %d, the maximum socre is %d, and the average score is %d \n", min, max, avg);
}

void deallocate(struct student* stud){
     free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;

    stud = allocate();
    generate(stud);
    output(stud);
    summary(stud);
    deallocate(stud);

    return 0;
}

