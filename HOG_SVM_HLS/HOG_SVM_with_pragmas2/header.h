




#define min_wdw_sz_r 100
#define min_wdw_sz_c 40

#define step_size_r 10
#define step_size_c 10

#define B_ROW  3
#define B_COL  3




#define orientations  9
#define pixels_per_cell_r  5
#define pixels_per_cell_c 	5
#define cells_per_block_r  3
#define cells_per_block_c  3


#define n_cells_row 8 // s_row / c_row;
#define n_cells_col 20 // s_col / c_col;


#define n_blocks_row 6 // (n_cells_row - b_row) + 1;
#define n_blocks_col 18 // (n_cells_col - b_col) + 1;

float hog_hls(float *image);
