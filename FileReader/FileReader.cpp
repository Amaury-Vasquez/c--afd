#include <fstream>
#include <iostream>

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
  // Assigns values to table
  vector <string> table_lines;
  while(!file.eof()) {
    string str;
    getline(file, str);
    table_lines.push_back(str);
  }
  int columns, rows;
  this->transition_table = create_transition_table(table_lines, &rows, &columns);
  this->columns = columns;
  this->rows = rows;
}

vector<string> FileReader::get_alphabet() { return this->alphabet; }

vector<int> FileReader::get_accept_states() { return this->accept_states; }

int** FileReader::get_transition_table() { return this->transition_table; }

int** FileReader::create_transition_table(vector <string> str_arr, int *rows, int *columns) {
  int i, j, **table = new int*[str_arr.size()];

  for(i = 0; i < str_arr.size(); i++) {
    // Declaracion/Inicializacion de variables
    string str = str_arr.at(i);
    vector <string> splitted_str = split_string(str);
    vector <int> arr = vector_string_to_int(splitted_str);
    table[i] = new int[arr.size()];
    
    //Asignacion elementos a la columna de la tabla
    for(j = 0; j < arr.size(); j++)
      table[i][j] = arr.at(i);
  }
  *rows = i;
  *columns = j;
  return table;
}

void FileReader::print_transition_table(int **table, int rows, int columns) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++)
      cout << table[i][j];
    cout << endl;
  }
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