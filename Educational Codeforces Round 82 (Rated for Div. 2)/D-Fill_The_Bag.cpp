#include<bits/stdc++.h>
using namespace std;
void solve(long long target,int n){
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long res;
        while(n--){
            cin>>res;
            pq.push(res);
        }
        res=0;
        while(target){
            long long low=target&(~target+1);
            if(pq.empty()){
                cout<<-1<<endl;
                return;
            }
            long long t=pq.top();pq.pop();
            if(t<low){
                if(pq.size()){
                    if(pq.top()==t){
                        pq.pop();
                        pq.push(2*t);
                    }
                }
            }else if(t==low){
                target-=low;
            }else{
                res++;
                pq.push(t/2);
                pq.push(t/2);
            }
        }
        cout<<res<<endl;
}
int main(int argc, char const *argv[])
{
    #ifdef LOCAL
        freopen("E:\\Cpp\\in.txt", "r", stdin);
        freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
    int T;cin>>T;
    long long target;int n;
    while(T--&&cin>>target>>n){
        solve(target,n);
    }
    return 0;
}
