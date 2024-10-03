#include "Graph.hpp"

// Constructors 

Graph::Graph(std::list<Vertex*> vertices,
    std::vector<std::pair<int, int>> edges): 
        vertices(vertices),
        edges(edges),
        order(vertices.size()),
        size(edges.size()) {
            this->setEdges(edges);
            for (const auto& it: vertices) 
                order += it->adjacencies.size();           
}

Graph::Graph(const Graph& graph) {
    this->vertices = graph.vertices;
    this->edges = graph.edges;
    this->order = graph.order; 
    this->size = graph.size;
}

Graph::Graph() {}

// Destructor
Graph::~Graph() {
    for (auto& it: vertices)
        delete it;
}

// O(|V| * |E|)

void Graph::setEdges(std::vector<std::pair<int, int>> edges) {
    for (const auto& start: edges) {
        int source = start.first;
        int destiny = start.second;
        Vertex* v1 = nullptr;
        Vertex* v2 = nullptr;
        for (const auto& it: vertices) {
            if (it->identificator == source) {
                v1 = it;
                break;
            }
        }

        for (const auto& it: vertices) {
            if (it->identificator == destiny) {
                v2 = it;
                break;
            }
        }
   
        if (v1 && v2) { 
            v1->adjacencies.push_back(v2);
            v2->adjacencies.push_back(v1);
        }
    }
}

    size_t Graph::getOrder() { return this->order; }
    
    size_t Graph::getSize() { return this->size; }
    
    std::list<Vertex*> Graph::getVertices() { return this->vertices; }





