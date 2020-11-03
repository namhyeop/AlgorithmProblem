#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 10001;
const int INF = 987654321;

int nodeSize;
int nodeidx;//노드의 너비 위치 값

int node[MAX]; //루트를 찾기 위한 배열, 가장 작은게 부모
int low[MAX]; //레벨에서 가장 작은 위치 값을 저장한 배열
int high[MAX] = {0,};//레벨에서 가장 큰 위치 값을 저장한 배열
pair<int, int> tree[MAX];

//중위 순회 구조
void DFS(int nodeNum, int cnt)//cnt는 레벨, nodeidx는 위치 값
{
	if (tree[nodeNum].first > 0)
		DFS(tree[nodeNum].first, cnt + 1);

	//Visit
	low[cnt] = min(low[cnt], nodeidx);
	high[cnt] = max(high[cnt], nodeidx++);

	//right subTree
	if (tree[nodeNum].second > 0)
		DFS(tree[nodeNum].second, cnt + 1);
}
int main(int argc, char * argv[])
{
	cin >> nodeSize;

	for (int i = 0; i < MAX; i++)// 최소값을 찾아야 하기에 전부 큰 값으로 초기화
		low[i] = INF;

	for (int i = 0; i < nodeSize; i++)
	{
		int parent;
		int child1;
		int child2;

		cin >> parent >> child1 >> child2;

		node[parent]++;

		if (child1 != -1)
			node[child1]++;
		tree[parent].first = child1;
		if (child2 != -1)
			node[child2]++;
		tree[parent].second = child2;
	}

	//count한 갯수가 1개인 노드가 루트이다
	int root;
	for (int i = 1; i <= nodeSize; i++)
	if (node[i] == 1)
		root = i;

	//DFS
	nodeidx = 1;
	DFS(root, 1);

	//최대 길이를 구한다.
	int result = high[1] - low[1] + 1;
	int level = 1;
	for (int i = 2; i <= nodeSize; i++)
	{
		int tmp = high[i] - low[i] + 1;
		if (tmp > result)
		{
			result = tmp;
			level = i;
		}
	}
	cout << level << " " << result << "\n";
}
