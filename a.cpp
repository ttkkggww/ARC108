#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	ll s,p;cin >> s >> p;
	for(ll i=1;i*i<=p;i++){
		if(p%i!=0)continue;
		ll n = i,m = p/i;
		if(n+m==s){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
