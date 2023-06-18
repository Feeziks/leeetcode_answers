class Solution
{
public:
    int countPaths(vector<vector<int>>& grid)
    {
        return solve(grid) % 1000000007;
    }
private:
    int solve(vector<vector<int>> &grid)
    {
        // Init 
        int grid_width = grid[0].size();
        int grid_height = grid.size();
        // We can replace the "visited" vector with initing the count to -1
        vector<vector<int>> count(grid_height, vector<int>(grid_width, -1));
        int num_paths = 0;

        for(int x = 0; x < grid_width; x++)
        {
            for(int y = 0; y < grid_height; y++)
            {
                if(count[y][x] != -1)
                {
                    num_paths = (num_paths + count[y][x]) % 1000000007;
                }
                else
                {
                    num_paths = (num_paths + depth_first_search(grid, x, y, count, -1)) % 1000000007;
                }
            }
        }
        std::cout << num_paths << "\n";
        return num_paths;
    }

    int depth_first_search(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &count, int prev_value)
    {        
        // Check if we are trying to look outside the bounds of the grid
        if(x < 0 || x >= grid[0].size())
        {
            return 0;
        }
        if(y < 0 || y >= grid.size())
        {
            return 0;
        }
        // Check if this path is strictly increasing
        if(prev_value >= grid[y][x])
        {
            return 0;
        }
        // Check if we have already visited this cell
        if(count[y][x] != -1)
        {
            //std::cout << "Visited this before\n";
            return count[y][x];
        }

        //std::cout << "x: " << x << " y: " << y << " prev_value: " << prev_value << " this_value: " << grid[y][x] << "\n";
        
        // Check all 4 directions
        int north = depth_first_search(grid, x, y - 1, count, grid[y][x]);
        int east  = depth_first_search(grid, x + 1, y, count, grid[y][x]);
        int south = depth_first_search(grid, x, y + 1, count, grid[y][x]);
        int west  = depth_first_search(grid, x - 1, y, count, grid[y][x]);

        // Our visit to this cell is done
        count[y][x] = (1 + north + east + south + west) % 1000000007;
        return count[y][x];
    }
};