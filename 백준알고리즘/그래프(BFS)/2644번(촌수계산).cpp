#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX = 101;

int P1;
int P2;
vector<int> family[MAX];
int cache[MAX];

int BFS()
{
	queue<int> q;
	q.push(P1);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		
		if (here == P2)
			return cache[P2];
		for (int i = 0; i < family[here].size(); i++)
		{
			int next = family[here][i];
			if (cache[next] == 0)
			{
				q.push(next);
				cache[next] = cache[here] + 1;
			}
		}
	}
	return -1;
}
int main(int argc, char *argv[])
{
	int N;
	int M;
	cin >> N;
	cin >> P1 >> P2;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int node1;
		int node2;
		cin >> node1 >> node2;
		family[node1].push_back(node2);
		family[node2].push_back(node1);
	}
	cout << BFS() << "\n";

	return 0;
}
