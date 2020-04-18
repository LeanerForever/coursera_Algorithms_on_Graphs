#Uses python3

import sys


def negative_cycle(adj, cost):
    #write your code here
    n = len(adj)
    cycle = 0
    dists = [10**7]*n
    dists[0] = 0
    for i in range(n+1):
        cycle = 0
        for i in range(n):
            for j,w in enumerate(adj[i]):
                if dists[w]> dists[i]+cost[i][j]:
                    dists[w] = dists[i] + cost[i][j]
                    cycle = 1
        if cycle==0:
            return 0
    return cycle


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    print(negative_cycle(adj, cost))
