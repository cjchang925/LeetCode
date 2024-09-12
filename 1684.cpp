#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
  int counter = 0;

  for (const string& str : words) {
      for (size_t i = 0; i < str.size(); ++i) {
          if (allowed.find(str[i]) == std::string::npos) {
              break;
          }

          if (i == str.size() - 1) {
              counter++;
          }
      }
  }

  return counter;
}

int main() {
  string allowed = "abc";
  vector<string> words;
  words.push_back("a");
  words.push_back("b");
  words.push_back("ce");
  words.push_back("ab");
  words.push_back("ac");
  cout << countConsistentStrings(allowed, words) << endl;
  return 0;
}
