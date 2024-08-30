#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    struct coord {
        int x;
        int y;
        friend std::ostream& operator<<(std::ostream& os, const coord& c);
    };

    void binary_search();
    void bfs(std::vector<std::vector<int>>& grid, std::deque<coord> thieves) {
        std::vector<coord> to_be_searched;

        while (!thieves.empty()) {
            to_be_searched.push_back(thieves[0]);
            thieves.pop_front();


            while (!to_be_searched.empty()) {
                // search n, e, s, w
                
                coord curr_coord = to_be_searched.back();
                to_be_searched.pop_back();

                if (grid[curr_coord.x][curr_coord.y]) {
                    
                }
            }

        }
    }

    std::deque<coord> find_thieves(std::vector<std::vector<int>>& grid) {
        std::deque<coord> thieves;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid.size(); col++) {
                if (grid[row][col]) {
                    coord c = {row, col};
                    thieves.push_back(c);
                }
            }
        }
        return thieves;
    }

    std::vector<std::vector<int>> bfs_from_thieves(std::vector<std::vector<int>>& grid) {
        
    }

    int maximum_safeness_factor(std::vector<std::vector<int>>& grid) {
        if (grid[0][0]) {
            return 0;
        }
        std::deque<coord> thieves = find_thieves(grid);    



        return 0;
    }
    
};

std::ostream& operator<<(std::ostream& os, const Solution::coord& c) {
    os << '(' << c.x << ", " << c.y << ')';
    return os;
}



int main() {
    std::vector<std::vector<int>> test1 = {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0} 
    };

    std::vector<std::vector<int>> test2 = {
        {0, 0, 1},
        {0, 0, 0},
        {0, 1, 0} 
    };

    Solution sol;
    int safeness = sol.maximum_safeness_factor(test2);

    std::cout << safeness << '\n'; 
    return 0;
}