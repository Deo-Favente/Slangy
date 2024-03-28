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

void rec_pgm(Ast *A);

void rec_instructions(Ast *A);

void rec_instruction(Ast *A);

void rec_expression(Ast *A);

void rec_variable(Ast *A);
