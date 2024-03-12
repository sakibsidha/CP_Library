#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int gpf[N+1], lpf[N+1], divsum[N+1], divcount[N+1],
    dist_pf[N+1], tot_pf[N+1];
bool prime[N+1];

void sieve(){
    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; j += i){
            divcount[j]++;
            divsum[j] += i;
        }
    }
}

void another_sieve(){
    for(int i = 2; i*i <= N; ++i){
        if(prime[i] == false){
            gpf[i] = i;
            lpf[i] = i;
            for(int j = 2*i; j <= N; j += i){
                if(prime[j] == true){
                    gpf[j] = i;
                }
                else{
                    gpf[j] = i;
                    lpf[j] = i;
                    prime[j] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    another_sieve();
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        cout << lpf[x] << " " << gpf[x] << " " << 0 <<
            " " << 0 << " " << divcount[x] << " " << divsum[x] << "\n";
    }
    for(int i = 2; i <= 10; ++i){
        cout << lpf[i] << "\n";
    }
    
}
