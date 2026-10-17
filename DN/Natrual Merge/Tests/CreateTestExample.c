#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nums[1000000];

int comp(const void* a, const void* b) {
  	// If a is smaller, positive value will be returned
    return (*(int*)a - *(int*)b);
}

void CreateTests(char* fileName){
    int N, k, a;
    N = rand() % 1000000;
    printf("N -> %d\n", N);
    k = rand() % 10 + 1;
    printf("K -> %d\n", k);
    a = rand() % 20 + 1;
    printf("A -> %d\n", a);

    FILE* izhodniTest = fopen(fileName, "w");

    fprintf(izhodniTest, "%d %d %d\n", N, k, a);

    for(int i = 0; i < N; i++){
        int j = rand() % 1000000;
        nums[i] = j;
        fprintf(izhodniTest, "%d\n", j);
    }

    fclose(izhodniTest);
    return;
}

/*
void CreateTests(char* name){
    printf("Got hereeee\n");
    FILE* vhod = fopen(name, "w");

    fprintf(vhod, "Hello_World");

    fclose(vhod);

    return;
}
*/

int main(int arg, char** args){

    int a;
    scanf("%d", &a);

    for(int i = 0; i < a; i++){
        char name[] = "primer___.in\0";
        if(i < 10){
            printf("Doing name operation ----\n");
            name[6] = (char)(i + '0');
            printf("Completed name operation\n");
        }
        if(i >= 10 && i < 100){
            printf("Doing this operation ----\n");
            name[6] = i/10 + '0';
            name[7] = i%10 + '0';
            printf("Completed name operation\n");
        }
        if(i >= 100){
            printf("Doing this operation ----\n");
            name[6] = (i/100) + '0';
            name[7] = (i%100)/10 + '0';
            name[8] = i%10 + '0';
            printf("Completed name operation\n");
        }
        CreateTests(name);
    }
    return 0;
}