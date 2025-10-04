class Solution {
    // Shreya
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int m = heightMap.size();
        int n = heightMap[0].size();

        // If the map is too small, no water can be trapped
        if (m <= 2 || n <= 2) return 0;

        // Min-heap (priority queue) -> stores {height, row, col}
        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>>
        > minHeap;

        // Keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Step 1: Add all boundary cells to heap
        for (int i = 0; i < m; i++) 
        {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) 
        {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        // 4 possible directions (up, down, left, right)
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int totalWater = 0;

        // Step 2: Process heap
        while (!minHeap.empty()) {
            // Take out the cell with the lowest boundary
            auto cell = minHeap.top();
            minHeap.pop();

            int height = cell[0];
            int x = cell[1];
            int y = cell[2];

            // Check all 4 neighbors
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k][0];
                int ny = y + dirs[k][1];

                // Skip if out of bounds or already visited
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;

                // If neighbor is lower than current boundary, water is trapped
                if (heightMap[nx][ny] < height) {
                    totalWater += height - heightMap[nx][ny];
                }

                // Push neighbor into heap with updated boundary height
                int newHeight = max(heightMap[nx][ny], height);
                minHeap.push({newHeight, nx, ny});
            }
        }

        return totalWater;
    }
};