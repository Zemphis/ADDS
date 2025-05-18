#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <unordered_map>
using namespace std;

class PrefixNode {
 public:
  int routerNumber;
  unordered_map<char, PrefixNode*> children;
  PrefixNode();
};

class PrefixMatcher {
 private:
  PrefixNode* root;

 public:
  PrefixMatcher();
  void insert(string address, int routerNumber);
  int selectRouter(string networkAddress);
};

#endif
