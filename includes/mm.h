#ifndef MM_H
# define MM_H

# include <stdio.h>
# include <stdlib.h>

# define PAWN_CHR "\u2588"
# define DIVIDER_CHR "\u2503"

# define BLACK_COLOR "\033[0;30m"
# define RED_COLOR "\033[0;31m"
# define GREEN_COLOR "\033[0;32m"
# define YELLOW_COLOR "\033[0;33m"
# define BLUE_COLOR "\033[0;34m"
# define PURPLE_COLOR "\033[0;35m"
# define CYAN_COLOR "\033[0;36m"
# define WHITE_COLOR "\033[0;37m"

# define NB_ROUNDS 12
# define NB_PAWNS 4

typedef struct	t_pawn
{
	char	*color;
	int		position;
}	s_pawn;

typedef struct	t_board
{
	s_pawn	*color_clues[NB_ROUNDS][NB_PAWNS];
	s_pawn	*user_pawns[NB_ROUNDS][NB_PAWNS];
	s_pawn	*color_pos_clues[NB_ROUNDS][NB_PAWNS];
}	s_board;

void	init_board(s_board *board);
void	show_board(s_board *board);

#endif
