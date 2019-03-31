/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     PLUS = 259,
     MINUS = 260,
     MUL = 261,
     DIV = 262,
     BEG = 263,
     READ = 264,
     WRITE = 265,
     END = 266,
     ASGN = 267,
     ID = 268,
     LT = 269,
     GT = 270,
     LE = 271,
     GE = 272,
     EQ = 273,
     NEQ = 274,
     IF = 275,
     THEN = 276,
     WHILE = 277,
     ENDWHILE = 278,
     ENDIF = 279,
     DO = 280,
     ELSE = 281,
     REPEAT = 282,
     UNTIL = 283,
     BREAK = 284,
     CONTINUE = 285,
     DECL = 286,
     ENDDECL = 287,
     INT = 288,
     STR = 289,
     STRING = 290,
     CONN = 291,
     INTTYPE = 292,
     STRTYPE = 293,
     BOOLTYPE = 294,
     MOD = 295
   };
#endif
/* Tokens.  */
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define BEG 263
#define READ 264
#define WRITE 265
#define END 266
#define ASGN 267
#define ID 268
#define LT 269
#define GT 270
#define LE 271
#define GE 272
#define EQ 273
#define NEQ 274
#define IF 275
#define THEN 276
#define WHILE 277
#define ENDWHILE 278
#define ENDIF 279
#define DO 280
#define ELSE 281
#define REPEAT 282
#define UNTIL 283
#define BREAK 284
#define CONTINUE 285
#define DECL 286
#define ENDDECL 287
#define INT 288
#define STR 289
#define STRING 290
#define CONN 291
#define INTTYPE 292
#define STRTYPE 293
#define BOOLTYPE 294
#define MOD 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "new.y"
{
 struct tnode *no;
}
/* Line 1529 of yacc.c.  */
#line 133 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

