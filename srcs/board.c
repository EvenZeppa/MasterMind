#include "../includes/mm.h"
#include "../includes/utils.h"

s_pawn	*create_pawn(const char *color, int position)
{
	s_pawn	*pawn;

	pawn = malloc(sizeof(s_pawn));
	if (!pawn)
		exit(1);
	pawn->color = ft_strdup(color);
	pawn->position = position;
	return (pawn);
}

void	print_empty_line()
{
	int	i;
	int	j;

	i = 0;
	while (i++ < 3)
	{
		j = 0;
		while (j++ < (NB_PAWNS * 2) - 1)
			printf(" ");
		if (i != 3)
			printf(" " DIVIDER_CHR " ");
	}
	printf("\n");
}

void	init_board(s_board *board)
{
	int	i;
	int	j;

	i = 0;
	while (i < NB_ROUNDS)
	{
		j = 0;
		while (j < NB_PAWNS)
		{
			board->color_clues[i][j] = create_pawn(WHITE_COLOR, j);
			board->user_pawns[i][j] = create_pawn(WHITE_COLOR, j);
			board->color_pos_clues[i][j] = create_pawn(WHITE_COLOR, j);
			j++;
		}
		i++;
	}
}

void	show_board(s_board *board)
{
	int		i;
	int		j;

	i = 0;
	while (i < NB_ROUNDS)
	{
		j = 0;
		while (j < NB_PAWNS)
		{
			printf("%s" PAWN_CHR WHITE_COLOR, board->color_clues[i][j]->color);
			if (j != NB_PAWNS - 1)
				printf(" ");
			j++;
		}
		printf(" " DIVIDER_CHR " ");
		j = 0;
		while (j < NB_PAWNS)
		{
			printf("%s" PAWN_CHR WHITE_COLOR, board->user_pawns[i][j]->color);
			if (j != NB_PAWNS - 1)
				printf(" ");
			j++;
		}
		printf(" " DIVIDER_CHR " ");
		j = 0;
		while (j < NB_PAWNS)
		{
			printf("%s" PAWN_CHR WHITE_COLOR, board->color_pos_clues[i][j]->color);
			if (j != NB_PAWNS - 1)
				printf(" ");
			j++;
		}
		printf("\n");
		if (i != NB_ROUNDS - 1)
			print_empty_line();
		i++;
	}
}
