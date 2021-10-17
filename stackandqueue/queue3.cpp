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
		
		queue<int> discard;
		queue<int> deck;
		for (int i = 1; i <= n; ++i)
			deck.push(i);
		
		while (deck.size() > 1) 
		{
			int d = deck.front();
			deck.pop();
			discard.push(d);
			d = deck.front();
			deck.pop();
			deck.push(d);
		}
		
		cout << "Discarded cards:";
		if (!discard.empty()) {
			cout << " " << discard.front();
			discard.pop();
		}
		while(!discard.empty()) {
			cout << ", " << discard.front();
			discard.pop();
		}
		cout << "\nRemaining card: " << deck.front() << "\n";
	}
	return 0;
}
