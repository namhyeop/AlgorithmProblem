#include<iostream>
#include<vector>
#include<string>
#define MAX 101

using namespace std;

int order[MAX];
int plugState[MAX];

int main(int argc, char *argv[])
{
	int n,k;
	int result = 0;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
		cin >> order[i];


	for (int i = 0; i < k; i++)
	{
		bool pluggedIn = false;

		//기기가 이미 꽂혀있는지 확인하고 만약 꽂현있다면 continue;
		for (int j = 0; j < n; j++)
			if (plugState[j] == order[i])
			{
				pluggedIn = true;
				break;
			}
			if (pluggedIn)
				continue;

		//콘센트에 자리가 아직 있다면 일단 꽂는다.
			for (int j = 0; j < n; j++)
			if (!plugState[j])
			{
				plugState[j] = order[i];
				pluggedIn = true;
				break;
			}
			if (pluggedIn)
				continue;
		
		//44줄 까지 왔다는건 이제 꽂혀있는 콘센트중 무엇을 바꿔 주어야 하는지 정해야 하는 상태
		//그 중에서 이후에 가장 늦게 쓰여지는것을 바꿔줄것이다.
		int idx, deviceIdx = -1;
		for (int j = 0; j < n; j++)
		{
			int lastIdx = 0;
			for (int l = i + 1; l < k; l++)
			{
				if (plugState[j] == order[l])
					break;
				//cout << "lastIdx"<<lastIdx << "\n";
				lastIdx++;
			}

			if (lastIdx > deviceIdx)
			{
				idx = j;
				deviceIdx = lastIdx;
			}
		}
		result++;
		plugState[idx] = order[i];
	}

	cout << result << "\n";
	return 0;
}
