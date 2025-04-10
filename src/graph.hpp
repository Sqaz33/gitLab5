#ifndef SRC_GRAPH_HPP
#define SRC_GRAPH_HPP

#include <vector>
#include <cstddef>

namespace graph {
     
using Vertex_t = std::size_t;

// без гарантии исключений
class Graph final {
    std::vector<std::vector<Vertex_t>> adjs_;
    std::size_t E_ = 0;

public:
    Graph(std::size_t V) : adjs_(V) {}
    Graph() = default;

public:
    void addEdge(Vertex_t v, Vertex_t w) {
        adjs_[v].push_back(w);
        adjs_[w].push_back(v);
    }

    decltype(auto) adj(Vertex_t v) const noexcept {
        return adjs_[v];
    }

    auto E() const noexcept { return E_; }
    auto V() const noexcept { return adjs_.size(); }
};

} // namespace graph

#endif // SRC_GRAPH_HPP