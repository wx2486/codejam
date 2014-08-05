#include <stdio.h>

int main()
{
	int cc, cn;
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int sum, num;
		int arr[2000];
		int i,j;
		scanf("%d%d", &sum, &num);

		for (i=0; i<num; i++)
			scanf("%d", arr+i);
		for (i=0; i<num; i++)
		{
			for (j=i+1; j<num; j++)
			{
				if (arr[i]+arr[j] == sum)
				{
					printf("Case #%d: %d %d\n", cc, i+1, j+1);
					goto END;
				}
			}
		}

END:
		;
	}

	return 0;
}
