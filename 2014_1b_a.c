#include <stdio.h>
#include <string.h>

int main()
{
    int cn, cc;

    freopen("A-large-practice.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        int i,j,k;
        char ch[100][100];
        int mult[100][100];
        int chn[100];
        int n;
        int sum;

        scanf("%d", &n);
        getchar();

        for (i=0; i<n; i++)
        {
            char c;
            chn[i] = 0;

            while ((c = getchar()) != '\n')
            {
                if (chn[i] == 0 || c != ch[i][chn[i]-1])
                {
                    ch[i][chn[i]] = c;
                    mult[i][chn[i]] = 1;
                    chn[i]++;
                }
                else
                    mult[i][chn[i]-1]++;
            }
        }

        for (i=1; i<n; i++)
            if (chn[i] != chn[0] || strncmp(ch[0], ch[i], chn[0]))
                goto FEGLA_WON;

        sum = 0;
        for (i=0; i<chn[0]; i++)
        {
            int min = -1;
            for (j=1; j<=100; j++)
            {
                int dis = 0;
                for (k=0; k<n; k++)
                    if (mult[k][i] < j)
                        dis += j - mult[k][i];
                    else
                        dis += mult[k][i] - j;
                if (min < 0 || dis < min)
                    min = dis;
            }
            sum += min;
        }

        printf("Case #%d: %d\n", cc, sum);
        continue;
    FEGLA_WON:
        printf("Case #%d: Fegla Won\n", cc);
    }

    return 0;
}
