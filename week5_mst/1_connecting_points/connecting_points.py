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
    while disjoint_set[x]!=x:
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


def minimum_distance(x, y):
    result = 0.
    #write your code here
    n = len(x)
    adj = edges(x,y)
    adj.sort()
    disjoint_set = [i for i in range(n)]
    rank = [0]*n
    for d,i,j in adj:
        if find(disjoint_set,i)!=find(disjoint_set,j):
            result += d
            union(disjoint_set,rank,i,j)

    return result


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(x, y)))
