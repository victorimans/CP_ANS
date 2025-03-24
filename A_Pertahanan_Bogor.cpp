#include <bits/stdc++.h>
using namespace std;
int read() {
    int ketek = 0; bool ne=0;
    register char c = getchar();
    while(c == ' ' or c =='\n') c =getchar();
    if(c=='-'){ne = 1; c = getchar();}
    while(c >= '0' and c <='9') { ketek = (ketek<<3)+(ketek<<1)+c-'0'; c = getchar();}
    if(ne) ketek*=-1;
    return ketek;
}   
int dp[200002], poin[200002], id, n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    n = read();
    for(int i = 1; i <= n; i++){
        id = read();
        if(i-id >= 0){
            poin[i-id+1]++;
            dp[i] = max(dp[i], dp[i-id] + poin[i-id+1]);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    printf("%d", n-dp[n]);
}

