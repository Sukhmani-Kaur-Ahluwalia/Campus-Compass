#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "graph_types.h"
#include "graph_funcs.h"
#include "queue.h"
#include "heap_funcs.h"


//DIJKSTRA'S ALGORITHM IMPLEMENTATION

void Graph::print_shortest_route_recursive(int parent_array[], int current_id) const
{
    if (parent_array[current_id] == -1)
    {
        cout << get_location_name(current_id);
        return;
    }
    print_shortest_route_recursive(parent_array, parent_array[current_id]);
    cout << " -> " << get_location_name(current_id);
}

void Graph::find_shortest_route(int start_id, int end_id)
{
    int shortest_dist[MAX_LOCATIONS];
    int parent_route[MAX_LOCATIONS];

    if (LocationNames[start_id].empty() || LocationNames[end_id].empty())
    {
        cout << "Error: Invalid start or end location for Dijkstra's." << endl;
        return;
    }

    // 1. Initialization
    for (int i = 0; i < MAX_LOCATIONS; i++)
    {
        shortest_dist[i] = INF;
        parent_route[i] = -1;
    }

    // 2. Setup Min-Heap
    MinHeap pq(MAX_LOCATIONS * 2);

    shortest_dist[start_id] = 0;
    pq.insert_heap({0, start_id});

    cout << "\n\n--- Shortest Route Guidance via Dijkstra's ---\n";
    cout << "Finding path from " << get_location_name(start_id) << " to " << get_location_name(end_id) << "...\n";

    // 3. Main Algorithm Loop
    while (!pq.is_empty())
    {
        Pair current_pair = pq.extract_min();
        int current_id = current_pair.location_id;
        int current_dist = current_pair.distance;

        if (current_dist > shortest_dist[current_id]) continue;

        if (current_id == end_id)
        {
            cout << "Shortest Distance: " << shortest_dist[end_id] << " meters\n";
            cout << "Optimized Route: ";
            print_shortest_route_recursive(parent_route, end_id);
            cout << "\n";
            return;
        }

        // 4. Relaxation Step
        E* current_edge = CampusMapHeads[current_id];
        while (current_edge != nullptr)
        {
            int neighbor_id = current_edge->dest_id;
            int path_weight = current_edge->weight;

            if (shortest_dist[current_id] != INF &&
               ((long long)shortest_dist[current_id] + path_weight < shortest_dist[neighbor_id]))
            {
                shortest_dist[neighbor_id] = shortest_dist[current_id] + path_weight;
                parent_route[neighbor_id] = current_id;
                pq.insert_heap({shortest_dist[neighbor_id], neighbor_id});
            }
            current_edge = current_edge->next;
        }
    }

    if (shortest_dist[end_id] == INF)
    {
        cout << "The destination " << get_location_name(end_id) << " is unreachable from " << get_location_name(start_id) << ".\n";
    }
}
