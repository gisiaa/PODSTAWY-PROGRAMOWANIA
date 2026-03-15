#include <iostream>
#include "math.h"

using namespace std;

/* ZADANIE 1*/
double SUMA_SZEREGU(double eps){
    double result = 0, power, division, res_szereg;
    for (int i = 0; ;++i){
        power = pow(-1, i+1);
        division = 2*i-1;
        res_szereg = power * 4/division;
        result += res_szereg;
        if (res_szereg > 0 && res_szereg < eps){
            return result;
        }
        if (res_szereg < 0 && res_szereg*-1 < eps){
            return result;
        }
    }
}

/* ZADANIE 2*/
void USUN_SAMOGLOSKI(char* str){
    int size = 0;
    while (str != NULL) size++;

    for (int i = 0; i < size; ++i) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){
            for(int j = i; j < size - 1; ++size){
                str[j] = str[j+1];
            }
        }
    }
    for(int i = 0; i < size; ++i)
        printf("%c", str[i]);
}

/* ZADANIE 3*/
void TABLICA_IND(float tab[]){
    float maxnum = 0, minnum = 0;
    for (int i = 0; i < 10; ++i) {
        tab[i] = rand() % 50;
        printf("| %f |", tab[i]);

        maxnum = max(maxnum, tab[i]);
        minnum = min(minnum, tab[i]);
    }

    printf("\nMax: %f\nMin: %f\n", maxnum, minnum);
}
void TABLICA_WSK(float tab[]){
    float maxnum = 0, minnum = 0;
    for (int i = 0; i < 10; ++i) {
        *(tab + i) = rand() % 50;
        printf("| %f |", *(tab + i));

        maxnum = max(maxnum, *(tab + i));
        minnum = min(minnum, *(tab + i));
    }

    printf("\nMax: %f\nMin: %f\n", maxnum, minnum);
}

/* ZADANIE 4*/
void TABELKA(int wierszy, int kolumn){
    for (int i = 0; i < kolumn; ++i) {
        if (i == 0){
            printf("%5s#", "");
            for (int j = 0; j < wierszy; ++j) {
                printf("=====|");
            }
            printf("\n");
            printf("%5s#", "");
            for (int j = 0; j < wierszy; ++j) {
                printf("%4d%1s|", j, "");
            }
            printf("\n");
            printf("|====#");
            for (int j = 0; j < wierszy; ++j) {
                printf("=====|");
            }
            printf("\n");
        }
        printf("|----#");
        for (int j = 0; j < wierszy; ++j) {
            printf("%4d%1s|", i*j, "");
        }
        printf("\n");
        printf("|----#");
        for (int j = 0; j < wierszy; ++j) {
            printf("-----|");
        }
        printf("\n");
    }
}

/* ZADANIE 5*/
struct Structure{
    unsigned short x;
    unsigned short y;
};
Structure* TABLICA_STRUKTUR(){
    Structure* ptr = (Structure*)malloc(sizeof(Structure)*10);
    if (ptr == nullptr){
        return nullptr;
    }
    for (int i = 0; i < 10; ++i) {
        ptr[i].x = rand() % 100;
        ptr[i].y = rand() % 100;
    }
    return ptr;
}

int main() {
    // task1
    double eps;
    printf("Enter eps: ");
    //scanf("%lf", &eps); // didn't have luck with this one but that SHOULD work
    cin >> eps;
    if (eps > 0 && eps < 1){
        double suma = SUMA_SZEREGU(eps);
        printf("Suma: %f", suma);

    } else {
        printf("Input error!");
    }

    // task2
    char str[50];
    printf("Enter 50 chars: ");
    fflush(stdin);
    fgets(str, 50, stdin);
    USUN_SAMOGLOSKI(str);

    // task3
    srand(time(NULL));
    float arr[10];
    TABLICA_IND(&arr[0]);
    TABLICA_WSK(&arr[0]);

    // task4
    int wierszy, kolumn;
    printf("Enter the amount of rows: ");
    scanf("%d", &wierszy);

    printf("Enter the amount of columns: ");
    scanf("%d", &kolumn);

    TABELKA(wierszy, kolumn);

    // task5
    srand(time(NULL));

    Structure* ptr = TABLICA_STRUKTUR();
    if (ptr == nullptr){
        printf("Memory allocation error!");
    }
    for (int i = 0; i < 10; ++i) {
        printf("(%d %d)", ptr[i].x, ptr[i].y);
    }
    free(ptr);

    system("pause");
    return 0;
}
