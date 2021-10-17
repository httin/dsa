#include <bits/stdc++.h>
#include <memory>

using namespace std;
#define MAX 26

class Trie 
{
public:
	struct Node 
	{
		shared_ptr<struct Node> child[MAX];
		int wordCount;
		int priority;
		
		Node() 
		{
			wordCount = 0;
			priority = 0;
			for (int i = 0; i < MAX; ++i)
			{
				child[i] = nullptr;
			}
		}
	};
	
	
	Trie()
	{
		_root = make_shared<Node>();
	}
	~Trie() {}
	
	void AddWord(shared_ptr<struct Node> root, string s, int prio)
	{
		int ch;
		struct Node* temp = &(*root);
		for (size_t i = 0; i < s.size(); ++i)
		{
			ch = s[i] - 'a';
			if (temp->child[ch] == NULL)
			{
				temp->child[ch] = make_shared<struct Node>();
			}
			temp = &(*temp->child[ch]);
			temp->priority = max(temp->priority, prio);
		}
		temp->wordCount++;
	}
	
	int Find(shared_ptr<struct Node> root, string prefix)
	{
		int ch;
		struct Node* temp = &(*root);
		for (size_t i = 0; i < prefix.size(); ++i)
		{
			ch = prefix[i] - 'a';
			if (temp->child[ch] == NULL)
			{
				return -1;
			}
			temp = &(*temp->child[ch]);
		}
		return temp->priority;
	}
	
public:
	shared_ptr<struct Node> _root = nullptr;
};

int main()
{
	Trie trie;
	
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		int prio;
		cin >> s >> prio;
		trie.AddWord(trie._root, s, prio);
	}
	
	for (int i = 0; i < q; i++)
	{
		string prefix;
		cin >> prefix;
		cout << trie.Find(trie._root, prefix) << endl;
	}
	
	return 0;
}

