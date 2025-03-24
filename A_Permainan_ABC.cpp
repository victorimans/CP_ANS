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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int fibo[44], id;
    fibo[0] = 1;
    fibo[1] = 2;
    for(int i = 2; i < 44; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        if(fibo[i] > 1e9){
            id = i;
            break;
        }
    }
    //cout << id;
    int t;
    t = read();
    for(int i = 1; i < id; i++){
        if(t % fibo[i] == 0){
            printf("%d", t/fibo[i]*fibo[i-1]);
            return 0;
        }
    }
    printf("-1");
}

