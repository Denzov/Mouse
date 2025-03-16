#include "Maze.h"

void Maze::print_cell_north_wall(const uint8_t x, const uint8_t y) const{
    Serial.print(ANGLE);
    if(_cell_blocks[x + y * (MAZE_SIDE_LENGTH_ADD_ONE)].s_wall == WallState::HI){
        Serial.print(HORIZ_WALL);
    }
    else{
        Serial.print(BLANK_HORIZ_WALL);
    }
}

void Maze::print_cell_middle_walls(const uint8_t x, const uint8_t y) const{
    if(_cell_blocks[MAZE_SIDE_LENGTH + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall == WallState::HI){
        Serial.print(VERTIC_WALL);
    }
    else{
        Serial.print(BLANK_VERTIC_WALL);
    }

    Serial.print(VOID_CELL);
}

void Maze::print_cell_south_wall(const uint8_t x, const uint8_t y) const{
    Serial.print(ANGLE);

    if(_cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall == WallState::HI){
        Serial.print(HORIZ_WALL);
    }
    else{
        Serial.print(BLANK_HORIZ_WALL);
    }
}

void Maze::set_cell(const Cell set_cell, const uint8_t x, const uint8_t y){
    _cell_blocks[x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall = set_cell.north_wall;

    _cell_blocks[MAZE_SIDE_LENGTH + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall = set_cell.west_wall;

    _cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall = set_cell.east_wall;

    _cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall = set_cell.south_wall;
}

void Maze::get_cell(Cell& get_cell, const uint8_t x, const uint8_t y) const{
    get_cell.north_wall = _cell_blocks[x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall;

    get_cell.west_wall = _cell_blocks[MAZE_SIDE_LENGTH + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall;

    get_cell.east_wall = _cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall;  

    get_cell.south_wall = _cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall;
}

void Maze::Init(){
    /*fill north wall fronts*/
    for(uint16_t i = 0; i < MAZE_SIDE_LENGTH; i++){
        _cell_blocks[i].s_wall = WallState::HI;
    }

    /*fill west wall fronts*/
    for(uint16_t i = MAZE_SIDE_LENGTH; i <= MAZE_SIDE_LENGTH_ADD_ONE*MAZE_SIDE_LENGTH; i+=MAZE_SIDE_LENGTH_ADD_ONE){
        _cell_blocks[i].e_wall = WallState::HI;
    }
    
    /*fill east wall fronts*/
    for(uint16_t i = MAZE_SIDE_LENGTH_ADD_ONE + (MAZE_SIDE_LENGTH - 1); 
        i <= (MAZE_SIDE_LENGTH_ADD_ONE + (MAZE_SIDE_LENGTH - 1) + (MAZE_SIDE_LENGTH - 1) * MAZE_SIDE_LENGTH_ADD_ONE); i += MAZE_SIDE_LENGTH_ADD_ONE){
        _cell_blocks[i].e_wall = WallState::HI;   
    }

    /*fill south wall fronts*/
    for(uint16_t i = (MAZE_TOTAL_SIZE - MAZE_SIDE_LENGTH); i < MAZE_TOTAL_SIZE; i++){
        _cell_blocks[i].s_wall = WallState::HI;   
    }
}

void Maze::PrintCell(const uint8_t x, const uint8_t y) const{
    /*print north wall front*/
    Serial.print(ANGLE);
    if(_cell_blocks[x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall == WallState::HI){
        Serial.print(HORIZ_WALL);
    }
    else{
        Serial.print(BLANK_HORIZ_WALL);
    }

    Serial.println(ANGLE);

    /*print west wall front*/
    if(_cell_blocks[MAZE_SIDE_LENGTH + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall == WallState::HI){
        Serial.print(VERTIC_WALL);
    }
    else{
        Serial.print(BLANK_VERTIC_WALL);
    }

    Serial.print(VOID_CELL);

    /*print east wall front*/
    if(_cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].e_wall == WallState::HI){
        Serial.println(VERTIC_WALL);
    }
    else{
        Serial.println(BLANK_VERTIC_WALL);
    }

    Serial.print(ANGLE);

    /*print north wall front*/
    if(_cell_blocks[MAZE_SIDE_LENGTH_ADD_ONE + x + y * MAZE_SIDE_LENGTH_ADD_ONE].s_wall == WallState::HI){
        Serial.print(HORIZ_WALL);
    }
    else{
        Serial.print(BLANK_HORIZ_WALL);
    }

    Serial.println(ANGLE);
}

void Maze::Print() const{
    for(uint16_t x = 0; x < MAZE_SIDE_LENGTH; x++){
        print_cell_north_wall(x, 0);
    }
    Serial.print(ANGLE);
    Serial.println();

    for(uint16_t y = 0; y < MAZE_SIDE_LENGTH; y++){
        for(uint16_t x = 0; x < MAZE_SIDE_LENGTH; x++){
            print_cell_middle_walls(x, y);
        }            

        print_cell_middle_walls(MAZE_SIDE_LENGTH, y);
        Serial.println();
        for(uint16_t x = 0; x < MAZE_SIDE_LENGTH; x++){
            print_cell_south_wall(x, y);
        }
        Serial.print(ANGLE);
        Serial.println();
    }
}