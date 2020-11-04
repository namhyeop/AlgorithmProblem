#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int MAX = 10000 + 1;
bool Entrance[MAX]; //트리 생성시 중복을 제거하기 위해 존재하는 행렬

int ret = 0; //지름을 나타내는 변수
int farthestNode;// 가장 멀리있는 Node를 의미, 가장 먼 노드에서 측정해야 루트노드를 안 거치는 경우에도 가장 멀리있는 노드를 측정 할 수 있다.

int Testcase;
vector<pair<int, int>> graph[MAX]; //트리를 위한 vector변수

void operateDFS(int node, int cost)
{
	if (Entrance[node]) //측정한 경우 함수를 돌리지 않는다.
		return;

	Entrance[node] = true; //출입 경험이 있을 경우 체크

	if (ret < cost) //가장 멀리 있는 변수를 확인 하기위한 조건
	{
		ret = cost;
		farthestNode = node;
	}
	for (int i = 0; i < graph[node].size(); i++) //밑에서 DFS를 1회 돌릴시에는 가장 멀리 있는 노드를 찾고 그 노드를 찾은 뒤에 그 노드 기준 cost를 측정하면 가장 멀리있는 가중치값이다.
		operateDFS(graph[node][i].first, cost + graph[node][i].second);
}
int main(int argc, char * argv[])
{
	cin >> Testcase;

	for (int i = 0; i < Testcase - 1; i++)
	{
		int parentNode;
		int childNode;
		int weight;

		cin >> parentNode >> childNode >> weight;

		graph[parentNode].push_back(make_pair(childNode, weight));
		graph[childNode].push_back(make_pair(parentNode, weight));
	}
	memset(Entrance, false, sizeof(Entrance));

	operateDFS(1, 0);

	ret = 0;
	memset(Entrance, false, sizeof(Entrance));
	
	operateDFS(farthestNode, 0);

	cout << ret << '\n';

	return 0;
}
