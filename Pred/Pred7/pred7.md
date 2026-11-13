# Izbira aktivnosti

n aktivnosti $(s_i,e_i)$

kako lahko obiscemo cim vec predavanj, brez da se ta sekajo?

```txt
   |---------------|
|-------|  |----|  
  |--| |-----|    |----|
```
Ideje:
- Najzgodnejsi na zacetek
  - Problem: ce je eden, ki je dalsji od vseh
- Najkrajsi na zacetek
  - problem: ce sta 2 dalja, katere se prekiva min:
  - ``` txt
               1
            |-----|
    |---------| |--------|
         0          0
    ```
- Najmanj konflikten
  - problem: ce so stacked ena na drugi:
  - ```txt
      |----|            |----|
      |----|            |----|
      |----|            |----|
      |----|     |----| |----|
    |--------||----||----||-----|
    ```
- Najzgodejsi konec
  - time complexity: $O(n \cdot n^2) = O(n^3)$
  - Lahko najprej sortiramo po koncih, nato gremo cez, si zapovnimo konec prvega elementa,
  nato isecmo taprvega sprejemljivega, ter ga dodamo not v resitev.
    - Time complexity: $O(n \cdot \log{n} + n) = O(n\log{n})$


# Rezervacija ucilnic
Ang: interval scheduling

```txt
P1        |--------|    |----|
P2 |----| |----| |----|
P3 |-----------|   |---------|
P4 |----|        |----| |----|
```

min stevilo predavalnic, ki jih rabim?

time complexity: $O(n\cdot \log n + n \cdot D) = O(n \log n^2) = O(n^2)$

$D = O(n)$

Ce pustim zapisano samo $O(n\cdot \log n + n \cdot D)$ se temu rece
parametrizirana casovna zahtevnost

Uredimo use predavalnice po koncih Predavanj

Pq: P3,P1,P2

Mamo priority queue, kjer so na zacetku tisti, ki imajo prejsnji konec

Vedno izberem tisto, ki se najbolj zgodi konca, ce je uredu dodam nov interval, nato dodam nov konec.

Ce prva ni uredu, tudi ostale niso

Time complexity : $O(n\cdot \log n + n \cdot [1+\log n + \log n]) = O(n \cdot \log n)$

# Razvrscanje podatkov na trakovih

```txt
          x_i
|-------------------|
|   |      |    |   |
|-------------------|
           | l_i|
```

Datoteka $d_i$ z dostopi: $d_i = (s_i, l_i)$
- a) Kaj ce so usi enako veliki?
  - $s_i = 1$
  - max $l_i$ damo na zacetek
  - $x \cdot f_i + (x+1) \cdot f_j \rightarrow^{\text{menjava}} x \cdot f_j + (x+1) \cdot f_i$
  - sepravi ce so vsi enako dolgi, jih lahko posortiram po frekvenci
- b) Vse ferkvence so enake 1
  - $f_i = 1$
  - sortiras po velikosti $\rightarrow$ kratke na zacetek $\rightarrow$ min $s_i$ na zacetek
  - ```txt
    |-----------------|
    |      |i|j|      |
    |-----------------|
    ```
  - $x \cdot f_i + (x \cdot s_i) \cdot f_j \le x \cdot f_j + (x + s_j) \cdot f_i$
  - $s_i \cdot f_j \le s_j \cdot f_i$
  - $\frac{s_i}{f_i} \le \frac{s_j}{f_j}$
  - ce najdem 2 ki nista prou urejena, ju menjam
  - v optimalni resitvi morajo biti urejeni po razmerjih med velikostjo ter frekvenco

# TLDR
dokazovanje pravilnosti pozresnih strategij
varijante:
- Prednost
  - Resitev je pozresna strategija ki je vedno 1 stanje pred optimalno
  - arg z protislovjem
- Zamenjava
  - Predpostavimo da je pozresna resitev je optimalna. Ce to ni res bi obstajala neka druga, ki je bolj efficient.
  - Ce bi ta obstajala, lahko zamenjam z del z tistim iz pozresni. Na koncu bi amenjali vse z pozresno
- Strukturne
  - Da obstaja neka spodnja meja, ki jo mora nujno resitev dosezti. Nato smo si zmisnli neko pozresno resitev
  ki jo doseze.
