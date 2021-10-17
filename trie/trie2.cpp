#include <bits/stdc++.h>

using namespace std;
#define MAX 26

struct Node 
{
	struct Node *child[MAX];
	int countSubset;
	
	Node(int count) 
	{
		countSubset = count;
		for (int i = 0; i < MAX; i++)
		{
			child[i] = nullptr;
		}
	}
	
	~Node()
	{
		for (int i = 0; i < MAX; i++)
		{
			if (child[i] != nullptr)
				delete child[i];
		}		
	}
};

void AddWord(struct Node* root, string& s)
{
	int ch;
	struct Node* temp = root;
	for (size_t i = 0; i < s.size(); i++)
	{
		ch = s[i] - 'A';
		if (temp->child[ch] == nullptr)
		{
			temp->child[ch] = new Node(1);
		}
		else
		{
			temp->child[ch]->countSubset++;
		}
		temp = temp->child[ch];
	}
}

void FindBestPrefix(struct Node* root, int level, int& res)
{
	struct Node* temp = root;
	for (int i = 0; i < MAX; i++)
	{
		if (temp->child[i] != nullptr)
		{
			struct Node* walker = temp->child[i];
			res = max(res, walker->countSubset * level);
			FindBestPrefix(walker, level + 1, res);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		struct Node* root = new Node(0);
		int res = 0;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			string s;
			cin >> s;
			AddWord(root, s);
		}
		
		FindBestPrefix(root, 1, res);
		cout << "Case " << i << ": "<<  res << '\n';
		delete root;
	}
	
	return 0;
}
