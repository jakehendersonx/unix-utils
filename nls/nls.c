// a neo-ls
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void) {

	DIR *dir;
	struct dirent *entry;
	// this dir only for now
	dir = opendir(".");
	if (dir == NULL) {
		perror("you can't open that one...");
		return 1;
	}
	// read dir entry until done
	// filter out hidden files that start w . 
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.') {
			if (entry->d_type == DT_DIR) {
				printf("%s\n", entry->d_name);
			} else {
				printf("%s\n", entry->d_name);
			}
		}
	}
	closedir(dir);
	return 0;
}
