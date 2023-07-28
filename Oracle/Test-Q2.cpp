#include <bits/stdc++.h>
using namespace std;

long dominatingXorPairs(vector<int> arr) {
    int n = arr.size();
    long count = 0;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (auto it : hash) {
        int num = it.first;
        int freq = it.second;
        if (freq > 1) {
            count += (long)(freq * (freq - 1) / 2);
        }
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            if (num & mask) {
                int complement = num & ~mask;
                if (hash.find(complement) != hash.end()) {
                    count += (long)(freq * hash[complement]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] ^ arr[j]) > (arr[i] & arr[j])) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << dominatingXorPairs(arr) << endl;
    return 0;
}