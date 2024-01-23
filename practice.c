#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *processLine(const char *line, int len, int start_index)
{
    // Allocate memory for a new string
    char *temp = (char *)malloc((len + 1) * sizeof(char)); // +1 for the null terminator
    if (temp == NULL)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    strncpy(temp, line + start_index, len);
    temp[len] = '\0';
    return temp;
}

int main()
{
    FILE *pdbfile;
    char temp1[4];
    pdbfile = fopen("1asy.pdb", "r");
    char line[100];
    int move = 0;
    int count = 5;
    // while (fgets(line, sizeof(line), pdbfile) != NULL){
    //     printf("%s\n",processLine(line,10,10));
    // }
    rewind(pdbfile);
    while (fgets(line, sizeof(line), pdbfile) != NULL)
    {
        if (move)
        {
            //printf("%s", line);
            if (strcmp(processLine(line,4,0),"ATOM") == 0 && line[17] != ' ' ){
                if (count){
                    printf("%s", line);
                    count = count - 1;
                }
            } 
            else {
                move = 0;
            }
        }
        strncpy(temp1, line, 3);
        temp1[3] = '\0';
        if (strcmp(temp1, "TER") == 0)
        {
            printf("%s\n", processLine(line, 20, 0));
            move = 1;
            count = 5;
        }
    }
    fclose(pdbfile);
    return 0;
}