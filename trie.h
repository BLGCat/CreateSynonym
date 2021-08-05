// Tất cả các compile file đều include trie.h
// bất kỳ file .h nào mới đuợc tạo ra cần đợc include dưới Sub-prototype

// Library
#ifndef _TRIE_H_
#define _TRIE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <filesystem>

// Sub-prototype
//#include "159.h"
//#include "utils.h"


#define pos vector<unsigned long>

using namespace std;

const string fileList = "Search Engine-Data/___index.txt";

// Global variable
struct node {
    node();
    node** elements = nullptr;
    // '0'->'9': 0->9
    // 'a'/'A'->'z'/'Z': 10->36
    // '#': 37
    // '$': 38
    // '&': 39
    // char 27 ' :40
    // '-': 41
    bool end = false;
    map<string, pos> info;
    // frequent: pos.size()
    unordered_set<string> synonym;
    ~node();
};

void insert(node*& root, string word, string FilePath, unsigned long position);
node* search(node* root, string word);
void destroy(node*& root);
int getIndex(char c);
char getCharacter(int k);

#endif // !_TRIE_H_
