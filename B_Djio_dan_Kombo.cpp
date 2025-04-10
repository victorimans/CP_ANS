
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+10;
int read() {
    int ketek = 0; bool ne=0;
    register char c = getchar();
    while(c == ' ' or c =='\n') c =getchar();
    if(c=='-'){ne = 1; c = getchar();}
    while(c >= '0' and c <='9') { ketek = (ketek<<3)+(ketek<<1)+c-'0'; c = getchar();}
    if(ne) ketek*=-1;
    return ketek;
}   
void print(int x) {
    if (x < 0) {putchar('-');x = -x;}
    int len = 0, buf[10];
    if (x == 0) {putchar('0');return;}
    while (x > 0) {buf[len++] = x % 10; x/=10;}
    while (len > 0) {putchar('0' + buf[--len]);}
}
void File_Work(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
int n, m, a, b, c, d, id;
struct babi{
    ll x, y, id;
};
struct babis{
    ll x, y;
};
ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}
ll pgkt(ll rnx, ll rny){
    if(rny == 0) return 1;
    ll nwrn = pgkt(rnx, rny/2);
    if(rny%2){
        return (((nwrn*nwrn)%md)*rnx)%md;
    }else{
        return (nwrn*nwrn)%md;
    }
}
vector<string> v;
string s, t;
bool cmp(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}
void solve(){
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++){
        cin >> t;
        v.push_back(t);
    }
    sort(all(v));
    int ans = 0;
    string pp = "";
    for(int i = 0; i < n; i++){
        pp += s[i];
        int l = 0, r = m-1, res = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] >= pp){
                r = mid-1;
                res = mid;
            }else{
                l = mid+1;
            }
        }
        ll kc = pp.length();
        if(res == -1 || v[res].substr(0, kc) != pp){
            pp = s[i];
            l = 0, r = m-1, res = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(v[mid] >= pp){
                    r = mid-1;
                    res = mid;
                }else{
                    l = mid+1;
                }
            }
        }
        if(res != -1 && v[res] == pp){
            ans++;
            pp = "";
        }
    }
    cout << ans;
    /* 
    aaa
    aab
    aba
    ba
    baa
    bab
    bba
     */

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

