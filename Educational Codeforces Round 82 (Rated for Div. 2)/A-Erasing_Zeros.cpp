#include<iostream>
#include<string>
using namespace std;

int main(){  
    #ifdef LOCAL
        freopen("E:\\Cpp\\in.txt", "r", stdin);
        freopen("E:\\Cpp\\out.txt", "w", stdout);
    #endif
    /* code */
    int n;
    cin>>n;
    string s;
    while(n--&&cin>>s){
        int sz=s.size();bool sf=false,ef=false;
        int cur=0,res=0;
        for(int i=0;i<sz;i++)
            if(s[i]=='1'){
                res+=cur;
                sf=true;
                cur=0;
            }else if(sf)
                cur++;
        cout<<res<<endl;
    }
    return 0;
}
