#include "stdafx.h"
#include "LinkStack.h"

void conversion() {
	Stack s;
	Init(s);
	int N;
	scanf_s("%d", &N);
	while (N) {
		Push(s, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(s)) {
		int e;
		Pop(s, e);
		printf("%d", e);
	}
}