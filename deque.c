#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "deque.h"

static dequeImpl* head = NULL;
static dequeImpl* tail = NULL;

dequeImpl* generate_deque(int data)
{
	if (!tail && !head) {
		if (tail = (dequeImpl*)malloc(sizeof(dequeImpl))) {
			tail->data = data;
			tail->next = NULL;
			tail->prev = NULL;
			head = tail;
			return tail;
		}else return NULL;
	}else return push_back(data);
}

dequeImpl* push_back(int data)
{
	if(!tail){
		if (tail = (dequeImpl*)malloc(sizeof(dequeImpl))) {
			tail->data = data;
			tail->next = NULL;
			tail->prev = NULL;
			head = tail;
			return tail;
		}else return NULL;
		
	}
	else {
		dequeImpl* temp = (dequeImpl*)malloc(sizeof(dequeImpl));
		if (temp) {
			tail->next = temp;
			temp->data = data;
			temp->next = NULL;
			temp->prev = tail;
			tail = temp;
			return tail;
		}else return NULL;
	}
	
}

dequeImpl* push_front(int data)
{
	if (!head) {
		if (head = (dequeImpl*)malloc(sizeof(dequeImpl))) {
			head->data = data;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			return head;
		}
		else return NULL;
	}
	else {
		dequeImpl* temp = (dequeImpl*)malloc(sizeof(dequeImpl));
		if (temp) {
			head->prev = temp;
			temp->data = data;
			temp->next = head;
			temp->prev = NULL;
			head = temp;
			return head;
		}else return NULL;
	}
}

dequeImpl* begin(void)
{
	return head;
}
dequeImpl* end(void)
{
	return tail;
}

void print_deque(dequeImpl* deque)
{
	while (deque->next) {
		printf("%d\n", deque->data);
		deque = deque->next;
	}
	if(head && tail) printf("%d\n", deque->data);
}

void pop_back(void)
{
	if ((tail && head) && tail->prev) {
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
	else if (tail && head) {
		free(tail);
		head = tail = NULL;
		
	}
}

void pop_front(void)
{
	if ((tail && head) && (head->next)) {
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	else if (tail && head) {
		free(head);
		head = tail = NULL;
	}
}

int is_empty(dequeImpl* deque)
{
	return tail && head ? 0 : 1;
}

int size_of_deque(dequeImpl* deque)
{
	int count = 0;
	if (head && tail) ++count; else return count;
	while (deque->next) {
		++count;
		deque = deque->next;
	}
	return count;
}
