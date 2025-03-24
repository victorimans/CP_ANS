#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
void File_Work(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
ll n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
ll memo[31];
void solve(){
    cin >> n >> m;
    ll pat = min(m, (ll)(30));
    cout << min(n+1, memo[pat]) << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
    memo[0] = 1;
    for(int i = 1; i < 31; i++){
        memo[i] = (ll)memo[i-1] *2;
    }
	while(t--) solve();
}

