/*
Leonardo Mascelli.
Advent of Code 2022 day 4 pt 2

Each line contains two pairs of number in the form x0-x1,y0-y1
the goal is to count how many times a range overlaps with the other
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("input.txt");
  int r1[2], r2[2], count = 0, lines = 0;
  string line, tmp1, tmp2;
  stringstream tokens;
  while(true){
    getline(ifs, line);
    if (ifs.eof()) break;
    tokens = stringstream(line);
    getline(tokens, tmp1, ',');
    getline(tokens, tmp2);
    r1[0] = stoi(tmp1.substr(0, tmp1.find('-')));
    r1[1] = stoi(tmp1.substr(tmp1.find('-')+1, tmp1.length()));
    r2[0] = stoi(tmp2.substr(0, tmp2.find('-')));
    r2[1] = stoi(tmp2.substr(tmp2.find('-')+1, tmp2.length()));
    count += (r1[1]<r2[0] or r2[1]<r1[0]);
    lines++;
  }
  cout << lines - count << endl;
  ifs.close();
  return 0;
}
