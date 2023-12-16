#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main()
{
    FILE *file = fopen("Ques5_input.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0)
            {
                char *var_name = strtok(NULL, " ");
                char *equal_sign = strtok(NULL, " ");
                char *value = strtok(NULL, " ;\n");
                if (var_name != NULL && equal_sign != NULL && value != NULL)
                {
                    if (strcmp(token, "int") == 0)
                    {
                        int int_val = atoi(value);
                        printf("Integer: %s = %d\n", var_name, int_val);
                    }
                    else if (strcmp(token, "float") == 0)
                    {
                        float float_val = atof(value);
                        printf("Float: %s = %f\n", var_name, float_val);
                    }
                }
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);
    return 0;
}