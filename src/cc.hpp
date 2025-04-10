#ifndef SRC_CC_HPP
#define SRC_CC_HPP

#include <vector>
#include <cstddef>

#include "graph.hpp"

namespace cc {
using Id_t = std::size_t; 

// без гарантии исключений
class CC final {
    std::vector<std::size_t> ids_;
    std::vector<bool> marked_;
    Id_t count = 0;

    void dfs(const graph::Graph& g) {}

public:
    CC(const graph::Graph& g)  :
        ids_(g.V())
        , marked_(g.V(), false)
    {   
        for (graph::Vertex_t s = 0; s < g.V(); ++s) {
            if (!marked_[s]) {
                dfs_(g, s);
                ++count_;
            } 
        }
    }

public:
    bool connected(graph::Vertex_t v, graph::Vertex_t w) const {
        return ids_[v] == ids_[w];
    }

    Id_t id(graph::Vertex_t v) const;
};

} // namespace cc 

#endif // SRC_CC_HPP