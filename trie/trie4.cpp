#include <bits/stdc++.h>

using namespace std;
#define MAX 26

struct Node
{
	struct Node* child[MAX];
	int countWord;
	int freq;
	
	Node()
	{
		countWord = 0;
		freq = 1;
		for (int i = 0; i < MAX; i++)
			child[i] = nullptr;
	}
	~Node()
	{
		for (int i = 0; i < MAX; i++)
			if (child[i] != nullptr)
				delete child[i];
	}
};

void AddWord(struct Node* root, string s)
{
	int ch;
	struct Node* temp = root;
	for (size_t i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == nullptr) {
			temp->child[ch] = new Node();
		}
		else {
			temp->child[ch]->freq++;
		}
		temp = temp->child[ch];
	}
	temp->countWord++;
}

int FindContacts(struct Node* root, string s)
{
	int ch;
	struct Node* temp = root;
	for (size_t i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'a';
		if (temp->child[ch] == nullptr) {
			return 0;
		}
		temp = temp->child[ch];
		//cout << (char)s[i] << ' ' << temp->freq << endl;
	}
	return temp->freq;
}

int main()
{
	struct Node* root = new Node();
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string op, s;
		cin >> op >> s;
		
		if (op.compare("add") == 0) {
			AddWord(root, s);
		} 
		else if (op.compare("find") == 0) {
			cout << FindContacts(root, s) << '\n';
		}
	}
	
	delete root;
	return 0;
}
