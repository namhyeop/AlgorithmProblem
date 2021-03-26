#include<bits/stdc++.h>

using namespace std;

int cache[2][100001];
int arr[2][100001];
int Testcase;
int main()
{
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int width;
		cin >> width;
		int maxValue;

		for (int i = 0; i < 2; i++)
		for (int j = 0; j < width; j++)
			cin >> arr[i][j];
		
		cache[0][0] = arr[0][0];
		cache[1][0] = arr[1][0];
		cache[0][1] = arr[0][1] + cache[1][0];
		cache[1][1] = arr[1][1] + cache[0][0];
		
		for (int i = 2; i < width; i++)
		{
			cache[0][i] = arr[0][i] + max(cache[1][i - 1], cache[1][i -2]);
			cache[1][i] = arr[1][i] + max(cache[0][i - 1], cache[0][i - 2]);
		}

		cout << max(cache[0][width -1], cache[1][width - 1]) << '\n';
	}
}
/*
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int input[2][100000];
int cache[3][100001];

//case == 0인경우 아무것도 안 뗀경우
//case == 1인경우 열의 위에껄 뗀경우
//case == 2인경우 열의 아래껄 뗀경우

int search(int x, int Case)//루트노드 기준으로 자식이 3개인 구조의 그림의 트리가 형성
{
	if (x == n)
		return 0;
	int &ret = cache[Case][x];
	if (ret != -1)
		return ret;
	
	ret = search(x + 1, 0);
	
	if (Case != 1) 
		ret = max(ret, search(x + 1, 1) + input[0][x]);
	if (Case != 2) 
		ret = max(ret, search(x + 1, 2) + input[1][x]);

	return ret;

}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> n;

		for (int i = 0; i < 3; i++)
		for (int j = 0; j < 100001; j++)
			cache[i][j] = -1;

		for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> input[i][j];

		cout << search(0,0)<< endl;
	}

	return 0;
}
*/
