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
vector<string> prm;
vector<string> v;
string s;
string ask(string &rn){
    string sem;
    cout << rn << endl;
    cin >> sem;
    return sem;
}
int blk[10];
int ar[10][10];
int cek(string &a, string &b){
    int ret = 0;
    int kl = 1;
    int ar1[5], ar2[5];
    for(int i = 0; i < 5; i++) {
        if(a[i] == b[i]) {
            //cout << i << " " << kl << endl;
            ar1[i] = -1;
            ar2[i] = -1;
            ret += 2*kl;
        }else{
            ar1[i] = 0;
            ar2[i] = 0;
        }
        kl*=3;
    }
    kl = 1;
    for(int i = 0; i < 5; i++) {
        for(int j =0; j < 5; j++) {
            if(ar1[i] != -1 && ar2[j] != -1 && a[i]==b[j]) {
                ar1[i] = -1;
                ar2[j] = -1;
                ret+=1*kl;
            }
        }
        kl*=3;
    }
    return ret;
}
void solve(){
    //cin >> s >> n >> m;
    v.clear();
    string rn = "62791";
    string ck = ask(rn);
    if(ck == "+++++"){
        return;
    }
    ll val = 0;
    ll kl = 1;
    for(auto i : ck){
        if(i == '+'){
            val += 2*kl;
        }else if(i == '?'){
            val += kl;
        }
        kl*=3;
    }
    for(auto i : prm) {
        if(cek(rn, i) == val)v.push_back(i);
    }
    int mx = INT_MAX;
    for(int i = 0; i <= 100; i++){
        vector<int> s(244, 0);
        int as = 0;
        for(auto j : v){
            int dd = cek(prm[i], j);
            as = max(as, ++s[dd]);
        }
        if(mx > as){
            rn = prm[i];
            mx = as;
        }
    }
    //cout << "masuk" << endl;
    while(v.size() > 1){
        ck = ask(rn);
        if(ck == "+++++"){
            return;
        }
        val = 0;
        kl = 1;
        for(auto i : ck){
            if(i == '+'){
                val += 2*kl;
            }else if(i == '?'){
                val += kl;
            }
            kl*=3;
        }
        vector<string> tmp;
        for(auto i : v) {
            if(cek(rn, i) == val) tmp.push_back(i);
        }
        v = tmp;
        //cout << v.size() << "\n";
        int mx = INT_MAX;
        for(int i = 0; i <= 100; i++){
            vector<int> s(244, 0);
            int as = 0;
            for(auto j : v){
                int dd = cek(prm[i], j);
                as = max(as, ++s[dd]);
            }
            if(mx > as){
                rn = prm[i];
                mx = as;
            }
        }
    }
    ck = ask(v[0]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    for(ll i = 10000; i <= 99999; i++){
        bool cek = 0;
        for(ll j = 2; j*j <= i; j++){
            if(i%j == 0){
                cek = 1;
            }
        }
        if(!cek){
            prm.push_back(to_string(i));
        }
    }
    random_shuffle(all(prm));
    cin >> s >> n;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

