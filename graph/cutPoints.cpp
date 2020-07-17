

ll timer = 0;
set<ll> ans;
vector< vector<ll> >g;
vector<bool> used;
vector<ll> tin, fup;

void pts(ll v, ll p = -1){
    used[v] = true;
	tin[v] = fup[v] = timer++;
	ll children = 0;
	for (ll i=0; i<g[v].size(); ++i) {
		ll to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			pts (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				ans.insert(v+1);
			++children;
		}
	}
	if (p == -1 && children > 1)
		ans.insert(v+1);
}

int main() {
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    tin.resize(n);
    fup.resize(n);
    fi(0, m-1){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    fi(0, n-1){
        if(!used[i]){
            pts(i);
        }
    }
    cout << ans.size() << endl;
    for(ll x: ans){
        cout << x << endl;
    }
    run();
}