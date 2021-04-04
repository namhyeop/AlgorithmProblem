#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1000000;

vector<int> primeV;
bool visited[MAX + 1];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	visited[1] = true;
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (!visited[i])
		{
			for (int j = i * i; j <= MAX; j += i)
				visited[j] = true;
		}
	}

	while (1)
	{
		int num;
		cin >> num;

		bool failFlag = false;
		if (num == 0)
			break;

		for (int i = 3; i <= num; i += 2)
		{
			if (!visited[i] && !visited[num - i])
			{
				cout << num << " = " << i << " + " << num - i << "\n";
				failFlag = true;
				break;
			}
		}
		if (failFlag == false)
			cout << "Goldbach's conjecture is wrong." << "\n";
	}

	return 0;
}
