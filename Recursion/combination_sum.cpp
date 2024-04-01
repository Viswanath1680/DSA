#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define speedup ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

void answer_vector( vector<vector<int>>&answer, vector<int> &arr , int target , vector<int>temp , int pointer ){
    if( pointer == arr.size() ) {
        if( target == 0 )
            answer.emplace_back( temp );
        return;
    }
    if( arr[pointer] <= target ){
        temp.emplace_back( arr[pointer] );
        answer_vector( answer, arr, target-arr[pointer], temp, pointer );
        temp.pop_back();
    }
    answer_vector( answer, arr, target, temp, pointer+1 );

}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<vector<int>> answer;
    vector<int> temp;
    answer_vector( answer, ARR, B, temp, 0 );
    return answer;
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
        int target; cin >> target;
        vector<vector<int>> ans = combSum( arr , target ); 
        for( auto outer : ans ){
            for( auto it : outer )
                cout << it << " ";
            cout << "\n";
        }
   }
}