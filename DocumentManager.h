#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class Document {
 public:
  std::string name;
  int id;
  int license_limit;
  std::unordered_set<int> current_patrons;

  Document(std::string name, int id, int license_limit);
};

class DocumentManager {
 private:
  std::unordered_map<std::string, int> nameToId;
  std::unordered_map<int, Document> documents;
  std::unordered_set<int> patrons;

 public:
  void addDocument(std::string name, int id, int license_limit);
  void addPatron(int patronID);
  int search(std::string name);
  bool borrowDocument(int docid, int patronID);
  void returnDocument(int docid, int patronID);
};

#endif
