#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    long  a,b;
    while(T--&&cin>>a>>b){
        if(b==0){
            cout<<0<<endl;
            continue;
        }
        if(b==1&&a&1){
            cout<<(a+1)*(a+1)/4<<endl;
        }
        long res=0;
        //a-b...a
        res=b*(a-b+1+a)/2;
        
        cout<<res<<endl;
            
    }
    return 0;
}