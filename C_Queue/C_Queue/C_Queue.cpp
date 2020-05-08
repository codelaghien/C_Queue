// C_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

typedef struct queue {
	linked_list* list;
} queue;

queue* create_queue();
void enqueue(queue* my_queue, node* new_node);
node* dequeue(queue* my_queue);
void print_queue(queue* my_queue);
bool is_empty(queue* my_queue);
int queue_size(queue* my_queue);
void destroy(queue* my_queue);

int main()
{
	printf("Queue \n");

	sinh_vien* A = create_sinh_vien("A", 30);
	sinh_vien* B = create_sinh_vien("B", 10);
	sinh_vien* C = create_sinh_vien("C", 40);

	queue* my_queue = create_queue();

	enqueue(my_queue, create_node(A));
	enqueue(my_queue, create_node(B));
	enqueue(my_queue, create_node(C));
	enqueue(my_queue, create_node(create_sinh_vien("D", 40)));
	print_queue(my_queue);

	node* a_node = dequeue(my_queue); 
	if (a_node) {
		printf("dequeue lan 1: name = %s, age = %d \n", a_node->data->name, a_node->data->age);
	}
	print_queue(my_queue);

	a_node = dequeue(my_queue);
	if (a_node) {
		printf("dequeue lan 2: name = %s, age = %d \n", a_node->data->name, a_node->data->age);
	}
	print_queue(my_queue);

	destroy(my_queue);

	char c = getchar();
	return 0;
}

queue* create_queue() {
	queue* new_queue = (queue*)calloc(1, sizeof(queue));
	new_queue->list = create_list();

	return new_queue;
}
void destroy(queue* my_queue) {
	destroy(my_queue->list);
	free(my_queue);
}
void print_queue(queue* my_queue) {
	print_list(my_queue->list);
}

void enqueue(queue* my_queue, node* new_node) {
	insert_before(my_queue->list, new_node, my_queue->list->size);
}
node* dequeue(queue* my_queue) {
	node* a_node = my_queue->list->head;
	my_queue->list->head = my_queue->list->head->next;
	my_queue->list->size--;
	return a_node;
}

int queue_size(queue* my_queue) {
	return my_queue->list->size;
}
bool is_empty(queue* my_queue) {
	return (queue_size(my_queue) == 0);
}


