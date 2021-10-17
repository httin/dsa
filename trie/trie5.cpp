#include <bits/stdc++.h>

using namespace std;
#define MAX 26

struct Node
{
	struct Node* child[MAX];
	
	Node()
	{
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

void CreateWord(struct Node* root, string word, long long& size)
{
	int ch;
	struct Node* temp = root;
	for (size_t i = 0; i < word.size(); i++)
	{
		ch = word[i] - 'a';
		if (temp->child[ch] == nullptr) {
      ++size;
			temp->child[ch] = new Node();
		}
		temp = temp->child[ch];
	}
}

void traverse(struct Node* root, long long* dict, int level = 0)
{
  struct Node* temp = root;
  for (size_t i = 0; i < MAX; ++i)
  {
    if (temp->child[i] != nullptr) {
      traverse(temp->child[i], dict, level + 1);
      
      if (level > 0) {
        dict[i]++;
      }
    }
  }
}

int main()
{
	while (true)
	{
		int P, S;
		cin >> P >> S;
		if (P == 0 && S == 0)
			break;
    long long p_size = 0, s_size = 0;
		struct Node* p_root = new Node();
		struct Node* s_root = new Node();
    long long p[MAX] = { 0 }; // p(x): number of prefix end of 'x'
    long long s[MAX] = { 0 }; // s(x): number of suffix start of 'x'
		
		for (int i = 0; i < P; i++) {
			string str;
			cin >> str;
			CreateWord(p_root, str, p_size);
		}
		for (int i = 0; i < S; i++) {
			string str;
			cin >> str;
			std::reverse(str.begin(), str.end());
			CreateWord(s_root, str, s_size);
		}
		
    traverse(p_root, p);
    traverse(s_root, s);
    
    long long res = p_size * s_size;
    for (int i = 0; i < MAX; i++) {
      // cout << p[i] << ' ' << s[i] << endl;
      res -= p[i]*s[i];
    }
    cout << res << '\n';
		delete p_root;
		delete s_root;
	}
	return 0;
}
