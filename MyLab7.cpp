#include "MyLab7.h"

int LongConverter(string line)
{
    bool isHexadecimal = false;
    bool isOctal = false;
    bool isDecimal = true;

    int hexadecimal = 16;
    int octal = 8;
    int secimal = 1;

    int startNumber = 0;
    int exp;

    int lenght = line.size();

    if (line[0] == '0')
    {
        isDecimal = false;
        exp = lenght - 2;

        if (line[1] == 'x')
        {
            exp--;
            isHexadecimal = true;
            startNumber = 2;
        }
        else
        {
            isOctal = true;
            startNumber = 1;
        }
    }

    int result = 0;
    int digit = 0;

    for (int i = startNumber; i < lenght; i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            digit = line[i] - '0';
        }
        else if (line[i] >= 'A' && line[i] <= 'F')
        {
            digit = line[i] - 'A';
        }
        else
        {
            cout << "Incorrect input" << endl;

            return -1;
        }

        if (isDecimal)
        {
            result += digit * pow(10, lenght - 1 - i);
        }
        else if (isOctal)
        {
            if (digit >= 0 && digit <= 7)
            {
                result += digit * pow(octal, exp--);
            }
            else
            {
                cout << "Incorrect input" << endl;
            }
        }
        else if (isHexadecimal)
        {
            result += digit * pow(hexadecimal, exp--);
        }
    }

    return result;
}