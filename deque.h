#pragma once

typedef struct dequeImpl{
	int data;
	struct dequeImpl* next;
	struct dequeImpl* prev;
}dequeImpl;

dequeImpl* generate_deque(int data);
dequeImpl* push_back(int data);
dequeImpl* push_front(int data);
dequeImpl* begin(void);
dequeImpl* end(void);
void pop_back(void);
void pop_front(void);
int is_full(dequeImpl* deque);
int size_of_deque(dequeImpl* deque);
void print_deque(dequeImpl* deque);