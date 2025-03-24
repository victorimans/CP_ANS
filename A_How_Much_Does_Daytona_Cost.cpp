#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+2;
int n, m, a, b, c, d, id;
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
        cin >> id;
        if(id == m) tot++;
    }
    if(tot == 0){
        cout << "NO" << "\n";
    }else cout << "YES" << "\n";
    tot = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

