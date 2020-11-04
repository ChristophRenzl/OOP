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

    makefile(arguments);
  
    return 0;
}