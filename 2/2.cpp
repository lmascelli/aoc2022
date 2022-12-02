/*
Leonardo Mascelli.
Advent of Code 2022 day 2 pt 1

conversion table for the second pt

A: Rock       X: Lose
B: Paper      Y: Draw
C: Scissor    Z: Win

Rock:     +1          win:  Z -> +6 
Paper:    +2          draw: Y -> +3 
Scissor:  +3          loss: X -> +0 

so:
for such a few cases the more optimized solution i think it's the direct
mapping of a case to the corresponding result, avoiding this way the parsing,
the conversion and the cases tree.

A X -> 3
B X -> 1
C X -> 2
A Y -> 4
B Y -> 5
C Y -> 6
A Z -> 8
B Z -> 9
C Z -> 7
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
      tot += 3;
    else if (cur == "B X")
      tot += 1;
    else if (cur == "C X")
      tot += 2;
    else if (cur == "A Y")
      tot += 4;
    else if (cur == "B Y")
      tot += 5;
    else if (cur == "C Y")
      tot += 6;
    else if (cur == "A Z")
      tot += 8;
    else if (cur == "B Z")
      tot += 9;
    else if (cur == "C Z")
      tot += 7;
    else
      cout << cur << endl;
  }
  
  cout << "tot: " << tot << endl;
  return 0;
}
