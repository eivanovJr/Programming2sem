#include <GL/glu.h>
#include "cube.hpp"

int main()
{
    Cube myCube;
    //myCube.generate();
    myCube.read("cube.in");
    //myCube.print();
    /*for (int i = 0; i < 10000; i++)
    {
        myCube.generate();
        myCube.solve();
        std::cout << i << "\n";
    }*/
    //myCube.print();
    myCube.solve();
    myCube.write("cube.out");
    return 0;
}
