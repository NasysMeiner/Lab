#include <iostream>

using namespace std;


const char* words[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
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

char* CopyWord(int lenghtWord, int allLenght, char* timeLine, const char* word)
{
    char* newTimeLine = (char*)realloc(timeLine, (allLenght + 1) * sizeof(char));

    if (newTimeLine != NULL)
        timeLine = newTimeLine;
    else
        return;

    for (int i = allLenght - lenghtWord; i < allLenght; i++) 
    {
        *(timeLine + i) = *(word + (i + lenghtWord - allLenght));
    }

    timeLine[allLenght] = '\0';

    return timeLine;
}

char* ChangeTimeLine(int index, int* line, int* wordColumns, int* currentColumns, char* timeLine)
{
    LenghtLine(words[index], &*line, &*wordColumns);
    *currentColumns += *wordColumns;
    char* newTimeLine = CopyWord(*wordColumns, *currentColumns, timeLine, words[index]);

    return newTimeLine;
}

char* WriteNotDigit(int* currentColumns, char simbol, char* timeLine) 
{
    (*currentColumns)++;
    timeLine = (char*)realloc(timeLine, (*currentColumns + 1) * sizeof(char));
    timeLine[*currentColumns - 1] = simbol;
    timeLine[*currentColumns] = '\0';

    return timeLine;
}

void ChangeWords(char** sortArray, int* line) 
{
    int wordColumns;

    int currentColumns = 0;
    int value;
    int rotation = 0;
    char* arrayLine = (char*)malloc(sizeof(char));

    for(int i = *line; i > 0; i--)
    {
        LenghtLine(*sortArray, &value, &wordColumns);
        arrayLine = CopyWord(wordColumns, wordColumns, arrayLine, *sortArray);

        while ((arrayLine + rotation) && *(arrayLine + rotation) != '\0')
        {
            switch (*(arrayLine + rotation))
            {
                case '0':
                    *sortArray = ChangeTimeLine(0, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '1':
                    *sortArray = ChangeTimeLine(1, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '2':
                    *sortArray = ChangeTimeLine(2, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '3':
                    *sortArray = ChangeTimeLine(3, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '4':
                    *sortArray = ChangeTimeLine(4, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '5':
                    *sortArray = ChangeTimeLine(5, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '6':
                    *sortArray = ChangeTimeLine(6, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '7':
                    *sortArray = ChangeTimeLine(7, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '8':
                    *sortArray = ChangeTimeLine(8, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                case '9':
                    *sortArray = ChangeTimeLine(9, &value, &wordColumns, &currentColumns, *sortArray);
                    break;

                default:
                    *sortArray = WriteNotDigit(&currentColumns, *(arrayLine + rotation), *sortArray);
                    break;
            }

            rotation++;
        }

        free(arrayLine);
        arrayLine = (char*)malloc(sizeof(char));
        rotation = 0;
        currentColumns = 0;
    }

    free(arrayLine);
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

int main()
{
    int BUFF_LEN = 256;
    char* buf = (char*)malloc(BUFF_LEN * sizeof(char));

    printf("Enter the string: ");
    fgets(buf, BUFF_LEN, stdin);

    int lines;
    int value;
    int columns;
    LenghtLine(buf, &lines, &columns);

    char** strArray = CreateArray(columns, lines);
    WriteWord(strArray, buf);
    free(buf);

    ChangeWords(strArray, &lines);

    for (int i = 0; i < lines; i++)
    {
        LenghtLine(strArray[i], &value, &columns);
    }
    
    ReadArray(strArray, lines);
    ClearMemory(strArray, lines);
}
