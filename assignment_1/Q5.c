/* CS261- Assignment 1 - Q.5*/
/* Name: Edward Goynes
 * Date: 10/6/11
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     int i;
     for(i=0; word[i] != 0; i++)
     {
         if((64 < word[i] < 91) | (96 < word[i] < 123))
         {
             if(i == 0)
             {
                 if(0>(word[i]-90))
                 word[i] = toUpperCase(word[i]);
             }
             else if(i%2)
             {
                 if(0>(word[i]-90))
                 word[i] = toUpperCase(word[i]);
             }
             else
             {
                if(0<(word[i]-90))
                 word[i] = toLowerCase(word[i]);
             }
         }
     }
}

void print_pointer(char *string)
{
    int i;
    for(i=0; string[i] != 0; i++)
    {
        printf("%s", string[i]);
    }
}

int main(){
    char word[100];
    char *string = (char *) malloc(100*(sizeof(char)));

    printf("Type in a Word. \n");

    scanf("%s", word);

    string = &word[0];

    sticky(string);

    print_pointer(string);

    free(string);

    return 0;
}
