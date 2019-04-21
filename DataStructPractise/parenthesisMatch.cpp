#include "stdafx.h"
#include "LinkStack.h"


bool PairMatch(char c1, char c2) {
	int b1, b2;
	if (c1 < c2) {
		b1 = c1; b2 = c2;
	}
	else {
		b1 = c2; b2 = c1;
	}
	char MatchArray[3][2] = {{'[',']'},
							{ '{','}' },
							{ '(',')' }};
	for (int i = 0; i < 3; i++) {
		if (b1 == MatchArray[i][0])
			return (b2 == MatchArray[i][1]);
	}
	return false;
}
void ParenthesisMatch() {
	Stack s;
	Init(s);
	char a[100];
	scanf("%s", a);

	Push(s, a[0]);

	char *p = a ;
	
	while (*++p) {
		ElemType e = 0;
		GetTop(s, e);
		if (PairMatch(e, *p)) {
			Pop(s, e);
		}
		else {
			Push(s, *p);
		}
	}

	if (StackEmpty(s)) { printf("success.");  }
	else { printf("failed.");  }
}