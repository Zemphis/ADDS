#include "Node.h"

Node::Node(int val) : data(val), link(nullptr) {}

int Node::getData() const { return data; }

Node* Node::getLink() const { return link; }

void Node::setLink(Node* next) { link = next; }