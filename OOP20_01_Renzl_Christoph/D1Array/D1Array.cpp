#include <iostream>
#include <array>

using namespace std;

void coutarray(array<float, 12>arr)
{
    int help = 0;

    for (int z = 0; z < 3; z++)
    {
        for (int s = 0; s < 4; s++)
        {
            cout << arr[help++] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    array<float, 12>arr{ 0 };

    for (int i = 0; i < 12; i++)
    {
        arr[i] = i * 0.3456789;
    }
    coutarray(arr);

    return 0;
}