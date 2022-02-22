#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll w, ll h){
    ll small, big;

    if(w > h){
        swap(w, h);
    }

    while(h != 0){
        ll tmp = w % h;
        w = h;
        h = tmp;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1;
    /**
     * 전체 사각형의 개수, 자료 범위로 인한 ll 형변환 필수
     */
    ll allRt = (ll)w * (ll)h;
    ll gcdValue = gcd(w, h);
    /**
     * ((w/gcd) + (h/gcd) - 1)) * gcd = 총 빼야할 도형의 갯수
     * -1은 n과 m의 시작지가 같으므로 빼줘야함
     * 답은 [천제 사각형 개수 - ((w/gcd) + (h/gcd) - 1)) * gcd]
     */
    answer = allRt - (w + h - gcdValue);
    return answer;
}

int main(){
    solution(8, 12);
}