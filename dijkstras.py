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
    graph = [[] for _ in range(n)]
    minHeap = [(0, src, k + 1)]  # (d, u, stops)
    dist = [[math.inf] * (k + 2) for _ in range(n)]

    for u, v, w in flights:
      graph[u].append((v, w))

    while minHeap:
      d, u, stops = heapq.heappop(minHeap)
      if u == dst:
        return d
      if stops > 0:
        for v, w in graph[u]:
          newDist = d + w
          if newDist < dist[v][stops - 1]:
            dist[v][stops - 1] = newDist
            heapq.heappush(minHeap, (newDist, v, stops - 1))

    return -1
