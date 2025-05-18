#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
 public:
  bool isEndOfWord;
  unordered_map<char, TrieNode*> children;
  TrieNode();
};

class Autocomplete {
 private:
  TrieNode* root;
  void dfs(TrieNode* node, string prefix, vector<string>& results);

 public:
  Autocomplete();
  void insert(string word);
  vector<string> getSuggestions(string partialWord);
};

#endif