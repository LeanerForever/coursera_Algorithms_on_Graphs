#Uses python3

import sys


def acyclic(adj):
    visited = [False]*(len(adj))
    pre_visited = [False]*len(adj)
    post_visited = [False]*len(adj)

    def dfs(v):
        visited[v] = True
        pre_visited[v] = True
        for w in adj[v]:
            if visited[w] and (pre_visited[w] and not post_visited[w]):
                return 1
            else:
                if dfs(w)==1:
                    return 1
        post_visited[v] = True
        return 0
    for i in range(len(adj)):
        if visited[i]==False:
            if (dfs(i)==1):
                return 1
    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    # input = input()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
    print(acyclic(adj))
