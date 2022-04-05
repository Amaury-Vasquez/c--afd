#include <vector>
#include <string>

using namespace std;

class FileReader {
  public:
    FileReader(string);
    static vector<string> split_string(string);

  private:
    vector<char> alphabet;
    vector<int> accept_states;
    int **transition_table;
};