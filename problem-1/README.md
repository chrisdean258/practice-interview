# Problem 1

In `reachable.c` please implement `uint64_t reachable(uint64_t graph[64], size_t start_node)`.

`graph` an array of 64 elements which represent a directed graph. Each element
at index `i` of `graph` is a bitmap which represents the outgoing edges from
vertex `i`. Bit 0 is 1 if there is an edge from node `i` to node 0 otherwise it
is a 0 and similarly for bits 1-63 and vertices 1-63 respectively.

`reachable()` is a function that accepts the graph and a start node and returns
a bitmap of reachable nodes. A node is reachable if there is a sequence of
edges from the start node to the target node. The reachability of any given
node should be encoded in the bitmap similarly to how the edges are encoded in
the graph e.i. if node `i` is reachable from `start_node` the the `i`th bit of
the return value should be 1 and otherwise it should be 0.
