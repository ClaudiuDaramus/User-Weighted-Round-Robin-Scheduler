#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    FILE *open = fopen("proccesses.txt", "r");
    
    char *line, **proc;
    int i,j;
    int rows = 0;
    int column[10];

    line = (char*)malloc(100 *sizeof(char));
    proc= (char **)malloc(5 * sizeof(char*));
    for(i = 0; i < rows; i++)
        proc[i] = (char *)malloc(100 * sizeof(char));
   
    while (fscanf(open,"%s",line)!= EOF) 
    { 
       column[rows] = 0;
       for(i = 0; i < strlen(line); i++)   
       {
            if(line[i] != ':') 
            {
               proc[rows][i] = line[i];
               column[rows]++;
            } 
            else 
            {
               break;
            }
        }
        rows++;
    }

    for(i = 0; i < rows; i++) 
    {
        for(j = 0; j < column[i]; j++)
           printf("%c\n",proc[i][j]);
    }
  


    fclose(open);
    for(i = 0; i < rows; i++)
        free(proc[i]);
    free(proc);

    return 0;
}
