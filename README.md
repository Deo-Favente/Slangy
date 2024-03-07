### Slangy

Slangy est un langage de programmation de haut niveau de notre création.
Son nom tiens sa référence au mot "Slang" (Argot en anglais). Ses différents mots clés sont inspirés de l'argot populaire américain
et de diverses références humoristiques anglaises.
Il contient des fonctionnalités de base de tout langage de programmation facilement interprétables, telles que les variables, les boucles, les conditions, entrées/sorties, etc.

L'idée de base viens de ce meme :
https://media.discordapp.net/attachments/1154716905618276352/1209949468456132618/IMG_9353.png?ex=65fb3d41&is=65e8c841&hm=8f3fd0b87b6c6358f3d126c3042f367386179861153734e32784186d14a81f4d&=&format=webp&quality=lossless&width=523&height=509

### Idées de mot clé

- "yo wassup" = DEBUT (début de programme)
- "bye bye" = FIN (fin de programme)
- "fr" = TRUE
- "cap" = FALSE
- "bussin" = DEF (définition de variable)
- "sus" = ! (négation)
- "u sure" = IF
- "nah" = ELSE
- "wait a sec" = WHILE
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
yo wassup
lit "Hello, World!"
bye bye
```
Explications : Ce programme affiche "Hello, World!" puis termine.
Traduction en grammaire : programme -> 'yo wassup' instructions 'bye bye'

```
yo wassup
bussin x = 10
bussin y = 5
lit x
lit y
x slay 1
y bet 1
lit x
lit y
bussin z = x bet y
lit z
bye bye
```
Explications : Ce programme déclare deux variables x et y, leur attribue respectivement les valeurs 10 et 5, puis les affiche. Ensuite, il incrémente x et décrémente y, puis affiche le résultat de ces opérations. Enfin, il déclare une variable z qui contient la somme de x et y, l'affiche puis termine le programme.

```
yo wassup
lit "Entrez un nombre :"
chill x
lit "Entrez un autre nombre :"
chill y
u sure x u mad y
    lit "x est plus grand que y"
nah
    lit "x est plus petit que y"
aight
bye bye
```
Explications : Ce programme demande à l'utilisateur d'entrer deux nombres, puis affiche un message indiquant si le premier nombre est plus petit ou plus grand que le second. Il termine ensuite le programme.

```
yo wassup
busin x = 0
wait a sec x brokie 10
    lit x
    x bet 1
aight

skrrt y = 0 y brokie 10 y bet 1
    lit y
aight

bye bye
```
Explications : Ce programme déclare une variable x et l'incrémente de 1 à chaque itération de la boucle while, puis affiche sa valeur. Il déclare ensuite une variable y et l'incrémente de 1 à chaque itération de la boucle for, puis affiche sa valeur. Il termine ensuite le programme.

### Grammaire

# Structure générale
programme -> 'yo wassup' instructions 'bye bye'

# Instructions
instructions -> instrcution instructions
instructions -> instruction

# Entrées / Sorties
instruction -> 'lit' expression
instruction -> 'chill' variable

# Déclaration de variable
instruction -> 'bussin' variable = expression
variable -> [a-zA-Z_]+

# Commentaire
instruction -> 'mewing' expression

# Boucles
instruction -> 'wait a sec' expression instructions 'aight' # while
instruction -> 'skrrt' variable = expression variable expression instructions instructions 'aight' # for

# Expressions booléennes
expression -> expression operator expression # opérateur booléen
expression -> 'sus' expression # négation (booléen)
expression -> 'fr' # vrai
expression -> 'cap' # faux

# Opérateurs booléens
operator -> 'versus' # ou
operator -> 'deadass' # et
operator -> 'same' # égalité
operator -> 'brokie' # inférieur
operator -> 'u mad' # supérieur

# Expressions textuelles
string -> "[a-zA-Z0-9!@#$%^&*()_+]" # chaîne de caractères
expression -> string

# Expressions arithmétiques
entier -> [0-9]+
expression -> entier bet entier # addition
expression -> entier slay entier # soustraction
expression -> entier

# Conditions
instruction -> u sure expression instructions nah instructions aight # if
instruction -> u sure expression instructions nah instructions aight nah instructions aight # if else
