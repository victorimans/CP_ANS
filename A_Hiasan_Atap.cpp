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
ll n, m, a, b, c, d, id, sz;
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
vector<int> v;
string s;
ll pf[ukr], pf2[ukr];
void solve(){
    cin >> s >> s;
    id = s.length();
    sz = id;
    for(int i = 1; i <= sz; i++){
        if(s[i-1] == 'A'){
            pf[i] = 1;
        }else{
            pf2[i] = 1;
        }
        pf[i] += pf[i-1];
        pf2[i] += pf2[i-1];
    }
    cin >> n >> m;
    ll tgh = 1 + pf2[sz]*n;
    //cout << tgh << "\n";
    id *= n;
    id++;
    while(m--){
        cin >> a >> b;
        if(a <= tgh && tgh <= b){
            cout << id << "\n";
            continue;
        }
        if(b < tgh){
            int l = 0, r = n, res = 0, res2 = 0;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(1+pf2[sz]*mid <= b && b <= id-pf[sz]*mid){
                    res = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            l = 0, r = sz;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(1+pf2[sz]*res+pf2[mid] <= b && b <= id-pf[sz]*res-pf[mid]){
                    res2 = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            //cout << res << " " << res2 << "\n";
            cout << sz*res+res2+1 << "\n";
        }else{
            int l = 0, r = n, res = 0, res2 = 0;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(1+pf2[sz]*mid <= a && a <= id-pf[sz]*mid){
                    res = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            l = 0, r = sz;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(1+pf2[sz]*res+pf2[mid] <= a && a <= id-pf[sz]*res-pf[mid]){
                    res2 = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            cout << sz*res+res2+1 << "\n";
        }
    }
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

