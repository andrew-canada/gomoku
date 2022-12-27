# graphs

## types of graphs

- special graphs
  - null graph: no edges
  - trivial graphs: only one point
  - directed acyclic graph: directed graph with no cycle
  - bipartite graph: nodes divided into 2 sets, whithin each of which no edges exist
  - weighted graph: edges have a weight (e.g., road choice difficulties)
- directions
  - undirected graphs: edge order doesn't matter
  - directed graphs: on sided edge
- connections
  - connected graphs: all nodes connected
  - disconnected graphs: at least one node unreachable
- vertex/node degrees
  - regular graphs: all vertex degrees equal. (e.g., square is called 2-regular)
  - complete graphs: all nodes connected
- cycles
  - cycle graph: graph itself is a cycle
  - cyclic graph: graph contains a cycle

## tree vs graph

- tree is a directed graph that goes exclusively from up to down (root to leaves)

## graph representation

- two ways to store graph:
  - adjacency matrix
    - 2d matrix
    - rows and columns denote verticies
    - entry inside matrix is edge weight between verticies
  - adjacecy list
    - collection of linked lists
    - array of pointer pointing to connected edges to a node
