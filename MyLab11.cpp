#include "MyLab11.h"

int LeangthWord(char* word)
{
    int leangthWord = 0;

    while (*word)
    {
        if (*(word++) && *(word) != '\0')
            leangthWord++;
    }

    return leangthWord;
}

int LeangthLine(char* line)
{
    int leangthWord = 0;

    while (*line)
    {
        if (*(line++) != '\n')
            leangthWord++;
    }

    return leangthWord;
}

int SearchIndexWord(char* line, char* word, int* leangth)
{
    *leangth = LeangthWord(word);

    int iteration = 0;

    while (*(line + iteration))
    {
        if (*line != ' ')
        {
            int coincidences = 0;

            do
            {
                if (*(line + (iteration++)) == word[coincidences])
                    coincidences++;

            } while (*(line + iteration) && *(line + iteration) != ' ' && *(line + iteration) != '\n');

            if (coincidences == *leangth)
                return iteration - coincidences;
        }
    }

    return -1;
}

char* DeleteWord(char* line, char* word)
{
    int leangthWord;
    int leangthLine = LeangthLine(line);
    int indexWord = SearchIndexWord(line, word, &leangthWord);

    if (indexWord == -1)
        return NULL;

    if (leangthLine == leangthWord)
        leangthLine++;

    char* newArray = (char*)malloc((leangthLine - leangthWord) * sizeof(char));

    int iterationLine = 0;
    int iterationWord = 0;
    int indexEndWord = 0;

    while (*(line + iterationLine) && *(line + iterationLine) != '\0' && *(line + iterationLine) != '\n' && iterationLine < leangthLine)
    {
        if (iterationLine == indexWord)
        {
            iterationLine += leangthWord + 1;

            continue;
        }

        newArray[iterationWord++] = *(line + iterationLine++);

        if (*(line + iterationLine) == ' ' || *(line + iterationLine) == '\n' || *(line + iterationLine) == '\0')
        {
            indexEndWord = iterationWord;
        }
    }

    newArray[indexEndWord] = '\0';

    free(line);

    return newArray;
}

void ReadArray(char* array)
{
    printf(array);
}

void InputLine(char* line, int MAX) 
{
    printf("Enter line: ");

    fgets(line, MAX, stdin);
}