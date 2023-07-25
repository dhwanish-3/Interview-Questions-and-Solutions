#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int findNumberOfNewArray(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int mod = 1e9 + 7;
    long long prod=1;
    for (int i = 0; i < n; i++){
        // the new_arr[i] could take values from 1 to arr[i] except those values taken by the positions preceding it and thus a (-i)
        prod *= arr[i]-i;
        if( prod == 0) return 0; // optimization
    }
    return prod % mod;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << findNumberOfNewArray(arr) << endl;
    return 0;
}