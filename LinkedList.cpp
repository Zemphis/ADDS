#include "LinkedList.h"

#include <iostream>
#include <limits>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
  for (int i = 0; i < len; ++i) {
    insertPosition(i + 1, array[i]);
  }
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->getLink();
    delete temp;
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
  Node* newNode = new Node(newNum);

  if (pos <= 1 || head == nullptr) {
    newNode->setLink(head);
    head = newNode;
    return;
  }

  Node* current = head;
  int index = 1;
  while (current != nullptr && index < pos - 1) {
    if (current->getLink() == nullptr) {
      break;
    }
    current = current->getLink();
    ++index;
  }

  newNode->setLink(current->getLink());
  current->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
  if (pos < 1 || head == nullptr) return false;

  if (pos == 1) {
    Node* temp = head;
    head = head->getLink();
    delete temp;
    return true;
  }

  Node* current = head;
  int index = 1;
  while (current != nullptr && index < pos - 1) {
    if (current->getLink() == nullptr) {
      break;
    }
    current = current->getLink();
    ++index;
  }

  if (current == nullptr || current->getLink() == nullptr) return false;

  Node* target = current->getLink();
  current->setLink(target->getLink());
  delete target;
  return true;
}

int LinkedList::get(int pos) {
  if (pos < 1) return std::numeric_limits<int>::max();

  Node* current = head;
  int index = 1;
  while (current != nullptr && index < pos) {
    current = current->getLink();
    ++index;
  }

  if (current == nullptr) return std::numeric_limits<int>::max();
  return current->getData();
}

int LinkedList::search(int target) {
  Node* current = head;
  int index = 1;
  while (current != nullptr) {
    if (current->getData() == target) return index;
    current = current->getLink();
    ++index;
  }
  return -1;
}

void LinkedList::printList() {
  if (!head) {
    std::cout << "[]" << std::endl;
    return;
  }

  std::cout << "[";
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->getData();
    if (current->getLink() != nullptr) std::cout << " ";
    current = current->getLink();
  }
  std::cout << "]" << std::endl;
}