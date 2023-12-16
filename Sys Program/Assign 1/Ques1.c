#include <stdio.h>

// Function to create a file
void createFile()
{
    FILE *file = fopen("Ques1_output.txt", "w");
    if (file != NULL)
    {
        printf("Create Operation Successful.\n");
        fputs("Created File", file);
        fclose(file);
    }
    else
    {
        printf("Create Operation Failed.\n");
    }
}

// Function to read a file
void readFile()
{
    FILE *file = fopen("Ques1_input.txt", "r");
    if (file != NULL)
    {
        char ch;
        printf("File contents of createdFile.txt: ");
        while ((ch = fgetc(file)) != EOF)
        {
            putchar(ch);
        }
        printf("\n");
        fclose(file);
    }
    else
    {
        printf("Unable to open the file.\n");
    }
}

// Function to write contents to another file
void writeToFile()
{
    FILE *inputFile = fopen("Ques1_input.txt", "r");
    FILE *outputFile = fopen("Ques1_output.txt", "w");
    if (inputFile != NULL && outputFile != NULL)
    {
        char ch;
        while ((ch = fgetc(inputFile)) != EOF)
        {
            fputc(ch, outputFile);
        }
        printf("Written Operation Successful");
        fclose(inputFile);
        fclose(outputFile);
    }
    else
    {
        printf("Unable to open the files.\n");
    }
}

int main()
{
    createFile();
    readFile();
    writeToFile();
    return 0;
}