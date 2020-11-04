#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void makefile(vector<string> arguments)
{
        ofstream myfile;
        myfile.open("arguments.txt");
        for (int i = 0; i < arguments.size(); i++)
        {
            if (i == 0)
            {
                myfile << "Programmname=" << arguments[i]<<endl;
            }
            else {
                myfile << "Argument_" << i << "=" << arguments[i] << endl;
            }
        }
        
        myfile.close();
}

int main(int argc, char* argv[])
{
    vector<string> arguments;
    arguments.reserve(4);

    for (int i = 1; i < argc; i++)
    {
        arguments.emplace_back(argv[i]);
    }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
