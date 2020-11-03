#include<iostream>
#include<vector>

using namespace std;

struct island
{
	int value;
	vector<int> next;
};

island tree[123457];

long long dfs(int cur)
{
	long long ret;
	ret = tree[cur].value;
	for (int next : tree[cur].next)
		ret += dfs(next);
	if (ret < 0LL)//음수일경우 양이 다 잡아먹혔기 때문에 0을 반환
		ret = 0LL;
	return ret;
}

int main(int argc, char *argv[])
{
	int islandNum;
	char ws;
	int animalSize;
	int parent;

	cin >> islandNum;
	for (int i = 2; i <= islandNum; i++)
	{
		cin >> ws >> animalSize >> parent;
		tree[i].value = (ws == 'W' ? -animalSize : animalSize); //W면 늑대이기 때문에 -값을 S면 양이기 때문에 양수 값을
		tree[parent].next.push_back(i);
	}
	tree[1].value = 0;
	cout << dfs(1) << endl;
	return 0;
}
