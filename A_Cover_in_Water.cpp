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
int n, m, a, b, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
char c;
void solve(){
    cin >> n;
    tot = 0;
    int ans = 200;
    int totsem = 0;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '#'){
            tot = 0;
        }else if(c == '.'){
            tot++;
            if(tot == 3){
                ans = 2;
            }
            totsem++;
        }
    }
    cout << min(ans, totsem) << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

