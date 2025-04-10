#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 1e5+10;
ll memo[ukr];
ll memo2[ukr];
ll vis[ukr];
ll memo3[ukr];
ll memo4[ukr];
ll dp[ukr];
ll bf[ukr];
ll n, m, s, t, u, v, a, b, c, id, jwb = 1e18;
struct babi{
    ll id, x;
    bool operator < (const babi &other) const{
        return id > other.id;
    }
};
struct babis{
    ll id, x, par;
    bool operator < (const babis &other) const{
        return id > other.id;
    }

};
struct babiss{
    ll id, x, l, r;
    bool operator < (const babiss &other) const{
        return id > other.id;
    }
};
vector<vector<pair<ll,ll>>> adj(ukr);
vector<ll> vc;
priority_queue<babi> pq;
priority_queue<babis> pq2;
priority_queue<babiss> pq3;
vector<vector<ll>> adj2(ukr);
void solve(){
    cin >> n >> m >> s >> t >> u >> v;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i = 0; i <= n; i++){
        memo[i] = 1e18; memo2[i] = 1e18; memo3[i] = 1e18, memo4[i] = 1e18;
    }
    memset(dp, -1, sizeof(dp));
    memo[u] = 0;
    pq.push({0, u});
    while(!pq.empty()){
        babi rn = pq.top();
        pq.pop();
        if(!vis[rn.x]){
            vis[rn.x] = 1;
            for(auto i : adj[rn.x]){
                if(memo[i.first] > memo[rn.x] + i.second){
                    memo[i.first] = memo[rn.x] + i.second;
                    pq.push({memo[i.first], i.first});
                }
            }
        }
    }
    memo2[v] = 0;
    pq.push({0, v});
    while(!pq.empty()){
        babi rn = pq.top();
        pq.pop();
        if(vis[rn.x] == 1){
            vis[rn.x] = 2;
            for(auto i : adj[rn.x]){
                if(memo2[i.first] > memo2[rn.x] + i.second){
                    memo2[i.first] = memo2[rn.x] + i.second;
                    pq.push({memo2[i.first], i.first});
                }
            }
        }
    }
    memo3[s] = 0;
    pq2.push({0, s, -1});
    while(!pq2.empty()){
        babis rn = pq2.top();
        pq2.pop();
        if(vis[rn.x] == 2){
            vis[rn.x] = 3;
            for(auto i : adj[rn.x]){
                if(memo3[i.first] == memo3[rn.x] + i.second){
                    adj2[i.first].push_back(rn.x);
                }else if(memo3[i.first] > memo3[rn.x] + i.second){
                    adj2[i.first].clear();
                    adj2[i.first].push_back(rn.x);
                    memo3[i.first] = memo3[rn.x] + i.second;
                    pq2.push({memo3[i.first], i.first, rn.x});
                }
            }
        }
    }
    memo4[t] = memo[t]+memo2[t];
    pq3.push({ memo[t]+memo2[t], t, memo[t], memo2[t]});
    while(!pq3.empty()){
        babiss rn = pq3.top();
        pq3.pop();
        //cout << rn.x<< "\n";
        jwb = min(jwb, memo4[rn.x]);
        for(auto i : adj2[rn.x]){
            ll nwx = min(memo[i], rn.l);
            ll nwy = min(memo2[i], rn.r);
            if(memo4[i] > nwx+nwy){
                memo4[i] = nwx+nwy;
                pq3.push({memo4[i], i, nwx, nwy});
            }
        }
    }
    cout << min(jwb, memo[v]) << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}