#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Node{
//	malloc���� node ����  
	int data;
	struct Node * left;
	struct Node * right;
}node;

typedef struct Binary_Search_Tree{	
	struct Node * root;
	int size;
}BST;

void init(BST * bst){
	bst->root = NULL;
	bst->size = 0;
}

bool insert(BST * bst, int data){
//	1. ���ڷ� ���� data�� �̿��� node ���� �� �ʱ�ȭ  
	node * n1 = (node *)malloc(sizeof(node));
	n1->data = data;
	n1->left = NULL;
	n1->right = NULL;
	
	if(bst->size==0){
		bst->root = n1;
		bst->size++;
		return 1;
	}
	
	node * currentNode = bst->root;
	while(1){
		if(currentNode->data>data){
//			A. left�� �̵�  
            if(currentNode->left==NULL){
            	currentNode->left = n1;
			}
			
			else{
				currentNode = currentNode->left;
				break;
			} 
		}
		
		else if(currentNode->data<data){
//			B. right�� �̵� 
            if(currentNode->right==NULL){
            	currentNode->right = n1;
			}
			
			else{
				currentNode = currentNode->right;
				break;
			}
		}
	}
	bst->size++;
	return 1;
}

void find(BST * bst, int data){
//	���ڷ� ���� data�� ���� ��� ã��, �ִٸ� �� ����� �θ� ��� return, ���ٸ� null return 
    node * parentNode = NULL;
	node * currentNode = bst->root;
	
	while(currentNode->data != data){
		if(currentNode->data>data){
//			1. data�� ���� ����Ű�� ��庸�� ���� ��� - right�� �̵�  
 			printf("%d left\n", currentNode->data);
			parentNode = currentNode;
			currentNode = currentNode->left;
		}
		
		else if(currentNode->data<data){
//			2. data�� ���� ����Ű�� ��庸�� Ŭ ��� - left�� �̵� 
 			printf("%d right\n", currentNode->data);
            parentNode = currentNode;
			currentNode = currentNode->right; 
		} 
	}
	
    printf("%d answer\n", currentNode->data);
}


int main(void){
	BST bst; 
	init(&bst);
    insert(&bst, 5);
    insert(&bst, 7);
    insert(&bst, 3);
    insert(&bst, 1);
    find(&bst, 7);
    find(&bst, 1);
}
