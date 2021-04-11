#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int Testcase;
bool visited[101];

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int Testcase;
	cin >> Testcase;
	
	for (int i = 0; i < Testcase; i++)
	{
		int n, k;
		cin >> n >> k;
		int arr[101];
		memset(visited, false, sizeof(visited));
		if (k == 0)
		{
			for (int i = 0; i < n; i++)
				arr[i] = i + 1;
			print(arr, n);
		}
		else if (n == 1)
		{
			if (k)
				cout << -1 << "\n";
			else
				cout << 1 << "\n";
		}
		else if (n == 2)
		{
			if (k)
				cout << -1 << "\n";
			else
				cout << "1 2" << "\n";
		}
		else if (n == 3)
		{
			if (k == 1)
				cout << "1 3 2" << "\n";
			else if (k == 0)
				cout << "1 2 3" << "\n";
			else
				cout << -1 << "\n";
		}
		else if (k > (n - 1) / 2)
			cout <<  -1 << "\n";
		else
		{
			int i= 1, j= n;
			while (i < n)
			{
				arr[i] = j;
				visited[i] = true;
				i += 2;
				j--;

				if (n - j == k) 
					break;
			}

			for (int i = 0,k= 1; i < n; i++)
			{
				if (!visited[i])
				{
					arr[i] = k;
					k++;
				}
			}
			print(arr, n);
		}
	}
	return 0;
}
