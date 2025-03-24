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
        return (((nwrn*nwrn))*rnx);
    }else{
        return (nwrn*nwrn);
    }
}
vector<int> v;
string s;
ll ar[ukr];
ll br[ukr], pw2 = 1;
ll pf[ukr], sf[ukr];
void solve(){
    cin >> n >> m >> c >> id;
    id--;
    while(n > pw2){
        pw2 *= 2;
    }
    for(ll i = 1; i <= n; i++){
        cin >> ar[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> br[i];
    }
    if(!id || !c){
        for(ll i = 1; i <= n; i++){
            pf[i] = br[i]+(n-i)*c;
            if(i >= 2) pf[i] = min(pf[i], pf[i-1]);
        }
        for(ll i = n; i >= 1; i--){
            sf[i] = br[i]+(i-1)*c;
            if(i <= n-1) sf[i] = min(sf[i], sf[i+1]);
        }
        for(ll i = 1; i <= n; i++){
            ll rn = m-ar[i]; 
            ll bgi = (c == 0 ? 0 : (m-ar[i])/c); 
            ll l = 1, r = i, res = -1;
            while(l <= r){
                ll mid = l + (r-l)/2;
                if(pf[mid]-(n-i)*c <= rn){
                    r = mid-1;
                    res = mid;
                }else{
                    l = mid+1;
                }
            }
            ll ans = 0, sem = 0;
            if(res == -1){
                sem = m;
            }else{
                ans = i-res+1;
                sem = rn - (pf[res]-(ll)(n-i)*c);
            }
            l = i, r = n, res = -1;
            while(l <= r){
                ll mid = l + (r-l)/2;
                if(sf[mid]-((ll)i-1)*c<= rn){
                    l = mid+1;
                    res = mid;
                }else{
                    r = mid-1;
                }
            }
            if(res != -1){
                if(res-i+1 > ans){
                    ans = res-i+1;
                    sem = rn - (sf[res]-(ll)(i-1)*c);
                }else if(res-i+1 == ans){
                    sem = max(sem, rn - (sf[res]-(ll)(i-1)*c));
                }
            }
            cout << ans << " " << sem << "\n";
        }
    }else{
        for(ll i = 1; i <= n; i++){
            ll rn = m-ar[i]; 
            ll l = 0, r = n, res = -1;
            while(l <= r){
                ll mid = l + (r-l)/2;
                if(mid*mid*c <= rn){
                    l = mid+1;
                    res = mid;
                }else{
                    r = mid-1;
                }
            }
            ll ans = 0, sem = m;
            if(res == -1){
                cout << ans << " " << sem << "\n";
                continue;
            }
            for(ll j = max(1LL, i-res); j <= i; j++){
                if(rn >= br[j]+(i-j)*(i-j)*c){
                    ans = i-j+1;
                    sem = rn - (br[j]+(ll)(i-j)*(i-j)*c);
                    break; 
                }
            }
            for(ll j = min(n, i+res); j >= i; j--){
                if(rn >= br[j]+(j-i)*(j-i)*c){
                    if(j-i+1 > ans){
                        ans = j-i+1;
                        sem = rn - (br[j]+(ll)(j-i)*(j-i)*c);
                    }else if(j-i+1 == ans){
                        sem = max(sem, rn - (br[j]+(ll)(j-i)*(j-i)*c));
                    }
                    break; 
                }
            }
            cout << ans << " " << sem << "\n";
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

