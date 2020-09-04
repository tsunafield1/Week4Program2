#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n, pre = 0, mi = 0;
	char s[100001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &s[i - mi]); //Scan Enter of previous line
		scanf("%c", &s[i - mi]);
		if (s[pre] == s[i - mi] && i - mi > 0)
		{
			mi += 2;
			pre--;
			for (int j = pre; j > 0; j--)
			{
				if (s[j] == s[j - 1])
				{
					mi += 2;
					pre -= 2;
				}
				else break;
			}
		}
		pre = i - mi;
	}
	printf("%d\n", pre + 1);
	if (pre == -1) printf("empty");
	else
	{
		for (int i = pre; i >= 0; i--)
		{
			printf("%c", s[i]);
		}
	}
}