#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
int n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
string s;
void solve(){
    cin >> s;
    string old = s;
    sort(old.begin(), old.end());
    for(int i = 0; i < 3; i++){
        if(old[i] != s[i]){
            tot++;
        }
    }
    if(tot == 2 || tot == 0) cout << "YES\n";
    else cout << "NO\n";
    tot = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t=1;
    cin >> t;
	while(t--) solve();
}

