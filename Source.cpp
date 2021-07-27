#include "trie.h"
#include "utils.h"

using namespace std;

void printSynonyms(node* root, ifstream& f) {
	string word;
	f >> word;
	ofstream out;
	out.open(word + ".txt");
	while (!f.eof()) {
		string synonym;
		f >> synonym;
		node* Node = search(root, synonym);
		if (Node && Node->end)
			out << synonym << "\n";
	}
	out.close();
}

int main() {
	string folder = "Search Engine-Data/";
	//vector<string> FilePath = getAllFileName(folder);
	vector<string> FilePath = {"words.txt" };
	node* root = createTree(FilePath);

	ifstream f;
	f.open("synonym.txt");
	printSynonyms(root,f);
	f.close();
	/*ofstream f;
	f.open("words.txt");
	printAllWords(f, root, "");
	f.close();*/
	//node *info = search(root, "100000four");
	/*for (auto i : info) {
		cout << i.first << "\n";
		for (auto j : i.second)
			cout << j << " ";
	}*/

	destroy(root);
	return 0;
}