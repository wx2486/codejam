#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main()
{
    int status = 0;
    int lvl = 0;
    char c;

    puts("Case #1:");
    while ((c=getchar()) != EOF)
        if (status == 0)
        {
            if (c == '/')
                status = 1;
            else
                putchar(c);
        }
        else if (status == 1)
        {
            if (c == '*')
                status = 2;
            else
            {
                if (!lvl)
                    putchar('/');
                if (c != '/')
                {
                    status = 0;
                    if (!lvl)
                        putchar(c);
                    if (lvl)
                    {
                        lvl--;
                        status = 2;
                    }
                }
            }
        }
        else if (status == 2)
        {
            if (c == '*')
                status = 3;
            else if (c == '/')
            {
                lvl++;
                status = 1;
            }
        }
        else // status == 3
        {
            if (c == '/')
            {
                status = 0;
                if (lvl)
                {
                    lvl--;
                    status = 2;
                }
            }
            else if (c == '*')
                status = 3;
            else
                status = 2;
        }

    return 0;
}
