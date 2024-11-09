#include "../includes/mm.h"
#include "../includes/utils.h"

void	IA_pawns(s_pawn *ia_pawns)
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

int	is_str_valable_color(char *str)
{
	while (*str)
	{
		if (*str != '1' &&
			*str != '2' &&
			*str != '3' &&
			*str != '4' &&
			*str != '5' &&
			*str != '6' &&
			*str != '7')
			return (0);
		str++;
	}
	return (1);
}

void	user_input(s_board *board, char *input)
{
	int	i;
	int	can_validate;

	can_validate = 0;
	while (1)
	{
		printf( "\n"
			RED_COLOR PAWN_CHR " " 
			GREEN_COLOR PAWN_CHR " "
			YELLOW_COLOR PAWN_CHR " "
			BLUE_COLOR PAWN_CHR " "
			PURPLE_COLOR PAWN_CHR " "
			CYAN_COLOR PAWN_CHR " "
			WHITE_COLOR PAWN_CHR "\n");
		printf("1 2 3 4 5 6 7\n");

		if (can_validate)
			printf("Type " GREEN_COLOR "y" WHITE_COLOR " to validate your choice or another combination : ");
		else
			printf("Type a combination : ");
		scanf("%s", input);
		if (can_validate && input[0] == 'y')
			break;
		if (ft_strlen(input) != NB_PAWNS)
			printf(RED_COLOR "ERROR" WHITE_COLOR " : Number digits = %d\n", NB_PAWNS);
		else if (!is_str_valable_color(input))
			printf(RED_COLOR "ERROR" WHITE_COLOR " : Valable inputs = (1 -> 7)\n");
		else
		{
			i = 0;
			while (i < NB_PAWNS)
			{
				board->user_pawns[board->round][i]->color = INT_TO_COLOR(input[i] - '0');
				i++;
			}
			can_validate = 1;
		}
		show_board(board);
	}
}

int	board_resolve(s_board *board, s_pawn *ia_pawns)
{
	int	c;
	int	cp;
	int	i;
	int	j;
	int	states[NB_PAWNS] = {0};

	c = NB_PAWNS - 1;
	cp = 0;
	i = 0;
	while (i < NB_PAWNS)
	{
		if (board->user_pawns[board->round][i]->position == ia_pawns[i].position &&
			memcmp(board->user_pawns[board->round][i]->color, ia_pawns[i].color, 7) == 0)
		{
			states[i] = 1;
			board->color_pos_clues[board->round][cp]->color = RED_COLOR;
			cp++;
		}
		i++;
	}
	i = 0;
	while (i < NB_PAWNS)
	{
		j = 0;
		while (j < NB_PAWNS)
		{
			if (i != j && states[j] == 0 && memcmp(board->user_pawns[board->round][i]->color, ia_pawns[j].color, 8) == 0)
			{
				states[j] = 1;
				board->color_clues[board->round][c]->color = WHITE_COLOR;
				c--;
				break;
			}
			j++;
		}
		i++;
	}
	if (cp == NB_PAWNS)
		return (1);
	return (0);
}

void	end(s_board *board, s_pawn *ia_pawns)
{
	int	i;
	
	if (board->round == NB_ROUNDS)
		printf(RED_COLOR "You left !!!\n" WHITE_COLOR);
	else
		printf(GREEN_COLOR "You won !!!\n" WHITE_COLOR);
	printf("The combination was : " );
	i = 0;
	while (i < NB_PAWNS)
	{
		printf("%s" PAWN_CHR " ", ia_pawns[i].color);
		i++;
	}
	printf(WHITE_COLOR);
}

void	run(s_board *board, s_pawn *ia_pawns)
{
	char	*input;
	int		is_win;

	is_win = 0;
	input = malloc(sizeof(char) * 128);
	while (board->round < NB_ROUNDS)
	{
		show_board(board);

		user_input(board, input);

		is_win = board_resolve(board, ia_pawns);

		if (is_win)
			break;
		board->round++;
		printf(BLUE_COLOR "\n=====================\n\n");
	}
	show_board(board);

	end(board, ia_pawns);
}

void	start()
{
	s_board	*board;
	s_pawn	*ia_pawns;

	board = malloc(sizeof(s_board));
	ia_pawns = malloc(sizeof(s_pawn) * NB_PAWNS);
	if (!board)
		exit(1);
	init_board(board);
	IA_pawns(ia_pawns);

	run(board, ia_pawns);

	free_board(board);
}
