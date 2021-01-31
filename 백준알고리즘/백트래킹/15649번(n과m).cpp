#include<iostream>

using namespace std;

int n, m;

bool visited[9];
int arr[9];
void operate(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";

		return ;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			arr[cnt] = i;
			visited[i] = true;
			operate(cnt + 1);
			visited[i] = false;
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	
	operate(0);

	return 0;
}
