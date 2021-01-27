#include<iostream>

using namespace std;

int num[4] = { 1, 5, 10, 50 };
int visit[10000];
int N;
int ret;

void operate(int validNum, int number, int idx)
{
	if (validNum == N)
	{
		//cout << "end "<< validNum << " " << number << " " << idx << "\n";
		if (visit[number])
			return;
		visit[number] = 1;
		ret++;
		return;
	}

	//cout << validNum << " " << number << " " << idx << "\n";

	for (int i = idx; i < 4; i++)
		operate(validNum +1, number + num[i], i);
}
int main(int argc, char *argv[])
{
	cin >> N;
	operate(0, 0, 0);
	cout << ret;

	return 0;
}
