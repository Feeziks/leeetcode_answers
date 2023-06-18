class tree_node
{
public:
    int val;
    tree_node *north;
    tree_node *east;
    tree_node *south;
    tree_node *west;

    tree_node()
    {
        val = -1;
        north = nullptr;
        east = nullptr;
        south = nullptr;
        west = nullptr;
    }
};

class Solution
{
public:
    int countPaths(vector<vector<int>>& grid)
    {
        // Each psoition in the grid is a different root of a tree
        // The tree will have at most 4 children for each parent
        // N, E, S, W
        // Each walk from each grid will reveal all possible length's
        // So once you complete this tree making process for a given grid section you already have the values for
        // 1 length, 2 length etc
        
        m_grid = grid;
        grid_width = m_grid[0].size(); // Size of each entry in the outer vector is the same, and the width of the grid
        grid_height = m_grid.size(); // Size of the outer vector is the number of entries in the grid
        solve();
        int ret = cnt % mod;
        return ret;
    }
private:
    vector<tree_node *> roots; // One for each entry in the grid
    vector<vector<int>> m_grid; // Copy once dont need to pass to each function
    int grid_width;
    int grid_height;
    long long mod = 1e9 + 7;
    long long cnt;

    void solve()
    {
        roots.resize(grid_width * grid_height);
        for(int x = 0; x < grid_width; x++)
        {
            for(int y = 0; y < grid_height; y++)
            {
                roots[x + y] = new tree_node;
                roots[x + y]->val = m_grid[y][x];
                depth_first_search(roots[x+y], x, y);
                cnt += depth_first_count(roots[x+y]);
            }
        }
    }

    void depth_first_search(tree_node *root, int x, int y)
    {
        if(root == NULL)
        {
            std::cout << "Root at x: " << x << "\ty: " << y << "\tis NULL\n";
            return;
        }
        // Check if north, east, south, west are strictly increasing
        // North
        if(y != 0 && m_grid[y - 1][x] > root->val)
        {
            root->north = new tree_node;
            root->north->val = m_grid[y - 1][x];
            depth_first_search(root->north, x, y - 1);
        }

        // East
        if(x != grid_width - 1 && m_grid[y][x + 1] > root->val)
        {
            root->east = new tree_node;
            root->east->val = m_grid[y][x + 1];
            depth_first_search(root->east, x + 1, y);
        }

        // South
        if(y != grid_height - 1 && m_grid[y + 1][x] > root->val)
        {
            root->south = new tree_node;
            root->south->val = m_grid[y + 1][x];
            depth_first_search(root->south, x, y + 1);
        }

        // West
        if(x != 0 && m_grid[y][x - 1] > root->val)
        {
            root->west = new tree_node;
            root->west->val = m_grid[y][x - 1];
            depth_first_search(root->west, x - 1, y);
        }
    }

    int depth_first_count(tree_node *root)
    {
        // Count the "self" as 1
        int ret = 1;

        if(root->north)
        {
            ret += depth_first_count(root->north);
        }

        if(root->east)
        {
            ret += depth_first_count(root->east);
        }

        if(root->south)
        {
            ret += depth_first_count(root->south);
        }

        if(root->west)
        {
            ret += depth_first_count(root->west);
        }

        return ret;
    }
};
