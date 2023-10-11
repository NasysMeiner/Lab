#include "MyLab8.h"

int SearchLenghtArray(string line)
{
    int leangthLine = line.size();
    int resultLeangth = 0;

    for (int i = 0; i < leangthLine; i++)
    {
        if (line[i] != ' ')
            resultLeangth++;
    }

    return resultLeangth;
}

int* CreateArray(int leangthArray)
{
    int* array = (int*)malloc(leangthArray * sizeof(int));

    return array;
}

int* WriteNumbers(int* array, string line)
{
    int index = 0;

    for (int i = 0; i < line.size(); i++)
    {
        int* number = &array[index++];
        *number = 0;

        if (line[i] != ' ')
        {
            int leanght = -1;
            int iteration = 0;

            do
            {
                leanght++;
                iteration++;

            } while (i + iteration < line.size() && line[i + iteration] != ' ');

            do
            {
                *number += (line[i++] - '0') * pow(10, leanght--);

            } while (i < line.size() && line[i] != ' ');
        }
    }

    return array;
}

int SearchLengthLocalMaximum(string line)
{
    int leangthNumberArray = SearchLenghtArray(line);
    int* numbersArray = CreateArray(leangthNumberArray);
    numbersArray = WriteNumbers(numbersArray, line);

    int leangthLocalMaximum = 0;

    for (int i = 0; i < leangthNumberArray; i++)
    {
        if (i == 0 && numbersArray[i] > numbersArray[i + 1] || i == leangthNumberArray - 1 && numbersArray[i] > numbersArray[i - 1])
        {
            leangthLocalMaximum++;
            i++;
        }
        else if (numbersArray[i] > numbersArray[i + 1] && numbersArray[i] > numbersArray[i - 1])
        {
            leangthLocalMaximum++;
            i++;
        }
    }

    free(numbersArray);

    return leangthLocalMaximum;
}