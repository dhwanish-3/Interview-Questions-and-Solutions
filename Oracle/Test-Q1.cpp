#include <bits/stdc++.h>
using namespace std;

vector<long> redOrBlue(vector<int> red, vector<int> blue, int blueCost) {
    int n = red.size();
    vector<long> sol = {0};
    int line = 1; // 1 red , -1 blue
    long path = 0;
    for (int i = 0; i < n; i++) {
        if (line == 0 || line == -1) {
            if (red[i] < blue[i]) {
                path += red[i];
                line = 1;
            } else if (red[i] == blue[i]) {
                path += red[i];
                line = 0;
            } else {
                path += blue[i];
                line = -1;
            }
        } else if (line == 1) {
            if (red[i] < blue[i] + blueCost) {
                path += red[i];
                line = 1;
            } else if (red[i] == blue[i] + blueCost) {
                path += red[i];
                line = 0;
            } else {
                path += blue[i] + blueCost;
                line = -1;
            }
        }
        sol.push_back(path);
    }
    return sol;
}

int main(){
    int n, blueCost;
    cin >> n;
    vector<int> red(n);
    vector<int> blue(n);
    for (int i = 0; i < n; i++) {
        cin >> red[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> blue[i];
    }
    cin >> blueCost;
    vector<long> sol = redOrBlue(red, blue, blueCost);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}