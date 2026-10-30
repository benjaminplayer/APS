## Obhod
- premi (Pre-order)
- obratni (Post order)
  - najprej levo pod drevo, pole desno, pole root
  - racun rezultatov is sub trees
- in order
  - Po vrstnem redu 
  - Dobro pri search trees
- Nivojski oz level order
  - Gremo po nivojih
  - Implementacija:
    - Naredis todo queue, kamor dajas vozlisca naslednjih nivojev

## Predstavitev dreves
- Hranimo sezname otrok
  - Za vsako vozlice imamo list otrok
  - Space complexity: $O(n)$

- Hranim za vsak node samo njegovega starsa
  - Ce se premikam po drevesu navzgor
  - Space complexity: $O(n)$

- Seznam povezav
  - Ce rabim samo it skozi vse povezave in jih obdelat

- Implicitna
  - Z array-i

## Binary Search trees
Imam vozlisce x, na levi strani so elementi manjsi od x,
na desni pa tisti, ki so vecji od x

- Iskanje
  - obhod $O(n)$
  - Sekanje drevesa na pol
    - $O(h), \text{kjer je } h \text{ visina drevesa}$
- Vstavljanje
  - isakanje, kjer se ustavi, tja vstavis element $O(h)$
- Brisanje
  - najprej dobis element
    - 0 otrok -> zbrises
    - 1 otrok -> samo replaceas z tem k brises
    - 2 otroka
      - isces najmanjsega, ki je vecji od trenutnega node.
      - pole ju swapas
      - $O(h)$


- Kako ugotovis ali je tree binary search tree
  - Post order traversal , pogledas min in max vseh subtrees -> $O(n)$

# Raba dreves
- Staticna drevesa -> drevesa, katerim se struktura ne spreminja

## Poizvedbe na obmocjih

```txt
A | a_1 | a_2 | a_3 | | | | | a_n |
```
$q(l,r) = f(a_l2, a_{l+1}, \dots, a_{r-1})$

Gledamo 2 stvari: cas in prostor za pred-obdelavo (pre processing), ter cas za poizvedbo

### Vsota
$$
c_i = \sum\limits_{j=1}^{i-1}a_j \newline
q(l,n) = c_r - c_l
$$

primerjava:

<table>
<tr>
<td></td>
<td>Cas</td>
<td>Prostor</td>
</tr>
<tr>
    <td>Pred-obdelava</td>
    <td>O(n)</td>
    <td>O(n)</td>
</tr>
<tr>
    <td>Poizvedba</td>
    <td>O(n)</td>
    <td>O(n)</td>
</tr>
</table>

### Minimum

<table>
<tr>
<td></td>
<td>Cas</td>
<td>Prostor</td>
</tr>
<tr>
    <td>Pred-obdelava</td>
    <td>O(1)</td>
    <td>O(1)</td>
</tr>
<tr>
    <td>Poizvedba</td>
    <td>O(n)</td>
    <td>O(1)</td>
</tr>
</table>

Ali


<table>
<tr>
<td></td>
<td>Cas</td>
<td>Prostor</td>
</tr>
<tr>
    <td>Pred-obdelava</td>
    <td>O(n^3) -> O(n^2)</td>
    <td>O(n^2)</td>
</tr>
<tr>
    <td>Poizvedba</td>
    <td>O(1)</td>
    <td>O(1)</td>
</tr>
</table>

#### Bloki
```txt
 6 8 4  5 2 6  3 7 1 2 9 
| - - - | B = 3
min:
  6 8 4   5 2 6   3 7 1   2 9 
| - - - | - - - | - - - | - - |
    4       2       1      2
```
st blokov: $\frac{n}{\text{B}}$

Za B izberem: $B = \sqrt{n}$

<table>
<tr>
<td></td>
<td>Cas</td>
<td>Prostor</td>
</tr>
<tr>
    <td>Pred-obdelava</td>
    <td>O(n)</td>
    <td>O(n/B) = O(sqrt(n))</td>
</tr>
<tr>
    <td>Poizvedba</td>
    <td>O(n/B + B) = O( sqrt(n) )</td>
    <td>O(1)</td>
</tr>
</table>

#### Bloki blokov -> Statično drevo
```txt
6 8 4 5 2 6 3 7 1 2 9 2 7 8 4 2
min:
  6 8   4 5   2 6   3 7   1 2   9 2   7 8   4 2 
| - - | - - | - - | - - | - - | - - | - - | - - |
   6     4     2     3     1     2     7     2
|-----------|-----------|-----------|-----------|
       4          2           1           2
|-----------------------|-----------------------|
            2                       1
|-----------------------------------------------|
                        1
```

<table>
<tr>
<td></td>
<td>Cas</td>
<td>Prostor</td>
</tr>
<tr>
    <td>Pred-obdelava</td>
    <td>O(n)</td>
    <td>O(n)</td>
</tr>
<tr>
    <td>Poizvedba</td>
    <td>O(log(n))</td>
    <td>O(1)</td>
</tr>
</table>
