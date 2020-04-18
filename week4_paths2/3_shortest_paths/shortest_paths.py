#Uses python3

import sys
import queue


def shortet_paths(adj, cost, s, distance, reachable, shortest):
    #write your code here

    ## reachable nodes from s
    n = 1  ## total number of nodes reachable from s
    q = queue.Queue()
    q.put(s)
    reachable[s] = 1
    while not q.empty():
        v = q.get()
        for w in adj[v]:
            if reachable[w]==0:
                reachable[w] = 1
                n += 1
                q.put(w)
    distance[s] = 0
    cycle = queue.Queue()
    ## calculate distances
    for _ in range(n):
        change = False
        for i in range(len(adj)):
            if reachable[i]==1:
                for j in range(len(adj[i])):
                    if distance[adj[i][j]]>distance[i]+cost[i][j]:
                        distance[adj[i][j]]=distance[i]+cost[i][j] 
                        change = True
        # print("distance: ",distance)
        if change==False:
            return 

    ## select the negative weight cycle points
    for i in range(len(adj)):
        if reachable[i]==1:
            for j in range(len(adj[i])):
                if(distance[adj[i][j]]>distance[i]+cost[i][j]):
                    shortest[adj[i][j]] = 0
                    cycle.put(adj[i][j])
    while not cycle.empty():
        x = cycle.get()
        for w in adj[x]:
            if shortest[w] == 1:
                shortest[w] = 0
                cycle.put(w)
    # print("reachable: ", reachable)
    # print("shortest: ", shortest)
    # print("distance: ",distance)

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
    s = data[0]
    s -= 1
    distance = [10**19] * n
    reachable = [0] * n
    shortest = [1] * n
    shortet_paths(adj, cost, s, distance, reachable, shortest)
    for x in range(n):
        if reachable[x] == 0:
            print('*')
        elif shortest[x] == 0:
            print('-')
        else:
            print(distance[x])
# [0,10,-,-,-,*]
