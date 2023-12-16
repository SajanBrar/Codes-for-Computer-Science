#include <stdio.h>
#include <ctype.h>

typedef struct
{
    int characters;
    int words;
    int spaces;
    int lines;
} CountResult;

CountResult getCount(const char *filename)
{
    FILE *file = fopen(filename, "r");
    CountResult result = {0, 0, 0, 0};
    char ch;
    int insideWord = 0;

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return result;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        result.characters++;

        if (isspace(ch))
        {
            result.spaces++;

            if (ch == '\n')
                result.lines++;

            insideWord = 0;
        }
        else if (!insideWord)
        {
            result.words++;
            insideWord = 1;
        }
    }

    if (result.characters > 0)
        result.lines++;

    fclose(file);
    return result;
}

int main()
{
    CountResult result = getCount("Ques2_input.txt");

    printf("Number of characters: %d\n", result.characters);
    printf("Number of words: %d\n", result.words);
    printf("Number of spaces: %d\n", result.spaces);
    printf("Number of lines: %d\n", result.lines);

    return 0;
}