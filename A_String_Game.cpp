#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
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
int ar[ukr], vis[ukr];
vector<int> v;
string s1, s2;
bool cek(int rn){
    string dupe;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= rn; i++){
        vis[ar[i]] = 1; 
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dupe += s1[i-1]; 
    }
    int j = 0;
    for(int i = 0; i < dupe.length() && j < m; i++){
        if(dupe[i] == s2[j]){
            j++;
        }
    }
    if (j == m) return 1;
    else return 0;
}
void solve(){
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    for(int i = 1; i <= n; i++) cin >> ar[i];
    int l = 0, r = n, res = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        //cout << mid << endl;
        if(cek(mid)){
            l = mid+1;
            res = mid;
        }else r = mid-1;
    }
    cout << res;
    /* 
    bbbabb

    bbabb

    bbab

    bbb

    bb
     */
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

