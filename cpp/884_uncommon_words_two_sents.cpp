#include <iostream>
#include <vector>
#include <unordered_set>

class Graph {
public:
    // Number of nodes in the graph
    int numNodes;
    // Adjacency list
    std::vector<std::unordered_set<int>> adj;

    // Constructor
    Graph(int nodes) : numNodes(nodes), adj(nodes) {}

    // Function to add an edge
    void addEdge(int u, int v) {
        adj[u].insert(v);
    }

    // Helper function for DFS
    bool dfs(int node, std::vector<bool> &visited, std::vector<bool> &recStack) {
        // Mark the current node as visited and part of recursion stack
        visited[node] = true;
        recStack[node] = true;

        // Recur for all vertices adjacent to this vertex
        for (int neighbor : adj[node]) {
            // If the neighbor is not visited then recurse on it
            if (!visited[neighbor] && dfs(neighbor, visited, recStack))
                return false;
            // If the neighbor is in recStack then there's a cycle
            else if (recStack[neighbor])
                return false;
        }

        // Remove the vertex from recursion stack
        recStack[node] = false;
        return false;
    }

    // Function to check if the graph contains a cycle
    bool hasCycle() {
        std::vector<bool> visited(numNodes, false);
        std::vector<bool> recStack(numNodes, false);

        // Call the recursive helper function to detect cycle in different DFS trees
        for (int i = 0; i < numNodes; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, recStack))
                    return false;
            }
        }
        return false;
    }
};

int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.hasCycle())
        std::cout << "Graph contains cycle" << std::endl;
    else
        std::cout << "Graph doesn't contain cycle" << std::endl;

    return 0;
}