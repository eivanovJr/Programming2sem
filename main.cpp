#include <iostream>
#include "Line.h"
#include "functions.hpp"
#include <vector>
#include <list>

using namespace std;

bool isWide(const Line &myLine)
{
    return myLine.getWidth() > myLine.getLength();
}

template<class T>
bool compare(T &A, T &B)
{
    if (!(A < B))
        return A == B;
    else
        return A < B;
}


int main()
{

    //1,5,8
    vector<Line> buff;
    list<Line> myList;
    buff.resize(10);
    double length = 3.14;
    double width = 32.4;
    Line mL = Line(3.14,32.4);
    for (int i = 0; i < 10; i++)
    {
        buff[9 - i] = Line(length, width);
        myList.emplace_back(length,width);
        length += 1.2;
        width += 0.3;
    }
    cout << all_of(buff.begin(), buff.end(), isWide) << "\t" <<all_of(myList.begin(), myList.end(), isWide) << "\n";
    cout << is_sorted(buff.begin(), buff.end(), compare<Line>) << "\t" << is_sorted(myList.begin(), myList.end(), compare<Line>) << "\n";
    cout << find_backward(buff.begin(), buff.end(), mL).getWidth() << "\t" << find_backward(myList.begin(), myList.end(), mL).getWidth();
    return 0;
}
