# Laboratorium 01

## Wymagania ogólne
Proszę uważnie przeanalizować program przykładowy o nazwie `Pierwszy Program.cpp`. Wzorując się na tym programie, proszę wykonać poniższe zadania.

* **Jeden plik źródłowy:** Wszystkie zadania należy zrobić w jednym pliku źródłowym (rozszerzenie `*.cpp`). Do oceny proszę wysłać tylko ten plik.
* **Komentarze:** Każdy program musi być w komentarzu podpisany!
* **Dane autora:** Po uruchomieniu, każdy program powinien na początku wyświetlać na ekranie imię i nazwisko autora.
* **Struktura kodu:** Do każdego zadania proszę napisać oddzielną funkcję. Ponadto proszę napisać funkcję `main`, w której zostaną wywołane funkcje będące rozwiązaniami poszczególnych zadań.

---

## Zadanie 1: Równanie kwadratowe
Proszę narysować schemat blokowy programu, który wczytuje trzy liczby rzeczywiste `a`, `b`, `c`, będące współczynnikami równania kwadratowego: 
$$a x^2 + b x + c = 0$$

Program powinien sprawdzać, czy jest to poprawne równanie kwadratowe (tzn. czy `a` jest różne od 0), obliczać wartość wyróżnika `delta` oraz – jeśli istnieją – obliczać i drukować pierwiastki `x1` i `x2`.

Napisz program, który realizuje powyższy schemat blokowy.

**Wskazówki:**
* Współczynniki `a`, `b`, `c` powinny być typu rzeczywistego.
* Jeśli `a = 0`, to brak równania kwadratowego – nie można liczyć pierwiastków.
* `delta = b^2 - 4*a*c`
* Jeśli `delta < 0`, to brak pierwiastków rzeczywistych.
* Jeśli `delta = 0`, to istnieje podwójny pierwiastek `x1 = x2 = -b / (2*a)`.
* Jeśli `delta > 0`, to:
  * `x1 = (-b - sqrt(delta)) / (2*a)`
  * `x2 = (-b + sqrt(delta)) / (2*a)`
* Pierwiastek z liczby `x` można obliczyć za pomocą funkcji `sqrt(x)`, która znajduje się w bibliotece `<math.h>` (lub `<cmath>`).

---

## Zadanie 2: Walidator daty
Proszę napisać funkcję, która wczytuje z klawiatury trzy liczby całkowite, które oznaczają dzień, miesiąc i rok. Następnie funkcja powinna wypisać na ekranie utworzoną z tych liczb datę oraz sprawdzić, czy to jest poprawna data. 

Przy sprawdzaniu poprawności proszę uwzględnić ilość dni w poszczególnych miesiącach (1...31 w styczniu, 1...28 w lutym w roku zwykłym, 1...29 w lutym w roku przestępnym, 1...31 w marcu, 1...30 w kwietniu itd.).

**Uwzględnić lata przestępne:**
Przyjąć, że rok **nie jest** przestępny (rok zwykły), jeśli:
* nie dzieli się przez 4
* lub dzieli się przez 100, ale nie dzieli się przez 400.

*(np. lata zwykłe: 1700, 1800, 2100; lata przestępne: 4, 1600, 1996, 2000, 2400).*
W szczególności data `29-02-1800 r.` nie jest datą poprawną.

---

## Zadanie 3: Właściwości trójkąta
Proszę napisać funkcję, która wczytuje trzy liczby dodatnie `a`, `b`, `c`, które będą oznaczać długości trzech odcinków.

1. Następnie proszę sprawdzić i wypisać informację, czy z odcinków o podanych długościach można utworzyć trójkąt.
2. Jeśli odpowiedź jest pozytywna, to proszę sprawdzić i wypisać na ekranie informację, czy będzie to trójkąt:
   * równoramienny, 
   * równoboczny, 
   * ostrokątny, 
   * prostokątny, 
   * rozwartokątny.

---

## Zadanie 4: Tabela obwodów i pól kół
Proszę napisać funkcję, która wczytuje minimalny i maksymalny promień koła oraz liczbę wierszy tabeli, w której będą wypisane promienie i odpowiadające im obwód oraz pole koła.

Tabela z ramkami oraz nagłówkiem powinna zawierać cztery kolumny: numer wiersza (`Lp`), promień koła (`promien`), obwód koła (`obwod kola`), pole koła (`pole kola`). 

**Wskazówka:**
* Do obliczeń obwodu i pola koła proszę wykorzystać dokładną wartość $\pi$, która jest zdefiniowana w stałej `M_PI` z biblioteki `<math.h>` (lub `<cmath>`).

**Przykładowy widok konsoli:**
```text
Podaj minimalny promien: 1
Podaj maksymalny promien: 2
Podaj liczbe wierszy: 5

=========================================================
| Lp | promien | obwod kola | pole kola |
=========================================================
|  1 |    1.00 |       6.28 |      3.14 |
|  2 |    1.25 |       7.85 |      4.91 |
|  3 |    1.50 |       9.42 |      7.07 |
|  4 |    1.75 |      11.00 |      9.62 |
|  5 |    2.00 |      12.57 |     12.57 |
=========================================================
Aby kontynuować, naciśnij dowolny klawisz . . .
