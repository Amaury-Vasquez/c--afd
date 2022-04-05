#include <vector>
#include <string>
#include <iostream>

#include "FileReader/FileReader.h"

int main() {
  std::vector<std::string> words = FileReader::split_string("hola maricas me llamo amaury");
  for(int i = 0; i < words.size(); i++)
    std::cout << words.at(i) << std::endl;
  return 0;
}
