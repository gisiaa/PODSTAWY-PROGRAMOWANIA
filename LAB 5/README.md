# Laboratorium 4

## Wymagania ogólne
Proszę wykonać obowiązkowo zadanie 1a, 1b, 2, 3. Osoby ambitne mogą wykonać również zadanie 4.

* **Zadanie 1a oraz 1b** proszę zrobić jako oddzielne programy (każdy w innym pliku źródłowym).
* **Zadania 2, 3 oraz 4** (nieobowiązkowo) proszę zrobić jako jeden program, w którym każde zadanie jest oddzielną funkcją wywoływaną z prostego menu w funkcji `main()`.

**UWAGA:** Każdy program musi być w komentarzu podpisany! Po uruchomieniu każdy program powinien na początku wyświetlać na ekranie imię i nazwisko autora. Do oceny proszę wysłać tylko plik źródłowy tzn. plik z rozszerzeniem `*.cpp`.

### Program przykładowy nr 1
Proszę przeanalizować program przykładowy `row_kwa.cpp`, który ilustruje sposób podziału programu na kilka funkcji. Program oblicza pierwiastki równania kwadratowego.
* Funkcje `CzytajDane` oraz `WypiszPierwiastki` zapewniają komunikację z użytkownikiem programu. Sposób implementacji tych funkcji zależy od wykorzystywanej biblioteki wejścia-wyjścia (np. `<stdio.h>` oraz funkcje `printf` i `scanf`).
* Funkcje `Delta` oraz `ObliczPierwiastki` wykonują wszystkie obliczenia. Te funkcje nie wypisują żadnych komunikatów na ekranie, a więc są niezależne od wykorzystywanej biblioteki wejścia-wyjścia.

Proszę zwrócić szczególną uwagę na dobór sposobu przekazywania parametrów w poszczególnych funkcjach.

---

## Zadanie 1a: Układ równań liniowych (przez referencję)
Proszę napisać program, który rozwiązuje układ dwóch równań liniowych:

$$
 egin{cases}
a1*x + b1*y = c1 \
a2*x + b2*y = c2
\end{cases}
$$

Proszę zastosować metodę wyznaczników (Wzory Cramera):
$$W =  egin{vmatrix} a1 & b1 \ a2 & b2 \end{vmatrix} = a1*b2 - a2*b1$$
$$Wx =  egin{vmatrix} c1 & b1 \ c2 & b2 \end{vmatrix} = c1*b2 - c2*b1$$
$$Wy =  egin{vmatrix} a1 & c1 \ a2 & c2 \end{vmatrix} = a1*c2 - a2*c1$$

**Możliwe są trzy przypadki:**
1. Jeżeli $W 
eq 0$ to układ posiada dokładnie 1 jedno rozwiązanie: $x = rac{Wx}{W}$, $y = rac{Wy}{W}$
2. Jeżeli $W = 0$, $Wx = 0$, $Wy = 0$ to układ posiada nieskończenie wiele rozwiązań.
3. Jeżeli $W = 0$, $Wx 
eq 0$, $Wy 
eq 0$ to układ jest sprzeczny tzn. nie posiada żadnego rozwiązania.

Proszę podzielić program na funkcje realizujące komunikację z użytkownikiem oraz funkcje wykonujące obliczenia. Proponuję następujące funkcje:
* `void CzytajRownanie(float &a, float &b, float &c);` - funkcja wczytuje współczynniki jednego równania ($a*x + b*y = c$)
* `void WypiszRozwiązanie(int N, float x, float y);` - funkcja wypisuje rozwiązanie układu równań lub inny komunikat
* `float ObliczWyznacznik(float p1, float p2, float p3, float p4);` - funkcja oblicza wyznacznik $ egin{vmatrix} p1 & p2 \ p3 & p4 \end{vmatrix} = p1*p4 - p3*p2$
* `int ObliczRozwiązanie(float a1, float b1, float c1, float a2, float b2, float c2, float &x, float &y);` - funkcja oblicza rozwiązanie układu równań i zwraca:
  * `2` - nieskończenie wiele rozwiązań
  * `1` - jest jedno rozwiązanie
  * `0` - brak rozwiązań (układ sprzeczny)

**Funkcja main może mieć wówczas następującą postać:**
```cpp
int main(int argc, char* argv[]) {
    float A1, B1, C1; // pierwsze równanie,
    float A2, B2, C2; // drugie równanie,
    float X, Y;       // rozwiązanie,
    int N;            // liczba rozwiazan.
    
    CzytajRownanie(A1, B1, C1);
    CzytajRownanie(A2, B2, C2);
    
    N = ObliczRozwiązanie(A1, B1, C1, A2, B2, C2, X, Y);
    WypiszRozwiązanie(N, X, Y);
    
    getch();
    return 0;
}
```

---

## Zadanie 1b: Układ równań liniowych (przez wskaźnik)
Proszę zmodyfikować program z poprzedniego zadania tak, by parametry przekazywane do funkcji przez referencję zastąpić parametrami przekazywanymi przez wskaźnik.
*Uwaga: Zmodyfikowany program proszę umieścić w nowym pliku źródłowym.*

---

## Zadanie 2: Usuwanie cyfr z łańcucha
Napisz funkcję, która z podanego w parametrze łańcucha znaków usuwa wszystkie cyfry (znaki od `'0'` do `'9'`). 
* Funkcja powinna zwracać jako wynik swojego działania liczbę znalezionych i usuniętych cyfr. 
* Zmodyfikowany łańcuch znaków powinien być zapamiętany pod tym samym adresem co łańcuch pierwotny.

---

## Zadanie 3: Usuwanie komentarzy (kontynuacja zadania 2)
Napisz funkcję, która z podanego w parametrze łańcucha znaków usunie komentarze.
* Jako komentarz należy traktować wszystkie znaki rozpoczynające się od sekwencji `/*` do sekwencji `*/` oraz wszystkie znaki począwszy od ciągu `//` do końca łańcucha.
* Zmodyfikowany łańcuch znaków powinien być zapamiętany pod tym samym adresem co łańcuch pierwotny. 
* Funkcja powinna zwracać adres początku łańcucha wynikowego.

---

## Zadanie 4: Wskaźniki i pamięć (nieobowiązkowe - dla ambitnych)
Proszę zadeklarować kilka zmiennych globalnych i lokalnych różnych typów (np. `char`, `int`, `long`, `float`, `double`) i przypisać im różne wartości początkowe. Następnie napisz instrukcje wykonujące następujące operacje:

1. Wypisz na ekranie adresy oraz wartości wszystkich zadeklarowanych zmiennych globalnych i lokalnych (porównaj czym różnią się adresy zmiennych globalnych i lokalnych).
2. Narysuj na kartce papieru "bajtową mapę pamięci", na której zaznacz adresy i obszary zajmowane przez poszczególne zmienne.
3. Napisz instrukcje, które wyświetlą w kodzie szesnastkowym (heksadecymalnie) zawartości poszczególnych bajtów kodujących poszczególne zmienne. 
   * *Uwaga:* Dla każdej zmiennej należy wypisać tyle bajtów ile ta zmienna zajmuje miejsca w pamięci np. dla zmiennej `A` typu `int` wydruk powinien wyglądać następująco:
   `Zmienna A: Adres: 0x45674523 Wartosc:10 Bajty: 0x00 0x00 0x00 0x0A`
4. Napisz instrukcje zapisu nowej wartości każdej zmiennej za pomocą adresu tej zmiennej (tzn. dla każdej zmiennej utwórz wskaźnik, który ma przypisany adres tej zmiennej i wskaż miejsce zapisu do pamięci za pomocą tego wskaźnika - wykorzystaj operator wyłuskania), a następnie wydrukuj ponownie wartości wszystkich zadeklarowanych zmiennych oraz ich reprezentację w poszczególnych bajtach.
5. Napisz instrukcje zapisu wartości zmiennej za pomocą adresu innej zmiennej (wskaż miejsce zapisu za pomocą wskaźnika zawierającego adres innej zmiennej, do którego jest dodana odpowiednia liczba całkowita), a następnie wydrukuj ponownie wartości wszystkich zadeklarowanych zmiennych.

**Wskazówki do zadania 4:**
* **Zmienne globalne** to zmienne zadeklarowane poza ciałem jakiejkolwiek funkcji. Zwykle są deklarowane na początku programu. Zmiana wartości zmiennej globalnej w jednej funkcji będzie widoczna również w innej funkcji.
* **Zmienne lokalne** to zmienne zadeklarowane wewnątrz funkcji (lub bloku np. `for`, ograniczonego klamrami `{}`). Zasięg zmiennych lokalnych jest ograniczony wyłącznie do bloku instrukcji, w którym są zadeklarowane.
* Jeżeli w funkcji jest zadeklarowana zmienna lokalna o nazwie pokrywającej się z nazwą zmiennej globalnej, to zmienna lokalna „przesłania” zmienną globalną.
* Ilość pamięci zajmowanej przez zmienną określonego typu można odczytać za pomocą instrukcji `sizeof(typ)`.
* Adres zmiennej (wartość wskaźnika) można wypisać za pomocą instrukcji `printf`, używając w łańcuchu formatującym symbolu `%p` (zapis hexadecymalny) lub `%u` (zapis dziesiętny). Np.:
  ```cpp
  int x;
  int *wsk;
  wsk = &x;
  printf("Adres zmiennej x = %p", wsk);
  printf("Wartość zmiennej x = %d", *wsk);
