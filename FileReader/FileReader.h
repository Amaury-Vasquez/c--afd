#include <vector>
#include <string>

class FileReader {
  public:
    FileReader(std::string);
    static int **create_transition_table(std::vector <string>);
    static std::vector<std::string> split_string(std::string);
    static std::vector<int> vector_string_to_int(std::vector <std::string>);

  private:
    std::vector<std::string> alphabet;
    std::vector<int> accept_states;
    int **transition_table;
};