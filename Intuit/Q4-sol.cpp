#include <bits/stdc++.h>
using namespace std;

void findPossibleJumps(int n, int m, int x, vector<int>& dx, vector<int>& dy) {
    dx.push_back(0);
    dy.push_back(x);
    dx.push_back(0);
    dy.push_back(-x);
    dx.push_back(x);
    dy.push_back(0);
    dx.push_back(-x);
    dy.push_back(0);
    int l = 1, r = x - 1;
    while (l <= r) {
        if (l * l + r * r == x * x) {
            dx.push_back(l);
            dy.push_back(r);
            dx.push_back(r);
            dy.push_back(l);
            dx.push_back(-l);
            dy.push_back(r);
            dx.push_back(-r);
            dy.push_back(l);
            dx.push_back(-r);
            dy.push_back(-l);
            dx.push_back(-l);
            dy.push_back(-r);
            dx.push_back(l);
            dy.push_back(-r);
            dx.push_back(r);
            dy.push_back(-l);
            l++;
            r--;
        }
        else if (l * l + r * r < x * x) {
            l++;
        }
        else {
            r--;
        }
    }

    // dx = [0, 5, 3, 4]
    // dy = [5, 0, 4, 3]
    // for (int i = 0; i < dx.size(); i++) {
    //     cout << dx[i] << " " << dy[i] << endl;
    // }
}

int minimumJumpsByX(int n, int m, int x, pair<int, int> src, pair<int, int> dest) {
    src.first--;
    src.second--;
    dest.first--;
    dest.second--;
    vector<int> dx, dy;
    findPossibleJumps(n, m, x, dx, dy);
    int count = 0;
    queue<pair<int, int>> q;
    q.push(src);
    while(!q.empty()) {
        count++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> curr = q.front();
            q.pop();
            cout << curr.first << " " << curr.second << endl;
            if (curr.first == dest.first && curr.second == dest.second) {
                return count - 1;
            }
            for (int j = 0; j < dx.size(); j++) {
                int newX = curr.first + dx[j];
                int newY = curr.second + dy[j];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    q.push({newX, newY});
                }
            }
        }
    }
    return -1;
}

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    pair<int, int> src, dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;
    cout << minimumJumpsByX(n, m, x, src, dest) << endl;
    return 0;
}