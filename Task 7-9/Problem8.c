#include <stdlib.h>
#include <stdio.h>  
#include "qsort.c"
//#define FILENAME "data.txt"

int main()
{
  char *line;
  ssize_t len = 0;
  ssize_t nread;
  FILE *fp;
  int line_count = 0;
  fp = fopen("data.txt", "r");
  if (!fp)
  {
    printf("Error Opening File");
    return EXIT_FAILURE;
  }
  int ch;
  int linenum = 0;

  //Count the number of lines in the file to use it for creating array
  while( (ch = fgetc(fp)) != EOF ) 
    {
        if( ch == '\n')
            linenum++;
    } 
  fclose(fp);

  //create an array to keep all the texts in the file
  int buffer[linenum];
  
   //read each line and put the number in the array named "buffer"
  fp = fopen("data.txt", "r");
  while ((nread = getline(&line, &len, fp))!=-1)
  {
    buffer[line_count] = atoi(line);
    line_count++;
  }
  fclose(fp);

  //use quicksort code from the imported file
  quicksort(buffer,0,linenum-1);

    //write sorted data into "data_sorted.txt"
  fp = fopen("data_sorted.txt","w");
  for(int j=0;j<line_count;j++)
  {
    fprintf(fp,"%d\n",buffer[j]);
  }
  fclose(fp);
  printf("Sorting Completed");
  return EXIT_SUCCESS;
}