#include "cube.h"
#include "solver.hpp"
#include "validator.hpp"

Cube::Cube()
{
    buff = new brink[6];
}

brink* Cube::giveBuff() const
{
    return buff;
}

void Cube::solve()
{
    if (!validCheck())
        return;
    CubeSolver solver(this);
    solver.solve();
}

void Cube::read(const std::string& input)
{
    int temp = 0;
    std::ifstream InputFile(input.c_str());
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 9; i++) {
            color *up = buff[j].getData();
            InputFile >> temp;
            switch (temp) {
                case 0 :
                    up[i] = BLUE;
                    break;
                case 1 :
                    up[i] = WHITE;
                    break;
                case 2 :
                    up[i] = RED;
                    break;
                case 3 :
                    up[i] = GREEN;
                    break;
                case 4 :
                    up[i] = YELLOW;
                    break;
                case 5 :
                    up[i] = ORANGE;
                    break;
                default :
                    throw std::exception();
            }
        }
    }
}

void Cube::write(const std::string& output)
{
    if (!validCheck())
        return;
    std::ofstream OutputFile(output.c_str());
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
            case 0 : OutputFile << "down :\n"; break;
            case 1 : OutputFile << "front :\n"; break;
            case 2 : OutputFile << "right :\n"; break;
            case 3 : OutputFile << "back :\n"; break;
            case 4 : OutputFile << "left :\n"; break;
            case 5 : OutputFile << "up :\n"; break;
        }
        color* temp = buff[i].getData();
        for (int j = 0; j < 9; j++)
        {
            OutputFile << temp[j] << " ";
            if ((j + 1) % 3 == 0 && j != 0)
                OutputFile << "\n";

        }
        OutputFile << "\n";
    }

}

void Cube::print() const
{
    for (int j = 0; j < 6; j++)
    {
        color* temp = buff[j].getData();
        switch (j)
        {
            case 0 : std::cout << "down :\n"; break;
            case 1 : std::cout << "front :\n"; break;
            case 2 : std::cout << "right :\n"; break;
            case 3 : std::cout << "back :\n"; break;
            case 4 : std::cout << "left :\n"; break;
            case 5 : std::cout << "up :\n"; break;
        }
        for (int i = 0; i < 9; i++)
        {
            std::cout << temp[i] << " ";
            if ((i + 1) % 3 == 0 && i != 0)
                std::cout << "\n";
        }
    }
}


bool Cube::validCheck()
{
    Validator isValid(this);
    return isValid.Validate();
}

void Cube::generate()
{
    for (int i = 0; i < 6; i++)
    {
        color* temp = buff[i].getData();
        for (int j = 0; j < 9; j++)
        {
            switch (i) {
                case 0 :
                    temp[j] = BLUE;
                    break;
                case 1 :
                    temp[j] = WHITE;
                    break;
                case 2 :
                    temp[j] = RED;
                    break;
                case 3 :
                    temp[j] = GREEN;
                    break;
                case 4 :
                    temp[j] = YELLOW;
                    break;
                case 5 :
                    temp[j] = ORANGE;
                    break;
            }
        }
    }
    print();
    srand(time(NULL));
    int rotations = (rand() % 50) + 1, rotate, direction;
    for (int i = 0; i < rotations; i++)
    {
        rotate = rand() % 6;
        direction = rand() % 2;
        switch (rotate)
        {
            case 0 :
            {
                rotateDown(direction == 0);
            }
                break;
            case 1 :
            {
                rotateFront(direction == 0);
            }
                break;
            case 2 :
            {
                rotateRight(direction == 0);
            }
                break;
            case 3 :
            {
                rotateBack(direction == 0);
            }
                break;
            case 4 :
            {
                rotateLeft(direction == 0);
            }
                break;
            case 5 :
            {
                rotateUp(direction == 0);
            }
                break;
        }

    }

}

void Cube::rotateFront(bool clockwise)
{
    color *up = buff[5].getData();
    color *down = buff[0].getData();
    color *right = buff[2].getData();
    color *left = buff[4].getData();
    color temp[3];
    temp[0] = up[6];
    temp[1] = up[7];
    temp[2] = up[8];
    if (clockwise)
    {
        buff[1].rotate_clockwise();
        up[6] = left[8];
        up[7] = left[5];
        up[8] = left[2];
        left[2] = down[0];
        left[5] = down[1];
        left[8] = down[2];
        down[0] = right[6];
        down[1] = right[3];
        down[2] = right[0];
        right[0] = temp[0];
        right[3] = temp[1];
        right[6] = temp[2];
    } else
    {
        buff[1].rotate_counter_clockwise();
        up[6] = right[0];
        up[7] = right[3];
        up[8] = right[6];
        right[0] = down[2];
        right[3] = down[1];
        right[6] = down[0];
        down[2] = left[8];
        down[1] = left[5];
        down[0] = left[2];
        left[8] = temp[0];
        left[5] = temp[1];
        left[2] = temp[2];
    }
}

void Cube::rotateUp(bool clockwise)
{
    color *left = buff[4].getData();
    color *back = buff[3].getData();
    color *right = buff[2].getData();
    color *front = buff[1].getData();
    color temp[3];
    temp[0] = back[6];
    temp[1] = back[7];
    temp[2] = back[8];
    if (clockwise)
    {
        buff[5].rotate_clockwise();
        back[6] = left[2];
        back[7] = left[1];
        back[8] = left[0];
        left[0] = front[0];
        left[1] = front[1];
        left[2] = front[2];
        front[0] = right[0];
        front[1] = right[1];
        front[2] = right[2];
        right[0] = temp[2];
        right[1] = temp[1];
        right[2] = temp[0];
    } else
    {
        buff[5].rotate_counter_clockwise();
        back[6] = right[2];
        back[7] = right[1];
        back[8] = right[0];
        right[2] = front[2];
        right[1] = front[1];
        right[0] = front[0];
        front[2] = left[2];
        front[1] = left[1];
        front[0] = left[0];
        left[2] = temp[0];
        left[1] = temp[1];
        left[0] = temp[2];
    }
}
void Cube::rotateRight(bool clockwise)
{
    color *down = buff[0].getData();
    color *back = buff[3].getData();
    color *up = buff[5].getData();
    color *front = buff[1].getData();
    color temp[3];
    temp[0] = up[8];
    temp[1] = up[5];
    temp[2] = up[2];
    if (clockwise)
    {
        buff[2].rotate_clockwise();
        up[8] = front[8];
        up[5] = front[5];
        up[2] = front[2];
        front[2] = down[2];
        front[5] = down[5];
        front[8] = down[8];
        down[2] = back[2];
        down[5] = back[5];
        down[8] = back[8];
        back[2] = temp[2];
        back[5] = temp[1];
        back[8] = temp[0];
    } else
    {
        buff[2].rotate_counter_clockwise();
        up[8] = back[8];
        up[5] = back[5];
        up[2] = back[2];
        back[8] = down[8];
        back[5] = down[5];
        back[2] = down[2];
        down[8] = front[8];
        down[5] = front[5];
        down[2] = front[2];
        front[8] = temp[0];
        front[5] = temp[1];
        front[2] = temp[2];
    }
}

void Cube::rotateLeft(bool clockwise)
{
    color *down = buff[0].getData();
    color *back = buff[3].getData();
    color *up = buff[5].getData();
    color *front = buff[1].getData();
    color temp[3];
    temp[0] = up[0];
    temp[1] = up[3];
    temp[2] = up[6];
    if (clockwise)
    {
        buff[4].rotate_clockwise();
        up[0] = back[0];
        up[3] = back[3];
        up[6] = back[6];
        back[6] = down[6];
        back[3] = down[3];
        back[0] = down[0];
        down[6] = front[6];
        down[3] = front[3];
        down[0] = front[0];
        front[0] = temp[0];
        front[3] = temp[1];
        front[6] = temp[2];
    } else
    {
        buff[4].rotate_counter_clockwise();
        up[0] = front[0];
        up[3] = front[3];
        up[6] = front[6];
        front[0] = down[0];
        front[3] = down[3];
        front[6] = down[6];
        down[0] = back[0];
        down[3] = back[3];
        down[6] = back[6];
        back[0] = temp[0];
        back[3] = temp[1];
        back[6] = temp[2];
    }
}

void Cube::rotateDown(bool clockwise)
{
    color *left = buff[4].getData();
    color *back = buff[3].getData();
    color *right = buff[2].getData();
    color *front = buff[1].getData();
    color temp[3];
    temp[0] = front[6];
    temp[1] = front[7];
    temp[2] = front[8];
    if (clockwise)
    {
        buff[0].rotate_clockwise();
        front[6] = left[6];
        front[7] = left[7];
        front[8] = left[8];
        left[8] = back[0];
        left[7] = back[1];
        left[6] = back[2];
        back[0] = right[8];
        back[1] = right[7];
        back[2] = right[6];
        right[8] = temp[2];
        right[7] = temp[1];
        right[6] = temp[0];
    } else
    {
        buff[0].rotate_counter_clockwise();
        front[6] = right[6];
        front[7] = right[7];
        front[8] = right[8];
        right[6] = back[2];
        right[7] = back[1];
        right[8] = back[0];
        back[2] = left[6];
        back[1] = left[7];
        back[0] = left[8];
        left[6] = temp[0];
        left[7] = temp[1];
        left[8] = temp[2];
    }
}

void Cube::rotateBack(bool clockwise)
{
    color *up = buff[5].getData();
    color *down = buff[0].getData();
    color *right = buff[2].getData();
    color *left = buff[4].getData();
    color temp[3];
    temp[0] = down[6];
    temp[1] = down[7];
    temp[2] = down[8];
    if (clockwise)
    {
        buff[3].rotate_clockwise();
        down[6] = left[0];
        down[7] = left[3];
        down[8] = left[6];
        left[6] = up[0];
        left[3] = up[1];
        left[0] = up[2];
        up[0] = right[2];
        up[1] = right[5];
        up[2] = right[8];
        right[2] = temp[2];
        right[5] = temp[1];
        right[8] = temp[0];
    } else
    {
        buff[3].rotate_counter_clockwise();
        down[6] = right[8];
        down[7] = right[5];
        down[8] = right[2];
        right[8] = up[2];
        right[5] = up[1];
        right[2] = up[0];
        up[2] = left[0];
        up[1] = left[3];
        up[0] = left[6];
        left[0] = temp[0];
        left[3] = temp[1];
        left[6] = temp[2];
    }
}

bool Cube::solved()
{
    bool solved = true;
    for (int i = 0; i < 6; i++)
    {
        color* temp = buff[i].getData();
        for (int j = 0; j < 9; j++)
        {
            if (temp[j] != buff[i].getMainColor())
            {
                solved = false;
            }
        }
    }
    return solved;
}