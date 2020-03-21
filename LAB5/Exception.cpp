#include "Exception.h"

MyException::MyException(string str)
{
    error = move(str);
}

string MyException:: getError() const
{
    return error;
}
