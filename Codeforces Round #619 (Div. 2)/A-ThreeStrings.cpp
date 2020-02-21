#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

    int T;
    cin>>T;
    string a,b,c;
    while(T--&&cin>>a>>b>>c){
        int n=a.size();bool f=true;
        for(int i=0;i<n;i++)
            if(a[i]==c[i]||b[i]==c[i])
                continue;
            else
            {   f=false;
                cout<<"NO"<<endl;
                break;
            }
        if(f)
            cout<<"YES"<<endl;
            
    }
    return 0;
}
