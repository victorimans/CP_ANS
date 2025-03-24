#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
int n, m, mx = -1, a;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n-2; i++){
        for(int j = i+2; j < n; j++){
            if(v[j] - v[i] <= m){
                tot += j-i-1;
                mx = max(mx, v[j] + v[i] + v[i+1]);
            }else break;
        }
    }
    if(mx != -1) cout << tot << " "<< mx;
    else cout << -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

