#include <stdio.h>
#include <malloc.h>

using namespace std;

const char* words[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const int minLenghtWord = 3;
void LenghtLine(const char* line, int* lines, int* columns)
{
    int maxLenghtWord = 0;
    *lines = 0;
    *columns = 0;

    while (*line && *line != '\0')
    {
        if (*line != ' ' && *line != '\n')
        {
            do
            {
                maxLenghtWord++;
                line++;
            } while (*line && *line != ' ' && *line != '\n');

            if (maxLenghtWord > *columns)
            {
                *columns = maxLenghtWord;
            }

            (*lines)++;
            maxLenghtWord = 0;
        }
        else
        {
            line++;
        }
    }
}
char** CreateArray(int columns, int lines)
{
    char** newArray = (char**)malloc(lines * sizeof(char*));

    for (int i = 0; i < lines; i++)
    {
        newArray[i] = (char*)malloc((columns + 1) * sizeof(char));
    }

    return newArray;
}

void WriteWord(char** array, char* line)
{
    int lineWord = 0;
    int r = 0;

    while (*line && *line != '\n')
    {
        if (*line != ' ')
        {
            char* word = array[lineWord];

            do
            {
                *(word++) = *(line++);
            } while (*line && *line != ' ' && *line != '\n');

            *word = '\0';
            lineWord++;
        }
        else
        {
            line++;
        }
    }
}

void CopyDigit(int allLenght, char* currentWord, char digit) 
{
    currentWord = (char*)realloc(currentWord, (allLenght + 1) * sizeof(char));
    currentWord[allLenght - 1] = digit;
    currentWord[allLenght] = '\0';
}

void SearchDigit(char* word, int* currentLenghtWord, int* resultLenghtWord)
{
    int lines;
    int lenghtWord;

    if (*currentLenghtWord - *resultLenghtWord >= minLenghtWord)
    {
        for (int i = 0; i < 10; i++)
        {
            int matches = 0;
            int iteration = 0;
            LenghtLine(words[i], &lines, &lenghtWord);

            if (*currentLenghtWord - *resultLenghtWord >= lenghtWord)
            {
                for (int j = *resultLenghtWord; j < *currentLenghtWord; j++)
                {
                    if (word[j] == words[i][iteration])
                    {
                        matches++;
                        iteration++;
                    }
                    else
                    {
                        iteration = 0;
                        matches = 0;
                    }
                }

                if (matches == lenghtWord)
                {
                    *currentLenghtWord = *currentLenghtWord - lenghtWord + 1;
                    *resultLenghtWord = *currentLenghtWord;
                    CopyDigit(*currentLenghtWord, word, i + '0');

                    return;
                }
            }         
        }
    }
}

void ChangeWords(char** sortArray, int line)
{
    int lenghtLine = 0;
    int lenghtWord = 0;
    int resultLenghtWord = 0;

    char* timeLine = (char*)malloc(sizeof(char));
    
    for (int i = 0; i < line; i++)
    {
        timeLine = sortArray[i];
        char* timeWord = (char*)malloc(sizeof(char));

        while (*timeLine)
        {
            lenghtWord++;
            CopyDigit(lenghtWord, timeWord, *(timeLine++));
            SearchDigit(timeWord, &lenghtWord, &resultLenghtWord);
        }

        free(sortArray[i]);
        resultLenghtWord = 0;
        lenghtWord = 0;
        sortArray[i] = timeWord;
    }

}

void ReadArray(char** array, int lines)
{
    printf("\nChanged words:\n");

    for (int i = 0; i < lines; i++)
    {
        printf("%d - %s\n", i, *(array + i));
    }
}

void ClearMemory(char** array, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        free(array[i]);
    }

    free(array);
}

char* ReadStringConsole()
{
    int leanghtLine = 0;
    int capacity = 1;
    char* line = (char*)malloc(sizeof(char));

    printf("Enter the string: ");
    char symbol = getchar();

    while (symbol != '\n')
    {
        line[leanghtLine++] = symbol;

        if (leanghtLine >= capacity)
        {
            capacity *= 2;
            line = (char*)realloc(line, capacity * sizeof(char));
        }

        symbol = getchar();
    }

    line[leanghtLine] = '\0';

    return line;
}

int main()
{
    char* buf = ReadStringConsole();

    int lines;
    int columns;

    LenghtLine(buf, &lines, &columns);

    char** strArray = CreateArray(columns, lines);

    WriteWord(strArray, buf);

    ChangeWords(strArray, lines);

    ReadArray(strArray, lines);
    ClearMemory(strArray, lines);
}
