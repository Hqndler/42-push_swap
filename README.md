# push_swap [![ec█████'s 42 push_swap Score](https://badge42.vercel.app/api/v2/cld0a5i4x00160gmjxtqwizec/project/2910870)](https://github.com/JaeSeoKim/badge42)

## Le projet

Le projet consiste à trier une liste d'entier avec les instructions donnée dans l'énoncer. Le but est de trier la liste avec le moins d'instructions possible.
Voir le pdf pour plus d'information sur les instructions.

## Performance

| | Pour avoir 5/5 | Mon algo |
| ----------- | ---------- | -------------- |
| 5 nombres : | < 12 coups | 6-10 coups |
| 100 nombres : | < 700 coups | 468-695 coups |
| 500 nombres : | < 5500 coups | 3889-4634 coups |

Pour 100 nombres la moyenne est de 578 coups.<br>
Pour 500 nombres la moyenne est de 4244 coups.

## Comment ça fonctionne ?

L'algo en lui même est divisé en deux partie.<br>
- La première consiste à pré-trier les éléments de la pile A en les pushant dans B pour qu'il soit en partie trié dans l'ordre décroissant.<br>
Pour ce faire j'utilise la médianne et les quartils : si l'élément est compris entre la médianne et le premier quartil, il sera push dans B puis B sera rotate, s'il est compris entre la médianne et le dernier quartil, il sera simplement push dans B. Si l'élément est supérieur au dernier quartil ou inférieur au premier, on rotate A.<br>
On continue de push dans B avec l'idée d'avoir les éléments à peu près trier dans l'ordre décroissant jusqu'à ce qu'il ne reste 3 éléments dans A.

- La deuxième partie est la plus cruciale car c'est là que tout se joue : tout les éléments de B devront être push dans A mais de la manière la plus opti possible.<br>
Pour chaque élément de la pile B on calcule le coup d'instructions pour placer l'élément. On garde l'élément le moins couteux à placer dans A. L'élément sera placer de façon à ce que l'élément d'avant soit plus petit que lui et que le suivant soit le plus grand.<br>
Une fois qu'il n'y a plus rien dans B, A est trié mais pas forcément dans l'ordre qu'on peut : il lui manque des rotates.<br>
Une fois l'opération de rotate terminée la pile A est triée dans l'ordre croissant.

Et on oublie pas de tout free pour ne pas avoir de fuite de mémoire.

## Visualisation des instructions


https://user-images.githubusercontent.com/69089935/212922624-a9230c23-a3b2-4147-9ad8-fcfb054ae378.mp4



https://user-images.githubusercontent.com/69089935/212925804-d2990a2f-a4a7-4686-b0d8-429d2312ee92.mp4

## Pour les gens qui aiment python

J'ai fais l'algo en python aussi, il se peut qu'il soit plus compréhensible que le code en C éparpiller sur plusieurs fichiers.
