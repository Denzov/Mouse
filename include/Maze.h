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

enum class Direction : uint8_t{
    N = 0, E, S, W
};

enum class DirectionState : uint8_t{
    UNDEF,
    DEF
};

struct RawCellStore{
    enum PathDirStore{
        first, second
    };

    WallState s_wall : 2;
    WallState e_wall : 2;
    Direction cell_dir : 2;
    DirectionState is_def_cell_dir : 1;
    PathDirStore path_dir : 1; 

    /* it may be both LO_PATH_DIR and HI_PATH_DIR. it depend by current element
    so, take maze 2x2 
    in string view (here it is cell_store): 0 1 2 3 4 5 6 7 8 
    in matrix view:   0 1  
                    2 3 4
                    5 6 7
    in this way, 0th-element is LO_PATH_DIR, 1th-element is HI_PATH_DIR.
    but, 0th and 1th elements together are the full direction of the path
    for example, LO_PATH_DIR are: 0, 2, 4, 6;
                 HI_PATH_DIR are: 1, 3, 5, 7;
          but full direction are: {0, 1}, {2, 3}, {4, 5}, {6, 7}
    
    that are, (full struct) Direction = static_cast<Direction>((cell_store[1] << 1) | cell_store[0])
    */
};

struct DirectionStore
{
    DirectionState is_def_cell_dir : 1;
    Direction cell_dir : 2;
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

    DirectionStore _buf_direction_store;

    Direction _buf_path_direction_store;
    uint8_t _path_ind = 0;

    void print_cell_north_wall(const uint8_t x, const uint8_t y) const;
    void print_cell_middle_walls(const uint8_t x, const uint8_t y) const;
    void print_cell_south_wall(const uint8_t x, const uint8_t y) const;
    void print_cell_path(const uint8_t x, const uint8_t y);
    
public:
    void Init();
    
    void SetCell(const Cell set_cell, const uint8_t x, const uint8_t y);
    void UndefCell(const uint8_t x, const uint8_t y);

    void GetCell(Cell& get_cell, const uint8_t x, const uint8_t y) const;
    
    void SetCellDir(const Direction direction, const uint8_t x, const uint8_t y);
    void GetCellDir(DirectionStore& direction_store, const uint8_t x, const uint8_t y);

    void PushBackDirPath(const Direction dir);
    
    void SetDirPath(const Direction dir, uint8_t ind);
    void GetDirPath(Direction& dir, uint8_t ind) const;

    void ClearDirPath();
    uint8_t GetPathSize();

    void PrintDirPath();

    void PrintCell(const uint8_t x, const uint8_t y);
    void Print();
};

#endif // !_MAZE_H_