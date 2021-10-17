#include <bits/stdc++.h>

using namespace std;

int main()
{
	while (true) 
	{
		int n;
		cin >> n;	
		if (n == 0)
			break;
		
		stack<int> s1;
		stack<int> s2;
		vector<int> v;
		bool success = true;
		#include <bits/stdc++.h>

using namespace std;

int main()
{
	while (true) 
	{
		int n;
		cin >> n;	
		if (n == 0)
			break;
		
		stack<int> s;
		queue<int> q;
		vector<int> v;
		bool success = true;
		
		for (int i = 0; i < n; i++) {
			int j;
			cin >> j;
			v.push_back(j);
		}
		
		for (int i = 0; i < n - 1; ++i) {
			if (v[i] > v[i + 1])
				s.push(v[i]);
			else
				q.push(v[i]);
		}
		q.push(v[n - 1]);
		
		int sSize = s.size();
		for (int i = 0; i < sSize - 1; i++) {
			int j = s.top();
			s.pop();
			if (j > s.top()) {
				success = false;
				break;
			}
		}
		
		int qSize = q.size();
		for (int i = 0; i < qSize - 1; i++) {
			int j = q.front();
			q.pop();
			if (j > q.front()) {
				success = false;
				break;
			}
		}
		
		cout << (success ? "yes" : "no") << endl;
	}		
	return 0;
}

		for (int i = 0; i < n; i++) {
			int j;
			cin >> j;
			v.push_back(j);
		}
		
		for (int i = 0; i < n - 1; ++i) {
			if (v[i] > v[i + 1])
				s1.push(v[i]);
			else
				
		}
		
		int sSize = s1.size();
		for (int i = 0; i < sSize - 1; i++) {
			int j = s1.top();
			s1.pop();
			if (j > s1.top()) {
				success = false;
				break;
			}
		}
		
		cout << (success ? "yes" : "no") << endl;
	}		
	return 0;
}
