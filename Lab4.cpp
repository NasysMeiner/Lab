#include <stdio.h>
#include <malloc.h>

char splitLine[100][256];
char sortWord[100][256];

void LengthWord(char *s, int *len) 
{
    *len = 0;

    while (*(s + *len) != '\n' && *(s + *len) != '\0' && *(s + *len))
    {
        (*len)++;
    }
}

void SortArray() 
{
    int len = 0;
    int r = 0;
    int index = 0;
    bool isNoRepeats = true;

    while (*splitLine[r])
    {
        LengthWord(splitLine[r], &len);
        /*char* ptr = sortWord[index];*/

        char* currentWord = splitLine[r];
        int numbersEmpty = 0;

        for (int i = 0; i < len - 1; i++) 
        {
            if (currentWord[i] == '\n')
                continue;

            for (int j = i + 1; j < len; j++) 
            {
                if (currentWord[i] == currentWord[j]) 
                {
                    currentWord[j] = '\n';
                    numbersEmpty++;
                }
            }
        }

        int iteration = 0;

        for (int i = 0; i < len; i++)
        {
            if (currentWord[i] == '\n')
            {
                int empty = 1;

                do
                {
                    if (currentWord[i + empty] != '\n')
                    {
                        currentWord[iteration++] = currentWord[i + empty];
                        currentWord[i + empty] = '\n';

                        break;
                    }
                    else
                    {
                        empty++;
                    }
                } while (i + empty < len);
            }
            else
            {
                iteration++;
            }

            if (numbersEmpty == len - numbersEmpty)
                break;
        }

        currentWord[len - numbersEmpty] = '\0';
        r++;

        /*for (int i = 0; i < len; i++) 
        {
            for (int j = i + 1; j < len; j++)
            {
                if (splitLine[r][i] == splitLine[r][j]) 
                {
                    isNoRepeats = false;

                    break;
                }
            }

            if (isNoRepeats == false)
                break;
        }

        if (isNoRepeats) 
        {
            int symbol = 0;

            while (splitLine[r][symbol] != '\0')
            {
                if(splitLine[r][symbol] != '\n')
                    *(ptr++) = splitLine[r][symbol];

                symbol++;
            }

            index++;
        }

        isNoRepeats = true;
        r++;*/
    }
}

void SplitLine(char *s) 
{
    int line = 0;

    while (*s) 
    {
        if (*s != ' ') 
        {
            char* ptr = splitLine[line++];

            do
            {
                *(ptr++) = *(s++);
            } while (*s && *s != ' ');
            *ptr = '\0';
        }
        else
        {
            s++;
        }
    }
}

void ReadSortArray() 
{
    int strLen = 0;
    char* str;

    printf("Words:");

    while (*splitLine[strLen])
    {
        str = splitLine[(strLen)++];
        printf("\n%d - %s", strLen, str);
    }
}

int main() 
{
    int BUFF_LEN = 256;
    char* buf = (char*)malloc(BUFF_LEN * sizeof(char));

    printf("Enter the string: ");
    fgets(buf, BUFF_LEN, stdin);

    SplitLine(buf);
    SortArray();
    ReadSortArray();
    
    return 0;
}
