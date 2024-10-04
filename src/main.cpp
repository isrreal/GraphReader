#include "Graph.hpp"

#include <sstream>
#include <fstream>

// Read whole info of the file "graph.txt"
// Reads the first line: order and size of graph, respectively, and build his edges 

std::vector<Graph*> readGraphs() {
    std::vector<Graph*> graphs;
    std::list<Vertex*> vertices;
    std::vector<std::pair<int, int>> edges;
    std::string line;
    size_t order = 0;
    size_t size = 0;
    int source = 0;
    int destiny = 0;
    std::ifstream file("graph.txt", std::fstream::in);
    if (!file) {
        std::cerr << "Error!" << std::endl;
        return {};
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ss >> order >> size;

        for (size_t i = 0; i < order; ++i)
            vertices.push_back(new Vertex(i));

        while (edges.size() < size) {
            std::getline(file, line);
            std::stringstream ssEdges(line);

            while ((edges.size() < size) && (ssEdges >> source >> destiny))
                edges.push_back({source, destiny});
        }
        
        graphs.push_back(new Graph(vertices, edges));
        vertices.clear();
        edges.clear();
    }
    return graphs;
}


int main() {
    std::vector<Graph*> graphs = readGraphs();
    graphs.clear();
    return 0;
}
