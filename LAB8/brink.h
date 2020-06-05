#ifndef LAB8_BRINK_H
#define LAB8_BRINK_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

enum color{BLUE = 0, WHITE, RED, GREEN, YELLOW, ORANGE};

class brink
{
public:
    brink();
    void build(const color*);
    ~brink();
    [[nodiscard]] color* getData() const;
    [[nodiscard]] color getMainColor() const;
    void rotate_clockwise();
    void rotate_counter_clockwise();
private:
    color mainColor;
    color* data;
};

#endif //LAB8_BRINK_H
