class tree_node
{
public:
    int val;
    int paths;
    tree_node *north;
    tree_node *east;
    tree_node *south;
    tree_node *west;

    tree_node()
    {
        val = -1;
        paths = 1; // Counts itself as a path of length 1
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
                int idx = (y * grid_width) + x;
                if(roots[idx] == nullptr)
                {
                    roots[idx] = new tree_node;
                    roots[idx]->val = m_grid[y][x];
                    depth_first_search(roots[idx], x, y);
                }
                //cnt += depth_first_count(roots[x+y]);
                cnt += roots[idx]->paths;
            }
        }
        // Clear tree
        /*
        for(int i = 0; i < roots.size(); i++)
        {
            if(roots[i] != nullptr)
            {
                std::cout << "Deleting index: " << i << "\t[" << i - (i/grid_width) << ", " << i/grid_width << "]\n";
                std::cout << roots[i] << "\n";
                delete_tree_2(roots[i]);
            }
        }
        */
        
    }

    void depth_first_search(tree_node *root, int x, int y)
    {
        if(root == NULL)
        {
            //std::cout << "Root at x: " << x << "\ty: " << y << "\tis NULL\n";
            return;
        }

        if(roots[(x * grid_width) + y] == nullptr)
        {
            // Save this node as the root for this entry in the grid - no need to re-traverse
            //std::cout << "Inserting at index: " << (y * grid_width) + x << "\tx: " << x << "\ty: " << y << "\tvalue: " << root->val << "\n";
            roots[(y * grid_width) + x] = root;
        }
        else if(root->paths > 1)
        {
            // We have already traversed this route - we can exit early?
            return;
        }
        // Check if north, east, south, west are strictly increasing
        // North
        if(y != 0 && m_grid[y - 1][x] > root->val)
        {
            root->north = new tree_node;
            root->north->val = m_grid[y - 1][x];
            depth_first_search(root->north, x, y - 1);
            root->paths += root->north->paths;
            //std::cout << "NORTH: root->paths: " << root->paths << "\n";
        }

        // East
        if(x != grid_width - 1 && m_grid[y][x + 1] > root->val)
        {
            root->east = new tree_node;
            root->east->val = m_grid[y][x + 1];
            depth_first_search(root->east, x + 1, y);
            root->paths += root->east->paths;
            //std::cout << "EAST: root->paths: " << root->paths << "\n";
        }

        // South
        if(y != grid_height - 1 && m_grid[y + 1][x] > root->val)
        {
            root->south = new tree_node;
            root->south->val = m_grid[y + 1][x];
            depth_first_search(root->south, x, y + 1);
            root->paths += root->south->paths;
            //std::cout << "SOUTH: root->paths: " << root->paths << "\n";
        }

        // West
        if(x != 0 && m_grid[y][x - 1] > root->val)
        {
            root->west = new tree_node;
            root->west->val = m_grid[y][x - 1];
            depth_first_search(root->west, x - 1, y);
            root->paths += root->west->paths;
            //std::cout << "WEST: root->paths: " << root->paths << "\n";
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

    void delete_tree(tree_node *root)
    {
        if(root == nullptr)
        {
            return;
        }

        if(root->north)
        {
            delete_tree(root->north);
        }

        if(root->east)
        {
            delete_tree(root->east);
        }

        if(root->south)
        {
            delete_tree(root->south);
        }

        if(root->west)
        {
            delete_tree(root->west);
        }

        std::cout << "Deleting tree node at address: " << root << "\n";
        std::cout << "Deleting node: " << root->val << "\tWith paths: " << root->paths << "\n";
        delete root;
        root = nullptr;
    }

    void delete_tree_2(tree_node *root)
    {
        if(root == nullptr)
        {
            return;
        }

        delete_tree_2(root->north);
        delete_tree_2(root->east);
        delete_tree_2(root->south);
        delete_tree_2(root->west);

        delete root;
    }
};
