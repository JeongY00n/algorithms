#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*
두 건물을 잇는 선분에 다른 건물이 접하거나 지나면 안됨
양옆 모두 확인
기울기가 갱신되는 경우는 보이는 경우이기 때문에 
갱신될 때마다 카운팅해주기
*/


int n;
double building[50];
int answer;
void init(){
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>building[i];
    }
}



void solution(){
    if(n==1)return;
    for(int idx = 0; idx<n; idx++){
        double left_mini=2e9, right_maxi=-2e9;
        int cnt = 0;
        //좌
        for(int i = idx-1; i>=0; i--)
        {
            double grad = (building[idx]-building[i])/double(idx-i);
            if(left_mini>grad)
            {
                cnt++;
                left_mini=grad;
            }
            
        }
        //우
        for(int i = idx+1; i<n; i++)
        {
            double grad = (building[idx]-building[i])/double(idx-i);
            if(right_maxi<grad)
            {
                cnt++;
                right_maxi=grad;
            }

        }
        answer = max(answer, cnt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solution();
    cout<<answer;
    return 0;
}
