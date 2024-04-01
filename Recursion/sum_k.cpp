#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

void count_k(int pointer, long long k, const std::vector<int>& arr, long long sum, std::vector<int>& temp, std::vector<std::vector<int>>& answer, std::set<std::vector<int>>& uniqueSet) {
    if (sum > k)
        return;
    // if (pointer == arr.size()) {
    //     sort( temp.begin(), temp.end() );
    //     if (sum == k && uniqueSet.find(temp) == uniqueSet.end()) {
    //         answer.emplace_back(temp);
    //         uniqueSet.insert(temp);
    //     }
    //     return;
    // }
    if( sum == k ){
        sort( temp.begin(), temp.end() );
        int sum_c = 0;
        for( auto it : temp )
            sum_c += it;
        if( sum_c != k )
            return;
        if( uniqueSet.find(temp) == uniqueSet.end() ){
            answer.emplace_back( temp );
            uniqueSet.insert( temp );
        }
        return;
    }
    if( pointer == arr.size() )
        return;
    sum += arr[pointer];
    temp.emplace_back(arr[pointer]);
    count_k(pointer + 1, k, arr, sum, temp, answer, uniqueSet);
    sum -= arr[pointer];
    temp.pop_back();
    count_k(pointer + 1, k, arr, sum, temp, answer, uniqueSet);
    return;
}

std::vector<std::vector<int>> subarraysWithSumK(const std::vector<int>& a, long long k) {
    std::vector<std::vector<int>> answer;
    std::vector<int> temp;
    std::set<std::vector<int>> uniqueSet;
    count_k(0, k, a, 0, temp, answer, uniqueSet);
    return answer;
}


int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        int k; cin >> k;
        vector<vector<int>> answer = subarraysWithSumK( arr, k );
        for( auto outer : answer ){
            for( auto it : outer )
                cout << it << " ";
            cout << "\n";
        }
   }
}