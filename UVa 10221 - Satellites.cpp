#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	double s,a;
	char   c[10];
	while ( scanf("%lf %lf %s",&s,&a,c) != EOF ) {
		if ( strcmp(c,"min")==0 ) a =a/ 60;
		if ( a > 180 ) a = 360-a;
		double ang = a*acos(-1.0)/180.0;
		double arc = 2.0*(s+6440.0)*sin(ang/2.0);
		double cho = ang*(s+6440.0);
		printf("%.6lf %.6lf\n",cho,arc);
	}
	return 0;
}
