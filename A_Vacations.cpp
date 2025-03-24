#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;  
const int ukr = 2e5+2;
ll n, m, id, a, b, tot=0;
vector<int> v;
int dp[101][2][2];
int rec(int rn, int gym, int cp){
    if(rn == n){
        return 0;
    }
    if(dp[rn][gym][cp] != -1) return dp[rn][gym][cp];
    int tot = ukr;
    if(v[rn] == 0){
        tot = rec(rn+1, 0, 0) + 1;
    }else if(v[rn] == 1){
        int op1 = ukr, op2 = ukr;
        if(!cp){
            op1 = rec(rn+1, 0, 1);
        }
        op2 = rec(rn+1, 0, 0) + 1;
        tot = min(op1, op2);
    }else if(v[rn] == 2){
        int op1 = ukr, op2 = ukr;
        if(!gym){
            op1 = rec(rn+1, 1, 0);
        }
        op2 = rec(rn+1, 0, 0) + 1;
        tot = min(op1, op2);
    }else{
        int op1 = ukr, op2 = ukr, op3 = ukr;
        if(!cp){
            op1 = rec(rn+1, 0, 1);
        }
        if(!gym)
        op2 = rec(rn+1, 1, 0);
        op3 = rec(rn+1, 0, 0) + 1;
        tot = min(op1, op2);
    }
    return dp[rn][gym][cp] = tot;
}
void solve(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i < n; i++){
        cin >> m;
        v.push_back(m);
    }
    cout << rec(0, 0, 0) << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}