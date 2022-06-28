#ifndef SEQ_STACK
#include "seq_stack.h"
#endif

Status InitStack(SqStack& S){
	S.stacksize = MAXSIZE;
	S.base = new ElemType[MAXSIZE];
	S.top = S.base;
	return OK;
}

Status DestroyStack(SqStack& S){
	if (S.base != nullptr) {
		S.stacksize = 0;
		delete[] S.base;
		S.base = nullptr;
		S.top = nullptr;
		return OK;
	}
	else return ERROR;
}

Status ClearStack(SqStack& S){
	if (DestroyStack(S)) {
		InitStack(S);
		return OK;
	}
	else return ERROR;
}

bool StackEmpty(SqStack S){
	if (S.base != nullptr) {
		return S.base == S.top ? true : false;
	}
	else false;
}

int StackLength(SqStack S) {
	if (S.base != nullptr) {
		return S.top - S.base;
	}
	else ERROR;
}

ElemType GetTop(SqStack S){
	if (!StackEmpty(S)) {
		return *--S.top;
	}
	else ERROR;
}

Status Push(SqStack& S, ElemType e){
	if (S.base != nullptr) {
		if (StackLength(S) == S.stacksize) return YWM_OVERFLOW;
		*S.top++ = e;
		return OK;
	}
	else ERROR;
}

Status Pop(SqStack& S, ElemType& e){
	if (S.base != nullptr) {
		if (!StackLength(S)) return YWM_UNDERFLOW;
		e = *--S.top;
		return OK;
	}
	else ERROR;
}

Status StackTraverse(SqStack S){
	if (S.base != nullptr) {
		while (!StackEmpty(S)) {
			std::cout << GetTop(S) << " ";
			S.top--;
		}
		return OK;
	}
	else ERROR;
}