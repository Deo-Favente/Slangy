#ifndef __LEC_CAR__
#define __LEC_CAR__

/* ------------------------------------------------------------------------
-- module lecture_caracteres
--
-- sequence de caracteres
--
-- J-P. Peyrin, G. Serasset (version initiale) : janvier 1999
-- P. Habraken : 12 novembre 2002
-- L. Mounier (version C) : aout 2016
------------------------------------------------------------------------ */

void demarrer_car(char *nom_fichier);
   // e.i. : indifferent
   // e.f. : la sequence de caracteres est accessible dans le fichier designe
   //        par nom_fichier
   //        fin_de_sequence vaut vrai ou alors caractere_courant est le
   //        premier caractere de la sequence

void avancer_car();
   // pre-condition : la sequence de caracteres est accessible
   // e.i. : fin_de_sequence = faux ;
   //        on pose i = rang du caractere courant
   // e.f. : fin_de_sequence vaut vrai ou alors caractere_courant est le
   //        caractere de rang i+1 dans la sequence

char caractere_courant(); 
   // pre-condition : la sequence de caracteres est accessible
   // caractere_courant est le caractere de rang i
   // pre-condition : la machine sequentielle est demarree et
   // fin_de_sequence = faux

int fin_de_sequence_car(); 
   // pre-condition : la sequence de caracteres est accessible
   // fin_de_sequence vaut vrai <=> tous les caracteres de la sequence
   // ont ete lus
   // pre-condition : la machine sequentielle est demarree

unsigned int numero_ligne(); 
   // pre-condition : la sequence de caracteres est accessible
   // numero de la ligne ou se trouve le caractere courant
   // pre-condition : la machine sequentielle est demarree et
   // fin_de_sequence = faux

unsigned int numero_colonne();
   // pre-condition : la sequence de caracteres est accessible
   // numero de la colonne ou se trouve le caractere courant
   // pre-condition : la machine sequentielle est demarree et
   // fin_de_sequence = faux

void arreter_car();
   // pre-condition : la sequence de caracteres est accessible
   // e.i. : indifferent
   // e.f. : la sequence de caracteres n'est plus accessible

#endif
