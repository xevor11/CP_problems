/*It can be shown that after at most n steps of transformation, array a becomes repetitive. There is even a better lower bound: it can be shown that after at most log(n) steps a becomes repetitive, so we use either of these two facts to simulate the process and answer the queries.
*/
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, a;
    cin >> n;
    deque<int> d;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (d.empty() || a < d[0]) {
        d.push_front(a);
      }
      else {
        d.push_back(a);
      }
    }
    for (int x : d) {
      cout << x << ' ';
    }
    cout << '\n';
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
Solution 2:

We'll process the permutation elements one by one.

For the first element, it doesn't matter which side of the deque we add it to, the result of its addition will be the same — there will be a sequence of one element (equal to the first permutation element) in the deque.

Now let's consider adding the i-th element of a permutation to the deque. First i=2 will be considered, then i=3, and so on up to i=n. Let us describe the general algorithm for choosing the side of the deque for each step. Note that if the elements [d1,…,di−1] are now in the deque, then all final permutations that can be obtained in the deque from the current state can be broken down into pairs of the form
[…,ai,d1,…,di−1,…]
[…,d1,…,di−1,ai,…],
where the beginning and the end of the final permutations, hidden behind "…", are obtained by the same sequences of all the following choices and thus are equal between the first and the second.

Note that when ai<d1 the first permutation will always be lexicographically smaller than the second one, and vice versa. Therefore, regardless of the following choices, if ai<d1 then the second permutation will never be minimal, and if ai>d1 then the first permutation will never be minimal.

This means that we can make a choice about the side of the deque to add the i-th element to based only on its relation to d1: if ai<d1, then ai is added to the beginning of the deque, otherwise — to the end.

The time complexity is O(n). Alternative solutions, which also fit in the time limit, involved finding a lexicographically minimal increasing sequence in the reversed original permutation and could be implemented either with O(nlogn) time complexity or with O(n) time complexity if the permutation's definition was taken into consideration.


#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; // for testcases (template)
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int temp[n];
    for(int i = 0; i < n; i++) {
      cin >> temp[i];
    }
    deque<int> size;
    for(int i = 0; i < n; i++ {
      if(dq.size() == 0) {
        size.push_back(temp[i]);
      }
      else {
        if(temp[i] < size.front()) {
          size.push_front(temp[i]);
        }
        else {
          size.push_back(temp[i]);
        }
      }
    }
    for(auto x : size) {
      cout << x << "";
    }
  }
}

Solution 3 (Similar implementation):

void solve() {
    ll n;
    cin >> n;
    ll tmp;
    deque<ll> q;
    cin >> tmp;
    q.push_back(tmp);
    for(int i = 1; i < n; i++) {
        cin >> tmp;
        if(tmp < q.front()) q.push_front(tmp);
        else q.push_back(tmp);
    }
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop_front();
    }
    cout << '\n';
}

*/
