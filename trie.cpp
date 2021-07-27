#include "trie.h"

const int characterUsed = 42;

using namespace std;

node::~node(){
    if (elements != nullptr)
        for (int i = 0; i < characterUsed; i++)
            delete elements[i];
    info.clear();
    synonym.clear();
}

node::node() {
    elements = new node * [characterUsed];
    for (int i = 0; i < characterUsed; ++i) elements[i] = 0;
    end = 0;
    info.clear();
    synonym.clear();
}

void insert(node*& root, string word, string FilePath, unsigned long position){
    if (!root) root = new node();
    node* cur = root;
    for (auto c : word) {
        int i = getIndex(c);
        if (i == -1) continue;
        if (!cur->elements[i])
            cur->elements[i] = new node();
        cur = cur->elements[i];
    }
    cur->end = 1;
    if (cur->info.find(FilePath) == cur->info.end()) {
        pos tmp = { position };
        cur->info.emplace(FilePath, tmp);
    }
    else cur->info[FilePath].push_back(position);
}

node* search(node* root, string word){
    if (!root) return 0;
    node* cur = root;
    int l = word.length();
    for (int i = 0; i < l - 1;++i) {
        int k = getIndex(word[i]);
        if (k==-1 || !cur->elements[k]) return 0;
        cur = cur->elements[k];
    }
    int k = getIndex(word[l - 1]);
    return cur->elements[k];
}

void destroy(node*& root){
    if (!root) return;
    for (int i = 0; i < characterUsed; ++i)
        destroy(root->elements[i]);
    delete root;
    root = 0;
}

int getIndex(char c){
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return c - 'a'+10;
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    switch (c)
    {
        case '#': 
            return 37;
            break;

        case '$':
            return 38;
            break;

        case '&':
            return 39;
            break;

        case 27:
            return 40;
            break;

        case '-':
            return 41;
            break;

        default:
            return -1;
    }
}

char getCharacter(int k) {
    if (0 <= k && k <= 9) return k + '0';
    if (10 <= k && k <= 'z' - 'a' + 10) return k - 10 + 'a';
    switch (k)
    {
        case 37:
            return '#';
            break;

        case 38:
            return '$';
            break;

        case 39:
            return '&';
            break;

        case 40:
            return 27;
            break;

        case 41:
            return '-';
            break;

        default:
            return -1;
    }
}
