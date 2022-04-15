#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int MAX= 3000;
int visited[MAX][MAX];
set<int> checkNum;
set<int> s;
vector<vector<int>> Arr;
int row, col;
int zeroCnt, oneCnt;
int sectorNum = 0;

bool isSame(int sy, int sx, int gy, int gx){
    int tmp = Arr[sy][sx];
    for(int i = sy; i < gy; i++){
        for(int j = sx; j < gx; j++){
            if(tmp != Arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

void marking(int sy, int sx, int gy, int gx){
    for(int i = sy; i < gy; i++){
        for(int j = sx; j < gx; j++){
            visited[i][j] = sectorNum;
        }
    }
    s.insert(sectorNum);
}

void divide(int sy, int sx, int gy, int gx,int area){
//    cout <<"sectorNum " << sectorNum << " " << "sy : " << sy <<" sx : " << sx << " gy : " << gy <<" gx : " << gx << " " << "area " << area<<"\n";
    if(isSame(sy, sx, gy, gx)){
        marking(sy, sx, gy, gx);
        sectorNum++;
        return ;
    }

    if(sy == gy && sx == gx){
        return;
    }
    divide(sy,  sx, (sy  + gy)/2, (sx + gx)/2, 2); //2사분면
    divide(sy, (sx + gx)/2, (sy  + gy) / 2, gx,1); //1사분면
    divide((sy + gy) / 2, sx, gy, (sx + gx)/2, 3); //3사분면
    divide((sy + gy) / 2, (sx + gx)/2, gy, gx,4); //4사분면
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    Arr = arr;
    row = arr.size();
    col = arr[0].size();
    divide(0,0,row, col,0);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(s.count(visited[i][j]) && !checkNum.count(visited[i][j])){
                if(Arr[i][j] == 0){
                    zeroCnt++;
                    checkNum.insert(visited[i][j]);
                }
                else{
                    oneCnt++;
                    checkNum.insert(visited[i][j]);
                }
            }
        }
    }

//    for(int i = 0; i < row; i++){
//        for(int j = 0; j < col; j++){
//            cout << visited[i][j] <<" ";
//        }
//        cout <<"\n";
//    }
//    cout <<zeroCnt <<" "<< oneCnt <<"\n";
    answer[0] = zeroCnt, answer[1] = oneCnt;
    return answer;
}

int main(){
    solution({{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}});
}