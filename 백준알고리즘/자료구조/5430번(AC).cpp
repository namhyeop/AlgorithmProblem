#include<iostream>
#include<deque>
#include<queue>
#include<string>
using namespace std;

//진짜 눈물이 앞을 가리는 문제다
//투자한 시간 때문에 평생 기억남을 문제 
//3시~ 1시32분 종료. deque STL 덕분에 제대로 이해하고 간다..
//다시 한 번 멍청한 두뇌에 감탄한다.
int main()
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		string comds;
		int Asize;
		string inputA;
		queue<char> q;
		deque<string> dq;
		cin >> comds;
		cin >> Asize;
		cin >> inputA;

		for (int i = 0; i < comds.size(); i++) //q에는 명령 함수를 담아준다
			q.push(comds[i]);

		for (int i = 0; i < inputA.size(); i++)//문자 파싱과정. 숫자들만 담아줄것이다.
		{
			if (inputA[i] == '[')
			{
				i++;
				string ret = "";
				while (inputA[i] != ',' && inputA[i] != ']')
				{
					ret += inputA[i];
					i++;
				}
				dq.push_back(ret);
			}
			else
			{
				string ret = "";
				while (inputA[i] != ',' && inputA[i] != ']')
				{
					ret += inputA[i];
					i++;
				}
				dq.push_back(ret);
			}
		}

		/*
		if (dq.front() == "" || dq.back() == "")
		{
			cout << "error" << endl;
			break;
		}*/

		bool reverse = false; //함수가 뒤집어진 상태인지를 구분하는 flag
		int error_sign = 0;// error가 발생했는지 안 발생했는지 구분하는 flag, error시 파싱 문자를 출력을 안해야하기 때문에 존재
		while (!q.empty())
		{
			char command = q.front();
			q.pop();

			if (command == 'D' && (dq.empty() || dq.front() =="")) //함수가 비었는데 D명령시 오류 발생
			{
				cout << "error" << endl;
				error_sign = 1;
				break;
			}
			
			switch (command)
			{
			case 'R':
				reverse = !reverse;
				break;
			case 'D':
				if (reverse == false) //함수가 뒤집혀지지 않으면 앞에서 pop
					dq.pop_front();
				else
					dq.pop_back();//함수가 뒤집혀있으면 뒤에서 pop
				break;
			}
		}

		if (error_sign != 1)
			cout << "[";

		while (error_sign != 1 && !dq.empty())
		{	
			if (reverse == false) //함수가 뒤집혀지지 않을 경우 앞에서 부터 출력
			{
				string alpha = dq.front();
				dq.pop_front();
				cout << alpha;
				if (dq.size() != 0)
					cout << ",";
			}
			else
			{
				string alpha = dq.back();//함수가 뒤집혀져있을 경우 뒤에서부터 출력
				dq.pop_back();
				cout << alpha;
				if (dq.size() != 0)
					cout << ",";
			}
		}
		if (error_sign != 1)
			cout << "]" << endl;
	}

	return 0;
}
