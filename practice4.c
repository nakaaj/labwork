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
    char temp1[5];
    pdbfile = fopen("1asy.pdb", "r");
    char line[100];
    int len = 0;
    char *linetemp[15000];

    // rewind(pdbfile);
    // printf("this is line \n");
    while (fgets(line, sizeof(line), pdbfile) != NULL)
    {
        strncpy(temp1, line, 4);
        temp1[4] = '\0';
        if (strcmp(temp1, "ATOM") == 0)
        {
            // printf("%s\n",processLine(line,30,0));
            linetemp[len] = processLine(line, 100, 0);
            len++;
        }
    }
    fclose(pdbfile);
    printf("%d \n", len);
    char atom_type[5];
    int serial_number;
    char atom_name[4];
    char residue_name[4];
    char chain_id;
    int residue_number;
    double x, y, z;
    double occupancy, temperature_factor;
    char element_symbol;
    for (int i = 0; i < len; i++)
    {
        // printf("%s",linetemp[i]);
        // printf("this is line\n");
    }
    sscanf(linetemp[45], "%4s %d %3s %3s %c %d %lf %lf %lf %lf %lf %c",
           atom_type, &serial_number, atom_name, residue_name, &chain_id,
           &residue_number, &x, &y, &z, &occupancy, &temperature_factor, &element_symbol);
    printf("Atom Type: %s\n", atom_type);
    printf("Serial Number: %d\n", serial_number);
    printf("Atom Name: %s\n", atom_name);
    printf("Residue Name: %s\n", residue_name);
    printf("Chain ID: %c\n", chain_id);
    printf("Residue Number: %d\n", residue_number);
    printf("Coordinates: (%lf, %lf, %lf)\n", x, y, z);
    printf("Occupancy: %lf\n", occupancy);
    printf("Temperature Factor: %lf\n", temperature_factor);
    printf("Element Symbol: %c\n", element_symbol);
    fclose(pdbfile);
    return 0;
}
