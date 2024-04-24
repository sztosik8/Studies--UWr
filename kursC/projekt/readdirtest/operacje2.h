int GetPath(char *s, int y_path, int x_path);
void Clear(char dir_path[]);
void Empty(char name[]);
int sim_or_dup(int choice, int y_choice, int x_choice_dup, int x_choice_sim);
char *ha_value(char *output_file, char *filename, unsigned char *img, int width, int height, int channels);
int duplicate(int similarity, char *dir_path, char *str1, char *filename1, int num);
int hammingDistance(char *str1, char *str2);

