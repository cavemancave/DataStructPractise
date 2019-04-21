#include "stdafx.h"
#include "LinkStack.h"


void RevertStack(Stack &s, Stack &s2) {
	
	ElemType e;
	while (!StackEmpty(s)) {
		Pop(s, e);
		Push(s2, e);
	}
}
void PrintRevertStack(Stack &s) {
	Stack s2;
	Init(s2);
	ElemType e;
	RevertStack(s, s2);
	while (!StackEmpty(s2)) {

		Pop(s2, e);
		printf("%c", e);
	}
	printf("\n");
}

void LineEdit() {

	Stack s;
	Init(s);

	char c = getchar();
	ElemType e;

	while (c != EOF) {
		while (c != EOF && c != '\n') {
			switch (c) {
			case '#': Pop(s, e); break;
			case '@': ClearStack(s); break;
			default: Push(s, c);
			}
			c = getchar();
		}
		PrintRevertStack(s);
		
		if (c != EOF) c = getchar();
	}

}