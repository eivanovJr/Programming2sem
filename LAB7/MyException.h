#ifndef ADVANCED_MYEXCEPTION_H
#define ADVANCED_MYEXCEPTION_H

class MyException : public exception
{
public:
    explicit MyException(string str)
    {
        error = move(str);
    }
    [[nodiscard]] string getError() const
    {
        return error;
    }
private:
    string error;
};

#endif //ADVANCED_MYEXCEPTION_H
