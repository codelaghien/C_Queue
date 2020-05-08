#include "linked_list.h"

void delete_node(linked_list* list, int age) {
	node* prev = NULL;
	node* temp = list->head;
	int i = 0;
	while (temp) {
		if (temp->data->age == age) {
			// xoa
			if (prev == NULL) {
				// xoa toa dau tien
				list->head = list->head->next;
			}
			else {
				prev->next = temp->next;
			}
			free(temp->data);
			free(temp);
			list->size--;
			return;
		}
		i++;
		prev = temp;
		temp = temp->next;
	}
}

node* search_node(linked_list* list, int age, int* position) {
	node* temp = list->head;
	int i = 0;
	while (temp) {
		if (temp->data->age == age) {
			*position = i;
			return temp;
		}
		i++;
		temp = temp->next;
	}
	return NULL;
}

linked_list* create_list() {
	// m = messy hay la mess up
	//linked_list* list = (linked_list*)malloc(sizeof(linked_list));

	// c = clean
	linked_list* list = (linked_list*)calloc(1, sizeof(linked_list));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

sinh_vien* create_sinh_vien(const char name[100], const int age) {
	sinh_vien* new_sinh_vien = (sinh_vien*)calloc(1, sizeof(sinh_vien));

	//strcpy(new_sinh_vien->name, name);
	strcpy_s(new_sinh_vien->name, name);
	new_sinh_vien->age = age;

	return new_sinh_vien;
}

node* create_node(sinh_vien* new_sinh_vien) {
	node* new_node = (node*)calloc(1, sizeof(node));

	new_node->data = new_sinh_vien;
	new_node->next = NULL;

	return new_node;
}

void insert_before(linked_list* list, node* new_node, int position) {
	if (position < 1 || list->head == NULL) {
		// insert dau tien
		new_node->next = list->head;
		list->head = new_node;
		if (list->tail == NULL) list->tail = new_node;
		list->size++;
		return;
	}
	if (position >= list->size) {
		// insert sau chot
		list->tail->next = new_node;
		list->tail = new_node;
		list->size++;
		return;
	}

	node* temp = list->head;
	int i = 0;
	while (temp) {
		if (position - 1 == i) {
			// insert
			new_node->next = temp->next;
			temp->next = new_node;
			list->size++;
			return;
		}
		i++;
		temp = temp->next;
	}
}

void print_list(linked_list* list) {
	node* temp = list->head;
	printf("------------------ List ------------------ \n");
	int i = 0;
	while (temp) {
		printf("%d: name: %s, age: %d \n", ++i, temp->data->name, temp->data->age);
		temp = temp->next;
	}
	printf("------------------------------------------ \n");
}

void destroy(linked_list* list) {
	while (list->head) {
		node* temp = list->head;
		list->head = list->head->next;
		free(temp->data);
		free(temp);
	}
	free(list);
}
