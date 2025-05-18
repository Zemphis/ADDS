#include <iostream>

#include "Autocomplete.h"
#include "PrefixMatcher.h"

int main() {
  Autocomplete ac;
  ac.insert("bin");
  ac.insert("ball");
  ac.insert("ballet");

  vector<string> suggestions = ac.getSuggestions("bal");
  for (string& s : suggestions) {
    cout << s << endl;
  }

  PrefixMatcher pm;
  pm.insert("1100110111", 1);
  pm.insert("11001101", 2);
  pm.insert("11001101", 3);

  cout << "Router: " << pm.selectRouter("110011011001") << endl;

  return 0;
}