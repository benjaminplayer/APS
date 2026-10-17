# Pred 2
## Računska zahtevnost
Količina dela, ki jo potrebujemo za opraviti delo neke velikosti
n je velikost -> pove koliko dela rabimo za izvedbo

Pogovarjamo se po **prostorski** ter **časovni** zahtevnosti

Glede na scenarij, ki ga gledamo, se deli na 
- Najboljša
- Povprečna
- Najslabša

Asim rač zah $\rightarrow$ kaj se dogaja, ko gre $n \rightarrow \infty$

Zgornja meja $\rightarrow$ (big O)

$f(n)$ ima kompleksnost reda $g(n)$:
$f(n) = O(g(n)) \space ... \space O(n^2)$
to pomeni:
$\exist k > O \space \exist n_0 \forall n > n_0 : f(n) \le kg(n)$

$ \lim_{n \rightarrow \infty} \frac{f(n)}{g(n)} < \infty$

Zogrnja meja asim rač zah v naslednem primeru:

$f(n) = \frac{1}{2}(n-1)(n+2) \log n + \sqrt{n} = O(n^2 \log n)$
$= \frac{1}{2}n^2 \log n + \frac{1}{2}n\log n - \log n + \sqrt{n}$

vsi členi iz $+ \frac{1}{2}n\log n$ in $\sqrt{n}$ so manjši kot $n^2 \log n$, zato jih lohko zamenjam:
$n^2 \log n+ n^2 \log n - \log n + n^2 \log n < 3n^2 \log{n}$

v praksi:
- vsota: najhitrejše rastoči člen
- produkt: lahko "vržemo stran" (zanemarimo) konstante

Common zahtevnosti:
- O(1) ... konstanta
- O(n) ... linearna
- O(log n) ... logaritemska
- O($\sqrt{n}$) ... korenska
- O(n log n) ... loglinearna
- O($n \log^c n$) ... kvazilinearna
- O($n^2$) ... kvadratna
- O($n^3$) ... kubična
- o($n^c$) ... polinomska
- O($2^n$), O($c^n$) ... eksponentna
- O(n!), O($n^n$)

$100 + 2n^2 + 3n^3 = O(n^3)$
$3n \cos{2\pi n} + \frac{n}{\log n} + 2n = O(n)$,
ker cos je med 0 in 1, zato vzamemo 1, zato je najvecji clen n
$1 + n \log n + n^{1.5} = O(n^{1.5}) = O(n\sqrt{n})$
$f(n) = \sum_{k=1}^{n} \frac{n}{k} = n \sum_{k=1}^n = O(n^2 \log n)$

$f(n) = n + f(\frac{n}{2})$
$f(n \le 1) = 1$
$f(n) = n + f(\frac{n}{2}) = n + \frac{n}{2} + \frac{n}{4} + ... < 2n = O(n)$

$f(n,m) = an^2 + n\sqrt{m} + b \log{am} = O(n^2 + n \sqrt{m})$

### primer z programom:

```
for (x = 1 x <= n x*=2)
{
    for (i = 0 i < x i++)
    {
        for (j = 0 j < n j+=2)
        {
            konstantno st op
        }
        for (j = 1; j < n; j*=2)
        {
            konstantno st op
        }
    }
}
```
Prva zanka se izvede: $\log n$- krat. (Kolkrat mozis n da prides do 2).
Ni vazno kaksen je log, lahko je karkoli, saj je pretvorba logaritma samo mnozenje / deljenje z konstanto.

Drugi loop je n
Tretji $frac{n}{2}$
cetrti pa spet $\log n$

kar nam da: $O(\log n \cdot n(n + \log n)) = O(n^2 \log n)$

## Napredno urejanje
Radi bi prisli iz $O(n^2)$ na neki kar ima $O(n \log n)$

- Merge sort
- Quick sort
- Heap sort


### Merge sort
```txt
| 2 | 3 | 9 | 10 | 17 | -> n el
| 4 | 5 | 11 | 13 | 20 | -> m el
```
zlepljen seznmam
```txt
| 2 | 3 | 4 | 5 | 9 | 10 | 11 | 13 | 17 | | 20 |
```

Zahtevnost je $O(n+m)$

```
| 10 | 3 | 7 | 1 | 5 | 8 | 4 | 2 | 3 | 1 | 9 | 8 |
```
Združuješ par po par -> majhni kosi dolžine 1 in pole večaš korake. Recimo zliješ 10 in 3 v neki urejenga pole 7 pa 1 itd. nato taprve 4 elemente...

Lahko pa tudi razdelimo seznam na 2 polovici, ju uredimo, in nato zlijemo skupi.

Ta pristop ima complexity $O(n + (\frac{n}{2})^2 + (\frac{n}{2})^2 + n) = O(n^2)$

Lahko pa dobljene sezname se dodatno razbviam na manjse in manjse kose levih in desnih polovic. Nato vsako prelijem nazaj v urejen seznam.

2 koraka: **split** pa **merge**:
<table>
<tr>
    <td>Split</td>
    <td>Merge</td>
</tr>
<tr>
    <td>n</td>
    <td>n</td>
</tr>
<tr>
    <td>n</td>
    <td>n</td>
</tr>
</table>

<table>
<tr>
    <td>Split</td>
    <td>Merge</td>
</tr>
<tr>
    <td colspan="2">2n</td>
    
</tr>
<tr>
    <td colspan="2">2n</td>
</tr>
<tr>
    <td colspan="2">4* 2n * n/4 = 2n</td>
</tr>
</table>

Ker je st ukazov za vsak nivo 2n, za celoten postopek dobimo časovno kompleksnost: $\log n \cdot 2n = O(n\log n)$

**Prostorska zahtevnost?**

$O(n \log n)$

Na vsakem nivoju bo n elementov, razbitih vsakic po pol. Za vsak seznam bo zato potrebno alocirati n prostora $\log n$ - krat


Kako bi izboljsal prostorsko zahtevnost?

Namesto alociranja lahko podajam samo index-e elementov z katerim elemenotm seznama se ukvarjam.

- Težava?
Rabim pomožno tabelo za zlivanje, katero nato prepisem v orignalno tabelo. To izboljša kompleksnost na $O(n)$

- Ali se lahko vse to naredi in place?
Da, vendar je precej bol kompleksen algoritem.

### Quick sort

Podobna strategija kot merge sort
Tle razdelimo stvari na majhne pa velike:

Seznam razbijemo na 2 dela:
- L $\rightarrow$ Majhni el
- R $\rightarrow$ Veliki el

Oba dela nato za isto logiko posrotiram

Kako pa se odločim, kaj je veliko in kaj je majhno?

Določimo **PIVOT**.

Razdelimo seznam na 3 kose:
- $<$ pivot
- $=$ pivot
- $>$ pivot

- Kako dobim pivot?
  - aritmetična seredina
  - random

Z tistimi ki so enaki se ne ukvarajm,
za ostale izberem nov pivot in ponovim

- Time complexity
  - worst: $O(n^2)$
  - avg: $O(n \log n)$
  - best: $O(n \log n)$

- Spacce complexity:
  - $O(n \log n)$
  - Z optimizacijami se da narediti in place algoritem ($O(n) + O(1)$)


## Counting sort
n poštnih števil
1000, 2000, ...
naredim seznam ferkvenc:

| postna st | ferq |

time complexity: $O(n + M + n) = O(n+M)$
M = max vrednost, ki sem jo do sedaj videl

Space complexity: $O(M)$

## Bucket sort
Naredim kose:
- majhni
- srednji
- veliki
- ogromni

Te kose nato razbivam kot pri quick sortu
Lahko tudi uporabljam isto logiko na teh kosih

### Radix sort (Korensko urejanje)

Imamo kup stringov:
ABA, AC, ADDA, BAA, BC, BAD, A

Lexikografsko:
A[ABA,AB,ADDA,A]
B[BAA,BA,BAD]

Nato razbijem ponovno:

A[ABA,AB,ADDA,A]:
A[A]
B[ABA]
C[AC]
D[ADDA]

itd.

Na vsakem nivoju je n nizov razbitih na različno nizov.
Na vsakem nivju: n el, globino drevesa pa predstavlja dolžina najdalšega stringa.

## Zakaj urejamo podatke?
Lažje iskanje podatkov $\rightarrow$ **BINARY SEARCH**

### Binary search
Poiscemo sredino,
ce je iskano st sredina -> OK :)
ce je manjse ponovi na prvi polovici
ce je vecje ponovi na drugi polovici.

Time complexity: $O(\log n)$

Kako bi vstavili x med nek urejen seznam?

Najdem mejo med tistimi, ki so pre majhni, in tistimi ki so pre veliki.

Init 2 pointerja, tamanjsi ter tavecji, ter delam binary search. Kadar je razlika 1, vem da sem dobil, kam ustaviti tisti element