#ifndef NODE_H
#define NODE_H

#include "Trajet.h"
class Node{
    private:
        Trajet* t;
        Node* next;
    public:
    Trajet* getTrajet() const;
    Node* getNext() const;

    void setTrajet(Trajet* newT);
    void setNext(Node* nextNode);
};
#endif