#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define vi vector<int>
#define vll vector<LL>
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define fr first
#define sc second
#define MAX 50010
#define LL   long long int
#define ll   long long int
//#define LLL long long int
#define inf 1ll<<62
#define INF 1000000
#define mod 1000000007
#define PI acos(-1)
#define pi acos(-1)
#define NN 50003
#define mMax 100010
#define nMax 200
#define MAXN 200010
#define maxN 1<<18
#define SZ(a) a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep1(i,b) for(int i=1;i<=b;i++)
#define rep2(i,b) for(int i=0;i<b;i++)
#define REP(i,b) for(int i=0;i<b;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define all(A) A.begin(),A.end()
#define isf(a) scanf("%d",&a);
#define Lsf(a) scanf("%I64d",&a);
#define lsf(a) scanf("%lld",&a);
#define csf(a) scanf("%c",&a);
using namespace std;
#define LSOne(S) (S & (-S))
#define EPS 1e-12
#define B (1<<7)
int dp[B+1][10005];
void prec(int n)
{
  //there is a pattern for every n = 1<<k where k>1 and n=(r-l)
  //k=2, ncr%2, 10001
  //k=3, ncr%2, 100000001
  //Pattern:
  // Let, B=1<<2
  // Now ,
  // For n=1*B , 10001000000000000
  // For n=2*B , 10000000100000000
  // For n=3*B , 10001000100010000
  // For n=4*B , 10000000000000001
  // See, we can find n=3*B with the help of n=2*B, as follows
  for(int i=1;i*B < n;i++)
    for(int j=0;j+ i*B <n;j++)
      dp[i][j]=dp[i-1][j]^dp[i-1][j+B];
  return;
}
int calc(int l,int r)
{
  // for any query we first break them into some block of size k*B, since we know answer for size of k*B.
  // then we brute force the answer usinf ncr%2
  int m=r-l; //not r-l+1 
  int p=m/B;
  int q=m%B;
  int ret=0;
  //cout<<m%B<<endl;
  for(int i=0;i<=q;i++){
      if((i&q)==i) // from lucas theorem , for any bit if n is 0 but r is 1 then nCr%2 = 0
        ret^=dp[p][l+i];}
  return ret;
}
int main()
{
  int T,I=1;
  cin>>T;
  while(T--)
  {
    printf("Case %d:\n",I++);
    int n,q;
    scanf("%d",&n);
    rep2(i,n) scanf("%d",&dp[0][i]);
    prec(n);
    scanf("%d",&q);
    while(q--)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      printf("%d\n",calc(a,b));
    }
  }
  return 0;
}
