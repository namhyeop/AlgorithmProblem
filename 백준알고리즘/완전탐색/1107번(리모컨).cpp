#include<iostream>

using namespace std;

bool brokenNum[10];

int check(int n)
{
	if (n == 0)
	{
		if (brokenNum[0])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	
	int length = 0;

	while (n > 0)
	{
		if (brokenNum[n % 10])
			return 0;
		n = n / 10;
		length += 1;
	}
	return length;
}

int main(int argc, char *argv[])
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		brokenNum[tmp] = true;
	}

	int ret = abs(N - 100); //온전히 +만한 횟수

	for (int i = 0; i <= 1000000; i++)
	{
		int c = i;
		int len = check(c); //len는 숫자를 입력한 횟수 check함수를 통해 부셔진 숫자가 나오면 이동이 불가능한 숫자를 제외해준다.

		if (len > 0)
		{
			int press = abs(c - N); //press는 +한 횟수
			if (ret > press + len)
				ret = press + len;
		}
	}
	cout << ret << "\n";

	return 0;
}
