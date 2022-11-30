#include<stdio.h>

int main(){
  int objects[100];
  int capacity;
  int count = 0;
  scanf("%d", &capacity);
  while(1){
    int x;
    scanf("%d", &x);
    if(x==-1)
      break;

    objects[count]=x;
    count++;
  }

  int possible[120][10100];

  int i,j;
  for(i=0;i<120;i++){
    for(j=0;j<10100;j++){
      if(j!=0)
        possible[i][j] = 0;
      else
        possible[i][j] = 1;
    }
  }

  for(i = count; i>0; i--){
    for(j = 0; j<=capacity; j++){
      if(possible[i][j]){
        possible[i-1][j] = 1;
        possible[i-1][j+objects[i-1]] = 1;
      }
    }
  }

  if(possible[0][capacity]){
    printf("OUI\r\n");
  }else{
    printf("NON\r\n");
  }

  return 0;
}
