#include<iostream>
#define MAX 100000
using namespace std;

int gates[MAX + 1];
int gate;
int planeNum;
int gi;
int ret;

int do_find(int x)
{
	if (x == gates[x])
		return gates[x];
	else
		return gates[x] = do_find(gates[x]); //실질적으로 여기서 다 0으로 만들어줌
}

void do_union(int a, int b)//이 과정에서 루트로 다 묶어준다.
{
	int x = do_find(a);
	int y = do_find(b);

	gates[x] = y;
}

int main(int argc, char *argv[])
{
	cin >> gate;
	cin >> planeNum;

	for (int i = 0; i <= gate; i++)
		gates[i] = i;

	for (int i = 0; i < planeNum; i++)
	{
		cin >> gi;

		int parent = do_find(gi);

		if (parent == 0) //parent가 0 == gate에서 이미 union으로 묶여있는것을 의미. 즉 공항의 폐쇄 조건을 의미함
			break;
		else
		{
			ret++;
			do_union(parent, parent - 1);
		}
	}
	cout << ret << "\n";

	return 0;
}
