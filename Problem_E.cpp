#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////
#define db1(x)                cout<<#x<<": "<<x<<"\n"
#define db2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n"
#define db3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n"
#define db4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n"
////////////////////////////////////////////////////////////////////////////////////////
#define ll long long
#define ld long double
#define setbits(x)      __builtin_popcountll(x)
///////////////////////////////////////////////////////////////////////////////////////
#define bhaag_basanti ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///////////////////////////////////////////////////////////////////////////////////////
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sp(x,y)         fixed<<setprecision(y)<<x
///////////////////////////////////////////////////////////////////////////////////////
const ll N = 2e6 + 7;
const ll mod = 1e9 + 7;
const ll INF = 1e18 + 1 ;
///////////////////////////////////////////////////////////////////////////////////////


//return continue break

void solve()
{
	ll n;
	string s;
	cin >> n >> s;
	ll ans = 0;
	ll ii = 0;
	while (ii < n and s[ii] == '.')ii++;
	if (ii == n)
	{
		cout << 0 << '\n';
		return;
	}
	vector<ll>v;
	for (int i = ii; i < n; i++)
	{
		ii = i;
		ll cnt = 0;
		while (ii < n and s[i] == s[ii])
		{
			ii++;
			cnt++;
		}
		v.push_back(cnt);
		i = ii - 1;
	}

	n = v.size();
	if (n <= 2)
	{
		cout << "0\n";
		return;
	}
	ll left1 = 0, right1 = v[0] * v[1], stay1 = 0;
	ll left2 = 0, right2 = v[0] * v[1], stay2 = 0;
	for (int i = 2; i < n; i += 2)
	{
		right1 = right2;
		stay1 = stay2;
		left1 = left2;
		left2 = v[i] * v[i - 1] + stay1;
		stay2 = min({right1, left2 + (v[i - 2] + v[i])*v[i - 1]});
		v[i] += v[i - 2];
		if (i != n - 1)
		{
			right2 = v[i] * v[i + 1] + stay2;
		}
	}
	cout << min({left2, stay2, right1}) << '\n';
}

int main()
{
	bhaag_basanti

	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();

	}
}