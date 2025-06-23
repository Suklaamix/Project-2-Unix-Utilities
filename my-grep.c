#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
    }
    char *line = NULL;
    size_t size = 0;
    if (argc == 2){
        FILE *file = stdin;
        while (getline(&line, &size, file) != -1){
            if (strstr(line, argv[1]) != NULL){
                printf("%s", line);
            }
        }
    }else {
        for (int i = 2; i < argc; i++){
            FILE *file = fopen(argv[i], "r");
            if (file == NULL){
                printf("my-grep: cannot open file %s\n", argv[i]);
                exit(1);
            }
            while (getline(&line, &size, file) != -1){
                if (strstr(line, argv[1]) != NULL){
                    printf("%s", line);
                }
            }
            fclose(file);
        }
    }
    free(line);
    return 0;
}

