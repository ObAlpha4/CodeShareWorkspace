#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mul(ll a, ll b, ll p) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}
ll mul2(ll a,ll b,ll p){
    a%=p,b%=p;
    ll c=(long double)a*b/p;
    ll ans=(a*b-c*p)%p;
    if(ans<0)ans+=p;
    return ans;
}

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p);
    return 0;
}