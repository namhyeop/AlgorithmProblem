/*
문제를 이해하기 어려웠던 문제
첫 번째 예제 입력으로 예시를 들면
입력의 관계가 지금 누가 부모이고 자식인지 모른다.
그런데
1번째 줄의 1은 루트이기 때문에 1이 6의 자식이 되는것은 불가능하다. 그래서 6이 1의 자식이 되는게 맞기 때문에 parent 6자리에 1이 입력된다.
2번째줄은 위에서 6은 1의 자식이기 때문에 3은 6의 자식이 되어야 한다.
3번째줄은 3은 6의 자식이기 때문에 5는 3의 부모가 되는게 맞다.
이런식으로 문제를 접근해야 한다.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> Tree[100001];
bool Entrance[100001];
int parent[100001];

void operate(int node)
{
	Entrance[node] = true;

	for (int i = 0; i < Tree[node].size(); i++)
	{
		int next = Tree[node][i];

		if (!Entrance[next])
		{
			parent[next] = node;
			operate(next);
		}
	}
}

int main(int argc, char *argv[])
{
	int testNode;
	cin >> testNode;

	for (int i = 0; i < testNode - 1; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		Tree[tmp1].push_back(tmp2);
		Tree[tmp2].push_back(tmp1);
	}

	operate(1);

	for (int i = 2; i <= testNode; i++)
		cout << parent[i] << '\n';

	return 0;
}
