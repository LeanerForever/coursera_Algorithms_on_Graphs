#Uses python3

import sys


def number_of_components(adj):
    result = 0
    visited = [False]*len(adj)

    def dfs(v):
        for w in adj[v]:
            if visited[w]==False:
                visited[w]=True
                dfs(w)

    for i in range(len(adj)):
        if visited[i]==False:
            visited[i] = True
            dfs(i)
            result += 1
    return result

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(number_of_components(adj))
