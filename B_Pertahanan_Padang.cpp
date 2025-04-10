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
ll n, m, a, b, c, d, id;
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
vector<pair<ll,ll>> v;
string s;
void solve(){
    cin >> s >> n >> m >> id;
    bool cek = 0;
    while(1){
        if(n == 0 && m == 0) break;
        if(n == 0){
            cek = 1;
            break;
        }
        if(n > m){
            ll bg = n/(1+m);
            ll ss = n%(1+m);
            v.push_back({bg, 1});
            n = ss;
        }else{
            ll bg = m/n;
            ll ss = m%n;
            v.push_back({bg, 0});
            m = ss;
        }
    }
    if(cek){
        cout << "TIDAK MUNGKIN" << "\n";
        return;
    }
    cout << "MUNGKIN\n";
    for(ll i = 1; i < v.size(); i++){
        v[i].first += v[i-1].first;
    }
    n = v.back().first;
    while(id--){
        cin >> a >> b;
        a = abs(a-b)+1;
        b = n-b;
        if(b <= 0){
            cout << "DI LUAR BATAS\n";
            continue;
        }
        ll l = 0, r = v.size()-1, idx1 = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(v[mid].first >= b){
                idx1 = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        vector<ll> ans;
        while(a--){
            if(v[idx1].second){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
            b++;
            if(v[idx1].first < b){
                idx1++;
            }
        }
        for(ll i = ans.size()-1; i >= 0; i--){
            cout << ans[i];
        }
        cout << '\n';
    }
    /* 
    4 1

    3 2
    1+pf[]
    110110
    10 = 2 + 4
    1010 = 4
    1 0
    2 0
    2 2
    5 2
    8 2
    8 10
    (1 + 2)x2
    011
    pf[0] = pf[1] + pf[0];
    pf[1] = pf[0] + pf[1] + 1;
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

