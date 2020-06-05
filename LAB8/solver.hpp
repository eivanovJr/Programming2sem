#include "solver.h"

CubeSolver::CubeSolver(Cube *obj)
{
    toSolve = obj;
}

bool CubeSolver::first_step(std::vector<std::string> &answer)
{
    bool match = true;
    std::vector<int> action;
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color * left = buff[4].getData();
    color* back = buff[3].getData();
    if (front[1] == buff[1].getMainColor() && up[7] == buff[0].getMainColor())
    {
        toSolve->rotateFront(true);
        toSolve->rotateFront(true);
        answer.emplace_back("front rotate 180 grades");
        action.push_back(1);
    }
    else if (right[1] == buff[2].getMainColor() && up[5] == buff[0].getMainColor())
    {
        toSolve->rotateRight(true);
        toSolve->rotateRight(true);
        answer.emplace_back("right rotate 180 grades");
        action.push_back(2);
    }
    else if (left[1] == buff[4].getMainColor() && up[3] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(true);
        toSolve->rotateLeft(true);
        answer.emplace_back("left rotate 180 grades");
        action.push_back(3);
    }
    else if (back[7] == buff[3].getMainColor() && up[1] == buff[0].getMainColor())
    {
        toSolve->rotateBack(true);
        toSolve->rotateBack(true);
        answer.emplace_back("back rotate 180 grades");
        action.push_back(4);
    }
    else if (front[1] == buff[0].getMainColor() && up[7] == buff[1].getMainColor())
    {
        toSolve->rotateUp(false);
        toSolve->rotateRight(false);
        toSolve->rotateFront(true);
        toSolve->rotateRight(true);
        answer.emplace_back("Up counter clockwise");
        answer.emplace_back("Right counter clockwise");
        answer.emplace_back("Front clockwise");
        answer.emplace_back("Right clockwise");
        action.push_back(5);
    }
    else if (up[5] == buff[2].getMainColor() && right[1] == buff[0].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("Back counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("Right clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("Back clockwise");
        action.push_back(6);
    }
    else if (left[1] == buff[0].getMainColor() && up[3] == buff[4].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("Front counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("Left clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("Front clockwise");
        action.push_back(7);
    }
    else if (up[1] == buff[3].getMainColor() && back[7] == buff[0].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("Left counter clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("Back clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("Left clockwise");
        action.push_back(8);
    }
    else if (front[5] == buff[0].getMainColor())
    {
        toSolve->rotateFront(false);
        answer.emplace_back("Front counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("Front clockwise");
        action.push_back(9);
    }
    else if (right[5] == buff[0].getMainColor())
    {
        toSolve->rotateRight(false);
        answer.emplace_back("Right counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("Right clockwise");
        action.push_back(10);
    }
    else if (left[5] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(false);
        answer.emplace_back("Left counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("Left clockwise");
        action.push_back(11);
    }
    else if (back[3] == buff[0].getMainColor())
    {
        toSolve->rotateBack(false);
        answer.emplace_back("Back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("Back clockwise");
        action.push_back(12);
    }
    else if (front[3] == buff[0].getMainColor())
    {
        toSolve->rotateFront(true);
        answer.emplace_back("Front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("Front counter clockwise");
        action.push_back(13);
    }
    else if (right[3] == buff[0].getMainColor())
    {
        toSolve->rotateRight(true);
        answer.emplace_back("Right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("Right counter clockwise");
        action.push_back(14);
    }
    else if (left[3] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(true);
        answer.emplace_back("Left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("Left counter clockwise");
        action.push_back(15);
    }
    else if (back[5] == buff[0].getMainColor())
    {
        toSolve->rotateBack(true);
        answer.emplace_back("Back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("Back counter clockwise");
        action.push_back(16);
    }
    else if (front[7] == buff[0].getMainColor())
    {
        toSolve->rotateFront(true);
        toSolve->rotateFront(true);
        answer.emplace_back("Front rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateFront(true);
        toSolve->rotateFront(true);
        answer.emplace_back("Front rotate 180 degrees");
        action.push_back(17);
    }
    else if (right[7] == buff[0].getMainColor())
    {
        toSolve->rotateRight(true);
        toSolve->rotateRight(true);
        answer.emplace_back("Right rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateRight(true);
        toSolve->rotateRight(true);
        answer.emplace_back("Right rotate 180 degrees");
        action.push_back(18);
    }
    else if (left[7] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(true);
        toSolve->rotateLeft(true);
        answer.emplace_back("Left rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateLeft(true);
        toSolve->rotateLeft(true);
        answer.emplace_back("Left rotate 180 degrees");
        action.push_back(19);
    }
    else if (back[1] == buff[0].getMainColor())
    {
        toSolve->rotateBack(true);
        toSolve->rotateBack(true);
        answer.emplace_back("Back rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateBack(true);
        toSolve->rotateBack(true);
        answer.emplace_back("Back rotate 180 degrees");
        action.push_back(20);
    }
    else if (down[1] == buff[0].getMainColor()  && front[7] != buff[1].getMainColor())
    {
        toSolve->rotateFront(true);
        toSolve->rotateFront(true);
        answer.emplace_back("Front rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateFront(true);
        toSolve->rotateFront(true);
        answer.emplace_back("Front rotate 180 degrees");
        action.push_back(21);
    }
    else if (down[5] == buff[0].getMainColor() && right[7] != buff[2].getMainColor())
    {
        toSolve->rotateRight(true);
        toSolve->rotateRight(true);
        answer.emplace_back("Right rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateRight(true);
        toSolve->rotateRight(true);
        answer.emplace_back("Right rotate 180 degrees");
        action.push_back(22);
    }
    else if (down[3] == buff[0].getMainColor() && left[7] != buff[4].getMainColor())
    {
        toSolve->rotateLeft(true);
        toSolve->rotateLeft(true);
        answer.emplace_back("Left rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateLeft(true);
        toSolve->rotateLeft(true);
        answer.emplace_back("Left rotate 180 degrees");
        action.push_back(23);

    }
    else if (down[7] == buff[0].getMainColor() && back[1] != buff[3].getMainColor())
    {
        toSolve->rotateBack(true);
        toSolve->rotateBack(true);
        answer.emplace_back("Back rotate 180 degrees");
        toSolve->rotateUp(false);
        answer.emplace_back("Up counter clockwise");
        toSolve->rotateBack(true);
        toSolve->rotateBack(true);
        answer.emplace_back("Back rotate 180 degrees");
        action.push_back(24);
    }
    if (action.empty())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("Up clockwise");
        match = false;
    }
    return match;
}

bool CubeSolver::second_step(std::vector<std::string> &answer)
{
    bool match = true;
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();

    if (front[7] == buff[1].getMainColor() && front[2] == buff[0].getMainColor() && right[0] == buff[2].getMainColor()
        && right[7] == buff[2].getMainColor() && up[8] == buff[1].getMainColor())
    {
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else if (front[0] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && left[2] == buff[0].getMainColor()
             && left[7] == buff[4].getMainColor() && up[6] == buff[4].getMainColor())
    {
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[8] == buff[3].getMainColor() && right[2] == buff[0].getMainColor()
             && right[7] == buff[2].getMainColor() && up[2] == buff[2].getMainColor())
    {
        toSolve->rotateRight(false);
        toSolve->rotateUp(false);
        toSolve->rotateRight(true);
        answer.emplace_back("right counter clockwise");
        answer.emplace_back("up counter clockwise");
        answer.emplace_back("right clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[6] == buff[0].getMainColor() && left[0] == buff[4].getMainColor()
             && left[7] == buff[4].getMainColor() && up[0] == buff[3].getMainColor())
    {
        toSolve->rotateBack(false);
        toSolve->rotateUp(false);
        toSolve->rotateBack(true);
        answer.emplace_back("back counter clockwise");
        answer.emplace_back("up counter clockwise");
        answer.emplace_back("back clockwise");
    }
    else if (front[2] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && right[0] == buff[0].getMainColor()
             && right[7] == buff[2].getMainColor() && up[8] == buff[2].getMainColor())
    {
        toSolve->rotateRight(true);
        toSolve->rotateUp(true);
        toSolve->rotateRight(false);
        answer.emplace_back("right clockwise");
        answer.emplace_back("up clockwise");
        answer.emplace_back("right counter clockwise");
    }
    else if (front[0] == buff[0].getMainColor() && front[7] == buff[1].getMainColor() && up[6] == buff[1].getMainColor()
             && left[2] == buff[4].getMainColor() && left[7] == buff[4].getMainColor())
    {
        toSolve->rotateFront(true);
        toSolve->rotateUp(true);
        toSolve->rotateFront(false);
        answer.emplace_back("front clockwise");
        answer.emplace_back("up clockwise");
        answer.emplace_back("front counter clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[8] == buff[0].getMainColor() && right[2] == buff[2].getMainColor()
             && right[7] == buff[2].getMainColor() && up[2] == buff[3].getMainColor())
    {
        toSolve->rotateBack(true);
        toSolve->rotateUp(true);
        toSolve->rotateBack(false);
        answer.emplace_back("back clockwise");
        answer.emplace_back("up clockwise");
        answer.emplace_back("back counter clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[6] == buff[3].getMainColor() && left[0] == buff[0].getMainColor()
             && up[0] == buff[4].getMainColor() && left[7] == buff[4].getMainColor())
    {
        toSolve->rotateLeft(true);
        toSolve->rotateUp(true);
        toSolve->rotateLeft(false);
        answer.emplace_back("left clockwise");
        answer.emplace_back("up clockwise");
        answer.emplace_back("left counter clockwise");
    }
    else if (front[7] == buff[1].getMainColor() && front[2] == buff[2].getMainColor() && up[8] == buff[0].getMainColor()
             && right[0] == buff[1].getMainColor() && right[7] == buff[2].getMainColor())
    {
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up rotate 180 grades");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
    else if (front[0] == buff[4].getMainColor() && front[7] == buff[1].getMainColor() && left[2] == buff[1].getMainColor()
             && left[7] == buff[4].getMainColor() && up[6] == buff[0].getMainColor())
    {
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up rotate 180 degrees");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[8] == buff[2].getMainColor() && right[7] == buff[2].getMainColor()
             && right[2] == buff[3].getMainColor() && up[2] == buff[0].getMainColor())
    {
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up rotate 180 degrees");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[6] == buff[4].getMainColor() && left[0] == buff[3].getMainColor()
             && left[7] == buff[4].getMainColor() && up[0] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        toSolve->rotateUp(false);
        answer.emplace_back("up rotate 180 degrees");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
    }
    else if (front[7] == buff[1].getMainColor() && front[8] == buff[0].getMainColor() && right[7] == buff[2].getMainColor())
    {
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else if (front[7] == buff[1].getMainColor() && left[7] == buff[4].getMainColor() && left[8] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && right[7] == buff[2].getMainColor() && right[8] == buff[0].getMainColor())
    {
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && back[0] == buff[0].getMainColor() && left[7] == buff[4].getMainColor())
    {
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
    }
    else if (front[7] == buff[1].getMainColor() && right[6] == buff[0].getMainColor() && right[7] == buff[2].getMainColor())
    {
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else if (front[7] == buff[1].getMainColor() && front[6] == buff[0].getMainColor() && left[7] == buff[4].getMainColor())
    {
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
    }
    else if (back[2] == buff[0].getMainColor() && back[1] == buff[3].getMainColor() && right[7] == buff[2].getMainColor())
    {
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && left[7] == buff[4].getMainColor() && left[6] == buff[0].getMainColor())
    {
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
    }
    else if (down[0] == buff[0].getMainColor() && down[1] == buff[0].getMainColor() && down[3] == buff[0].getMainColor()
             && down[4] == buff[0].getMainColor() && down[5] == buff[0].getMainColor() && down[7] == buff[0].getMainColor()
             && front[7] == buff[1].getMainColor() && left[7] == buff[4].getMainColor() && (front[6] != buff[1].getMainColor() || left[8] != buff[4].getMainColor()))
    {
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
    }
    else if (front[7] == buff[1].getMainColor() && down[1] == buff[0].getMainColor() && down[2] == buff[0].getMainColor()
             && down[3] == buff[0].getMainColor() && down[4] == buff[0].getMainColor() && down[5] == buff[0].getMainColor() && down[7] == buff[0].getMainColor()
             && (front[8] != buff[1].getMainColor() || right[6] != buff[2].getMainColor()) && right[7] == buff[2].getMainColor())
    {
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
    else if ((back[2] != buff[3].getMainColor() || right[8] != buff[2].getMainColor()) && back[1] == buff[3].getMainColor() && right[7] == buff[2].getMainColor()
             && down[8] == buff[0].getMainColor() && down[7] == buff[0].getMainColor() && down[5] == buff[0].getMainColor() && down[4] == buff[0].getMainColor()
             && down[3] == buff[0].getMainColor() && down[1] == buff[0].getMainColor())
    {
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
    }
    else if (back[1] == buff[3].getMainColor() && left[7] == buff[4].getMainColor() &&
             (back[0] != buff[3].getMainColor() || left[6] != buff[4].getMainColor()) &&
             down[7] == buff[0].getMainColor() && down[6] == buff[0].getMainColor() && down[5] == buff[0].getMainColor()
             && down[4] == buff[0].getMainColor() && down[3] == buff[0].getMainColor() && down[1] == buff[0].getMainColor())
    {
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
    } else
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        match = false;
    }
    return match;
}

bool CubeSolver::third_step(std::vector<std::string> &answer)
{
    bool match = true;
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();

    if (front[8] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[6] == buff[1].getMainColor()
        && front[1] == buff[1].getMainColor() && left[8] == buff[4].getMainColor() &&
        left[7] == buff[4].getMainColor() && left[6] == buff[4].getMainColor() && up[7] == buff[4].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
    }
    else if (front[8] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[6] == buff[1].getMainColor()
             && right[8] == buff[2].getMainColor() && right[7] == buff[2].getMainColor() && right[6] == buff[2].getMainColor()
             && right[1] == buff[2].getMainColor() && up[5] == buff[1].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
    else if (back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && back[7] == buff[3].getMainColor() && right[8] == buff[2].getMainColor() && right[7] == buff[2].getMainColor()
             && right[6] == buff[2].getMainColor() && up[1] == buff[2].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
    }
    else if (back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && left[8] == buff[4].getMainColor() && left[7] == buff[4].getMainColor() && left[6] == buff[4].getMainColor() && left[1] == buff[4].getMainColor()
             && up[3] == buff[3].getMainColor())
    {
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
    }
    else if (front[8] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[6] == buff[1].getMainColor() && front[1] == buff[1].getMainColor()
             && right[8] == buff[2].getMainColor() && right[7] == buff[2].getMainColor() && right[6] == buff[2].getMainColor()
             && up[7] == buff[2].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else if (front[8] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[6] == buff[1].getMainColor()
             && left[8] == buff[4].getMainColor() && left[7] == buff[4].getMainColor() && left[6] == buff[4].getMainColor()
             && left[1] == buff[4].getMainColor() && up[3] == buff[1].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
    }
    else if (back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && back[7] == buff[3].getMainColor() && left[8] == buff[4].getMainColor() && left[7] == buff[4].getMainColor()
             && left[6] == buff[4].getMainColor() && up[1] == buff[4].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
    }
    else if (back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && right[8] == buff[2].getMainColor() && right[7] == buff[2].getMainColor() && right[6] == buff[2].getMainColor()
             && right[1] == buff[2].getMainColor() && up[5] == buff[3].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
    } else
    {
        match = false;
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
    }
    return match;
}

bool CubeSolver::advanced_third(std::vector<std::string> &answer)
{
    bool match = true;
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();
    if (front[8] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[6] == buff[1].getMainColor()
        && (front[5] != buff[1].getMainColor() || right[3] != buff[2].getMainColor()) && right[6] == buff[2].getMainColor()
        && right[7] == buff[2].getMainColor() && right[8] == buff[2].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else if (front[8] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[6] == buff[1].getMainColor()
             && (front[3] != buff[1].getMainColor() || left[5] != buff[4].getMainColor()) && left[8] == buff[4].getMainColor()
             && left[7] == buff[4].getMainColor() && left[6] == buff[4].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
    }
    else if (back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && (back[3] != buff[3].getMainColor() || left[3] != buff[4].getMainColor()) && left[8] == buff[4].getMainColor()
             && left[7] == buff[4].getMainColor() && left[6] == buff[4].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
    }
    else if (back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor() &&
             (back[5] != buff[3].getMainColor() || right[5] != buff[2].getMainColor()) && right[8] == buff[2].getMainColor()
             && right[7] == buff[2].getMainColor() && right[6] == buff[2].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
    } else
    {
        match = false;
    }
    return match;
}

void CubeSolver::fourth_step(std::vector<std::string> &answer)
{
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();

    if (front[3] == buff[1].getMainColor() && front[5] == buff[1].getMainColor()
        && front[6] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[8] == buff[1].getMainColor() && front[1] == buff[5].getMainColor()
        && right[3] == buff[2].getMainColor() && right[5] == buff[2].getMainColor() && right[1] == buff[5].getMainColor()
        && right[6] == buff[2].getMainColor() && right[7] == buff[2].getMainColor() && right[8] == buff[2].getMainColor()
        && up[3] == buff[5].getMainColor() && up[1] == buff[5].getMainColor())
    {
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
    }
    else if (front[3] == buff[1].getMainColor() && front[5] == buff[1].getMainColor()
             && front[6] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[8] == buff[1].getMainColor() && front[1] == buff[5].getMainColor()
             && left[1] == buff[5].getMainColor() && left[3] == buff[4].getMainColor() && left[5] == buff[4].getMainColor()
             && left[6] == buff[4].getMainColor() && left[7] == buff[4].getMainColor() && left[8] == buff[4].getMainColor()
             && up[1] == buff[5].getMainColor() && up[5] == buff[5].getMainColor())
    {
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
    }
    else if (back[7] == buff[5].getMainColor() && back[0] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && back[1] == buff[3].getMainColor() && back[5] == buff[3].getMainColor() && back[3] == buff[3].getMainColor()
             && right[3] == buff[2].getMainColor() && right[5] == buff[2].getMainColor() && right[6] == buff[2].getMainColor()
             && right[7] == buff[2].getMainColor() && right[8] == buff[2].getMainColor() && right[1] == buff[5].getMainColor()
             && up[3] == buff[5].getMainColor() && up[7] == buff[5].getMainColor())
    {
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
    else if (up[7] == buff[5].getMainColor() && up[5] == buff[5].getMainColor() && left[1] == buff[5].getMainColor() && back[7] == buff[5].getMainColor()
             && back[5] == buff[3].getMainColor() && back[3] == buff[3].getMainColor() && back[0] == buff[3].getMainColor() && back[1] == buff[3].getMainColor() && back[2] == buff[3].getMainColor()
             && left[3] == buff[4].getMainColor() && left[5] == buff[4].getMainColor() && left[6] == buff[4].getMainColor() && left[7] == buff[4].getMainColor() && left[8] == buff[4].getMainColor())
    {
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
    }
    else if (up[3] == buff[5].getMainColor() && up[5] == buff[5].getMainColor() && back[7] == buff[5].getMainColor()
             && front[1] == buff[5].getMainColor() && front[3] == buff[1].getMainColor() && front[5] == buff[1].getMainColor()
             && front[6] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[8] == buff[1].getMainColor()
             && right[3] == buff[2].getMainColor() && right[5] == buff[2].getMainColor() && right[6] == buff[2].getMainColor()
             && right[7] == buff[2].getMainColor() && right[8] == buff[2].getMainColor())
    {
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
    }
    else if (front[3] == buff[1].getMainColor() && front[5] == buff[1].getMainColor() && up[7] == buff[5].getMainColor()
             && front[6] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[8] == buff[1].getMainColor()
             && right[3] == buff[2].getMainColor() && right[5] == buff[2].getMainColor() && right[6] == buff[2].getMainColor() && right[1] == buff[5].getMainColor()
             && right[7] == buff[2].getMainColor() && right[8] == buff[2].getMainColor() && up[1] == buff[5].getMainColor() && left[1] == buff[5].getMainColor())
    {
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
    else if (front[1] == buff[5].getMainColor() && front[3] == buff[1].getMainColor() && front[5] == buff[1].getMainColor()
             && front[6] == buff[1].getMainColor() && front[7] == buff[1].getMainColor() && front[8] == buff[1].getMainColor()
             && right[3] == buff[2].getMainColor() && right[5] == buff[2].getMainColor() && right[6] == buff[2].getMainColor()
             && right[7] == buff[2].getMainColor() && right[8] == buff[2].getMainColor() && right[1] == buff[5].getMainColor()
             && left[1] == buff[5].getMainColor() && back[7] == buff[5].getMainColor())
    {
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        answer.emplace_back("up counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
}

void CubeSolver::fifth_step(std::vector<std::string> &answer)
{
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();

    if (right[1] == buff[1].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(false);
        toSolve->rotateUp(false);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
    }
    else  if (left[1] == buff[1].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(false);
        toSolve->rotateUp(false);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
    }
    else if (back[7] == buff[1].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
    }
    if (back[7] == buff[2].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else if (left[1] == buff[2].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
    }
    if (left[1] == buff[3].getMainColor())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        toSolve->rotateUp(true);
        answer.emplace_back("up 180 rotate");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
    }
}

bool comparator (color f, color s, color t, color x, color y, color z)
{
    bool first = (f == x || f == y || f == z);
    bool second = (s == x || s == y || s == z);
    bool third = (t == x || t == y || t == z);
    return (first && second && third);
}

bool CubeSolver::sixth_step(std::vector<std::string> &answer)
{
    bool first_attempt = false;
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();
    if (comparator(front[0], left[2], up[6], buff[1].getMainColor(), buff[2].getMainColor(), buff[5].getMainColor()))
    {
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        first_attempt = true;
    }
    else if (comparator(back[8], right[2], up[2], buff[1].getMainColor(), buff[2].getMainColor(), buff[5].getMainColor()))
    {
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        first_attempt = true;
    }
    else if (comparator(back[6], left[0], up[0], buff[1].getMainColor(), buff[2].getMainColor(), buff[5].getMainColor()))
    {
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateBack(false);
        answer.emplace_back("back counter clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateLeft(false);
        answer.emplace_back("left counter clockwise");
        toSolve->rotateBack(true);
        answer.emplace_back("back clockwise");
        toSolve->rotateLeft(true);
        answer.emplace_back("left clockwise");
        first_attempt = true;
    }
    if (!first_attempt)
    {
        if (comparator(front[0], left[2], up[6], buff[2].getMainColor(), buff[3].getMainColor(),
                       buff[5].getMainColor())) {
            toSolve->rotateBack(false);
            answer.emplace_back("back counter clockwise");
            toSolve->rotateRight(false);
            answer.emplace_back("right counter clockwise");
            toSolve->rotateBack(true);
            answer.emplace_back("back clockwise");
            toSolve->rotateLeft(false);
            answer.emplace_back("left counter clockwise");
            toSolve->rotateBack(false);
            answer.emplace_back("back counter clockwise");
            toSolve->rotateRight(true);
            answer.emplace_back("right clockwise");
            toSolve->rotateBack(true);
            answer.emplace_back("back clockwise");
            toSolve->rotateLeft(true);
            answer.emplace_back("left clockwise");
        } else if (comparator(back[6], left[0], up[0], buff[2].getMainColor(), buff[3].getMainColor(),
                              buff[5].getMainColor())) {
            toSolve->rotateLeft(false);
            answer.emplace_back("left counter clockwise");
            toSolve->rotateBack(false);
            answer.emplace_back("back counter clockwise");
            toSolve->rotateRight(false);
            answer.emplace_back("right counter clockwise");
            toSolve->rotateBack(true);
            answer.emplace_back("back clockwise");
            toSolve->rotateLeft(true);
            answer.emplace_back("left clockwise");
            toSolve->rotateBack(false);
            answer.emplace_back("back counter clockwise");
            toSolve->rotateRight(true);
            answer.emplace_back("right clockwise");
            toSolve->rotateBack(true);
            answer.emplace_back("back clockwise");
        }
    }
    return first_attempt;
}

bool CubeSolver::seventh_step(std::vector<std::string> &answer)
{
    brink* buff = toSolve->giveBuff();
    color* up = buff[5].getData();
    color* down = buff[0].getData();
    color* front = buff[1].getData();
    color* right = buff[2].getData();
    color* left = buff[4].getData();
    color* back = buff[3].getData();
    bool match = true;

    if (right[0] == buff[5].getMainColor())
    {
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
    }
    else if (front[2] == buff[5].getMainColor())
    {
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
        toSolve->rotateRight(true);
        answer.emplace_back("right clockwise");
        toSolve->rotateFront(false);
        answer.emplace_back("front counter clockwise");
        toSolve->rotateRight(false);
        answer.emplace_back("right counter clockwise");
        toSolve->rotateFront(true);
        answer.emplace_back("front clockwise");
    }
    else
    {
        match = false;
    }
    return match;
}

void CubeSolver::solve() {
    std::vector<std::string> answer;
    std::vector<int> action;
    if (toSolve->solved())
        return;
    int counter = 0;
    while (counter < 4) {
        if (first_step(answer))
            counter = 0;
        else
            counter++;
    }
    counter = 0;
    while (counter < 4) {
        if (second_step(answer))
            counter = 0;
        else
            counter++;
    }
    counter = 0;
    while (counter < 4) {
        if (third_step(answer))
            counter = 0;
        else
            counter++;
        if (counter == 4) {
            if (advanced_third(answer))
                counter = 0;
        }
    }
    counter = 0;
    fourth_step(answer);
    fifth_step(answer);
    while (sixth_step(answer))
    {

    }
    seventh_step(answer);
    toSolve->rotateUp(true);
    answer.emplace_back("up clockwise");
    while (counter < 2) {
        seventh_step(answer);
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
        counter++;
    }

    seventh_step(answer);
    while (!toSolve->solved())
    {
        toSolve->rotateUp(true);
        answer.emplace_back("up clockwise");
    }
    std::cout << "Solved !\n";
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << std::endl;
    }
}
