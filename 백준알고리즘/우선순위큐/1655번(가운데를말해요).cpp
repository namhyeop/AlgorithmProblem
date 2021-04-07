/*
우선순위 큐를 활용한 중간값 문제 알고리즘
1.최대힙의 크기는 최소힙의 크기와 같거나 1개 더 커야 한다.
2.최대힙의 원소는 최소힙의 원소보다 작거나 같아야 한다.

이 규칙을 지키면 최대힙의 top구간이 각 입력값을 받았을 경우의 중간값이 된다.
*/

#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 100001;

int n;
priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (max_heap.empty())
			max_heap.push(num);

		else if (max_heap.size() == min_heap.size())
			max_heap.push(num);
		else
			min_heap.push(num);

		if (!max_heap.empty() && !min_heap.empty() && !(max_heap.top() <= min_heap.top()))
		{
			int a = max_heap.top();
			int b = min_heap.top();

			max_heap.pop();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}
		cout << max_heap.top() << "\n";
	}
	return 0;
}
