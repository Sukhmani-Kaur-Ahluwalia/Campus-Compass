#include "graph.h"
#include <iostream>
#include <string>

using namespace std;

void insert(E* heads[], int from, int to, int wt) {
    E* p = new E;
    p->to = to;
    p->wt = wt;
    p->next = heads[from];
    heads[from] = p;
}

Graph::Graph() {
    size = 0;
    for(int i = 0; i < MAX; i++) {
        heads[i] = NULL;
        names[i] = "";
    }
}

void Graph::add(int id, const string& name) {
    if (id >= 0 && id < MAX) {
        if (names[id].length() == 0) {
            size++;
        }
        names[id] = name;
        heads[id] = NULL;
    } else {
        cout << "Error" << endl;
    }
}

void Graph::connect(int from, int to, int wt) { //3,2,20
    int validFrom = 0;
    int validTo = 0;

    if (from >= 0 && from < MAX && (names[from].length() > 0) ) {
        validFrom = 1; 
        }
    

    if (to >= 0 && to < MAX &&  (names[to].length() > 0)) {
       validTo = 1;
        }
    
    if (validFrom && validTo) {
        insert(heads, from, to, wt);
        insert(heads, to, from, wt);
    } else {
        cout << "Error" << endl;
    }
}

void Graph::show() const {
    cout << "\nMap" << endl;

    for(int i = 0; i < size; i++) {
        if (names[i].length() == 0) continue;

        cout << "\n" << names[i];
        E* p = heads[i];

        while(p != NULL) {
            cout << "---- > " << name(p->to) << " ( " << p->wt <<" m)";
            p = p->next;
        }
    }
}

int Graph::count() const {
    return size;
}

string Graph::name(int id) const {
    if(id >= 0 && id < MAX && names[id].length() > 0) {
        return names[id];
    }
    return " ";
}

E* Graph::list(int id) const {
    if(id >= 0 && id < MAX) {
        return heads[id];
    }
    return NULL;
}