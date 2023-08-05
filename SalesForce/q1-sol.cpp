#include <bits/stdc++.h>
using namespace std;

int noOfAliveFrogsOnTheNthDay(int n, int x, int y) {
    vector<int> dp(n + 1, 0);
    int m = 1e9 + 7;

    int temp = 0;
    dp[1] = 1;
    for(int i = 2; i <= n + 1; i++) {
        dp[i] = temp = (temp + dp[max(i - x, 0)] - dp[max(i - y, 0)]);
    }

    int res = 0;
    for(int i = n - y + 1; i <= n; i++) {
        res = res + dp[i];
    }
    return res;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    cout << noOfAliveFrogsOnTheNthDay(n, x, y) << endl;
    return 0;
}