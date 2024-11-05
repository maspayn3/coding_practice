#include <vector>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

enum Direction {NORTH, SOUTH, EAST, WEST};

static const int HASH_MULTIPLIER = 60013;

class Solution {
public:

    typedef struct  {
        int x;
        int y;
} coord;

    bool is_obstacle(coord curr_coord, unordered_set<int>& obstacles) {
        if (obstacles.count(hash_coords(curr_coord.x, curr_coord.y))) {
            return true;
        }
        return false;
    }

    int hash_coords(int x, int y) {
        return x + HASH_MULTIPLIER * y;
    }

    unordered_set<int> fill_hash_table(vector<vector<int>>& obstacles) {

        std::unordered_set<int> obstacle_set;

        for (auto& obstacle : obstacles) {
            obstacle_set.insert(hash_coords(obstacle[0], obstacle[1]));
        }

        return obstacle_set;
    }

    Direction turn_robot(Direction curr_dir, int command) {
        Direction new_direction;

        // turn right 90 degrees, clock-wise
        if (command == -1) {
            switch (curr_dir)
            {
            case NORTH:
                new_direction = EAST;
                break;
            case SOUTH:
                new_direction = WEST;
                break;
            case EAST:
                new_direction = SOUTH; 
                break;
            case WEST:
                new_direction = NORTH;
                break;
            default:
                cerr << "ERROR UNKNOWN DIRECTION!!\n";
                break;
            }
        }
        // turn left 90 degrees, counter clock-wise
        else if (command == -2) {
            switch (curr_dir)
            {
            case NORTH:
                new_direction = WEST;
                break;
            case SOUTH:
                new_direction = EAST;
                break;
            case EAST:
                new_direction = NORTH; 
                break;
            case WEST:
                new_direction = SOUTH;
                break;
            default:
                cerr << "ERROR UNKNOWN DIRECTION!!\n";
                break;
            }
        }
        return new_direction;
    }

    coord move_robot(coord curr_coord, int distance, Direction curr_dir, unordered_set<int>& obstacles) {

            // if (is_obstacle(curr_coord, obstacles)) {
            //     return curr_coord;
            // }

            switch (curr_dir) {
                case NORTH:
                    for (int i = 1; i <= distance; i++) { 
                        if (is_obstacle({curr_coord.x, curr_coord.y + i}, obstacles)) {
                            curr_coord.y += i - 1;
                            return curr_coord;
                        }
                    }
                    curr_coord.y += distance;
                    break;
                case SOUTH:
                    for (int i = 1; i <= distance; i++) { 
                        if (is_obstacle({curr_coord.x, curr_coord.y - i}, obstacles)) {
                            curr_coord.y -= i - 1;
                            return curr_coord;
                        }
                    }
                    curr_coord.y -= distance;
                    break;
                case EAST:
                    for (int i = 1; i <= distance; i++) {
                        if (is_obstacle({curr_coord.x + i, curr_coord.y}, obstacles)) {
                            curr_coord.x += i - 1;
                            return curr_coord;
                        }
                    }
                    curr_coord.x += distance;
                    break;
                case WEST:
                    for (int i = 1; i <= distance; i++) {
                        if (is_obstacle({curr_coord.x - i, curr_coord.y}, obstacles)) {
                            curr_coord.x -= i - 1;
                            return curr_coord;
                        }
                    }
                    curr_coord.x -= distance;
                    break;
                default:
                    break;
            }
        return curr_coord;
    }

    int calculate_distance(coord final_coord) {
        return final_coord.x * final_coord.x + final_coord.y * final_coord.y;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // can add all obstacles to a hash-table for quick lookup;
        unordered_set<int> obstacle_map = fill_hash_table(obstacles);

        int max_distance = 0;
        int current_command;
        coord curr_coord = {0,0};
        Direction curr_dir = NORTH;

        deque<int> commands_deq(commands.begin(), commands.end());

        while (!commands_deq.empty()) {
            
            // grab next command and destroy
            current_command = commands_deq.front();
            commands_deq.pop_front();

            if (current_command == -1 || current_command == -2) {
                curr_dir = turn_robot(curr_dir, current_command);
            }
            else {
                int distance = current_command;
                curr_coord = move_robot(curr_coord, distance, curr_dir, obstacle_map);

                int temp_distance = calculate_distance(curr_coord);

                if (temp_distance > max_distance) {
                    max_distance = temp_distance;
                }
            }
        }
        return max_distance;
    }
};


int main() {

    ios_base::sync_with_stdio(0);
    Solution sol;
    vector<int> commands = {1,-1,1,-1,1,-1,6};
    vector<vector<int>> obstacles = {{0,0}};
    int distance = sol.robotSim(commands, obstacles);

    std::cout << "Final result: " << distance << "\n";
    return 0;
}