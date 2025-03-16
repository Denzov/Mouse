#ifndef _MAZE_H_
#define _MAZE_H_

#include "Arduino.h"
#include "Config.h"

#define HORIZ_WALL "=="
#define VERTIC_WALL " | "

#define BLANK_HORIZ_WALL "  "
#define BLANK_VERTIC_WALL "   "

#define ANGLE " + "
#define LEFT_ANGLE "* "
#define RIGHT_ANGLE " *"

#define VOID_CELL "  "

/*  /N\
  <W + E>
    \S/
*/
// enum class Cell{
//     N = 0, E, S, W
// };

enum class WallState : uint8_t{
    UND = 0, LO, HI
};

struct RawCellStore{
    WallState s_wall : 4;
    WallState e_wall : 4;
};

struct Cell{
    WallState north_wall;
    WallState east_wall;
    WallState south_wall;
    WallState west_wall;
};

class Maze{
private:
    RawCellStore _cell_blocks[MAZE_MEM_SIZE];      

    void print_cell_north_wall(const uint8_t x, const uint8_t y) const;
    void print_cell_middle_walls(const uint8_t x, const uint8_t y) const;
    void print_cell_south_wall(const uint8_t x, const uint8_t y) const;
    
    void set_cell(const Cell set_cell, const uint8_t x, const uint8_t y);
    void get_cell(Cell& get_cell, const uint8_t x, const uint8_t y) const;
    
    public:
    void Init();
    
    void PrintCell(const uint8_t x, const uint8_t y) const;
    void Print() const;
};

#endif // !_MAZE_H_