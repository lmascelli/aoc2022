#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  ifstream ifs("input.txt");
  unsigned long sel_elf = 0, cur_elf = 0;
  string buf;
  
  while(not ifs.eof()) {
    getline(ifs, buf);
    if (not buf.empty()) {
      cur_elf += stoi(buf);
    } else {
      sel_elf = max(sel_elf, cur_elf);
      cur_elf = 0;
    }
  }
  cout << sel_elf << endl;
  return 0;
}
