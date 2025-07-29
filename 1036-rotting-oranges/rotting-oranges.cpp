class Solution {
public:
// Shreya
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q; 
        int fresh = 0;
        
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 2) 
                {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) 
                {
                    fresh++;
                }
            }
        }

        int time = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) 
        {
            auto front = q.front();
            q.pop();
            int x = front.first.first;
            int y = front.first.second;
            int t = front.second;
            time = max(time, t);

            for (int k = 0; k < 4; ++k) 
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2; 
                    fresh--;          
                    q.push({{nx, ny}, t + 1});
                }
            }
        }
        if (fresh > 0) return -1;
        return time;
    }
};
