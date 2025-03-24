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
set<int> bsr;
set<int> kc;
set<int> kc2;
set<int> pp;
vector<int> v;
vector<int> ss;
string s;
vector<int> bg = {59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
bool debug = 1;
int anj = 0;
map<pair<int,int>, int> mp;
ll ask(set<int> &sem, int jns){
    int idx;
    if(debug){
        if(anj > id){
            cout << "KELEBIHAN query luh" << endl;
            exit(0);
        }
        anj++;
        if(sem.size() < m || sem.size() > m){
            cout << "Kurang ? Lebih ?" << sem.size() << endl;
            exit(0);
        }
        int dd;
        if(jns){
            cout << "min ";
        }else{
            cout << "max ";
        } 
        for(auto i : sem){
            cout << i << " ";
        }
        cout << endl;
        if(jns){
            dd = INT_MAX;
            for(auto i : sem){
                if(bg[i] < dd){
                    idx = i;
                    dd = bg[i];
                }
            }
        }else{
            dd = -1;
            for(auto i : sem){
                if(bg[i] > dd){
                    idx = i;
                    dd = bg[i];
                }
            }
        }
        return idx;
    }
    cout << "?";
    if(jns){
        cout << "min ";
    }else{
        cout << "max ";
    }
    for(auto i : sem){
        cout << i << " ";
    }
    cout << endl;
    cin >> idx;
    return idx;
}
bool cmp(int a, int b){
    if(a == b) return 1;
    if(mp[{a, b}] != 0){
        return (mp[{a, b}] == 1 ? 1 : 0);
    }
    //swap(a, b);
    cout << "?min " << a << " " << b << endl;
    int jj;
    if(debug){
        if(anj > id){
            cout << "KELEBIHAN query luh" << endl;
            exit(0);
        }
        anj++;
        if(bg[a] > bg[b]){
            jj = b;
        }else{
            jj = a;
        }
    }else{
        cin >> jj;
    }
    if(jj == a){
        mp[{a, b}] = 1;
        mp[{b, a}] = -1;
        return 1;
    }else{
        mp[{b, a}] = 1;
        mp[{a, b}] = -1;
        return 0;
    }
}
void solve(){
    if(!debug)cin >> n >> m >> id;
    if(m == 2){
        for(int i = 0; i < n; i++){
            ss.push_back(i);
        }
        sort(all(ss), cmp);
        cout << "! ";
        for(auto i : ss){
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        pp.insert(i);
        if(pp.size() == m){
            int rr = ask(pp, 1);
            auto it = pp.find(rr);
            pp.erase(it);
            kc.insert(rr);
        }
    }
    bsr = pp;
    int cnt = 0;
    while(1){
        if(debug)cout << "ini udh di atas lagi" << endl;
        //bool cek = 0;
        while(bsr.size() > 1){
            pp = bsr;
            for(auto i : kc){
                if(pp.size() < m){
                    pp.insert(i);
                }else break;
            }
            if(pp.size() < m){
                for(auto i : bsr){
                    kc.insert(i);
                }
                break;
            }
            int rr = ask(pp, 0);
            v.push_back(rr);
            auto it = bsr.find(rr);
            bsr.erase(it);
        }
        if(debug)cout << "ni keluar " << endl;
        if(bsr.size() == 1){
            v.push_back(*bsr.begin());
            bsr.erase(bsr.begin());
        }
        if(kc.size() < m){
            break;
        }
        if(debug)cout << "ni mulai masuk kecil " << cnt << " " << kc.size()<< endl;
        pp.clear(); kc2.clear();
        for(auto i : kc){
            if(pp.size() < m){
                pp.insert(i);
            }
            if(pp.size() == m){
                int rr = ask(pp, 1);
                kc2.insert(rr);
                auto it = pp.find(rr);
                pp.erase(it);
            }
        }
        kc = kc2;
        bsr = pp;
        cnt++;
    }
    if(debug){
        cout << "ril -> keluar" << endl;
    for(auto i : kc){
        cout << i << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    }
    
    int idx = 0;
    pp = kc;
    while(kc.size() > 1){
        while(pp.size() < m){
            pp.insert(v[idx]);
            idx++;
        }
        int rr = ask(pp, 1);
        ss.push_back(rr);
        auto it = kc.find(rr);
        kc.erase(it);
        it = pp.find(rr);
        pp.erase(it);
    }
    if(kc.size() == 1){
        ss.push_back(*kc.begin());
    }
    reverse(all(v));
    for(int i : v){
        ss.push_back(i);
    }
    cout << "! ";
    for(auto i : ss){
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    n = bg.size(), m = 3, id = n*6+1;
    //cin >> t;
    //t = n/2+1;
    for(int i = 1; i <= t; i++){
        ss.clear(), v.clear(), bsr.clear(), kc.clear(), kc2.clear(), mp.clear();
        anj = 0;
        //cout << "Case " << i << ": ";
        solve();
    }
}

