#ifndef BFS_H
#define BFS_H

// Forward declarations to avoid circular dependencies
class Graph; 

// BFS implementation for basic path checking (unweighted search)
void perform_bfs(Graph* g, int start_id);

#endif