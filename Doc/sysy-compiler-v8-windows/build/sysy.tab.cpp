/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 16 "/root/compiler/src/sysy.y"

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

#line 86 "/root/compiler/build/sysy.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ROOT_COMPILER_BUILD_SYSY_TAB_HPP_INCLUDED
# define YY_YY_ROOT_COMPILER_BUILD_SYSY_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "/root/compiler/src/sysy.y"

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

#line 143 "/root/compiler/build/sysy.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "/root/compiler/src/sysy.y"

    string *stringPointer;
    int integer32;
    BaseAST *astPointer;
    vector<BaseAST *> *vectorPointer;

#line 181 "/root/compiler/build/sysy.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (NodesManager &manager);

#endif /* !YY_YY_ROOT_COMPILER_BUILD_SYSY_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "UNARYOP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    44,   123,   125,    59,    61,    60,    62,    43,
      45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,   135,   118,    81,  -125,   -25,    11,   -80,
    -124,   -24,  -125,    80,    85,    57,    39,    54,   -13,  -125,
      -4,  -125,   123,  -125,  -125,  -125,  -125,   125,  -125,  -125,
    -125,  -125,  -125,   -82,     2,  -125,  -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    32,    33,    89,   113,   114,   115,
     116,   117,    42,    43,    44,    45,    46,    47,    48,    49,
       7,     8,    21,    59,   119,    60,     9,    17,    50,    85,
      22,    18,    51,    52,    34,    11,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (manager, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, manager); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, NodesManager &manager)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (manager);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, NodesManager &manager)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, manager);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, NodesManager &manager)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , manager);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, manager); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, NodesManager &manager)
{
  YYUSE (yyvaluep);
  YYUSE (manager);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (NodesManager &manager)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 56 "/root/compiler/src/sysy.y"
        {
        manager.root = (BaseAST*)((yyvsp[0].astPointer));
    }
#line 1463 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 3:
#line 63 "/root/compiler/src/sysy.y"
        {
        auto comp_unit = manager.create_CompUnitAST();
        auto func_def = (yyvsp[0].astPointer);
        comp_unit->func_def_list.push_back(func_def);
        (yyval.astPointer) = comp_unit;
    }
#line 1474 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 4:
#line 71 "/root/compiler/src/sysy.y"
        {
        auto comp_unit = manager.create_CompUnitAST();
        auto decl = (BaseAST*)((yyvsp[0].astPointer));
        comp_unit->decl_list.push_back(decl);
        (yyval.astPointer) = comp_unit;
    }
#line 1485 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 5:
#line 79 "/root/compiler/src/sysy.y"
        {
        auto comp_unit = (CompUnitAST*)((yyvsp[-1].astPointer));
        auto func_def = (BaseAST*)((yyvsp[0].astPointer));
        comp_unit->func_def_list.push_back(func_def);
        (yyval.astPointer) = comp_unit;
    }
#line 1496 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 6:
#line 87 "/root/compiler/src/sysy.y"
        {
        auto comp_unit = (CompUnitAST*)((yyvsp[-1].astPointer));
        auto decl = (BaseAST*)((yyvsp[0].astPointer));
        comp_unit->decl_list.push_back(decl);
        (yyval.astPointer) = comp_unit;
    }
#line 1507 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 7:
#line 97 "/root/compiler/src/sysy.y"
        {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[-4].stringPointer));
        delete (yyvsp[-4].stringPointer);
        func_def->ident = *((yyvsp[-3].stringPointer));
        delete (yyvsp[-3].stringPointer);
        func_def->block = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = func_def;
    }
#line 1521 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 8:
#line 108 "/root/compiler/src/sysy.y"
        {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[-5].stringPointer));
        delete (yyvsp[-5].stringPointer);
        func_def->ident = *((yyvsp[-4].stringPointer));
        delete (yyvsp[-4].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[-2].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            func_def->params.push_back(*it);
        func_def->block = (BaseAST*)((yyvsp[0].astPointer));
        ((BlockAST*)(func_def->block))->func = func_def->ident;
        (yyval.astPointer) = func_def;
    }
#line 1539 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 9:
#line 123 "/root/compiler/src/sysy.y"
        {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[-4].stringPointer));
        delete (yyvsp[-4].stringPointer);
        func_def->ident = *((yyvsp[-3].stringPointer));
        delete (yyvsp[-3].stringPointer);
        func_def->block = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = func_def;
    }
#line 1553 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 10:
#line 134 "/root/compiler/src/sysy.y"
        {
        auto func_def = manager.create_FuncDefAST();
        func_def->func_type = *((yyvsp[-5].stringPointer));
        delete (yyvsp[-5].stringPointer);
        func_def->ident = *((yyvsp[-4].stringPointer));
        delete (yyvsp[-4].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[-2].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            func_def->params.push_back(*it);
        func_def->block = (BaseAST*)((yyvsp[0].astPointer));
        ((BlockAST*)(func_def->block))->func = func_def->ident;
        (yyval.astPointer) = func_def;
    }
#line 1571 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 11:
#line 152 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 1581 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 12:
#line 159 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = ((yyvsp[-2].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 1591 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 13:
#line 168 "/root/compiler/src/sysy.y"
        {
        auto param = manager.create_FuncFParamAST();
        param->b_type = *((yyvsp[-1].stringPointer));
        delete (yyvsp[-1].stringPointer);
        param->ident = *((yyvsp[0].stringPointer));
        delete (yyvsp[0].stringPointer);
        (yyval.astPointer) = param;
    }
#line 1604 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 14:
#line 180 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 1614 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 15:
#line 187 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = ((yyvsp[-2].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 1624 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 16:
#line 196 "/root/compiler/src/sysy.y"
        {
        auto block = manager.create_BlockAST();
        vector<BaseAST*> *v_ptr = ((yyvsp[-1].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            block->block_item_list.push_back(*it);
        (yyval.astPointer) = block;
    }
#line 1636 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 17:
#line 207 "/root/compiler/src/sysy.y"
        {
        auto stmt = ((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1645 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 18:
#line 213 "/root/compiler/src/sysy.y"
        {
        auto stmt = ((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1654 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 19:
#line 223 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ret;
        stmt->block_exp = (BaseAST*)((yyvsp[-1].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1665 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 20:
#line 231 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ret;
        stmt->block_exp = nullptr;
        (yyval.astPointer) = stmt;
    }
#line 1676 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 21:
#line 239 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::lval;
        stmt->lval = *((yyvsp[-3].stringPointer));
        delete (yyvsp[-3].stringPointer);
        stmt->block_exp = (BaseAST*)((yyvsp[-1].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1689 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 22:
#line 249 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::block;
        stmt->block_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1700 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 23:
#line 257 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::exp;
        stmt->block_exp = (BaseAST*)((yyvsp[-1].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1711 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 24:
#line 265 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::exp;
        stmt->block_exp = nullptr;
        (yyval.astPointer) = stmt;
    }
#line 1722 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 25:
#line 273 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::break_;
        (yyval.astPointer) = stmt;
    }
#line 1732 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 26:
#line 280 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::continue_;
        (yyval.astPointer) = stmt;
    }
#line 1742 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 27:
#line 289 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ifelse;
        stmt->exp_simple = (BaseAST*)((yyvsp[-4].astPointer));
        stmt->if_stmt = (BaseAST*)((yyvsp[-2].astPointer));
        stmt->else_stmt = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1755 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 28:
#line 299 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::while_;
        stmt->exp_simple = (BaseAST*)((yyvsp[-2].astPointer));
        stmt->while_stmt = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1767 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 29:
#line 310 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::if_;
        stmt->exp_simple = (BaseAST*)((yyvsp[-2].astPointer));
        stmt->if_stmt = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1779 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 30:
#line 319 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::ifelse;
        stmt->exp_simple = (BaseAST*)((yyvsp[-4].astPointer));
        stmt->if_stmt = (BaseAST*)((yyvsp[-2].astPointer));
        stmt->else_stmt = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1792 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 31:
#line 329 "/root/compiler/src/sysy.y"
        {
        auto stmt = manager.create_StmtAST();
        stmt->type = StmtType::while_;
        stmt->exp_simple = (BaseAST*)((yyvsp[-2].astPointer));
        stmt->while_stmt = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = stmt;
    }
#line 1804 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 32:
#line 341 "/root/compiler/src/sysy.y"
        {
        auto exp = manager.create_ExpAST();
        exp->l_or_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = exp;
    }
#line 1814 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 33:
#line 350 "/root/compiler/src/sysy.y"
        {
        auto l_or_exp = manager.create_LOrExpAST();
        l_or_exp->op = "";
        l_or_exp->l_and_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = l_or_exp;
    }
#line 1825 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 34:
#line 358 "/root/compiler/src/sysy.y"
        {
        auto l_or_exp = manager.create_LOrExpAST();
        l_or_exp->l_or_exp = (BaseAST*)((yyvsp[-2].astPointer));

        l_or_exp->op = "||";
        l_or_exp->l_and_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = l_or_exp;
    }
#line 1838 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 35:
#line 370 "/root/compiler/src/sysy.y"
        {
        auto l_and_exp = manager.create_LAndExpAST();
        l_and_exp->op = "";
        l_and_exp->eq_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = l_and_exp;
    }
#line 1849 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 36:
#line 378 "/root/compiler/src/sysy.y"
        {
        auto l_and_exp = manager.create_LAndExpAST();
        l_and_exp->l_and_exp = (BaseAST*)((yyvsp[-2].astPointer));
        l_and_exp->op = "&&";
        l_and_exp->eq_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = l_and_exp;
    }
#line 1861 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 37:
#line 389 "/root/compiler/src/sysy.y"
        {
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->op = "";
        eq_exp->rel_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = eq_exp;
    }
#line 1872 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 38:
#line 397 "/root/compiler/src/sysy.y"
        {
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->eq_exp = (BaseAST*)((yyvsp[-2].astPointer));
        eq_exp->op = "==";
        eq_exp->rel_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = eq_exp;
    }
#line 1884 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 39:
#line 406 "/root/compiler/src/sysy.y"
        {
        auto eq_exp = manager.create_EqExpAST();
        eq_exp->eq_exp = (BaseAST*)((yyvsp[-2].astPointer));
        eq_exp->op = "!=";
        eq_exp->rel_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = eq_exp;
    }
#line 1896 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 40:
#line 417 "/root/compiler/src/sysy.y"
        {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->op = "";
        rel_exp->add_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = rel_exp;
    }
#line 1907 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 41:
#line 425 "/root/compiler/src/sysy.y"
        {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[-2].astPointer));
        rel_exp->op = "<=";
        rel_exp->add_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = rel_exp;
    }
#line 1919 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 42:
#line 434 "/root/compiler/src/sysy.y"
        {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[-2].astPointer));
        rel_exp->op = ">=";
        rel_exp->add_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = rel_exp;
    }
#line 1931 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 43:
#line 443 "/root/compiler/src/sysy.y"
        {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[-2].astPointer));
        rel_exp->op = "<";
        rel_exp->add_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = rel_exp;
    }
#line 1943 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 44:
#line 452 "/root/compiler/src/sysy.y"
        {
        auto rel_exp = manager.create_RelExpAST();
        rel_exp->rel_exp = (BaseAST*)((yyvsp[-2].astPointer));
        rel_exp->op = ">";
        rel_exp->add_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = rel_exp;
    }
#line 1955 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 45:
#line 463 "/root/compiler/src/sysy.y"
        {
        auto add_exp = manager.create_AddExpAST();
        add_exp->op = "";
        add_exp->mul_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = add_exp;
    }
#line 1966 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 46:
#line 471 "/root/compiler/src/sysy.y"
        {
        auto add_exp = manager.create_AddExpAST();
        add_exp->add_exp = (BaseAST*)((yyvsp[-2].astPointer));
        add_exp->op = "+";
        add_exp->mul_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = add_exp;
    }
#line 1978 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 47:
#line 480 "/root/compiler/src/sysy.y"
        {
        auto add_exp = manager.create_AddExpAST();
        add_exp->add_exp = (BaseAST*)((yyvsp[-2].astPointer));
        add_exp->op = "-";
        add_exp->mul_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = add_exp;
    }
#line 1990 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 48:
#line 491 "/root/compiler/src/sysy.y"
        {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->op = "";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = mul_exp;
    }
#line 2001 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 49:
#line 499 "/root/compiler/src/sysy.y"
        {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)((yyvsp[-2].astPointer));
        mul_exp->op = "*";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = mul_exp;
    }
#line 2013 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 50:
#line 508 "/root/compiler/src/sysy.y"
        {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)((yyvsp[-2].astPointer));
        mul_exp->op = "/";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = mul_exp;
    }
#line 2025 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 51:
#line 517 "/root/compiler/src/sysy.y"
        {
        auto mul_exp = manager.create_MulExpAST();
        mul_exp->mul_exp = (BaseAST*)((yyvsp[-2].astPointer));
        mul_exp->op = "%";
        mul_exp->unary_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = mul_exp;
    }
#line 2037 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 52:
#line 528 "/root/compiler/src/sysy.y"
        {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::primary;
        unary_exp->exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = unary_exp;
    }
#line 2048 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 53:
#line 536 "/root/compiler/src/sysy.y"
        {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::unary;
        unary_exp->op = *((yyvsp[-1].stringPointer));
        delete (yyvsp[-1].stringPointer);
        unary_exp->exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = unary_exp;
    }
#line 2061 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 54:
#line 546 "/root/compiler/src/sysy.y"
        {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::func_call;
        unary_exp->ident = *((yyvsp[-2].stringPointer));
        delete (yyvsp[-2].stringPointer);
        (yyval.astPointer) = unary_exp;
    }
#line 2073 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 55:
#line 555 "/root/compiler/src/sysy.y"
        {
        auto unary_exp = manager.create_UnaryExpAST();
        unary_exp->type = UnaryExpType::func_call;
        unary_exp->ident = *((yyvsp[-3].stringPointer));
        delete (yyvsp[-3].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[-1].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            unary_exp->params.push_back(*it);
        (yyval.astPointer) = unary_exp;
    }
#line 2088 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 56:
#line 569 "/root/compiler/src/sysy.y"
        {
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::exp;
        primary_exp->exp = (BaseAST*)((yyvsp[-1].astPointer));
        (yyval.astPointer) = primary_exp;
    }
#line 2099 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 57:
#line 577 "/root/compiler/src/sysy.y"
        {
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::number;
        primary_exp->number = ((yyvsp[0].integer32));
        (yyval.astPointer) = primary_exp;
    }
#line 2110 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 58:
#line 585 "/root/compiler/src/sysy.y"
        {
        auto primary_exp = manager.create_PrimaryExpAST();
        primary_exp->type = PrimaryExpType::lval;
        primary_exp->lval = *((yyvsp[0].stringPointer));
        delete (yyvsp[0].stringPointer);
        (yyval.astPointer) = primary_exp;
    }
#line 2122 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 59:
#line 596 "/root/compiler/src/sysy.y"
        {
        auto decl = manager.create_DeclAST();
        decl->type = DeclType::const_decl;
        decl->decl = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = decl;
    }
#line 2133 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 60:
#line 604 "/root/compiler/src/sysy.y"
        {
        auto decl = manager.create_DeclAST();
        decl->type = DeclType::var_decl;
        decl->decl = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = decl;
    }
#line 2144 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 61:
#line 614 "/root/compiler/src/sysy.y"
        {
        auto const_decl = manager.create_ConstDeclAST();
        const_decl->b_type = *((yyvsp[-2].stringPointer));
        delete (yyvsp[-2].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[-1].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            const_decl->const_def_list.push_back(*it);
        (yyval.astPointer) = const_decl;
    }
#line 2158 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 62:
#line 627 "/root/compiler/src/sysy.y"
        {
        auto const_def = manager.create_ConstDefAST();
        const_def->ident = *((yyvsp[-2].stringPointer));
        delete (yyvsp[-2].stringPointer);
        const_def->const_init_val = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = const_def;
    }
#line 2170 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 63:
#line 638 "/root/compiler/src/sysy.y"
        {
        auto const_init_val = manager.create_ConstInitValAST();
        const_init_val->const_exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = const_init_val;
    }
#line 2180 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 64:
#line 647 "/root/compiler/src/sysy.y"
        {
        auto block_item = manager.create_BlockItemAST();
        block_item->type = BlockItemType::decl;
        block_item->content = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = block_item;
    }
#line 2191 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 65:
#line 655 "/root/compiler/src/sysy.y"
        {
        auto block_item = manager.create_BlockItemAST();
        block_item->type = BlockItemType::stmt;
        block_item->content = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = block_item;
    }
#line 2202 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 66:
#line 665 "/root/compiler/src/sysy.y"
        {
        auto const_exp = manager.create_ConstExpAST();
        const_exp->exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = const_exp;
    }
#line 2212 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 67:
#line 674 "/root/compiler/src/sysy.y"
        {
        auto var_decl = manager.create_VarDeclAST();
        var_decl->b_type = *((yyvsp[-2].stringPointer));
        delete (yyvsp[-2].stringPointer);
        vector<BaseAST*> *v_ptr = ((yyvsp[-1].vectorPointer));
        for (auto it = v_ptr->begin(); it != v_ptr->end(); it++)
            var_decl->var_def_list.push_back(*it);
        (yyval.astPointer) = var_decl;
    }
#line 2226 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 68:
#line 687 "/root/compiler/src/sysy.y"
        {
        auto var_def = manager.create_VarDefAST();
        var_def->ident = *((yyvsp[0].stringPointer));
        delete (yyvsp[0].stringPointer);
        var_def->has_init_val = false;
        (yyval.astPointer) = var_def;
    }
#line 2238 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 69:
#line 696 "/root/compiler/src/sysy.y"
        {
        auto var_def = manager.create_VarDefAST();
        var_def->ident = *((yyvsp[-2].stringPointer));
        delete (yyvsp[-2].stringPointer);
        var_def->has_init_val = true;
        var_def->init_val = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = var_def;
    }
#line 2251 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 70:
#line 708 "/root/compiler/src/sysy.y"
        {
        auto init_val = manager.create_InitValAST();
        init_val->exp = (BaseAST*)((yyvsp[0].astPointer));
        (yyval.astPointer) = init_val;
    }
#line 2261 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 71:
#line 717 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = manager.create_vector();
        (yyval.vectorPointer) = v;
    }
#line 2270 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 72:
#line 723 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = ((yyvsp[-1].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 2280 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 73:
#line 732 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 2290 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 74:
#line 739 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = ((yyvsp[-2].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 2300 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 75:
#line 748 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = manager.create_vector();
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 2310 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 76:
#line 755 "/root/compiler/src/sysy.y"
        {
        vector<BaseAST*> *v = ((yyvsp[-2].vectorPointer));
        v->push_back((BaseAST*)((yyvsp[0].astPointer)));
        (yyval.vectorPointer) = v;
    }
#line 2320 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 77:
#line 765 "/root/compiler/src/sysy.y"
        {
        (yyval.integer32) = ((yyvsp[0].integer32));
    }
#line 2328 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 78:
#line 772 "/root/compiler/src/sysy.y"
        {
        string *lval = new string(*((yyvsp[0].stringPointer)));
        delete (yyvsp[0].stringPointer);
        (yyval.stringPointer) = lval;
    }
#line 2338 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 79:
#line 781 "/root/compiler/src/sysy.y"
        {
        string *type = new string("int");
        (yyval.stringPointer) = type;
    }
#line 2347 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 80:
#line 792 "/root/compiler/src/sysy.y"
        {
        string *type = new string("void");
        (yyval.stringPointer) = type;
    }
#line 2356 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 81:
#line 800 "/root/compiler/src/sysy.y"
        {
        string *op = new string("+");
        (yyval.stringPointer) = op;
    }
#line 2365 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 82:
#line 806 "/root/compiler/src/sysy.y"
        {
        string *op = new string("-");
        (yyval.stringPointer) = op;
    }
#line 2374 "/root/compiler/build/sysy.tab.cpp"
    break;

  case 83:
#line 812 "/root/compiler/src/sysy.y"
        {
        string *op = new string("!");
        (yyval.stringPointer) = op;
    }
#line 2383 "/root/compiler/build/sysy.tab.cpp"
    break;


#line 2387 "/root/compiler/build/sysy.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (manager, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (manager, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (manager, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, manager);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, manager);
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
  return yyresult;
}
#line 824 "/root/compiler/src/sysy.y"


void yyerror(NodesManager &manager, const char *s)

	{
    extern int yylineno;
    extern char *yytext;
    cerr << "ERROR: " << s << " at symbol '" << yytext << "' on line "
        << yylineno << endl;
}