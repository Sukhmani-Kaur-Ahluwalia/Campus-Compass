#include <iostream>
#include <string>
#include <cstdlib> // For exit(1)


#include "graph_types.h"
#include "queue.h"
#include "graph_funcs.h"
#include "heap_funcs.h"


using namespace std;
int main()
{
    Graph campus_map;
    //Test case 1

    // 1. Adding Campus Locations (Vertices)
    campus_map.add_location(0, "Main Gate");
    campus_map.add_location(1, "CS/IT Block");
    campus_map.add_location(2, "Library");
    campus_map.add_location(3, "Fountain");
    campus_map.add_location(4, "Admin Block");
    campus_map.add_location(5, "Hostel");
    campus_map.add_location(6, "Cafeteria");

    // 2. Connecting Locations (Edges) with Weights (Distances in meters)
    campus_map.connect_locations(0, 1, 200);
    campus_map.connect_locations(0, 2, 100);
    campus_map.connect_locations(0, 3, 90);
    campus_map.connect_locations(1, 2, 110);
    campus_map.connect_locations(2, 4, 50);
    campus_map.connect_locations(3, 4, 30);
    campus_map.connect_locations(4, 5, 80);
    campus_map.connect_locations(5, 6, 20);
    campus_map.connect_locations(2, 6, 180);

    // 3. Demonstrating BFS (Basic Path Check)
    campus_map.perform_bfs(0);

    // 4. Dijkstra's Algorithm (Shortest Route Guidance)
    campus_map.find_shortest_route(0, 6); // Main Gate (0) to Cafeteria (6)

    /*
    // Test case 2
      campus_map.add_location(0, "Main Gate");
    campus_map.add_location(1, "Fountain");
    campus_map.add_location(2, "GEU Block");
    campus_map.add_location(3, "Admin Block");
    campus_map.add_location(4, "Electrical Engineering Block");
    campus_map.add_location(5, "Quick Bite Cafeteria");
    campus_map.add_location(6, "Laxmi Bai Hostel");
    campus_map.add_location(7, "CS/IT Block");
    campus_map.add_location(8, "Civil Block");

     campus_map.connect_locations(0, 1, 70);
    campus_map.connect_locations(0, 6, 110);
    campus_map.connect_locations(1, 3, 30);
    campus_map.connect_locations(1, 2, 20);
    campus_map.connect_locations(2, 4, 100);
    campus_map.connect_locations(2, 5, 60);
    campus_map.connect_locations(3, 4, 10);
    campus_map.connect_locations(4, 5, 80);
    campus_map.connect_locations(3, 8, 50);
    campus_map.connect_locations(6, 7, 120);

    campus_map.perform_bfs(0);

    campus_map.find_shortest_route(0, 6);
    campus_map.find_shortest_route(0, 7);
    campus_map.find_shortest_route(0, 8);
    campus_map.find_shortest_route(7, 8);
    campus_map.find_shortest_route(1, 5);
    */
/*

    //Test case 3

    campus_map.add_location(0, "A");
    campus_map.add_location(1, "B");
    campus_map.add_location(2, "C");
    campus_map.add_location(3, "D");

    campus_map.connect_locations(0, 1, 10);
    campus_map.connect_locations(0, 2, 20);
    campus_map.connect_locations(2, 3, 40);
    campus_map.connect_locations(1, 3, 20);

    campus_map.find_shortest_route(0, 3);
    campus_map.find_shortest_route(0, 2);
    campus_map.find_shortest_route(2, 3);

*/
    return 0;
}
