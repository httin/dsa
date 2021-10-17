#include <bits/stdc++.h>

using namespace std;
#define MAX 2
#define MAX_WORDLEN 1001

struct word {
	int id;
	int len;
};

bool word_sort(struct word& i, struct word& j) {
	return i.len < j.len;
}

struct Node
{
	struct Node* child[MAX];
	int countWord;
	bool blocked;
	
	Node(int cnt = 0)
	{
		countWord = cnt;
		blocked = false;
		for (int i = 0; i < MAX; i++)
			child[i] = nullptr;
	}
	~Node()
	{
		for (int i = 0; i < MAX; i++)
			if (child[i] != nullptr)
				delete child[i];
	}
	
	bool isFull() {
		for (int i = 0; i < MAX; i++)
			if (child[i] == nullptr)
				return false;
		return true;
	}
};



bool CreateWord(struct Node* root, int len)
{
	struct Node* temp = root;
	if (len == 0) {
		temp->countWord++;
		return true;
	}
	
	for (int i = 0; i < MAX; i++)
	{
		if (temp->child[i] == nullptr) {
			printf("len=%d new-node=%d\n", len, i);
			temp->child[i] = new Node();
			
			if (i == MAX - 1 && len == 1)
				temp->blocked = true;
			return CreateWord(temp->child[i], len - 1);
		} 
		else if (temp->child[i]->countWord == 0 && 
				!temp->child[i]->blocked) 
		{
			printf("len=%d node=%d\n", len, i);
			return CreateWord(temp->child[i], len - 1);
		}
	}
	return false;
}

void PrintWord(char* str, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", str[i]);
	cout << '\n';
}

void PrintTrie(struct Node* root, char* wordArray, int pos = 0)
{
	if (root == nullptr)
		return;
	
	if (root->countWord > 0)
		PrintWord(wordArray, pos);
		
	for (int i = 0; i < MAX; i++)
	{
		if (root->child[i] != nullptr) {
			wordArray[pos] = i;
			PrintTrie(root->child[i], wordArray, pos + 1);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<word> a(n);
	
	bool success = true;
	struct Node* root = new Node();
	for (int i = 0; i < n; ++i) {
		int len;
		cin >> len;
		a[i].len = len;
		a[i].id = i;
	}
	
	std::sort(a.begin(), a.end(), word_sort);
	for (auto i : a)
		cout << i.id << ' ' << i.len << '\n';
	
	for (int i = 0; i < n; ++i) {
		if (!CreateWord(root, a[i].len)) {
			cout << "NO";
			success = false;
			break;
		}
	}
	
	char wordArray[MAX_WORDLEN];
	if (success) {
		cout << "YES\n";
		PrintTrie(root, wordArray);
	}
	
	delete root;
	return 0;
}
