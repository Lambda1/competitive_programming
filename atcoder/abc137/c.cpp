#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <limits>

using ll = long long int;
using ul = unsigned long long int;

namespace lamlib
{
	// EPSITON
	constexpr double epsilon = std::numeric_limits<double>::epsilon();
	// Absolute
	template<class T> inline T abs(const T &a){ return (a>0) ? a : -a; }
	// Digit
	ul inline digit(const ul &num){ return static_cast<ul>(std::log10(num+epsilon))+1; }
	// GCD: a > b
	ul gcd(ul a,ul b) { return (!b) ? a : gcd(b,a%b); }
	
	/* string */
	inline ul same_char_count(const std::string s,const char &ch){ return std::count(std::cbegin(s),std::cend(s),ch); }
}

int main(int argc,char *argv[])
{
	ul n;
	std::cin >> n;
	
	std::vector<std::string> s(n);
	for(ll i = 0;i < n;++i) std::cin >> s[i];

	ul ans = 0;
	std::unordered_map<std::string, ll> m;
	for(ll i = 0;i < n;++i)
	{
		std::sort(s[i].begin(),s[i].end());
		if(m[s[i]] > 0) ans += m[s[i]];
		++m[s[i]];
	}

	std::cout << ans << std::endl;

	return 0;
}
