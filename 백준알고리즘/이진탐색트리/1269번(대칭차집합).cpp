#include<iostream>
#include<set>
using namespace std;
//1.집합 A를 입력받고
//2.집합 B를 입력받으면서 A안에 있는 것들이 존재하면
//3.count값을 증가 시킨뒤에
//4.집합 A.size + 집합 B.size - 2 *count = 대칭차집합값이
//5.나온다.
int main(int argc, char * argv[])
{
	set<int> board;
	set<int>::iterator iter;

	int sizeA;
	int sizeB;
	int count;

	cin >> sizeA >> sizeB;
	
	count = 0;

	for (int i = 0; i < sizeA; i++)
	{
		int tmp;
		cin >> tmp;
		board.insert(tmp);
	}

	for (int i = 0; i < sizeB; i++)
	{
		int tmp;
		cin >> tmp;
		
		iter = board.find(tmp);
		if (iter != board.end())
			count++;
	}

	cout << sizeA + sizeB - 2 * count;
	
	return 0;
}
