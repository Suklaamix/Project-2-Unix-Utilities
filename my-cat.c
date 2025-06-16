#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        return 0;
    }
    for (int i = 1; i < argc; i++){
        FILE *file = fopen(argv[i], "r");
        if (file == NULL){
            printf("my-cat: cannot open file\n");
            return 1;
        }
        char *line = NULL;
        size_t size = 0;
        while (getline(&line, &size, file) != -1){
            printf("%s", line);
        }
        free(line);
        line = NULL;
        fclose(file);
    }
    return 0;
}

