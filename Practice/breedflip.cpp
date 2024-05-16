#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    for(int l = 0, r = l; l < n; l = r){
        if(s[r] == t[r]) r++; 
        else{
            while(r < n && s[r] != t[r]){
                r++;
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
}