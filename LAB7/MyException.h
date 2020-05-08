#ifndef ADVANCED_MYEXCEPTION_H
#define ADVANCED_MYEXCEPTION_H

class MyException : public std::exception
{
public:
    explicit MyException(std::string str)
    {
        error = move(str);
    }
    [[nodiscard]] std::string getError() const
    {
        return error;
    }
private:
    std::string error;
};

#endif //ADVANCED_MYEXCEPTION_H
