#include <fstream>


void modify(int p, int &value, int*t, int&n) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r, const int*t, int&n) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    std::string line;
    std::ifstream in("sum.in");
    std::ifstream out("sum.out");
    int n, k;
    in.close();
    in>>n>>k;
    int t[2*n+1];
    for (int i = 0; i < 2*n+1; ++i) {
        t[i]=0;
    }
    for (int i = 0; i < k; ++i) {
        char choice;
        int a, b;
        std::cin>>choice>>a>>b;
        switch (choice) {
            case 'A':{
                modify(a, b, t, n);
                continue;
            }
            case 'Q':{
                std::cout<<query(a, b+1, t, n)<<"\n";
                continue;
            }
        }
    }
    return 0;
}