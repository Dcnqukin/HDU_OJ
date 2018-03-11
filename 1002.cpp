#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1005;

int main(){
	int n;
	char a[maxn], b[maxn];
	int da[maxn], db[maxn], dc[maxn];
	cin >> n;
	for(int flag = 1; flag <= n; flag ++)
	{
		scanf("%s", a);
		scanf("%s", b);
		printf("Case %d:\n", flag);
		printf("%s + %s = ", a, b);
		memset(da, 0, sizeof(da));
		memset(db, 0, sizeof(db));
		memset(dc, 0, sizeof(dc));
		int lena = strlen(a), lenb = strlen(b);
		int len = lena > lenb ? lena : lenb;
		int k = 0;
		for(int i = lena - 1; i >= 0; i--)
			da[k++] = a[i] - '0';
		k = 0;
		for(int i = lenb - 1; i >= 0; i--)
			db[k++] = b[i] - '0';
		int carry = 0;
		for(int i = 0; i < len; i++)
		{
			dc[i] = (da[i] + db[i] + carry) %10;
			carry = (da[i] + db[i] + carry) /10;
		}
		dc[len] += carry;
		bool start = false;
		if(dc[len] == 0 && dc[len - 1] == 0) cout << 0;
		for(int i = len; i >= 0; i--)
		{
			if(start)
				cout << dc[i];
			else if(dc[i])
			{
				cout << dc[i];
				start = true;
			}

		}
		cout << endl;
		if(flag != n)
		cout << endl;
	}
}
