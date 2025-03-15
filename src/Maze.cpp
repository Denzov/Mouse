#include "Maze.h"

Maze::Maze(){
    for(uint16_t i = 0; i < MAZE_MEM_SIZE; i++){
        _cell_locks[i].s_wall = CellValue::HI;
        _cell_locks[i].e_wall = CellValue::HI;
    }

    for(uint16_t i = 0; i < 15; i++){
        _cell_locks[i].s_wall = CellValue::HI;
        _cell_locks[i].e_wall = CellValue::HI;
    }
}