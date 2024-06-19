
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 16 "sysy.y"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "Nodes.h"
#include "NodesManager.h"
using namespace std;
void yyerror(NodesManager &manager, const char *s);
int yylex();


/* Line 189 of yacc.c  */
#line 90 "sysy.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 2 "sysy.y"

    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>
    #include <map>
    #include <set>
    #include <cmath>
    #include <cstdlib>
    #include "Nodes.h"
    #include "NodesManager.h"
    using namespace std;



/* Line 209 of yacc.c  */
#line 130 "sysy.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     VOID = 259,
     RETURN = 260,
     CONST = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     BREAK = 265,
     CONTINUE = 266,
     IDENT = 267,
     INT_CONST = 268,
     LE = 269,
     GE = 270,
     EQ = 271,
     NE = 272,
     AND = 273,
     OR = 274
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 35 "sysy.y"

    string *stringPointer;
    int integer32;
    BaseAST *astPointer;
    vector<BaseAST *> *vectorPointer;



/* Line 214 of yacc.c  */
#line 175 "sysy.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 187 "sysy.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,    33,     2,     2,
      20,    21,    31,    29,    22,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      27,    26,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    15,    21,    28,
      34,    41,    43,    47,    50,    52,    56,    60,    62,    64,
      68,    71,    76,    78,    81,    83,    86,    89,    97,   103,
     109,   117,   123,   125,   127,   131,   133,   137,   139,   143,
     147,   149,   153,   157,   161,   165,   167,   171,   175,   177,
     181,   185,   189,   191,   194,   198,   203,   207,   209,   211,
     213,   215,   220,   224,   226,   228,   230,   232,   236,   238,
     242,   244,   245,   248,   250,   254,   256,   260,   262,   264,
     266,   268,   270,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    -1,    55,    -1,    37,
      38,    -1,    37,    55,    -1,    70,    12,    20,    21,    42,
      -1,    70,    12,    20,    39,    21,    42,    -1,    69,    12,
      20,    21,    42,    -1,    69,    12,    20,    39,    21,    42,
      -1,    40,    -1,    39,    22,    40,    -1,    69,    12,    -1,
      46,    -1,    41,    22,    46,    -1,    23,    64,    24,    -1,
      45,    -1,    44,    -1,     5,    46,    25,    -1,     5,    25,
      -1,    68,    26,    46,    25,    -1,    42,    -1,    46,    25,
      -1,    25,    -1,    10,    25,    -1,    11,    25,    -1,     7,
      20,    46,    21,    44,     8,    44,    -1,     9,    20,    46,
      21,    44,    -1,     7,    20,    46,    21,    43,    -1,     7,
      20,    46,    21,    44,     8,    45,    -1,     9,    20,    46,
      21,    45,    -1,    47,    -1,    48,    -1,    47,    19,    48,
      -1,    49,    -1,    48,    18,    49,    -1,    50,    -1,    49,
      16,    50,    -1,    49,    17,    50,    -1,    51,    -1,    50,
      14,    51,    -1,    50,    15,    51,    -1,    50,    27,    51,
      -1,    50,    28,    51,    -1,    52,    -1,    51,    29,    52,
      -1,    51,    30,    52,    -1,    53,    -1,    52,    31,    53,
      -1,    52,    32,    53,    -1,    52,    33,    53,    -1,    54,
      -1,    71,    53,    -1,    12,    20,    21,    -1,    12,    20,
      41,    21,    -1,    20,    46,    21,    -1,    67,    -1,    68,
      -1,    56,    -1,    61,    -1,     6,    69,    65,    25,    -1,
      12,    26,    58,    -1,    60,    -1,    55,    -1,    43,    -1,
      46,    -1,    69,    66,    25,    -1,    12,    -1,    12,    26,
      63,    -1,    46,    -1,    -1,    64,    59,    -1,    57,    -1,
      65,    22,    57,    -1,    62,    -1,    66,    22,    62,    -1,
      13,    -1,    12,    -1,     3,    -1,     4,    -1,    29,    -1,
      30,    -1,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    62,    70,    78,    86,    96,   107,   122,
     133,   151,   158,   167,   179,   186,   195,   206,   212,   222,
     230,   238,   248,   256,   264,   272,   279,   288,   298,   309,
     318,   328,   340,   349,   357,   369,   377,   388,   396,   405,
     416,   424,   433,   442,   451,   462,   470,   479,   490,   498,
     507,   516,   527,   535,   545,   554,   568,   576,   584,   595,
     603,   613,   626,   637,   646,   654,   664,   673,   686,   695,
     707,   717,   722,   731,   738,   747,   754,   764,   771,   780,
     791,   799,   805,   811
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "RETURN", "CONST", "IF",
  "ELSE", "WHILE", "BREAK", "CONTINUE", "IDENT", "INT_CONST", "LE", "GE",
  "EQ", "NE", "AND", "OR", "'('", "')'", "','", "'{'", "'}'", "';'", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "Start", "CompUnit", "FuncDef", "FuncFParams", "FuncFParam",
  "FuncRParams", "Block", "Stmt", "ClosedStmt", "OpenStmt", "Exp",
  "LOrExp", "LAndExp", "EqExp", "RelExp", "AddExp", "MulExp", "UnaryExp",
  "PrimaryExp", "Decl", "ConstDecl", "ConstDef", "ConstInitVal",
  "BlockItem", "ConstExp", "VarDecl", "VarDef", "InitVal", "BlockItemList",
  "ConstDefList", "VarDefList", "Number", "LVal", "BType", "VoidType",
  "UNARYOP", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    44,   123,   125,    59,    61,    60,    62,    43,
      45,    42,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    37,    38,    38,    38,
      38,    39,    39,    40,    41,    41,    42,    43,    43,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    52,    53,    53,    53,    53,    54,    54,    54,    55,
      55,    56,    57,    58,    59,    59,    60,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    69,
      70,    71,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     5,     6,     5,
       6,     1,     3,     2,     1,     3,     3,     1,     1,     3,
       2,     4,     1,     2,     1,     2,     2,     7,     5,     5,
       7,     5,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     3,     4,     3,     1,     1,     1,
       1,     4,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     0,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    79,    80,     0,     0,     2,     3,     4,    59,    60,
       0,     0,     0,     1,     5,     6,    68,    75,     0,     0,
       0,    73,     0,     0,     0,     0,    67,     0,     0,     0,
      61,     0,     0,    11,     0,    78,    77,     0,    81,    82,
      83,    70,    32,    33,    35,    37,    40,    45,    48,    52,
      69,    57,    58,     0,    68,    76,     0,     0,    66,    62,
      63,    74,    71,     9,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     7,     0,     0,    10,    12,    54,     0,
      14,    56,    34,    36,    38,    39,    41,    42,    43,    44,
      46,    47,    49,    50,    51,     8,     0,     0,     0,     0,
       0,    16,    24,    22,    65,    18,    17,     0,    64,    72,
      58,     0,    55,     0,    20,     0,     0,     0,    25,    26,
      23,     0,    15,    19,     0,     0,     0,     0,     0,    21,
      29,    18,    28,    31,     0,    27,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    32,    33,    89,   113,   114,   115,
     116,   117,    42,    43,    44,    45,    46,    47,    48,    49,
       7,     8,    21,    59,   119,    60,     9,    17,    50,    85,
      22,    18,    51,    52,    34,    11,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int16 yypact[] =
{
      72,  -125,  -125,    31,    38,    72,  -125,  -125,  -125,  -125,
      32,    36,    42,  -125,  -125,  -125,   -10,  -125,     8,    41,
      47,  -125,    70,     5,    96,    65,  -125,     6,    96,    42,
    -125,    67,     7,  -125,    82,    84,  -125,    96,  -125,  -125,
    -125,  -125,    87,   106,    -5,    83,    56,    86,  -125,  -125,
    -125,  -125,  -125,    96,   107,  -125,    67,    99,  -125,  -125,
    -125,  -125,  -125,  -125,    67,    31,  -125,    59,   113,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,  -125,  -125,    67,    12,  -125,  -125,  -125,   101,
    -125,  -125,   106,    -5,    83,    83,    56,    56,    56,    56,
      86,    86,  -125,  -125,  -125,  -125,    71,   115,   116,   102,
     112,  -125,  -125,  -125,  -125,  -125,  -125,   114,  -125,  -125,
     117,    65,  -125,    96,  -125,   119,    96,    96,  -125,  -125,
    -125,    96,  -125,  -125,   120,   121,   122,    40,    40,  -125,
    -125,   130,  -125,  -125,    40,  -125,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,   135,   118,    81,  -125,   -25,    11,   -80,
    -124,   -24,  -125,    80,    85,    57,    39,    54,   -13,  -125,
      -4,  -125,   123,  -125,  -125,  -125,  -125,   125,  -125,  -125,
    -125,  -125,  -125,   -82,     2,  -125,  -125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    15,    10,   120,    58,    12,    63,    10,     1,     1,
      23,    71,    72,    68,   143,     1,    24,   106,     3,   107,
     146,   108,   109,   110,    35,    36,    31,    56,    64,    65,
      25,    83,    37,    26,     1,    62,   111,   112,    13,    86,
      82,    38,    39,    90,    16,   106,    40,   107,    19,   108,
     109,   110,    35,    36,    20,   120,   120,   141,   142,   105,
      37,    27,   120,    62,   145,   112,   102,   103,   104,    38,
      39,    35,    36,    28,    40,     1,     2,    54,     3,    37,
      88,   118,   125,    35,    36,    77,    78,   121,    38,    39,
      62,    37,    29,    40,    66,    30,   124,    73,    74,   132,
      38,    39,   134,   135,    67,    40,    69,   136,    35,    36,
      75,    76,    96,    97,    98,    99,    37,    79,    80,    81,
      84,    65,   122,   123,    70,    38,    39,   128,    94,    95,
      40,   100,   101,    24,    91,   126,   127,   129,   144,   130,
      14,   137,   138,   131,   133,    57,    87,   139,   140,    92,
      55,     0,    61,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
      24,     5,     0,    85,    28,     3,    31,     5,     3,     3,
      20,    16,    17,    37,   138,     3,    26,     5,     6,     7,
     144,     9,    10,    11,    12,    13,    21,    21,    21,    22,
      22,    56,    20,    25,     3,    23,    24,    25,     0,    64,
      53,    29,    30,    67,    12,     5,    34,     7,    12,     9,
      10,    11,    12,    13,    12,   137,   138,   137,   138,    84,
      20,    20,   144,    23,   144,    25,    79,    80,    81,    29,
      30,    12,    13,    26,    34,     3,     4,    12,     6,    20,
      21,    85,   106,    12,    13,    29,    30,    85,    29,    30,
      23,    20,    22,    34,    12,    25,    25,    14,    15,   123,
      29,    30,   126,   127,    20,    34,    19,   131,    12,    13,
      27,    28,    73,    74,    75,    76,    20,    31,    32,    33,
      21,    22,    21,    22,    18,    29,    30,    25,    71,    72,
      34,    77,    78,    26,    21,    20,    20,    25,     8,    25,
       5,    21,    21,    26,    25,    27,    65,    25,   137,    69,
      25,    -1,    29,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    36,    37,    38,    55,    56,    61,
      69,    70,    69,     0,    38,    55,    12,    62,    66,    12,
      12,    57,    65,    20,    26,    22,    25,    20,    26,    22,
      25,    21,    39,    40,    69,    12,    13,    20,    29,    30,
      34,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      63,    67,    68,    71,    12,    62,    21,    39,    46,    58,
      60,    57,    23,    42,    21,    22,    12,    20,    46,    19,
      18,    16,    17,    14,    15,    27,    28,    29,    30,    31,
      32,    33,    53,    42,    21,    64,    42,    40,    21,    41,
      46,    21,    48,    49,    50,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    53,    42,     5,     7,     9,    10,
      11,    24,    25,    42,    43,    44,    45,    46,    55,    59,
      68,    69,    21,    22,    25,    46,    20,    20,    25,    25,
      25,    26,    46,    25,    46,    46,    46,    21,    21,    25,
      43,    44,    44,    45,     8,    44,    45
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
      yyerror (manager, YY_("syntax error: cannot back up")); \
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value, manager); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, NodesManager &manager)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, manager)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    NodesManager &manager;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (manager);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, NodesManager &manager)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, manager)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    NodesManager &manager;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, manager);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, NodesManager &manager)
#else
static void
yy_reduce_print (yyvsp, yyrule, manager)
    YYSTYPE *yyvsp;
    int yyrule;
    NodesManager &manager;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , manager);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, manager); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, NodesManager &manager)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, manager)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    NodesManager &manager;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (manager);

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
int yyparse (NodesManager &manager);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (NodesManager &manager)
#else
int
yyparse (manager)
    NodesManager &manager;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 2:

/* Line 1455 of yacc.c  */
#line 56 "sysy.y"
    {
        manager.root = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 63 "sysy.y"
    {
        auto comp_unit = manager.create_CompUnitAST();
        auto func_def = (yyvsp[(1) - (1)].astPointer);
        comp_unit->func_def_list.push_back(func_def);
        (yyval.astPointer) = comp_unit;
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 71 "sysy.y"
    {
        auto comp_unit = manager.create_CompUnitAST();
        auto decl = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        comp_unit->decl_list.push_back(decl);
        (yyval.astPointer) = comp_unit;
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 79 "sysy.y"
    {
        auto comp_unit = (CompUnitAST*)((yyvsp[(1) - (2)].astPointer));
        auto func_def = (BaseAST*)((yyvsp[(2) - (2)].astPointer));
        comp_unit->func_def_list.push_back(func_def);
        (yyval.astPointer) = comp_unit;
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 87 "sysy.y"
    {
        auto comp_unit = (CompUnitAST*)((yyvsp[(1) - (2)].astPointer));
        auto decl = (BaseAST*)((yyvsp[(2) - (2)].astPointer));
        comp_unit->decl_list.push_back(decl);
        (yyval.astPointer) = comp_unit;
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 97 "sysy.y"
    {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[(1) - (5)].stringPointer));
        delete (yyvsp[(1) - (5)].stringPointer);
        func_def->ident = *((yyvsp[(2) - (5)].stringPointer));
        delete (yyvsp[(2) - (5)].stringPointer);
        func_def->block = (BaseAST*)((yyvsp[(5) - (5)].astPointer));
        (yyval.astPointer) = func_def;
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 108 "sysy.y"
    {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[(1) - (6)].stringPointer));
        delete (yyvsp[(1) - (6)].stringPointer);
        func_def->ident = *((yyvsp[(2) - (6)].stringPointer));
        delete (yyvsp[(2) - (6)].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[(4) - (6)].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            func_def->params.push_back(*it);
        func_def->block = (BaseAST*)((yyvsp[(6) - (6)].astPointer));
        ((BlockAST*)(func_def->block))->func = func_def->ident;
        (yyval.astPointer) = func_def;
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 123 "sysy.y"
    {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[(1) - (5)].stringPointer));
        delete (yyvsp[(1) - (5)].stringPointer);
        func_def->ident = *((yyvsp[(2) - (5)].stringPointer));
        delete (yyvsp[(2) - (5)].stringPointer);
        func_def->block = (BaseAST*)((yyvsp[(5) - (5)].astPointer));
        (yyval.astPointer) = func_def;
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 134 "sysy.y"
    {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[(1) - (6)].stringPointer));
        delete (yyvsp[(1) - (6)].stringPointer);
        func_def->ident = *((yyvsp[(2) - (6)].stringPointer));
        delete (yyvsp[(2) - (6)].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[(4) - (6)].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            func_def->params.push_back(*it);
        func_def->block = (BaseAST*)((yyvsp[(6) - (6)].astPointer));
        ((BlockAST*)(func_def->block))->func = func_def->ident;
        (yyval.astPointer) = func_def;
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 152 "sysy.y"
    {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[(1) - (1)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 159 "sysy.y"
    {
        vector<BaseAST*> *v = ((yyvsp[(1) - (3)].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[(3) - (3)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 168 "sysy.y"
    {
        auto param = manager.create_FuncFParamAST();
        param->b_type = *((yyvsp[(1) - (2)].stringPointer));
        delete (yyvsp[(1) - (2)].stringPointer);
        param->ident = *((yyvsp[(2) - (2)].stringPointer));
        delete (yyvsp[(2) - (2)].stringPointer);
        (yyval.astPointer) = param;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 180 "sysy.y"
    {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[(1) - (1)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 187 "sysy.y"
    {
        vector<BaseAST*> *v = ((yyvsp[(1) - (3)].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[(3) - (3)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 196 "sysy.y"
    {
        auto block = manager.create_BlockAST();
        vector<BaseAST*> *v_ptr = ((yyvsp[(2) - (3)].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            block->block_item_list.push_back(*it);
        (yyval.astPointer) = block;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 207 "sysy.y"
    {
        auto stmt = ((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 213 "sysy.y"
    {
        auto stmt = ((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 223 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ret;
        stmt->block_exp = (BaseAST*)((yyvsp[(2) - (3)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 231 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ret;
        stmt->block_exp = nullptr;
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 239 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::lval;
        stmt->lval = *((yyvsp[(1) - (4)].stringPointer));
        delete (yyvsp[(1) - (4)].stringPointer);
        stmt->block_exp = (BaseAST*)((yyvsp[(3) - (4)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 249 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::block;
        stmt->block_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 257 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::exp;
        stmt->block_exp = (BaseAST*)((yyvsp[(1) - (2)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 265 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::exp;
        stmt->block_exp = nullptr;
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 273 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::break_;
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 280 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::continue_;
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 289 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ifelse;
        stmt->exp_simple = (BaseAST*)((yyvsp[(3) - (7)].astPointer));
        stmt->if_stmt = (BaseAST*)((yyvsp[(5) - (7)].astPointer));
        stmt->else_stmt = (BaseAST*)((yyvsp[(7) - (7)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 299 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::while_;
        stmt->exp_simple = (BaseAST*)((yyvsp[(3) - (5)].astPointer));
        stmt->while_stmt = (BaseAST*)((yyvsp[(5) - (5)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 310 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::if_;
        stmt->exp_simple = (BaseAST*)((yyvsp[(3) - (5)].astPointer));
        stmt->if_stmt = (BaseAST*)((yyvsp[(5) - (5)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 319 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ifelse;
        stmt->exp_simple = (BaseAST*)((yyvsp[(3) - (7)].astPointer));
        stmt->if_stmt = (BaseAST*)((yyvsp[(5) - (7)].astPointer));
        stmt->else_stmt = (BaseAST*)((yyvsp[(7) - (7)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 329 "sysy.y"
    {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::while_;
        stmt->exp_simple = (BaseAST*)((yyvsp[(3) - (5)].astPointer));
        stmt->while_stmt = (BaseAST*)((yyvsp[(5) - (5)].astPointer));
        (yyval.astPointer) = stmt;
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 341 "sysy.y"
    {
        auto exp = manager.create_ExpAST();
        exp->l_or_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = exp;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 350 "sysy.y"
    {
        auto l_or_exp = manager.create_LOrExpAST();
        l_or_exp->op = "";
        l_or_exp->l_and_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = l_or_exp;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 358 "sysy.y"
    {
        auto l_or_exp = manager.create_LOrExpAST();
        l_or_exp->l_or_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));

        l_or_exp->op = "||";
        l_or_exp->l_and_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = l_or_exp;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 370 "sysy.y"
    {
        auto l_and_exp = manager.create_LAndExpAST();
        l_and_exp->op = "";
        l_and_exp->eq_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = l_and_exp;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 378 "sysy.y"
    {
        auto l_and_exp = manager.create_LAndExpAST();
        l_and_exp->l_and_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        l_and_exp->op = "&&";
        l_and_exp->eq_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = l_and_exp;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 389 "sysy.y"
    {
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->op = "";
        eq_exp->rel_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = eq_exp;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 397 "sysy.y"
    {
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->eq_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        eq_exp->op = "==";
        eq_exp->rel_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = eq_exp;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 406 "sysy.y"
    {
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->eq_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        eq_exp->op = "!=";
        eq_exp->rel_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = eq_exp;
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 417 "sysy.y"
    {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->op = "";
        rel_exp->add_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = rel_exp;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 425 "sysy.y"
    {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        rel_exp->op = "<=";
        rel_exp->add_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = rel_exp;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 434 "sysy.y"
    {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        rel_exp->op = ">=";
        rel_exp->add_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = rel_exp;
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 443 "sysy.y"
    {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        rel_exp->op = "<";
        rel_exp->add_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = rel_exp;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 452 "sysy.y"
    {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        rel_exp->op = ">";
        rel_exp->add_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = rel_exp;
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 463 "sysy.y"
    {
        auto add_exp = manager.create_AddExpAST();
        add_exp->op = "";
        add_exp->mul_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = add_exp;
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 471 "sysy.y"
    {
        auto add_exp = manager.create_AddExpAST();
        add_exp->add_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        add_exp->op = "+";
        add_exp->mul_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = add_exp;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 480 "sysy.y"
    {
        auto add_exp = manager.create_AddExpAST();
        add_exp->add_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        add_exp->op = "-";
        add_exp->mul_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = add_exp;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 491 "sysy.y"
    {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->op = "";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = mul_exp;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 499 "sysy.y"
    {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        mul_exp->op = "*";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = mul_exp;
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 508 "sysy.y"
    {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        mul_exp->op = "/";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = mul_exp;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 517 "sysy.y"
    {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)((yyvsp[(1) - (3)].astPointer));
        mul_exp->op = "%";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = mul_exp;
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 528 "sysy.y"
    {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::primary;
        unary_exp->exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = unary_exp;
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 536 "sysy.y"
    {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::unary;
        unary_exp->op = *((yyvsp[(1) - (2)].stringPointer));
        delete (yyvsp[(1) - (2)].stringPointer);
        unary_exp->exp = (BaseAST*)((yyvsp[(2) - (2)].astPointer));
        (yyval.astPointer) = unary_exp;
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 546 "sysy.y"
    {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::func_call;
        unary_exp->ident = *((yyvsp[(1) - (3)].stringPointer));
        delete (yyvsp[(1) - (3)].stringPointer);
        (yyval.astPointer) = unary_exp;
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 555 "sysy.y"
    {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::func_call;
        unary_exp->ident = *((yyvsp[(1) - (4)].stringPointer));
        delete (yyvsp[(1) - (4)].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[(3) - (4)].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            unary_exp->params.push_back(*it);
        (yyval.astPointer) = unary_exp;
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 569 "sysy.y"
    {
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::exp;
        primary_exp->exp = (BaseAST*)((yyvsp[(2) - (3)].astPointer));
        (yyval.astPointer) = primary_exp;
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 577 "sysy.y"
    {
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::number;
        primary_exp->number = ((yyvsp[(1) - (1)].integer32));
        (yyval.astPointer) = primary_exp;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 585 "sysy.y"
    {
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::lval;
        primary_exp->lval = *((yyvsp[(1) - (1)].stringPointer));
        delete (yyvsp[(1) - (1)].stringPointer);
        (yyval.astPointer) = primary_exp;
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 596 "sysy.y"
    {
        auto decl = manager.create_DeclAST();
        decl->type = "const_decl";
        decl->decl = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = decl;
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 604 "sysy.y"
    {
        auto decl = manager.create_DeclAST();
        decl->type = "var_decl";
        decl->decl = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = decl;
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 614 "sysy.y"
    {
        auto const_decl = manager.create_ConstDeclAST();
        const_decl->b_type = *((yyvsp[(2) - (4)].stringPointer));
        delete (yyvsp[(2) - (4)].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[(3) - (4)].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            const_decl->const_def_list.push_back(*it);
        (yyval.astPointer) = const_decl;
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 627 "sysy.y"
    {
        auto const_def = manager.create_ConstDefAST();
        const_def->ident = *((yyvsp[(1) - (3)].stringPointer));
        delete (yyvsp[(1) - (3)].stringPointer);
        const_def->const_init_val = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = const_def;
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 638 "sysy.y"
    {
        auto const_init_val = manager.create_ConstInitValAST();
        const_init_val->const_exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = const_init_val;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 647 "sysy.y"
    {
        auto block_item = manager.create_BlockItemAST();
        block_item->type = BlockItemType::decl;
        block_item->content = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = block_item;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 655 "sysy.y"
    {
        auto block_item = manager.create_BlockItemAST();
        block_item->type = BlockItemType::stmt;
        block_item->content = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = block_item;
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 665 "sysy.y"
    {
        auto const_exp = manager.create_ConstExpAST();
        const_exp->exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = const_exp;
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 674 "sysy.y"
    {
        auto var_decl = manager.create_VarDeclAST();
        var_decl->b_type = *((yyvsp[(1) - (3)].stringPointer));
        delete (yyvsp[(1) - (3)].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[(2) - (3)].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            var_decl->var_def_list.push_back(*it);
        (yyval.astPointer) = var_decl;
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 687 "sysy.y"
    {
        auto var_def = manager.create_VarDefAST();
        var_def->ident = *((yyvsp[(1) - (1)].stringPointer));
        delete (yyvsp[(1) - (1)].stringPointer);
        var_def->has_init_val = false;
        (yyval.astPointer) = var_def;
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 696 "sysy.y"
    {
        auto var_def = manager.create_VarDefAST();
        var_def->ident = *((yyvsp[(1) - (3)].stringPointer));
        delete (yyvsp[(1) - (3)].stringPointer);
        var_def->has_init_val = true;
        var_def->init_val = (BaseAST*)((yyvsp[(3) - (3)].astPointer));
        (yyval.astPointer) = var_def;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 708 "sysy.y"
    {
        auto init_val = manager.create_InitValAST();
        init_val->exp = (BaseAST*)((yyvsp[(1) - (1)].astPointer));
        (yyval.astPointer) = init_val;
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 717 "sysy.y"
    {
        vector<BaseAST*> *v = manager.create_vector();
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 723 "sysy.y"
    {
        vector<BaseAST*> *v = ((yyvsp[(1) - (2)].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[(2) - (2)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 732 "sysy.y"
    {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[(1) - (1)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 739 "sysy.y"
    {
        vector<BaseAST*> *v = ((yyvsp[(1) - (3)].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[(3) - (3)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 748 "sysy.y"
    {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[(1) - (1)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 755 "sysy.y"
    {
        vector<BaseAST*> *v = ((yyvsp[(1) - (3)].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[(3) - (3)].astPointer)));
        (yyval.vectorPointer) = v;
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 765 "sysy.y"
    {
        (yyval.integer32) = ((yyvsp[(1) - (1)].integer32));
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 772 "sysy.y"
    {
        string *lval = new string(*((yyvsp[(1) - (1)].stringPointer)));
        delete (yyvsp[(1) - (1)].stringPointer);
        (yyval.stringPointer) = lval;
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 781 "sysy.y"
    {
        string *type = new string("int");
        (yyval.stringPointer) = type;
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 792 "sysy.y"
    {
        string *type = new string("void");
        (yyval.stringPointer) = type;
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 800 "sysy.y"
    {
        string *op = new string("+");
        (yyval.stringPointer) = op;
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 806 "sysy.y"
    {
        string *op = new string("-");
        (yyval.stringPointer) = op;
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 812 "sysy.y"
    {
        string *op = new string("!");
        (yyval.stringPointer) = op;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2531 "sysy.tab.c"
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
      yyerror (manager, YY_("syntax error"));
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
	    yyerror (manager, yymsg);
	  }
	else
	  {
	    yyerror (manager, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
		      yytoken, &yylval, manager);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
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
		  yystos[yystate], yyvsp, manager);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (manager, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, manager);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, manager);
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



/* Line 1675 of yacc.c  */
#line 824 "sysy.y"


void yyerror(NodesManager &manager, const char *s)
{
    extern int yylineno;
    extern char *yytext;
    cerr << "ERROR: " << s << " at symbol '" << yytext << "' on line " << yylineno << endl;
}
