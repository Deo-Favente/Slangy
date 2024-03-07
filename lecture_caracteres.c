
/* ------------------------------------------------------------------------
-- module letcure_caracteres
--
-- sequence de caracteres
--
-- P. Habraken : 12 novembre 2002
-- L. Mounier : Aout 2016 (version en C)
 ------------------------------------------------------------------------ */


#include <stdio.h>
#include <string.h>

#include "lecture_caracteres.h"

   /* --------------------------------------------------------------------- */

   // Les variables locales au module 

    int CarCour;  	// caractere courant
    unsigned int LigneCour, ColonneCour;  // numeros de ligne et colonne
    FILE *File;		// le fichier d'entree

   /* --------------------------------------------------------------------- */

   void demarrer_car(char *nom_fichier) { 
      if (strlen(nom_fichier) == 0) {
         File = stdin ;
      } else {
	 File = fopen(nom_fichier, "r") ;
      } ;
      LigneCour = 1 ; ColonneCour = 0 ;
      avancer_car () ;
   } 

   /* --------------------------------------------------------------------- */

   void avancer_car() {
      if (!feof(File)) { 
	CarCour = fgetc(File) ;
	if (CarCour != '\n') {  
		ColonneCour = ColonneCour + 1 ;
	} else { 
		ColonneCour = 1 ;
		LigneCour = LigneCour + 1 ;
	} ;
      } else { 
	CarCour = EOF ;
      } ;
   }

   /* --------------------------------------------------------------------- */

   char caractere_courant() {
      return CarCour;
   }

   /* --------------------------------------------------------------------- */

   int fin_de_sequence_car()  {
      return CarCour == EOF ;
   } 

   /* --------------------------------------------------------------------- */

   unsigned int numero_ligne() {
      return LigneCour;
   }

   /* --------------------------------------------------------------------- */

   unsigned int numero_colonne() {
      return ColonneCour ;
   }

   /* --------------------------------------------------------------------- */

  void arreter_car() {
     fclose(File) ;
  } 

   /* --------------------------------------------------------------------- */

// begin
   // put("Analyseur lexical : Machine_Caracteres. ");
   // put_line("Copyright UJF - UFR IMAG.");
// end lecture_caracteres;
