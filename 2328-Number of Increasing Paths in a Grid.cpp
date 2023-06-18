class Solution
{
public:
    int countPaths(vector<vector<int>>& grid)
    {
        return solve(grid) % mod;
    }
private:
    long long mod = 10e9 + 7;

    long long solve(vector<vector<int>> &grid)
    {
        // Init 
        int grid_width = grid[0].size();
        int grid_height = grid.size();
        vector<vector<bool>> visited(grid_height, vector<bool>(grid_width, false));
        vector<vector<int>> count(grid_height, vector<int>(grid_width, 0));
        long long num_paths = 0;

        for(int x = 0; x < grid_width; x++)
        {
            for(int y = 0; y < grid_height; y++)
            {
                if(visited[y][x])
                {
                    num_paths = (num_paths + count[y][x]) % mod;
                }
                else
                {
                    num_paths = (num_paths + depth_first_search(grid, x, y, visited, count)) % mod;
                }
            }
        }

        return num_paths;
    }

    long long depth_first_search(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &count)
    {
        //std::cout << x << "    " << y << "\n";
        // Check if we have already visited this cell
        if(visited[y][x])
        {
            //std::cout << "Visited this before\n";
            return count[y][x];
        }
        
        long long paths = 1; // Init to 1 to include the "self" path

        // Check the 4 directions
        // North
        if(y != 0 && grid[y - 1][x] > grid[y][x])
        {
            //std::cout << "North\n";
            paths += depth_first_search(grid, x, y - 1, visited, count);
        }
        // East
        if(x != grid[0].size() - 1 && grid[y][x + 1] > grid[y][x])
        {
            //std::cout << "East\n";
            paths += depth_first_search(grid, x + 1, y, visited, count);
        }
        // South
        if(y != grid.size() - 1 && grid[y + 1][x] > grid[y][x])
        {
            //std::cout << "South\n";
            paths += depth_first_search(grid, x, y + 1, visited, count);
        }
        // West
        if(x != 0 && grid[y][x - 1] > grid[y][x])
        {
            //std::cout << "West\n";
            paths += depth_first_search(grid, x - 1, y, visited, count);
        }
        // Our visit to this cell is done
        visited[y][x] = true;
        count[y][x] = paths % mod;
        return count[y][x];
    }
};