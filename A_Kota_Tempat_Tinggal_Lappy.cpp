#include <bits/stdc++.h>
using namespace std;
vector<int> v;
string s;
int ar[1501];
int m;
void initialize(int n){
    memset(ar, 0, sizeof(ar));
    m = n;
} 
int hasEdge(int u, int v){
    /* int rn =  max(u, v);
    ar[rn]++;
    return ar[rn] == rn; */
    ar[u]++;
    ar[v]++;
    if(ar[u] == m-1 || ar[v] == m-1){
        return 1;
    }
    return 0;
}
/* int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();x
    }
} */

