#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define SIZE 10000

int Queue[SIZE];
int front = 0;
int back = 0;
int qsize;

void push(int x);
int pop();
void size();
int empty();
void ffront();
void bback();

int main() {
	int turn;
	int num;
	char str[15] = { 0 };
	scanf("%d", &turn);
	while (turn-- > 0) {
		scanf("%s",str);
		getchar();
		switch (str[0]) {
		case 'p':
			if (str[1] == 'u') {
				scanf("%d", &num);
				push(num);
			}
			else {
				printf("%d\n", pop());
			}
			break;
		case 'b':
			bback();
			break;
		case 'f':
			ffront();
			break;
		case 's':
			size();
			break;
		case 'e':
			printf("%d\n", empty());
			break;
		}
	}
	return 0;
}
void push(int x) {
	if (front > back || qsize>=SIZE) {
		return;
	}
	Queue[back++%SIZE] = x;
	qsize++;
}
int pop() {
	int num;
	if (front > back || empty()) {
		return -1;
	}
	qsize--;
	num = Queue[front++%SIZE];
	return num;
}
void size() {
	printf("%d\n", qsize);
}
int empty() {
	if (qsize <= 0)return 1;
	else return 0;
}
void ffront() {
	printf("%d\n", empty() ? -1 : Queue[(front)%SIZE]);
}
void bback(){
	printf("%d\n", empty() ? -1 : Queue[(back-1)%SIZE]);
}