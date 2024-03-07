#include "type_ast.h"
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

void analyser(char *fichier, Ast *A);
//--e.i : indifferent
//-- e.f : une Expression Arithmetique a ete lue dans fichier
//-- si elle ne contient pas d’erreur de syntaxe un message est affiche
//-- sinon le pgm termine sur un message d’erreur

void rec_suite_seq_facteur(Ast *Ag, Ast *A);

void rec_eag();

void rec_op1(TypeOperateur *op);

void rec_op2(TypeOperateur *op);

void rec_terme(Ast *A);

void rec_facteur(Ast *A);

void rec_suite_seq_terme(Ast *Ag, Ast *A);

void rec_seq_facteur(Ast *A);

void rec_seq_terme(Ast *A);

void rec_eag(Ast *A);
