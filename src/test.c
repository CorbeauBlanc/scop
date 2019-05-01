# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_test
{
	float x;
	float y;
	float z;
}				t_test;

int main(int argc, char const *argv[])
{
	t_test tab[3] = {
		(t_test){1, 2, 3},
		(t_test){4, 5, 6},
		(t_test){7, 8, 9}
	};

	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3;j++)
			printf("%f", tab[i].x);

	return 0;
}
