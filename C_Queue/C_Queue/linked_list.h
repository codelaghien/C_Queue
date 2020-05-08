#pragma once

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct sinh_vien
{
	char name[100];
	int age;
} sinh_vien;

typedef struct node {
	sinh_vien* data;
	node* next;
} node;

typedef struct linked_list {
	node* head;
	node* tail;
	int size;
} linked_list;

// prototype : menu : thuc don
linked_list* create_list();
sinh_vien* create_sinh_vien(const char name[100], const int age);
node* create_node(sinh_vien* new_sinh_vien);
void insert_before(linked_list* list, node* new_node, int position = 0);
void print_list(linked_list* list);
node* search_node(linked_list* list, int age, int* position);
void delete_node(linked_list* list, int age);
void destroy(linked_list* list);
