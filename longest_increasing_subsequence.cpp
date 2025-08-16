#include <bits/stdc++.h>
using namespace std;
#define int long long

    int helper(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n,1);

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i] , dp[j]+1);
                }
            }
        }

        int maxi = 0;

        for(int i = 0 ; i < dp.size() ; i++){
            maxi = max(maxi,dp[i]);
        }

    return maxi;    
    }

signed main(){
    int n;
    cin>>n;

    vector<int>arr;

    for(int i =0 ; i< n ;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int count = helper(arr);
    cout<<count;
}