#include "linked_list.h"

struct node* create_node(char* str)
{
	struct node* temp;

	temp = (struct node*) malloc(sizeof(struct node));
	temp->str = str;
	temp->next = NULL;

	return temp;
}

struct node* insert_front(struct node* head, char* str)
{
	char* new_str = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(new_str, str);

	struct node* temp = create_node(new_str);
	temp->next = head;

	return temp;
}

void print_nodes(struct node* head)
{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n> printing word list\n");
	int total_letters = 0, total_words = 0;

	while (head != NULL)
	{
		printf("+ %s\tletter count: %d\n", head->str, strlen(head->str));
		total_words++;
		total_letters += strlen(head->str);
		head = head->next;
	}

	printf("\nTotal letters:%d\nTotal correct words:%d\n", total_letters, total_words);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int is_word_doop(struct node* head, char* word)
{
	while (head != NULL)
	{
		if (strlen(word) == strlen(head->str))
		{
			int x = 0; 

			for (int i = 0; word[i] != '\0'; i++)
			{
				if (word[i] != head->str[i])
				{
					x++;
				}
			}

			if (x == 0)
			{
				return 1;
			}
		}
		head = head->next;
	}

	return -1;
}

void release_nodes(struct node* head)
{
	struct node* temp;
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		printf("> releasing word: '%s'\n", temp->str);
		free(temp->str);
		free(temp);
	}

	printf("\n> all nodes have been released.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}