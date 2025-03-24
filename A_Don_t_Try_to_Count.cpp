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
int n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
string s1, s2;
void solve(){
    cin >> n >> m >> s1 >> s2;
    while(tot <= 5 && s1.find(s2) == string::npos){
        tot++;
        s1 += s1;
    }
    cout << (tot == 6? -1 : tot) << "\n";
    tot = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

