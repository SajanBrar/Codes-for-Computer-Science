#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lex(const char *input_file, const char *output_file)
{
    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL)
    {
        printf("Failed to open the input file.\n");
        return;
    }

    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL)
    {
        printf("Failed to open the output file.\n");
        fclose(input_fp);
        return;
    }

    int num_single_line_comments = 0;
    int num_multi_line_comments = 0;
    char line[1024];
    int inside_multi_line_comment = 0;

    while (fgets(line, sizeof(line), input_fp))
    {
        int i = 0;
        while (line[i] != '\0')
        {
            if (!inside_multi_line_comment && line[i] == '/' && line[i + 1] == '/')
            {
                num_single_line_comments++;
                break; // Move to the next line after finding a single-line comment
            }
            else if (!inside_multi_line_comment && line[i] == '/' && line[i + 1] == '*')
            {
                num_multi_line_comments++;
                inside_multi_line_comment = 1;
                i++;
            }
            else if (inside_multi_line_comment && line[i] == '*' && line[i + 1] == '/')
            {
                inside_multi_line_comment = 0;
                i++;
            }
            else
            {
                if (!inside_multi_line_comment)
                {
                    fputc(line[i], output_fp);
                }
            }
            i++;
        }
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("Number of single-line comments: %d\n", num_single_line_comments);
    printf("Number of multi-line comments: %d\n", num_multi_line_comments);
}

int main()
{
    lex("Ques3_input.txt", "Ques3_output.txt");
    return 0;
}