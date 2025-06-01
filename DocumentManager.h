#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Document {
 public:
  std::string name;
  int id;
  int licenseLimit;
  std::unordered_set<int> currentPatrons;
  Document();
  Document(std::string name, int id, int licenseLimit);
};
// DocumentManager class manages documents and their patrons

class DocumentManager {
 private:
  std::unordered_map<std::string, int>
      nameToId;  // Maps document name to document ID
  std::unordered_map<int, Document>
      documents;                    // Maps document ID to Document object
  std::unordered_set<int> patrons;  // Set of patron IDs

 public:
  DocumentManager() = default;

  void addDocument(std::string name, int id, int licenseLimit);
  void addPatron(int patronId);
  int search(std::string name);
  bool borrowDocument(int documentID, int patronId);
  void returnDocument(int documentId, int patronId);
};

#endif
