#ifndef HEAP_FUNCS_H
#define HEAP_FUNCS_H

#include "graph_types.h"

// ======================== MIN HEAP CLASS (Priority Queue) ========================
class MinHeap {
private:
    Pair* heap_array;
    int capacity;
    int size;

    int get_parent(int i) { return (i - 1) / 2; }
    int get_left(int i) { return (2 * i + 1); }
    int get_right(int i) { return (2 * i + 2); }

    void swap_pair(Pair* x, Pair* y);
    void min_heapify(int i);

public:
    MinHeap(int cap);
    ~MinHeap();

    void insert_heap(Pair val);
    Pair extract_min();
    bool is_empty() const { return size == 0; }
};

#endif
