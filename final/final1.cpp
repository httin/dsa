#include <bits/stdc++.h>

using namespace std;
#define MAX 2005
using ii = pair<int, int>;

int main()
{
	int N;
	cin >> N;
	vector<ii> a(N);
	vector<int> res[3];
	for(int i = 0; i < N; ++i) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	
	for (int i = 0; i < 3; ++i) {
		res[i] = vector<int>(N);
	}
	
	int c = 0;
	for (int i = 0; i + 1 < N; i++)
    {
        if (a[i].first == a[i + 1].first)
			c++;
        if (c == 2)
        {
            cout << "YES" << endl;
            for (int j = 0; j < N; j++) 
				cout << a[j].second << " ";
            cout << endl;
            c = 0;
            for (int j = 0; j + 1 < N; j++)
            {
                if (a[j].first == a[j + 1].first)
                {
                    c++;
                    swap(a[j].second, a[j + 1].second);
                    for (int k = 0; k < N; k++)
						cout << a[k].second << " ";
                    cout << endl;
                    swap(a[j].second, a[j + 1].second);
                }
                if (c == 2) 
					return 0;
            }
        }
	}
	cout << "NO" << endl;
	return 0;
}


