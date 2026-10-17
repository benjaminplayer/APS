# Pred 1
>WE ARE FUCKED

compilation:
```
g++ -std=c++23 main.cpp
```
Crash course cpp:
Pred1.cpp


# Sorting

List y n elementi, za sort
za primerjat usak z usakimi.

operacije
<table>
<tr>
    <td>Sistematično</td>
    <td>n!/2</td>
</tr><tr>
    <td>Naključno</td>
    <td>n!</td>
</tr>
</table>

TLDR: Oba sta useless

## Selection sort

Urejanje z izbiranjem

- Je in-place sorting algorithm
- Stabilnost -> ali bodo po sortu isti
elementi ostali v enakem orderju?
    - Ni stabilen
Poišče min, da na začetek

<table>
<tr>
    <td></td>
    <td></td>
    <td></td>
    <td>3</td>
    <td></td>
</tr>
</table>

<table>
<tr>
    <td>3</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
</tr>
</table>

$$ 
n+1
+n-1 +1
+n-2 +1
.
.
.
prb n^2 $$

Time complexity:
<table>
<tr>
    <td>Worst</td>
    <td>O(n^2)</td>
<tr>
    <td>Avg</td>
    <td>O(n^2)</td>
<tr>
    <td>Best</td>
    <td>O(n^2)</td>
</tr>
</table>

Space complexity: O(n)

## Insertion sort

Gradim vedno daljsi urejen seznam.
Ko dobim element, ki ni sorted, pogledam kam v sorted del ta pase.
Nato vstavim na mesto, ter shiftam ostale v stran.

<table>
<tr>
    <td>Worst (pri sorted obratni vrstni red)</td>
    <td>O(n^2)</td>
<tr>
    <td>Avg</td>
    <td>O(n^2)</td>
<tr>
    <td>Best (pri already sorted) </td>
    <td>O(n)</td>
</tr>
</table>

Space complexity: O(n)

## Bubble sort
"Dokler je kaj narobe, zamenjaj"
Bejzi cez array, menjuj sosednja elementa, dokler ne prides cez
ceu list

TLDR, se v vsakem iteration-u se tavecje stevilo spravi na konec seznama

<table>
<tr>
    <td>Worst</td>
    <td>O(n^2)</td>
<tr>
    <td>Avg</td>
    <td>O(n^2)</td>
<tr>
    <td>Best (when all already sorted)</td>
    <td>O(n)</td>
</tr>
</table>

Space complexity: O(n)