#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	std::set<long long> prices{};
	long long res = 1e16;
	for (int i = 0; i < n; i++)
	{
		long long price;
		cin >> price;
	
		auto it = prices.upper_bound(price);
		if (it != prices.end())
			res = std::min(res, *it - price);
		prices.insert(price);
	}
	
	cout << res << endl;
	return 0;
}
