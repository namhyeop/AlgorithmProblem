#include<iostream>
#include<string>
#include<queue>
#include<string.h>

using namespace std;
#define MAX 10000

int A;
int B;
bool visited[MAX];

string BFS()
{
	queue<pair<int, string>> q;
	q.push(make_pair(A, ""));
	visited[A] = true;

	while (!q.empty())
	{
		int num = q.front().first;
		string prev = q.front().second;
		q.pop();

		if (num == B)
			return prev;

		int curNum = (2 * num) % MAX;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, prev + 'D'));
		}

		curNum = (num - 1 < 0) ? 9999 : num - 1;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, prev + 'S'));
		}

		curNum = (num % 1000) * 10 + num / 1000;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, prev + 'L'));
		}

		curNum = (num % 10) * 1000 + num / 10;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, prev + 'R'));
		}
	}
}
int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> A >> B;
		memset(visited, false, sizeof(visited));
		
		cout << BFS() << "\n";
	}
	return 0;
}
