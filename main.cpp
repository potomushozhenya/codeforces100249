#include <fstream>


void modify(int p, long long &value, long long*t, int&n) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

long long query(int l, long long r, const long long*t, int&n) {  // sum on interval [l, r)
    long long res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    std::ifstream in("sum.in");
    std::ofstream out("sum.out");
    int n, k;
    in>>n>>k;
    long long t[2*n+1];
    for (int i = 0; i < 2*n+1; ++i) {
        t[i]=0;
    }
    for (int i = 0; i < k; ++i) {
        char choice;
        int a;
        long long b;
        in>>choice>>a>>b;
        switch (choice) {
            case 'A':{
                modify(a, b, t, n);
                continue;
            }
            case 'Q':{
                out<<query(a, b+1, t, n)<<'\n';
                continue;
            }
        }
    }
    in.close();
    out.close();
    return 0;
}