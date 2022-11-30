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

  int possible[110001] = {0};

  possible[0] = 1;

  int i;
  for(i = 0; i<capacity; i++){
    if(possible[i]){
      int j;
      for(j = 0; j<count; j++){
        if(i+objects[j] <=capacity)
          possible[i + objects[j]] = 1;
      }
    }
  }

  if(possible[capacity]){
    printf("OUI\r\n");
  }
  else{
    printf("NON\r\n");
  }

  return 0;
}
