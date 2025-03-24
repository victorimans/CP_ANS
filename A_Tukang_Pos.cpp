#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 5e5+10;
void File_Work(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
int n, m, a, b, c, d, id;
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
vector<vector<pair<int,int>>> adj(ukr);
vector<int> v;
int vis[ukr];
int eve[ukr];
int idx[ukr];
int ans[ukr];
string s;
int dfs(ll rn, ll sz){
    //cout << rn << endl;
    vis[rn] = 1;
    ans[sz] = rn;
    for(int i = idx[rn]; i < adj[rn].size(); i++){
        auto [nx, ii] = adj[rn][i];
        if(eve[ii]){
            idx[rn]++;
            continue;
        }
        eve[ii] = 1;
        idx[rn]++;
        if(!vis[nx]){
            ll pp = dfs(nx, sz+1);
            if(pp == rn){
                continue;
            }else{
                vis[rn] = 0;
                return pp;
            }
        }else{
            for(int j = sz; j >= 0; j--) {
                cout << ans[j] << " ";
                if(ans[j] == nx) break;
            }
            cout << "\n";
            vis[rn] = 0;
            return nx;
        }
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
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

