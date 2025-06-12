#include "solong.h"
#include <stdlib.h>

int main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 200, 200, "Test");

	mlx_destroy_window(mlx, win);
	#ifdef __linux__
	mlx_destroy_display(mlx);
	free(mlx);
	#endif
	return (0);
}