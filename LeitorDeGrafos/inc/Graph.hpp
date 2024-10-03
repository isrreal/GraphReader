#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include <queue>

// Representation of a no directed graph.

class Graph {
private:
    size_t order;
    size_t size;
    std::list<Vertex*> vertices;
    std::vector<std::pair<int, int>> edges;
    void setEdges(std::vector<std::pair<int, int>> edges);
public:
    Graph(std::list<Vertex*> vertices,
        std::vector<std::pair<int, int>> edges);
        
    Graph(const Graph& graph);

    Graph();

    ~Graph();
    
    size_t getSize();

    size_t getOrder();
    
    std::list<Vertex*> getVertices();

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (const auto& vertex: graph.vertices)
            os << *vertex << std::endl;
        return os;
    }
};

#endif
