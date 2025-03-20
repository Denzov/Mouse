#include "Solver.h"

void Solver::MazeTestConfig(){
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 0, 0);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::HI, WallState::LO}, 2, 0);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 4, 0);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::LO, WallState::HI}, 6, 0);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 8, 0);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 1, 1);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::HI, WallState::HI}, 3, 1);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 5, 1);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 7, 1);
    _maze->SetCell({WallState::HI, WallState::HI, WallState::LO, WallState::HI}, 9, 1);
    _maze->SetCell({WallState::HI, WallState::HI, WallState::LO, WallState::HI}, 0, 2);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::LO}, 2, 2);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 4, 2);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::LO, WallState::HI}, 6, 2);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 8, 2);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 1, 3);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::HI, WallState::LO}, 3, 3);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 5, 3);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 7, 3);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::LO}, 9, 3);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::LO, WallState::HI}, 0, 4);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 2, 4);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::LO, WallState::HI}, 4, 4);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 6, 4);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 8, 4);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 1, 5);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 3, 5);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 5, 5);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 7, 5);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 9, 5);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 0, 6);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::HI, WallState::HI}, 2, 6);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::LO}, 4, 6);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 6, 6);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::LO, WallState::HI}, 8, 6);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 1, 7);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 3, 7);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 5, 7);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::LO}, 7, 7);
    _maze->SetCell({WallState::HI, WallState::HI, WallState::HI, WallState::LO}, 9, 7);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 0, 8);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::LO, WallState::HI}, 2, 8);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::LO, WallState::LO}, 4, 8);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 6, 8);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::LO, WallState::HI}, 8, 8);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::LO}, 1, 9);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::HI}, 3, 9);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 5, 9);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::LO, WallState::LO}, 7, 9);
    _maze->SetCell({WallState::HI, WallState::HI, WallState::HI, WallState::LO}, 9, 9);
    _maze->SetCell({WallState::HI, WallState::HI, WallState::LO, WallState::HI}, 0, 0);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 1, 8);
}

void Solver::SolveBfsMaze(uint8_t x_s, uint8_t y_s, uint8_t x_f, uint8_t y_f){
    uint8_t ind_s = x_s + y_s * MAZE_SIDE_LENGTH;   
    uint8_t ind_f = x_f + y_f * MAZE_SIDE_LENGTH;   
    
    _queue.pushBack(ind_f);

    while(!_queue.isEmpty()){
        uint8_t cur_cell_ind = _queue.popFront();
        
        if(cur_cell_ind == ind_s){
            break;
        }

        uint8_t cur_x = cur_cell_ind % MAZE_SIDE_LENGTH;
        uint8_t cur_y = cur_cell_ind / MAZE_SIDE_LENGTH;

        Cell cur_cell;
        _maze->GetCell(cur_cell, cur_x, cur_y);

        if(cur_cell.north_wall != WallState::HI){
            if(cur_y - 1 >= 0){
                _maze->GetCellDir(_buf_cell_dir, cur_x, cur_y - 1);
                
                if(_buf_cell_dir.is_def_cell_dir != DirectionState::DEF){
                    _maze->SetCellDir(Direction::S, cur_x, cur_y - 1);
                    _queue.pushBack(cur_cell_ind - MAZE_SIDE_LENGTH); // cur_y++
                }
            }
        }

        if(cur_cell.east_wall != WallState::HI){
            if(cur_x + 1 < MAZE_SIDE_LENGTH){
                _maze->GetCellDir(_buf_cell_dir, cur_x + 1, cur_y);

                if(_buf_cell_dir.is_def_cell_dir != DirectionState::DEF){
                    _maze->SetCellDir(Direction::W, cur_x + 1, cur_y);
                    _queue.pushBack(cur_cell_ind + 1); // cur_x++
                }
            }
        }

        if(cur_cell.south_wall != WallState::HI){
            if(cur_y + 1 < MAZE_SIDE_LENGTH){
                _maze->GetCellDir(_buf_cell_dir, cur_x, cur_y + 1);

                if(_buf_cell_dir.is_def_cell_dir != DirectionState::DEF){
                    _maze->SetCellDir(Direction::N, cur_x, cur_y + 1);
                    _queue.pushBack(cur_cell_ind + MAZE_SIDE_LENGTH); // cur_y--
                }
            }
        }

        if(cur_cell.west_wall != WallState::HI){
            if(cur_x - 1 >= 0){
                _maze->GetCellDir(_buf_cell_dir, cur_x - 1, cur_y);

                if(_buf_cell_dir.is_def_cell_dir != DirectionState::DEF){
                    _maze->SetCellDir(Direction::E, cur_x - 1, cur_y);
                    _queue.pushBack(cur_cell_ind - 1); // cur_x--
                }
            }
        }
    }

    _maze->UndefCell(x_f, y_f);
}