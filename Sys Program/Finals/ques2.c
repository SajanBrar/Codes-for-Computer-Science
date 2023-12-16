#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_MACROS 100

typedef struct
{
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} Macro;

Macro macros[MAX_MACROS];
int num_macros = 0;

void read_macros(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if (strncmp(line, "#define", 7) == 0)
        {
            sscanf(line, "#define %s %s", macros[num_macros].name, macros[num_macros].value);
            num_macros++;
        }
    }

    fclose(file);
}

void resolve_line(char *line)
{
    int resolved = 1;
    while (resolved)
    {
        resolved = 0;
        for (int i = 0; i < num_macros; i++)
        {
            char *pos = strstr(line, macros[i].name);
            if (pos != NULL)
            {
                resolved = 1;
                int index = pos - line;
                int name_len = strlen(macros[i].name);
                int value_len = strlen(macros[i].value);

                memmove(pos + value_len, pos + name_len, strlen(pos + name_len) + 1);
                memcpy(pos, macros[i].value, value_len);
            }
        }
    }
}

void resolve_macros(const char *input_filename, const char *output_filename)
{
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL)
    {
        printf("Error opening input file: %s\n", input_filename);
        return;
    }

    if (output_file == NULL)
    {
        printf("Error opening output file: %s\n", output_filename);
        fclose(input_file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL)
    {
        if (strncmp(line, "#define", 7) == 0)
        {
            resolve_line(line);
            continue;
        }

        resolve_line(line);
        fprintf(output_file, "%s", line);
    }

    fclose(input_file);
    fclose(output_file);
}

int main()
{
    const char *input_filename = "ques2_input.c";
    const char *output_filename = "ques2_output.c";

    read_macros(input_filename);
    resolve_macros(input_filename, output_filename);

    printf("Macro processing completed successfully.\n");
    
    return 0;
}