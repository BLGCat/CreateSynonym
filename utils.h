#ifndef _UTILS_H_

#define _UTILS_H_
#include "trie.h"

using namespace std;

vector<string> getAllFileName(string folder);
void printFilePath(string file, vector<string> filePath);
node* createTree(vector<string>FilePath);
void printAllWords(ofstream& f, node* root, string word);

#endif // !_UTILS_H_
