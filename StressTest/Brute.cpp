#include <bits/stdc++.h>
using namespace std;

int maxCyclicWindowSum(const std::vector<int>& arr, int k) {
    int n = arr.size();

    // 1. Handle edge cases
    if (n == 0 || k <= 0) {
        return 0; 
    }
    
    // If the window is larger than the array, we cap it at n 
    // (assuming we don't want to count the same elements multiple times)
    if (k > n) {
        k = n;
    }

    int current_sum = 0;

    // 2. Calculate the sum of the initial window
    for (int i = 0; i < k; ++i) {
        current_sum += arr[i];
    }

    int max_sum = current_sum;

    // 3. Slide the window exactly n-1 times to check every starting position
    for (int i = 1; i < n; ++i) {
        // The element leaving the window is just behind our starting index
        int leaving_element = arr[i - 1];
        
        // The element entering wraps around using modulo arithmetic
        int entering_element = arr[(i + k - 1) % n];
        
        current_sum = current_sum - leaving_element + entering_element;
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> d;
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        for(int k = 1; k <= j; k++) d.push_back(k);
    }
    cout << maxCyclicWindowSum(d, x) << '\n';
}
