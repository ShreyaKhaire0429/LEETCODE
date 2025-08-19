class Solution:
    # Shreya
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        state = [0] * n  
        # 0 = unvisited, 1 = visiting, 2 = safe
        
        def dfs(node: int) -> bool:
            if state[node] != 0:  # already visited
                return state[node] == 2  # return True if safe
            
            state[node] = 1  # mark as visiting
            
            for nei in graph[node]:
                if state[nei] == 1 or not dfs(nei):  
                    # cycle found or neighbor unsafe
                    return False
            
            state[node] = 2  # mark safe
            return True
        
        safe_nodes = [i for i in range(n) if dfs(i)]
        return safe_nodes