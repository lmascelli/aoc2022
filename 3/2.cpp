/*
Leonardo Mascelli.
Advent of Code 2022 day 3 pt 1

find the common element each three lines, the corrisponding value and sum each
value found

each element is labeled with a letter from a-zA-Z with corresponding value of
1(a) -> 26(z); 27(A) -> 52(Z)
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  int res = 0;
  string elf1, elf2, elf3;
  ifstream ifs("input.txt");
  while (not ifs.eof()) {
    unsigned int e1[52] = {0} , e2[52] = {0}, e3[52] = {0};
    getline(ifs, elf1);
    getline(ifs, elf2);
    getline(ifs, elf3);
    for (unsigned int i = 0; i < elf1.length(); i++) {
      int el = (int)elf1[i];
      el - (int)('a') >= 0 ? e1[el - (int)'a'] = 1 : e1[26 + el - (int)'A'] = 1;
    }
    for (unsigned int i = 0; i < elf2.length(); i++) {
      int el = (int)elf2[i];
      el - (int)('a') >= 0 ? e2[el - (int)'a'] = 1 : e2[26 + el - (int)'A'] = 1;
    }
    for (unsigned int i = 0; i < elf3.length(); i++) {
      int el = (int)elf3[i];
      el - (int)('a') >= 0 ? e3[el - (int)'a'] = 1 : e3[26 + el - (int)'A'] = 1;
    }
    for (unsigned int i=0; i<52; i++) {
      if (e1[i] and e2[i] and e3[i]) res += i+1;
    }
  }
  ifs.close();
  cout << res << endl;
  return 0;
}
