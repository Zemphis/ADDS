#include "PrefixMatcher.h"

PrefixNode::PrefixNode() : routerNumber(-1) {}

PrefixMatcher::PrefixMatcher() { root = new PrefixNode(); }

void PrefixMatcher::insert(string address, int routerNumber) {
  PrefixNode* curr = root;
  for (char bit : address) {
    if (!curr->children[bit]) curr->children[bit] = new PrefixNode();
    curr = curr->children[bit];
  }
  curr->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
  PrefixNode* curr = root;
  int bestMatch = -1;
  for (char bit : networkAddress) {
    if (!curr->children[bit]) break;
    curr = curr->children[bit];
    if (curr->routerNumber != -1) bestMatch = curr->routerNumber;
  }
  return bestMatch;
}