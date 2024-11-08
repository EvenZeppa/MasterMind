#include "../includes/mm.h"
#include "../includes/utils.h"

void	IA_pawns(s_pawn ia_pawns[NB_PAWNS])
{

}

int	is_user_input_validated(char *input)
{

}

int	board_resolve(s_board *board, s_pawn ia_pawns[NB_PAWNS])
{

}

void	start()
{
	s_board	*board;
	s_pawn	ia_pawns[NB_PAWNS];
	init_board(board);

	IA_pawns(ia_pawns);
	run(board, ia_pawns);
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

void	end(s_board *board)
{

}
