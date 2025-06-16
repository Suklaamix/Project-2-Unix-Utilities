#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    if (argc < 2){
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++){
        FILE *file = fopen(argv[i], "r");
        if (file == NULL ){
            printf("my-zip: cannot open file\n");
            exit(1);
        }
        char New_char = fgetc(file);
        if (New_char == EOF) {
            fclose(file);
            exit(0);
        }
        int Count = 1;
        char Current_char = New_char;
        while ((New_char = fgetc(file)) != EOF ) {
            if (New_char == Current_char){
                Count++;
            } else {
                fwrite(&Count, sizeof(int),1,stdout);
                fwrite(&Current_char,sizeof(char),1,stdout);
                Current_char = New_char;
                Count = 1;
            }
        }
        fwrite(&Count, sizeof(int), 1, stdout);
        fwrite(&Current_char, sizeof(char), 1, stdout);
        fclose(file);
    }
    return 0;
}