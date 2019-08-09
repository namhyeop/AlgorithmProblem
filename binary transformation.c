#include <stdio.h> 
#include<conio.h> 
void main()
{
	int i, j, k, a;
	int num = 2; //밑
	int	power = 0;//지수
	int next_sum = 0; //자릿수를 올려주기 위해 존재하는 변수
	int	temp_number; //곱한수에 대한 수치 2자릿수로 자리 올림이 발생시에 나눠서 next_sum으로 넘겨줄거임
	int all_number = 0; //그 자리수 계산을 처음부터 들어간다는 소리 이 숫자 전은 계산완료
	int data[39] = { 0 };  //계산된 숫자를 저장하기 위한 변수
	printf("알고 싶은 2의 거듭제곱을 입력 하시오 : ");
	scanf("%d", &power);
	data[0] = num;

		if (power == 0) //2의 0승일 경우는 계산값이 1이나온다.
		{
			printf("1");
			return 0;
		}

		for (i = 1; i<power; i++) //몇 승이 되냐를 의미하는 총 반복 횟수
		{
			temp_number = 0;
			next_sum = 0;
			for (j = all_number; j >= 0; j--)  //해당 승의 반복
			{
				temp_number = data[j] * num + next_sum; // 첫 째 자리수으 계산
				next_sum = 0; //자릿수 더해주었던게 있더라면 초기화 시킨다
				if (temp_number > 9) //일의 자리수보다 크면
				{
					data[j] = temp_number % 10;  //10으로 나눠서 자리수를 그 현존 자리수에 넣어두고
					if (j == 0)		//첫 번째 자리수가 두자리가 나서 자리 밀림 현상이 발생한다면
					{

						for (k = all_number; k >= 0; k--)
						{
							data[k + 1] = data[k]; //한 칸식 전부 밀어주어서 자릿수 올림 현상을 표현해준다.
						}

						data[0] = temp_number / 10;
						all_number++;                   //자릿수 증가에 대한 총 몇 자리 수인지 알려주는 변수 index값을 증가


					}
					else
					{
						next_sum = temp_number / 10;
					}									//그 다음자리수에는 나눈 목 값을 넣어준다
				}
				else
				{
					data[j] = temp_number;  //첫 번째 자릿수 계산이면 값을 넣겠다.
				}
			}
		}
		//이 식 밑으로는 자릿수를 표현해주는 식
		a = all_number + 1; //배열이 0부터 시작이라 1을 더해주어서 가독성을 향상시키겠다.
		if (a > 3) //3자릿수 이상이면 밑에 조건식 비교 아니면 그냥 출력 이유는 3자릿수 이상부터 ,가 필요 밑에 규칙을 찾는 그림 참조
		{
			if (a % 3 == 0) //나머지 0일때는 앞자릿수 상관없이 도중에나오는 ,점만 찾아주면 되므로 첫 번째 식 비교에 ,추가가 없음
			{
				printf("2^%d : ", power);
				printf("%d", data[0]);                     //매 식마다 뒤에 오는 숫자가 발생시에 ,점을 넣을수 있게 추가함 이유는 1,333, 이러현상의 발생을 막기 위함
				for (i = 1; i <= all_number; i++)
				{
					if ((i % 3 == 0))
						printf(",");

					printf("%d", data[i]);
				}
				printf("\n");

			}

			if (a % 3 == 1)//나머지가 1일때는 앞에 숫자가 1개나오고 ,이 나오므로 데이터값 첫 번째에 ,을 추가하고 중간에 ,을 찾으면 된다
			{
				printf("2^%d : ", power);
				printf("%d,", data[0]);
				for (i = 1; i <= all_number; i++)
				{
					if ((i % 3 == 1) && (i != 1))
					{
						printf(",");
						printf("%d", data[i]);
					}
					else
						printf("%d", data[i]);
				}
				printf("\n");
			}

			if (a % 3 == 2)//나머지가 2일때에는 앞에 숫자가 2개 나오고 ,이 나오므로 데이터 두 번째까지 출력후,을 추가하고 중간, 탐색을 시작
			{
				printf("2^%d : ", power);
				printf("%d", data[0]);
				printf("%d,", data[1]);
				for (i = 2; i <= all_number; i++)
				{
					if ((i % 3 == 2) && (i != 2))
					{
						printf(",");
						printf("%d", data[i]);
					}
					else
						printf("%d", data[i]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("2^%d : ",power);
			for (int i = 0; i <= all_number; i++)
				printf("%d", data[i]);
			printf("\n");
		}
	
		return 0;
		    /*            =뒤의 숫자는 자릿수,온전갬수,3으로나누었을때 나머지수를 의미
		    1, 111 I = 4 1 1
			11, 111 I = 5 1 2
			111, 111 I = 6 1 0
			1, 111, 111 I = 7 2 1
			11, 111, 111 I = 8 2 2
			111, 111, 111 I = 9 2 0
			1, 111, 111, 111 I = 10 3 1
			11, 111, 111, 111 I = 11 3 2
			111, 111, 111, 111 I = 12 3 0
			1, 111, 111, 111, 111 I = 13 4 1
			11, 111, 111, 111, 111 I = 14 4 2
			*/
}