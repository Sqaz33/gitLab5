#ifndef SRC_PATH_HPP
#define SRC_PATH_HPP

#include <cstddef>
#include <queue>
#include <vector>

#include "graph.hpp"

namespace path {
     

// без гарантии исключений
class Path final {
    using Vertex_t = graph::Vertex_t;

    const Vertex_t src_;
    std::vector<Vertex_t> pathTo_;

    void bfs_(const graph::Graph& g, Vertex_t v) {
        std::vector<bool> marked_(g.V(), false);
        marked_[v] = true;
        std::queue<Vertex_t> q;
        q.push(v);
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (auto w : g.adj(v)) {
                if (!marked_[w]) {
                    pathTo_[w] = v;
                    marked_[w] = true;
                    q.push(w);
                }
            }
        }
    }

public:
    Path(const graph::Graph& g, Vertex_t src);

public:
    std::vector<Vertex_t> pathTo(Vertex_t v);
};

} // namespace path

#endif // SRC_PATH_HPP