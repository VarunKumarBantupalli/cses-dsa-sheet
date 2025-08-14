#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;


int helper(int n , vector<int>& coins , vector<int>& dp){
    if(n < 0)return 0;
    if(n == 0)return 1;

    if(dp[n] != -1){
        return dp[n];
    }

    int ways = 0;

    for(int i = 0 ;i < coins.size() ; i++){
        ways += helper(n - coins[i] , coins ,dp) % MOD;
    }

    return dp[n] = ways;
}

signed main(){
    int n;
    int x;
    cin>>n>>x;
    
    vector<int>coins;

    for(int i = 0; i< n ; i++){
        int a;
        cin>>a;
        coins.push_back(a);
    }

    vector<int>dp(x+1 , -1);

    int count = helper(x , coins ,dp);

    int res = count % MOD;

    cout<<res;

}