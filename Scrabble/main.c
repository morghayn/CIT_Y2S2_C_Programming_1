#include "linked_list.h"
#include "scrabble.h"
#define _CRT_SECURE_NO_WARNINGS
#define NUMBER 7

void driver(int* letter_frequency, int* letter_values)
{
	char word[NUMBER + 1], try_again = 'y';
	int frequency[26], points = 0;
	struct node* head = NULL;

	while (try_again != 'n')
	{
		memcpy(frequency, letter_frequency, 26 * sizeof(int));
		input_word(word);

		if (tally_points(&points, process_word(word, frequency, letter_values, head), word) != -1)
		{
			head = insert_front(head, word);
		}

		ask_to_continue(&try_again);
	}

	print_nodes(head);
	release_nodes(head);
}

int main()
{
	char letters[NUMBER + 1];
	int letter_values[26], letter_frequency[26] = { 0 };

	if (read_array_from_file("letter_values", letter_values, 26) != -1)
	{
		generate_letters(NUMBER, letters);
		letters[NUMBER] = '\0';

		display_letters(letters, letter_frequency);
		driver(letter_frequency, letter_values);
	}
	else
	{
		printf("> file for letter values is missing or corrupt.\n");
	}

	system("pause"); // i think this a windows thing so heads up
	return 0;
}
