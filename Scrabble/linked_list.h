#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS
#define LIMIT 7

#include <stdio.h>
#include <string.h>

struct node
{
	char* str;
	struct node* next;
};

struct node* insert_front(struct node* head, char* str);
struct node* create_node(char* str);

void release_nodes(struct node* head);
void print_nodes(struct node* head);

int is_word_doop(struct node* head, char* word);

#endif