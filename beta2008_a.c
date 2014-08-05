#include <stdio.h>

#define AREA(ea, eb) ((ea).x * (eb).y - (ea).y * (eb).x)
#define LEN(ea) ((ea).x * (ea).x + (ea).y * (ea).y)
#define ANGLE(ea, eb) ((ea).x * (eb).x + (ea).y * (eb).y)

struct Point
{
	int x,y;
};

int main()
{
	int cc, cn;
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		struct Point a,b,c;
		struct Point ea, eb, ec;
		scanf("%d%d %d%d %d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

		ea.x = a.x - b.x; ea.y = a.y - b.y;
		eb.x = b.x - c.x; eb.y = b.y - c.y;
		ec.x = c.x - a.x; ec.y = c.y - a.y;

		printf("Case #%d: ", cc);

		if (!AREA(ea, eb))
		{
			puts("not a triangle");
			continue;
		}

		if (LEN(ea) == LEN(eb) || LEN(ea) == LEN(ec) || LEN(eb) == LEN(ec))
			printf("isosceles ");
		else
			printf("scalene ");

		if (!ANGLE(ea, eb) || !ANGLE(ea, ec) || !ANGLE(eb, ec))
			puts("right triangle");
		else if (ANGLE(ea, eb) > 0 || ANGLE(ea, ec) > 0 || ANGLE(eb, ec) > 0)
			puts("obtuse triangle");
		else
			puts("acute triangle");
	}

	return 0;
}
