#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
    }
    for (int i = 1; i < argc; i++){ 
        FILE *file = fopen(argv[i],"r");
        if (file == NULL) {
            printf("my-unzip: cannot open file\n");
            exit(1);
        }
        int Count;
        char New_char;
        while (fread(&Count, sizeof(int),1,file) == 1){
            if (fread(&New_char, sizeof(char), 1, file) == 1) {
                for (int j = 0; j < Count; j++){
                    printf("%c", New_char);
                }
            }
        }

    }
}