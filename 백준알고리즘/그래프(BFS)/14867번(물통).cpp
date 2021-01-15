#include<iostream>
#include<queue>
#include<map>

using namespace std;
int A;
int B;
int endA;
int endB;

map<pair<int, int>, int> visited;

int BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[{0, 0}] = 0;

	while (!q.empty())
	{
		int curA = q.front().first;
		int curB = q.front().second;
		int cnt = visited[{curA, curB}];
		q.pop();

		if (curA == endA && curB == endB)
			return cnt;

		//물통을 Fill할 경우
		//A를 Fill 할 경우
		if (visited.count({ A, curB }) == 0)
		{
			q.push({ A, curB });
			visited[{A, curB}] = cnt + 1;
		}
		//B를 Fill 할 경우
		if (visited.count({ curA, B }) == 0)
		{
			q.push({ curA, B });
			visited[{ curA, B }] = cnt + 1;
		}
		//물통을 Empty할 경우
		//A를 비울 경우
		if (visited.count({ 0, curB }) == 0)
		{
			q.push({ 0, curB });
			visited[{0, curB}] = cnt + 1;
		}
		//B를 비울 경우
		if (visited.count({curA, 0}) == 0)
		{
			q.push({ curA, 0 });
			visited[{curA, 0}] = cnt + 1;
		}
		int changeA;
		int changeB;
		if (curA > B - curB)
		{
			changeA = curA + curB - B;
			changeB = B;
		}
		else
		{
			changeA = 0;
			changeB = curA + curB;
		}
		if (visited.count({ changeA, changeB }) == 0)
		{
			q.push({ changeA, changeB });
			visited[{changeA, changeB}] = cnt + 1;
		}

		if (curB > A - curA)
		{
			changeA = A;
			changeB = curB + curA - A;
		}
		else
		{
			changeA = curA + curB;
			changeB = 0;
		}
		if (visited.count({changeA, changeB}) == 0)
		{
			q.push({ changeA, changeB });
			visited[{changeA, changeB}] = cnt + 1;
		}
	}
	return -1;
}
int main(int argc, char *argv[])
{
	cin >> A >> B >> endA >> endB;

	cout << BFS() << "\n";
	
	return 0;
}
