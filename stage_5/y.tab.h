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
     BEG = 259,
     READ = 260,
     WRITE = 261,
     END = 262,
     ASGN = 263,
     ID = 264,
     IF = 265,
     THEN = 266,
     WHILE = 267,
     ENDWHILE = 268,
     ENDIF = 269,
     DO = 270,
     ELSE = 271,
     REPEAT = 272,
     UNTIL = 273,
     BREAK = 274,
     CONTINUE = 275,
     MAIN = 276,
     DECL = 277,
     ENDDECL = 278,
     INT = 279,
     STR = 280,
     CONN = 281,
     INTTYPE = 282,
     STRTYPE = 283,
     BOOLTYPE = 284,
     VARIABLE = 285,
     ARRAY = 286,
     FUNCTION = 287,
     RETURN = 288,
     NOT = 289,
     OR = 290,
     AND = 291,
     MINUS = 292,
     PLUS = 293,
     MOD = 294,
     DIV = 295,
     MUL = 296,
     NEQ = 297,
     EQ = 298,
     GE = 299,
     LE = 300,
     GT = 301,
     LT = 302
   };
#endif
/* Tokens.  */
#define NUM 258
#define BEG 259
#define READ 260
#define WRITE 261
#define END 262
#define ASGN 263
#define ID 264
#define IF 265
#define THEN 266
#define WHILE 267
#define ENDWHILE 268
#define ENDIF 269
#define DO 270
#define ELSE 271
#define REPEAT 272
#define UNTIL 273
#define BREAK 274
#define CONTINUE 275
#define MAIN 276
#define DECL 277
#define ENDDECL 278
#define INT 279
#define STR 280
#define CONN 281
#define INTTYPE 282
#define STRTYPE 283
#define BOOLTYPE 284
#define VARIABLE 285
#define ARRAY 286
#define FUNCTION 287
#define RETURN 288
#define NOT 289
#define OR 290
#define AND 291
#define MINUS 292
#define PLUS 293
#define MOD 294
#define DIV 295
#define MUL 296
#define NEQ 297
#define EQ 298
#define GE 299
#define LE 300
#define GT 301
#define LT 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

