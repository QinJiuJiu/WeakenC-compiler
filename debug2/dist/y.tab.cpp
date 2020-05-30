/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler.y" /* yacc.c:339  */


#include <cstdlib>

#include <cstdio>

#include <string>

#include<fstream>

#include "tree.h"

using namespace std;

extern char *yytext;

extern int column;

extern FILE * yyin;

extern FILE * yyout;

SyntaxTree *root;

extern int yylineno;

FILE * fp;

int yylex(void);

void yyerror(const char*); 


#line 100 "dist/y.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
#ifndef YY_YY_DIST_Y_TAB_HPP_INCLUDED
# define YY_YY_DIST_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    CONSTANT_INT = 262,
    CONSTANT_DOUBLE = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPE_NAME = 285,
    CHAR = 286,
    INT = 287,
    DOUBLE = 288,
    VOID = 289,
    BOOL = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    DO = 294,
    FOR = 295,
    CONTINUE = 296,
    BREAK = 297,
    RETURN = 298,
    TRUE = 299,
    FALSE = 300,
    LOWER_THAN_ELSE = 301
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define CONSTANT_INT 262
#define CONSTANT_DOUBLE 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define AND_OP 273
#define OR_OP 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define LEFT_ASSIGN 280
#define RIGHT_ASSIGN 281
#define AND_ASSIGN 282
#define XOR_ASSIGN 283
#define OR_ASSIGN 284
#define TYPE_NAME 285
#define CHAR 286
#define INT 287
#define DOUBLE 288
#define VOID 289
#define BOOL 290
#define IF 291
#define ELSE 292
#define WHILE 293
#define DO 294
#define FOR 295
#define CONTINUE 296
#define BREAK 297
#define RETURN 298
#define TRUE 299
#define FALSE 300
#define LOWER_THAN_ELSE 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "compiler.y" /* yacc.c:355  */


    struct SyntaxTree* gt;


#line 238 "dist/y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DIST_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "dist/y.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   664

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    60,    53,     2,
      68,    69,    58,    57,    47,    56,    52,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    46,
      61,    49,    62,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    64,    67,    55,     2,     2,     2,
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
      45,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   127,   143,   159,   171,   189,   202,   230,
     242,   258,   274,   290,   306,   334,   346,   374,   387,   403,
     419,   447,   459,   471,   483,   511,   523,   535,   547,   575,
     587,   599,   627,   639,   655,   687,   699,   711,   723,   739,
     771,   783,   799,   827,   839,   867,   879,   907,   919,   947,
     959,   991,  1003,  1035,  1051,  1079,  1091,  1107,  1123,  1139,
    1155,  1171,  1187,  1203,  1219,  1235,  1267,  1283,  1315,  1327,
    1355,  1367,  1391,  1403,  1435,  1447,  1459,  1471,  1483,  1515,
    1531,  1547,  1563,  1579,  1595,  1611,  1627,  1663,  1675,  1699,
    1711,  1723,  1747,  1759,  1783,  1795,  1807,  1819,  1831,  1843,
    1855,  1867,  1879,  1891,  1903,  1931,  1943,  1959,  1987,  1999,
    2011,  2023,  2047,  2071,  2083,  2107,  2119,  2147,  2159,  2171,
    2183,  2195,  2207,  2235,  2265,  2277,  2301,  2313,  2337,  2349,
    2373,  2385,  2413,  2425,  2457,  2469,  2481,  2493,  2505,  2517,
    2544,  2556,  2568,  2580,  2604,  2616,  2640,  2656,  2683,  2695,
    2719,  2731
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "CONSTANT_INT", "CONSTANT_DOUBLE", "PTR_OP",
  "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "CHAR", "INT", "DOUBLE", "VOID",
  "BOOL", "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK",
  "RETURN", "TRUE", "FALSE", "';'", "','", "':'", "'='", "'['", "']'",
  "'.'", "'&'", "'!'", "'~'", "'-'", "'+'", "'*'", "'/'", "'%'", "'<'",
  "'>'", "'^'", "'|'", "'?'", "'{'", "'}'", "'('", "')'",
  "LOWER_THAN_ELSE", "$accept", "Program", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "assignment_operator", "expression",
  "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "parameter_list",
  "parameter_declaration", "identifier_list", "abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    44,    58,    61,
      91,    93,    46,    38,    33,   126,    45,    43,    42,    47,
      37,    60,    62,    94,   124,    63,   123,   125,    40,    41,
     301
};
# endif

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     172,  -143,  -143,  -143,  -143,  -143,    22,  -143,     5,   172,
    -143,  -143,  -143,  -143,  -143,     7,   146,  -143,   387,  -143,
      78,  -143,     7,   571,   485,   209,    73,  -143,     5,  -143,
     119,  -143,  -143,   218,  -143,  -143,  -143,   596,   596,  -143,
    -143,  -143,  -143,  -143,  -143,   423,   596,  -143,    48,   269,
     596,   155,   142,   257,     3,   255,   -28,   -44,   -33,    15,
      31,  -143,  -143,  -143,     4,    12,    13,    18,    24,   333,
      41,    67,    72,   277,  -143,  -143,  -143,   253,  -143,  -143,
    -143,  -143,   271,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
      17,   -41,  -143,     1,  -143,  -143,  -143,  -143,   596,   117,
    -143,   -15,   571,   112,  -143,    19,  -143,  -143,   596,    27,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,   596,  -143,   596,   596,   596,   596,   596,   596,   596,
     596,   596,   596,   596,   596,   596,   596,   596,   596,   596,
     596,  -143,  -143,   333,   596,   596,    85,   349,  -143,  -143,
    -143,   273,  -143,   596,  -143,  -143,   500,    10,   -21,    62,
     172,  -143,   123,  -143,  -143,    -5,  -143,   404,  -143,  -143,
    -143,  -143,  -143,   116,  -143,    50,  -143,  -143,  -143,  -143,
    -143,   155,   155,   142,   142,   257,   257,   257,   257,     3,
       3,   255,   -28,   -44,   -33,    15,  -143,    96,    97,    61,
     577,   577,  -143,  -143,  -143,    81,   122,  -143,   125,   189,
     515,   106,  -143,  -143,  -143,  -143,  -143,   571,  -143,   596,
    -143,   333,   333,   596,    46,   114,  -143,  -143,  -143,  -143,
    -143,   157,   159,  -143,   131,  -143,  -143,   181,  -143,   132,
     333,   133,   333,   140,  -143,  -143,  -143,   333,   103,  -143,
     333,  -143,   333,  -143,  -143,  -143,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    75,    76,    77,    74,    78,     0,   147,     0,     2,
     144,   146,     1,    79,    68,     0,     0,    70,    72,   145,
       0,    69,     0,     0,     0,     0,     0,   150,     0,   149,
       0,    80,    71,    72,     3,     6,     7,     0,     0,     4,
       5,    24,    23,    22,    21,     0,     0,     9,    17,    25,
       0,    29,    32,    35,    40,    43,    45,    47,    49,    51,
      53,   105,    73,    83,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,   130,   124,    66,     0,   128,   129,
     117,   118,     0,   126,   119,   120,   121,   122,    92,    86,
      91,     0,    87,     0,   151,   148,    18,    19,     0,     0,
     108,     0,     0,     0,   113,     0,    13,    14,     0,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      55,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    81,     0,     0,     0,     0,     0,   140,   141,
     142,     0,   131,     0,   125,   127,     0,     0,    89,    90,
       0,    84,     0,    85,    25,     0,   116,     0,   106,   109,
     112,   114,     8,     0,    11,     0,    15,    54,    26,    27,
      28,    31,    30,    33,    34,    38,    39,    36,    37,    41,
      42,    44,    46,    48,    50,    52,   123,     0,     0,     0,
       0,     0,   143,    67,    95,     0,     0,   101,     0,     0,
       0,     0,    88,    93,   115,   107,   110,     0,    10,     0,
      12,     0,     0,     0,     0,     0,    99,    96,   102,    94,
      97,     0,     0,   103,     0,   111,    16,   132,   134,     0,
       0,     0,     0,     0,   100,    98,   104,     0,     0,   138,
       0,   136,     0,   133,   135,   139,   137
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,  -143,    98,  -143,   203,   219,   129,
     215,   110,   136,   118,   144,   161,   210,   -22,  -143,   -34,
     -14,  -143,   302,     0,    -1,  -142,   175,  -143,   185,   -40,
    -143,   179,  -143,   248,   -66,  -143,     6,  -143,   272,  -107,
    -143,  -143,  -143,  -143,   344,  -143,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    47,    48,   175,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    76,   121,    77,
       7,    16,    17,    28,    20,    91,    92,    93,   159,    62,
     101,   102,   103,   104,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     9,    10,    11,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
       8,    61,    65,   146,    27,   100,   160,    18,    13,     8,
      13,    78,   105,    13,   140,   208,    94,   130,   131,   137,
      13,    33,    12,    61,    29,   136,    90,    33,   161,    24,
      34,   138,   167,   139,    35,    36,    95,    37,    38,   151,
     201,     1,     2,     3,     4,     5,   214,    26,   162,    34,
     140,    14,   168,    35,    36,   141,    37,    38,   106,   107,
     156,   143,   169,   142,   132,   133,   153,   156,    78,   234,
     163,    39,    40,    15,   173,    15,    88,   196,   157,   207,
      61,    41,    42,    43,    44,   157,   144,   176,   172,   158,
      39,    40,   145,   224,   225,    46,   174,   219,   108,   177,
      41,    42,    43,    44,     1,     2,     3,     4,     5,   147,
     197,   198,   210,   148,    46,   240,   109,    34,   149,   220,
     166,    35,    36,   199,    37,    38,   213,   216,    24,   223,
     211,   203,   226,   200,   206,    96,    97,     1,     2,     3,
       4,     5,    89,   153,   153,    61,    26,    31,   122,   254,
       1,     2,     3,     4,     5,   237,   238,    90,    39,    40,
      90,   170,    98,   153,    99,   221,   222,   218,    41,    42,
      43,    44,   160,   227,   249,   233,   251,   235,   160,   153,
     153,   253,    46,   242,   255,    25,   256,   153,   232,   239,
     241,   243,    21,    22,   228,    61,   164,   236,   126,   127,
     246,   248,   250,     1,     2,     3,     4,     5,   244,   252,
     245,    90,    66,   123,   124,   125,    35,    36,   247,    37,
      38,   178,   179,   180,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   210,
       1,     2,     3,     4,     5,    67,   191,    68,    69,    70,
      71,    72,    73,    39,    40,    74,   193,   211,   229,   185,
     186,   187,   188,    41,    42,    43,    44,    23,    24,   128,
     129,   134,   135,   192,    66,    25,    75,    46,    35,    36,
      34,    37,    38,   194,    35,    36,    26,    37,    38,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   152,
     153,   195,     1,     2,     3,     4,     5,    67,   165,    68,
      69,    70,    71,    72,    73,    39,    40,    74,   120,   202,
     153,    39,    40,   150,    32,    41,    42,    43,    44,   181,
     182,    41,    42,    43,    44,   212,    66,    25,   154,    46,
      35,    36,   209,    37,    38,    46,   217,   183,   184,   189,
     190,   171,    34,    19,   155,     0,    35,    36,     0,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    68,    69,    70,    71,    72,    73,    39,    40,    74,
       1,     2,     3,     4,     5,     0,     0,    41,    42,    43,
      44,     0,     0,    39,    40,    74,     0,     0,     0,    25,
       0,    46,     0,    41,    42,    43,    44,    34,     0,     0,
       0,    35,    36,     0,    37,    38,     0,    46,     1,     2,
       3,     4,     5,     0,     0,     0,    34,     0,     0,     0,
      35,    36,     0,    37,    38,     0,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,     0,    25,    98,    26,    99,     0,    41,    42,
      43,    44,     0,     0,     0,     0,     0,    39,    40,     0,
      45,   215,    46,    98,     0,    99,     0,    41,    42,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    34,    45,
       0,    46,    35,    36,     0,    37,    38,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,    35,    36,     0,
      37,    38,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,    35,    36,     0,    37,    38,     0,     0,    39,
      40,     0,     0,     0,     0,     0,    63,     0,     0,    41,
      42,    43,    44,    64,    39,    40,     0,     0,     0,     0,
       0,   204,     0,    46,    41,    42,    43,    44,   205,    39,
      40,     0,     0,     0,     0,     0,   230,     0,    46,    41,
      42,    43,    44,   231,    34,     0,     0,     0,    35,    36,
      34,    37,    38,    46,    35,    36,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,    35,    36,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,    39,    40,     0,     0,     0,
       0,    39,    40,    74,     0,    41,    42,    43,    44,     0,
       0,    41,    42,    43,    44,     0,     0,    45,     0,    46,
      39,    40,     0,     0,     0,    46,     0,     0,     0,     0,
      41,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46
};

static const yytype_int16 yycheck[] =
{
       0,    23,    24,    69,    18,    45,    47,     8,     3,     9,
       3,    25,    46,     3,    19,   157,    30,    14,    15,    63,
       3,    22,     0,    45,    18,    53,    26,    28,    69,    50,
       3,    64,    47,    18,     7,     8,    30,    10,    11,    73,
     147,    31,    32,    33,    34,    35,    51,    68,    47,     3,
      19,    46,    67,     7,     8,    51,    10,    11,    10,    11,
      50,    48,   102,    51,    61,    62,    47,    50,    82,   211,
      69,    44,    45,    68,   108,    68,     3,   143,    68,    69,
     102,    54,    55,    56,    57,    68,    68,   109,    69,    90,
      44,    45,    68,   200,   201,    68,    69,    47,    50,   121,
      54,    55,    56,    57,    31,    32,    33,    34,    35,    68,
     144,   145,    50,    46,    68,    69,    68,     3,    46,    69,
       3,     7,     8,    38,    10,    11,     3,   167,    50,    68,
      68,   153,    51,   147,   156,    37,    38,    31,    32,    33,
      34,    35,    69,    47,    47,   167,    68,    69,    50,    46,
      31,    32,    33,    34,    35,   221,   222,   157,    44,    45,
     160,    49,    50,    47,    52,    69,    69,    51,    54,    55,
      56,    57,    47,    51,   240,    69,   242,   217,    47,    47,
      47,   247,    68,    69,   250,    66,   252,    47,   210,   223,
     224,   225,    46,    47,    69,   217,    98,   219,    56,    57,
      69,    69,    69,    31,    32,    33,    34,    35,    51,    69,
      51,   211,     3,    58,    59,    60,     7,     8,    37,    10,
      11,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    50,
      31,    32,    33,    34,    35,    36,   136,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   138,    68,    69,   130,
     131,   132,   133,    54,    55,    56,    57,    49,    50,    12,
      13,    16,    17,   137,     3,    66,    67,    68,     7,     8,
       3,    10,    11,   139,     7,     8,    68,    10,    11,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    46,
      47,   140,    31,    32,    33,    34,    35,    36,    98,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    49,    46,
      47,    44,    45,    46,    22,    54,    55,    56,    57,   126,
     127,    54,    55,    56,    57,   160,     3,    66,    67,    68,
       7,     8,   157,    10,    11,    68,   167,   128,   129,   134,
     135,   103,     3,     9,    82,    -1,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      31,    32,    33,    34,    35,    -1,    -1,    54,    55,    56,
      57,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    66,
      -1,    68,    -1,    54,    55,    56,    57,     3,    -1,    -1,
      -1,     7,     8,    -1,    10,    11,    -1,    68,    31,    32,
      33,    34,    35,    -1,    -1,    -1,     3,    -1,    -1,    -1,
       7,     8,    -1,    10,    11,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    66,    50,    68,    52,    -1,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      66,    67,    68,    50,    -1,    52,    -1,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    66,
      -1,    68,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,     7,     8,    -1,    10,    11,    -1,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      55,    56,    57,    58,    44,    45,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    68,    54,    55,    56,    57,    58,    44,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    68,    54,
      55,    56,    57,    58,     3,    -1,    -1,    -1,     7,     8,
       3,    10,    11,    68,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    54,    55,    56,    57,    -1,
      -1,    54,    55,    56,    57,    -1,    -1,    66,    -1,    68,
      44,    45,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    72,    91,    94,   114,
     115,   116,     0,     3,    46,    68,    92,    93,    95,   115,
      95,    46,    47,    49,    50,    66,    68,    91,    94,   107,
     117,    69,    93,    95,     3,     7,     8,    10,    11,    44,
      45,    54,    55,    56,    57,    66,    68,    73,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   100,    51,    58,    88,     3,    36,    38,    39,
      40,    41,    42,    43,    46,    67,    88,    90,    91,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     3,    69,
      94,    96,    97,    98,    91,   107,    76,    76,    50,    52,
     100,   101,   102,   103,   104,    90,    10,    11,    50,    68,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      49,    89,    76,    58,    59,    60,    56,    57,    12,    13,
      14,    15,    61,    62,    16,    17,    53,    63,    64,    18,
      19,    51,    51,    48,    68,    68,   105,    68,    46,    46,
      46,    90,    46,    47,    67,   109,    50,    68,    95,    99,
      47,    69,    47,    69,    76,    87,     3,    47,    67,   100,
      49,   104,    69,    90,    69,    75,    88,    88,    76,    76,
      76,    78,    78,    79,    79,    80,    80,    80,    80,    81,
      81,    82,    83,    84,    85,    86,   105,    90,    90,    38,
      91,   110,    46,    88,    51,    58,    88,    69,    96,    99,
      50,    68,    97,     3,    51,    67,   100,   102,    51,    47,
      69,    69,    69,    68,   110,   110,    51,    51,    69,    69,
      51,    58,    88,    69,    96,   100,    88,   105,   105,    90,
      69,    90,    69,    90,    51,    51,    69,    37,    69,   105,
      69,   105,    69,   105,    46,   105,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    77,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    81,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   102,   103,   103,   104,   104,   105,   105,   105,
     105,   105,   105,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     113,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     2,     2,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     4,     3,     4,     4,     3,     1,     3,     2,
       2,     1,     1,     3,     3,     2,     3,     3,     4,     3,
       4,     2,     3,     3,     4,     1,     3,     4,     1,     2,
       3,     4,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     1,     2,     1,     1,
       1,     2,     5,     7,     5,     7,     6,     7,     6,     7,
       2,     2,     2,     3,     1,     2,     1,     1,     4,     3,
       1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 99 "compiler.y" /* yacc.c:1646  */
    {



        root = create_tree("Program",1,(yyvsp[0].gt));



    }
#line 1624 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 127 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("primary_expression",1,(yyvsp[0].gt));



    }
#line 1638 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("primary_expression",1,(yyvsp[0].gt));



    }
#line 1652 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 159 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("primary_expression",1,(yyvsp[0].gt));



    }
#line 1666 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 171 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("primary_expression",1,(yyvsp[0].gt));



        



    }
#line 1686 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 189 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("primary_expression",1,(yyvsp[0].gt));




    }
#line 1701 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 202 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("primary_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1715 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 230 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",1,(yyvsp[0].gt));



    }
#line 1729 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 242 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



        //数组调用



    }
#line 1747 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 258 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



        //函数调用



    }
#line 1765 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 274 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



        //函数调用



    }
#line 1783 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 290 "compiler.y" /* yacc.c:1646  */
    {



        //++



        (yyval.gt) = create_tree("postfix_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1801 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 306 "compiler.y" /* yacc.c:1646  */
    {



        //--



        (yyval.gt) = create_tree("postfix_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1819 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 334 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("argument_expression_list",1,(yyvsp[0].gt));



    }
#line 1833 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 346 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("argument_expression_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1847 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 374 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("unary_expression",1,(yyvsp[0].gt));



    }
#line 1862 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 387 "compiler.y" /* yacc.c:1646  */
    {



        //++



        (yyval.gt) = create_tree("unary_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1880 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 403 "compiler.y" /* yacc.c:1646  */
    {



        //--



        (yyval.gt) = create_tree("unary_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1898 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 419 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("unary_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1912 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 447 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("unary_operator",1,(yyvsp[0].gt));



    }
#line 1926 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 459 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("unary_operator",1,(yyvsp[0].gt));



    }
#line 1940 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 471 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("unary_operator",1,(yyvsp[0].gt));



    }
#line 1954 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 483 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("unary_operator",1,(yyvsp[0].gt));



    }
#line 1968 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 511 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("multiplicative_expression",1,(yyvsp[0].gt));



    }
#line 1982 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 523 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("multiplicative_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1996 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 535 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("multiplicative_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2010 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 547 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("multiplicative_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2024 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 575 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("additive_expression",1,(yyvsp[0].gt));



    }
#line 2038 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 587 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("additive_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2052 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 599 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("additive_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2066 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 627 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("shift_expression",1,(yyvsp[0].gt));



    }
#line 2080 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 639 "compiler.y" /* yacc.c:1646  */
    {



        //<<



        (yyval.gt) = create_tree("shift_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2098 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 655 "compiler.y" /* yacc.c:1646  */
    {



        //<<



        (yyval.gt) = create_tree("shift_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2116 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 687 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("relational_expression",1,(yyvsp[0].gt));



    }
#line 2130 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 699 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("relational_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2144 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 711 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("relational_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2158 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 723 "compiler.y" /* yacc.c:1646  */
    {



        // <= 



        (yyval.gt) = create_tree("relational_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2176 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 739 "compiler.y" /* yacc.c:1646  */
    {



        // >=



        (yyval.gt) = create_tree("relational_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2194 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 771 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("equality_expression",1,(yyvsp[0].gt));



    }
#line 2208 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 783 "compiler.y" /* yacc.c:1646  */
    {



        // ==



        (yyval.gt) = create_tree("equality_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2226 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 799 "compiler.y" /* yacc.c:1646  */
    {



        // !=



        (yyval.gt) = create_tree("equality_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2244 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 827 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("and_expression",1,(yyvsp[0].gt));



    }
#line 2258 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 839 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("and_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2272 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 867 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("exclusive_or_expression",1,(yyvsp[0].gt));



    }
#line 2286 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 879 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("exclusive_or_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2300 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 907 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("inclusive_or_expression",1,(yyvsp[0].gt));



    }
#line 2314 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 919 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("inclusive_or_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2328 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 947 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("logical_and_expression",1,(yyvsp[0].gt));



    }
#line 2342 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 959 "compiler.y" /* yacc.c:1646  */
    {



        //&&



        (yyval.gt) = create_tree("logical_and_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2360 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 991 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("logical_or_expression",1,(yyvsp[0].gt));



    }
#line 2374 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1003 "compiler.y" /* yacc.c:1646  */
    {



        //||



        (yyval.gt) = create_tree("logical_or_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2392 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 1035 "compiler.y" /* yacc.c:1646  */
    {



        //条件表达式



        (yyval.gt) = create_tree("assignment_expression",1,(yyvsp[0].gt));



    }
#line 2410 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1051 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("assignment_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2424 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1079 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2438 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1091 "compiler.y" /* yacc.c:1646  */
    {



        //*=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2456 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1107 "compiler.y" /* yacc.c:1646  */
    {



        // /=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2474 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1123 "compiler.y" /* yacc.c:1646  */
    {



        // %=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2492 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1139 "compiler.y" /* yacc.c:1646  */
    {



        // += 



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2510 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1155 "compiler.y" /* yacc.c:1646  */
    {



        // -=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2528 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1171 "compiler.y" /* yacc.c:1646  */
    {



        // <<=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2546 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1187 "compiler.y" /* yacc.c:1646  */
    {



        // >>=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2564 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1203 "compiler.y" /* yacc.c:1646  */
    {



        // &=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2582 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1219 "compiler.y" /* yacc.c:1646  */
    {



        // ^=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2600 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1235 "compiler.y" /* yacc.c:1646  */
    {



        // |=



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2618 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1267 "compiler.y" /* yacc.c:1646  */
    {



        //赋值表达式



        (yyval.gt) = create_tree("expression",1,(yyvsp[0].gt));



    }
#line 2636 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1283 "compiler.y" /* yacc.c:1646  */
    {



        //逗号表达式



        (yyval.gt) = create_tree("expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2654 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1315 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration",2,(yyvsp[-1].gt),(yyvsp[0].gt)); //?



    }
#line 2668 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1327 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2682 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1355 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator_list",1,(yyvsp[0].gt));



    }
#line 2696 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1367 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2710 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1391 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator",1,(yyvsp[0].gt));



    }
#line 2724 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1403 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2738 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1435 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_specifier",1,(yyvsp[0].gt));



    }
#line 2752 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1447 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_specifier",1,(yyvsp[0].gt));



    }
#line 2766 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1459 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_specifier",1,(yyvsp[0].gt));



    }
#line 2780 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1471 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_specifier",1,(yyvsp[0].gt));    



    }
#line 2794 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1483 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_specifier",1,(yyvsp[0].gt));



    }
#line 2808 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1515 "compiler.y" /* yacc.c:1646  */
    {



        //变量



        (yyval.gt) = create_tree("declarator",1,(yyvsp[0].gt));



    }
#line 2826 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1531 "compiler.y" /* yacc.c:1646  */
    {



        //.....



        (yyval.gt) = create_tree("declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2844 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1547 "compiler.y" /* yacc.c:1646  */
    {



        //数组



        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2862 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1563 "compiler.y" /* yacc.c:1646  */
    {



        //....



        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2880 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1579 "compiler.y" /* yacc.c:1646  */
    {



        //数组



        (yyval.gt) = create_tree("declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2898 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1595 "compiler.y" /* yacc.c:1646  */
    {



        //函数



        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2916 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1611 "compiler.y" /* yacc.c:1646  */
    {



        //函数



        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2934 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1627 "compiler.y" /* yacc.c:1646  */
    {



        //函数



        (yyval.gt) = create_tree("declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2952 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1663 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_list",1,(yyvsp[0].gt));



    }
#line 2966 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1675 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2980 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1699 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_declaration",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2994 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1711 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_declaration",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3008 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1723 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_declaration",1,(yyvsp[0].gt));



    }
#line 3022 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1747 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("identifier_list",1,(yyvsp[0].gt));



    }
#line 3036 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1759 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("identifier_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3050 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1783 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3064 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1795 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3078 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1807 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3092 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1819 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3106 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1831 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3120 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1843 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3134 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1855 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3148 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1867 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3162 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1879 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3176 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1891 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3190 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1903 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3204 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1931 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer",1,(yyvsp[0].gt));



    }
#line 3218 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1943 "compiler.y" /* yacc.c:1646  */
    {



        //列表初始化 {1,1,1}



        (yyval.gt) = create_tree("initializer",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3236 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1959 "compiler.y" /* yacc.c:1646  */
    {



        //列表初始化 {1,1,1,}



        (yyval.gt) = create_tree("initializer",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3254 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1987 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",1,(yyvsp[0].gt));



    }
#line 3268 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1999 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3282 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 2011 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3296 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 2023 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",3,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt));



    }
#line 3310 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 2047 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designation",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3324 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 2071 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator_list",1,(yyvsp[0].gt));



    }
#line 3338 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 2083 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3352 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 2107 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3366 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 2119 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3380 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 2147 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3394 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 2159 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3408 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 2171 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3422 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 2183 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3436 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 2195 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3450 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 2207 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3464 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 2235 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("labeled_statement",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3478 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 2265 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compound_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3492 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 2277 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compound_statement",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3506 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 2301 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item_list",1,(yyvsp[0].gt));



    }
#line 3520 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 2313 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3534 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 2337 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item",1,(yyvsp[0].gt));



    }
#line 3548 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 2349 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item",1,(yyvsp[0].gt));



    }
#line 3562 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 2373 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("expression_statement",1,(yyvsp[0].gt));



    }
#line 3576 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 2385 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("expression_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3590 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 2413 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("selection_statement",5,(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3604 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 2425 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("selection_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3618 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 2457 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",5,(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3632 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 2469 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3646 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 2481 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",6,(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3660 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 2493 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3674 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 2505 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",6,(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3688 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 2517 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3702 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 2544 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3716 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 2556 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3730 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 2568 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3744 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 2580 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3758 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 2604 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("translation_unit",1,(yyvsp[0].gt));



    }
#line 3772 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 2616 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("translation_unit",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3786 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 2640 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("external_declaration",1,(yyvsp[0].gt));



        //函数定义



    }
#line 3804 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 2656 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("external_declaration",1,(yyvsp[0].gt));



        //变量声明


    }
#line 3821 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 2683 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("function_definition",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3835 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 2695 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("function_definition",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3849 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 2719 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration_list",1,(yyvsp[0].gt));



    }
#line 3863 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 2731 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3877 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;


#line 3881 "dist/y.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 2751 "compiler.y" /* yacc.c:1906  */












void yyerror(char const *s)



{



    fflush(stdout);



    printf("\n%*s\n%*s\n", column, "^", column, s);



}











int main(int argc,char* argv[]) {







    yyin = fopen(argv[1],"r");



    yyparse();



    printf("\n");



    analysis_tree(root,0);   //输出语法分析树



    write_to_file(root,"syntax-tree.json");

    

    //graphivz

    fp = fopen("ir_tree.dot", "w");

    fprintf(fp, "digraph G{\n");

    print_tree(root,fp);

    fprintf(fp, "}\n");

    fclose(fp);


    free_tree(root);







    fclose(yyin);



    return 0;



}
