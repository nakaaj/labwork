#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char* processLine(const char *line, int len, int start_index) {
    // Allocate memory for a new string
    char *temp = (char*)malloc((len + 1) * sizeof(char)); // +1 for the null terminator
    if (temp == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    strncpy(temp, line+start_index, len);
    temp[len] = '\0';
    return temp;
}

int main(){
    FILE *pdbfile;
    char temp1[4];
    pdbfile = fopen("1asy.pdb", "r");
    char line[100];
    int move = 0;
    // while (fgets(line, sizeof(line), pdbfile) != NULL){
    //     printf("%s\n",processLine(line,10,10));
    // }
    rewind(pdbfile);    
    while (fgets(line, sizeof(line), pdbfile) != NULL){
        strncpy(temp1,line,3);
        temp1[3] = '\0';
        if (strcmp(temp1,"TER") == 0){
            printf("%s\n",processLine(line,20,0));
            printf("%s\n",processLine(line,4,17));
            move = 1;
        }
        if (move){
            if (line[17] == ' '){
                move = 0;
            }
        }
        
    }
    fclose(pdbfile);
    return 0;
}

int main2(){
    char line[100] = "lorem hfffkffhgg oedkdfjf oeffflfk oeeoefkffjgg owwlwskddjdk sssodkkeekdkd";
    char *four[4];
    four[2] = processLine(line, 4, 12);
    //strncpy(four,processLine(line,4,10),sizeof(four));
    printf("%s\n",four[2]);
    printf("%d\n",strncmp(four[2],"fhgwg",4));
    return 0;
}
