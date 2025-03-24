#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 998244353;
const int ukr = 3e5+10;
ll n, m, a, b, c, d, id;
struct babi{
    ll x, y, id;
};
struct babis{
    ll x, y;
};
ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}
ll pgkt(ll rnx, ll rny){
    if(rny == 0) return 1;
    ll nwrn = pgkt(rnx, rny/2);
    if(rny%2){
        return (((nwrn*nwrn)%md)*rnx)%md;
    }else{
        return (nwrn*nwrn)%md;
    }
}
vector<pair<int,int>> v;
vector<pair<int,int>> v2;
string s;
ll ar[ukr], pref[ukr], dp[ukr], ma[ukr], mi[ukr];
void solve(){
    cin >> n;
    dp[0] = pref[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> id;
        while(!v.empty() && v.back().first < id){
            v.pop_back();
        }
        while(!v2.empty() && v2.back().first > id){
            v2.pop_back();
        }
        if(!v.empty()){
            ma[i] = (pref[i-1]-pref[v.back().second-1]+md)%md*id%md + ma[v.back().second];
            ma[i] %= md;
        }else{
            ma[i] = (pref[i-1]*id%md);
        }
        if(!v2.empty()){
            mi[i] = (pref[i-1]-pref[v2.back().second-1]+md)%md*id%md + mi[v2.back().second];
            mi[i] %= md;
        }else{
            mi[i] = (pref[i-1]*id%md);
        }
        dp[i] = (ma[i]-mi[i]+md)%md;
        pref[i] = (pref[i-1]+dp[i])%md;
        v.push_back({id, i});
        v2.push_back({id, i});
    }
    cout << dp[n] << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

