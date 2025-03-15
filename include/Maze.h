#ifndef _MAZE_H_
#define _MAZE_H_

#include "Arduino.h"
#include "Config.h"

/*  /N\
  <W + E>
    \S/
*/

enum class Cell{
    N = 0, E, S, W
};

enum class CellValue : uint8_t{
    UND = 0, LO, HI
};

struct RawCellStore{
    CellValue s_wall : 4;
    CellValue e_wall : 4;
};

class Maze{
private:
    RawCellStore _cell_locks[MAZE_MEM_SIZE];      
public:
    Maze(); 
};

#endif // !_MAZE_H_