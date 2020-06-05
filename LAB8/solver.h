#ifndef LAB8_SOLVER_H
#define LAB8_SOLVER_H

#include "cube.h"

class CubeSolver
{
public:
    explicit CubeSolver(Cube*);
    void solve();
    bool first_step(std::vector<std::string> &);
    bool second_step(std::vector<std::string> &);
    bool third_step(std::vector<std::string> &);
    bool advanced_third(std::vector<std::string> &);
    void fourth_step( std::vector<std::string> &);
    void fifth_step(std::vector<std::string> &);
    bool sixth_step(std::vector<std::string> &);
    bool seventh_step(std::vector<std::string> &);
private:
    Cube* toSolve;
};

#endif //LAB8_SOLVER_H
