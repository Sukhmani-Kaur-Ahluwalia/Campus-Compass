#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "graph_types.h"
#include "graph_funcs.h"
#include "queue.h"
void Graph::perform_bfs(int start_id)
{
    bool visited[MAX_LOCATIONS] = {false};
    Queue q;

    if (LocationNames[start_id].empty())
    {
        cout << "Error: Invalid starting location for BFS." << endl;
        return;
    }

    visited[start_id] = true;
    q.enqueue(start_id);

    cout << "\n--- Basic Path Check (BFS) starting from " << get_location_name(start_id) << " ---\n";
    cout << "Traversal Order: ";

    while (!q.is_empty())
    {
        int current_id = q.dequeue();
        cout << get_location_name(current_id) << " ";

        E* current_edge = CampusMapHeads[current_id];
        while (current_edge != nullptr)
        {
            int neighbor_id = current_edge->dest_id;
            if (!visited[neighbor_id])
            {
                visited[neighbor_id] = true;
                q.enqueue(neighbor_id);
            }
            current_edge = current_edge->next;
        }
    }
    cout << "\n";
}
