#include<stdio.h>

int main(){
  int numbers[1100];
  int x;
  int count=0;
  int isPal = 1;
  int i;
  while(1){
    scanf("%d", &x);
    if(x==-1)
      break;

    numbers[count]=x;
    count++;
  }

  for(i=0;i<count; i++){
    if(numbers[i] != numbers[count -1 - i]){
      isPal = 0;
      break;
    }
  }
  printf("%d\r\n", isPal);
  return 0;
}
