from collections import defaultdict
import heapq as heap

visited = set()
nodeCosts = defaultdict(lambda: 0)
nodeCosts[home] = 1
parentsMap = {}
pq = []
heap.heappush(pq, (-1, home))  # use negative because heapq is min heap
while pq:
    _, name = heap.heappop(pq)
    if name in visited:
        continue
    visited.add(name)
    for nextname, val in graph[name].items():
        cost = nodeCosts[name] * float(val)
        if nodeCosts[nextname] < cost:
            parentsMap[nextname] = name
            nodeCosts[nextname] = cost
            heap.heappush(pq, (-cost, nextname))  # use negative because heapq is min heap
print(nodeCosts[target])
