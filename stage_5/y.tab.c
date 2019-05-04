/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "fun.y"
  
    #define YYSTYPE struct tnode*
	#include <stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "symbol.h"
    #include "symbol.c"
    #include "parameter.h"
    #include "parameter.c"
    #include "tree.h"
    #include "tree.c"
    #include "codegen.h"
    #include "codegen.c"

;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 217 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   470

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    16,    19,    21,    24,
      25,    30,    32,    34,    38,    40,    42,    47,    52,    53,
      57,    59,    62,    65,    67,    68,    69,    81,    82,    85,
      89,    91,    94,    98,   100,   104,   109,   113,   114,   124,
     128,   131,   133,   135,   137,   142,   147,   151,   155,   159,
     163,   167,   171,   175,   179,   183,   187,   191,   195,   199,
     202,   206,   211,   217,   223,   234,   243,   252,   260,   268,
     271,   274,   278
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    67,    76,    -1,    58,    76,    -1,
      76,    -1,    22,    59,    23,    -1,    22,    23,    -1,    60,
      -1,    59,    60,    -1,    -1,    62,    61,    63,    48,    -1,
      24,    -1,    25,    -1,    63,    49,    64,    -1,    64,    -1,
       9,    -1,     9,    50,     3,    51,    -1,     9,    52,    65,
      53,    -1,    -1,    65,    49,    66,    -1,    66,    -1,    62,
       9,    -1,    67,    68,    -1,    68,    -1,    -1,    -1,    62,
       9,    69,    52,    65,    53,    70,    54,    71,    75,    55,
      -1,    -1,    22,    23,    -1,    22,    72,    23,    -1,    73,
      -1,    72,    73,    -1,    62,    74,    48,    -1,     9,    -1,
      74,    49,     9,    -1,     4,    79,    78,     7,    -1,     4,
      78,     7,    -1,    -1,    24,    21,    52,    53,    77,    54,
      71,    75,    55,    -1,    33,    80,    48,    -1,    79,    81,
      -1,    81,    -1,     3,    -1,     9,    -1,     9,    50,    80,
      51,    -1,     9,    52,    82,    53,    -1,    80,    38,    80,
      -1,    80,    37,    80,    -1,    80,    41,    80,    -1,    80,
      40,    80,    -1,    80,    39,    80,    -1,    80,    47,    80,
      -1,    80,    46,    80,    -1,    80,    45,    80,    -1,    80,
      44,    80,    -1,    80,    43,    80,    -1,    80,    42,    80,
      -1,    80,    36,    80,    -1,    80,    35,    80,    -1,    34,
      80,    -1,    52,    80,    53,    -1,    80,     8,    80,    48,
      -1,     5,    52,    80,    53,    48,    -1,     6,    52,    80,
      53,    48,    -1,    10,    52,    80,    53,    11,    79,    16,
      79,    14,    48,    -1,    10,    52,    80,    53,    11,    79,
      14,    48,    -1,    12,    52,    80,    53,    15,    79,    13,
      48,    -1,    15,    79,    12,    52,    80,    53,    48,    -1,
      17,    79,    18,    52,    80,    53,    48,    -1,    19,    48,
      -1,    20,    48,    -1,    82,    49,    80,    -1,    80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    29,    30,    33,    34,    37,    38,    41,
      41,    44,    45,    48,    49,    53,    54,    56,    59,    60,
      61,    65,    68,    69,    72,    73,    72,    84,    85,    86,
      89,    90,    93,    96,    97,   100,   101,   104,   104,   110,
     113,   114,   117,   118,   121,   123,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   157,   158
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "BEG", "READ", "WRITE", "END",
  "ASGN", "ID", "IF", "THEN", "WHILE", "ENDWHILE", "ENDIF", "DO", "ELSE",
  "REPEAT", "UNTIL", "BREAK", "CONTINUE", "MAIN", "DECL", "ENDDECL", "INT",
  "STR", "CONN", "INTTYPE", "STRTYPE", "BOOLTYPE", "VARIABLE", "ARRAY",
  "FUNCTION", "RETURN", "NOT", "OR", "AND", "MINUS", "PLUS", "MOD", "DIV",
  "MUL", "NEQ", "EQ", "GE", "LE", "GT", "LT", "';'", "','", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "$accept", "start", "Gdeclblock",
  "Gdecllist", "Gdecl", "@1", "Type", "Glist", "Gid", "Paralist", "para",
  "Fdefblock", "Fdef", "@2", "@3", "Ldeclblock", "Ldecllist", "LDecl",
  "Llist", "Body", "Mainblock", "@4", "Rstmt", "Slist", "exp", "stmt",
  "Arglist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    59,    44,
      91,    93,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    59,    59,    61,
      60,    62,    62,    63,    63,    64,    64,    64,    65,    65,
      65,    66,    67,    67,    69,    70,    68,    71,    71,    71,
      72,    72,    73,    74,    74,    75,    75,    77,    76,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     1,     2,     0,
       4,     1,     1,     3,     1,     1,     4,     4,     0,     3,
       1,     2,     2,     1,     0,     0,    11,     0,     2,     3,
       1,     2,     3,     1,     3,     4,     3,     0,     9,     3,
       2,     1,     1,     1,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     4,     5,     5,    10,     8,     8,     7,     7,     2,
       2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    11,    12,     0,
       7,     9,     0,     1,    11,     0,     0,    23,     3,     5,
       8,     0,     0,    24,    22,     2,    15,     0,    14,    37,
       0,     0,    18,    10,     0,     0,    18,     0,     0,     0,
      20,    13,    27,     0,    16,    21,     0,    17,     0,     0,
      25,    19,    28,     0,     0,    30,     0,     0,     0,    33,
       0,    29,    31,    42,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      38,    27,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    70,     0,    59,     0,    36,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,    72,
       0,     0,     0,     0,     0,    39,    60,    35,     0,    58,
      57,    47,    46,    50,    49,    48,    56,    55,    54,    53,
      52,    51,     0,     0,     0,    44,     0,    45,     0,     0,
       0,     0,    61,    26,    62,    63,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      65,     0,    66,     0,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    21,    38,    27,    28,    39,
      40,    16,    17,    30,    58,    49,    54,    55,    60,    57,
       5,    35,    76,    77,    78,    79,   120
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
      27,    57,     3,    32,   -21,   -76,   -76,   -76,   -76,   114,
     -76,   -76,     1,   -76,     3,    50,   -21,   -76,   -76,   -76,
     -76,    55,    16,   -76,   -76,   -76,    41,   -36,   -76,   -76,
      26,    87,    93,   -76,    55,    53,    93,    44,    95,   -44,
     -76,   -76,    92,   -39,   -76,   -76,    93,   -76,   119,   120,
     -76,   -76,   -76,   100,   122,   -76,    96,    65,    73,   -76,
     105,   -76,   -76,   -76,    80,    88,    60,   108,   110,   187,
     187,   109,   121,    89,    89,    89,   157,    96,   226,   -76,
     -76,    92,   -76,   158,    89,    89,    89,    89,    89,    89,
     208,   116,   -76,   -76,   209,   414,   239,   -76,   164,   -76,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,   120,   -76,   258,   277,   372,   403,
      -1,   296,   315,   123,   126,   -76,   -76,   -76,   389,   414,
     414,   423,   423,   -16,   -16,   -16,    30,    30,    30,    30,
      30,    30,   128,   137,   140,   -76,    89,   -76,   163,   174,
      89,    89,   -76,   -76,   -76,   -76,   403,   187,   187,   334,
     353,    51,   146,    10,   143,   147,   187,   152,   -76,   -76,
     -76,   167,   -76,   155,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   185,   -76,    46,   -76,   171,   172,
     166,   -76,   193,   -76,   -76,   129,   -76,   161,   -76,   102,
       7,   -76,   145,   -69,   -67,   -75,   -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      90,    91,    99,    14,     8,    46,    94,    95,    96,    47,
      46,    18,    33,    34,    50,    99,    99,   116,   117,   118,
     119,   121,   122,    25,    12,   158,   108,   109,   110,   111,
     112,   113,    13,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    11,   146,     1,
      15,     2,   147,    22,    63,    11,    64,    65,   168,    23,
      66,    67,    15,    68,    26,   165,    69,   166,    70,    29,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    36,   156,
       6,     7,     8,   159,   160,    74,    99,    99,   161,   162,
      37,    31,    63,    32,    53,    44,    99,   171,    66,    63,
      53,    64,    65,    75,    45,    66,    67,    42,    68,    59,
      86,    69,    87,    70,    48,    71,    72,     7,     8,    63,
      80,    64,    65,    74,    56,    66,    67,    81,    68,    73,
      74,    69,    84,    70,   124,    71,    72,    19,     7,     8,
      85,    75,    52,     7,     8,    61,     7,     8,    75,    63,
      74,    64,    65,    82,    83,    66,    67,    92,    68,   167,
      88,    69,    89,    70,    97,    71,    72,   115,    75,    93,
      63,   127,    64,    65,   157,   150,    66,    67,   151,    68,
      74,   173,    69,   153,    70,   154,    71,    72,   155,   158,
      63,   169,    64,    65,    20,   170,    66,    67,    75,    68,
     172,    74,    69,   174,    70,    41,    71,    72,    43,    24,
     114,    63,    51,    64,    65,    62,   142,    66,    67,    75,
     123,    74,    98,    69,     0,    70,     0,    71,    72,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,    75,
       0,     0,    74,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   125,     0,     0,
      75,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,     0,     0,
       0,     0,   126,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,     0,
       0,   143,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
     144,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,   148,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,     0,   149,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,   163,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,   164,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,   145,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   152,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   105,   106,   107,   108,   109,   110,   111,   112,
     113
};

static const yytype_int16 yycheck[] =
{
      69,    70,    77,    24,    25,    49,    73,    74,    75,    53,
      49,     4,    48,    49,    53,    90,    91,    84,    85,    86,
      87,    88,    89,    16,    21,    15,    42,    43,    44,    45,
      46,    47,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     1,    49,    22,
       4,    24,    53,    52,     3,     9,     5,     6,    48,     9,
       9,    10,    16,    12,     9,    14,    15,    16,    17,    53,
      19,    20,    42,    43,    44,    45,    46,    47,    52,   146,
      23,    24,    25,   150,   151,    34,   161,   162,   157,   158,
       3,    50,     3,    52,    48,    51,   171,   166,     9,     3,
      54,     5,     6,    52,     9,     9,    10,    54,    12,     9,
      50,    15,    52,    17,    22,    19,    20,    24,    25,     3,
      55,     5,     6,    34,     4,     9,    10,    54,    12,    33,
      34,    15,    52,    17,    18,    19,    20,    23,    24,    25,
      52,    52,    23,    24,    25,    23,    24,    25,    52,     3,
      34,     5,     6,    48,    49,     9,    10,    48,    12,    13,
      52,    15,    52,    17,     7,    19,    20,     9,    52,    48,
       3,     7,     5,     6,    11,    52,     9,    10,    52,    12,
      34,    14,    15,    55,    17,    48,    19,    20,    48,    15,
       3,    48,     5,     6,     9,    48,     9,    10,    52,    12,
      48,    34,    15,    48,    17,    34,    19,    20,    36,    16,
      81,     3,    46,     5,     6,    54,   114,     9,    10,    52,
      12,    34,    77,    15,    -1,    17,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    34,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      52,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    53,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      53,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    53,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    53,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    39,    40,    41,    42,    43,    44,    45,    46,
      47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    24,    57,    58,    76,    23,    24,    25,    59,
      60,    62,    21,     0,    24,    62,    67,    68,    76,    23,
      60,    61,    52,     9,    68,    76,     9,    63,    64,    53,
      69,    50,    52,    48,    49,    77,    52,     3,    62,    65,
      66,    64,    54,    65,    51,     9,    49,    53,    22,    71,
      53,    66,    23,    62,    72,    73,     4,    75,    70,     9,
      74,    23,    73,     3,     5,     6,     9,    10,    12,    15,
      17,    19,    20,    33,    34,    52,    78,    79,    80,    81,
      55,    54,    48,    49,    52,    52,    50,    52,    52,    52,
      79,    79,    48,    48,    80,    80,    80,     7,    78,    81,
       8,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    71,     9,    80,    80,    80,    80,
      82,    80,    80,    12,    18,    48,    53,     7,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    75,    53,    53,    51,    49,    53,    53,    53,
      52,    52,    48,    55,    48,    48,    80,    11,    15,    80,
      80,    79,    79,    53,    53,    14,    16,    13,    48,    48,
      48,    79,    48,    14,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 33 "fun.y"
    {Gprinttable();initialize();}
    break;

  case 9:
#line 41 "fun.y"
    {dectype=ctype;}
    break;

  case 11:
#line 44 "fun.y"
    {ctype=INTTYPE;}
    break;

  case 12:
#line 45 "fun.y"
    {ctype=STRTYPE;}
    break;

  case 15:
#line 53 "fun.y"
    {Ginstall((yyvsp[(1) - (1)])->stringVal,dectype,1,VARIABLE,NULL);}
    break;

  case 16:
#line 54 "fun.y"
    {if((yyvsp[(3) - (4)])->intVal<=0) {printf("array %s size invalid ",(yyvsp[(1) - (4)])->stringVal);exit(1);}
		                      Ginstall((yyvsp[(1) - (4)])->stringVal,dectype,(yyvsp[(3) - (4)])->intVal,ARRAY,NULL);}
    break;

  case 17:
#line 56 "fun.y"
    {Ginstall((yyvsp[(1) - (4)])->stringVal,dectype,-1,FUNCTION,parahead);parahead=NULL;}
    break;

  case 21:
#line 65 "fun.y"
    { Parainstall((yyvsp[(2) - (2)])->stringVal,ctype); }
    break;

  case 24:
#line 72 "fun.y"
    {dectype=ctype;}
    break;

  case 25:
#line 73 "fun.y"
    {struct Gsymbol *temp=GLookup((yyvsp[(2) - (6)])->stringVal);
                            if(temp== NULL){printf("function %s not defined ",(yyvsp[(2) - (6)])->stringVal);exit(1);}
                            if(temp->type != dectype){printf("fun %s invalid return type",(yyvsp[(2) - (6)])->stringVal);exit(1);}
                            checkpara(parahead,temp->paralist);Lparainstall();parahead=NULL;
                             fprintf(out,"F%d: ",temp->flabel);}
    break;

  case 26:
#line 78 "fun.y"
    {Lprinttable();fungen((yyvsp[(10) - (11)]));
                             struct Gsymbol *temp = GLookup((yyvsp[(2) - (11)])->stringVal);
                             if(temp->size == 0) {printf("multiple function declaration");exit(1);}
                             temp->size=0;Lsymboltable=NULL;}
    break;

  case 33:
#line 96 "fun.y"
    {Linstall((yyvsp[(1) - (1)])->stringVal,ctype);}
    break;

  case 34:
#line 97 "fun.y"
    {Linstall((yyvsp[(3) - (3)])->stringVal,ctype);}
    break;

  case 35:
#line 100 "fun.y"
    {(yyval) = Createtree(0,0,NULL,CONN,(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),NULL);}
    break;

  case 36:
#line 101 "fun.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 37:
#line 104 "fun.y"
    { dectype=INTTYPE;fprintf(out,"MAIN: ");}
    break;

  case 38:
#line 106 "fun.y"
    {Lprinttable();fungen((yyvsp[(8) - (9)]));Lsymboltable=NULL;}
    break;

  case 39:
#line 110 "fun.y"
    {(yyval)=Createtree(0,0,NULL,RETURN,(yyvsp[(2) - (3)]),NULL,NULL);}
    break;

  case 40:
#line 113 "fun.y"
    {(yyval)=Createtree(0,0,NULL,CONN,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),NULL);}
    break;

  case 41:
#line 114 "fun.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 43:
#line 118 "fun.y"
    {(yyvsp[(1) - (1)])->Gentry = GLookup((yyvsp[(1) - (1)])->stringVal); (yyvsp[(1) - (1)])->Lentry=  LLookup((yyvsp[(1) - (1)])->stringVal); 
                              if((yyvsp[(1) - (1)])->Lentry == NULL) if((yyvsp[(1) - (1)])->Gentry == NULL) 
                              {printf("undeclared variable %s\n",(yyvsp[(1) - (1)])->stringVal);exit(1);}Variable((yyvsp[(1) - (1)]));(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 44:
#line 121 "fun.y"
    {(yyvsp[(1) - (4)])->Gentry = GLookup((yyvsp[(1) - (4)])->stringVal); if((yyvsp[(1) - (4)])->Gentry == NULL) 
                              {printf("undeclared array %s\n",(yyvsp[(1) - (4)])->stringVal);exit(1);}Array((yyvsp[(1) - (4)]));(yyvsp[(1) - (4)])->left=(yyvsp[(3) - (4)]);checkindex((yyvsp[(3) - (4)]));(yyval) = (yyvsp[(1) - (4)]);}
    break;

  case 45:
#line 123 "fun.y"
    {(yyvsp[(1) - (4)])->Gentry = GLookup((yyvsp[(1) - (4)])->stringVal); (yyvsp[(1) - (4)])->Lentry=  LLookup((yyvsp[(1) - (4)])->stringVal); 
                              if((yyvsp[(1) - (4)])->Lentry == NULL) if((yyvsp[(1) - (4)])->Gentry == NULL) 
                              {printf("undeclared function %s\n",(yyvsp[(1) - (4)])->stringVal);exit(1);}Function((yyvsp[(1) - (4)]));
                              (yyvsp[(1) - (4)])->Arglist=arghead;checkarg((yyvsp[(1) - (4)]));arghead=NULL;(yyval) = (yyvsp[(1) - (4)]);}
    break;

  case 46:
#line 127 "fun.y"
    {(yyval) = Createtree(0,INTTYPE,NULL,PLUS,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 47:
#line 128 "fun.y"
    {(yyval) = Createtree(0,INTTYPE,NULL,MINUS,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 48:
#line 129 "fun.y"
    {(yyval) = Createtree(0,INTTYPE,NULL,MUL,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 49:
#line 130 "fun.y"
    {(yyval) = Createtree(0,INTTYPE,NULL,DIV,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 50:
#line 131 "fun.y"
    {(yyval) = Createtree(0,INTTYPE,NULL,MOD,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 51:
#line 132 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,LT,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 52:
#line 133 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,GT,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 53:
#line 134 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,LE,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 54:
#line 135 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,GE,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 55:
#line 136 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,EQ,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 56:
#line 137 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,NEQ,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 57:
#line 138 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,AND,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 58:
#line 139 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,OR,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);}
    break;

  case 59:
#line 140 "fun.y"
    {(yyval) = Createtree(0,BOOLTYPE,NULL,NOT,(yyvsp[(2) - (2)]),NULL,NULL);}
    break;

  case 60:
#line 141 "fun.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 61:
#line 145 "fun.y"
    {(yyval) = Createtree(0,0,'=',ASGN,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);}
    break;

  case 62:
#line 146 "fun.y"
    {(yyval) = Createtree(0,0,NULL,READ,(yyvsp[(3) - (5)]),NULL,NULL);}
    break;

  case 63:
#line 147 "fun.y"
    {(yyval) = Createtree(0,0,NULL,WRITE,(yyvsp[(3) - (5)]),NULL,NULL);}
    break;

  case 64:
#line 148 "fun.y"
    {(yyval) = Createtree(0,0,NULL,IF,(yyvsp[(3) - (10)]),(yyvsp[(6) - (10)]),(yyvsp[(8) - (10)]));}
    break;

  case 65:
#line 149 "fun.y"
    {(yyval) = Createtree(0,0,NULL,IF,(yyvsp[(3) - (8)]),(yyvsp[(6) - (8)]),NULL);}
    break;

  case 66:
#line 150 "fun.y"
    {(yyval) = Createtree(0,0,NULL,WHILE,(yyvsp[(3) - (8)]),(yyvsp[(6) - (8)]),NULL);}
    break;

  case 67:
#line 151 "fun.y"
    {(yyval) = Createtree(0,0,NULL,DO,(yyvsp[(5) - (7)]),(yyvsp[(2) - (7)]),NULL);}
    break;

  case 68:
#line 152 "fun.y"
    {(yyval) = Createtree(0,0,NULL,REPEAT,(yyvsp[(5) - (7)]),(yyvsp[(2) - (7)]),NULL);}
    break;

  case 69:
#line 153 "fun.y"
    {(yyval) = Createtree(0,0,NULL,BREAK,NULL,NULL,NULL);}
    break;

  case 70:
#line 154 "fun.y"
    {(yyval) = Createtree(0,0,NULL,CONTINUE,NULL,NULL,NULL);}
    break;

  case 71:
#line 157 "fun.y"
    {Arginstall((yyvsp[(3) - (3)]));}
    break;

  case 72:
#line 158 "fun.y"
    {Arginstall((yyvsp[(1) - (1)]));}
    break;


/* Line 1267 of yacc.c.  */
#line 1883 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 161 "fun.y"


void yyerror(char *s)
{
    printf("error in yacc %s",s);
	exit(0);
}

int main(int argc,char* argv[]) {
if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
}   
    out=fopen(argv[2],"w");
	yyparse();
    return 0;
}
void checkindex(struct tnode* node)
{
	int type=gettype(node);
	if(type != INTTYPE)
	{
		printf("invalid array size");
		exit(1);
	}
}

void checkarg(struct tnode* node)
{
    struct parameter *para=node->Gentry->paralist;
    struct argument *arg=getarg();
    if(para == NULL && arg == NULL) return;
    while(para!=NULL && arg !=NULL)
    {
        if(para->type==gettype(arg->node))
        {
            para=para->next;
            arg=arg->prev;
            continue;
        }
        printf("parameter %s mismatch ",node->stringVal);
        exit(1);
    
    }
    if(!(para==NULL && arg== NULL))
    {
        printf("parameter %s mismatch",node->stringVal);
        exit(1);
    }
}

void Variable(struct tnode *node)
{
    int design = getdesign(node->stringVal);
    if(design != VARIABLE)
    {    
        printf("ERROR: variable id %s invalid \n",node->stringVal);
        exit(1);
    }
}
void Array(struct tnode *node)
{
    int design = getdesign(node->stringVal);
    if(design != ARRAY)
    { 
        printf("ERROR: variable array %s invalid \n",node->stringVal);
        exit(1);
    }
}
void Function(struct tnode* node)
{
    int design=getdesign(node->stringVal);
    if(design!=FUNCTION)
    {
        printf("ERROR:Function %s invalid",node->stringVal);
        exit(1);
    }
}

int getdesign(char *name)
{
   struct Lsymbol *ptr= Lsymboltable;
    while(ptr!=NULL)
    {
        if(!(strcmp(name,ptr->name)))
        {
            return VARIABLE;
        }
        ptr=ptr->next;
    }

    struct Gsymbol *ptr2 = Gsymboltable;
    while(ptr2 != NULL)
    {
        if(!(strcmp(name,ptr2->name)))
        {
            return ptr2->design;
        }
        ptr2 = ptr2->next;
    }
    return 0;
}

