#include "MyLab8.h"

int main()
{
    string numbersText;

    cout << "Enter numbers: ";

    getline(cin, numbersText);

    int lengthLocalMaximus = SearchLengthLocalMaximum(numbersText);

    cout << "The number of local maxima is equal to: " << lengthLocalMaximus << endl;
}
