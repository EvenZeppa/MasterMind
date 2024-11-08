#ifndef MM_H
# define MM_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

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

# define INT_TO_COLOR(i)	( \
							(i) == 0 ? BLACK_COLOR :\
							(i) == 1 ? RED_COLOR :\
							(i) == 2 ? GREEN_COLOR :\
							(i) == 3 ? YELLOW_COLOR :\
							(i) == 4 ? BLUE_COLOR :\
							(i) == 5 ? PURPLE_COLOR :\
							(i) == 6 ? CYAN_COLOR :\
							(i) == 7 ? WHITE_COLOR : "\033[0m" \
							)

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
	int		round;
}	s_board;

void	init_board(s_board *board);
void	show_board(s_board *board);
void	free_board(s_board *board);

void	start();

#endif
