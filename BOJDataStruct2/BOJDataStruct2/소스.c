#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 10000
int Deque[SIZE];
int front=5001;
int back=5000;
int dsize;

void push_front(int x);
void push_back(int x);
int pop_front();
int pop_back();
void size();
int empty();
void ffront();
void bback();

int main() {
	int turn;
	int num;
	char str[100] = {0};
	scanf("%d", &turn);
	while (turn-- > 0) {
		scanf("%s", str);
		switch (str[0]) {
		case 'p':
			if (str[1] == 'u') {
				scanf("%d", &num);
				if (str[5] == 'f')push_front(num);
				else push_back(num);
			}
			else {
				if (str[4] == 'f') printf("%d\n", pop_front());
				else printf("%d\n", pop_back());
			}
			break;
		case 'f':
			ffront();
			break;
		case 'b':
			bback();
			break;
		case 's':
			size();
			break;
		case 'e':
			printf("%d\n",empty());
			break;
		default:
			break;
		}
	}
	return 0;
}
int empty() {
	if (dsize <= 0)return 1;
	else return 0;
}
void push_front(int x) {
	if ((front - 1) % SIZE == back % SIZE && !empty()) {
		return;
	}
	Deque[--front%SIZE] = x;
	dsize++;
}
void push_back(int x) {
	if ((back + 1) % SIZE == front % SIZE && !empty()) {
		return;
	}
	Deque[++back%SIZE] = x;
	dsize++;
}
int pop_front() {
	int num;
	if (empty()) return -1;
	dsize--;
	num = Deque[front++%SIZE];
	return num;
}
int pop_back() {
	int num;
	if (empty()) return -1;
	dsize--;
	num = Deque[back--%SIZE];
	return num;
}
void size() {
	printf("%d\n", dsize);
}
void ffront() {
	printf("%d\n", empty()? -1 : Deque[front%SIZE]);
}
void bback() {
	printf("%d\n", empty() ? -1 : Deque[back%SIZE]);
}