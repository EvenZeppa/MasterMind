#include "../includes/mm.h"

int	main(void)
{
	s_board	*board;

	board = malloc(sizeof(s_board));

	// printf("%lx", sizeof(s_board));

	init_board(board);
	show_board(board);
}
