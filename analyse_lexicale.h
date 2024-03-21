/* ------------------------------------------------------------------------
-- paquetage machine_lexemes
--
-- analyse lexicale d'une expression arithmetique
--
-- P.Habraken - 18/01/2010
--
-- 2 aout 2006 - PH :
-- remplacement record a champs variants par record "plat"
------------------------------------------------------------------------ */

typedef enum
{
   CAR_INCONNU,    // autre caractere
   CHIFFRE,       // chiffre
   LETTRE,        // lettre
   SYMBOLE,       // symbole,
   C_FIN_SEQUENCE // caractere de fin de sequence
} Nature_Caractere;

typedef enum
{
   DEBUT,                // yo_wassup, debut du programme
   FIN,                  // bye_bye, fin du programme
   DEF,                  // bussin, définition de variable
   INPUT,                // lit, lecture d'une variable
   OUTPUT,               // chill, ecriture d'une variable
   FIN_SEQUENCE,         // fin de la sequence de lexemes
   ENTIER,               // entier
   FLECHE,               // fleche
   INSTRUCTION_INCONNUE, // instruction pas encore reconnue
   CHAINE
} Nature_Lexeme;

typedef struct
{
   Nature_Lexeme nature; // nature du lexeme
   unsigned int ligne;   // numero de ligne
   unsigned int colonne; // numero de colonne
   char chaine[256];     // chaine de caracteres
   int val;              // valeur d'un entier
} Lexeme;

void afficher_lex(Lexeme l);

void demarrer(char *nom_fichier);
// e.i. : indifferent
// e.f. : la sequence de lexemes est lue dans le fichier designe par
//        nom_fichier
//        fin_de_sequence <=> lexeme_courant.nature = FIN_SEQUENCE
//        (non fin_de_sequence) => lexeme courant est le premier
//        lexeme de la sequence
//        l'exception Erreur lexicale est levee en cas d'erreur

void avancer();
// pre-condition : la machine sequentielle est demarree
// e.i. : on pose i = rang du lexeme_courant :
//        (non fin_de_sequence)
//        et (non lexeme_courant.nature = FIN_SEQUENCE)
// e.f. : fin_de_sequence <=> lexeme_courant.nature = FIN_SEQUENCE
//        (non fin_de_sequence) => lexeme_courant est le lexeme i+1
//        l'exception Erreur lexicale est levee en cas d'erreur

Lexeme lexeme_courant();
// pre-condition : la machine sequentielle est demarree
// lexeme_courant est :
// . le pseudo lexeme FIN_SEQUENCE si fin_de_sequence
// . le pseudo lexeme ERREUR si une erreur a ete detectee
// . le lexeme de rang i sinon

int fin_de_sequence();
// pre-condition : la machine sequentielle est demarree
// fin_de_sequence vaut :
// . vrai si tous les lexemes de la sequence ont ete reconnus
// . faux sinon

void arreter();
// e.i. : la machine sequentielle est demarree
// e.f. : la machine sequentielle est arretee

int est_separateur(char c);
