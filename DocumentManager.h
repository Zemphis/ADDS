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
  bool borrowDocument(int patronId, int documentId);
  void returnDocument(int patronId, int documentId);
  void printDocumentState(int documentId) const {
    auto it = documents.find(documentId);
    if (it != documents.end()) {
      const Document& doc = it->second;
      std::cout << "Document ID: " << doc.id << ", Name: " << doc.name
                << ", License Limit: " << doc.licenseLimit
                << ", Current Patrons: ";
      for (int patron : doc.currentPatrons) {
        std::cout << patron << " ";
      }
      std::cout << std::endl;
    } else {
      std::cout << "Document with ID " << documentId << " not found."
                << std::endl;
    }
  }
};

#endif
