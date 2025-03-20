#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "Maze.h"
#include "MyQueue.h"

class Solver{
private:
    Maze* _maze;
    Queue<uint8_t> _queue;   

    DirectionStore _buf_cell_dir;   

    
public:
    Solver(Maze* maze) : _maze(maze){}
    
    void MazeTestConfig();
    void SolveBfsMaze(uint8_t x_s, uint8_t y_s, uint8_t x_f, uint8_t y_f);
};

#endif // !_SOLVER_H_