struct Hash{
    ll p, mod;
    vector<ll> H, pow;
    Hash(string& s, ll P = 79, ll MOD = 1e9+7){
        p = P;
        mod = MOD;
        pow.resize(s.size()+1);
        pow[0] = 1;
        fi(1, s.size()) pow[i] = pow[i-1] * p % mod;
        H.resize(s.size());
        H[0] = s[0];
        fi(1, s.size() - 1) H[i] = (H[i-1] * p + s[i]) % mod;
    }
    ll sub(ll l = 0, ll r = -1){
        if(r == -1) r = H.size()-1;
        ll big = H[r];
        ll small = 0;
        if(l) small = H[l-1] * pow[r - l + 1] % mod; 
        return (big - small + mod) % mod;
    }
};