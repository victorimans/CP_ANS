#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 1e6+10;
ll n, m, id, a, b;
/* 
1 2 3 4 5 6 
2 3 1
 */
ll ar[ukr];
ll dsu[ukr];
ll ans[ukr];
ll cekies(ll rn){
    if(dsu[rn] == rn) return rn;
    return dsu[rn] = cekies(dsu[rn]);
}
void join(ll ax, ll bx){
    ll axt = cekies(ax);
    ll bxt = cekies(bx);
    if(axt > bxt){
        dsu[axt] = bxt;
    }else{
        dsu[bxt] = axt;
    }
}
vector<vector<int>> adj(ukr);
queue<int> q;
ll vis[ukr];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dsu[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        ar[i]++;
        join(ar[i], i);
        adj[i].push_back(ar[i]);
    }
    for(int i = 1; i <= n; i++){
        if(cekies(i) == i){
            q.push(i);
            vis[i] = 1;
            ans[i] = 0;
            while(!q.empty()){
                auto rn = q.front();
                q.pop();
                for(auto j : adj[rn]){
                    if(!vis[j]){
                        vis[j] = 1;
                        vis[i]++;
                        ans[j] = ans[rn]+1;
                        q.push(j);
                    }
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a++; b++;
        if(cekies(a) != cekies(b)){
            cout << -1 << "\n";
            continue;
        }
        ll cnt = abs(ans[a]-ans[b]);
        ll jwb = min(cnt, abs(vis[cekies(a)]-cnt));
        cout << jwb << "\n";
    }


}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  int t =1;
    //cin >> t;
    while(t--){
        solve();
    }
}

