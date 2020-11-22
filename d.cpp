#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;

ll g(ll x){
	int ret = 1;
	for(int i = 0;i<x;i++){
		(ret*=2)%=MOD;
	}
	return ret;
}

ll f(ll x){
	ll ret;
	ll ret_1 = 1;
	ll ret_2 = 1;
	for(int i = 0;i<x-1;i++){
		(ret = ret_1 + ret_2)%=MOD;
		ret_2 = ret_1;
		ret_1 = ret;
	}
	return ret;
}
int main()
{
	int n;cin >> n;
	char c[4];
	for(int i = 0;i<4;i++)cin >> c[i];
	if(n<4){
	cout<<1<<endl;
	return 0;
	}
	ll ans;
	if(     c[0]=='A'&&c[1]=='A')                      ans=1;
	else if(           c[1]=='B'&&           c[3]=='B')ans=1;
	else if(           c[1]=='B'&&c[2]=='A'&&c[3]=='A')ans = g(n-3);
	else if(c[0]=='B'&&c[1]=='A'&&c[2]=='B')           ans = g(n-3);
	else if(           c[1]=='B'&&c[2]=='B'&&c[3]=='A')ans = f(n-2);
	else if(c[0]=='B'&&c[1]=='A'&&c[2]=='A')           ans = f(n-2);
	cout<<ans<<endl;
}
