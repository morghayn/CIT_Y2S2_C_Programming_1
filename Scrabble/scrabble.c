#include "scrabble.h"

void ask_to_continue(char* try_again)
{
	printf("\n> Try again? (y/n)\t"); // defaults to 'y' in driver function
	int ch;
	ch = getchar();
	while ('\n' != getchar());
	*try_again = ch;
	printf("\n");
}

int tally_points(int* points, int word_worth, char* word)
{
	if (word_worth == -1)
	{
		return -1;
	}

	*points += word_worth;
	printf("You used: %s.\nWorth: %i.\nCurrent total: %d\n", word, word_worth, *points);

	return 0;
}

int process_word(char* word, int* frequency, int* values, struct node* head)
{
	char invalid_letters[NUMBER + 1];
	int invalid_attempts = 0, points = 0;

	if (is_word_doop(head, word) != -1)
	{
		printf("> Word is a doop, sorry but try again.\n");
		return -1;
	}

	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z' && frequency[word[i] - 'a'] != 0)
		{
			points += values[word[i] - 'a'];
			frequency[word[i] - 'a']--;
		}
		else
		{
			invalid_letters[invalid_attempts] = word[i];
			invalid_attempts++;
			invalid_letters[invalid_attempts] = '\0';
		}
	}

	if (invalid_attempts != 0)
	{
		printf(invalid_attempts > 1 ? "letters " : "letter ");

		for (int i = 0; i < invalid_attempts; i++)
		{
			printf(i == invalid_attempts - 1 ? "%c not available\n" : "%c, ", invalid_letters[i]);
		}

		printf("Not enough letters available to make:\t%s\n", word);
		return -1;
	}

	return points;
}

void input_word(char* word)
{
	printf("> Input word:\t\t");
	if (fgets(word, NUMBER + 1, stdin)) 
	{
		char* p;

		if (p = strchr(word, '\n')) 
		{
			*p = 0;
		}
		else 
		{
			scanf("%*[^\n]"); 
			scanf("%*c");
		}
	}

	for (int i = 0; word[i]; i++) 
	{
		word[i] = tolower(word[i]);
	}
}

void display_letters(char* letters, int* letter_frequency)
{
	for (int i = 0; letters[i] != '\0'; i++)
	{
		letter_frequency[letters[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		printf(letter_frequency[i] == 0 ? "" : "%c ---> %d\n", i + 'a', letter_frequency[i]);
	}
	printf("\n");
}

int read_array_from_file(const char* filepath, int* array, int array_length)
{
	FILE* file; int i;

	if ((file = fopen(filepath, "r")) == NULL)
	{
		return -1;
	}

	for (i = 0; i < array_length; i++)
	{
		if (fscanf(file, "%d", &array[i]) == EOF) break;
	}

	return i;
}

void generate_letters(int number, char* destination)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	int i, rand_seed;

	printf("Number < 1000:\t");
	scanf_s("%d", &rand_seed);
	getchar();
	srand(rand_seed);

	for (i = 0; i < number / 2; i++, destination++)
	{
		*destination = vowels[rand() % 5];
	}

	for (; i < number; i++, destination++)
	{
		*destination = rand() % 26 + 'a';
	}
}