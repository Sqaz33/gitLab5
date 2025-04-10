#include <cstddef>
#include <exception>
#include <iostream>
#include <fstream>

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

// входные данные:
// 1 строка : число V - количество вершин
// 2 строка : число E - количество ребер
// 3 - E+3 строки : v w ребро графа
int main(int argc, char** argv) try { 
    graph::Graph g;

    if (argc != 2) {
        g = readGraph(std::cin);
    } else {
        std::ifstream ifs(argv[1]);
        g = readGraph(ifs);
    }

} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
} catch (...) {
    std::cerr << "Unknown exception\n";
} 