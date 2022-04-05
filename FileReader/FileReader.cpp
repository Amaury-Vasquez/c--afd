#include <fstream>

#include "FileReader.h"

FileReader::FileReader(std::string filename) {
  ifstream file(filename);
  string alphabet;
  getline(file, alphabet);
}

vector<string> FileReader::split_string(string line) {
  vector<string> words;
  string str;
  
  for(int i = 0; i < line.length(); i++) {
    char c = line.at(i);
    if(c == ' '){
      words.push_back(str);
      str.clear();
    }
    else
      str += c;
  }
  
  if(str.length() > 0)
    words.push_back(str);
  return words;
}