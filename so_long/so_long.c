

/*#include <mlx.h>

int	main(void)
{
	void *mlx;
	void *windows;
	int ancho;
	int alto;
    void *img;
	int *close;

	mlx = mlx_init();
	windows = mlx_new_window(mlx, 1000, 1000, "nueva ventana");
	img = mlx_xpm_file_to_image(mlx, "/Users/bfebles-/Desktop/github/so_long/xpmd", &ancho, &alto);

	//mlx_put_image_to_window(mlx, windows,img, 0, 0);
	//close = mlx_destroy_window(mlx, windows);
	mlx_loop(mlx);
}
*/


#include "so_long.h"

int main(void)
{
	t_data *data;
	data = malloc(sizeof(t_data));
	if(!data)
		return(0);
	
	int i;
	int j;
	int width;
	int height;

    data->mlx = mlx_init();

    data->win.width = 10 * 64;
    data->win.height = 10 * 64;
    data->win.window = mlx_new_window(data->mlx, data->win.width, data->win.height, "pepe");

    char *image_dog = "xpmd/suelo.xpm";
	data->imgsuelo = mlx_xpm_file_to_image(data->mlx, image_dog, &width, &height);
	i = 0;
	while((i * 64) < data->win.height)
	{
		j = 0;
		while((j * 64) < data->win.width)
		{
    		mlx_put_image_to_window(data->mlx, data->win.window, data->imgsuelo, (j * 64), (i * 64));
			++j;
		}
		++i;
	}
	data->player.img = mlx_xpm_file_to_image(data->mlx, "xpmd/perro.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->win.window, data->player.img, 0, 0);

	data->galleta = mlx_xpm_file_to_image(data->mlx, "xpmd/Galleta.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->win.window, data->galleta, 210, 0);

	data->galleta = mlx_xpm_file_to_image(data->mlx, "xpmd/Galleta.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->win.window, data->galleta, 220, 0);

    // if (image == 0)
    // {
    //     return 1;
    // }
    mlx_loop(data->mlx);
   //mlx_destroy_window(mlx, window);

    return 0;
}
