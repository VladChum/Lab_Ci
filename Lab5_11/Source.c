#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Queue
{
	int size;
	struct Stack* head;
	struct Stack* end;
};

void push_back(struct Queue* queue, int i);
int pop(struct Queue* queue);
int find(struct Queue* queue, const char Symbol, const int index, const int number);

struct Stack
{

	struct Numbers
	{
		struct Numbers* stack_next;
		int number;
	};

	int stack_size;
	struct Stack* next;
	struct Stack* last;
	struct Numbers* stack_head;
};

struct Stack* set_stack(int _number, struct Stack* _last, struct Stack* _next);
struct Numbers* set_number(int _number, struct Numbers* next);
int pop_number(struct Stack* stack);

int Check(const char* funcpointer);
char Check_A_D(const char* funcpointer);

int main()
{
	struct Queue* queue = (struct Queue*)calloc(1, sizeof(struct Queue));
	do
	{
		char action = Check_A_D("Please input A or D or E to Exit: ");
		int index;
		if (action == 'E')
		{
			break;
		}
		do
		{
			index = Check("Please input index: ");
		} while (index < 0);
		int number_input = 0;
		if (action == 'A')
			number_input = Check("Please input number: ");
		int result = find(queue, action, index, number_input);
		printf("Top: %d stack size: %d\n", result, queue->size);
	} while (1);
}

void push_back(struct Queue* queue, int number)
{
	if (queue->end != NULL)
	{
		struct Stack* temp = queue->end;

		temp->next = set_stack(number, temp, NULL);

		queue->end = temp->next;

		queue->end->stack_size = 1;
	}
	else
	{
		queue->end = queue->head = set_stack(number, NULL, NULL);
		queue->head->stack_size = 1;
	}
	queue->size++;
}

int pop(struct Queue* queue)
{
	if (queue->head != NULL)
	{
		struct Stack* temp = queue->head;
		int number = pop_stack(queue, temp);
		if (temp != NULL)
		{
			struct Stack result = *(temp);
			queue->head = temp->next;
			free(temp);
		}
		queue->size--;
		return number;
	}
	else
	{
		free(queue);
		queue = NULL;
	}

	return -1;
}

int do_action(struct Queue* queue, struct Stack* temp, const char Symbol, const int number)
{
	int result;
	if (Symbol == 'A')
	{
		temp->stack_head = set_number(number, temp->stack_head);
		temp->stack_size++;
		result = temp->stack_head->number;
	}
	else
	{
		result = pop_stack(queue, temp);
	}
	return result;
}

int find(struct Queue* queue, const char Symbol, const int index, const int number)
{
	int counter = 0;
	struct Stack* temp = queue->head;
	if (index >= queue->size && Symbol == 'D')
	{
		return -1;
	}
	if (index >= queue->size) {
		push_back(queue, number);
		return queue->end->stack_head->number;
	}
	while (queue->size != counter)
	{
		if (counter == index)
		{
			return do_action(queue, temp, Symbol, number);
		}
		temp = temp->next;
		counter++;
	}
}

int pop_stack(struct Queue* queue, struct Stack* stack)
{
	if (stack->stack_size >= 0)
	{
		int number = pop_number(stack);
		stack->stack_size--;
		if (stack->stack_size == 0)
		{
			queue->size--;
			if (stack->next != NULL)
			{
				stack->next->last = stack->last;
			}
			if (stack->last != NULL)
			{
				stack->last->next = stack->next;
			}
			else
			{
				if (stack->next != NULL)
				{
					queue->head = stack->next;
				}
				else
				{
					queue->head = queue->end = NULL;
				}
			}
			free(stack);
			stack = NULL;
		}
		return number;
	}

	return -1;
}

int pop_number(struct Stack* stack)
{
	if (stack != NULL)
	{
		struct Numbers* temp = stack->stack_head;
		stack->stack_head = temp->stack_next;
		int number = temp->number;
		free(temp);
		return number;
	}

	return -1;
}

struct Stack* set_stack(int _number, struct Stack* last, struct Stack* next)
{
	struct Stack* new_stack = (struct Stack*)calloc(1, sizeof(struct Stack));
	new_stack->stack_head = set_number(_number, new_stack->stack_head);
	new_stack->stack_size++;
	new_stack->next = next;
	new_stack->last = last;
	return new_stack;
}

struct Numbers* set_number(int _number, struct Numbers* next)
{
	struct Numbers* new_stack = (struct Numbers*)calloc(1, sizeof(struct Numbers));
	new_stack->number = _number;
	new_stack->stack_next = next;
	return new_stack;
}

char Check_A_D(const char* funcpointer)
{
	char symbol;
	do
	{
		printf("%s\n", funcpointer);
		if (scanf("%c", &symbol) == 1 && (symbol == 'A' || symbol == 'D' || symbol == 'E'))
		{
			break;
		}
		rewind(stdin);
		printf("Error: Incorrect input\n");

	} while (1);
	return symbol;
}


int Check(const char* funcpointer)
{
	int num;
	char temp = '\n';
	do
	{
		printf("%s\n", funcpointer);
		if (scanf("%d%c", &num, &temp) == 2 && temp == '\n' && num < INT_MAX)
		{
			break;
		}
		rewind(stdin);
		printf("Error: Incorrect input\n");

	} while (1);
	return num;
}