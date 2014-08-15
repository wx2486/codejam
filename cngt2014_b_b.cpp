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

struct rect
{
    long long x1, y1, x2, y2;
};

bool inrect(rect rec, long long x, long long y)
{
    return x >= rec.x1 && x <= rec.x2 && y >= rec.y1 && y <= rec.y2;
}

long long dissum(rect rec, long long x, long long y)
{
    long long sum = 0;

    for (long long i=rec.x1; i<=rec.x2; i++)
        for (long long j=rec.y1; j<=rec.y2; j++)
            sum += abs(x - i) + abs(y - j);

    return sum;
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        long long minsum = -1;
        long long minx, miny;

        int n;
        cin >> n;

        rect recs[1000];
        for (int i=0; i<n; i++)
            cin >> recs[i].x1 >> recs[i].y1 >> recs[i].x2 >> recs[i].y2;

        vector<long long> xs, ys;
        for (int i=0; i<n; i++)
            for (long long xx=recs[i].x1; xx<=recs[i].x2; xx++)
                for (long long yy=recs[i].y1; yy<=recs[i].y2; yy++)
                    xs.push_back(xx), ys.push_back(yy);

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        int midx[2], midy[2];
        midx[0] = xs[(xs.size()-1)/2];
        midx[1] = xs[xs.size()/2];
        midy[0] = ys[(ys.size()-1)/2];
        midy[1] = ys[ys.size()/2];

        for (int mxid=0; mxid<2; mxid++)
            for (int myid=0; myid<2; myid++)
                for (int i=0; i<n; i++)
                    if (inrect(recs[i], midx[mxid], midy[myid]))
                    {
                        long long x, y;
                        x = midx[mxid];
                        y = midy[myid];

                        long long sum = 0;
                        for (int j=0; j<n; j++)
                            sum += dissum(recs[j], x, y);
                       
                        if (minsum < 0 || minsum > sum
                            || minsum == sum && ( x < minx || x == minx && y < miny))
                        {
                            minsum = sum;
                            minx = x;
                            miny = y;
                        }
                    }
        
        for (int i=0; i<n; i++)
        {
            long long sum;
            bool usex, usey;

#define TRY(X, Y) \
            sum = 0;\
            for (int j=0; j<n; j++)\
                sum += dissum(recs[j], X, Y);\
            if (minsum < 0 || minsum > sum\
                || minsum == sum && ( X < minx || X == minx && Y < miny))\
            {\
                minsum = sum;\
                minx = X;\
                miny = Y;\
            }

            usex = midx[0] >= recs[i].x1 && midx[0] <= recs[i].x2;
            usey = midy[0] >= recs[i].y1 && midy[0] <= recs[i].y2;

            rect trec = recs[i];
            if (usex)
                trec.x1 = trec.x2 = midx[0];
            if (usey)
                trec.y1 = trec.y2 = midy[0];

            TRY(trec.x1, trec.y1);
            TRY(trec.x1, trec.y2);
            TRY(trec.x2, trec.y1);
            TRY(trec.x2, trec.y2);
        }

        cerr << cc << " of " << cn << endl;
        cout << "Case #" << cc << ": " << minx << " " << miny << " " << minsum << endl;
    }

    return 0;
}
