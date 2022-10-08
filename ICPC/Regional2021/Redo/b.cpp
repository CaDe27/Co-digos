#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <ccomplex>
using namespace std;
typedef int64_t ll;
typedef pair<ll,ll> pii;
#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(ll i = a; i < b; ++i)

//====== FFT
typedef long double ld;
const int maxn = 1e5 + 10;
const ld PI = acos(-1);
typedef complex<ld> base;
base wlen_pw[2*maxn];
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		ld ang = 2*PI/len * (invert ? -1 : 1);
		int len2 = len>>1;
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			for (int j=0; j<len2; ++j) {
				base u = a[i+j],  v = a[i+j+len2] * wlen_pw[j];
				a[i+j] = u + v;
				a[i+j+len2] = u - v;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
 
void multiply (const vector<int> & a, const vector<int> & b, vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i){
		res[i] = ll (fa[i].real() + 0.5 * (fa[i].real() >= 0 ? 1 : -1));
	}
}
//===END FFT
const ll maxN = 100005;
ll nm;
ll respMax[maxN], respMin[maxN];

void getMax(vector<ll> f, vector<ll> c){
    priority_queue<ll> maxHeap;
    //get positives
    ll indxTP = nm-1, indxTS=nm-1, indxBP=0, indxBS = 0;
    while(indxTP >= 0 && f[indxTP]> 0 && c[indxTS]>0)
        maxHeap.push(f[indxTP--]*c[indxTS--]);
    while(indxBP < nm && f[indxBP]< 0 && c[indxBS]<0)
        maxHeap.push(f[indxBP++]*c[indxBS++]);
    //get zeros
    //at this poll we have something like
    //     0 ... 0 0 + ... + +
    //     - ... - 0 ...   0 0
    //at end, pair them with the others biggest 
    while( indxTP >= 0 && (f[indxTP]==0 || c[indxTS]==0) )
        maxHeap.push(f[indxTP--]*c[indxTS--]);
    //at beginning, pair them with the others smallest
    while( indxBP < nm && (f[indxBP]==0 || c[indxBS]==0) )
        maxHeap.push(f[indxBP++]*c[indxBS++]);

    //get negatives
    //use fast polynomial multiplication 
    ll suma = 0;
    ll indx = 0;
    while(!maxHeap.empty()){
        suma += maxHeap.top();
        maxHeap.pop();
        respMin[indx++] = suma;
    }
    ll size = indxTP-indxBP + 1;
    if(size <= 0) return;
    vector<int> a(size), b(size); vector<ll> d(2*size); 
    if(f[indxBP] < 0){
        loop(i, 0, size){
            a[i] = f[indxTP-i];
            b[i] = c[indxBS+i];
        }
    }
    else{
        loop(i, 0, size){
            a[i] = c[indxTS-i];
            b[i] = f[indxBP+i];
        }
    }
    multiply(a,b,d);
    ll indxD = 0;
    while(indx != nm){
        respMin[indx++] = suma + d[indxD++];
    }
}
void solve(){
    cin>>nm;
    
    vector<ll> f(nm), c(nm);
    loop(i, 0, nm) cin>>f[i];
    loop(i, 0, nm) cin>>c[i];
    sort(begin(f), end(f));
    sort(begin(c), end(c));
    getMax(f, c);
    loop(i, 0, nm) respMax[i] = respMin[i];

    reverse(f.begin(), f.end());
    loop(i, 0, nm) f[i] = -f[i];
    getMax(f, c);
    loop(i, 0, nm){
        cout<<-respMin[i]<<" "<<respMax[i]<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    solve();
    return 0; 
}