#include<iostream>
#include<queue>
#include<functional>
#include<vector>

using namespace std;

//이 방식은 메모리제한의 규칙을 넘겨서 메모리 초과 오류가 발생
//그래서 중간에 메모리를 덜 사용하는 방식을 사용해야 한다.
/*
int main(int argc, char *argv[])
{
	int inputSize;
	cin >> inputSize;

	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 0; i < inputSize * inputSize; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	for (int j = 0; j < inputSize - 1; j++)
		pq.pop();

	cout << pq.top() << "\n";

	return 0;
}
*/

int main(int argc, char *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int inputSize;
	cin >> inputSize;

	priority_queue<int, vector<int>, greater<int>>pq;
	for (int j = 0; j < inputSize; j++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	for (int i = 0; i < inputSize-1; i++)
	for (int j = 0; j < inputSize; j++)
	{
		int tmp;
		cin >> tmp;
			
		if (pq.top() < tmp)
		{
			pq.pop();
			pq.push(tmp);
		}
	}

	cout << pq.top() << "\n";

	return 0;
}
