#include <stdio.h>
#include <stdio.h>
#include <memory.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char buf[256];
    const char* mode;
    FILE* file;

    for (int i = 1 ; i < argc; i ++){
        if (strcmp(argv[i], "-a") == 0)
            mode = "a";
        else
        	mode = "w";
    }
    fread(buf, 1, 256, stdin);
    for (int i = 1; i < argc; i ++){
    	if (strcmp(argv[i], "-a") == 0)
            continue;
        file = fopen(argv[i], mode);
        fprintf(file, "%s", buf);
        fclose(file);
    }
    printf("%s", buf);
    return 0;
}




