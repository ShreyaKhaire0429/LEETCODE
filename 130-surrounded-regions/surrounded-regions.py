class Solution:
    # Shreya
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return

        m, n = len(board), len(board[0])
        q = deque()

        # Helper: mark an 'O' as safe ('S') and enqueue it
        def mark(r: int, c: int) -> None:
            if 0 <= r < m and 0 <= c < n and board[r][c] == 'O':
                board[r][c] = 'S'
                q.append((r, c))

        # 1) Seed BFS from all border 'O's
        for r in range(m):
            mark(r, 0)
            mark(r, n - 1)
        for c in range(n):
            mark(0, c)
            mark(m - 1, c)

        # BFS flood fill to mark all border-connected 'O's as safe ('S')
        while q:
            r, c = q.popleft()
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                mark(r + dr, c + dc)

        # 2) Flip the truly surrounded 'O' -> 'X'
        # 3) Restore safe 'S' -> 'O'
        for r in range(m):
            for c in range(n):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                elif board[r][c] == 'S':
                    board[r][c] = 'O'
