#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
        bool is_in_bounds(vector<int> cell, int rows, int cols) {
            if (cell[0] >= rows || cell[0] < 0) {
                return false;
            }
            if (cell[1] >= cols || cell[1] < 0) {
                return false;
            }
            return true;
        }

        vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        // just need to simulate the path even if we go out of the bounds. 
        // just a pattern of increasing and decreasing rows and cols and adding to vector

        // current location will be the path.back(); 
    
        // will use a probing technique to try and be efficient


        int total_cells = rows * cols;
        int visited_cells = 0;

        int row_changer = 1;
        int col_changer = 1;

        int new_row = NULL;
        int new_col = NULL;

        bool in_bounds = true; 

        vector<int> start = {rStart, cStart};
        vector<int> curr_cell = {};
        vector<int> new_cell = {};
        vector<vector<int>> path = {};

        // initialize path
        path.reserve(total_cells);
        path.push_back(start);
        
        
        while (total_cells > visited_cells) {
        
            curr_cell = path.back();
            new_cell = curr_cell;

            // first EAST
            new_col = curr_cell[1] + col_changer;
            new_cell[1] = new_col;

            if (is_in_bounds(new_cell, rows, cols)) {
                path.push_back(new_cell);
                visited_cells++;
            }
            else {
                
            }

            // SOUTH
            new_row = curr_cell[0] + row_changer;
            new_cell[0] = new_row;

            if (is_in_bounds(new_cell, rows, cols)) {
                path.push_back(new_cell);
                visited_cells++;
            }
            else {
                
            }

            
        }
    }
};


int main() {
    return 0;
}