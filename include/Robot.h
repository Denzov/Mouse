#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "Cyclogram.h"
#include "Solver.h"
#include "Maze.h"

struct RobotConnectionParams{
    CycloWorker* cycloWorker;
    Solver* solver;
    Maze* maze;
};

class Robot : public RobotConnectionParams{
public:
    Robot(RobotConnectionParams* rcp) :
        RobotConnectionParams(*rcp){}

    void convertPathToCyclogram();
private:
    
};

#endif // !_ROBOT_H_