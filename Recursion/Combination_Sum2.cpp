#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

void Print(int pointer, vector<vector<int>>& answer, vector<int>& arr, vector<int>& ans, int k) {
    if (pointer == arr.size()) {
        int sum = 0;
        for (auto it : ans)
            sum += it;
        if (sum == k && ans.size() != 0) {
            sort(ans.begin(), ans.end());
            answer.emplace_back(ans);
        }
        return;
    }
    ans.emplace_back(arr[pointer]);
    Print(pointer + 1, answer, arr, ans, k);
    ans.pop_back();
    Print(pointer + 1, answer, arr, ans, k);
}

bool vectorCompare(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    } else {
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        Print(0, answer, candidates, temp, target);
        sort(answer.begin(), answer.end(), vectorCompare);
        set<vector<int>> set_of_vectors;
        for( auto it: answer ){
            set_of_vectors.insert( it );
        }
        answer.clear();
        for( auto it : set_of_vectors )
            answer.emplace_back( it );
        return answer;
    }
};

int32_t main() {
    speedup;
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto& it : arr)
            cin >> it;

        int target;
        cin >> target;

        Solution sol;
        vector<vector<int>> result = sol.combinationSum2(arr, target);

        // Displaying the result
        for (const auto& res : result) {
            for (int value : res) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
}
