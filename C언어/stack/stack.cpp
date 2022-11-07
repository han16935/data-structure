#include <stdio.h>
#define SIZE 10

typedef struct Stack{
	int arr[SIZE];
	int rear;
}stack;

void init(stack * s1){
	for(int i=0;i<SIZE;i++){
		s1->arr[i] = 0;
	}
	s1->rear=-1;
}

bool is_full(stack * s1){
	if(s1->rear==SIZE-1) return 1;
	else return 0;
}

bool is_empty(stack * s1){
	if(s1->rear==0) return 1;
	else return 0;
}

void push(stack * s1, int data){
	if(!is_full(s1)){
		s1->arr[++s1->rear] = data;
		printf("%d is pushed.\n", data);
	}
	
	else{
		printf("This stack is full.\n");
	}
}

void pop(stack * s1){
	if(!is_empty(s1)){
		int result = s1->arr[s1->rear--];
		printf("%d is popped.\n", result);
	}
	
	else{
		printf("This stack is empty.\n");
	}
}

void peek(stack * s1){
  // arr[rear] 데이터 배출
  printf("%d\n", s1->arr[s1->rear]);	 
}

void print(stack * s1){
	for(int i=0;i<=s1->rear;i++){
		printf("%d ", s1->arr[i]);
	}
	printf("\n");
}

int main(void){
	stack s1;
	init(&s1);
	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);
	print(&s1);
	pop(&s1);
	print(&s1);
	peek(&s1);
}
