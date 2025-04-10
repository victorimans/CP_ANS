#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+101;
const ll md = 1e9+7;
ll pgkt(ll rn, ll pp){
    if(pp == 0) return 1;
    ll nwx = pgkt(rn, pp/2)%md;
    if(pp%2){
        return nwx*nwx%md*rn%md;
    }else{
        return nwx*nwx%md;
    }
}
string s;
ll n, m, id;
ll dp[ukr][2][4];
vector<int> v;
ll rec(ll rn, ll pp, ll cnt){
    if(rn == n) return 0;
    if(dp[rn][pp][cnt] != -1) return dp[rn][pp][cnt];
    ll tot = 0;
    tot = max(tot, rec(rn+1, 1, cnt));
    if(s[rn] == 'W'){
        tot = max(tot, rec(rn+1, 0, (cnt == 3 ? 3 : cnt+1))+2+(cnt == 3 || cnt+1 == 3 ?1:0));
    }else if(s[rn] == 'D'){
        tot = max(tot, rec(rn+1, 0, 0)+1);
    }else{
        tot = max(tot, rec(rn+1, 0, 0));
    }
    return dp[rn][pp][cnt] = tot;
}
void solve(){
    cin >> s;
    n = s.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}