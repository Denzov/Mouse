#ifndef _MAZE_H_
#define _MAZE_H_

#include "Arduino.h"
#include "Config.h"

#define HORIZ_WALL "==="
#define VERTIC_WALL (" | ")

#define BLANK_HORIZ_WALL "   "
#define BLANK_VERTIC_WALL "   "

#define ANGLE " + "
#define LEFT_ANGLE "* "
#define RIGHT_ANGLE " *"

#define VOID_CELL " X "

#define UNDEF_DIR "   "
#define N_DIR " N "
#define E_DIR " E "
#define S_DIR " S "
#define W_DIR " W "

/*  /N\
  <W + E>
    \S/
*/

enum class WallState : uint8_t{
    UND = 0, LO, HI
};

enum class PathDirection : uint8_t{
    N = 0, E, S, W
};

enum class DirectionState : uint8_t{
    UNDEF,
    DEF
};

struct RawCellStore{
    WallState s_wall : 2;
    WallState e_wall : 2;
    DirectionState state_dir : 1;
    PathDirection path_dir : 2;
};

struct CellDirectionStore
{
    DirectionState state_dir : 1;
    PathDirection path_dir : 2;
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
    RawCellStore* buf_cell_ptr = nullptr;

    CellDirectionStore buf_direction_store;

    void print_cell_north_wall(const uint8_t x, const uint8_t y) const;
    void print_cell_middle_walls(const uint8_t x, const uint8_t y) const;
    void print_cell_south_wall(const uint8_t x, const uint8_t y) const;
    void print_cell_path(const uint8_t x, const uint8_t y);
    
    public:
    void Init();
    
    void SetCell(const Cell set_cell, const uint8_t x, const uint8_t y);
    void GetCell(Cell& get_cell, const uint8_t x, const uint8_t y) const;
    void SetPathDir(const PathDirection direction, const uint8_t x, const uint8_t y);
    void GetPathDir(CellDirectionStore& direction_store, const uint8_t x, const uint8_t y);
    
    void UndefCell(const uint8_t x, const uint8_t y);

    void PrintCell(const uint8_t x, const uint8_t y);
    void Print();
};

#endif // !_MAZE_H_