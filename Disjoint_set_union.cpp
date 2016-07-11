//Problem : https://code.google.com/codejam/contest/32017/dashboard#s=p1&a=2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t, i, j, k, low, a, b, vis[1000010], cnt, ans, _t, p, flag;
set<ll> st;
vector<ll> primes;
ll parent[1000010], rnk[1000010];
void init(ll n) {
    for(ll i = 0; i < n; i++) {
        rnk[i] = 0;
        parent[i] = -1;
    }
}
ll _find(ll vertex) {
    if(parent[vertex] == -1) return vertex;
    else {
        ll store = _find(parent[vertex]);
        parent[vertex] = store;
        return store;
    }
}
void join(ll a, ll b) {
    ll ap, bp;
    ap = _find(a);
    bp = _find(b);
    if(ap == bp) return;
    if(rnk[ap] > rnk[bp]) parent[bp] = ap;
    else if(rnk[bp] > rnk[ap]) parent[ap] = bp;
    else {
        parent[bp] = ap;
        rnk[ap]++;
    }
}
int main() {
    cin>>t;
    memset(vis, 0, sizeof vis);
    for(i = 2; i < 1e6+6; i++) {
        if(!vis[i]) {
            primes.push_back(i);
            for(j = i; j < 1e6+6; j += i) {
                vis[j] = 1;
            }
        }
    }
    for(_t = 1; _t <= t; _t++) {
        cin>>a>>b>>p;
        ll n = b-a+1;
        init(n);
        for(i = 0; i < primes.size(); i++) {
            if(primes[i] < p) continue;
            low = (a/primes[i])*primes[i];
            if(low < a) low += primes[i];
            for(j = low; j <= b; j += primes[i]) {
                if(j >= a && j <= b) {
                    if(j + primes[i] <= b) {
                        join(j-a, j-a+primes[i]);
                    }
                }
            }
        }
        cnt = 0;
        for(i = a; i <= b; i++) {
            if(parent[i-a] == -1) {
                cnt++;
            }
        }
        printf("Case #%lld: %lld\n", _t, cnt);
    }

    return 0;
}


