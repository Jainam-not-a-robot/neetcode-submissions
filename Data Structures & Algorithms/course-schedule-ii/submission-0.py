class Solution:
    def makeAdj(self, adj, prerequisites):
        for (u, v) in prerequisites:
            adj[u].append(v)
    def getIndegree(self, indegree, adj):
        for x in adj:
            for y in x:
                indegree[y] = indegree[y] + 1
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        self.makeAdj(adj, prerequisites)
        indegree = [0]*numCourses
        self.getIndegree(indegree, adj)
        ans = []
        q = deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                q.append(i)
        while q:
            node = q[0]
            q.popleft()
            ans.append(node)
            for nei in adj[node]:
                indegree[nei] = indegree[nei] - 1
                if indegree[nei] == 0:
                    q.append(nei)
        ans.reverse()
        if len(ans) == numCourses:
            return ans
        return []
