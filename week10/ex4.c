#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


int main() {
	DIR *dir;
	struct dirent *entry;
	struct stat file_stat;  
	dir = opendir("tmp/");

	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		char* path[20];
		strcpy(path, "tmp/");
		strcat(path, entry->d_name);
		int ret;
		ret = stat (path, &file_stat);
		if (file_stat.st_nlink >= 2) {
			printf("%s ", entry->d_name);
		}
	}
	printf("\n");
	closedir(dir);
	return 0;
}