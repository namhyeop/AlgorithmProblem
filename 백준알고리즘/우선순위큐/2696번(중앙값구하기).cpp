#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int arr[10000];

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int cycleValue;
		cin >> cycleValue;

		for (int i = 0; i < cycleValue; i++)
			cin >> arr[i];

		priority_queue<int, vector<int>, less<int>> maxheap;
		priority_queue<int, vector<int>, greater<int>> minheap;
		vector<int> tmp;
		
		for (int j = 1; j <= cycleValue; j++)
		{
			if (maxheap.size() == minheap.size())
				maxheap.push(arr[j-1]);
			else
				minheap.push(arr[j-1]);

			if (!minheap.empty() && !maxheap.empty() && minheap.top() < maxheap.top())
			{
				int a = maxheap.top();
				int b = minheap.top();
				maxheap.pop();
				minheap.pop();
				maxheap.push(b);
				minheap.push(a);
			}
			
			if (j % 2 == 1)
				tmp.push_back(maxheap.top());
		}

		int maxheapSize = maxheap.size();
		cout << maxheap.size() << "\n";

		int k = 0;
		int count = 0;
		int tmpSizeValue = tmp.size();
		while (tmpSizeValue)
		{
			cout << tmp[k] << " ";
			count++;
			k++;
			tmpSizeValue--;
			if (count % 10 == 0)
				cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
