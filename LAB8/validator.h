#ifndef LAB8_VALIDATOR_H
#define LAB8_VALIDATOR_H

#include "cube.h"

class Validator
{
public:
    explicit Validator(Cube*);
    void getCorners(color**);
    void getSides(color**);
    void ValidCorner(int, color*);
    void ValidSide(int, color*);
    bool Validate();
private:
    Cube* checkValid;
};

#endif //LAB8_VALIDATOR_H
