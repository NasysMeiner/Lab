#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

using namespace std;

char splitLine[100][256];
char sortWord[100][256];

void LengthWord(char *s, int *len) 
{
    char* p = (char*)malloc(sizeof(char));
    *len = 0;

    while (*(s + *len) != '\n' && *(s + *len))
    {
        p = (s + *len);

        if(*p != '\0')
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
        char* ptr = sortWord[index];

        for (int i = 0; i < len; i++) 
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j)
                    continue;

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
            int word = 0;

            while (splitLine[r][word] != '\0')
            {
                if(splitLine[r][word] != '\n')
                    *(ptr++) = splitLine[r][word];

                word++;
            }

            index++;
        }

        isNoRepeats = true;
        r++;
    }
}

int SplitLine(char *s) 
{
    int line = 0;

    while (*s) 
    {
        if (*s != ' ') 
        {
            char *ptr = splitLine[line++];

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

    return line;
}

void ReadSortArray() 
{
    int strLen = 0;
    char* str;

    printf("Words:\n");

    while (*sortWord[strLen])
    {
        str = sortWord[(strLen)++];
        printf("%d - %s", strLen, str);
        printf("\n");
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
