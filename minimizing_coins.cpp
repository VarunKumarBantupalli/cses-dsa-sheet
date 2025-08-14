#include <bits/stdc++.h>
using namespace std;
#define int long long

int helper(int num , vector<int>& coins , vector<int>& dp){
    if(num < 0)return INT_MAX;
    if(num == 0)return 0;

    if(dp[num] != -1){
        return dp[num];
    }

    int mini = INT_MAX;
    
    for(int i = 0 ; i < coins.size() ; i++){
        int res = helper(num - coins[i] , coins ,dp);
        if(res != INT_MAX){
            mini = min(mini , res+1);
        }
    }
    
    return dp[num] = mini;
}

signed main(){
    int n;
    int x;
    cin>>n>>x;

    vector<int>coins;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin>>a;
        coins.push_back(a);
    }
    
    vector<int>dp(x+1 , -1);
    int count = helper(x , coins ,dp);

    if(count == INT_MAX) {
        cout<<"-1";
        return 0;
    }
    
    cout<<count;
}