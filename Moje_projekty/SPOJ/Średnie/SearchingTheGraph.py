import sys
from collections import deque

# Podniesienie limitu rekurencji dla głębokich grafów (n <= 1000)
sys.setrecursionlimit(2000)

def bfs_visit(graph, start_node):
    visited = set([start_node])
    queue = deque([start_node])
    order = []

    while queue:
        u = queue.popleft()
        order.append(u)

        for neighbor in graph[u]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return order

def dfs_visit(graph, start_node):
    visited = set()
    order = []

    def dfs(u):
        visited.add(u)
        order.append(u)
        for neighbor in graph[u]:
            if neighbor not in visited:
                dfs(neighbor)

    dfs(start_node)
    return order

def main():
    data = sys.stdin.read().split()
    if not data:
        return

    it = iter(map(int, data))
    t = next(it)

    for test_nr in range(1, t + 1):
        n = next(it)
        graph = {i: [] for i in range(1, n + 1)}

        for _ in range(n):
            node = next(it)
            m = next(it)
            graph[node] = [next(it) for _ in range(m)]

        print(f"graph {test_nr}")

        while True:
            u = next(it)
            v = next(it)

            if u == 0 and v == 0:
                break

            if v == 0:
                order = dfs_visit(graph, u)
            else:
                order = bfs_visit(graph, u)

            print(*order)

if __name__ == "__main__":
    main()
