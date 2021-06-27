#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 201;
int n, k;
int arr[MAX];
bool visited[MAX];
int main()
{
	fastio;
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++)
		cin >> arr[i];
	
	int level = 0;
	int cnt = 0;
	while (1)
	{
		if (cnt >= k)
			break;
		auto beltrotate = [&]()
		{
			int tmp = arr[2 * n - 1];
			for (int i = 2 * n - 1; i > 0; i--)
				arr[i] = arr[i - 1];
			arr[0] = tmp;

			bool tmp2 = visited[2 * n - 1];
			for (int i = 2 * n - 1; i > 0; i--)
				visited[i] = visited[i - 1];
			visited[0] = tmp2;

			visited[n - 1] = false;
		};

		auto robotrotate = [&]()
		{
			for (int i = n - 2; i >= 0; i--)
			{
				if (!visited[i + 1] && arr[i + 1] > 0 && visited[i])
				{
					visited[i] = false;
					visited[i + 1] = true;
					arr[i + 1] -= 1;
				}
			}
			visited[n - 1] = false;
		};

		auto putrobot = [&]()
		{
			if (arr[0] > 0 && !visited[0])
			{
				arr[0] -= 1;
				visited[0] = true;
			}
		};

		beltrotate();
		robotrotate();
		putrobot();

		int tmpcnt = 0;
		for (int i = 0; i < 2 * n; i++)
			if (arr[i] == 0)
				tmpcnt++;

		cnt = tmpcnt;
		level++;
	}

	cout << level << "\n";
}
/*
#include<bits/stdc++.h>

using namespace std;

deque<int> durability;
deque<bool> conveyer;
int n, k;
int level = 1;

void rotate()
{
	conveyer.push_front(conveyer.back());
	conveyer.pop_back();

	durability.push_front(durability.back());
	durability.pop_back();
	conveyer[n - 1] = false;
}

void move()
{
	for (int i = n - 2; i >= 0; i--)
	{
		if ((!conveyer[i + 1]) && (durability[i + 1] > 0) && (conveyer[i]))
		{
			conveyer[i] = false;
			conveyer[i + 1] = true;
			durability[i + 1]--;
		}
	}
	conveyer[n - 1] = false;	
}

void put_robot()
{
	if (!conveyer[0] && durability[0] > 0)
	{
		conveyer[0] = true;
		durability[0]--;
	}
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++)
	{
		int tmp;
		cin >> tmp;
		durability.push_back(tmp);
		conveyer.push_back(false);
	}

	while (true)
	{
		rotate();
		move();
		put_robot();
		int cnt = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			if (durability[i] == 0)
				cnt++;
		}

		if (cnt >= k)
		{
			cout << level << "\n";
			return 0;
		}
		level++;
	}
	return 0;
}
*/
