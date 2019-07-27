#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//KEYWORD L R D P
//이 에디터는 삽입하면 포인터로 삽입한 부분을 짚고 있는다.
typedef struct node {
	char data;
	struct node *front, *back;
}NODE;
NODE head;
NODE *pointer = &head;
void insert(char data){
	NODE * node = (NODE*)malloc(sizeof(NODE));
	if (node == NULL)return;
	node->data = data;
	node->front = NULL;
	node->back = NULL;
	if (pointer == NULL)pointer = node;
	else{
		if (pointer->back != NULL) {
			node->back = pointer->back;
			pointer->back->front = node;


		}
		pointer->back = node;
		node->front = pointer;
	}
	pointer = node;
}
void delet() {
	NODE * node = pointer;
	if (pointer == &head)return;
	//printf("%c\n", pointer->data);
	if (pointer->back != NULL) {
		pointer->front->back = pointer->back;
		pointer->back->front = pointer->front;
	}
	else {
		pointer->front->back = pointer->back;
	}
	pointer = pointer->front;
	free(node);
}
void moveL() {
	if (pointer == &head) return;
	pointer = pointer->front;
}
void moveR() {
	if (pointer->back == NULL)return;
	pointer = pointer->back;
}
void print() {
	NODE * node = head.back;
	while (node != NULL) {
		printf("%c", node->data);
		node = node->back;
	}
}
int main() {
	char str[100001];
	char string[5];
	int num;
	int i = 0;
	scanf("%s", str);
	scanf("%d", &num);
	getchar();
	while (str[i] != '\0')insert(str[i++]);
	while (num-- > 0) {
		gets(string);
		//printf("%s\n",string);
		switch (string[0]) {
		case 'P':
			insert(string[2]);
			break;
		case 'L':
			moveL();
			break;
		case 'D':
			moveR();
			break;
		case 'B':
			delet();
			break;
		default:
			break;
		}

	}
	print();
	return 0;
}