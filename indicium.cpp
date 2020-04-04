#include<bits/stdc++.h>

#include<algorithm>

using namespace std;

#define ll          long long

#define double      long double

#define endl        '\n'

#define sz(x)       (int)(x).size()





#define pb          push_back

#define pf          push_front

#define lb(v,n)     lower_bound(all((v)),(n))

#define ub(v,n)     upper_bound(all((v)),(n))

        

#define vi          vector<int>

#define vii         vector<pii>

#define viiii       vector<pair<pii,pii>>

        

#define mi          map<int,int>

#define mii         map<pii,int>

        

#define pii         pair<int,int>

#define piii        pair<int,pair<int,int> >

#define piiii       pair<pii,pii>

#define fi          first

#define se          second

#define mp          make_pair

#define all(a)      (a).begin(),(a).end()

#define rall(a)     (a).rbegin(),(a).rend()

        

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))

#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))

#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))

#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))

#define toit ios::sync_with_stdio(0);cin.tie(0);     



int gcd(int a, int b) {  if (b == 0)  return a; return gcd(b , a % b); }

bool mod(double a,double b) {return a/b - floor(a/b);}

        

int occurs(vi v,int n){

auto it=lb(v,n);auto it1=ub(v,n);int x=it1-it;return x;}

        

double max(double a,double b){

    return a<b ? b:a;

}


const int N = 51;
int n,k;
int mat[N][N];



bool nxtpos(int &row, int &col)
{

    for (row = 0; row < n; row++)

        for (col = 0; col < n; col++)

            if (mat[row][col] == -1)

                return true;

    return false;

}

bool val(int x, int y, int num)
{
    rep(i,n){

        if(mat[i][y] == num)

            return false;
    }
    rep(i,n){

        if(mat[x][i] == num)

            return false;

    }

    return true;

}

bool rec(){

    int x,y;

    if(!nxtpos(x,y))

        return true;
    for(int i=1;i<=n;i++){
        if(val(x,y,i)){
            mat[x][y] = i;
            if(rec()){
                return true;
            }
            mat[x][y] = -1;
        }

    }

    return false;
}
int main()
{
    int t;
    cin>>t;
    int tc=0;
    while(t--){

        tc++;

        cin>>n>>k;

        if(n == 1){

            cout<<"Case #"<<tc<<": "<<"POSSIBLE"<<endl;

            cout<<1<<endl;

            continue;

        }

        if(k == n+1 || k == n*n-1){

            cout<<"Case #"<<tc<<": "<<"IMPOSSIBLE"<<endl;

            continue;

        }

        memset(mat,-1,sizeof mat);

        rep(i,n){

            mat[i][i] = k/n;

        }

        int t1 = k%n;

        int i1=0;

        while(t1--){

            mat[i1][i1]++;

            i1++;

        }

        if((k%n == 1) || (k%n == n-1)){

            mat[n/2][n/2]++;

            mat[n/2-1][n/2-1]--;

        }

        if(rec()){

            cout<<"Case #"<<tc<<": "<<"POSSIBLE"<<endl;

            rep(i,n){

                rep(j,n){

                    cout<<mat[i][j]<<" ";

                }cout<<endl;

            }

        }else{

            cout<<"Case #"<<tc<<": "<<"IMPOSSIBLE"<<endl;
        }
    }

    return 0;

}

