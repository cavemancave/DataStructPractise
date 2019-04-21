#include "stdafx.h"
#include <malloc.h>
#include<windows.h>

#include<stddef.h>
#include<stdlib.h>

#include "LinkStack.h"


int Init(Stack &s) {
	s.base = (Link)malloc(sizeof(Slink));
	if (s.base == NULL) { exit(1); }
	s.top = s.base;
	s.len = 0;

	return OK;
}

int Push(Stack &s, ElemType e) {
	Link p = (Link)malloc(sizeof(Slink));
	if (p == NULL) { exit(1); }
	p->next = s.top;
	p->data = e;
	s.top = p;
	s.len++;
	return OK;
}

int Pop(Stack &s, ElemType &e) {
	if (s.top == s.base) { return ERR; }

	e = s.top->data;
	Link p = s.top;
	s.top = p->next;
	free(p);
	s.len--;
	return OK;
}

bool StackEmpty(Stack &s) {
	return (s.len == 0) ? true : false;
}

int GetTop(Stack &s, ElemType &e) {
	if (StackEmpty(s)) return ERR;

	e = s.top->data;
	return OK;

}