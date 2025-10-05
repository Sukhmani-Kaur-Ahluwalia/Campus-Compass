#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
// MIN-HEAP CLASS IMPLEMENTATION

MinHeap::MinHeap(int cap) : capacity(cap), size(0)
{
    heap_array = new Pair[cap];
}

MinHeap::~MinHeap()
{
    delete[] heap_array;
}

void MinHeap::swap_pair(Pair* x, Pair* y)
{
    Pair temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::min_heapify(int i)
{
    int l = get_left(i);
    int r = get_right(i);
    int smallest = i;

    if (l < size && heap_array[l].distance < heap_array[smallest].distance)
        smallest = l;

    if (r < size && heap_array[r].distance < heap_array[smallest].distance)
        smallest = r;

    if (smallest != i)
    {
        swap_pair(&heap_array[i], &heap_array[smallest]);
        min_heapify(smallest);
    }
}

void MinHeap::insert_heap(Pair val)
{
    if (size == capacity) return;
    size++;
    int i = size - 1;
    heap_array[i] = val;
    while (i != 0 && heap_array[get_parent(i)].distance > heap_array[i].distance)
    {
        swap_pair(&heap_array[i], &heap_array[get_parent(i)]);
        i = get_parent(i);
    }
}

Pair MinHeap::extract_min()
{
    if (size <= 0)
    return {INF, -1};
    if (size == 1)
    {
        size--;
        return heap_array[0];
    }
    Pair root = heap_array[0];
    heap_array[0] = heap_array[size - 1];
    size--;
    min_heapify(0);
    return root;
}
