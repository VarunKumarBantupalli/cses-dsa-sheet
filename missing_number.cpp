#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

    int n;
    cin>>n;

    vector<int>arr;

    int sum = 0;

    for(int i = 0 ; i < n-1 ;i++){
        int x;
        cin>>x;

        arr.push_back(x);

        sum += x;
    }

    int required = (n * (n+1))/2;

     int missing =required-sum;

     cout<<missing;


}