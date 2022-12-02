#ifndef NODE_H
#define NODE_H

#include "Trajet.h"
class Node{
private:
    const Trajet* t;
    Node* next;
public:
    const Trajet* getTrajet() const;
    Node* getNext() const;

    void setTrajet(const Trajet* newT);
    void setNext(Node* nextNode);

    virtual ~Node();
};
#endif