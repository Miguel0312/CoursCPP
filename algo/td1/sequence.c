#include<stdio.h>

#define MAX(a,b) a>b ? a : b

int main(){
  double values[5100];
  int n;
  scanf("%d", &n);
  int i;
  for(i=0;i<n;i++){
    scanf("%lf",&values[i]);
  }

  double max = values[0];
  double last = values[0];
  
  for(i=1;i<n;i++){
    last = MAX(last + values[i], values[i]);
    max = MAX(max, last);
  }

  printf("%g\r\n", max);
  return 0;
}
