#include <bits/stdc++.h>

using namespace std;

#define MAX 105
#define INF 1e9

struct Freckle {
	int id;
	double x, y;
	Freckle(int _id, double _x, double _y) :
		id(_id), x(_x), y(_y) {}
};

double f(Freckle& a, Freckle& b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

using Node = pair<int, double>;
struct comp {
	bool operator() (const Node& a, const Node& b) const {
		return a.second > b.second;
	}
};

int N;
double grid[MAX][MAX];
double mst(int s)
{
	vector<bool> visited(N + 1, false);
	vector<double> dist(N + 1, INF);
	priority_queue<Node, vector<Node>, comp> pq;
	pq.push(Node(s, 0));
	dist[s] = 0;
	
	while (!pq.empty())
	{
		Node top = pq.top();
		pq.pop();
		visited[top.first] = true;
		for (int i = 1; i <= N; ++i)
		{
			double w = grid[top.first][i];
			if (!visited[i] && dist[i] > w)
			{
				dist[i] = w;
				pq.push(Node(i, w));
			}
		}
	}
	
	double res = 0;
	for (int i = 1; i <= N; ++i)
		res += dist[i];
	return res;
}

int main()
{
	int T;
	cin >> T;
	string blank;
	while (T--)
	{
		std::getline(cin, blank);
		scanf("%d", &N);
		vector<Freckle> Freckles;
		for (int i = 1; i <= N; ++i) {
			double x,y;
			scanf("%lf %lf", &x, &y);
			Freckles.push_back(Freckle(i, x, y));
		}
		
		for (auto& src : Freckles) {
			for (auto& dst : Freckles) {
				if (dst.id != src.id) {
					grid[dst.id][src.id] = grid[src.id][dst.id] = f(src, dst);
				}
				else {
					grid[src.id][dst.id] = 0;
				}
			}
		}
		
		auto ans = mst(1);
		printf("%.2lf\n\n", ans);
	}

	return 0;
}

