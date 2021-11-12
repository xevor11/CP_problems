/*It can be shown that after at most n steps of transformation, array a becomes repetitive. There is even a better lower bound: it can be shown that after at most log(n) steps a becomes repetitive, so we use either of these two facts to simulate the process and answer the queries.
*/
void solve() {
  int t;
  cin >> t;
  while(t--) {
    string a, b;
    cin >> a >> b;
    int arr[26];
    for(int i = 0; i < 26; i++) {
        arr[a[i] - 'a'] = i;
    }
    int result = 0;
    int size = (int) b.length();
    for(int i = 1; i < size; i++) {
        result += abs(arr[b[i] - 'a'] - arr[b[i - 1] - 'a']); 
    }
    cout << result << endl;
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

/*
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cout.precision(1000);
    int n;
    cin >> n;
    while(n--)
    {
        string s, ss;
        int ans = 0;
        cin >> ss >> s;
        map<char, int> map;
        for(int i = 0;i < ss.size();i++)
        {
            map[ss[i]] = i;
        }
        for(int i = 1;i < s.size();i++)
        {
            ans += abs(map[s[i]] - map[s[i - 1]]);
        }
        cout << ans << endl;
    }
}

int main() {
	int t; cin >> t;
	while(t--){
		string a; int x=0;
		map<char, int> z;
		cin >> a;
		for(int i=0; i<(int)a.length(); i++){
			z.insert(pair<char, int> (a[i], i+1));
		}
		string b; cin >> b;
		for(int i=0; i<(int)b.length()-1; i++){
			auto n = z.find(b[i]);
			auto m = z.find(b[i+1]);
			x+= abs((n->second)-(m->second));
		}
		cout << x << endl;
	}	
}

#include "bits/stdc++.h"
 
using namespace std;
 
string keyboard, s;
map < char, int > pos;
 
int main() {
    int t;
    scanf("%d", &t);
    while( t-- ) {
        cin >> keyboard;
        cin >> s;
        pos.clear();
        int tm = 0;
        for(int i = 0 ; i < 26 ; i++) {
            pos[keyboard[i]] = i + 1;
        }
        int sz = (int)s.length();
        for(int i = 1 ; i < sz ; i++) {
            tm += abs(pos[s[i]] - pos[s[i - 1]]);
        }
        printf("%d\n", tm);
    }
    return 0;
}
*/
