#ifndef QUEUE_H
#define QUEUE_H

#include "graph_types.h"

// ======================== QUEUE CLASS ========================
class Queue {
private:
    QNode* front_ptr;
    QNode* rear_ptr;

public:
    Queue();
    // Use destructor to free memory safely
    ~Queue(); 

    void enqueue(int value);
    int dequeue();
    bool is_empty() const;
};

#endif