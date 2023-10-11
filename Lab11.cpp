#include "MyLab11.h"

int main()
{
    int MAX = 256;
    char* line = (char*)malloc(MAX * sizeof(char));
    char* word = (char*)malloc(MAX * sizeof(char));

    InputLine(line, MAX);

    while (true)
    {
        InputLine(word, MAX);

        if (*word == '\n' || *word == NULL || *line == '\0')
            break;

        line = DeleteWord(line, word);

        if (*line == '\0' || line == NULL)
            break;

        printf("Edited line: %s\n", line);
    }

    printf("End");
}
