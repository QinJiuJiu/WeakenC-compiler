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
#define YYLAST   660

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  253

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
       0,    99,    99,   121,   137,   153,   165,   183,   196,   217,
     229,   242,   254,   267,   282,   307,   319,   344,   357,   373,
     387,   407,   419,   431,   443,   464,   476,   488,   500,   522,
     534,   546,   566,   578,   591,   615,   627,   639,   651,   665,
     690,   702,   717,   743,   755,   777,   789,   812,   824,   848,
     860,   884,   896,   922,   937,   960,   972,   985,   998,  1012,
    1027,  1041,  1056,  1071,  1084,  1098,  1124,  1138,  1167,  1179,
    1207,  1219,  1243,  1255,  1285,  1297,  1309,  1321,  1333,  1365,
    1380,  1395,  1409,  1423,  1437,  1452,  1467,  1493,  1505,  1529,
    1541,  1553,  1577,  1589,  1613,  1625,  1637,  1649,  1661,  1673,
    1685,  1697,  1709,  1721,  1733,  1757,  1769,  1784,  1811,  1823,
    1835,  1847,  1871,  1895,  1907,  1931,  1943,  1971,  1983,  1995,
    2007,  2019,  2042,  2054,  2078,  2090,  2114,  2126,  2150,  2162,
    2184,  2196,  2224,  2236,  2248,  2260,  2272,  2284,  2305,  2317,
    2329,  2341,  2365,  2377,  2401,  2414,  2438,  2450,  2474,  2486
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
  "LOWER_THAN_ELSE", "$accept", "Program", "basic_expression",
  "postfix_expression", "argument_expression_list", "monocular_expression",
  "monocular_operator", "muldiv_expression", "addsub_expression",
  "shift_expression", "compare_expression", "equaljudge_expression",
  "and_expression", "xor_expression", "bitwise_or_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "assignment_operator", "expression",
  "declaration", "init_declarator_list", "init_declarator",
  "type_definition", "declarator", "parameter_list",
  "parameter_declaration", "identifier_list", "abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
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

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     167,  -141,  -141,  -141,  -141,  -141,    20,  -141,     7,   167,
    -141,  -141,  -141,  -141,  -141,     5,    69,  -141,   383,  -141,
      76,  -141,     5,   567,   481,   205,    71,  -141,     7,  -141,
     104,  -141,  -141,   214,  -141,  -141,  -141,   592,   592,  -141,
    -141,  -141,  -141,  -141,  -141,   419,   592,  -141,    80,   265,
     592,   145,    93,   177,     1,   193,   -36,   -38,   -35,    13,
      26,  -141,  -141,  -141,    60,    73,    -3,    52,   329,    59,
      97,   123,   273,  -141,  -141,  -141,   210,  -141,  -141,  -141,
     267,  -141,  -141,  -141,  -141,  -141,  -141,  -141,    16,   -25,
    -141,   -23,  -141,  -141,  -141,  -141,   592,   171,  -141,   -17,
     567,   216,  -141,   -13,  -141,  -141,   592,    25,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   592,
    -141,   592,   592,   592,   592,   592,   592,   592,   592,   592,
     592,   592,   592,   592,   592,   592,   592,   592,   592,  -141,
    -141,   592,   592,   139,   345,  -141,  -141,  -141,   249,  -141,
     592,  -141,  -141,   496,     8,   114,   138,   167,  -141,   208,
    -141,  -141,   -14,  -141,   400,  -141,  -141,  -141,  -141,  -141,
      45,  -141,     2,  -141,  -141,  -141,  -141,  -141,   145,   145,
      93,    93,   177,   177,   177,   177,     1,     1,   193,   -36,
     -38,   -35,    13,    14,    17,   146,   573,   573,  -141,  -141,
    -141,   184,   207,  -141,    48,   126,   511,   127,  -141,  -141,
    -141,  -141,  -141,   567,  -141,   592,  -141,   329,   329,   592,
      44,   111,  -141,  -141,  -141,  -141,  -141,   218,   228,  -141,
      78,  -141,  -141,   230,  -141,    82,   329,    94,   329,   128,
    -141,  -141,  -141,   329,   196,  -141,   329,  -141,   329,  -141,
    -141,  -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    75,    76,    77,    74,    78,     0,   145,     0,     2,
     142,   144,     1,    79,    68,     0,     0,    70,    72,   143,
       0,    69,     0,     0,     0,     0,     0,   148,     0,   147,
       0,    80,    71,    72,     3,     6,     7,     0,     0,     4,
       5,    24,    23,    22,    21,     0,     0,     9,    17,    25,
       0,    29,    32,    35,    40,    43,    45,    47,    49,    51,
      53,   105,    73,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   122,    66,     0,   126,   127,   117,
       0,   124,   118,   119,   120,   121,    92,    86,    91,     0,
      87,     0,   149,   146,    18,    19,     0,     0,   108,     0,
       0,     0,   113,     0,    13,    14,     0,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    55,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      81,     0,     0,     0,     0,   138,   139,   140,     0,   129,
       0,   123,   125,     0,     0,    89,    90,     0,    84,     0,
      85,    25,     0,   116,     0,   106,   109,   112,   114,     8,
       0,    11,     0,    15,    54,    26,    27,    28,    31,    30,
      33,    34,    38,    39,    36,    37,    41,    42,    44,    46,
      48,    50,    52,     0,     0,     0,     0,     0,   141,    67,
      95,     0,     0,   101,     0,     0,     0,     0,    88,    93,
     115,   107,   110,     0,    10,     0,    12,     0,     0,     0,
       0,     0,    99,    96,   102,    94,    97,     0,     0,   103,
       0,   111,    16,   130,   132,     0,     0,     0,     0,     0,
     100,    98,   104,     0,     0,   136,     0,   134,     0,   131,
     133,   137,   135
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,  -141,    96,  -141,   191,   199,   124,
     211,   163,   169,   195,   183,   200,   246,   -22,  -141,   -34,
     -12,  -141,   323,     0,    -1,  -140,   189,  -141,   197,   -41,
    -141,   185,  -141,   253,   -65,    30,  -141,   270,   -87,  -141,
    -141,  -141,  -141,   338,  -141,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    47,    48,   172,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    75,   119,    76,
       7,    16,    17,    28,    20,    89,    90,    91,   156,    62,
      99,   100,   101,   102,    78,    79,    80,    81,    82,    83,
      84,    85,     9,    10,    11,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    61,    65,   143,    98,   138,    27,    18,    13,     8,
      13,    13,   103,    77,   204,   128,   129,   134,    92,    13,
      12,    33,   157,    61,   159,   135,    88,    33,    34,   136,
     164,   137,    35,    36,   150,    37,    38,   210,   148,     1,
       2,     3,     4,     5,   158,   138,   160,    34,    29,   215,
     165,    35,    36,    14,    37,    38,   169,   197,   153,   166,
      93,   150,   130,   131,   150,   141,   153,   230,    77,    39,
      40,   216,   170,    15,    86,    15,   154,   203,    61,    41,
      42,    43,    44,   217,   154,   173,   218,   155,    39,    40,
     104,   105,   150,    46,   171,   157,   214,   174,    41,    42,
      43,    44,     1,     2,     3,     4,     5,   193,   194,   220,
     221,   139,    46,   236,    34,    21,    22,   224,    35,    36,
     142,    37,    38,   212,   140,   157,    24,   144,   199,   150,
     106,   202,   196,    94,    95,     1,     2,     3,     4,     5,
      87,   150,    61,   145,    26,    31,   120,   242,   107,   124,
     125,   244,   233,   234,    88,    39,    40,    88,     1,     2,
       3,     4,     5,   246,    24,    41,    42,    43,    44,   146,
      25,   245,   231,   247,   163,   150,   206,   195,   249,    46,
     238,   251,    26,   252,   228,   235,   237,   239,   206,   126,
     127,    61,   161,   232,   207,   225,   229,   248,     1,     2,
       3,     4,     5,   121,   122,   123,   207,    88,    34,   132,
     133,   209,    35,    36,   219,    37,    38,   175,   176,   177,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   222,     1,     2,     3,     4,
       5,    66,   250,    67,    68,    69,    70,    71,    72,    39,
      40,    73,   182,   183,   184,   185,   149,   150,   223,    41,
      42,    43,    44,    23,    24,   167,    96,   243,    97,   240,
      34,    25,    74,    46,    35,    36,    34,    37,    38,   241,
      35,    36,    26,    37,    38,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   198,   150,   188,     1,     2,
       3,     4,     5,    66,   189,    67,    68,    69,    70,    71,
      72,    39,    40,    73,   118,   178,   179,    39,    40,   147,
     191,    41,    42,    43,    44,   180,   181,    41,    42,    43,
      44,   190,    34,    25,   151,    46,    35,    36,   192,    37,
      38,    46,   162,   186,   187,    32,   208,    19,    34,   213,
     152,   205,    35,    36,   168,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,    67,    68,    69,
      70,    71,    72,    39,    40,    73,     1,     2,     3,     4,
       5,     0,     0,    41,    42,    43,    44,     0,     0,    39,
      40,    73,     0,     0,     0,    25,     0,    46,     0,    41,
      42,    43,    44,    34,     0,     0,     0,    35,    36,     0,
      37,    38,     0,    46,     1,     2,     3,     4,     5,     0,
       0,     0,    34,     0,     0,     0,    35,    36,     0,    37,
      38,     0,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,     0,    25,
      96,    26,    97,     0,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    39,    40,     0,    45,   211,    46,    96,
       0,    97,     0,    41,    42,    43,    44,     0,     0,     0,
       0,     0,     0,     0,    34,    45,     0,    46,    35,    36,
       0,    37,    38,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,    35,    36,     0,    37,    38,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,    35,    36,
       0,    37,    38,     0,     0,    39,    40,     0,     0,     0,
       0,     0,    63,     0,     0,    41,    42,    43,    44,    64,
      39,    40,     0,     0,     0,     0,     0,   200,     0,    46,
      41,    42,    43,    44,   201,    39,    40,     0,     0,     0,
       0,     0,   226,     0,    46,    41,    42,    43,    44,   227,
      34,     0,     0,     0,    35,    36,    34,    37,    38,    46,
      35,    36,     0,    37,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,    35,
      36,     0,    37,    38,     0,     0,     0,     0,     0,     0,
       0,    39,    40,     0,     0,     0,     0,    39,    40,    73,
       0,    41,    42,    43,    44,     0,     0,    41,    42,    43,
      44,     0,     0,    45,     0,    46,    39,    40,     0,     0,
       0,    46,     0,     0,     0,     0,    41,    42,    43,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46
};

static const yytype_int16 yycheck[] =
{
       0,    23,    24,    68,    45,    19,    18,     8,     3,     9,
       3,     3,    46,    25,   154,    14,    15,    53,    30,     3,
       0,    22,    47,    45,    47,    63,    26,    28,     3,    64,
      47,    18,     7,     8,    47,    10,    11,    51,    72,    31,
      32,    33,    34,    35,    69,    19,    69,     3,    18,    47,
      67,     7,     8,    46,    10,    11,    69,   144,    50,   100,
      30,    47,    61,    62,    47,    68,    50,   207,    80,    44,
      45,    69,   106,    68,     3,    68,    68,    69,   100,    54,
      55,    56,    57,    69,    68,   107,    69,    88,    44,    45,
      10,    11,    47,    68,    69,    47,    51,   119,    54,    55,
      56,    57,    31,    32,    33,    34,    35,   141,   142,   196,
     197,    51,    68,    69,     3,    46,    47,    69,     7,     8,
      68,    10,    11,   164,    51,    47,    50,    68,   150,    47,
      50,   153,   144,    37,    38,    31,    32,    33,    34,    35,
      69,    47,   164,    46,    68,    69,    50,    69,    68,    56,
      57,    69,   217,   218,   154,    44,    45,   157,    31,    32,
      33,    34,    35,    69,    50,    54,    55,    56,    57,    46,
      66,   236,   213,   238,     3,    47,    50,    38,   243,    68,
      69,   246,    68,   248,   206,   219,   220,   221,    50,    12,
      13,   213,    96,   215,    68,    69,    69,    69,    31,    32,
      33,    34,    35,    58,    59,    60,    68,   207,     3,    16,
      17,     3,     7,     8,    68,    10,    11,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,    51,    31,    32,    33,    34,
      35,    36,    46,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   128,   129,   130,   131,    46,    47,    51,    54,
      55,    56,    57,    49,    50,    49,    50,    37,    52,    51,
       3,    66,    67,    68,     7,     8,     3,    10,    11,    51,
       7,     8,    68,    10,    11,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    46,    47,   134,    31,    32,
      33,    34,    35,    36,   135,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    49,   124,   125,    44,    45,    46,
     137,    54,    55,    56,    57,   126,   127,    54,    55,    56,
      57,   136,     3,    66,    67,    68,     7,     8,   138,    10,
      11,    68,    96,   132,   133,    22,   157,     9,     3,   164,
      80,   154,     7,     8,   101,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    31,    32,    33,    34,
      35,    -1,    -1,    54,    55,    56,    57,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    66,    -1,    68,    -1,    54,
      55,    56,    57,     3,    -1,    -1,    -1,     7,     8,    -1,
      10,    11,    -1,    68,    31,    32,    33,    34,    35,    -1,
      -1,    -1,     3,    -1,    -1,    -1,     7,     8,    -1,    10,
      11,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    66,
      50,    68,    52,    -1,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    44,    45,    -1,    66,    67,    68,    50,
      -1,    52,    -1,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    66,    -1,    68,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,
      -1,    10,    11,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    56,    57,    58,
      44,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    68,
      54,    55,    56,    57,    58,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    68,    54,    55,    56,    57,    58,
       3,    -1,    -1,    -1,     7,     8,     3,    10,    11,    68,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    44,    45,    46,
      -1,    54,    55,    56,    57,    -1,    -1,    54,    55,    56,
      57,    -1,    -1,    66,    -1,    68,    44,    45,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    32,    33,    34,    35,    72,    91,    94,   113,
     114,   115,     0,     3,    46,    68,    92,    93,    95,   114,
      95,    46,    47,    49,    50,    66,    68,    91,    94,   106,
     116,    69,    93,    95,     3,     7,     8,    10,    11,    44,
      45,    54,    55,    56,    57,    66,    68,    73,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   100,    51,    58,    88,    36,    38,    39,    40,
      41,    42,    43,    46,    67,    88,    90,    91,   105,   106,
     107,   108,   109,   110,   111,   112,     3,    69,    94,    96,
      97,    98,    91,   106,    76,    76,    50,    52,   100,   101,
     102,   103,   104,    90,    10,    11,    50,    68,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    49,    89,
      76,    58,    59,    60,    56,    57,    12,    13,    14,    15,
      61,    62,    16,    17,    53,    63,    64,    18,    19,    51,
      51,    68,    68,   105,    68,    46,    46,    46,    90,    46,
      47,    67,   108,    50,    68,    95,    99,    47,    69,    47,
      69,    76,    87,     3,    47,    67,   100,    49,   104,    69,
      90,    69,    75,    88,    88,    76,    76,    76,    78,    78,
      79,    79,    80,    80,    80,    80,    81,    81,    82,    83,
      84,    85,    86,    90,    90,    38,    91,   109,    46,    88,
      51,    58,    88,    69,    96,    99,    50,    68,    97,     3,
      51,    67,   100,   102,    51,    47,    69,    69,    69,    68,
     109,   109,    51,    51,    69,    69,    51,    58,    88,    69,
      96,   100,    88,   105,   105,    90,    69,    90,    69,    90,
      51,    51,    69,    37,    69,   105,    69,   105,    69,   105,
      46,   105,   105
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
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116
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
       1,     1,     2,     3,     1,     2,     1,     1,     1,     2,
       5,     7,     5,     7,     6,     7,     6,     7,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     3,     1,     2
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
#line 1620 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("basic_expression",1,(yyvsp[0].gt));



    }
#line 1634 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("basic_expression",1,(yyvsp[0].gt));



    }
#line 1648 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("basic_expression",1,(yyvsp[0].gt));



    }
#line 1662 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 165 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("basic_expression",1,(yyvsp[0].gt));



        



    }
#line 1682 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 183 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("basic_expression",1,(yyvsp[0].gt));




    }
#line 1697 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 196 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("basic_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1711 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 217 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",1,(yyvsp[0].gt));



    }
#line 1725 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 229 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));




    }
#line 1740 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 242 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1754 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 254 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("postfix_expression",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));




    }
#line 1769 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 267 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("postfix_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1786 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 282 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("postfix_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1801 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 307 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("argument_expression_list",1,(yyvsp[0].gt));



    }
#line 1815 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 319 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("argument_expression_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1829 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 344 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("monocular_expression",1,(yyvsp[0].gt));



    }
#line 1844 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 357 "compiler.y" /* yacc.c:1646  */
    {







        (yyval.gt) = create_tree("monocular_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1862 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 373 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("monocular_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1878 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 387 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("monocular_expression",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1892 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 407 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("monocular_operator",1,(yyvsp[0].gt));



    }
#line 1906 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 419 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("monocular_operator",1,(yyvsp[0].gt));



    }
#line 1920 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 431 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("monocular_operator",1,(yyvsp[0].gt));



    }
#line 1934 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 443 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("monocular_operator",1,(yyvsp[0].gt));



    }
#line 1948 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 464 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("muldiv_expression",1,(yyvsp[0].gt));



    }
#line 1962 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 476 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("muldiv_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1976 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 488 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("muldiv_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 1990 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 500 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("muldiv_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2004 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 522 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("addsub_expression",1,(yyvsp[0].gt));



    }
#line 2018 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 534 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("addsub_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2032 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 546 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("addsub_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2046 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 566 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("shift_expression",1,(yyvsp[0].gt));



    }
#line 2060 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 578 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("shift_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2075 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 591 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("shift_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2091 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 615 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compare_expression",1,(yyvsp[0].gt));



    }
#line 2105 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 627 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compare_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2119 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 639 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compare_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2133 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 651 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("compare_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2149 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 665 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("compare_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2166 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 690 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("equaljudge_expression",1,(yyvsp[0].gt));



    }
#line 2180 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 702 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("equaljudge_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2197 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 717 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("equaljudge_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2213 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 743 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("and_expression",1,(yyvsp[0].gt));



    }
#line 2227 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 755 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("and_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2241 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 777 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("xor_expression",1,(yyvsp[0].gt));



    }
#line 2255 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 789 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("xor_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2269 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 812 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("bitwise_or_expression",1,(yyvsp[0].gt));



    }
#line 2283 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 824 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("bitwise_or_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2297 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 848 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("logical_and_expression",1,(yyvsp[0].gt));



    }
#line 2311 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 860 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("logical_and_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2328 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 884 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("logical_or_expression",1,(yyvsp[0].gt));



    }
#line 2342 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 896 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("logical_or_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2358 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 922 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("assignment_expression",1,(yyvsp[0].gt));



    }
#line 2375 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 937 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("assignment_expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2389 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 960 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2403 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 972 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2418 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 985 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2433 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 998 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2449 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1012 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2466 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1027 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2482 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1041 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2499 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1056 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2516 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1071 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2531 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1084 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2547 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1098 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("assignment_operator",1,(yyvsp[0].gt));



    }
#line 2563 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1124 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("expression",1,(yyvsp[0].gt));



    }
#line 2579 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1138 "compiler.y" /* yacc.c:1646  */
    {




        (yyval.gt) = create_tree("expression",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2594 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1167 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration",2,(yyvsp[-1].gt),(yyvsp[0].gt)); //?



    }
#line 2608 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1179 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2622 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1207 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator_list",1,(yyvsp[0].gt));



    }
#line 2636 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1219 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2650 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1243 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator",1,(yyvsp[0].gt));



    }
#line 2664 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1255 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("init_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2678 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1285 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_definition",1,(yyvsp[0].gt));



    }
#line 2692 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1297 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_definition",1,(yyvsp[0].gt));



    }
#line 2706 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1309 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_definition",1,(yyvsp[0].gt));



    }
#line 2720 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1321 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_definition",1,(yyvsp[0].gt));    



    }
#line 2734 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1333 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("type_definition",1,(yyvsp[0].gt));



    }
#line 2748 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1365 "compiler.y" /* yacc.c:1646  */
    {



      


        (yyval.gt) = create_tree("declarator",1,(yyvsp[0].gt));



    }
#line 2765 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1380 "compiler.y" /* yacc.c:1646  */
    {



        


        (yyval.gt) = create_tree("declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2782 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1395 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2798 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1409 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2814 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1423 "compiler.y" /* yacc.c:1646  */
    {





        (yyval.gt) = create_tree("declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2830 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1437 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2847 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1452 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2864 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1467 "compiler.y" /* yacc.c:1646  */
    {



  


        (yyval.gt) = create_tree("declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2881 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1493 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_list",1,(yyvsp[0].gt));



    }
#line 2895 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1505 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2909 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1529 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_declaration",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2923 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1541 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_declaration",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2937 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1553 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("parameter_declaration",1,(yyvsp[0].gt));



    }
#line 2951 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1577 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("identifier_list",1,(yyvsp[0].gt));



    }
#line 2965 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1589 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("identifier_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2979 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1613 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 2993 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1625 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3007 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1637 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3021 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1649 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3035 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1661 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3049 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1673 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3063 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1685 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3077 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1697 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3091 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1709 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3105 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1721 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3119 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1733 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("abstract_declarator",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3133 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1757 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer",1,(yyvsp[0].gt));



    }
#line 3147 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1769 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("initializer",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3164 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1784 "compiler.y" /* yacc.c:1646  */
    {






        (yyval.gt) = create_tree("initializer",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3181 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1811 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",1,(yyvsp[0].gt));



    }
#line 3195 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1823 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3209 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1835 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3223 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1847 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("initializer_list",3,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt));



    }
#line 3237 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1871 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designation",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3251 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1895 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator_list",1,(yyvsp[0].gt));



    }
#line 3265 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1907 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3279 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1931 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3293 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1943 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("designator",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3307 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1971 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3321 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1983 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3335 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1995 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3349 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 2007 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3363 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 2019 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("statement",1,(yyvsp[0].gt));



    }
#line 3377 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 2042 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compound_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3391 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 2054 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("compound_statement",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3405 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 2078 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item_list",1,(yyvsp[0].gt));



    }
#line 3419 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 2090 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3433 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 2114 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item",1,(yyvsp[0].gt));



    }
#line 3447 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 2126 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("block_item",1,(yyvsp[0].gt));



    }
#line 3461 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 2150 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("expression_statement",1,(yyvsp[0].gt));



    }
#line 3475 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 2162 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("expression_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3489 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 2184 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("selection_statement",5,(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3503 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 2196 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("selection_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3517 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 2224 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",5,(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3531 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 2236 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3545 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 2248 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",6,(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3559 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 2260 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3573 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 2272 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",6,(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3587 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 2284 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("iteration_statement",7,(yyvsp[-6].gt),(yyvsp[-5].gt),(yyvsp[-4].gt),(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3601 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 2305 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3615 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 2317 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3629 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 2329 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3643 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 2341 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("jump_statement",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3657 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 2365 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("translation_unit",1,(yyvsp[0].gt));



    }
#line 3671 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 2377 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("translation_unit",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3685 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 2401 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("external_declaration",1,(yyvsp[0].gt));




    }
#line 3700 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 2414 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("external_declaration",1,(yyvsp[0].gt));



    }
#line 3714 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 2438 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("function_definition",4,(yyvsp[-3].gt),(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3728 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 2450 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("function_definition",3,(yyvsp[-2].gt),(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3742 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 2474 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration_list",1,(yyvsp[0].gt));



    }
#line 3756 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 2486 "compiler.y" /* yacc.c:1646  */
    {



        (yyval.gt) = create_tree("declaration_list",2,(yyvsp[-1].gt),(yyvsp[0].gt));



    }
#line 3770 "dist/y.tab.cpp" /* yacc.c:1646  */
    break;


#line 3774 "dist/y.tab.cpp" /* yacc.c:1646  */
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
#line 2506 "compiler.y" /* yacc.c:1906  */












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
