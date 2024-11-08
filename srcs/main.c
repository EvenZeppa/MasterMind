#include "../includes/mm.h"
#include "../includes/utils.h"

int	main(void)
{
	s_board	*board;

	board = malloc(sizeof(s_board));

	// printf("%lx", sizeof(s_board));

	init_board(board);
	show_board(board);

	printf("\n\n");

	board->user_pawns[7][3]->color = ft_strdup(RED_COLOR);

	show_board(board);

	free_board(board);
}
