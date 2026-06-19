class Solution {
public:

    void solve(int row,
               int col,
               vector<vector<int>>& grid,
               int n,
               vector<string>& ans,
               string path,
               vector<vector<int>>& vis) {

        if(row == n - 1 &&
           col == n - 1) {

            ans.push_back(path);
            return;
        }

        // Down
        if(row + 1 < n &&
           !vis[row + 1][col] &&
           grid[row + 1][col] == 1) {

            vis[row][col] = 1;

            solve(row + 1,
                  col,
                  grid,
                  n,
                  ans,
                  path + 'D',
                  vis);

            vis[row][col] = 0;
        }

        // Left
        if(col - 1 >= 0 &&
           !vis[row][col - 1] &&
           grid[row][col - 1] == 1) {

            vis[row][col] = 1;

            solve(row,
                  col - 1,
                  grid,
                  n,
                  ans,
                  path + 'L',
                  vis);

            vis[row][col] = 0;
        }

        // Right
        if(col + 1 < n &&
           !vis[row][col + 1] &&
           grid[row][col + 1] == 1) {

            vis[row][col] = 1;

            solve(row,
                  col + 1,
                  grid,
                  n,
                  ans,
                  path + 'R',
                  vis);

            vis[row][col] = 0;
        }

        // Up
        if(row - 1 >= 0 &&
           !vis[row - 1][col] &&
           grid[row - 1][col] == 1) {

            vis[row][col] = 1;

            solve(row - 1,
                  col,
                  grid,
                  n,
                  ans,
                  path + 'U',
                  vis);

            vis[row][col] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<string> ans;

        if(grid[0][0] == 0)
            return ans;

        vector<vector<int>> vis(
            n,
            vector<int>(n, 0)
        );

        solve(0,
              0,
              grid,
              n,
              ans,
              "",
              vis);

        return ans;
    }
};
