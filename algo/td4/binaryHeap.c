#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allcoation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

int left(int index){
    return 2*index+1;
}

int right(int index){
    return 2*index+2;
}

int main(void) 
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap = malloc(sizeof(BinaryHeap));
  heap->allocated = size;
  heap->filled = 0;
  heap->array = (int*) malloc(size*sizeof(int));
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
    int index = heap->filled;
    heap->filled++;
    if(heap->filled> heap->allocated){
        heap->array=realloc(heap->array, 2*heap->allocated*sizeof(int));
        heap->allocated*=2;
    }
    heap->array[index] = value;
    while(index > 0){
        int parent = heap->array[(index-1)/2];
        if(value>parent){
            heap->array[index] = parent;
            heap->array[(index-1)/2]=value;
            index = (index-1)/2;
        }
        else{
            break;
        }
    }

}

int ExtractMax(BinaryHeap * heap, int *res)
{
    if(heap->filled == 0)
        return 0;

    *res = heap->array[0];
    heap->filled--;
    heap->array[0] = heap->array[heap->filled];
    int index = 0;
    while(left(index)<heap->filled){
        int value = heap->array[index];
        int leftval = heap->array[left(index)];
        if(right(index)>=heap->filled){
            if(value < leftval){
                heap->array[index] = leftval;
                heap->array[left(index)] = value;
            }
            return 1;
        }
        int rightval = heap->array[right(index)];
        if(value>=rightval && value>=leftval){
            return 1;
        }   
        else if(rightval>leftval){
            heap->array[index] = rightval;
            heap->array[right(index)] = value;
            index = right(index);
        }
        else{
            heap->array[index] = leftval;
            heap->array[left(index)] = value;
            index = left(index);
        }
    }
  return 1;
}

void Destroy(BinaryHeap * heap)
{
  free(heap->array);
  heap->allocated = 0;
  heap->filled=0;
  free(heap);
}