#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

void printmatrix(const vector<vector<double>>& matrix,const double& det)
{
    cout << "\t[" << matrix[0][0] << "," << matrix[0][1] << "," << matrix[0][2] << "]" << endl;
    cout << "det\t[" << matrix[1][0] << "," << matrix[1][1] << "," << matrix[1][2] << "] =" << det << endl;
    cout << "\t[" << matrix[2][0] << "," << matrix[2][1] << "," << matrix[2][2] << "]" << endl;
}

vector<vector<double>> get_matrix(string filename)
{
    string line;
    vector<vector<double>> tmp;
    vector<double> var;
    tmp.reserve(3);
    ifstream myfile(filename);
 
    if (!myfile.is_open())
    {
        cerr << "Caannot open file!";
    }
    else{
        int z = 0;
        int s = 0;
            for(int i=1;i<10;i++)
            {
                getline(myfile, line, ',');
                var.push_back(stod(line));
                if (i % 3 == 0)
                {
                    tmp.push_back(var);
                    var.clear();
                }
            }
    }
    myfile.close();

    return tmp;
}

double calcdet(vector<vector<double>>& matrix)
{
    double d1, d2, d3, d4, d5, d6;
    double det;

    //00 01 02      00 01
    //10 11 12      10 11
    //20 21 22      20 21

    d1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
    d2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
    d3 = matrix[0][2] * matrix[1][0] * matrix[2][1];

    d4 = matrix[2][0] * matrix[1][1] * matrix[0][2];
    d5 = matrix[2][1] * matrix[1][2] * matrix[0][0];
    d6 = matrix[2][2] * matrix[1][0] * matrix[0][1];

    det = d1 + d2 + d3 -( d4 + d5 + d6);
    return det;
}



int main(int argc,char* argv[])
{
    vector<vector<double>> matrix;
    double det;
    matrix.reserve(3);
    matrix = get_matrix("2dim_matrix.txt");

    det = calcdet(matrix);

    printmatrix(matrix, det);
}