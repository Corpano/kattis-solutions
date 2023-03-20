inpStr = input()


# Python program for Dijkstra's single
# source shortest path algorithm. The program is
# for adjacency matrix representation of the graph
class Graph():

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]

    def printSolution(self, dist):
        print("Vertex \t Distance from Source")
        for node in range(self.V):
            print(node, "\t\t", dist[node])

    # A utility function to find the vertex with
    # minimum distance value, from the set of vertices
    # not yet included in shortest path tree
    def minDistance(self, dist, sptSet):

        # Initialize minimum distance for next node
        min_index = None
        min = 1e7

        # Search not nearest vertex not in the
        # shortest path tree
        for v in range(self.V):
            if dist[v] < min and sptSet[v] == False:
                min = dist[v]
                min_index = v

        return min_index

    # Function that implements Dijkstra's single source
    # shortest path algorithm for a graph represented
    # using adjacency matrix representation
    def dijkstra(self, src):

        dist = [1e7] * self.V
        dist[src] = 0
        sptSet = [False] * self.V

        for cout in range(self.V):

            # Pick the minimum distance vertex from
            # the set of vertices not yet processed.
            # u is always equal to src in first iteration
            u = self.minDistance(dist, sptSet)

            if u is not None:
                # Put the minimum distance vertex in the
                # shortest path tree
                sptSet[u] = True

            # Update dist value of the adjacent vertices
            # of the picked vertex only if the current
            # distance is greater than new distance and
            # the vertex in not in the shortest path tree
            for v in range(self.V):
                if (self.graph[u][v] >= 0 and
                        sptSet[v] == False and
                        dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]

        # self.printSolution(dist)
        return dist

inpStr = 'a' + inpStr + 'z'

vertices = {}
for i in range(len(inpStr)):
    for x in range(i+1, len(inpStr)):
        if ord(inpStr[x]) > ord(inpStr[i]):
            node = (x, ord(inpStr[x]) - ord(inpStr[i]) - 1)
            if i in vertices.keys():
                vertices[i].append(node)
            else:
                vertices[i] = [node]

g = Graph(len(inpStr))
g.graph = [[1e6 for y in range(len(inpStr))] for x in range(len(inpStr))]
for v in vertices.keys():
    for x in vertices[v]:
        g.graph[v][x[0]] = x[1]

aIndexes = []
zIndexes = []

for i in range(len(inpStr)):
    if inpStr[i] == 'a':
        aIndexes.append(i)
    elif inpStr[i] == 'z':
        zIndexes.append(i);

shortest_path = 1e7
for aIndex in aIndexes:
    dist = g.dijkstra(aIndex);

    for zIndex in zIndexes:
        path = 0;
        if zIndex == len(inpStr) - 1:
            path = path + 1;
        if aIndex == 0:
            path = path + 1;
        path = path + dist[zIndex]

        if path < shortest_path:
            shortest_path = path;

print(shortest_path)
