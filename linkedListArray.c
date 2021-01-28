#include <stdlib.h>
#include <stdio.h>

#define SIZE (4);

typedef struct{

	void** a;
	size_t size;
	size_t count;

}stack_t;

stack_t* new_stack(void){

	stack_t* stack;
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
		error("Out of memory")
	stack->a = malloc(SIZE*sizeof(void*));
	if (stack->a == NULL)
		error("Out of memory")
	stack->size = SIZE;
	stack->count = 0;
	return stack;
}

void free_stack(stack_t** stack){

	free((*stack)->a);
	free(*stack);
	stack = NULL;

}

void push(stack_t* stack, void* data){
	void* a;

	if(stack->size == stack->count){
		stack->size *= 2;
		a = realloc(stack->a, stack->size*sizeof(void*));
		if (a == NULL)
			error("Out of memory")
		stack->a = a;
	}
	stack->a[stack->count] = data;
}

void* pop(stack_t* stack){
	return stack->a[--stack->count];
}

void* top(stack* stack){
	return stack->a[stack->count-1];
}