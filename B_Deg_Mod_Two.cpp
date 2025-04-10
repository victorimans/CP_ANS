#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int ukr = 1e6+10;
const ll md = 1e9+7;
ll n, m, t, id, a, b;
int ar[ukr];
vector<vector<pair<int,int>>> adj(ukr);
vector<int> v;
int vis[ukr];
void dfs(ll rn, ll par, ll pp){
    vis[rn] = 1;
    for(auto i : adj[rn]){
        if(vis[i.first]) continue;
        dfs(i.first, rn, i.second);
    }
    if(ar[rn]){
        ar[rn] ^= 1;
        ar[par] ^= 1;
        v.push_back(pp);
    }
}
void solve(){
    cin >> n >> m;
    int tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        tot += max(ar[i], 0);
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].push_back({b, i+1});
        adj[b].push_back({a, i+1});
    }
    for(int i = 1; i <= n; i++){
        if(ar[i] == -1){
            if(tot%2){
                ar[i] = 1;
                tot++;
            }else{
                ar[i] = 0;
            }
        }
    }
    if(tot%2){
        cout << -1 << "\n";
        return;
    }
    dfs(1, 1, -1);
    sort(all(v));
    if(!v.empty() && *v.begin() == -1){
        cout << -1 << "\n";
        return;
    }
    cout << v.size() << "\n";
    for(auto i : v){
        cout << i << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ct = 1;
    //cin >> t;
    while(ct--){
        solve();
    }
}