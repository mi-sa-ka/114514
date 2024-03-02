#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1000005;
int n,T;
int a[maxn];

signed main()
{
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld",&n);
        for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
        int p=1,q=1,x=0,flag=0;
        for(int i=1;i<=n;++i) {
            if(a[i]==1) {p++; q++;}
            else if(a[i]==-1) {
                if(q>1) q--;
                else if(x==0) {
                    flag=1;
                    puts("-1");
                    break;
                }
                else {
                    p++;
                    x--;
                }
            }
            else ++x;
        }
        if(flag) continue;
        if(x<=q-1) q-=x;
        else {
            x-=(q-1);
            q=1;
            p+=x/2;
            q+=(x&1);
            p+=(x&1);
        }
        int g=__gcd(p,q);
        printf("%lld %lld\n",p/g,q/g);
    }


    return 0;
}
