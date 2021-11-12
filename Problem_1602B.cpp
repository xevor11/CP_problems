/*It can be shown that after at most n steps of transformation, array a becomes repetitive. There is even a better lower bound: it can be shown that after at most log(n) steps a becomes repetitive, so we use either of these two facts to simulate the process and answer the queries.
*/
void solve() {
  int t; // for testcases (template)
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int arr[n]; // array to store values for rows
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int v[n + 1][n]; 
    /*
    each kth transformation and resulting arr
           N
    (N + 1)
       0 -> intial array
       1 -> 1st transformation
       2 -> 2nd transformation
       3 -> 3rd transformation
       .
       .
       .
       n -> nth transformation

       Since we are only interested till the nth step anything after that is identical to the resulting
       array in the nth step so we ignore it
    */
    for(int i = 0; i < n; i++) { // this loop iterates till nth step
      v[0][i] = arr[i]; // intial state, stores resulting array after nth step
    }
    for(int i = 1; i <= n; i++) { // this startes iteration after inital step
      map <int, int> m; // a map data structure to store element (key) -> frequency of element (value)
      for(int i = 0; i < n; i++) {
        m[arr[i]]++; // increments occurences of each element
        for(int j = 0; j < n; j++) {
          arr[j] = m[arr[j]]; // replaces position of each element with its frequency
          v[i][j] = arr[j]; // for each row and column replacing position of each element with its frequency
          // v[i] stores the frequency after the ith step
        }
      }
    }
    int q; // # queries
    while(q--) { // loops till # queries == 0, or q != 0 is the condition
      int x, k; // variables to store ax position of the element in the array after kth transformation
      cin >> x >> k; // first take input of x then k
      x--; // since the x is in base-1 so decrement to base-0 (indexing)
      if(k <= n) {
        cout << v[k][x] << endl; // since we're interested in kth transformation till nth step so we return resulting
        // array after kth == nth
      } else {
        cout << v[n][x] << endl;
        // if k > n then we return state of array at nth step, at n + 1 is recurring
      }
    }
  }
}
 
int main() {
#ifdef vedant_tewari
	freopen("Error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef vedant_tewari
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}

//Alternate Solutions:

/*

Solution 1:

void AIput(LL x,int c) {putnum(x);putchar(c);}
 
int n,m,s,o,k;
char ss[MAXN];
int a[MAXN],b[MAXN][MAXN],cn,c[MAXN];
bool cg(int *a,int *b) {
	for(int i = 1;i <= n;i ++) c[i] = 0;
	for(int i = 1;i <= n;i ++) c[a[i]] ++;
	bool flag = 0;
	for(int i = 1;i <= n;i ++) {
		b[i] = c[a[i]];
		if(b[i] != a[i]) flag = 1;
//		printf("%d ",b[i]);
	}
//	ENDL;
	return flag;
}
int main() {
	int T = read();
	while(T --) {
		n = read();
		for(int i = 1;i <= n;i ++) {
			b[0][i] = read();
		}
		cn = 0;
		while(cg(b[cn],b[cn + 1])) cn ++;
		m = read();
		while(m --) {
			s = read();o = read();
			o = min(o,cn);
			AIput(b[o][s],'\n');
		}
	}
	return 0;
}


Solution 2 (Similar implementation):

void Solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> a(1, vector<ll>(n));
  copy_n(istream_iterator<ll>(cin), n, begin(a.front()));
 
  vector<ll> next = a.front();
  while (next == a.back()) {
    unordered_map<ll, ll, custom_hash> m;
    for (auto x : a.back()) {
      m.try_emplace(x, 0);
      ++m[x];
    }
 
    for (int i = 0; i < n; ++i) {
      next[i] = m[a.back()[i]];
    }
    if (next != a.back()) {
      a.push_back(next);
    } else {
      break;
    }
  }
 
  ll queries;
  cin >> queries;
 
  ll index, step;
  while (queries--) {
    cin >> index >> step;
    step = min(step, (ll)a.size() - 1LL);
    cout << a[step][index - 1] << '\n';
  }
}

Solution 3 (Similar implementation) :

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, n, i, j, ans, temp, sum, q;
    string sans;
    t = 1;
    cin >> t;
    while (t--)
    {
        sans = "NO";
        ans = temp = sum = 0;
        cin >> n;
        vector<vll>a(n + 3, vll(n + 1, 0));
        fo(i, 1, n)
        {
            cin >> a[0][i];
        }
        fo(i, 1, n + 2)
        {
            vll cnt(n + 1, 0);
            fo(j, 1, n)cnt[a[i - 1][j]]++;
            fo(j, 1, n)a[i][j] = cnt[a[i - 1][j]];
        }
        cin >> q;
        while (q--)
        {
            ll x, k;
            cin >> x >> k;
            if (k > n + 2)k = n + 2;
            cout << a[k][x] << "\n";
        }
    }
    return 0;
}

Solution 4 (using vector) :

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
 
        vector<vector<int> > mat(1, arr);
        vector<int>last = arr;
        while (1)
        {
            vector<int> neww(n);
 
            map<int, int> occur;
            for (int i = 0; i < n; i++)
                occur[last[i]]++;
            for (int i = 0; i < n; i++)
                neww[i] = occur[last[i]];
 
            if (neww == last)
                break;
            mat.push_back(neww);
            last = neww;
        }
 
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int gen, ind;
            cin >> ind >> gen;
            if (gen >= mat.size())
                gen = mat.size() - 1;
 
            cout << mat[gen][ind - 1] << endl;
        }
    }
}

Solution 5 (using vector and map):


void solve(){
   ll n ; cin >> n;
   vector<vector<ll>> v;
    // no change then we stop
    vector<ll> vv;
 for(ll i=0;i< n;i++) { ll m; cin >> m ;
   vv.push_back(m) ; }
   v.push_back(vv) ;
 
   for(ll i=1;i<=n;i++){ 
     map<ll,ll> mp ;
     vector<ll> vs = v[i-1] ;
     for(auto dd : vs) { mp[dd]++;}
     vector<ll> vn ;
     
     for(auto dd : vs){
           ll cc = mp[dd] ;
           
          vn.push_back(cc) ;
     }
     v.push_back(vn) ;
   }
 
   ll q ; cin >> q ;
   while(q--){
        ll x, k ; cin >> x >> k ;
        if(k<=n){  cout << v[k][x-1] << endl;}
        else { cout << v[n][x-1] << endl;}
   }
  
  }
 
 
 
int main(){ 
  
ios_base::sync_with_stdio(false) ;
cin.tie(NULL) ; cout.tie(NULL) ;
  
 
ll t; cin >> t ;
 
for(ll i=0 ;i< t ;i++){
     solve() ;
 
}
 
}

Solution 6 (identical except vector instead of 2D array):


void solve() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    vector<int> v[n + 1];
    v[0] = a;
    for (int k = 1; k <= n; k++) {
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }
 
        for (int i = 0; i < n; i++) {
            a[i] = freq[a[i]];
        }
 
        v[k] = a;
    }
 
    int q;
    cin >> q;
 
    while (q--) {
        int x, k;
        cin >> x >> k;
 
        if (k > n) {
            cout << v[n][x - 1] << nl;
        } else {
            cout << v[k][x - 1] << nl;
        }
    }
}


*/
