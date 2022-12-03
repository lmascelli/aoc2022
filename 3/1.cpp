/*
Leonardo Mascelli.
Advent of Code 2022 day 3 pt 1

Each line has the content of an elf backpack, both the compartment
the first half and the second half related to different compartments.

there is an alien element in each backpack that is present in both the
compartments

each element is labeled with a letter from a-zA-Z with corresponding value of
1(a) -> 26(z); 27(A) -> 52(Z)

the goal is to find the total of values of all alien objects of all backpacks
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  int res = 0, len = 0;
  string line;
  ifstream ifs("input.txt");
  while (not ifs.eof()) {
    unsigned int b1[52] = {0} , b2[52] = {0};
    getline(ifs, line);
    for (unsigned int i = 0; i < line.length() / 2; i++) {
      int el = (int)line[i];
      el - (int)('a') >= 0 ? b1[el - (int)'a'] = 1 : b1[26 + el - (int)'A'] = 1;
    }
    for (unsigned int i = line.length() / 2; i < line.length(); i++) {
      int el = (int)line[i];
      el - (int)('a') >= 0 ? b2[el - (int)'a'] = 1 : b2[26 + el - (int)'A'] = 1;
    }
    for (unsigned int i=0; i<52; i++) {
      if (b1[i] and b2[i]) res += i+1;
    }
  }
  ifs.close();
  cout << res << endl;
  return 0;
}
