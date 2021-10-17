#include <bits/stdc++.h>

using namespace std;

bool isOperation(char ch)
{
	return (ch == '+') || (ch == '-') || (ch == '*') \
			|| (ch == '/') || (ch == '^');
}

int main()
{
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
		std::stack<char> ops;
		std::string expression;
		cin >> expression;
		
		string res = "";
		for (size_t i = 0; i < expression.size(); i++)
		{
			if (isOperation(expression[i]))
				ops.push(expression[i]);
			else if (expression[i] == '(')
				continue;
			else if (expression[i] == ')') {
				res.push_back(ops.top());
				ops.pop();
			}
			else
				res.push_back((char)expression[i]);
		} 
		cout << res << '\n';
	}
	return 0;
}
