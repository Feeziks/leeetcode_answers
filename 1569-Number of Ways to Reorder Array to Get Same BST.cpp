class Solution {
public:
/*
    int numOfWays(vector<int>& nums) {
        // Low hanging fruit
        if(nums.size() == 1 || nums.size() == 2)
            return 0;

        // Build the table? Idk
        // This one was very hard, copy pasted a lot and read the solution reasoning
        // I have an introductory level of understanding after the reading, but this would have taken me a very long time to solve alone

        // My orignal thoughts on the approach would have been to sort the values other than the root to "left" and "right" similar to dfs below
        // I would have then created all unique permutations of those values and validated each permutation one by one to see if it was a valid tree
        // If it was a valid tree increment a counter
        // Return the counter
        int table_size = nums.size();
        table.resize(table_size + 1);
        for(int i = 0; i < table_size + 1; i++)
        {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; j++)
            {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }


        return (dfs(nums) - 1) % mod;
    }
*/

    int numOfWays(vector<int>& nums)
    {
        int m = nums.size();
        // Table of Pascal's triangle
        table.resize(m + 1);
        for(int i = 0; i < m + 1; ++i) {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        return (dfs(nums) - 1) % mod;
    }

private:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;
/*
    long long dfs(vector<int> &nums)
    {
        int m = nums.size();
        if(m < 3)
        {
            return 1;
        }

        int root = nums[0];
        vector<int> left_nodes, right_nodes;
        for(int i = 1; i < m; i++)
        {
            if(nums[i] < root)
            {
                left_nodes.push_back(nums[i]);
            }
            else
            {
                right_nodes.push_back(nums[i]);
            }
        }

        long long left_ways(dfs(left_nodes));
        long long right_ways(dfs(right_nodes));

        return (((left_ways * right_ways) % mod) * table[m - 1][left_nodes.size()] % mod);
    }
*/
    long long dfs(vector<int> &nums)
    {
        int m = nums.size();
        if(m < 3) {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        for(int i = 1; i < m; ++i){
            if (nums[i] < nums[0]) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }
		
        long long leftWays = dfs(leftNodes) % mod;
        long long rightWays = dfs(rightNodes) % mod;
		
        return (((leftWays * rightWays) % mod) * table[m - 1][leftNodes.size()]) % mod;
    }
};