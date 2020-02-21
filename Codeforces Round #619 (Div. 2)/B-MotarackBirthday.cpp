#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    int m[100005]={},n;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>m[i];
        m[n+1]=0;
        int cm=-1,cn=INT_MAX,mm=0;
        for(int i=1;i<=n;i++){
            if((m[i-1]==-1||m[i+1]==-1)&&m[i]!=-1){
                cm=max(cm,m[i]);
                cn=min(cn,m[i]);
            }
            if(m[i]!=-1&&m[i+1]!=-1&&i!=n)
                mm=max(mm,abs(m[i]-m[i+1]));
        }
            
        if(cm==-1){
            cout<<0<<" "<<0<<endl;
            continue;
        }
        int k=(cm+cn)/2;
        mm=max(mm,cm-k);
        cout<<mm<<" "<<k<<endl;
        
    }
}