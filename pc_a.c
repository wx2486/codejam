#include <stdio.h>

int main()
{
	int cc, cn;
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		if (b%2) printf("Case #%d: BLACK\n", cc);
		else printf("Case #%d: WHITE\n", cc);
	}

	return 0;
}
