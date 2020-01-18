#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//getent passwd {1000..60000} >> users.txt
//ps -u claudiu >> proc.txt
//sched_getscheduler
int main()
{

    FILE *openUsers = fopen("users.txt", "r");
    
    char *line, **users;
    int i,j;
    int rows = 0;
    int column[10];

    line = (char*)malloc(100 *sizeof(char));
    users= (char **)malloc(5 * sizeof(char*));
    for(i = 0; i < rows; i++)
        users[i] = (char *)malloc(100 * sizeof(char));
   
    while (fscanf(openUsers,"%s",line)!= EOF) 
    { 
       column[rows] = 0;
       for(i = 0; i < strlen(line); i++)   
       {
            if(line[i] != ':') 
            {
               users[rows][i] = line[i];
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
           printf("%c\n",users[i][j]);
    }
    //int result = system(getUSers);


    fclose(openUsers);
    for(i = 0; i < rows; i++)
        free(users[i]);
    free(users);

    return 0;
}
