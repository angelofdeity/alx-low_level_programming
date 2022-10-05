/**
* free_grid - Frees allocated memory
* @grid: Grid to be freed
* @height: height of grid
*/
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0 ; i < height ; i++)
	{
		free(grid[i]);
	}
}
