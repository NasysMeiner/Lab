#include "MyLab7.h"

int main()
{
    string line;

    cout << "Enter the number\n16 - 0xN...\n10 - N...\n8 - 0N...\nInput: ";

    getline(cin, line);

    int result = LongConverter(line);

    cout << "Final result: " << result << endl;

    return 0;
}
