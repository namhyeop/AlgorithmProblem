/**
     * 1. 1 <= X < X + d1 + d2 <= N의 문제 조건이 있습니다. 이항 전계를 통한 식 정리를 진행하면
     * 2. 1 <= X <= N -d1 - d2 가 나옵니다
     * 3. d1,d2 >= 1이므로
     * 4. 1 <= X <= N - 2의 식이 나옵니다.(45번줄 조건)
     *
     * 5. 1<= Y - d1 <y <y + d2 <= N이 문제 조건이 있습니다 .이항 전계를 통한 식 정리를 진행하면
     * 6. 1 + d1 <= y <= N -d2 가 나옵니다
     * 7. d1, d2 >= 1이므로
     * 8. 1 <= Y <= N - 1의 식이 나옵니다(46번줄 조건)
     *
     * 2번 줄을 이항전계하여 d1의 조건을 찾습니다.(47번줄 조건)
     * d1 >= x - N + d2
     * "d1 <= N -X + 1"
     * 6번 줄을 이항전계하여 d1의 조건을 찾습니다.
     * "d1 <= y - 1"
     *
     * 2번 줄을 이항전계하여 d2의 조건을 찾습니다.(48번줄 조건)
     * X- N + d1 <= d2
     * d2 <= N -X - d1
     * "d2 <= N - X - 1"
     * 6번 줄을 이항전계하여 d2의 조건을 찾습니다.
     * d2 <= N - Y
     *
     * 마지막으로 1,2,3,4,5번 구역의 범위에 부합한지 확인한 후 각 구역마다의 값을 합산하고 정렬한뒤 제일 큰 값에서 제일 작은 값을 빼줍니다.
     * */

#include<bits/stdc++.h>

using namespace std;

const int MAX = 21;

int N;
int board[MAX][MAX];

int main(){
    cin >> N;

    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cin >> board[x][y];
        }
    }

    int ret = INT_MAX;
    for(int x = 1; x <= N - 2; x++){
        for(int y = 2; y <= N - 1; y++){
            for(int d1 = 1; d1 <= N - x -1 && d1 <= y - 1; d1++){
                for(int d2 = 1; d2 <= N - x - 1 && d2 <= N - y; d2++){
                    vector<int> area(5, 0);
                    for(int i = 1; i <= N; i++){
                        for(int j = 1; j <= N; j++){
                            //첫 번째 구역이라면
                            if(i < x + d1 && j <= y && !(i >= x && j >= y - i + x)){
                                area[0] += board[i][j];
                                continue;
                            }
                            //두 번째 구역이라면
                            if(i <= x + d2 && j > y && !(j >= x && j <= y + i - x)){
                                area[1] += board[i][j];
                                continue;
                            }
                            //세 번째 구역이라면
                            if(i >= x + d1 && j < y - d1 + d2 && !(i <= x + d1 + d2 && j >= (y - d1 + d2 - (x + d1 + d2 - i)))){
                                area[2] += board[i][j];
                                continue;
                            }
                            //네 번째 구역이라면
                            if(i > x + d2 && j >= y - d1 + d2 && !(i <= x + d1 + d2 && j <= (y - d1 + d2 + (x + d1 + d2 - i)))){
                                area[3] += board[i][j];
                                continue;
                            }
                            //다섯 번째 구역이라면
                            area[4] += board[i][j];
                        }
                    }
                    sort(area.begin(), area.end());
                    ret = min(ret, area[4] - area[0]);
                }
            }
        }
    }
    cout << ret <<"\n";
}