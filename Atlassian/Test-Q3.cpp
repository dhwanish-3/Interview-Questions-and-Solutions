#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> dirs = {0, 1, 0, -1, 0};
long bfs (vector<vector<int> >& coins, long cur, vector<vector<bool> >& used) {
    long sol = 0;
    int n = coins[0].size();
    pair<int,int> prev{0,0};
    used[0][0] = true;
    int time = 1;
    while (time<2*n) {
        int i = prev.first;
        int j = prev.second;
        int mini = INT_MAX;
        int newX = i;
        int newY = j;
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k];
            int y = j + dirs[k+1];

            if (x<0 || x>=2 || y<0 || y>=n) {
                continue;
            }
            if (used[x][y] ) {
                continue;
            }
            if (mini >= coins[x][y]){
                mini = coins[x][y];
                newX = x;
                newY = y;
            }
        }
        if (newX != i || newY != j) {
            prev={newX,newY};
            sol += time * coins[newX][newY];
            used[newX][newY] = true;
            time++;
        }
    }
    return sol;
}


long getMaxCoins(vector<vector<int> > coins) {
    long sol = 0;
    int n = coins[0].size();
    pair<int,int> prev{0,0};
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    visited[0][0] = true;
    int time = 1;
    while (time < 2 * n) {
        int i = prev.first;
        int j = prev.second;
        int mini = INT_MAX;
        int newX = i;
        int newY = j;
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k];
            int y = j + dirs[k+1];
            if (x < 0 || x >= 2 || y < 0 || y >= n) {
                continue;
            }
            if (visited[x][y]) {
                continue;
            }
            if (mini >= coins[x][y]) {
                mini = coins[x][y];
                newX = x;
                newY = y;
            }
        }
        if (newX != i || newY != j) {
            prev = {newX, newY};
            sol += time * coins[newX][newY];
            visited[newX][newY] = true;
            time++;
        }
    }
    return sol;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int> > coins(2, vector<int>(n));
    for(int i = 0; i < 2 ; i++) {
        for(int j = 0;j < n; j++) cin >> coins[i][j];
    }
    cout<<getMaxCoins(coins)<<endl;

}
