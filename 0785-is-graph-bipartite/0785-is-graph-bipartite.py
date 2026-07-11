class Solution(object):
    def bfs(self,graph,start,color):
        q=deque()
        q.append(start)
        color[start]=0

        while q:
            node=q.popleft()

            for it in graph[node]:
                if color[it]==-1:
                    color[it]=1-color[node]
                    q.append(it)
                elif color[it]==color[node]:
                    return False
        
        return True

    def isBipartite(self, graph):
        V=len(graph)
        color=[-1]*V

        for i in range(V):
            if color[i]==-1:
                if self.bfs(graph,i,color)==False:
                    return False

        return True
        