#include "validator.h"

bool CompareCorner (color f, color s, color t, color x, color y, color z)
{
    bool first = (f == x || f == y || f == z);
    bool second = (s == x || s == y || s == z);
    bool third = (t == x || t == y || t == z);
    return (first && second && third);
}

bool CompareSide (color f, color s, color x, color y)
{
    bool first = (f == x || f == y);
    bool second = (s == x || s == y);
    return (first && second);
}

Validator::Validator(Cube* obj)
{
    checkValid = obj;
}

void Validator::ValidCorner(int number, color* result)
{
    brink* buff = checkValid->giveBuff();
    color *up = buff[5].getData();
    color *down = buff[0].getData();
    color *front = buff[1].getData();
    color *right = buff[2].getData();
    color *left = buff[4].getData();
    color *back = buff[3].getData();
    switch (number)
    {
        case 0 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[4].getMainColor();
            result[2] = buff[5].getMainColor();
        }
        break;
        case 1 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[2].getMainColor();
            result[2] = buff[5].getMainColor();
        }
        break;
        case 2 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[2].getMainColor();
            result[2] = buff[0].getMainColor();
        }
        break;
        case 3 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[4].getMainColor();
            result[2] = buff[0].getMainColor();
        }
        break;
        case 4 :
        {
            result[0] = buff[4].getMainColor();
            result[1] = buff[3].getMainColor();
            result[2] = buff[5].getMainColor();
        }
        break;
        case 5 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[4].getMainColor();
            result[2] = buff[0].getMainColor();
        }
        break;
        case 6 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[5].getMainColor();
            result[2] = buff[2].getMainColor();
        }
        break;
        case 7 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[2].getMainColor();
            result[2] = buff[0].getMainColor();
        }
        break;
    }
}

void Validator::ValidSide(int number, color* result)
{
    brink* buff = checkValid->giveBuff();
    color *up = buff[5].getData();
    color *down = buff[0].getData();
    color *front = buff[1].getData();
    color *right = buff[2].getData();
    color *left = buff[4].getData();
    color *back = buff[3].getData();
    switch (number)
    {
        case 0 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[4].getMainColor();
        }
            break;
        case 1 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[5].getMainColor();
        }
            break;
        case 2 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[2].getMainColor();
        }
            break;
        case 3 :
        {
            result[0] = buff[1].getMainColor();
            result[1] = buff[0].getMainColor();
        }
            break;
        case 4 :
        {
            result[0] = buff[5].getMainColor();
            result[1] = buff[4].getMainColor();
        }
            break;
        case 5 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[4].getMainColor();
        }
            break;
        case 6 :
        {
            result[0] = buff[0].getMainColor();
            result[1] = buff[4].getMainColor();
        }
            break;
        case 7 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[5].getMainColor();
        }
            break;
        case 8 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[0].getMainColor();
        }
            break;
        case 9 :
        {
            result[0] = buff[3].getMainColor();
            result[1] = buff[2].getMainColor();
        }
            break;
        case 10 :
        {
            result[0] = buff[2].getMainColor();
            result[1] = buff[5].getMainColor();
        }
            break;
        case 11 :
        {
            result[0] = buff[2].getMainColor();
            result[1] = buff[0].getMainColor();
        }
            break;
    }
}

void Validator::getCorners(color **answer)
{
    brink* buff = checkValid->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color * left = buff[4].getData();
    color* back = buff[3].getData();

    answer[0][1] = front[0];
    answer[0][2] = left[2];
    answer[0][0] = up[6];

    answer[1][1] = front[2];
    answer[1][2] = right[0];
    answer[1][0] = up[8];

    answer[2][1] = front[8];
    answer[2][2] = right[6];
    answer[2][0] = down[2];

    answer[3][1] = front[6];
    answer[3][2] = left[8];
    answer[3][0] = down[0];

    answer[4][1] = back[6];
    answer[4][2] = left[0];
    answer[4][0] = up[0];

    answer[5][1] = back[0];
    answer[5][2] = left[6];
    answer[5][0] = down[6];

    answer[6][1] = right[2];
    answer[6][2] = back[8];
    answer[6][0] = up[2];

    answer[7][1] = back[2];
    answer[7][2] = right[8];
    answer[7][0] = down[8];
}

void Validator::getSides(color** answer)
{
    brink* buff = checkValid->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color * left = buff[4].getData();
    color* back = buff[3].getData();

    answer[0][0] = front[1];
    answer[0][1] = up[7];

    answer[1][0] = front[5];
    answer[1][1] = right[3];

    answer[2][0] = front[7];
    answer[2][1] = down[1];

    answer[3][0] = front[3];
    answer[3][1] = left[5];

    answer[4][0] = left[1];
    answer[4][1] = up[3];

    answer[5][0] = left[7];
    answer[5][1] = down[3];

    answer[6][0] = left[3];
    answer[6][1] = back[3];

    answer[7][0] = back[7];
    answer[7][1] = up[1];

    answer[8][0] = back[1];
    answer[8][1] = down[7];

    answer[9][0] = back[5];
    answer[9][1] = right[5];

    answer[10][0] = right[1];
    answer[10][1] = up[5];

    answer[11][0] = right[7];
    answer[11][1] = down[5];
}

bool Validator::Validate()
{
    brink* buff = checkValid->giveBuff();
    std::vector<int> colorsCount;
    colorsCount.assign(6, 0);
    for (int i = 0; i < 6; i++)
    {
        color *temp = buff[i].getData();
        for (int j = 0; j < 9; j++)
        {
            if (temp[j] > 5 || temp[j] < 0)
                throw std::invalid_argument("Color not Valid\n");
            colorsCount[temp[j]]++;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (colorsCount[i] != 9)
        {
            std::cout << "Not Valid! \n";
            return false;
        }
    }

    auto **corners = new color*[8];
    for (int i = 0; i < 8; i++)
        corners[i] = new color[3];
    auto **sides = new color*[12];
    for (int i = 0; i < 12; i++)
        sides[i] = new color[2];
    getCorners(corners);
    getSides(sides);
    auto rightCorner = new color[3];
    bool match = false;
    for (int j = 0; j < 8; j++)
    {
        ValidCorner(j, rightCorner);
        for (int i = 0; i < 8; i++)
        {
            if (CompareCorner(corners[i][0], corners[i][1], corners[i][2], rightCorner[0], rightCorner[1], rightCorner[2]))
            {
                match = true;
            }
        }
        if (!match)
        {
            std::cout << "Not Valid!\n";
            return false;
        }
        match = false;
    }
    auto rightSide = new color[2];
    match = false;
    for (int j = 0; j < 12; j++)
    {
        ValidSide(j, rightSide);
        for (int i = 0; i < 12; i++)
        {
            if (CompareSide(sides[i][0], sides[i][1], rightSide[0], rightSide[1]))
            {
                match = true;
            }
        }
        if (!match)
        {
            std::cout << "Not Valid! \n";
            return false;
        }
        match = false;
    }
    std::cout << "Valid! \n";
    return true;
}