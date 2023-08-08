from collections import defaultdict
import heapq as heap


home = #FILL
target = #FILL
graph = #Adjaceny list

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

    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = collections.defaultdict(list)

        for x,y,w in times:
            adj[x].append((y, w))

        heap = [(k,0)]
        visited = set()
        while heap:
            node, time = heapq.heappop(heap)
            visited.add(node)

            if len(visited)==n:
                return time
            
            for neighbor, dist in adj[node]:
                if neighbor not in visited:
                    heapq.heappush(heap, (neighbor, dist + time))
        return -1
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        adj = collections.defaultdict(list)

        for x,y,w in flights:
            adj[x].append((w, y))

        heap = [(0,src,k)]
        visited = set()

        least = float("inf")
        while heap:
            time, node, stops = heapq.heappop(heap)
            visited.add(node)


            if k == 0 and dst == node:
                print(" ig ot ")
                least = min(time, least)
            elif k ==0:
                continue
            
            for dist, neigh in adj[node]:
                if neigh not in visited:
                    heapq.heappush(heap, (dist+time, neigh, k-1))
        
        return least if least != float("inf") else -1
