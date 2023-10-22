#include "deck.h"
#include <string.h>


/**
 * get_card_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_card_value(deck_node_t *card)
{
	if (strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (strcmp(card->card->value, "1") == 0)
		return (1);
	if (strcmp(card->card->value, "2") == 0)
		return (2);
	if (strcmp(card->card->value, "3") == 0)
		return (3);
	if (strcmp(card->card->value, "4") == 0)
		return (4);
	if (strcmp(card->card->value, "5") == 0)
		return (5);
	if (strcmp(card->card->value, "6") == 0)
		return (6);
	if (strcmp(card->card->value, "7") == 0)
		return (7);
	if (strcmp(card->card->value, "8") == 0)
		return (8);
	if (strcmp(card->card->value, "9") == 0)
		return (9);
	if (strcmp(card->card->value, "10") == 0)
		return (10);
	if (strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_by_kind - Sort a deck of cards in ascending order based on suits.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Description: Uses insertion sort algorithm to sort the deck from
 * sades to diamonds.
 */
void sort_by_kind(deck_node_t **deck)
{
	deck_node_t *current, *insertion, *tmp;

	for (current = (*deck)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insertion = current->prev;
		while (insertion != NULL && insertion->card->kind > current->card->kind)
		{
			insertion->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion;
			current->prev = insertion->prev;
			current->next = insertion;
			if (insertion->prev != NULL)
				insertion->prev->next = current;
			else
				*deck = current;
			insertion->prev = current;
			insertion = current->prev;
		}
	}
}

/**
 * sort_by_value - Sort a deck of cards in ascending order based on values.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Description: Uses insertion sort algorithm to sort the deck from
 * ace to king within each suit.
 */
void sort_by_value(deck_node_t **deck)
{
	deck_node_t *current, *insertion, *tmp;

	for (current = (*deck)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insertion = current->prev;
		while (insertion != NULL &&
		       insertion->card->kind == current->card->kind &&
		       get_card_value(insertion) > get_card_value(current))
		{
			insertion->next = current->next;
			if (current->next != NULL)
				current->next->prev = insertion;
			current->prev = insertion->prev;
			current->next = insertion;
			if (insertion->prev != NULL)
				insertion->prev->next = current;
			else
				*deck = current;
			insertion->prev = current;
			insertion = current->prev;
		}
	}
}
/**
 * sort_deck - Sort a deck of cards in ascending order based on suits
 * and values.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Description: Sorts the deck first by suits and then by values within
 * each suit using insertion sort.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_by_kind(deck);
	sort_by_value(deck);
}
