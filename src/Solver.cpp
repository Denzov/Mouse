#include "Solver.h"

void Solver::MazeTestConfig(){
    _maze->SetCell({WallState::HI, WallState::HI, WallState::LO, WallState::HI}, 0, 0);

    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::LO}, 1, 1);
    _maze->SetCell({WallState::LO, WallState::LO, WallState::LO, WallState::LO}, 1, 2);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 1, 3);
    
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::HI}, 0, 2);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::HI}, 0, 2);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::HI}, 2, 1);
    _maze->SetCell({WallState::HI, WallState::LO, WallState::HI, WallState::LO}, 3, 1);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 4, 1);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::HI}, 2, 3);

    _maze->SetCell({WallState::LO, WallState::HI, WallState::LO, WallState::HI}, 3, 3);
    _maze->SetCell({WallState::LO, WallState::HI, WallState::HI, WallState::LO}, 3, 4);

    _maze->SetCell({WallState::HI, WallState::HI, WallState::LO, WallState::HI}, 3, 3);

    _maze->Print();
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
                _maze->GetPathDir(_buf_cell_dir, cur_x, cur_y - 1);
                
                if(_buf_cell_dir.state_dir != DirectionState::DEF){
                    _maze->SetPathDir(PathDirection::S, cur_x, cur_y - 1);
                    _queue.pushBack(cur_cell_ind - MAZE_SIDE_LENGTH); // cur_y++
                }
            }
        }

        if(cur_cell.east_wall != WallState::HI){
            if(cur_x + 1 < MAZE_SIDE_LENGTH){
                _maze->GetPathDir(_buf_cell_dir, cur_x + 1, cur_y);

                if(_buf_cell_dir.state_dir != DirectionState::DEF){
                    _maze->SetPathDir(PathDirection::W, cur_x + 1, cur_y);
                    _queue.pushBack(cur_cell_ind + 1); // cur_x++
                }
            }
        }

        if(cur_cell.south_wall != WallState::HI){
            if(cur_y + 1 < MAZE_SIDE_LENGTH){
                _maze->GetPathDir(_buf_cell_dir, cur_x, cur_y + 1);

                if(_buf_cell_dir.state_dir != DirectionState::DEF){
                    _maze->SetPathDir(PathDirection::N, cur_x, cur_y + 1);
                    _queue.pushBack(cur_cell_ind + MAZE_SIDE_LENGTH); // cur_y--
                }
            }
        }

        if(cur_cell.west_wall != WallState::HI){
            if(cur_x - 1 >= 0){
                _maze->GetPathDir(_buf_cell_dir, cur_x - 1, cur_y);

                if(_buf_cell_dir.state_dir != DirectionState::DEF){
                    _maze->SetPathDir(PathDirection::E, cur_x - 1, cur_y);
                    _queue.pushBack(cur_cell_ind - 1); // cur_x--
                }
            }
        }
    }

    _maze->UndefCell(x_f, y_f);
}