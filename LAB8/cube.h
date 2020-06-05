#ifndef LAB8_CUBE_H
#define LAB8_CUBE_H

#include "brink.hpp"

class Cube
{
public:
    [[nodiscard]] brink* giveBuff() const;
    void solve();
    void read(const std::string&);
    void write(const std::string&);
    void generate();
    void print() const;
    void rotateUp(bool);
    void rotateDown(bool);
    void rotateRight(bool);
    void rotateLeft(bool);
    void rotateFront(bool);
    void rotateBack(bool);
    bool solved();
    bool validCheck();
    Cube();
private:
    brink* buff;
};
#endif //LAB8_CUBE_H
