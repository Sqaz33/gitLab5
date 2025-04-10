#ifndef SRC_CC_HPP
#define SRC_CC_HPP

#include <vector>
#include <cstddef>
#include <stack>

#include "graph.hpp"

namespace cc {
using Id_t = std::size_t; 

// без гарантии исключений
class CC final {
    std::vector<std::size_t> ids_;
    std::vector<bool> marked_;
    Id_t count_ = 0;

    void dfs_(const graph::Graph& g, graph::Vertex_t v) {
        std::stack<graph::Vertex_t> stack;
        stack.push(v);
        
        while (!stack.empty()) {
            auto v = stack.top(); stack.pop();
            for (auto&& w : g.adj(v)) {
                if (!marked_[w]) {
                    ids_[w] = count_;
                    marked_[w] = true;
                }
            }   
        }
    } 

public:
    CC(const graph::Graph& g) {}

public:
    bool connected(graph::Vertex_t v, graph::Vertex_t w) const {}

    Id_t id(graph::Vertex_t v) const {}
};

} // namespace cc 

#endif // SRC_CC_HPP
