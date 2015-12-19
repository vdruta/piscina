#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_back(int vfi, int vfj, char **tab, int *ok, char **tab2);
void	ft_go_next(int vfi, int vfj, char **tab, int *ok, char **tab2);
#endif
/*
"9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
*/
