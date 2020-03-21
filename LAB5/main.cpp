#include <iostream>
#include "Exception.h"
#include "Matrix.hpp"

using namespace std;

template <typename T1>
T1 myMin(const T1 &x, const T1 &y)
{
    return x < y ? x : y;
}

int main()
{
    int x = 5, y = 8;
    double X = 5.5, Y = 5.8;
    float xx = 5.634, yy = 5.323;
    cout << myMin(x, y) << endl;
    cout << myMin(X, Y) << endl;
    cout << myMin(xx, yy) << endl;
    cout << myMin(5.0001, 6.5) << endl;

    Matrix<int> myMatrix(9,10);
    for (int i = 1; i <= 10; i++)
    {
        try
        {
            myMatrix.SetDigit(i, i, i);
        }
        catch(MyException &error)
        {
            cerr << "An error has occured : " << error.getError() << "\n";
        }
        cout << myMatrix.GetDigit(i, i) << endl;
    }
    return 0;
}
