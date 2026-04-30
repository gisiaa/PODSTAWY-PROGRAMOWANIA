# Laboratorium 2

## Wymagania ogólne
Proszę wykonać co najmniej trzy spośród poniższych zadań!

* **Struktura kodu:** Do każdego zadania proszę napisać oddzielną funkcję. Ponadto proszę napisać funkcję `main`, w której zostaną wywołane funkcje będące rozwiązaniami poszczególnych zadań.
* **Menu (dla ambitnych):** Osoby ambitne powinny w metodzie `main` dopisać MENU umożliwiające wywoływanie poszczególnych funkcji lub zakończenie programu.
* **Komentarze i dane autora:** UWAGA: Każdy program musi być w komentarzu podpisany! Po uruchomieniu każdy program powinien na początku wyświetlać na ekranie imię i nazwisko autora. 
* **Format pliku:** Do oceny proszę wysłać tylko plik źródłowy tzn. plik z rozszerzeniem `*.cpp`.

---

## Zadanie 1: Tabliczka mnożenia
Proszę napisać funkcję, która wczytuje z klawiatury liczbę wierszy i kolumn tabliczki mnożenia, a następnie wyświetla na ekranie tabliczkę mnożenia o podanej liczbie wierszy i kolumn podobnie jak na poniższym rysunku.

**Przykładowy widok konsoli:**
```text
Program drukuje tabliczke mnozenia
Podaj liczbe wierszy: 12
Podaj liczbe kolumn: 15

     |   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
   --+------------------------------------------------------------
   1 |   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
   2 |   2   4   6   8  10  12  14  16  18  20  22  24  26  28  30
   3 |   3   6   9  12  15  18  21  24  27  30  33  36  39  42  45
 ... | ...
  12 |  12  24  36  48  60  72  84  96 108 120 132 144 156 168 180

Process returned 0 execution time : 4.379 s
Press any key to continue.
```

---

## Zadanie 2: Suma cyfr
Proszę napisać funkcję, która wczytuje z klawiatury dużą liczbę całkowitą dodatnią, a następnie oblicza i wyświetla na ekranie sumę cyfr z których składa się ta liczba.
Np. dla liczby `12345` suma cyfr wynosi `5 + 4 + 3 + 2 + 1 = 15`.

**Wskazówki:**
* Do zapamiętania dużej liczby całkowitej dodatniej proszę użyć typu `unsigned long`.
* Sumowanie można prowadzić od ostatniej cyfry do pierwszej. Ostatnia cyfra jest równa reszcie z dzielenia liczby przez 10.
* Po dodaniu ostatniej cyfry liczbę należy podzielić przez 10 (użyć operatora dzielenia całkowitoliczbowego), a następnie ponownie obliczyć i dodać ostatnią cyfrę.
* Obliczenia należy skończyć gdy zostaną posumowane wszystkie cyfry (tzn. gdy kolejna liczba będzie równa 0).

---

## Zadanie 3: NWD i NWW
Proszę napisać funkcję, która wczytuje z klawiatury dwie liczby całkowite `a` i `b`. Dla podanych liczb należy obliczyć i wypisać na ekranie największy wspólny dzielnik `nwd` oraz najmniejszą wspólną wielokrotność `nww`.

**Wskazówki:**
* `nwd` jest to największa liczba całkowita, dla której: `a % nwd == 0` oraz `b % nwd == 0`, gdzie `x % y` jest resztą z dzielenia `x` przez `y`.
* `nww` jest to najmniejsza liczba całkowita, dla której: `nww % a == 0` oraz `nww % b == 0`.
* Np. dla `a = 6` oraz `b = 9`:
  * największy wspólny dzielnik `nwd` wynosi `3`,
  * najmniejsza wspólna wielokrotność `nww` wynosi `18`.

---

## Zadanie 4: Szeregi
Proszę napisać funkcję, która wczytuje z klawiatury pożądaną dokładność obliczeń `eps` (`eps < 0.1`), a następnie oblicza i wyświetla na ekranie z zadaną dokładnością wartość sumy następujących szeregów:

$$S1 = 4 * \sum_{k=1}^{\infty} [(-1)^{k+1} * rac{1}{2k-1}] = 4 * [rac{1}{1} - rac{1}{3} + rac{1}{5} - rac{1}{7} + ...]$$

$$S2 = \sum_{k=0}^{\infty} rac{1}{k!}$$

**Wskazówki:**
* Do obliczeń proszę wykorzystywać zmienne zmiennoprzecinkowe podwójnej precyzji.
* Sumowanie szeregu należy zakończyć, gdy wartość bezwzględna pojedynczego wyrazu szeregu jest mniejsza niż zadana dokładność obliczeń `eps`.
* Wartość bezwzględną liczb rzeczywistych zwraca funkcja `fabs(x)` dostępna w bibliotece `<math.h>`.
* W trakcie obliczeń **proszę nie wykorzystywać funkcji `pow` !!!**
* Proszę nie pisać dodatkowej funkcji do obliczania wartości silni. Zamiast tego proszę wykorzystać wartość uzyskaną przy obliczaniu poprzedniego wyrazu szeregu.
* Suma szeregu `S1` jest zbieżna do wartości stałej $\pi$.
* Suma szeregu `S2` jest zbieżna do wartości stałej $e$.

---

## Zadanie 5: Liczby losowe
Proszę napisać funkcję, która oblicza wartość średnią liczb całkowitych generowanych w sposób losowy. 
Na początku funkcja powinna zapytać użytkownika o przedział wartości, z którego mają być losowane liczby całkowite oraz o ilość liczb, które mają być wygenerowane. Następnie funkcja powinna wypisywać na ekranie kolejne generowane liczby oraz zliczać ilość i sumę wygenerowanych liczb dodatnich oraz ilość i sumę wygenerowanych liczb ujemnych. Po zakończeniu generowania funkcja powinna wypisać podsumowane w którym będzie wypisane ile było liczb dodatnich i ile wynosiła ich wartość średnia oraz ile było liczb ujemnych i ile wynosiła wartość średnia wygenerowanych liczb ujemnych.

**Wskazówki:**
* W tej funkcji nie wolno używać tablicy do zapamiętywania wygenerowanych liczb.
* Do losowania liczb należy wykorzystać funkcję `rand()`, która zwraca wybraną losowo liczbę całkowitą dodatnią z przedziału od 0 do `RAND_MAX`.
* Jeśli trzeba wylosować liczbę całkowitą z zakresu `[min, max]` to można użyć następującą formułę: `losowa = min + rand() % (max - min + 1);`
* Przed rozpoczęciem losowania należy uruchomić generator liczb losowych przez wywołanie następującej instrukcji: `srand(time(NULL));`
