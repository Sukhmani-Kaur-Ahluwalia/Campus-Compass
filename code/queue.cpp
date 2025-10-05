#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// QUEUE  IMPLEMENTATION
Queue::Queue() : front_ptr(nullptr), rear_ptr(nullptr) {}

Queue::~Queue()
{
    while (front_ptr)
    {
        dequeue(); // Dequeue handles freeing nodes
    }
}

bool Queue::is_empty() const
{
    return front_ptr == nullptr;
}

void Queue::enqueue(int value)
{
    QNode* new_node = new QNode;
    if (!new_node)
    {
        cerr << "Queue: Memory failed" << endl;
        exit(1);
    }
    new_node->data = value;
    new_node->next = nullptr;

    if (rear_ptr == nullptr)
    {
        front_ptr = rear_ptr = new_node;
    }
    else
    {
        rear_ptr->next = new_node;
        rear_ptr = new_node;
    }
}

int Queue::dequeue()
{
    if (front_ptr == nullptr)
        {
            return -1;
        }

    QNode* temp = front_ptr;
    int value = temp->data;
    front_ptr = front_ptr->next;

    if (front_ptr == nullptr)
    {
        rear_ptr = nullptr;
    }

    delete temp;
    return value;
}
