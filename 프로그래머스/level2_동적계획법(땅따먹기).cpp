#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for(int i = 0; i < land.size() - 1; i++){
        land[i + 1][0] += max({land[i][1], land[i][2], land[i][3]});
        land[i + 1][1] += max({land[i][0], land[i][2], land[i][3]});
        land[i + 1][2] += max({land[i][0], land[i][1], land[i][3]});
        land[i + 1][3] += max({land[i][0], land[i][1], land[i][2]});
    }
    answer = max({land[land.size() - 1][0],land[land.size() - 1][1],land[land.size() - 1][2],land[land.size() - 1][3]});
    return answer;
}

/**
 * 시간 복잡도 계산 안한 잘못된 풀이
 */
//const int MAX = 1e5 + 1;
//bool visited[MAX][4];
//vector<vector<int>> Land;
//int row, maxPoint;
//void DFS(int level, int sum){
//    if(level == row){
//        maxPoint = max(maxPoint, sum);
//        return;
//    }
//
//    for(int i = 0; i< 4; i++){
//        if(!visited[level-1][i]){
//            visited[level][i] = true;
//            DFS(level + 1, sum + Land[level][i]);
//            visited[level][i] = false;
//        }
//    }
//}
//
//int solution(vector<vector<int> > land)
//{
//    int answer = 0;
//    Land = land;
//    row = land.size();
//
//    DFS(0, 0);
//    answer = maxPoint;
//
//    return answer;
//}