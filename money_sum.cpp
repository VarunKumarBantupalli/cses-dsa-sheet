#include <bits/stdc++.h>
using namespace std;
#define int long long

bool helper(int idx,int amount , vector<int>& coins , vector < vector<int> >& dp ,
set <int>& val){
    int n = coins.size();
    if(idx == n){
        if(amount > 0){
            val.insert(amount);
            return true;
        }
        return false;
    }
    if(dp[amount][idx] != -1){
        return dp[amount][idx];
    }
    //not take
    helper(idx+1 ,amount,coins,dp,val);

    //take
    helper(idx+1 ,amount+coins[idx],coins,dp,val);

    return dp[amount][idx] = 1;
}

signed main(){
    int n;
    cin>>n;

    vector<int>coins;
    int maxsum = 0;
    for(int i = 0 ;i < n;i++){
        int x;
        cin>>x;
        maxsum += x;
        coins.push_back(x);
    }

    vector< vector<int> >dp(maxsum+1 ,  vector<int>(n+1,-1));

    set<int>val;

    helper(0,0,coins,dp,val);

    cout<<val.size()<<endl;
    for(auto it : val){
        cout<<it<<" ";
    }

    
}