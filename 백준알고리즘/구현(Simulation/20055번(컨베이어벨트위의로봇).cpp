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
