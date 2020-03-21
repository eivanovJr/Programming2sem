#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <utility>

using namespace std;

class MyException : public exception
{
public:
    explicit MyException(string);
    [[nodiscard]] string getError() const;
private:
   string error;
};

#endif //LAB4_EXCEPTION_H
