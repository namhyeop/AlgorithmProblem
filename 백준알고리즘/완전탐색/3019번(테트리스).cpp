//다시 봐야 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 105
#define INF 987654321
using namespace std;
typedef pair<int, int> node;

int col,type,height,ans;
int map[MAX][100];
vector<node> v;

int make[8][4][4][2] = {
    // 0번 블럭 X
    { },
    // 1번 블럭
    {
        // 첫번째 방향
        { {0,0},{0,1},{0,2},{0,3} },
        // 두번째 방향
        { {0,0},{1,0},{2,0},{3,0} },
        // 세번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} },
        // 네번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} }
    },
    // 2번 블럭
    {
        // 첫번째 방향
        { {0,0},{0,1},{1,0},{1,1} },
        // 두번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} },
        // 세번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} },
        // 네번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} }
    },
    // 3번 블럭
    {
        // 첫번째 방향
        { {0,0},{1,0},{1,1},{2,1} },
        // 두번째 방향
        { {0,0},{0,1},{-1,1},{-1,2} },
        // 세번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} },
        // 네번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} }
    },
    // 4번 블럭
    {
        // 첫번째 방향
        { {0,0},{1,0},{1,-1},{2,-1} },
        // 두번째 방향
        { {0,0},{0,1},{1,1},{1,2} },
        // 세번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} },
        // 네번째 방향 (X)
        { {0,0},{0,0},{0,0},{0,0} }
    },
    // 5번 블럭
    {
        // 첫번째 방향
        { {0,0},{0,-1},{0,1},{-1,0} },
        // 두번째 방향
        { {0,0},{-1,0},{1,0},{0,1} },
        // 세번째 방향
        { {0,0},{0,-1},{0,1},{1,0} },
        // 네번째 방향
        { {0,0},{-1,0},{1,0},{0,-1} }
    },
    // 6번 블럭
    {
        // 첫번째 방향
        { {0,0},{1,0},{2,0},{2,1} },
        // 두번째 방향
        { {0,0},{0,1},{0,2},{1,0} },
        // 세번째 방향
        { {0,0},{0,1},{1,1},{2,1} },
        // 네번째 방향
        { {0,0},{0,1},{0,2},{-1,2} }
    },
    // 7번 블럭
    {
        // 첫번째 방향
        { {0,0},{0,1},{-1,1},{-2,1} },
        // 두번째 방향
        { {0,0},{1,0},{1,1},{1,2} },
        // 세번째 방향
        { {0,0},{0,1},{1,0},{2,0} },
        // 네번째 방향
        { {0,0},{0,1},{0,2},{1,2} }
    },
};

// 밑에 빈공간이 있는지 확인하는 메소드
bool is_ok(int x,int y){
    for(int nx=x; nx<MAX; nx++){
        if(map[nx][y] == 0){
            return false;
        }
    }
    return true;
}

// 1x1 블럭을 4개 설치하기 위한 DFS 탐색
void dfs(int r,int c,int dir,int cnt){
    // 테트리스를 놓은 경우
    if(cnt == 4){
        bool flag = true;
        for(int i=0; i<v.size(); i++){
            int x = v[i].first;
            int y = v[i].second;
            
            if(!is_ok(x,y)){
                flag = false;
                break;
            }
        }
        
        // 밑에 빈공간이 없다면
        if(flag) ans++;
        
        return;
    }
    
    // 다음 테트리스를 놓을 좌표
    int nx = r + make[type][dir][cnt][0];
    int ny = c + make[type][dir][cnt][1];
    
    // 맵을 벗어나거나 테트리스를 놓을 수 없는 곳이라면
    if(nx<0 || ny<0 || nx>=MAX || ny>=col) return;
    if(map[nx][ny] == 1) return;
    
    // 백트래킹
    v.push_back(node(nx,ny));
    map[nx][ny] = 2;
    dfs(r,c,dir,cnt+1);
    map[nx][ny] = 0;
    v.pop_back();
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> col >> type;
    
    for(int j=0; j<col; j++){
        cin >> height;
        
        for(int i=MAX-height; i<MAX; i++){
            map[i][j] = 1;
        }
    }
    
    ans = 0;
    
    // 최대 105x100 배열에 대해 모든 칸을 탐색함
    for(int i=0; i<MAX; i++){
        for(int j=0; j<col; j++){
            if(map[i][j] == 1) continue;
            
            for(int d=0; d<4; d++){
                if(type==1 && d>1) break;
                if(type==2 && d>0) break;
                if(type==3 && d>1) break;
                if(type==4 && d>1) break;
                
                dfs(i,j,d,0);
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
