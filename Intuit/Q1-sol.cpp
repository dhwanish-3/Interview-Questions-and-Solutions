#include <bits/stdc++.h>
using namespace std;

vector<int> GoodTank(int n, int m){
    vector<int> arr;
    for(int i = 0;i < m; i++){
        arr.push_back(i % (n) + 1);
        cout << arr[i] << " ";
    }
    return arr;
}

int main(){
    
    int n, m;
    cin>>n>>m;

    vector<int> arr = GoodTank(n,m);

    return 0;
}