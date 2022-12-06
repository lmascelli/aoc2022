/*

*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct crate {
  vector<char> pile;
  unsigned int length{0};
};

int main(int argc, char *argv[]) {
  ifstream ifs("input.txt");
  string line;
  unsigned int num, from, to;
  bool stop = false;

  // setup the right num of crates
  getline(ifs, line);
  const unsigned int crates_num = line.length() / 4 + 1;
  const unsigned int line_length = crates_num * 4 - 1;
  vector<crate> crates(crates_num);
  {
    // parsing initial state
    // temp crate for storing reversed initial state
    vector<vector<char>> crates_(crates_num);
    while (true) {
      // end of the initial state reached; skip next line and quit loop;
      if (line.at(1) == '1') {
        getline(ifs, line);
        break;
      }
      // parse current crate line;
      // letter are in position 1 + 4*i
      for (unsigned int i = 0; i < crates_num; i++) {
        if (line.at(1 + 4 * i) != ' ') {
          crates_[i].push_back(line.at(1 + 4 * i));
        }
      }
      //      cout << line << endl;
      getline(ifs, line);
    }
    for (unsigned int i = 0; i < crates_.size(); i++){
      for (unsigned int j = crates_[i].size(); j > 0;){
        crates[i].pile.push_back(crates_[i][--j]);
      }
      crates[i].length = crates[i].pile.size();
    }
  }

  // checking the crates
  for (unsigned int i=0; i<crates_num; i++) {
    for (auto el : crates[i].pile)
      cout << el << " ";
    cout << endl;
  }

  // moving the crates
  while(not ifs.eof()){
    getline(ifs, line);
    if (ifs.eof()) break;
    unsigned int from_ = line.find("f");
    unsigned int to_ = line.find("t");
    num = stoi(line.substr(5, from_ - 5));
    cout << "num " << num;
    from = stoi(line.substr(from_ + 4, to_ - from_ - 5));
    cout << " from " << from;
    to = stoi(line.substr(to_+3, line.length()-to_ - 3));
    cout << " to " << to << endl;
  }
  
  ifs.close();
  return 0;
}
