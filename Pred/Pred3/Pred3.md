## Queue
- fifo
- push(x)
- pop()
- peek()
- size()

Najlazje vzet linked list
pop: O(1)
push: O(n) oz O(1), ce imamo pointer na tail

Lahko se ga realizira z stackopm pa dynamic field-om

## Priority queue

- insert/ push (x,p)
- pull / pop()
- size()
- peek()
- . . .

Imamo list:
- (A,7) (B,2) (E,4)
- insert: o(1)
- pull: o(n)

Lahko realiziramo z urejenim seznamom
- (B,2)(E,4)(A,7)...
- insert O(n)
- pull O(1)

Kaj pa ce imamo urejeno polje?
Insert: o(log n + n) = o(n)
Pull: o(1+n) = o(n)

## heap
Struct: poravnan binary tree
vsebina: vozlišče otrok
min je v korenu
višina = o(log n)

Lahko hranim v seznamu:
- vozlisce x z indexom x:
- levi otrok: 2x
- desni otrok : 2x+1
- parent: floor(x/2)

Insert (a)
- dvigovanje po drevesu
- worst case -> dvignem do korena
- O(log(n))

Peek()
- o(1)

Pull() oz pop()
- tazadnjega v heapu prepises namesto taprvega
- nato popravljas strukturo

Izgradnja heapa:
$$
\sum_{x=0}^k x \cdot 2^{k-x} = O(n)
$$