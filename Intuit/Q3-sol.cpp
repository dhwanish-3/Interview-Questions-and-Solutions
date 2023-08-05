#include <bits/stdc++.h>
using namespace std;

int DrageRaceWinner(vector<int> &a, vector<int> &b){
    int n = a.size();
    int ans = 0;
    int winner = 0;
    for (int i = 0; i < n; i++){
        ans = (5 * a[i] + 2 * b[i]);
        winner = max(winner, ans);
    }
    return winner;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    cout << DrageRaceWinner(a, b);
    return 0;
}