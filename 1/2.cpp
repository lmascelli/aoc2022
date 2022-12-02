#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
  ifstream ifs("input.txt");
  unsigned long
    sel_1 = 0,
    sel_2 = 0,
    sel_3 = 0,
    cur_elf = 0;
  string buf;
  
  while(not ifs.eof()) {
    getline(ifs, buf);
    if (not buf.empty()) {
      cur_elf += stoi(buf);
    } else {
      if (cur_elf > sel_3) {
	if (cur_elf > sel_2) {
	  sel_3 = sel_2;
	  if (cur_elf > sel_1) {
	    sel_2 = sel_1;
	    sel_1 = cur_elf;
	  }
	  else {
	    sel_2 = cur_elf;
	  }
	}
	else {
	  sel_3 = cur_elf;
	}
      }
      cur_elf = 0;
    }
  }
  cout << sel_1 + sel_2 + sel_3 << endl;
  return 0;
}
