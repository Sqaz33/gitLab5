#include <cstddef>
#include <exception>
#include <iostream>

#include "src/graph.hpp"

namespace {
    // прочитать граф из входного потока 
    graph::Graph readGraph(std::istream& is) {
        using namespace graph;

        std::size_t V = 0;
        is >> V;

        std::size_t E = 0;
        is >> E;

        Graph g(V);

        while (E--) {
            Vertex_t v, w;
            is >> v >> w;
            g.addEdge(v, w);
        }

        return g;
    }
} // namespace


int main() try { 
    auto g = readGraph(std::cin);
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
} catch (...) {
    std::cerr << "Unknown exception\n";
} 