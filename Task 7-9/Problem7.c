#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () 
{
    int N ;
    FILE *f; //Declaring a pointer of type file
    f  = fopen ("data.txt", "w");
    printf("Enter N: ");
    scanf("%d",&N);
    srand (time(NULL)); // To randomize the seed
    for(int i = 0; i<N; i++)
    {
        fprintf(f, " %d \n", rand() %1000 );
    }
    fclose(f);
    return(0);
}