#include "Autocomplete.h"

TrieNode::TrieNode() : isEndOfWord(false) {}

Autocomplete::Autocomplete() { root = new TrieNode(); }

void Autocomplete::insert(string word) {
  TrieNode* curr = root;
  for (char c : word) {
    if (!curr->children[c]) curr->children[c] = new TrieNode();
    curr = curr->children[c];
  }
  curr->isEndOfWord = true;
}

void Autocomplete::dfs(TrieNode* node, string prefix, vector<string>& results) {
  if (node->isEndOfWord) {
    results.push_back(prefix);
  }
  for (auto& pair : node->children) {
    dfs(pair.second, prefix + pair.first, results);
  }
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
  TrieNode* curr = root;
  for (char c : partialWord) {
    if (!curr->children[c]) return {};
    curr = curr->children[c];
  }
  vector<string> results;
  dfs(curr, partialWord, results);
  return results;
}