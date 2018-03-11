#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e8;
typedef long long LL;
LL n, i, sum[10000], t;
void f(LL i)
{
	if(sum[i] >= maxn)
	{
		if(i + 1 >= t)
		t++;
		
		sum[i + 1] += sum[i] / maxn;
		sum[i] = sum[i] % maxn;
		
		f(i + 1);
	}
}

int main()
{
	while(cin >> n)
	{
		memset(sum, 0, sizeof(sum));
		sum[0] = 1;
		t = 1;
		if(n == 0)
		cout << "1\n";
		else
		{
			for(; n > 0; n--)
			{
				for(i = t - 1; i >= 0; i--)
				{
					sum[i] *= n;
					f(i);
				}
			}
			printf("%lld", sum[t-1]);
			if(t > 1)
			for(i = t - 2; i >= 0; i--)
			printf("%08lld", sum[i]);
			cout << endl;
		}
	}
}
