#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 500 + 1;

int N, M;
bool visited[MAX];
bool passed[MAX];
vector<int> tree[MAX];
//DFS를 통해 정점 개수 파악
int numofVertex(int nodeNum)
{
	int count = 1;
	visited[nodeNum] = true;

	for (int i = 0; i < tree[nodeNum].size(); i++)
	{
		int next = tree[nodeNum][i];
		if (!visited[next])
			count += numofVertex(next);
	}
	return count;
}
//DFS를 통해 간선 개수 파악
//정점 입력시 두 번 입력하므로 여기서 구한 개수는 실제의 2배
int numofEdge(int nodeNum)
{
	int count = tree[nodeNum].size();
	passed[nodeNum] = true;

	for (int i = 0; i < tree[nodeNum].size(); i++)
	{
		int next = tree[nodeNum][i];
		if (!passed[next])
			count += numofEdge(next);
	}

	return count;
}
int main(int argc, char*argv[])
{
	int count = 1;

	while (1)
	{
		for (int i = 0; i < MAX; i++)
			tree[i].clear();
		
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < M; i++)
		{
			int node1, node2;
			cin >> node1 >> node2;

			tree[node1].push_back(node2);
			tree[node2].push_back(node1);
		}

		memset(visited, false, sizeof(visited));
		memset(passed, false, sizeof(passed));

		cout << "Case " << count++ << ": ";

		int result = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				int V = numofVertex(i);
				int E = numofEdge(i);
				//트리의 조건
				if (V - 1 == E / 2)
					result++;
			}
		}

		switch (result)
		{
		case 0:
			cout << "No trees. " << "\n";
			break;
		case 1:
			cout << "There is one tree." << "\n";
			break;
		default:
			cout << "A forest of " << result << " trees." << "\n";
			break;
		}
	}
	return 0;
}
