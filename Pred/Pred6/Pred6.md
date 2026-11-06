## st najm vrednosti
- tabela 0/1; k-ta nicla

skip list z niclami
```txt
5 2 2 4 5 2 3 1 7

0 1 0 0 1 0 0 1 0
```


najmanjsi element, ki je >= x

```txt
3 7 5 2 1 4 8 9 3 5
  |------------|
  l     >=3    r
```

ce hocemo iskati vecje ali je enako, je lepo imeti urejen set

```txt
1 2 3 3 5 5 7 8 9
```

> [!TIP]
> PRIMER ZA IZPIT (1. NAL) CE ISCES, UREDI PODATKE

```txt
|3| |7| ||...
 3 7  2 5
|---||---|
  2 3 5 7    1 4 8 9
|--------| |---------|
     1 2 3 4 7 8 9
|--------------------|
``` 

(Basically merge sort)

Velikost seznamov je$O(n \log n)$

casovna zahtevnost za iskanje: $O(\log^2 n)$

$\log^2$ ker moras za vsek layer narest bisekcijo, worst case
moras skozi vse, katerih je $\log n$

# Uravnotezena drevesa
## AVL drevo
drevo je uravnotezeno takrat, ko je visina logaritmska

AVL definira, da je drevo uravnotezeno, kadar se visine levega ter desnega
pod drevesa razlikujeta k vecjemu za 1
$|k_2 - k_1| \le 1$

$h = O(\log n)$

$A(h) ... min st vozlisc za AVL drevo visine h$
$A(h) = 1 + A(h-1) + A(h-2)$