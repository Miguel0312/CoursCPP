#include "Node.h"
#include "Trajet.h"

const Trajet* Node::getTrajet() const{
    return t;
}

Node* Node::getNext() const{
    return next;
}

void Node::setTrajet(const Trajet* newT){
    t = newT;
}

void Node::setNext(Node* nextNode){
    next = nextNode;
}