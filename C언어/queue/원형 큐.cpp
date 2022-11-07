#include <stdio.h>
#define SIZE 5

typedef struct circular_queue{
	int arr[SIZE];
	int front;
	int rear;
	int size;
}c_queue;

void init(c_queue * queue){
	for(int i=0;i<SIZE;i++){
		queue->arr[i] = NULL;
	}
	queue->front = -1;
	queue->rear = -1;
	queue->size = 0;
}

bool is_full(c_queue * queue){
	return (queue->size==SIZE);
}

bool is_empty(c_queue * queue){
	return (queue->size==0);
}

int enqueue(c_queue * queue, int data){
	if(is_full(queue)){
		int answer;
		printf("This queue is full. Saved Data will be deleted. Continue?(If do, Please write 1, or 0)\n");
	    scanf("%d", &answer);
		if(answer==0){
			return 0;
		}		
	} 
	queue->rear = ((queue->rear)+1)%SIZE;
	if(queue->rear == queue->front){
  	   queue->rear++;
    }
	int will_put_index = queue->rear;
	queue->arr[will_put_index] = data;
	queue->size++;
	return 1;
}

int dequeue(c_queue * queue){
  // pop한 데이터 반환
  if(is_empty(queue)){
  	printf("This queue is empty. Please enqueue data first.");
  	return 0;
  }
  queue->front = ((queue->front)+1)%SIZE;
  if(queue->front == queue->rear){
  	queue->front++;
  }
  int will_deleted_index = queue->front;
  int result = queue->arr[will_deleted_index];
  queue->arr[will_deleted_index] = NULL;
  queue->size--;
  printf("%d is successfully popped.\n", result);
  return 1;
}

void printQueue(c_queue * queue){
	for(int i=0;i<SIZE;i++){
		printf("%d ", queue->arr[i]);
	}
}

int main(void){
	c_queue queue;
	c_queue * q = &queue;
	init(q);
	enqueue(q, 5);
	dequeue(q);
	printQueue(q);
}
