#include "DocumentManager.h"

Document::Document() : Document("", 0, 0) {}

Document::Document(std::string name, int id, int licenseLimit)
    : name(name), id(id), licenseLimit(licenseLimit) {}

// DocumentManager class implementations
void DocumentManager::addDocument(std::string name, int id, int licenseLimit) {
  if (documents.find(id) != documents.end()) {
    throw std::runtime_error(
        "Document with this ID already exists.");  // Ensure unique ID
  }
  // Check for unique name as well, as nameToId assumes unique names
  if (nameToId.count(name)) {
    throw std::runtime_error("Document with this name already exists.");
  }

  nameToId[name] = id;  // Map document name to ID
  documents[id] = Document(name, id, licenseLimit);
  // std::cout << "Added Document: " << name << " (ID: " << id << ")" <<
  // std::endl; // Debug
}

void DocumentManager::addPatron(int patronId) {
  if (patrons.count(patronId)) {
    return;
  }
  patrons.insert(patronId);
  // std::cout << "Added Patron: " << patronId << std::endl; // Debug
}

int DocumentManager::search(std::string name) {
  auto it = nameToId.find(name);
  if (it != nameToId.end()) {
    // std::cout << "Search found document '" << name << "' with ID: " <<
    // it->second << std::endl; // Debug
    return it->second;  // Return document ID
  }
  // std::cout << "Search failed for document '" << name << "'" << std::endl; //
  // Debug
  return 0;  // Document not found
}

bool DocumentManager::borrowDocument(int documentId, int patronId) {
  // std::cout << "Attempting to borrow: Patron " << patronId << ", Document "
  // << documentId << std::endl; // Debug

  if (patrons.find(patronId) == patrons.end()) {
    // std::cout << "Borrow failed: Patron " << patronId << " not registered."
    // << std::endl; // Debug
    return 0;  // Patron not registered
  }
  auto docIt = documents.find(documentId);
  if (docIt == documents.end()) {
    // std::cout << "Borrow failed: Document " << documentId << " not found." <<
    // std::endl; // Debug
    return 0;  // Document not found
  }
  Document& doc = docIt->second;
  if (doc.currentPatrons.size() >= static_cast<size_t>(doc.licenseLimit)) {
    // std::cout << "Borrow failed: Document " << documentId << " license limit
    // reached." << std::endl; // Debug
    return 0;  // License limit reached
  }

  if (doc.currentPatrons.count(patronId)) {
    // std::cout << "Borrow failed: Patron " << patronId << " already borrowed
    // Document " << documentId << "." << std::endl; // Debug
    return 0;  // Patron already borrowed it
  }
  doc.currentPatrons.insert(patronId);
  // std::cout << "Borrow successful: Patron " << patronId << " borrowed
  // Document " << documentId << "." << std::endl; // Debug
  return 1;  // Document borrowed successfully
}

void DocumentManager::returnDocument(int documentId, int patronId) {
  // std::cout << "Attempting to return: Patron " << patronId << ", Document "
  // << documentId << std::endl; // Debug

  auto docIt = documents.find(documentId);
  if (docIt == documents.end()) {
    // std::cout << "Return failed: Document " << documentId << " not found." <<
    // std::endl; // Debug
    throw std::runtime_error("Document not found.");
  }
  Document& doc = docIt->second;
  if (doc.currentPatrons.find(patronId) == doc.currentPatrons.end()) {
    // std::cout << "Return failed: Patron " << patronId << " did not borrow
    // Document " << documentId << "." << std::endl; // Debug
    throw std::runtime_error("Patron did not borrow this document.");
  }
  doc.currentPatrons.erase(patronId);  // Remove patron from current patrons
  // std::cout << "Return successful: Patron " << patronId << " returned
  // Document " << documentId << "." << std::endl; // Debug
}