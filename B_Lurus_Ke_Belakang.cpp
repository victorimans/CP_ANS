#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 3e5+10;
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
vector<int> v;
string s;
ll pf[ukr], pf2[ukr];
void upd(ll rn, ll vl, ll as[]){
    for(; rn < ukr; rn += (rn&-rn)){
        as[rn] += vl;
    }
}
ll get(ll rn, ll as[]){
    ll tot = 0;
    for(; rn > 0; rn -= (rn&-rn)){
        tot += as[rn];
    }
    return tot;
}
void solve(){
    cin >> n;
    /*
    a mod b = a - b*(a/b);
    1 2 4 5
    insert 3
    3 mod 1, 2, 4, 5
    gmna kalo semua mod 3?
    balik masuknya?
    hmm?
    jdi kayak 
    3 menarik
     */
    ll ans = 0, tot = 0;
    for(ll i = 0; i < n; i++){
        cin >> id;
        ans += id*i-get(id, pf);
        ans += tot;
        //cout << "anjai" << endl;
        //cout << id*i-get(id, pf) << " ";
        upd(id, id, pf);
        for(ll j = 2*id, cnt = 1; j < ukr; j += id, cnt++){
            ans -= (get(j-1, pf2)-get(j-id-1, pf2))*cnt*id;
            //ppk -= (get(j-1, pf2)-get(j-id-1, pf2))*cnt*id;
            upd(j, id, pf);
        }
        //cout << ppk << "\n";
        tot += id;
        upd(id, 1, pf2);
        cout << ans << " ";
    }
    //cout << ans;

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

