#include "brink.h"

brink::brink()
{
    data = new color[9];
}

void brink::build(const color* buff)
{
    for (int i = 0; i < 9; i++)
    {
        data[i] = buff[i];
    }
    mainColor = data[4];
}

color brink::getMainColor() const
{
    return data[4];
}

brink::~brink()
{
    delete[] data;
}

color* brink::getData() const
{
    return data;
}

void brink::rotate_clockwise()
{
    color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = data[i];
    data[0] = data[6];
    data[1] = data[3];
    data[2] = temp[0];
    data[3] = data[7];
    data[6] = data[8];
    data[7] = data[5];
    data[8] = temp[2];
    data[5] = temp[1];
}

void brink::rotate_counter_clockwise()
{
    color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = data[i];
    data[0] = temp[2];
    data[1] = data[5];
    data[2] = data[8];
    data[5] = data[7];
    data[8] = data[6];
    data[7] = data[3];
    data[6] = temp[0];
    data[3] = temp[1];
}