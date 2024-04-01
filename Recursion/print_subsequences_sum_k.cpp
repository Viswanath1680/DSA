#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

/*
    If they ask to 
    Print, just print all the subsequences.
    Print 1, just return true or false accordingly.
    Count, return 1 and return 0. Add all of them at last.
*/


// prints all the subsequences such that sum is k.
void Print( int pointer , vector<int> arr , vector<int> ans , int k ){
    if( pointer == arr.size() ){
        int sum = 0;
        for( auto it : ans )
            sum += it;
        if( sum == k && ans.size() != 0  ){
            for( auto it : ans )
                cout << it << " ";
            cout << "\n";
        }
        return;
    }
    ans.emplace_back( arr[pointer] );
    Print( pointer+1 , arr , ans, k );
    ans.pop_back();
    Print( pointer+1 , arr , ans, k );
}

// Tells if atleast one subsequence is there S.T sum is k.
bool Is_one_k( int pointer , vector<int> arr , vector<int>ans , int sum , int k ){
    if( pointer == arr.size() ){
        if( sum == k && ans.size() != 0 ){
            // for( auto it : ans )
            //     cout << it << " ";
            // cout << "\n";
            return true;
        }
        return false;
    }
    ans.emplace_back( arr[pointer] );   // with current element
    sum += arr[pointer];
    if( Is_one_k( pointer+1 , arr , ans , sum , k ) )   // trust the recursive function that it works and gives the output.
        return true;
    ans.pop_back();     // without current element
    sum -= arr[pointer];
    if( Is_one_k( pointer+1 , arr , ans , sum , k ) )   
        return true;    
    
    return false;   // If both recusrive calls fail, then return false as there's no subsequence at all.
}

// returns the number of subsequences such that their sum is k.
int subsequences_count_sum_k(  int pointer, vector<int> arr , int sum , int k ){
    if( pointer == arr.size() ){
        if( sum == k )
            return 1;
        return 0;
    }
    sum += arr[pointer];
    int l = subsequences_count_sum_k( pointer+1 , arr , sum , k );
    sum -= arr[pointer];
    int r = subsequences_count_sum_k( pointer+1 , arr , sum , k );
    return l+r;
}

int32_t main() {
    speedup;
    int t = 1;
    cin >> t;
    while( t-- ){
        int n ;cin >> n;
        vector<int> arr(n);
        for( auto& it : arr)
            cin >> it;
        int k; cin >> k;
        vector<int> ans;
        Print( 0 , arr , ans , k );
        cout << "--------\n";
        // cout << Is_one_k( 0 , arr , ans , 0 , k ) << "\n";
        cout << subsequences_count_sum_k( 0 , arr , 0 , k ) << "\n";
   }
}