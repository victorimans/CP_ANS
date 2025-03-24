#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+10;
const ll md = 1e9+7;
string s;
ll n, m, id, a, b;
ll ar[36][36];
int vis[36][36];
vector<ll> v;
void dfs(int rnx, int rny, ll val){
    //cout << rnx << " " << rny << "\n";
    if(rnx == n && rny == m){
        v.push_back(val);
        return;
    }
    if(rnx+1 <= n && !vis[rnx+1][rny]){
        vis[rnx+1][rny] = 1;
        dfs(rnx+1, rny, val+ar[rnx+1][rny]);
        vis[rnx+1][rny] = 0;
    }
    if(rnx-1 >= 1 && !vis[rnx-1][rny]){
        vis[rnx-1][rny] = 1;
        dfs(rnx-1, rny, val+ar[rnx-1][rny]);
        vis[rnx-1][rny] = 0;
    }
    if(rny+1 <= m && !vis[rnx][rny+1]){
        vis[rnx][rny+1] = 1;
        dfs(rnx, rny+1, val+ar[rnx][rny+1]);
        vis[rnx][rny+1] = 0;
    }
    if(rny-1 >= 1 && !vis[rnx][rny-1]){
        vis[rnx][rny-1] = 1;
        dfs(rnx, rny-1, val+ar[rnx][rny-1]);
        vis[rnx][rny-1] = 0;
    }
}
void solve(){
    cin >> s >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
        }
    }
    vis[1][1] = 1;
    dfs(1, 1, ar[1][1]);
    cin >> id;
    sort(v.begin(), v.end());
    int pt = v.size() - 1;
    while(id--){
        cin >> a >> b;
        int l = 0, r = pt, res = -1, res2 = -1; 
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] <= b){
                l = mid+1;
                res2 = mid;
            }else{
                r = mid-1;
            }
        }
        l = 0, r = pt;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] < a){
                l = mid+1;
                res = mid;
            }else{
                r = mid-1;
            }
        }
        res++; res2++;
        cout << res2-res << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}