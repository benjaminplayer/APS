# Pred 4
- urejen seznam elementov
  - Linked list
  - Array
  - seznam skupin

## Seznam skupin

|2 4 8 9 20| -> |31 32 47 50 90| -> |91 100 105 200 203|

$n...$ stevilo elementov
$k...$ velikost skupine
$\frac{n}{k} ...$ stevilo vseh skupin

- iskanje: $O(\frac{n}{k} + k)$
    - ce v zadnjem seznamu uporabim bisekcijo: $O(\frac{n}{k} + \log{k})$

- vstavljanje:
    - $O(\frac{n}{k} + \log{k} + k) = O(\frac{n}{k} + k)$
    - k se na koncu pristeje, saj se morajo elementi shiftat
    - $\log k$ odpade, saj je $k$ vecji

Kaksen k naj izberem?
$$
        k = 1 \rightarrow O(\frac{n}{1} + 1) = O(n) \\
        k = n \rightarrow O(\frac{n}{n} + n) = O(n) \\
        k = \log n \rightarrow O(\frac{n}{\log{n}} + \log n) \\
$$

Če uporabim:
$$ 
\frac{n}{k} = k\\
$$

Dobimo:

$$ k = \sqrt{n} \rightarrow O(\frac{1}{\sqrt{n}} + \sqrt{n}) = O(\sqrt{n})$$

Čemur se reče **KORENSKA DEKOMPOZICIJA**

Na 100 operacij naredim nek rebuild, ki zahteva $O(n)$ operacij

## Skip list
linked list z dodatnimi povezavami, ki omogocajo hitrejse skoke:

| | -> | | -> | | -> | | -> | |

kjere povezave bi bilo fajn imet?
Recimo povezava iz prvega elementa na osrednji element, saj bi se lohko skoraj sli bisekcijo, ma ko ustavim element se use pordre...

Strategija: Imam elemente, na katerih zgradis nivoje med vsemi:

```
|| ->               ->        ||
|| ->    -> ||      ->        || n/4
|| -> || -> || -> || -> || -> || n/2
|| -> || -> || -> || -> || -> || n
```

Kako se odločam za te nivoje?
Randomly!
Imamo neko vrjetnost $p = \frac{1}{2}$
Vsak nov nivo dodamo z vrjetnostjo $p$, sepravi če je $h = visina$, vrjetnost, da dosežem takšno višino je $p^{h-1}$

visina $h = \log n$

Prostorska kompleksnost:
- Worst case (vsi zrastejo do te visine): $O(n \cdot \log n)$
- avg: $O(2n) = O(n)$

Brisanje:
- worst case: $O(n)$
- pricakovan: $O(2 \log n) = O (\log n)$

## Drevesa
Drevesa rastejo od zgoraj navzdol
Sestavljen je iz vozlisc, ter povezav
Najvisje vozlisce se imenuje **koren** oz **root**

Tazadnja vozlisca, ki nimajo pod dreves se imenujejo **Listi**

Povezave povezujejo starše z otrokom.

Sosedi = Otroci + starši

Sorojenci oz siblings = otroci istega starša

**Potomci** so vsi nodes, ki so dosegljivi iz izbranega vozlisca.

Vsa vozlisca na poti porti root-u so **predniki**

- **Stopnja** = st otrok
- **Velikost** = st vozlisc
- **Globina** = oddaljenost od root
- **Visina** = max depth vozlisca

Poznamo se:
- uravnotezena drevesa
  - visina drevesa je reda $\log n$
- izrojena drevesa
  - primer: linked list

### Vrste dreves
- Dvojiska, K-tiska
  - Vsako vozlisce ima najvec k - otrok
- Polna drevesa
  - Vsako vozlisce ima max st otrok, ki jih lahko ima
  - Ali 0 ali vse
- Poravnano drevo
  - npr Heap
  - Vsa vozlisca do tazadnjega nivoja so po vrsti urejena
- Popolno drevo
  - Polna drevesa, ki imajo vse liste na istem nivoju
- Urejena
- Neurejena
- Iskalna
- Črkovna/ Znakovna (Trie)