#include <bits/stdc++.h> 

using namespace std;

#define deb(x) cout << #x << " = " << x << endl;
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define rep(i,j,k) for(int i=j;i<k;i++)
#define sz(x) (int)(x).size()

#define imax INT_MAX
#define imin INT_MIN
#define PI 3.1415926535897932384626433832795
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define sortall(x) sort(all(x))

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;

template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

void setIO(string name){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(!name.empty()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
#define here cout << "-----PASS-----" << endl;
const int mxN = 1e5+5;
const int MOD = 998244353;
const int INF = 2e9+50;

//*********************************************************************************

string ask(int q) {
    cout << q << endl;
    fflush(stdout);
    string s; cin >> s;
    //if(s=="!!!!!") exit(0);
    return s;
}

int cek(int a, int b) { // a =10007 -> b = 99991, ?----  - -> 0  ? -> 1  + -> 2
    // from a to b
    int ret = 0;
    VI ar1, ar2;
    while(a>0) {
        ar1.pb(a%10);
        a/=10;
    } 
    reverse(all(ar1));
    while(b>0) {
        ar2.pb(b%10); 
        b/=10;
    }
    reverse(all(ar2));
//
    //for(int a : ar1) cout << a << " "; cout << endl;
    //for(int a : ar2) cout << a << " "; cout << endl;
    int pow = 1;
    for(int i=0;i<5;i++) {
        if(ar1[i]==ar2[i]) {
            //cout << i << " " << pow << endl;
            ar1[i] = -1;
            ar2[i] = -1;
            ret+=2*pow;
            
        }
        pow*=3;
    }
    pow = 1;
    //cout << ret << endl;
    for(int i=0;i<5;i++) {
        
        for(int j=0;j<5;j++) {
            if(ar1[i]==-1) continue;
            if(ar1[i]==ar2[j]) {
                ar1[i] = -1;
                ar2[j] = -1;
                ret+=1*pow;
            }
        }
        pow*=3;
    }
    return ret;
}
vector<int> primes;
void solve(){
    vector<int> candidate = {-1,-1};

    int a = 62791;
    while(candidate.size()>1) {
        string s = ask(a);
        if(s=="+++++") return;
        int p = 0; // p = hasil response
        int pow = 1;
        for(int i=0;i<5;i++) {
            int inc = 0;
            if(s[i]=='+') inc=2;
            if(s[i]=='?') inc=1;
            p += inc*pow;
            pow*=3;
        }
        vector<int> tmp;

        if(candidate[0]==-1) {
            for(int b : primes) {
                if(cek(a,b)==p)tmp.pb(b);
            }
        }else{
            for(int b : candidate) {
                if(cek(a, b) == p) tmp.pb(b);
            }
        }

        candidate = tmp;
        
        int mn=INF, id;
        for(int i=0;i<=100;i++) {
            int c = primes[i]; // random karena primes udah di random shuffle :>
            int mx = 0 ;
            VI freq = VI(244, 0);
            for(int b : candidate) {
                int now = cek(c,b);

                mx = max(mx, ++freq[now]);
            }
            if(mn > mx) {
                mn = mx;
                id = c;
            }
        }
        
        a = id;
    }
    ask(candidate[0]);

}

int32_t main(){
    string name = "";
    setIO(name);
    int test_cases = 1;
    string dummy;
    for(int i=10000;i<=99999;i++) {
        bool tes = 1;
        for(int j=2;j*j<=i;j++) {
            if(i%j==0) tes = 0;
        }
        if(tes){
            primes.pb(i);
        }
    }
    random_shuffle(all(primes));
    cin >> dummy >> test_cases >> test_cases;

    
    while(test_cases--) {
        solve(); //cout << endl;
    }
    exit(0);

    return 0; 
}