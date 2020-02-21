#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
int dp[maxn][maxn];
int n;
int nxt[maxn][26];
bool solve(const string &a,const string &b){
    int an=a.size(),bn=b.size();
    for(int i=0;i<=an;i++)
        for(int j=0;j<=bn;j++)
            dp[i][j]=405;
    dp[0][0]=0;
    for(int i=0;i<=an;i++)
        for(int j=0;j<=bn;j++){
            if(dp[i][j]>n)
                return false;
            int len=dp[i][j];
            if(i<an&&nxt[len][a[i]-'a']<n)
                dp[i+1][j]=min(dp[i+1][j],nxt[len][a[i]-'a']+1);
            if(j<bn&&nxt[len][b[j]-'a']<n)
                dp[i][j+1]=min(dp[i][j+1],nxt[len][b[j]-'a']+1);
            
        }
    return true;
}
int main(int argc, char const *argv[])
{
    #ifdef LOCAL
        freopen("E:\\Cpp\\in.txt", "r", stdin);
        freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
    int T;cin>>T;
    string s,p;
        n=s.size();
    while(T--&&cin>>s>>p){
        memset(nxt,0x3f,sizeof nxt);
        for(int i=n-1;~i;--i){
            for(int j=0;j<26;j++)
                nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i]-'a']=i;
        }
        int sz=p.size();bool f=true;
        for(int k=0;k<sz;k++)
            if(solve(p.substr(0,k),p.substr(k))){
                cout<<"YES"<<endl;
                f=false;
                break;
            }
        if(f)
            cout<<"NO"<<endl;
    }
    return 0;
}