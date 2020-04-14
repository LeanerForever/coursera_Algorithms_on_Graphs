#Uses python3

import sys

sys.setrecursionlimit(200000)

def reverse_graph(adj):
    adj_r = [[] for _ in range(len(adj))]
    for i in range(len(adj)):
        for j in adj[i]:
            adj_r[j].append(i)
    return adj_r

def number_of_strongly_connected_components(adj):
    result = 0
    #write your code here
    order = []
    used = [False]*len(adj)
    adj_r = reverse_graph(adj)

    def dfs(v,G,sort=False):
        used[v] = True
        for w in G[v]:
            if used[w]==False:
                dfs(w,G,sort)
        if sort:
            order.append(v)
    ##### toposort
    for i in range(len(adj_r)):
        if used[i]==False:
            dfs(i,adj_r,sort=True)
    ##### count ssc
    used = [False]*len(adj)
    for i in reversed(order):
        if used[i]==False:
            dfs(i,adj,sort=False)
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
    print(number_of_strongly_connected_components(adj))
