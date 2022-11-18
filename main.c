#include "mlx.h"

int main(void)
{
    void *ptr;
    void *janela;

    ptr = mlx_init();
    janela = mlx_new_window(ptr, 100, 100, "janelinha");
    mlx_loop(ptr);
}
