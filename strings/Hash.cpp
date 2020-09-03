ll add(ll a, ll b, ll mod) {
    return (mod * mod + a + b) % mod;
}
 
ll mul(ll a, ll b, ll mod) {
    return (a * b) % mod;
}

struct Hash{
    ll p, mod;
    vector<ll> H, pow;
    Hash(string& s, ll P = 79, ll MOD = 1e9+21){
        ll n = s.size();
        p = P;
        mod = MOD;
        pow.resize(n+1, 1);
        fi(0, n-1) pow[i+1] = mul(pow[i], p, mod);
        H.resize(n);
        H[0] = s[0]-'0';
        // fi(1, n-1) H[i] = add(mul(H[i-1], p, mod), (ll)s[i]-'a', mod);
        for (ll i = 0; i < n-1; ++i) {
            ll c = (ll)s[i+1] - '0';
            H[i + 1] = add(mul(H[i], p, mod), c, mod);
        }
    }
    ll sub(ll l = 0, ll r = -1){ 
        if(r == -1) return H.back();
        if(l == 0) return H[r];
        return add(H[r], -mul(H[l-1], pow[r-l+1], mod), mod);
    }
};