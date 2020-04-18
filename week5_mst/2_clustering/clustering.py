#Uses python3
import sys
import math

def edges(x,y):
    n = len(x)
    adj = []
    f = lambda i,j: math.sqrt((x[i]-x[j])**2+(y[i]-y[j])**2)
    for i in range(n):
        for j in range(i+1,n):
            adj.append((f(i,j),i,j))
    return adj

def find(disjoint_set,x):
    while disjoint_set[x]!=-1:
        x = disjoint_set[x]
    return x

def union(disjoint_set,rank,x,y):
    px = find(disjoint_set,x)
    py = find(disjoint_set,y)
    if rank[px]<rank[py]:
        disjoint_set[px] = py
        rank[py] += rank[px]
    else:
        disjoint_set[py] = px
        rank[px] += rank[py]

def clustering(x, y, k):
    #write your code here
    n = len(x)
    adj = edges(x,y)
    adj.sort()
    disjoint_set = [-1]*n
    rank = [0]*n
    for d,i,j in adj:
        if find(disjoint_set,i)!=find(disjoint_set,j):
            n -= 1
            if n == k-1:
                return d
            union(disjoint_set,rank,i,j)



if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    data = data[1:]
    x = data[0:2 * n:2]
    y = data[1:2 * n:2]
    data = data[2 * n:]
    k = data[0]
    print("{0:.9f}".format(clustering(x, y, k)))
