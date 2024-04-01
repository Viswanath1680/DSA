#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

void Print(int Pointer, string arr, vector<char>& temp, vector<vector<char>>& ans) {
    if (Pointer == arr.size()) {
        ans.emplace_back(temp);
        return;
    }
    temp.emplace_back(arr[Pointer]);
    Print(Pointer + 1, arr, temp, ans);
    temp.pop_back();
    Print(Pointer + 1, arr, temp, ans);
    return;
}

int subsetsWithDup(string nums) {
    vector<char> temp;
    vector<vector<char>> ans;
    sort(nums.begin(), nums.end());
    Print(0, nums, temp, ans);

    set<vector<char>> ans_set;
    for (auto it : ans)
        ans_set.insert(it);

    // ans.clear();
    // for (auto it : ans_set)
    //     ans.emplace_back(it);

    // return ans;
    return ans_set.size();
}

string moreSubsequence(int n, int m, string a, string b)
{
    int x = n+1, y = m;
    if( n < m ){
        x = m+1;
        y = n;
        if( pow( 2 , y ) < x )
            return b;
    }
    else if( pow( 2 , y ) < x )
        return a;
    vector<vector<char>> answer;
    answer.clear();
    int ans1 = subsetsWithDup( a );
    answer.clear();
    int ans2 = subsetsWithDup( b );
    if( ans1 < ans2 )
        return b;
    return a;
}

int32_t main() {
    speedup;
    int t = 1;
    // cin >> t;
    while( t-- ){
       string a , b; cin >> a;
       cin >> b;
       cout << moreSubsequence( a.size() , b.size() , a , b ) << "\n";
   }
}