#include <vector>
#include <string>

class FileReader {
  public:
    // Constructor
    FileReader(std::string);
    // Getters
    std::vector<std::string> get_alphabet();
    std::vector<int> get_accept_states();
    int ** get_transition_table();

    // Methods
    static int **create_transition_table(std::vector <std::string>, int *, int *);
    static void print_transition_table(int **, int, int);
    static std::vector<std::string> split_string(std::string);
    static std::vector<int> vector_string_to_int(std::vector <std::string>);

  private:
    std::vector<std::string> alphabet;
    std::vector<int> accept_states;
    int **transition_table;
    int columns, rows;
};