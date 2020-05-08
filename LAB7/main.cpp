#include <iostream>
#include <algorithm>
#include "RingBuff.hpp"

int main() {
    RingBuffer<int> myBuff(5);
    myBuff.push_front(1);
    myBuff.push_front(3);
    myBuff.push_back(5);
    myBuff.push_front(2);
    myBuff.pop(2);
    myBuff.push(2, 7);
    myBuff.push_back(9);
    sort(myBuff.begin(), myBuff.end());
    reverse(myBuff.begin(), myBuff.end());
    for (auto i = myBuff.begin(); i != myBuff.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n";
    myBuff.resize(10);
    myBuff.push_front(15);
    myBuff.push_back(34);
    for (auto i = myBuff.begin(); i != myBuff.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n";
    for (auto i = 0; i < myBuff.size(); ++i)
    {
        cout << myBuff[i] << " ";
    }
    cout << "\n";
    cout << *find(myBuff.begin(), myBuff.end(), 5) << "\n";
    cout << *find(myBuff.begin(), myBuff.end(), 9) << "\n";
    cout << *find(myBuff.begin(), myBuff.end(), 2) << "\n";
    cout << *find(myBuff.begin(), myBuff.end(), 1) << "\n";
    return 0;
}
