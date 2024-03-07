#include <stdio.h> 

#include "ast_construction.h"
#include "ast_parcours.h"

int main() {

 Ast ast1, ast2, ast3, ast4, ast ;

 /*
 //((12+3)*2)
  ast1  = creer_valeur(12) ;
  ast2  = creer_valeur(3) ;
  ast3 = creer_operation(N_PLUS, ast1, ast2) ;
  ast4  = creer_valeur(2) ;
  ast = creer_operation(N_MUL, ast3, ast4) ;


 //2 + 3 * 5 - 2
  ast1  = creer_valeur(12) ;
  ast2  = creer_valeur(3) ;
  ast3 = creer_operation(N_PLUS, ast1, ast2) ;
  ast4  = creer_valeur(2) ;
  ast = creer_operation(N_MUL, ast3, ast4) ;

//(2 + 3) * (5 - 2)
  ast1  = creer_valeur(12) ;
  ast2  = creer_valeur(3) ;
  ast3 = creer_operation(N_PLUS, ast1, ast2) ;
  ast4  = creer_valeur(2) ;
  ast = creer_operation(N_MUL, ast3, ast4) ;


 //((12+3)*2)
  ast1  = creer_valeur(12) ;
  ast2  = creer_valeur(3) ;
  ast3 = creer_operation(N_PLUS, ast1, ast2) ;
  ast4  = creer_valeur(2) ;
  ast = creer_operation(N_MUL, ast3, ast4) ;

  */

 printf("Arbre abstrait de l'expression\n") ;
 afficher(ast) ; 
 printf("\n\nValeur de l'expression : %d\n", evaluation(ast)) ;
 return 0 ;

}
