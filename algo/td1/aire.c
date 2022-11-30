#include<stdio.h>

#define MAX(a,b) a<b ? b : a
#define MIN(a,b) a<b ? a : b
int main(){
  double a1,a2,b1,b2;

  scanf("%lf%lf%lf%lf",&a1, &b1,&a2, &b2);

  double ans = (MIN(b1,b2)) - (MAX(a1, a2));
  ans = MAX(ans, 0);
  printf("%g\r\n", ans);
  return 0;
}
