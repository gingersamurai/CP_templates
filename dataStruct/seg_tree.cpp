ll MAXV = 1e5 + 123;
ll n;
vector<ll>t(4*MAXV), a(4*MAXV);
 
ll left_son(ll v){ return 2 * v + 1; };
ll right_son(ll v){ return 2 * v + 2; };
 
void push(ll v, ll L, ll R){ 
    t[v] += a[v] * (R - L);
    a[left_son(v)] += a[v];
    a[right_son(v)] += a[v];
    a[v] = 0;
}
 
void relax(ll v, ll L, ll M, ll R){
    t[v] = t[left_son(v)] +  a[left_son(v)] * (M - L) +
           t[right_son(v)] + a[right_son(v)] * (R - M);
}
 
void build(vector<ll>& base, ll v = 0, ll L = 0, ll R = n){
    // cout << L << " " << R << endl; 
    a[v] = 0;
    if(R - L == 1){
        t[v] = base[L];
        return; 
    }
    ll M = (L + R) / 2;
    build(base, left_son(v), L, M);
    build(base, right_son(v), M, R);
    relax(v, L, M, R);
    return;
}
 
void add(ll l, ll r, ll h, ll v = 0, ll L = 0, ll R = n){
    // cout << L << " " << R << endl;
    if( L >= l && R <= r){
        a[v] += h;
        return;
    }
    else if(L >= r || R <= l){
        return;
    }
    push(v, L, R);
    ll M = (L + R)/2;
    add(l, r, h, left_son(v), L, M);
    add(l, r, h, right_son(v), M, R);
    relax(v, L, M, R);
}
 
ll sum(ll l, ll r, ll v = 0, ll L = 0, ll R = n){
    // cout << L << " " << R << endl;
    if(L >= l && R <= r) {
        return t[v] + a[v] * (R-L);
    }
    if(L >= r || R <= l){
        return 0;
    }
    push(v, L, R);
    ll M = (L+R)/2;
    ll ans = sum(l, r, left_son(v), L, M) + sum(l, r, right_son(v), M, R);
    relax(v, L, M, R);
    return ans;
}
 
void print_tree(ll agg = 0, ll v = 0, ll L = 0, ll R = n){
    agg += a[v];
    if(R - L == 1){
        cout << L <<": " << t[v] + agg << endl;
        return;
    }
    ll M =(L+R)/2;
    print_tree(agg, left_son(v), L, M);
    print_tree(agg, right_son(v), M, R);
}
 
int main() {
    cin >> n;
    n++;
    vector<ll> base(n, 0);
    build(base);
    ll q;
    cin >> q;
    fi(0, q-1){
        char c;
        cin >> c;
        if(c == '1'){
            ll l, r, h;
            cin >> l >> r >> h;
            add(l, r, h);
        } else if (c == '2'){
            ll l, r;
            cin >> l >> r;
            cout << sum(l, r) << endl;
        }
        // print_tree();
        // cout << endl;
    }
    run();
}