#include <bits/stdc++.h>

using namespace std;

#define MAX 10005
vector<int> graph[MAX];
bool visited[MAX] = {false};

int dfs(int s)
{
	int ret = 0;
	stack<int> _stack;
	_stack.push(s);
	memset(visited, false, sizeof(visited));
	visited[s] = true;
	
	while (!_stack.empty())
	{
		int u = _stack.top();
		_stack.pop();
		++ret;
		for (auto v : graph[u])
		{
			if (!visited[v]) 
			{
				visited[v] = true;
				_stack.push(v);
			}
		}
	}
	return ret;
}

int main()
{
	int V, E;
	cin >> V >> E;
	
	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	
	int res = 0;
	for (int i = 1; i <= V; ++i)
	{
		res = max(res, dfs(i));
	}
	
	cout << res << endl;
	return 0;
}
