#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
int n, m;
int ar[45];
pair<int,int> dp[41][41][41];
string s;
void solve(){
    cin >> s >> s;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int cnt = 1;
    for(auto i : st){
        blk[cnt] = i;
        mp[i] = cnt++;
    }
    cout << ans << "\n";
    /*
    10 5
    21 33 17 31 7 10 30 4 1 15

     */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    while(tc--){
        solve();
    }
}