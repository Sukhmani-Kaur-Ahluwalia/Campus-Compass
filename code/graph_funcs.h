#ifndef GRAPH_FUNCS_H
#define GRAPH_FUNCS_H

#include "graph_types.h"
#include <cstring>

using namespace std;

// ======================== GRAPH CLASS ========================
class Graph {
private:
    string LocationNames[MAX_LOCATIONS];
    E* CampusMapHeads[MAX_LOCATIONS];
    int total_locations;

    void insert_path(int from_id, int to_id, int weight);
    void print_shortest_route_recursive(int parent_array[], int current_id) const;

public:
    Graph();
    ~Graph();

    void add_location(int id, const string& name);
    void connect_locations(int from_id, int to_id, int weight);

    const string& get_location_name(int id) const;
    int get_total_locations() const { return total_locations; }
    E* get_adjacency_list(int id) const { return CampusMapHeads[id]; }

    // Core Algorithms (Implemented in separate .cpp files)
    void find_shortest_route(int start_id, int end_id);
    void perform_bfs(int start_id); // BFS is now a method of Graph
};

#endif
