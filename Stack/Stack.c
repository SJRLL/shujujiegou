#define _CRT_SECURE_NO_WARNINGS 1


#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a != NULL);
	{
      free(ps->_a);
	  ps->_capacity = 0;
	  ps->_top = 0;
	  ps->_a = NULL;
	}
	
}

void StackPush(Stack* ps, STDataType  x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a,newcapacity*sizeof(STDataType));
		assert(ps->_a != NULL);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps &&ps->_top>0);
	--ps->_top;
}

STDataType  StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	/*StackDestory(&s);*/
}