#include<iostream>
#include<string>
#include<stack>
using namespace std;
//1.HTML의 개행과 폐행의 여부를 묻는 문제
//2.개행과 폐행의 짝이 맞아야함
//3.안에 속성값이 들어갈 수 있다.
//4.#입력시 입력 종료
//개행 부분만 입력을 받아서 스택에 넣어 비교를 해준다. 만약 i가 NULL까지 가서 스택이 비어있으면 legal이고
//스택에 남아있으면 짝이 남아 있지 않으므로 illegal이다.
//루프로 도중에 짝을 맞추다가 안에서부터 개행과 폐행이 맞지 않다면 illegal이다.
int main(int argc, char*argv[])
{
	char input[256];

	do
	{
		cin.getline(input, 256);

		if (input[0] == '#')
			break;

		stack<string> st;
		for (int i = 0; i < 256; i++)
		{
			string temp;
			if (input[i] == '<') //1.태그가 개행인 경우
			{
				if (input[i + 1] == '/')
				{
					i++;
					while (1)
					{
						i++;
						if (input[i] == '>')
							break;
						temp += input[i];
					}
					if (!st.empty() && st.top() == temp)
						st.pop();
					else
					{
						cout << "illegal\n";
						break;
					}
				}
				else//2.아닌 경우
				{
					int no = 0, blank = 0;
					while (1)
					{
						i++;
						if (input[i] == '/' && input[i + 1] == '>') //<b/> 예외처리 이럴 경우 걍 담지 않고 무시
							no++;
						if (input[i] == ' ') //공백이 생기는 경우부터는 속성이거나 필요없는 부분
							blank++;
						if (input[i] == '>')//닫는 경우 나와서
							break;
						if (blank == 0)
							temp += input[i];
					}
					if (no == 0)//예외처리가 아닐 경우 스택에 삽입
						st.push(temp);
				}
			}

			if (st.empty() && input[i] == NULL)
			{
				cout << "legal" << endl;
				break;
			}
			else if (!st.empty() && input[i] == NULL)
			{
				cout << "illegal" << endl;
				break;
			}
		}
	} while (1);

	return 0;
} 

//나는 병신이야
