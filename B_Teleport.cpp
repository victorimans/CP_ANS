#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 5e4+10;
int n, m, a, b, c, d, id;
vector<vector<pair<int,int>>> adj(ukr);
string s;
int ar[ukr];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq2;
vector<pair<int,pair<int,int>>> pas;
int dp[ukr];
int dsu[ukr];
int tnda[ukr];
int cekies(int rn){
    if(dsu[rn] == rn) return rn;
    return dsu[rn] = cekies(dsu[rn]);
}
void join(int ax, int bx){
    ax = cekies(ax);
    bx = cekies(bx);
    if(ax < bx){
        dsu[bx] = ax;
    }else{
        dsu[ax] = bx;
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        pas.push_back({c, {a, b}});
    }
    cin >> id;
    for(int i = 1; i <= id; i++){
        cin >> ar[i];
    }
    sort(ar, ar+id);
    if(id == 1){
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
        }
        dp[1] = 0;
        pq.push({0, 1});
        while(!pq.empty()){
            auto [vl, rn] = pq.top();
            pq.pop();
            if(dp[rn] == vl){
                for(auto [nxt, w] : adj[rn]){
                    if(dp[nxt] > vl+w){
                        dp[nxt] = vl+w;
                        pq.push({dp[nxt], nxt});
                    }
                }
            }
        }
        cout << dp[ar[1]] << "\n";
    }else if(id == n){
        for(int i = 1; i <= n; i++){
            dsu[i] = i;
        }
        int ans = 0;
        sort(all(pas));
        for(int i = 0; i < m; i++){
            auto[vl, rn] = pas[i];
            if(cekies(rn.first) != cekies(rn.second)){
                join(rn.first, rn.second);
                ans += vl;
            }
        }
        cout << ans << "\n";
    }else{
        int ans = 0;
        for(int i = 1; i <= n; i++){
            dsu[i] = i;
            dp[i] = INT_MAX;
        }
        for(int i = 1; i <= id; i++){
            tnda[ar[i]] = 1;
        }
        pas.clear();
        dp[1] = 0;
        pq.push({0, 1});
        int ctt;
        while(!pq.empty()){
            auto [vl, rn] = pq.top();
            if(tnda[rn]){
                ans += vl;
                ctt = rn;
                break;
            }
            pq.pop();
            if(dp[rn] == vl){
                for(auto [nxt, w] : adj[rn]){
                    if(dp[nxt] > vl+w){
                        dp[nxt] = vl+w;
                        pq.push({dp[nxt], nxt});
                    }
                }
            }
        }
        //cout << ans << "\n";
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
        }
        pq2.push({0, {ctt, ctt}});
        dp[ctt] = 0;
        while(!pq2.empty()){
            auto [vl, rn] = pq2.top();
            pq2.pop();
            if(dp[rn.first] == vl){
                if(tnda[rn.first]){
                    if(cekies(rn.first) != cekies(rn.second)){
                        join(rn.first, rn.second);
                        ans += vl;
                        dp[rn.first] = 0;
                    }
                    for(auto [nxt, w] : adj[rn.first]){
                        if(dp[nxt] > w){
                            dp[nxt] = w;
                            pq2.push({dp[nxt], {nxt, rn.first}});
                        }
                    }
                }else{
                    for(auto [nxt, w] : adj[rn.first]){
                        if(dp[nxt] > vl+w){
                            dp[nxt] = vl+w;
                            pq2.push({dp[nxt], {nxt, rn.second}});
                        }
                    }
                }
                
            }
        }
        cout << ans << "\n";
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

