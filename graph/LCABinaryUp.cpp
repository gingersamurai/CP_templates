
ll n, l, timer = 0;
vector<vector<ll>> g, up;
vector<ll> tin, tout;

void dfs(ll v, ll p = 0){
    tin[v] = timer++;
    up[v][0] = p;
    for(ll to: g[v]){
        if(to != p){
            dfs(to, v);
        }
    }
    tout[v] = timer++;
}

bool isPrev(ll a, ll b){
    return(tin[a] <= tin[b] && tout[a] >= tout[b]);
}

ll lca(ll a, ll b){
    if(isPrev(a, b)) return a;
    if(isPrev(b, a)) return b;
    fim(l, 0){
        if(!isPrev(up[a][i], b)){
            a = up[a][i];
        }
    }
    return up[a][0];
}

int main() {
    cin >> n;
    ll m;
    cin >> m;
    g.resize(n);
    tin.resize(n);
    tout.resize(n);
    while(1<<l <= n) l++;
    up.resize(n, vector<ll> (l+1));
    fi(1, n-1){
        ll x, y;
        cin >> x >> ys;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    fi(1, l){
        fj(0, n-1){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
    fi(1, m){
        ll x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
}