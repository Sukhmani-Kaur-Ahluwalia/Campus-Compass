#ifndef GRAPH_TYPES_H
#define GRAPH_TYPES_H

#include <string>
#include <climits> // For INT_MAX

using namespace std;

#define INF INT_MAX 
#define MAX_LOCATIONS 100 

// ======================== GRAPH DATA STRUCTURES ========================

// Structure for an edge (path) in the campus map
typedef struct Edge {
    int dest_id; // Destination location ID
    int weight;  // Distance/cost (weight)
    struct Edge* next;
} E;

// ======================== MIN-HEAP DATA STRUCTURES ========================

// Pair for the Min-Heap: (distance, location_id)
typedef struct Pair {
    int distance;
    int location_id;
} Pair;

// ======================== QUEUE DATA STRUCTURES ========================

// Node for the Queue (used by BFS)
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode;

#endif