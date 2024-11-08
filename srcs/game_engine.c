#include "../includes/mm.h"
#include "../includes/utils.h"

void	IA_pawns(s_pawn ia_pawns[NB_PAWNS])
{
	int	i;

	i = 0;
	srand(time(NULL));
	while (i < NB_PAWNS)
	{
		ia_pawns[i].color = ft_strdup(INT_TO_COLOR((rand() % 7) + 1));
		ia_pawns[i].position = i;
		i++;
	}
}

int	is_user_input_validated(char *input)
{
	(void) input;
	return (1);
}

int	board_resolve(s_board *board, s_pawn ia_pawns[NB_PAWNS])
{
	(void) board;
	(void) ia_pawns;
	return (0);
}

void	end(s_board *board)
{
	(void) board;
}

void	run(s_board *board, s_pawn ia_pawns[NB_PAWNS])
{
	char	input[NB_PAWNS];
	int		is_win;

	is_win = 0;
	while (board->round++ < NB_ROUNDS)
	{
		show_board(board);

		ft_strlcpy(input, "0000", NB_PAWNS + 1);
		while (!is_user_input_validated(input))
			show_board(board);

		is_win = board_resolve(board, ia_pawns);

		if (is_win)
			break;
	}
	end(board);
}

void	start()
{
	s_board	*board;
	s_pawn	ia_pawns[NB_PAWNS];

	board = malloc(sizeof(s_board));
	if (!board)
		exit(1);
	init_board(board);
	IA_pawns(ia_pawns);

	run(board, ia_pawns);

	// free_board(board);
}
