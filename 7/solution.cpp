/*
  Advent of Code day 7
  Mascelli Leonardo

  rules:
  line starting with $ are commands:
  cd X  -> change directory to X if in the current level
  cd .. -> go to the parent directory
  cd /  -> go to the root directory
  ls    -> list files and directory in the form:
             size filename
             dir  dirname
 */

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const char *test =
    R"($ cd /
$ ls
dir a
14848514 b.txt
8504156 c.dat
dir d
$ cd a
$ ls
dir e
29116 f
2557 g
62596 h.lst
$ cd e
$ ls
584 i
$ cd ..
$ cd ..
$ cd d
$ ls
4060174 j
8033020 d.log
5626152 d.ext
7214296 k
)";

struct file {
  string name;
  int size;
};

struct dir {
  string name;
  dir *parent;
  vector<file> files;
  vector<dir*> dirs;
  unsigned int size() {
    unsigned int total = 0;
    for (auto &f : files)
      total += f.size;
    for (auto &d : dirs)
      total += d->size();
    return total;
  }
};

void print_tree(dir* root, int level)
{
  for (int i=0; i<level; i++)
    cout << "  ";
  cout << "dir " << root->name << endl;
    for (int i=0; i<level; i++)
      cout << "  ";
    cout << "total size: " << root->size() << endl;
  for (auto &d: root->dirs) {
    print_tree(d, level+1);
  }
  for (auto &f: root->files){
    for (int i=0; i<level+1; i++)
      cout << "  ";
    cout << f.name << " " << f.size << endl;
  }
}

unsigned int sum_dir_sizes(dir* root, unsigned int max=0){
  unsigned int total = 0;
  if (root->size() <= max)
    total += root->size();
  for (auto d : root->dirs){
    total += sum_dir_sizes(d, max);
  }
  return total;
}
dir* parsed_tree(istream &input){
  dir *root = new dir {"/", nullptr, {}, {}};
  dir *current_dir = root;
  string line;
  while (true) { 
    getline(input, line);
    if (input.eof() or not line.length())
      break;
    if (line.starts_with("$ cd")) {
      if (line.ends_with("..")) {
        if (current_dir->name != "/")
          current_dir = current_dir->parent;
      } else if (line.ends_with("/")) {
        current_dir = root;
      } else {
        // check if there is a directory with name and move into it
        string dir_name = line.substr(5, line.length() - 5);
        auto cd_dir =
            std::find_if(current_dir->dirs.begin(), current_dir->dirs.end(),
                         [&](const auto &in) { return in->name == dir_name; });
        if (cd_dir != current_dir->dirs.end()) {
	  current_dir = *cd_dir;
        }
      }
    } else if (line.starts_with("$ ls")) {
    } else {
      if (line.starts_with("dir ")) {
        string dir_name = line.substr(4, line.length() - 4);
        if (std::find_if(current_dir->dirs.begin(), current_dir->dirs.end(),
                         [&](const auto &in) { return in->name == dir_name; }) ==
            current_dir->dirs.end()){
          // directory does not exists. add it
          current_dir->dirs.push_back(new dir {dir_name, current_dir, {}, {}});
	}
      } else {
        // add file
        unsigned int sep = line.find(" ");
        string file_size = line.substr(0, sep);
        string file_name =
            line.substr(sep + 1, line.length() - sep - 1); // maybe 2
        if (std::find_if(current_dir->files.begin(), current_dir->files.end(),
                         [&](const auto &in) {
                           return in.name == file_name;
                         }) == current_dir->files.end())
          // file does not exists. add it
          current_dir->files.push_back({file_name, stoi(file_size)});
      }
    }
  }
  return root;
}
void p1(istream &input) {
  cout << sum_dir_sizes(parsed_tree(input), 100000) << endl;
}
void find_min(dir* d, unsigned int* min_space, unsigned int to_free_space){
  if (d->size() >= to_free_space and d->size() < *min_space){
    *min_space = d->size();
  }
  for (dir* c: d->dirs) find_min(c, min_space, to_free_space);
}
 void p2(istream &input){
  dir* root = parsed_tree(input);
  unsigned int total_space = 70000000, required_space = 30000000,
    to_free_space = required_space - (total_space - root->size());
  unsigned int min_space = total_space - to_free_space;
  find_min(root, &min_space, to_free_space);
  cout << min_space << endl;
}
int main(int argc, char *argv[]) {
  ifstream ifs("input.txt");
  string test_input(test);
  stringstream test_input_stream(test_input);
  p2(ifs);
  return 0;
}
