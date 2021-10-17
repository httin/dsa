#include <bits/stdc++.h>

using namespace std;
#define eps 1e-6
#define MAX 105
struct Edge {
	int u;
	int v;
	double p;
	Edge(int _u, int _v, double _p) : u(_u), v(_v), p(_p) {}
};
vector<Edge> graph;
double prob[MAX];
int n,m;

void BellmanFord(int s)
{
	prob[s] = 1;
	for (int i = 1; i <= n - 1; ++i) {
		for (auto& e : graph) {
			if (prob[e.u] > 0 && prob[e.v] < e.p * prob[e.u])
				prob[e.v] = e.p * prob[e.u];
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		int a,b,p;
		graph.clear();
		for (int i = 0; i <= n; i++) {
			prob[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d",&a,&b,&p);
			graph.push_back(Edge(a,b,(double)p/100));
			graph.push_back(Edge(b,a,(double)p/100));
		}
		
		BellmanFord(1);
		//for (int i = 1; i <= n; ++i)
			//printf("%.6lf ", prob[i]);
		printf("%.6lf percent\n", prob[n]*100);
	}
	
	return 0;
}
