#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

bool comparator(pair<char, int>& a, pair<char, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

string frequencySort(string s) {
   map<char, int> mp;
   for (int i = 0; i < s.length(); i++)
      mp[s[i]]++;
   vector<pair<char, int>> arr(mp.begin(), mp.end());
   sort(arr.begin(), arr.end(), comparator);
   string ans = "";
   for (int i = 0; i < arr.size(); i++) {
      while (arr[i].second) {
            ans += arr[i].first;
            arr[i].second--;
      }
   }
   return ans;
}

int32_t main() {
    speedup;
    int t = 1;
   //  cin >> t;
    while( t-- ){
       string s; cin >> s;
       cout << frequencySort( s ) << "\n";
   }
}