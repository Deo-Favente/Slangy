### Slangy

Slangy est un langage de programmation de haut niveau de notre création.
Son nom tiens sa référence au mot "Slang" (Argot en anglais). Ses différents mots clés sont inspirés de l'argot populaire américain
et de diverses références humoristiques anglaises, notamment au langage SMS anglophone et à la culture hip-hop.
Il contient des fonctionnalités de base de tout langage de programmation facilement interprétables, telles que les variables, les boucles, les conditions, entrées/sorties, etc.
Sa syntaxe est simple et semblable à celle de Python, mais avec des mots clés qu'on a choisi parce qu'ils nous plaisent.

L'idée de base viens de ce meme :
https://media.discordapp.net/attachments/1154716905618276352/1209949468456132618/IMG_9353.png?ex=65fb3d41&is=65e8c841&hm=8f3fd0b87b6c6358f3d126c3042f367386179861153734e32784186d14a81f4d&=&format=webp&quality=lossless&width=523&height=509

### Mots clés
- "yo_wassup" = DEBUT (début de programme)
- "bye_bye" = FIN (fin de programme)
- "fr" = TRUE
- "cap" = FALSE
- "bussin" = DEF (définition de variable)
- "sus" = ! (négation)
- "u_sure" = IF
- "nah" = ELSE
- "wait_a_sec" = WHILE
- "skrrt" = FOR
- "aight" = END (fin de boucle)
- "ayo" = OR
- "deadass" = AND
- "lit" = PRINT
- "chill" = INPUT
- "slay" = - (soustraction)
- "bet" = + (addition)
- "brokie" = < (inférieur)
- "u mad" = > (supérieur)
- "same" = == (égal)
- "mewing" = commentaire

### Exemple de code
```
yo_wassup
lit "Hello, World!"
bye_bye
```
Explications : Ce programme affiche "Hello, World!" puis termine.
Traduction en grammaire : programme -> 'yo_wassup' instructions 'bye_bye'

```
yo_wassup
bussin x is 10
bussin y is 5
lit x
lit y
x slay 1
y bet 1
lit x
lit y
bussin z is x bet y
lit z
bye_bye
```
Explications : Ce programme déclare deux variables x et y, leur attribue respectivement les valeurs 10 et 5, puis les affiche. Ensuite, il incrémente x et décrémente y, puis affiche le résultat de ces opérations. Enfin, il déclare une variable z qui contient la somme de x et y, l'affiche puis termine le programme.

```
yo_wassup
lit "Entrez un nombre :"
chill x
lit "Entrez un autre nombre :"
chill y
u_sure x u mad y
    lit "x est plus grand que y"
nah
    lit "x est plus petit que y"
aight
bye_bye
```
Explications : Ce programme demande à l'utilisateur d'entrer deux nombres, puis affiche un message indiquant si le premier nombre est plus petit ou plus grand que le second. Il termine ensuite le programme.

```
yo_wassup
busin x is 0
wait_a_sec x brokie 10
    lit x
    x bet 1
aight

skrrt y = 0 y brokie 10 y bet 1
    lit y
aight

bye_bye
```
Explications : Ce programme déclare une variable x et l'incrémente de 1 à chaque itération de la boucle while, puis affiche sa valeur. Il déclare ensuite une variable y et l'incrémente de 1 à chaque itération de la boucle for, puis affiche sa valeur. Il termine ensuite le programme.

### Grammaire

**Structure générale**
programme -> 'yo_wassup' instructions 'bye_bye'

**Instructions**
instructions -> instrcution instructions
instructions -> instruction

**Entrées / Sorties / Commentaires**
instruction -> 'lit' expression
// instruction -> 'chill' variable
instruction -> 'mewing' expression

**Déclaration de variable**
instruction -> 'bussin' variable = expression
variable -> [a-zA-Z_]+

### Prochains ajouts grammaire

**Boucles**
instruction -> 'wait_a_sec' expression instructions 'aight' # while
instruction -> 'skrrt' variable = expression variable expression instructions instructions 'aight' # for

**Expressions booléennes**
expression -> expression operator expression # opérateur booléen
expression -> 'sus' expression # négation (booléen)
expression -> 'fr' # vrai
expression -> 'cap' # faux

**Opérateurs booléens**
operator -> 'ayo' # ou
operator -> 'deadass' # et
operator -> 'same' # égalité
operator -> 'brokie' # inférieur
operator -> 'u mad' # supérieur

**Expressions de chaînes de caractères**
string -> "[a-zA-Z0-9!@#$%^&*()_+]" # chaîne de caractères
expression -> string

**Expressions arithmétiques**
entier -> [0-9]+
expression -> entier bet entier # addition
expression -> entier slay entier # soustraction
expression -> entier

**Structures conditionnelles**
instruction -> u_sure expression instructions nah instructions aight # if
instruction -> u_sure expression instructions nah instructions aight nah instructions aight # if else
