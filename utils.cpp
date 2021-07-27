#include "utils.h"

using namespace std;
namespace fs = std::filesystem;

const int characterUsed = 42;

vector<string> getAllFileName(string folder) {
	vector<string> FileName;
	FileName.clear();
	string path = folder;
	for (const auto& entry : fs::directory_iterator(path)) {
		FileName.push_back(entry.path().u8string());
	}
	return FileName;
}

void printFilePath(string file, vector<string> filePath) {
	ofstream f;
	f.open(file);
	for (auto i : filePath)
		f << i << "\n";
	f.close();
}

node* createTree(vector<string> FilePath){
	node* root = 0;
	for (auto file : FilePath) {
		ifstream f;
		f.open(file);
		if (f.is_open()) {
			unsigned long position = 0;
			while (!f.eof()) {
				string word;
				f >> word;
				insert(root, word, file, position++);
			}
		}
		f.close();
	}
	return root;
}

void printAllWords(ofstream& f, node* root, string word) {
	if (!root) return;
	if (root->end) f << word << "\n";
	for (int i=0;i<characterUsed;++i)
		if (root->elements[i]) {
			printAllWords(f, root->elements[i], word + getCharacter(i));
		}
}
