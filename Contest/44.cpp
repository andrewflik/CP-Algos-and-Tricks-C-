#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define endl "\n"
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
int main() {
    FIO;
    test
    {
        ll h,w; cin>>h>>w;
        string s[h];
        for(int i=0;i<h;i++){
            cin>>s[i];
        }
        vector<vector<ll>>dp(h,vector<ll>(w));
        vector<vector<ll>>l(h,vector<ll>(w));
        vector<vector<ll>>u(h,vector<ll>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                ll ans=0;
                if(i>0){
                    ans+=u[i-1][j];
                }
                if(j>0){
                    ans+=l[i][j-1];
                }
                ans%=mod;
                if(i==0 && j==0){
                    ans=1;
                }
                if(s[i][j]=='*'){
                    dp[i][j]=0;
                    u[i][j]=0;
                    l[i][j]=0;
                }
                else{
                    dp[i][j]=ans;
                    u[i][j]=((i>0 ? u[i-1][j]:0)+ans)%mod;
                    l[i][j]=((j>0 ? l[i][j-1]:0)+ans)%mod;
                }
            }
        }
        cout<<dp[h-1][w-1]<<endl;
    }
	return 0;
}