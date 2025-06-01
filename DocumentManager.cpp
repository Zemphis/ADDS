#include "DocumentManager.h"

Document::Document(std::string name, int id, int licenseLimit)
    : name(name), id(id), licenseLimit(licenseLimit) {}

void DocumentManager::addDocument(std::string name, int id, int licenseLimit) {
  if (documents.find(id) != documents.end()) {
    throw std::runtime_error(
        "Document with this ID already exists.");  // Ensure unique ID
  }
  nameToId[name] = id;  // Map document name to ID
  documents[id] = Document(name, id, licenseLimit);
}

void DocumentManager::addPatron(int patronId) { patrons.insert(patronId); }

int DocumentManager::searchDocument(std::string name) {
  auto it = nameToId.find(name);
  if (it != nameToId.end()) {
    return it->second;  // Return document ID
  }
  return -1;  // Document not found
}

bool DocumentManager::borrowDocument(int patronId, int documentId) {
  if (patrons.find(patronId) == patrons.end()) {
    return false;  // Patron not registered
  }
  auto docIt = documents.find(documentId);
  if (docIt == documents.end()) {
    return false;  // Document not found
  }
  Document& doc = docIt->second;
  if (doc.currentPatrons.size() >= static_cast<size_t>(doc.licenseLimit)) {
    return false;  // License limit reached
  }
  if (doc.currentPatrons.count(patronId)) {
    return false;  // Patron already borrowed it
  }
  doc.currentPatrons.insert(patronId);
  return true;  // Document borrowed successfully
}

void DocumentManager::returnDocument(int patronId, int documentId) {
  auto docIt = documents.find(documentId);
  if (docIt == documents.end()) {
    throw std::runtime_error("Document not found.");
  }
  Document& doc = docIt->second;
  if (doc.currentPatrons.find(patronId) == doc.currentPatrons.end()) {
    throw std::runtime_error("Patron did not borrow this document.");
  }
  doc.currentPatrons.erase(patronId);  // Remove patron from current patrons
}