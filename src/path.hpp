#ifndef SRC_PATH_HPP
#define SRC_PATH_HPP

#include <vector>
#include <cstddef>

#include "graph.hpp"

namespace path {
     

// без гарантии исключений
class Path final {
    using Vertex_t = graph::Vertex_t;

    const Vertex_t src_;
    std::vector<Vertex_t> pathTo_;

    void bfs_(const graph::Graph& g, Vertex_t v);

public:
    Path(const graph::Graph& g, Vertex_t src);

public:
    std::vector<Vertex_t> pathTo(Vertex_t v);
};

} // namespace path

#endif // SRC_PATH_HPP