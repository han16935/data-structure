#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node * prev;
	struct node * next;
}node;

typedef struct doubleLinkedList{
	struct node * head;
	struct node * tail;
	int length;
}doubleLinkedList;

node * makeNode(int data){
	node * n1 = (node *)malloc(sizeof(node));
	n1->data = data;
	return n1;
}

void init(doubleLinkedList * list){
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

void push(doubleLinkedList * list, node * n1){
  // list의 마지막에 노드 삽입
  if(list->length==0){
  	list->head = n1;
  	list->tail = n1;
  }
  
  else{
  	list->tail->next = n1;
  	n1->prev = list->tail;
  	list->tail = n1;
  }
  list->length++;
  printf("node %d is completely pushed.\n", n1->data); 
}

void pop(doubleLinkedList * list){
  // list의 tail 노드 제거
  int willReturnedData = list->tail->data;
  node * willDeletedNode = list->tail;
  node * willDeletedBeforeNode = list->tail->prev;
  list->tail = willDeletedBeforeNode;
  list->length--;
  free(willDeletedNode);
  printf("node %d is completely removed.\n", willReturnedData);
}

void unshift(doubleLinkedList * list, node * n1){
  // list의 제일 앞에 새로운 노드 삽입
  if(list->length==0){
  	push(list, n1);
  }
  
  else{
  	list->head->prev = n1;
  	n1->next = list->head;
  	list->head = n1;
  	list->length++;
  	printf("node %d is completely pushed at first.\n", n1->data); 
  }	
}

void shift(doubleLinkedList * list){
  // list의 제일 앞 노드 제거
  node * willRemovedData = list->head;
  int willReturnedData = list->head->data;
  node * willRemovedAfterNode = list->head->next;
  if(list->length==1){
  	 free(list->head);
  	 list->head=NULL;
  	 list->tail=NULL;
  }
  
  else{
  	list->head = willRemovedAfterNode;
  	willRemovedAfterNode->prev = NULL;
  }
  list->length--;
  free(willRemovedData); 
  printf("node %d is completely removed at first.\n", willReturnedData);	
}

node * get(doubleLinkedList * list, int index){
  // list의 index 번째 노드의 값 return, 혹은 printf로 출력
  node * willReturnedNode = list->head;
  for(int i=0;i<index;i++){
  	willReturnedNode = willReturnedNode->next;
  }
  return willReturnedNode;	
}

void insert(doubleLinkedList * list, node * n1, int index){
  // index 번째에 n1 노드 삽입
  if(index==list->length){
  	push(list, n1);
  }
  else if(index==0){
  	unshift(list, n1);
  } 
  else{
  	node * willInsertedBeforeNode = get(list, index-1);
  	node * willInsertedAfterNode = get(list, index+1);
  	willInsertedAfterNode->prev = n1;
  	willInsertedBeforeNode->next = n1;
  	n1->next = willInsertedAfterNode;
  	n1->prev = willInsertedBeforeNode;
  	list->length++;
  	printf("node %d is completely inserted at %d position.\n", n1->data, index); 	
 }
}

void remove(doubleLinkedList * list, int index){
	if(index==0){
		shift(list);
	}
	
	else if(index==list->length-1){
		pop(list);
	}
	
	else{
		int willReturnedData = get(list, index)->data;
		node * willDeletedBeforeNode = get(list, index-1);
		willDeletedBeforeNode->next = willDeletedBeforeNode->next->next;
		willDeletedBeforeNode->next->next->prev = willDeletedBeforeNode;
		free(get(list, index));
		list->length--;
		printf("node %d is completely removed at %dth position.\n", willReturnedData, index);	
	}
}

void set(doubleLinkedList * list, int index, int num){
  // list의 index번째 node의 값을 num으로 변경	
  node * willChangedNode = get(list, index);
  willChangedNode->data = num;
  printf("Node %d's data is succeefully changed to %d\n", index, num);
}
 

void print(doubleLinkedList * list){
   // list 내부 모든 노드의 데이터 출력	
	node * willPrintedNode = list->head;
	for(int i=0;i<list->length-1;i++){
		printf("%d -> ", willPrintedNode->data);
		willPrintedNode = willPrintedNode->next;
	}
	printf("%d\n", willPrintedNode->data);
}


int main(void){
    node * n1 = makeNode(0);
    node * n2 = makeNode(1);
    node * n3 = makeNode(2);
    node * n4 = makeNode(3);
    doubleLinkedList * list = (doubleLinkedList *)malloc(sizeof(doubleLinkedList));
    init(list);
    push(list, n1);
    push(list, n2);
    push(list, n3);
    push(list, n4);
    remove(list, 2);
    print(list);
}
