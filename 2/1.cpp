/*
Leonardo Mascelli.
Advent of Code 2022 day 2 pt 1

conversion table for the first pt

A: Rock       X: Rock
B: Paper      Y: Paper
C: Scissor    Z: Scissor

X +1          win:  +6
Y +2          draw: +3
Z +3          loss: +0

so:
for such a few cases the more optimized solution i think it's the direct
mapping of a case to the corresponding result, avoiding this way the parsing,
the conversion and the cases tree.

A X -> 4
B X -> 1
C X -> 7
A Y -> 8
B Y -> 5
C Y -> 2
A Z -> 3
B Z -> 9
C Z -> 6
 */


#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main (int argc, char *argv[])
{
  fstream ifs("input.txt");
  string cur;
  unsigned int tot = 0;
  while (not ifs.eof()){
    getline(ifs, cur);
    if (cur == "A X")
      tot += 4;
    else if (cur == "B X")
      tot += 1;
    else if (cur == "C X")
      tot += 7;
    else if (cur == "A Y")
      tot += 8;
    else if (cur == "B Y")
      tot += 5;
    else if (cur == "C Y")
      tot += 2;
    else if (cur == "A Z")
      tot += 3;
    else if (cur == "B Z")
      tot += 9;
    else if (cur == "C Z")
      tot += 6;
    else
      cout << cur << endl;
  }
  
  cout << "tot: " << tot << endl;
  return 0;
}
