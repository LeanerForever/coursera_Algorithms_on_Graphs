#Uses python3

import sys
import queue

def distance(adj, s, t):
    #write your code here
    q = queue.Queue()
    q.put(s)
    dists = [-1]*len(adj)
    dists[s] = 0
    while not q.empty():
        v = q.get()
        for w in adj[v]:
            if dists[w]==-1:
                dists[w] = dists[v]+1
                q.put(w)
    return dists[t]

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
    s, t = data[2 * m] - 1, data[2 * m + 1] - 1
    print(distance(adj, s, t))
