from typing import List

class Solution:
    # Shreya
    def numEnclaves(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        def dfs(i, j):
            # boundary and water check
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0:
                return
            grid[i][j] = 0   # mark as visited (sea)
            # explore 4 directions
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)

        # Step 1: remove boundary connected lands
        for i in range(m):
            if grid[i][0] == 1:
                dfs(i, 0)
            if grid[i][n-1] == 1:
                dfs(i, n-1)

        for j in range(n):
            if grid[0][j] == 1:
                dfs(0, j)
            if grid[m-1][j] == 1:
                dfs(m-1, j)

        # Step 2: count remaining land
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    count += 1
        return count
