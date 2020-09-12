#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char * argv[])
{
	queue<int> q;

	int n;
	cin >> n;

	for (int i = 1; i <= 6; i++)
		q.push(i);

	while (q.size != 1)
	{
		q.pop();
		int tmp = q.front();
		q.push(tmp);
	}

}
