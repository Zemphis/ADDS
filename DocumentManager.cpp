#include "DocumentManager.h"

Document::Document(std::string name, int id, int license_limit)
    : name(name), id(id), license_limit(license_limit) {}

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
  nameToId[name] = id;
  documents[id] = Document(name, id, license_limit);
}

void DocumentManager::addPatron(int patronID) { patrons.insert(patronID); }

int DocumentManager::search(std::string name) {
  auto it = nameToId.find(name);
  return (it != nameToId.end()) ? it->second : 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (patrons.find(patronID) == patrons.end()) return false;
  auto docIt = documents.find(docid);
  if (docIt == documents.end()) return false;

  Document& doc = docIt->second;
  if (doc.current_patrons.size() >= static_cast<size_t>(doc.license_limit))
    return false;
  if (doc.current_patrons.find(patronID) != doc.current_patrons.end())
    return false;

  doc.current_patrons.insert(patronID);
  return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
  auto docIt = documents.find(docid);
  if (docIt != documents.end()) {
    docIt->second.current_patrons.erase(patronID);
  }
}
