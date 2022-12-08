/*
  Advent of Code day 6 pt 1
  Mascelli Leonardo
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
bool is_unique(T arr){
  bool other = false;
  for (unsigned int i=0; i<arr.size()-1; i++){
    for (unsigned int j=i+1; j<arr.size(); j++ ){
      if (arr[i] == arr[j]) other = true;
    }
    if (other) return false;
  }
  return true;
}

void p1(istream &input) {
  string line;
  getline(input, line);
  const unsigned int unique_size = 14;
  bool found;

  unsigned int index = 0;
  while (index < (line.size() - unique_size)) {
    found = false;
    if (is_unique(line.substr(index, unique_size))) break;
    else index++;
  }
  cout << index + unique_size << endl;
}

int main(int argc, char **argv) {
  ifstream ifs("input.txt");
  p1(ifs);
  return 0;
}
