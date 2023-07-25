#include <bits/stdc++.h>
using namespace std;

void maxDegreeNodes(vector<vector<int>> v) {
    int m = v.size();
    int n = v[0].size();
    int maxDegree = 0;
    for (int i = 0; i < m; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) degree++;
        }
        maxDegree = max(maxDegree, degree);
    }
    for (int i = 0; i < m; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) degree++;
        }
        if (degree == maxDegree){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    maxDegreeNodes(v);
    return 0;
}