#include <fstream>

#include "FileReader.h"

using namespace std;

FileReader::FileReader(std::string filename) {
  ifstream file(filename);

  // Getting first two lines, alphabets and accept_states
  string alphabet, accept_states;
  getline(file, alphabet);
  getline(file, accept_states);

  // Assigns values to vectors
  this->alphabet = split_string(alphabet);
  vector <string> accept_strings = split_string(accept_states);
  this->accept_states = vector_string_to_int(accept_strings);
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

vector<int> FileReader::vector_string_to_int(vector <string> str_arr) {
  vector <int> arr;
  for(int i = 0; i < str_arr.size(); i++) {
    int value = stoi(str_arr[i]);
    arr.push_back(value);
  }
  return arr;
}