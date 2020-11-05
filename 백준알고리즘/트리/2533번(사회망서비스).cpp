#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1000001;

vector<int> friendsinfo[MAX];
vector<int> dirNode[MAX];
bool visited[MAX];
int cache[MAX][2];

void DFS(int nodeNum)
{
	visited[nodeNum] = true;

	for (int i = 0; i < friendsinfo[nodeNum].size(); i++)
	{
		int nextNode = friendsinfo[nodeNum][i];

		if (!visited[nextNode])
		{
			dirNode[nodeNum].push_back(nextNode);
			DFS(nextNode);
		}
	}
}

int decisionEarlyAdapter(int nodeNum, bool EA)
{
	int &result = cache[nodeNum][EA];

	if (result != -1)
		return result;

	//얼리어댑터일 경우 다음 경우가 ture여도 되고 false여도 된다.
	if (EA)
	{
		result = 1; //얼리어뎁터일 경우
		for (int i = 0; i < dirNode[nodeNum].size(); i++)
		{
			int nextNode = dirNode[nodeNum][i];
			result += min(decisionEarlyAdapter(nextNode, true), decisionEarlyAdapter(nextNode, false));
		}
	}
	//본인이 얼리어댑터가 아니면 자식은 무조건 얼리어댑터여야 한다.
	else
	{
		result = 0;
		for (int i = 0; i < dirNode[nodeNum].size(); i++)
		{
			int nextNode = dirNode[nodeNum][i];
			result += decisionEarlyAdapter(nextNode, true);
		}
	}
	return result;
}
int main(int argc, char * argv[])
{
	int nodeNum;
	cin >> nodeNum;

	for (int i = 0; i < nodeNum - 1; i++)
	{
		int parent;
		int child;
		cin >> parent >> child;

		friendsinfo[parent].push_back(child);
		friendsinfo[child].push_back(parent);
	}

	memset(cache, -1, sizeof(cache));

	DFS(1);

	cout << min(decisionEarlyAdapter(1, true), decisionEarlyAdapter(1, false)) << '\n';
	return 0;
}
