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
    id = 1, tot = 0;
    cin >> s;
    for(int i = 0; i < 4; i++){
        n = s[i]-'0';
        if(n == 0)  n = 10;
        tot += abs(n-id) + 1;
        id = n;
    }
    cout << tot << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

