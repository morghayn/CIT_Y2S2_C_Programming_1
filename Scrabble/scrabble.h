#ifndef SCRABBLE_H
#define SCRABBLE_H
#define _CRT_SECURE_NO_WARNINGS
#define NUMBER 7

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void generate_letters(int number, char* destination);
void display_letters(char* letters, int* letter_freuency);
void ask_to_continue(char* try_again);
void input_word(char* word);

int read_array_from_file(const char* filepath, int* array, int array_length);
int process_word(char* word, int* frequency, int* letter_values, struct node* head);
int tally_points(int* points, int word_worth, char* word);

#endif