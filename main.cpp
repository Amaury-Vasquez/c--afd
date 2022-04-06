#include <vector>
#include <string>
#include <iostream>

#include "FileReader/FileReader.h"

using namespace std;

template <typename T>
void print_vector(vector <T>);

int main() {
  FileReader reader("automata1.txt");
  print_vector(reader.get_alphabet());
  print_vector(reader.get_accept_states());
  return 0;
}

template <typename T>
void print_vector(vector <T> vec) {
  for(int i = 0; i < vec.size(); i++) 
    cout << vec.at(i) << " ";
  cout << endl;
}
