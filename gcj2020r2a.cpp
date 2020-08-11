#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    long long L, R;
    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> L >> R;
        long long i;
        long long l, m, r, s, d;
	long long M = floor(sqrt(2*(L+R)));
	long long ans;
	l = 1;
	r = M;
	d = L-R;
	if (R>L) {
	    d = R-L;
	}

	while (l<=r) {
	    i = l + (r-l)/2;
	    s = (i+1)*i/2;
	    if (s<=d && d-s<=i) {
	    	break;
	    } else if (s > d) {
		r = i-1;
	    } else {
		l = i+1;
	    }
	}
	ans = i;
	if (L>=R) {
	    L -= s;
	} else {
	    R -= s;
	}
	d = L;
	if (L<R) d = R;

	if (d>=i+1) {
		l = 1;
		r = M;
		while (l<=r) {
		    m = l + (r-l)/2;
		    s = (i+m)*m;
		    if (s<=d && d-s<i+2*m+1) {
			break;
		    } else if (s>d) {
			r = m-1;
		    } else {
			l = m+1;
		    }
		}
		ans += m;
		if (L>=R) {
		    L -= s;
		} else {
		    R -= s;
		}
		d = L;
		if (L<R) d = R;
	}

	if (d>=i+2) {
		l = 1;
		r = M;
		while (l<=r) {
		    m = l + (r-l)/2;
		    s = (i+m+1)*m;
		    if (s<=d && d-s<i+2*m+2) {
			break;
		    } else if (s>d) {
			r = m-1;
		    } else {
			l = m+1;
		    }
		}
		ans += m;
		if (L>=R) {
		    L -= s;
		} else {
		    R -= s;
		}
	
	}

        cout << "Case #" << t+1 << ": " 
            << ans << " " << L << " " << R << endl;
    }

    return 0;
}
