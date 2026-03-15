#include <stdio.h>
#include <math.h>
// Małgorzata Strusińska, poniedziałek parzysty 13:15, zadanie laboratorium 01, Data utworzenia 14.10.2024 godz. 13:15, Data modyfikacji 24.10.2024
int potegadruga(int liczba) {
    return liczba * liczba;
}

float potegadrugadlafloata(float wartosc) {
    return wartosc * wartosc;
}

bool czy_rok_przestepny(int rok) {
    if ((rok % 4 != 0) || (rok % 400 != 0 && rok % 100 == 0)) {
        return false;
    }
    return true;
}

bool czy_luty(int miesiac) {
    if (miesiac == 02) {
        return true;
    }
    return false;
}

void makssrodekmin(int d, int e, int f, int &najwieksza, int &srodkowa, int &najmniejsza) {
    if (d >= e && d >= f) {
        najwieksza = d;
        if (e >= f) {
            srodkowa = e;
            najmniejsza = f;
        } else {
            srodkowa = f;
            najmniejsza = e;
        }
    } else if (e >= d && e >= f) {
        najwieksza = e;
        if (d >= f) {
            srodkowa = d;
            najmniejsza = f;
        } else {
            srodkowa = f;
            najmniejsza = d;
        }
    } else {
        najwieksza = f;
        if (d >= e) {
            srodkowa = d;
            najmniejsza = e;
        } else {
            srodkowa = e;
            najmniejsza = d;
        }
    }
}

bool czy_31dni(int miesiac) {
    int miesiace_wiecejdni[7] = {1, 3, 5, 7, 8, 10, 12};
    for (int i = 0; i < 7; i++) {
        if (miesiace_wiecejdni[i] == miesiac) {
            return true;
        }
    }
    return false;
}


void zadanie1() {
    int a, b, c;
    int delta = 0;
    int x1 = 0, x2 = 0;
    int powdwojny_pierwiastek = 0;
    printf("ZADANIE 1\n\n");
    printf("Podaj pierwszy wspolczynnik: ");
    scanf("%d", &a);
    printf("Podaj drugi wspolczynnik: ");
    scanf("%d", &b);
    printf("Podaj trzeci wspolczynnik: ");
    scanf("%d", &c);
    printf("\n");
    if (a == 0) {
        printf("Nie jest to rownanie kwadratowe\n\n");
    }
    if (a != 0) {
        delta = potegadruga(b) - 4 * a * c;
        if (delta < 0) {
            printf("Brak pierwiastkow rzeczywistych\n\n");
        }
        else if (delta == 0) {
            powdwojny_pierwiastek = -b/2*a;
            printf("Istnieje podwojny pierwiastek =%d\n\n",powdwojny_pierwiastek);
        }
        else if (delta > 0) {
            x1 = (-b - sqrt(delta))/(2*a);
            x2 = (-b + sqrt(delta))/(2*a);
            printf("Pierwszy pierwiastek = %d\nDrugi pierwiastek = %d\n\n", x1, x2);
        }
    }
}
void zadanie2() {
    printf("ZADANIE 2\n\n");

    int g, h, j;
    printf("Podaj 3 liczby w formacje dd mm rrrr: ");
    scanf("%2d-%2d-%4d", &g, &h, &j);
    if ((g <= 29 && g>0) && czy_rok_przestepny(j) == true && czy_luty(h) == true) {
        printf("%d-%d-%d To poprawna data\n\n", g, h ,j);
    }
    else if ((g <= 28 && g>0) && czy_rok_przestepny(j) == false && czy_luty(h) == true) {
        printf("%d-%d-%d To poprawna data\n\n", g, h ,j);
    }
    else if ((g <= 31 && g> 0) && (h != 2 && (h <= 12 && h>0) && czy_31dni(h) == true) && j >= 0) {
        printf("%d-%d-%d To poprawna data\n\n", g, h ,j);
    }
    else if ((g <= 30 && g>0) && (h != 2 && (h <= 12 && h>0) && czy_31dni(h) == false) && j >= 0) {
        printf("%d-%d-%d To poprawna data\n\n", g, h ,j);
    }
    else {
        printf("%d-%d-%d To niepoprawna data\n\n", g, h ,j);
    }
}
void zadanie3() {
    printf("ZADANIE 3\n\n");

    int x, y, z;
    int najwieksza, srodkowa, najmniejsza;
    printf("Podaj długość boku x: ");
    scanf("%d", &x);
    printf("Podaj wartość boku y: ");
    scanf("%d", &y);
    printf("Podaj wartość boku z: ");
    scanf("%d", &z);
    makssrodekmin(x, y, z, najwieksza, srodkowa, najmniejsza);
    if (najwieksza < srodkowa + najmniejsza) {
        if (((x == z && x != y) || ((y == x) && y != z) || (y == z && y != x)) && (potegadruga(srodkowa) + potegadruga(najmniejsza) < potegadruga(najwieksza))) {
            printf("Trójkąt równoramienny, rozwartokątny\n\n");
        }
        else if (((x == z && x != y) || ((y == x) && y != z) || (y == z && y != x)) && (potegadruga(srodkowa) + potegadruga(najmniejsza) > potegadruga(najwieksza))) {
            printf("Trójkąt równoramienny, ostrokątny\n\n");
        }
        else if (x == y && y == z){
            printf("Jest to trójkąt równoboczny, ostrokątny\n\n");

        } else if (potegadruga(srodkowa) + potegadruga(najmniejsza) == potegadruga(najwieksza)) {
            printf("Jest to trójkąt prostokątny\n\n");
        }
        else if (((x == z && x != y) || ((y == x) && y != z) || (y == z && y != x)) && (potegadruga(srodkowa) + potegadruga(najmniejsza) == potegadruga(najwieksza))) {
            printf("Jest to trójkąt równoramienny, prostokątny");
        }
        else if (potegadruga(srodkowa) + potegadruga(najmniejsza) < potegadruga(najwieksza)) {
            printf("Jest to trójkąt rozwartokątny\n\n");
        }
        else if
        (potegadruga(srodkowa) + potegadruga(najmniejsza) > potegadruga(najwieksza)) {
            printf("Jest to trójkąt ostrokątny\n\n");
        }

    } else {
        printf("Nie jest to trójkąt\n\n");
    }
}

void zadanie4() {

    printf("ZADANIE 4\n\n");
    int promien_min, promien_max, liczba_wierszy;
    printf("Podaj minimalny promień: ");
    scanf("%d", &promien_min);
    printf("Podaj maksymalny promień: ");
    scanf("%d", &promien_max);
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &liczba_wierszy);
    printf("=========================================\n");
    printf("| Lp | Promien | Obwod kola | Pole kola |\n");
    printf("=========================================\n");
    int nr_wierszy = 0;
    float obwod_kola = 0;
    float pole_kola = 0;
    float promien = promien_min;
    float co_ile = (float)(promien_max - promien_min) / (liczba_wierszy - 1);
    for (int l=1; l <= liczba_wierszy; l++) {
        nr_wierszy += 1;
        obwod_kola = 2*M_PI*promien;
        pole_kola = M_PI*potegadrugadlafloata(promien);
        printf("| %2d | %7.2f | %10.2f | %9.2f |\n", nr_wierszy, promien, obwod_kola, pole_kola);
        promien += co_ile;
    }
    printf("=========================================\n");
    printf("\n\n");
}

int main() {
    int lista_wyboru;

    printf("Autor: Małgorzata Strusińska, PnP 13:15, Data utworzenia: 14.10.2024, Godzina: 13:15, Data modyfikacji 24.10.2024\n\n");
    while (true) {
        printf("Wybierz zadanie:\n");
        printf("1. ZADANIE 1\n");
        printf("2. ZADANIE 2\n");
        printf("3. ZADANIE 3\n");
        printf("4. ZADANIE 4\n");
        printf("0. WYJŚCIE\n");
        printf("Podaj numer zadania: ");
        scanf("%d", &lista_wyboru);

        switch (lista_wyboru) {
            case 1:
                zadanie1();
            break;
            case 2:
                zadanie2();
            break;
            case 3:
                zadanie3();
            break;
            case 4:
                zadanie4();
            break;
            case 0:
                return 0;
        }
    }
}
