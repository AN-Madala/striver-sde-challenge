class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Store all rotten oranges
        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 2) {

                    q.push({i,j});
                }

                else if(grid[i][j] == 1) {

                    fresh++;
                }
            }
        }

        // No fresh oranges
        if(fresh == 0)
            return 0;

        int minutes = 0;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()) {

            int size = q.size();

            bool rotten = false;

            while(size--) {

                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int i = 0; i < 4; i++) {

                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    if(newRow >= 0 &&
                       newRow < m &&
                       newCol >= 0 &&
                       newCol < n &&
                       grid[newRow][newCol] == 1) {

                        grid[newRow][newCol] = 2;

                        q.push({newRow,newCol});

                        fresh--;

                        rotten = true;
                    }
                }
            }

            if(rotten)
                minutes++;
        }

        if(fresh != 0)
            return -1;

        return minutes;
    }
};
