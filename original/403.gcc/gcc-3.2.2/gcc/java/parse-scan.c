/* A Bison parser, made from /home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y
   by GNU bison 1.33.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	PLUS_TK	257
# define	MINUS_TK	258
# define	MULT_TK	259
# define	DIV_TK	260
# define	REM_TK	261
# define	LS_TK	262
# define	SRS_TK	263
# define	ZRS_TK	264
# define	AND_TK	265
# define	XOR_TK	266
# define	OR_TK	267
# define	BOOL_AND_TK	268
# define	BOOL_OR_TK	269
# define	EQ_TK	270
# define	NEQ_TK	271
# define	GT_TK	272
# define	GTE_TK	273
# define	LT_TK	274
# define	LTE_TK	275
# define	PLUS_ASSIGN_TK	276
# define	MINUS_ASSIGN_TK	277
# define	MULT_ASSIGN_TK	278
# define	DIV_ASSIGN_TK	279
# define	REM_ASSIGN_TK	280
# define	LS_ASSIGN_TK	281
# define	SRS_ASSIGN_TK	282
# define	ZRS_ASSIGN_TK	283
# define	AND_ASSIGN_TK	284
# define	XOR_ASSIGN_TK	285
# define	OR_ASSIGN_TK	286
# define	PUBLIC_TK	287
# define	PRIVATE_TK	288
# define	PROTECTED_TK	289
# define	STATIC_TK	290
# define	FINAL_TK	291
# define	SYNCHRONIZED_TK	292
# define	VOLATILE_TK	293
# define	TRANSIENT_TK	294
# define	NATIVE_TK	295
# define	PAD_TK	296
# define	ABSTRACT_TK	297
# define	MODIFIER_TK	298
# define	STRICT_TK	299
# define	DECR_TK	300
# define	INCR_TK	301
# define	DEFAULT_TK	302
# define	IF_TK	303
# define	THROW_TK	304
# define	BOOLEAN_TK	305
# define	DO_TK	306
# define	IMPLEMENTS_TK	307
# define	THROWS_TK	308
# define	BREAK_TK	309
# define	IMPORT_TK	310
# define	ELSE_TK	311
# define	INSTANCEOF_TK	312
# define	RETURN_TK	313
# define	VOID_TK	314
# define	CATCH_TK	315
# define	INTERFACE_TK	316
# define	CASE_TK	317
# define	EXTENDS_TK	318
# define	FINALLY_TK	319
# define	SUPER_TK	320
# define	WHILE_TK	321
# define	CLASS_TK	322
# define	SWITCH_TK	323
# define	CONST_TK	324
# define	TRY_TK	325
# define	FOR_TK	326
# define	NEW_TK	327
# define	CONTINUE_TK	328
# define	GOTO_TK	329
# define	PACKAGE_TK	330
# define	THIS_TK	331
# define	BYTE_TK	332
# define	SHORT_TK	333
# define	INT_TK	334
# define	LONG_TK	335
# define	CHAR_TK	336
# define	INTEGRAL_TK	337
# define	FLOAT_TK	338
# define	DOUBLE_TK	339
# define	FP_TK	340
# define	ID_TK	341
# define	REL_QM_TK	342
# define	REL_CL_TK	343
# define	NOT_TK	344
# define	NEG_TK	345
# define	ASSIGN_ANY_TK	346
# define	ASSIGN_TK	347
# define	OP_TK	348
# define	CP_TK	349
# define	OCB_TK	350
# define	CCB_TK	351
# define	OSB_TK	352
# define	CSB_TK	353
# define	SC_TK	354
# define	C_TK	355
# define	DOT_TK	356
# define	STRING_LIT_TK	357
# define	CHAR_LIT_TK	358
# define	INT_LIT_TK	359
# define	FP_LIT_TK	360
# define	TRUE_TK	361
# define	FALSE_TK	362
# define	BOOL_LIT_TK	363
# define	NULL_TK	364

#line 37 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"

#define JC1_LITE

#include "config.h"
#include "system.h"

#include "obstack.h"
#include "toplev.h"

extern char *input_filename;
extern FILE *finput, *out;

/* Obstack for the lexer.  */
struct obstack temporary_obstack;

/* The current parser context.  */
static struct parser_ctxt *ctxp;

/* Error and warning counts, current line number, because they're used
   elsewhere  */
int java_error_count;
int java_warning_count;
int lineno;

/* Tweak default rules when necessary.  */
static int absorber;
#define USE_ABSORBER absorber = 0

/* Keep track of the current class name and package name.  */
static char *current_class;
static const char *package_name;

/* Keep track of the current inner class qualifier. */
static int current_class_length;

/* Keep track of whether things have be listed before.  */
static int previous_output;

/* Record modifier uses  */
static int modifier_value;

/* Record (almost) cyclomatic complexity.  */
static int complexity; 

/* Keeps track of number of bracket pairs after a variable declarator
   id.  */
static int bracket_count; 

/* Numbers anonymous classes */
static int anonymous_count;

/* Record a method declaration  */
struct method_declarator {
  const char *method_name;
  const char *args;
};
#define NEW_METHOD_DECLARATOR(D,N,A)					     \
{									     \
  (D) = 								     \
    (struct method_declarator *)xmalloc (sizeof (struct method_declarator)); \
  (D)->method_name = (N);						     \
  (D)->args = (A);							     \
}

/* Two actions for this grammar */
static void report_class_declaration PARAMS ((const char *));
static void report_main_declaration PARAMS ((struct method_declarator *));
static void push_class_context PARAMS ((const char *));
static void pop_class_context PARAMS ((void));

void report PARAMS ((void)); 

#include "lex.h"
#include "parse.h"

#line 113 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
#ifndef YYSTYPE
typedef union {
  char *node;
  struct method_declarator *declarator;
  int value;			/* For modifiers */
} yystype;
# define YYSTYPE yystype
#endif
#line 119 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"

#include "lex.c"
#ifndef YYDEBUG
# define YYDEBUG 1
#endif



#define	YYFINAL		606
#define	YYFLAG		-32768
#define	YYNTBASE	111

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 364 ? yytranslate[x] : 262)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     2,     4,     6,     8,    10,    12,    14,    16,
      18,    20,    22,    24,    26,    28,    30,    32,    34,    37,
      40,    42,    44,    46,    50,    52,    53,    55,    57,    59,
      62,    65,    68,    72,    74,    77,    79,    82,    86,    88,
      90,    94,   100,   102,   104,   106,   108,   111,   112,   120,
     121,   128,   129,   132,   133,   136,   138,   142,   145,   149,
     151,   154,   156,   158,   160,   162,   164,   166,   168,   170,
     172,   176,   181,   183,   187,   189,   193,   195,   199,   201,
     203,   206,   210,   214,   219,   224,   228,   233,   237,   239,
     243,   246,   250,   251,   254,   256,   260,   262,   264,   267,
     269,   273,   278,   283,   289,   293,   298,   301,   305,   309,
     314,   319,   325,   333,   340,   342,   344,   345,   350,   351,
     357,   358,   364,   365,   372,   375,   379,   382,   386,   388,
     391,   393,   395,   397,   399,   401,   404,   407,   411,   415,
     420,   422,   426,   429,   433,   435,   438,   440,   442,   444,
     447,   450,   454,   456,   458,   460,   462,   464,   466,   468,
     470,   472,   474,   476,   478,   480,   482,   484,   486,   488,
     490,   492,   494,   496,   498,   500,   503,   506,   509,   512,
     514,   516,   518,   520,   522,   524,   526,   532,   540,   548,
     554,   557,   561,   565,   570,   572,   575,   578,   580,   583,
     587,   590,   595,   598,   601,   603,   611,   619,   626,   634,
     641,   644,   647,   648,   650,   652,   653,   655,   657,   661,
     664,   668,   671,   675,   678,   682,   686,   692,   698,   700,
     704,   708,   713,   715,   718,   724,   727,   729,   731,   733,
     735,   739,   741,   743,   745,   747,   749,   753,   757,   761,
     765,   769,   775,   780,   782,   787,   793,   799,   806,   807,
     814,   815,   823,   827,   831,   833,   837,   841,   845,   849,
     854,   859,   864,   869,   871,   874,   878,   881,   885,   889,
     893,   897,   902,   908,   915,   921,   928,   933,   938,   940,
     942,   944,   946,   949,   952,   954,   956,   959,   962,   964,
     967,   970,   972,   975,   978,   980,   986,   991,   996,  1002,
    1004,  1008,  1012,  1016,  1018,  1022,  1026,  1028,  1032,  1036,
    1040,  1042,  1046,  1050,  1054,  1058,  1062,  1064,  1068,  1072,
    1074,  1078,  1080,  1084,  1086,  1090,  1092,  1096,  1098,  1102,
    1104,  1110,  1112,  1114,  1118,  1120,  1122,  1124,  1126,  1128,
    1130
};
static const short yyrhs[] =
{
     124,     0,   105,     0,   106,     0,   109,     0,   104,     0,
     103,     0,   110,     0,   114,     0,   115,     0,    83,     0,
      86,     0,    51,     0,   116,     0,   119,     0,   120,     0,
     116,     0,   116,     0,   114,   233,     0,   120,   233,     0,
     121,     0,   122,     0,   123,     0,   120,   102,   123,     0,
      87,     0,     0,   127,     0,   125,     0,   126,     0,   127,
     125,     0,   127,   126,     0,   125,   126,     0,   127,   125,
     126,     0,   128,     0,   125,   128,     0,   131,     0,   126,
     131,     0,    76,   120,   100,     0,   129,     0,   130,     0,
      56,   120,   100,     0,    56,   120,   102,     5,   100,     0,
     133,     0,   163,     0,   184,     0,    44,     0,   132,    44,
       0,     0,   132,    68,   123,   136,   137,   134,   139,     0,
       0,    68,   123,   136,   137,   135,   139,     0,     0,    64,
     117,     0,     0,    53,   138,     0,   118,     0,   138,   101,
     118,     0,    96,    97,     0,    96,   140,    97,     0,   141,
       0,   140,   141,     0,   142,     0,   156,     0,   158,     0,
     176,     0,   143,     0,   148,     0,   133,     0,   163,     0,
     184,     0,   113,   144,   100,     0,   132,   113,   144,   100,
       0,   145,     0,   144,   101,   145,     0,   146,     0,   146,
      93,   147,     0,   123,     0,   146,    98,    99,     0,   260,
       0,   174,     0,   149,   155,     0,   113,   150,   153,     0,
      60,   150,   153,     0,   132,   113,   150,   153,     0,   132,
      60,   150,   153,     0,   123,    94,    95,     0,   123,    94,
     151,    95,     0,   150,    98,    99,     0,   152,     0,   151,
     101,   152,     0,   113,   146,     0,   132,   113,   146,     0,
       0,    54,   154,     0,   117,     0,   154,   101,   117,     0,
     176,     0,   100,     0,   157,   176,     0,    44,     0,   159,
     153,   160,     0,   132,   159,   153,   160,     0,   159,   153,
     160,   100,     0,   132,   159,   153,   160,   100,     0,   121,
      94,    95,     0,   121,    94,   151,    95,     0,    96,    97,
       0,    96,   161,    97,     0,    96,   177,    97,     0,    96,
     161,   177,    97,     0,   162,    94,    95,   100,     0,   162,
      94,   229,    95,   100,     0,   120,   102,    66,    94,   229,
      95,   100,     0,   120,   102,    66,    94,    95,   100,     0,
      77,     0,    66,     0,     0,    62,   123,   164,   169,     0,
       0,   132,    62,   123,   165,   169,     0,     0,    62,   123,
     168,   166,   169,     0,     0,   132,    62,   123,   168,   167,
     169,     0,    64,   118,     0,   168,   101,   118,     0,    96,
      97,     0,    96,   170,    97,     0,   171,     0,   170,   171,
       0,   172,     0,   173,     0,   133,     0,   163,     0,   143,
       0,   149,   100,     0,    96,    97,     0,    96,   175,    97,
       0,    96,   101,    97,     0,    96,   175,   101,    97,     0,
     147,     0,   175,   101,   147,     0,    96,    97,     0,    96,
     177,    97,     0,   178,     0,   177,   178,     0,   179,     0,
     181,     0,   133,     0,   180,   100,     0,   113,   144,     0,
     132,   113,   144,     0,   183,     0,   186,     0,   190,     0,
     191,     0,   200,     0,   204,     0,   183,     0,   187,     0,
     192,     0,   201,     0,   205,     0,   176,     0,   184,     0,
     188,     0,   193,     0,   203,     0,   211,     0,   212,     0,
     213,     0,   215,     0,   214,     0,   217,     0,   100,     0,
     123,    89,     0,   185,   181,     0,   185,   182,     0,   189,
     100,     0,   257,     0,   241,     0,   242,     0,   238,     0,
     239,     0,   235,     0,   224,     0,    49,    94,   260,    95,
     181,     0,    49,    94,   260,    95,   182,    57,   181,     0,
      49,    94,   260,    95,   182,    57,   182,     0,    69,    94,
     260,    95,   194,     0,    96,    97,     0,    96,   197,    97,
       0,    96,   195,    97,     0,    96,   195,   197,    97,     0,
     196,     0,   195,   196,     0,   197,   177,     0,   198,     0,
     197,   198,     0,    63,   261,    89,     0,    48,    89,     0,
      67,    94,   260,    95,     0,   199,   181,     0,   199,   182,
       0,    52,     0,   202,   181,    67,    94,   260,    95,   100,
       0,   207,   100,   260,   100,   209,    95,   181,     0,   207,
     100,   100,   209,    95,   181,     0,   207,   100,   260,   100,
     209,    95,   182,     0,   207,   100,   100,   209,    95,   182,
       0,    72,    94,     0,   206,   208,     0,     0,   210,     0,
     180,     0,     0,   210,     0,   189,     0,   210,   101,   189,
       0,    55,   100,     0,    55,   123,   100,     0,    74,   100,
       0,    74,   123,   100,     0,    59,   100,     0,    59,   260,
     100,     0,    50,   260,   100,     0,   216,    94,   260,    95,
     176,     0,   216,    94,   260,    95,     1,     0,    44,     0,
      71,   176,   218,     0,    71,   176,   220,     0,    71,   176,
     218,   220,     0,   219,     0,   218,   219,     0,    61,    94,
     152,    95,   176,     0,    65,   176,     0,   222,     0,   230,
       0,   112,     0,    77,     0,    94,   260,    95,     0,   224,
       0,   234,     0,   235,     0,   236,     0,   223,     0,   120,
     102,    77,     0,   120,   102,    68,     0,   119,   102,    68,
       0,   114,   102,    68,     0,    60,   102,    68,     0,    73,
     117,    94,   229,    95,     0,    73,   117,    94,    95,     0,
     225,     0,   228,   123,    94,    95,     0,   228,   123,    94,
      95,   139,     0,   228,   123,    94,   229,    95,     0,   228,
     123,    94,   229,    95,   139,     0,     0,    73,   117,    94,
      95,   226,   139,     0,     0,    73,   117,    94,   229,    95,
     227,   139,     0,   120,   102,    73,     0,   221,   102,    73,
       0,   260,     0,   229,   101,   260,     0,   229,   101,     1,
       0,    73,   114,   231,     0,    73,   116,   231,     0,    73,
     114,   231,   233,     0,    73,   116,   231,   233,     0,    73,
     116,   233,   174,     0,    73,   114,   233,   174,     0,   232,
       0,   231,   232,     0,    98,   260,    99,     0,    98,    99,
       0,   233,    98,    99,     0,   221,   102,   123,     0,    66,
     102,   123,     0,   120,    94,    95,     0,   120,    94,   229,
      95,     0,   221,   102,   123,    94,    95,     0,   221,   102,
     123,    94,   229,    95,     0,    66,   102,   123,    94,    95,
       0,    66,   102,   123,    94,   229,    95,     0,   120,    98,
     260,    99,     0,   222,    98,   260,    99,     0,   221,     0,
     120,     0,   238,     0,   239,     0,   237,    47,     0,   237,
      46,     0,   241,     0,   242,     0,     3,   240,     0,     4,
     240,     0,   243,     0,    47,   240,     0,    46,   240,     0,
     237,     0,    90,   240,     0,    91,   240,     0,   244,     0,
      94,   114,   233,    95,   240,     0,    94,   114,    95,   240,
       0,    94,   260,    95,   243,     0,    94,   120,   233,    95,
     243,     0,   240,     0,   245,     5,   240,     0,   245,     6,
     240,     0,   245,     7,   240,     0,   245,     0,   246,     3,
     245,     0,   246,     4,   245,     0,   246,     0,   247,     8,
     246,     0,   247,     9,   246,     0,   247,    10,   246,     0,
     247,     0,   248,    20,   247,     0,   248,    18,   247,     0,
     248,    21,   247,     0,   248,    19,   247,     0,   248,    58,
     115,     0,   248,     0,   249,    16,   248,     0,   249,    17,
     248,     0,   249,     0,   250,    11,   249,     0,   250,     0,
     251,    12,   250,     0,   251,     0,   252,    13,   251,     0,
     252,     0,   253,    14,   252,     0,   253,     0,   254,    15,
     253,     0,   254,     0,   254,    88,   260,    89,   255,     0,
     255,     0,   257,     0,   258,   259,   256,     0,   120,     0,
     234,     0,   236,     0,    92,     0,    93,     0,   256,     0,
     260,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   189,   194,   196,   197,   198,   199,   200,   204,   206,
     209,   215,   220,   227,   229,   232,   236,   240,   244,   250,
     258,   260,   263,   267,   274,   279,   280,   281,   282,   283,
     284,   285,   286,   289,   291,   294,   296,   299,   304,   306,
     309,   313,   317,   319,   320,   326,   335,   346,   346,   353,
     353,   358,   359,   362,   363,   366,   369,   373,   376,   380,
     382,   385,   387,   388,   389,   392,   394,   395,   396,   397,
     401,   404,   408,   411,   414,   416,   419,   422,   426,   428,
     432,   436,   439,   440,   442,   449,   456,   462,   465,   467,
     473,   489,   505,   506,   509,   512,   516,   518,   522,   526,
     536,   538,   541,   543,   549,   552,   556,   558,   559,   560,
     564,   566,   569,   571,   575,   577,   582,   582,   586,   586,
     589,   589,   592,   592,   597,   599,   602,   605,   609,   611,
     614,   616,   617,   618,   621,   625,   630,   632,   633,   634,
     637,   639,   643,   645,   648,   650,   653,   655,   656,   659,
     663,   666,   670,   672,   673,   674,   675,   676,   679,   681,
     682,   683,   684,   687,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   701,   705,   710,   714,   720,   724,
     726,   727,   728,   729,   730,   731,   734,   738,   743,   748,
     752,   754,   755,   756,   759,   761,   764,   769,   771,   774,
     776,   779,   783,   787,   791,   795,   800,   802,   805,   807,
     810,   814,   817,   818,   819,   822,   823,   826,   828,   831,
     833,   838,   840,   843,   845,   848,   852,   854,   857,   862,
     864,   865,   868,   870,   873,   877,   882,   884,   887,   889,
     890,   891,   892,   893,   894,   895,   899,   903,   906,   908,
     910,   914,   916,   917,   918,   919,   920,   921,   924,   924,
     928,   928,   933,   936,   939,   941,   942,   945,   947,   948,
     949,   952,   953,   956,   958,   961,   965,   968,   972,   974,
     980,   983,   985,   986,   987,   988,   991,   994,   997,   999,
    1001,  1002,  1005,  1009,  1013,  1015,  1016,  1017,  1018,  1021,
    1025,  1029,  1031,  1032,  1033,  1036,  1038,  1039,  1040,  1043,
    1045,  1046,  1047,  1050,  1052,  1053,  1056,  1058,  1059,  1060,
    1063,  1065,  1066,  1067,  1068,  1069,  1072,  1074,  1075,  1078,
    1080,  1083,  1085,  1088,  1090,  1093,  1095,  1099,  1101,  1105,
    1107,  1111,  1113,  1116,  1120,  1123,  1124,  1127,  1129,  1132,
    1136
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "PLUS_TK", "MINUS_TK", "MULT_TK", "DIV_TK", 
  "REM_TK", "LS_TK", "SRS_TK", "ZRS_TK", "AND_TK", "XOR_TK", "OR_TK", 
  "BOOL_AND_TK", "BOOL_OR_TK", "EQ_TK", "NEQ_TK", "GT_TK", "GTE_TK", 
  "LT_TK", "LTE_TK", "PLUS_ASSIGN_TK", "MINUS_ASSIGN_TK", 
  "MULT_ASSIGN_TK", "DIV_ASSIGN_TK", "REM_ASSIGN_TK", "LS_ASSIGN_TK", 
  "SRS_ASSIGN_TK", "ZRS_ASSIGN_TK", "AND_ASSIGN_TK", "XOR_ASSIGN_TK", 
  "OR_ASSIGN_TK", "PUBLIC_TK", "PRIVATE_TK", "PROTECTED_TK", "STATIC_TK", 
  "FINAL_TK", "SYNCHRONIZED_TK", "VOLATILE_TK", "TRANSIENT_TK", 
  "NATIVE_TK", "PAD_TK", "ABSTRACT_TK", "MODIFIER_TK", "STRICT_TK", 
  "DECR_TK", "INCR_TK", "DEFAULT_TK", "IF_TK", "THROW_TK", "BOOLEAN_TK", 
  "DO_TK", "IMPLEMENTS_TK", "THROWS_TK", "BREAK_TK", "IMPORT_TK", 
  "ELSE_TK", "INSTANCEOF_TK", "RETURN_TK", "VOID_TK", "CATCH_TK", 
  "INTERFACE_TK", "CASE_TK", "EXTENDS_TK", "FINALLY_TK", "SUPER_TK", 
  "WHILE_TK", "CLASS_TK", "SWITCH_TK", "CONST_TK", "TRY_TK", "FOR_TK", 
  "NEW_TK", "CONTINUE_TK", "GOTO_TK", "PACKAGE_TK", "THIS_TK", "BYTE_TK", 
  "SHORT_TK", "INT_TK", "LONG_TK", "CHAR_TK", "INTEGRAL_TK", "FLOAT_TK", 
  "DOUBLE_TK", "FP_TK", "ID_TK", "REL_QM_TK", "REL_CL_TK", "NOT_TK", 
  "NEG_TK", "ASSIGN_ANY_TK", "ASSIGN_TK", "OP_TK", "CP_TK", "OCB_TK", 
  "CCB_TK", "OSB_TK", "CSB_TK", "SC_TK", "C_TK", "DOT_TK", 
  "STRING_LIT_TK", "CHAR_LIT_TK", "INT_LIT_TK", "FP_LIT_TK", "TRUE_TK", 
  "FALSE_TK", "BOOL_LIT_TK", "NULL_TK", "goal", "literal", "type", 
  "primitive_type", "reference_type", "class_or_interface_type", 
  "class_type", "interface_type", "array_type", "name", "simple_name", 
  "qualified_name", "identifier", "compilation_unit", 
  "import_declarations", "type_declarations", "package_declaration", 
  "import_declaration", "single_type_import_declaration", 
  "type_import_on_demand_declaration", "type_declaration", "modifiers", 
  "class_declaration", "@1", "@2", "super", "interfaces", 
  "interface_type_list", "class_body", "class_body_declarations", 
  "class_body_declaration", "class_member_declaration", 
  "field_declaration", "variable_declarators", "variable_declarator", 
  "variable_declarator_id", "variable_initializer", "method_declaration", 
  "method_header", "method_declarator", "formal_parameter_list", 
  "formal_parameter", "throws", "class_type_list", "method_body", 
  "static_initializer", "static", "constructor_declaration", 
  "constructor_declarator", "constructor_body", 
  "explicit_constructor_invocation", "this_or_super", 
  "interface_declaration", "@3", "@4", "@5", "@6", "extends_interfaces", 
  "interface_body", "interface_member_declarations", 
  "interface_member_declaration", "constant_declaration", 
  "abstract_method_declaration", "array_initializer", 
  "variable_initializers", "block", "block_statements", "block_statement", 
  "local_variable_declaration_statement", "local_variable_declaration", 
  "statement", "statement_nsi", "statement_without_trailing_substatement", 
  "empty_statement", "label_decl", "labeled_statement", 
  "labeled_statement_nsi", "expression_statement", "statement_expression", 
  "if_then_statement", "if_then_else_statement", 
  "if_then_else_statement_nsi", "switch_statement", "switch_block", 
  "switch_block_statement_groups", "switch_block_statement_group", 
  "switch_labels", "switch_label", "while_expression", "while_statement", 
  "while_statement_nsi", "do_statement_begin", "do_statement", 
  "for_statement", "for_statement_nsi", "for_header", "for_begin", 
  "for_init", "for_update", "statement_expression_list", 
  "break_statement", "continue_statement", "return_statement", 
  "throw_statement", "synchronized_statement", "synchronized", 
  "try_statement", "catches", "catch_clause", "finally", "primary", 
  "primary_no_new_array", "type_literals", 
  "class_instance_creation_expression", "anonymous_class_creation", "@7", 
  "@8", "something_dot_new", "argument_list", "array_creation_expression", 
  "dim_exprs", "dim_expr", "dims", "field_access", "method_invocation", 
  "array_access", "postfix_expression", "post_increment_expression", 
  "post_decrement_expression", "unary_expression", 
  "pre_increment_expression", "pre_decrement_expression", 
  "unary_expression_not_plus_minus", "cast_expression", 
  "multiplicative_expression", "additive_expression", "shift_expression", 
  "relational_expression", "equality_expression", "and_expression", 
  "exclusive_or_expression", "inclusive_or_expression", 
  "conditional_and_expression", "conditional_or_expression", 
  "conditional_expression", "assignment_expression", "assignment", 
  "left_hand_side", "assignment_operator", "expression", 
  "constant_expression", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,   111,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   114,   115,   115,   116,   117,   118,   119,   119,
     120,   120,   121,   122,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   127,   128,   128,
     129,   130,   131,   131,   131,   132,   132,   134,   133,   135,
     133,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   141,   142,   142,   142,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   149,   149,   149,   149,   150,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   157,
     158,   158,   158,   158,   159,   159,   160,   160,   160,   160,
     161,   161,   161,   161,   162,   162,   164,   163,   165,   163,
     166,   163,   167,   163,   168,   168,   169,   169,   170,   170,
     171,   171,   171,   171,   172,   173,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   178,   179,
     180,   180,   181,   181,   181,   181,   181,   181,   182,   182,
     182,   182,   182,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   185,   186,   187,   188,   189,
     189,   189,   189,   189,   189,   189,   190,   191,   192,   193,
     194,   194,   194,   194,   195,   195,   196,   197,   197,   198,
     198,   199,   200,   201,   202,   203,   204,   204,   205,   205,
     206,   207,   208,   208,   208,   209,   209,   210,   210,   211,
     211,   212,   212,   213,   213,   214,   215,   215,   216,   217,
     217,   217,   218,   218,   219,   220,   221,   221,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   223,   223,   223,
     223,   224,   224,   224,   224,   224,   224,   224,   226,   225,
     227,   225,   228,   228,   229,   229,   229,   230,   230,   230,
     230,   230,   230,   231,   231,   232,   233,   233,   234,   234,
     235,   235,   235,   235,   235,   235,   236,   236,   237,   237,
     237,   237,   238,   239,   240,   240,   240,   240,   240,   241,
     242,   243,   243,   243,   243,   244,   244,   244,   244,   245,
     245,   245,   245,   246,   246,   246,   247,   247,   247,   247,
     248,   248,   248,   248,   248,   248,   249,   249,   249,   250,
     250,   251,   251,   252,   252,   253,   253,   254,   254,   255,
     255,   256,   256,   257,   258,   258,   258,   259,   259,   260,
     261
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     3,     1,     0,     1,     1,     1,     2,
       2,     2,     3,     1,     2,     1,     2,     3,     1,     1,
       3,     5,     1,     1,     1,     1,     2,     0,     7,     0,
       6,     0,     2,     0,     2,     1,     3,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     1,     3,     1,     3,     1,     1,
       2,     3,     3,     4,     4,     3,     4,     3,     1,     3,
       2,     3,     0,     2,     1,     3,     1,     1,     2,     1,
       3,     4,     4,     5,     3,     4,     2,     3,     3,     4,
       4,     5,     7,     6,     1,     1,     0,     4,     0,     5,
       0,     5,     0,     6,     2,     3,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     4,
       1,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     7,     5,
       2,     3,     3,     4,     1,     2,     2,     1,     2,     3,
       2,     4,     2,     2,     1,     7,     7,     6,     7,     6,
       2,     2,     0,     1,     1,     0,     1,     1,     3,     2,
       3,     2,     3,     2,     3,     3,     5,     5,     1,     3,
       3,     4,     1,     2,     5,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     5,     4,     1,     4,     5,     5,     6,     0,     6,
       0,     7,     3,     3,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     1,     2,     3,     2,     3,     3,     3,
       3,     4,     5,     6,     5,     6,     4,     4,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     5,     4,     4,     5,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
      25,    45,     0,     0,     0,     0,   174,     1,    27,    28,
      26,    33,    38,    39,    35,     0,    42,    43,    44,    24,
       0,    20,    21,    22,   116,    51,     0,    31,    34,    36,
      29,    30,    46,     0,     0,    40,     0,     0,     0,   120,
       0,    53,    37,     0,    32,   118,    51,     0,    23,    17,
     124,    15,     0,   117,     0,     0,    16,    52,     0,    49,
       0,   122,    53,    41,    12,     0,    10,    11,   126,     0,
       8,     9,    13,    14,    15,     0,   132,   134,     0,   133,
       0,   128,   130,   131,   125,   121,    55,    54,     0,   119,
       0,    47,     0,    92,    76,     0,    72,    74,    92,     0,
      18,    19,     0,     0,   135,   127,   129,     0,     0,    50,
     123,     0,     0,     0,     0,    82,    70,     0,     0,     0,
      81,   276,     0,    92,     0,    92,    56,    45,     0,    57,
      20,     0,    67,     0,    59,    61,    65,    66,     0,    62,
       0,    63,    92,    68,    64,    69,    48,    85,     0,     0,
       0,    88,    94,    93,    87,    76,    73,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     6,
       5,     2,     3,     4,     7,   238,     0,     0,   289,    75,
      79,   288,   236,   245,   241,   253,     0,   237,   242,   243,
     244,   301,   290,   291,   309,   294,   295,   298,   304,   313,
     316,   320,   326,   329,   331,   333,   335,   337,   339,   341,
     349,   342,     0,    78,    77,   277,    84,    71,    83,    45,
       0,     0,   204,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     8,    14,   289,    22,     0,   148,   163,
       0,   144,   146,     0,   147,   152,   164,     0,   153,   165,
       0,   154,   155,   166,     0,   156,     0,   167,   157,   212,
       0,   168,   169,   170,   172,   171,     0,   173,   241,   243,
       0,   182,   183,   180,   181,   179,     0,    92,    58,    60,
      97,    80,    96,    98,     0,    90,     0,    86,     0,     0,
     289,   242,   244,   296,   297,   300,   299,     0,     0,     0,
      16,     0,   302,   303,     0,   289,     0,   136,     0,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,   348,     0,     0,     0,   219,     0,   223,
       0,     0,     0,     0,   210,   221,     0,     0,   150,   175,
       0,   143,   145,   149,   228,   176,   178,   202,     0,     0,
     214,   217,   211,   213,     0,     0,   104,     0,     0,     0,
     100,    91,    89,    95,   250,   279,     0,   267,   273,     0,
     268,     0,     0,     0,    18,    19,   240,   138,   137,     0,
     249,   248,   280,     0,   264,     0,   247,   262,   246,   263,
     278,     0,     0,   310,   311,   312,   314,   315,   317,   318,
     319,   322,   324,   321,   323,     0,   325,   327,   328,   330,
     332,   334,   336,   338,     0,   343,     0,   225,   220,   224,
       0,     0,     0,     0,   229,   232,   230,   222,   240,   151,
       0,     0,   215,     0,     0,   105,   101,   115,   239,   106,
     289,     0,     0,     0,   102,     0,     0,   274,   269,   272,
     270,   271,   252,     0,   306,     0,     0,   307,   139,   141,
     281,     0,   286,     0,   287,   254,     0,     0,     0,   201,
       0,     0,   235,   233,   231,     0,   218,     0,   216,   215,
       0,   103,     0,   107,     0,     0,   108,   284,     0,   275,
       0,   251,   305,   308,   266,   265,   282,     0,   255,   256,
     340,     0,   186,     0,   152,     0,   159,   160,     0,   161,
     162,     0,     0,   189,     0,     0,     0,     0,   227,   226,
       0,   109,     0,     0,   285,   259,     0,   283,   257,     0,
       0,   177,   203,     0,     0,     0,   190,     0,   194,     0,
     197,     0,     0,   207,     0,     0,   110,     0,   261,     0,
     187,   215,     0,   200,   350,     0,   192,   195,     0,   191,
     196,   198,   234,   205,   206,     0,     0,   111,     0,     0,
     215,   199,   193,   113,     0,     0,     0,     0,   112,     0,
     209,     0,   188,   208,     0,     0,     0
};

static const short yydefgoto[] =
{
     604,   175,   232,   176,    71,    72,    57,    50,   177,   178,
      21,    22,    23,     7,     8,     9,    10,    11,    12,    13,
      14,   237,   238,   111,    88,    41,    59,    87,   109,   133,
     134,   135,    77,    95,    96,    97,   179,   137,    78,    93,
     150,   151,   115,   153,   281,   139,   140,   141,   142,   380,
     461,   462,    17,    38,    60,    55,    90,    39,    53,    80,
      81,    82,    83,   180,   310,   239,   580,   241,   242,   243,
     244,   523,   245,   246,   247,   248,   526,   249,   250,   251,
     252,   527,   253,   533,   557,   558,   559,   560,   254,   255,
     529,   256,   257,   258,   530,   259,   260,   372,   497,   498,
     261,   262,   263,   264,   265,   266,   267,   444,   445,   446,
     181,   182,   183,   184,   185,   510,   546,   186,   403,   187,
     387,   388,   101,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   344,   404,
     575
};

static const short yypact[] =
{
     248,-32768,   -49,   -49,   -49,   -49,-32768,-32768,   283,   102,
     283,-32768,-32768,-32768,-32768,   157,-32768,-32768,-32768,-32768,
     374,-32768,-32768,-32768,   -18,    80,   379,   102,-32768,-32768,
     283,   102,-32768,   -49,   -49,-32768,    14,   -49,    53,    59,
     -49,   116,-32768,   -49,   102,   -18,    80,    81,-32768,-32768,
  -32768,    98,   639,-32768,   -49,    53,-32768,-32768,   -49,-32768,
      53,    59,   116,-32768,-32768,   -49,-32768,-32768,-32768,   -49,
     154,-32768,-32768,-32768,    39,   898,-32768,-32768,   169,-32768,
     827,-32768,-32768,-32768,-32768,-32768,-32768,   156,   190,-32768,
      53,-32768,   183,   -20,   183,    91,-32768,   -10,   -20,   192,
     198,   198,   -49,   -49,-32768,-32768,-32768,   -49,   263,-32768,
  -32768,   190,   343,   -49,   209,-32768,-32768,   -49,  1582,   234,
  -32768,-32768,   268,   -20,   300,   -20,-32768,   266,  2455,-32768,
     291,   898,-32768,   546,-32768,-32768,-32768,-32768,   112,-32768,
     284,-32768,   336,-32768,-32768,-32768,-32768,-32768,   -49,   467,
      87,-32768,-32768,   333,-32768,-32768,-32768,  2254,  2254,  2254,
    2254,   339,   342,   243,-32768,  2254,  2254,  2254,  1453,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,   136,   351,   486,-32768,
  -32768,   354,   384,-32768,-32768,-32768,   -49,-32768,   373,-32768,
     377,   378,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   216,
     485,   345,   185,   478,   502,   508,   510,   512,    -8,-32768,
  -32768,-32768,   473,-32768,-32768,-32768,-32768,-32768,-32768,   440,
     443,  2254,-32768,   -46,  1633,   447,   452,   284,   454,    93,
    2254,-32768,   -49,   136,   351,   370,   463,   429,-32768,-32768,
    2522,-32768,-32768,   455,-32768,-32768,-32768,  2924,-32768,-32768,
     459,-32768,-32768,-32768,  2924,-32768,  2924,-32768,-32768,  3042,
     462,-32768,-32768,-32768,-32768,-32768,   474,-32768,   170,   205,
     378,   524,   548,-32768,-32768,-32768,   449,   336,-32768,-32768,
  -32768,-32768,-32768,-32768,   487,   476,   -49,-32768,   477,   -49,
     271,-32768,-32768,-32768,-32768,-32768,-32768,   513,   -49,   491,
     491,   497,-32768,-32768,   286,   486,   507,-32768,   514,-32768,
     158,   539,   541,  1694,  1745,   141,     9,  2254,   516,-32768,
  -32768,  2254,  2254,  2254,  2254,  2254,  2254,  2254,  2254,  2254,
    2254,  2254,  2254,   243,  2254,  2254,  2254,  2254,  2254,  2254,
    2254,  2254,-32768,-32768,  2254,  2254,   522,-32768,   523,-32768,
     525,  2254,  2254,   332,-32768,-32768,   526,   532,   530,-32768,
     -49,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   569,   467,
  -32768,-32768,-32768,   538,  1806,  2254,-32768,   214,   487,  2589,
     549,   476,-32768,-32768,-32768,   554,  1745,   491,-32768,   406,
     491,   406,  1857,  2254,    44,   222,  1257,-32768,-32768,  1521,
  -32768,-32768,-32768,   239,-32768,   551,-32768,-32768,-32768,-32768,
     559,   556,  1918,-32768,-32768,-32768,   216,   216,   485,   485,
     485,   345,   345,   345,   345,   154,-32768,   185,   185,   478,
     502,   508,   510,   512,   568,-32768,   563,-32768,-32768,-32768,
     566,   570,   573,   284,   332,-32768,-32768,-32768,-32768,   530,
     576,  1050,  1050,   564,   578,-32768,   571,   342,   580,-32768,
     715,  2656,   581,  2723,-32768,  1969,   583,-32768,   198,-32768,
     198,-32768,   584,   277,-32768,  2254,  1257,-32768,-32768,-32768,
  -32768,  1402,-32768,  2030,-32768,   190,   294,  2254,  2991,-32768,
     589,   477,-32768,-32768,-32768,  2254,-32768,   582,   538,  1050,
      24,-32768,   309,-32768,  2790,  2081,-32768,-32768,   341,-32768,
     190,   592,-32768,-32768,-32768,-32768,-32768,   344,-32768,   190,
  -32768,   597,-32768,   637,   643,  2991,-32768,-32768,  2991,-32768,
  -32768,   596,   -21,-32768,   609,   610,  2924,   615,-32768,-32768,
     617,-32768,   613,   353,-32768,-32768,   190,-32768,-32768,  2254,
    2924,-32768,-32768,  2142,   626,  2254,-32768,   -11,-32768,  2321,
  -32768,   284,   616,-32768,  2924,  2193,-32768,   619,-32768,   625,
  -32768,  1050,   623,-32768,-32768,   635,-32768,-32768,  2388,-32768,
    2857,-32768,-32768,-32768,-32768,   627,   376,-32768,  2991,   633,
    1050,-32768,-32768,-32768,   630,   675,  2991,   638,-32768,  2991,
  -32768,  2991,-32768,-32768,   734,   735,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,    -1,   375,   404,    54,  -102,    19,    23,    82,
     -27,-32768,    -3,-32768,   728,   167,-32768,   144,-32768,-32768,
     253,     5,   796,-32768,-32768,   694,   679,-32768,   -87,-32768,
     618,-32768,   -65,   -99,   629,  -139,  -166,-32768,    20,   -43,
     471,  -280,   -53,-32768,-32768,-32768,-32768,-32768,   622,   371,
  -32768,-32768,    63,-32768,-32768,-32768,-32768,   703,     3,-32768,
     676,-32768,-32768,   128,-32768,   -69,  -125,  -228,-32768,   499,
     181,  -298,  -478,   258,  -472,-32768,-32768,-32768,  -253,-32768,
  -32768,-32768,-32768,-32768,-32768,   202,   204,  -511,  -433,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,  -423,-32768,  -481,   503,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   319,   321,
  -32768,-32768,-32768,    88,-32768,-32768,-32768,-32768,  -233,-32768,
     466,    56,   -26,  1059,   193,  1090,   251,   381,   439,  -137,
     544,   614,  -379,-32768,   275,   203,   288,   270,   431,   433,
     430,   435,   432,-32768,   298,   434,   732,-32768,-32768,   855,
  -32768
};


#define	YYLAST		3152


static const short yytable[] =
{
      24,    25,   309,   240,   124,    15,   371,   340,   382,   285,
     524,   152,   362,    15,    15,    15,   525,   477,   537,    47,
     293,   294,   295,   296,   146,   538,    98,   554,   302,   303,
      45,    46,    15,    48,   113,    15,    15,   554,    19,   144,
      48,    19,   555,   136,   100,   120,    37,   524,   581,    15,
     524,    69,   555,   525,   347,   528,   525,    75,    85,   123,
     125,   301,    92,    89,   144,   531,    94,   581,   136,   282,
     216,   283,   218,    84,   103,    73,   556,    86,   114,    69,
     341,   130,   409,   118,    20,    75,   576,    26,   119,   284,
     589,    49,   528,   110,    56,   528,    19,   513,    73,    92,
      94,    19,   531,    73,   130,   531,   130,    69,    49,   597,
     524,   148,    49,   131,   155,    79,   525,   149,   524,    51,
     128,   524,    51,   524,   525,   236,   126,   525,   138,   525,
     103,    73,    69,   358,    74,    73,    51,    99,   131,   475,
      51,    43,   122,    79,    40,   155,     1,   381,   286,    52,
     100,   234,    28,   138,    73,   528,    73,    74,   353,   473,
      54,    49,    74,   528,     3,   531,   528,    56,   528,    58,
       4,   143,    73,   531,    28,    27,   531,    31,   531,   486,
      19,    63,   287,   318,   413,   414,   415,   383,   288,    51,
      74,   116,   117,   355,    74,    51,   143,    44,   496,   371,
      43,    32,     6,   329,   330,   331,   332,   100,   128,   406,
     235,   534,   280,    74,   407,    74,   268,   300,   408,    33,
     348,   321,   322,   323,   378,    34,   356,   551,    19,   155,
     552,    74,   508,   479,    99,   362,   360,   236,   311,   290,
     290,   290,   290,   333,   236,    51,   371,   290,   290,   305,
     517,   236,    99,   236,   463,   398,   474,   107,    18,   399,
      73,   449,    29,   234,   369,  -185,    18,    18,    18,   104,
    -185,  -185,   543,   389,   391,   148,   362,   112,   394,   395,
      29,   149,   234,   155,    29,    18,   108,   148,    18,    18,
     595,   121,     1,   149,    64,   385,   122,    29,   600,    73,
    -184,   602,    18,   603,     2,  -184,  -184,   127,   154,   455,
       3,    73,    48,   410,    64,   288,     4,   476,   371,    74,
     122,   269,   235,    65,     5,     3,    66,     1,   268,    67,
      19,     4,   586,   214,   480,   268,   504,   371,   512,     2,
     481,   235,   268,    56,   268,     3,    66,   268,     6,    67,
      19,     4,   362,   326,   327,   328,    73,   155,    74,   128,
     129,   468,   -99,     6,   470,   313,   145,   215,   360,   314,
      74,    51,   511,   315,   492,   540,   236,   406,   481,   270,
     128,   393,   407,     6,    99,   276,   408,     1,   311,   519,
     113,   145,    73,   442,    64,   481,    19,   443,   518,   100,
     217,   117,   234,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,    74,   290,   290,   290,   290,
     290,   290,   290,   545,   319,   320,    66,    70,   365,    67,
      19,   539,   548,   269,   289,   367,   544,   368,   147,   547,
     269,   297,   481,   467,   298,   481,   467,   269,   567,   269,
      70,    74,   269,   312,   481,    70,   316,   -15,   236,   568,
     236,   460,  -344,  -344,   313,  -345,  -345,   268,   314,  -346,
    -346,   594,   315,    32,    35,   290,    36,   481,   290,    42,
      64,    43,   317,    70,   234,   236,   234,    70,   324,   325,
     148,   270,   582,     1,   334,   335,   149,    34,   270,    48,
      64,   236,   168,   233,   122,   270,    70,   270,    70,   271,
     270,    32,    66,   336,    73,    67,    19,   469,    64,   471,
     337,     1,   236,   338,    70,   236,   339,   234,    64,   418,
     419,   420,    66,   236,  -228,    67,    19,   345,   299,   268,
     268,   351,   304,   235,   376,   235,   352,   236,   354,   268,
      66,   268,   359,    67,    19,   363,   236,   290,   290,   366,
      66,   236,   374,    67,    19,   342,   343,   272,   375,   290,
    -290,  -290,   269,    74,   119,   236,   268,   236,  -344,  -344,
     313,   384,   234,   379,   314,   236,   235,   268,   315,   386,
     127,   392,   268,   236,  -291,  -291,   236,    64,   236,   416,
     417,   234,   396,   234,   427,   428,    65,   400,     3,   401,
     412,   397,    70,   268,     4,   233,   268,   421,   422,   423,
     424,   271,   437,   438,   268,   439,   447,   448,   271,    66,
     270,   117,    67,    19,   233,   271,   450,   271,   268,   451,
     271,   235,   128,   278,   269,   269,     6,   268,   465,   464,
     482,    70,   268,   483,   269,   484,   269,   487,   488,   268,
     235,   489,   235,    70,   499,   490,   268,   491,   268,   522,
     495,   501,   273,   500,  -114,   505,   268,   536,   268,   272,
    -258,   269,   509,     1,   268,   532,   272,   268,  -260,   268,
      64,   549,   269,   272,   550,   272,   553,   269,   272,    65,
    -158,     3,   270,   270,   561,   562,   365,     4,   425,   367,
     564,   565,   270,   566,   270,   573,   583,   563,   269,   587,
     588,   269,    66,   590,   591,    67,    19,   593,   596,   269,
     598,   570,   599,   601,   605,   606,    68,   426,    30,   270,
      62,    91,   274,   269,    70,   584,   156,   377,    61,   456,
     270,   279,   269,   277,   233,   270,   106,   269,   370,   577,
     271,   578,   373,   493,   269,   494,   390,   429,   431,   522,
     430,   269,   433,   269,   432,     0,   270,   563,   435,   270,
     570,   269,   584,   269,   273,   520,     0,   270,     0,   269,
       0,   273,   269,     0,   269,     0,    16,     0,   273,     0,
     273,   270,   -15,   273,    16,    16,    16,  -344,  -344,   313,
     270,     0,     0,   314,     0,   270,     0,   502,   272,     0,
       0,     0,   270,    16,     0,     0,    16,    16,     0,   270,
       0,   270,   271,   271,     0,     0,   233,     0,   233,   270,
      16,   270,   271,     0,   271,     0,     0,   270,    76,     0,
     270,     0,   270,     0,   274,     0,     0,     0,     0,     0,
     275,   274,     0,     0,     0,     0,    70,     0,   274,   271,
     274,     1,     0,   274,     0,     0,    76,     0,    64,   233,
     271,     0,     0,     0,     0,   271,     0,    65,     0,     3,
     272,   272,     0,     0,     0,     4,     0,     0,     0,     0,
     272,     0,   272,     0,   132,     0,   271,     0,     0,   271,
      66,     0,     0,    67,    19,     0,     0,   271,     0,     0,
       0,     0,     0,   273,   105,     0,     0,   272,     0,   132,
       0,   271,     0,     0,   233,     0,     0,     0,   272,     0,
     271,     0,    32,   272,     0,   271,     0,     0,     0,    64,
       0,     0,   271,   233,     0,   233,     0,     0,   102,   271,
      33,   271,     0,     0,   272,     0,    34,   272,     0,   271,
       0,   271,   275,   213,     0,   272,     0,   271,     0,   275,
     271,    66,   271,     0,    67,    19,   275,     0,   275,   272,
       0,   275,     0,   274,     0,   273,   273,     0,   272,     0,
       0,     0,     0,   272,     0,   273,     0,   273,     0,     0,
     272,     0,     0,     0,     0,     0,     0,   272,     0,   272,
       0,     0,   306,   213,     0,     0,     0,   272,     0,   272,
       0,     0,   273,     0,     0,   272,     0,     0,   272,     0,
     272,     0,     0,   273,     0,     0,     0,     0,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,   274,     0,     0,   273,
       0,     0,   273,     0,     0,   274,   346,   274,     0,   350,
     273,     0,     0,     0,     0,   357,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,   159,   160,     0,     0,
       0,    64,   274,   273,     0,     0,     0,     0,   273,     0,
     161,   275,     0,   274,     0,   273,   162,     0,   274,     0,
       0,     0,   273,   163,   273,     0,     0,   164,     0,     0,
       0,     0,   273,    66,   273,     0,    67,    19,     0,   274,
     273,     0,   274,   273,   230,   273,     0,     0,     0,     0,
     274,     0,     0,   169,   170,   171,   172,     0,     0,   173,
     174,     0,     0,     0,   274,     0,     0,     0,     0,   405,
       0,     0,   411,   274,     0,     0,     0,     0,   274,     0,
       0,     0,     0,   275,   275,   274,     0,     0,     0,     0,
       0,     0,   274,   275,   274,   275,   434,     0,     0,     0,
     436,     0,   274,     0,   274,     0,   440,   441,     0,     0,
     274,     0,     0,   274,     0,   274,   291,   291,   291,   291,
     275,     0,     0,     0,   291,   291,     0,     0,     0,   453,
     454,   275,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   466,     0,     0,     0,     0,     0,   292,   292,   292,
     292,     0,     0,     0,   213,   292,   292,   275,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   275,     0,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,    64,     0,
     275,     0,   275,     0,     0,     0,     0,   161,     0,     0,
     275,     0,   275,   162,     0,     0,     0,     0,   275,     0,
     163,   275,     0,   275,   164,     0,   515,     0,     0,     0,
      66,     0,     0,    67,    19,     0,     0,   165,   166,     0,
     535,   167,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,     0,     0,   173,   174,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,     0,   291,   291,   291,   291,   291,   291,   291,
       0,     0,     0,   514,   569,   157,   158,     0,   572,     0,
     574,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,     0,   292,   292,   292,   292,   292,   292,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
       0,     0,   291,    64,     0,   291,   157,   158,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,     0,     0,   292,     0,    66,   292,     0,    67,    19,
       0,     0,   165,   166,     0,     0,   167,     0,     0,   159,
     160,     0,     0,     0,    64,   169,   170,   171,   172,     0,
       0,   173,   174,   161,     0,     0,     0,     0,     0,   162,
       0,     0,     0,     0,   157,   158,   163,     0,     0,     0,
     164,     0,     0,     0,   291,   291,    66,     0,     0,    67,
      19,     0,     0,   165,   166,     0,   291,   167,     0,   168,
     307,     0,     0,     0,   308,     0,   169,   170,   171,   172,
       0,     0,   173,   174,     0,   292,   292,   159,   160,     0,
       0,     0,    64,     0,     0,     0,     0,   292,     0,     0,
       0,   161,     0,     0,     0,   157,   158,   162,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,   164,     0,
       0,     0,     0,     0,    66,     0,     0,    67,    19,     0,
       0,   165,   166,     0,     0,   167,     0,   168,   478,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   159,   160,
     173,   174,     0,    64,     0,     0,   157,   158,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,     0,     0,     0,     0,    66,     0,     0,    67,    19,
       0,     0,   165,   166,     0,     0,   167,     0,   168,   159,
     160,     0,     0,     0,    64,   169,   170,   171,   172,     0,
       0,   173,   174,   161,     0,     0,     0,   157,   158,   162,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
     164,     0,     0,     0,     0,     0,    66,     0,     0,    67,
      19,     0,     0,   165,   166,     0,     0,   167,     0,     0,
       0,     0,     0,   349,     0,     0,   169,   170,   171,   172,
     159,   160,   173,   174,     0,    64,     0,     0,   157,   158,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164,     0,     0,     0,     0,     0,    66,     0,     0,
      67,    19,     0,     0,   165,   166,     0,     0,   167,   402,
       0,   159,   160,     0,     0,     0,    64,   169,   170,   171,
     172,     0,     0,   173,   174,   161,     0,     0,     0,   157,
     158,   162,     0,     0,     0,     0,     0,     0,   163,     0,
       0,     0,   164,     0,     0,     0,     0,     0,    66,     0,
       0,    67,    19,     0,     0,   165,   166,     0,     0,   167,
       0,     0,     0,     0,   121,     0,     0,     0,   169,   170,
     171,   172,   159,   160,   173,   174,     0,    64,     0,     0,
     157,   158,     0,     0,     0,     0,   161,     0,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,   163,
       0,     0,     0,   164,     0,     0,     0,     0,     0,    66,
       0,     0,    67,    19,     0,     0,   165,   166,     0,     0,
     167,     0,     0,   159,   160,     0,   452,     0,    64,   169,
     170,   171,   172,     0,     0,   173,   174,   161,     0,     0,
       0,   157,   158,   162,     0,     0,     0,     0,     0,     0,
     163,     0,     0,     0,   164,     0,     0,     0,     0,     0,
      66,     0,     0,    67,    19,     0,     0,   165,   166,     0,
       0,   167,   472,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   159,   160,   173,   174,     0,    64,
       0,     0,   157,   158,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   164,     0,     0,     0,     0,
       0,    66,     0,     0,    67,    19,     0,     0,   165,   166,
       0,     0,   167,   485,     0,   159,   160,     0,     0,     0,
      64,   169,   170,   171,   172,     0,     0,   173,   174,   161,
       0,     0,     0,   157,   158,   162,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   164,     0,     0,     0,
       0,     0,    66,     0,     0,    67,    19,     0,     0,   165,
     166,     0,     0,   167,   507,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   159,   160,   173,   174,
       0,    64,     0,     0,   157,   158,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,   164,     0,     0,
       0,     0,     0,    66,     0,     0,    67,    19,     0,     0,
     165,   166,     0,     0,   167,   516,     0,   159,   160,     0,
       0,     0,    64,   169,   170,   171,   172,     0,     0,   173,
     174,   161,     0,     0,     0,   157,   158,   162,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,   164,     0,
       0,     0,     0,     0,    66,     0,     0,    67,    19,     0,
       0,   165,   166,     0,     0,   167,   542,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   159,   160,
     173,   174,     0,    64,     0,     0,   157,   158,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,     0,     0,     0,     0,    66,     0,     0,    67,    19,
       0,     0,   165,   166,     0,     0,   167,     0,     0,   159,
     160,     0,   571,     0,    64,   169,   170,   171,   172,     0,
       0,   173,   174,   161,     0,     0,     0,   157,   158,   162,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
     164,     0,     0,     0,     0,     0,    66,     0,     0,    67,
      19,     0,     0,   165,   166,     0,     0,   167,   585,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     159,   160,   173,   174,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164,     0,     0,     0,     0,     0,    66,     0,     0,
      67,    19,     0,     0,   165,   166,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,     0,     0,   173,   174,   219,     0,   159,   160,   554,
     220,   221,    64,   222,     0,     0,   223,     0,     0,     0,
     224,   161,     0,     0,   555,     0,     0,   162,   225,     4,
     226,     0,   227,   228,   163,   229,     0,     0,   164,     0,
       0,     0,     0,     0,    66,     0,     0,    67,    19,     0,
       0,     0,     0,     0,     0,   230,     0,   128,   579,     0,
       0,     6,     0,     0,   169,   170,   171,   172,     0,     0,
     173,   174,   219,     0,   159,   160,   554,   220,   221,    64,
     222,     0,     0,   223,     0,     0,     0,   224,   161,     0,
       0,   555,     0,     0,   162,   225,     4,   226,     0,   227,
     228,   163,   229,     0,     0,   164,     0,     0,     0,     0,
       0,    66,     0,     0,    67,    19,     0,     0,     0,     0,
       0,     0,   230,     0,   128,   592,     0,     0,     6,     0,
       0,   169,   170,   171,   172,     0,     0,   173,   174,   219,
       0,   159,   160,     0,   220,   221,    64,   222,     0,     0,
     223,     0,     0,     0,   224,   161,     0,     0,     0,     0,
       0,   162,   225,     4,   226,     0,   227,   228,   163,   229,
       0,     0,   164,     0,     0,     0,     0,     0,    66,     0,
       0,    67,    19,     0,     0,     0,     0,     0,     0,   230,
       0,   128,   231,     0,     0,     6,     0,     0,   169,   170,
     171,   172,     0,     0,   173,   174,   219,     0,   159,   160,
       0,   220,   221,    64,   222,     0,     0,   223,     0,     0,
       0,   224,   161,     0,     0,     0,     0,     0,   162,   225,
       4,   226,     0,   227,   228,   163,   229,     0,     0,   164,
       0,     0,     0,     0,     0,    66,     0,     0,    67,    19,
       0,     0,     0,     0,     0,     0,   230,     0,   128,   361,
       0,     0,     6,     0,     0,   169,   170,   171,   172,     0,
       0,   173,   174,   219,     0,   159,   160,     0,   220,   221,
      64,   222,     0,     0,   223,     0,     0,     0,   224,   161,
       0,     0,     0,     0,     0,   457,   225,     4,   226,     0,
     227,   228,   163,   229,     0,     0,   458,     0,     0,     0,
       0,     0,    66,     0,     0,    67,    19,     0,     0,     0,
       0,     0,     0,   230,     0,   128,   459,     0,     0,     6,
       0,     0,   169,   170,   171,   172,     0,     0,   173,   174,
     219,     0,   159,   160,     0,   220,   221,    64,   222,     0,
       0,   223,     0,     0,     0,   224,   161,     0,     0,     0,
       0,     0,   162,   225,     4,   226,     0,   227,   228,   163,
     229,     0,     0,   164,     0,     0,     0,     0,     0,    66,
       0,     0,    67,    19,     0,     0,     0,     0,     0,     0,
     230,     0,   128,   503,     0,     0,     6,     0,     0,   169,
     170,   171,   172,     0,     0,   173,   174,   219,     0,   159,
     160,     0,   220,   221,    64,   222,     0,     0,   223,     0,
       0,     0,   224,   161,     0,     0,     0,     0,     0,   162,
     225,     4,   226,     0,   227,   228,   163,   229,     0,     0,
     164,     0,     0,     0,     0,     0,    66,     0,     0,    67,
      19,     0,     0,     0,     0,     0,     0,   230,     0,   128,
     506,     0,     0,     6,     0,     0,   169,   170,   171,   172,
       0,     0,   173,   174,   219,     0,   159,   160,     0,   220,
     221,    64,   222,     0,     0,   223,     0,     0,     0,   224,
     161,     0,     0,     0,     0,     0,   162,   225,     4,   226,
       0,   227,   228,   163,   229,     0,     0,   164,     0,     0,
       0,     0,     0,    66,     0,     0,    67,    19,     0,     0,
       0,     0,     0,     0,   230,     0,   128,   541,     0,     0,
       6,     0,     0,   169,   170,   171,   172,     0,     0,   173,
     174,   219,     0,   159,   160,     0,   220,   221,    64,   222,
       0,     0,   223,     0,     0,     0,   224,   161,     0,     0,
       0,     0,     0,   162,   225,     4,   226,     0,   227,   228,
     163,   229,     0,     0,   164,     0,     0,     0,     0,     0,
      66,     0,     0,    67,    19,     0,     0,     0,     0,     0,
       0,   230,     0,   128,     0,     0,     0,     6,     0,     0,
     169,   170,   171,   172,     0,     0,   173,   174,   364,     0,
     159,   160,     0,   220,   221,    64,   222,     0,     0,   223,
       0,     0,     0,   224,   161,     0,     0,     0,     0,     0,
     162,   225,     0,   226,     0,   227,   228,   163,   229,     0,
       0,   164,     0,     0,     0,     0,     0,    66,     0,     0,
      67,    19,     0,     0,     0,     0,     0,     0,   230,     0,
     128,     0,     0,     0,     6,     0,     0,   169,   170,   171,
     172,     0,     0,   173,   174,   364,     0,   159,   160,     0,
     521,   221,    64,   222,     0,     0,   223,     0,     0,     0,
     224,   161,     0,     0,     0,     0,     0,   162,   225,     0,
     226,     0,   227,   228,   163,   229,     0,     0,   164,     0,
       0,     0,     0,     0,    66,     0,     0,    67,    19,     0,
       0,     0,     0,     0,     0,   230,     1,   128,   159,   160,
       0,     6,     0,    64,   169,   170,   171,   172,     0,     0,
     173,   174,   161,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,   163,     0,     0,     0,   164,
       0,     0,     0,     0,     0,    66,     0,     0,    67,    19,
       0,     0,     0,     0,     0,     0,   230,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,     0,
       0,   173,   174
};

static const short yycheck[] =
{
       3,     4,   168,   128,   103,     0,   259,    15,   288,   148,
     488,   113,   240,     8,     9,    10,   488,   396,   499,     5,
     157,   158,   159,   160,   111,     1,    69,    48,   165,   166,
      33,    34,    27,    36,    54,    30,    31,    48,    87,   108,
      43,    87,    63,   108,    70,    98,    64,   525,   559,    44,
     528,    52,    63,   525,   100,   488,   528,    52,    55,   102,
     103,   163,    65,    60,   133,   488,    69,   578,   133,   138,
     123,   140,   125,    54,    75,    52,    97,    58,    98,    80,
      88,   108,    73,    93,     2,    80,    97,     5,    98,   142,
     571,    37,   525,    90,    40,   528,    87,   476,    75,   102,
     103,    87,   525,    80,   131,   528,   133,   108,    54,   590,
     588,   112,    58,   108,   117,    52,   588,   112,   596,    37,
      96,   599,    40,   601,   596,   128,   107,   599,   108,   601,
     131,   108,   133,   232,    52,   112,    54,    98,   133,    95,
      58,   102,    98,    80,    64,   148,    44,   286,   149,    96,
     176,   128,     8,   133,   131,   588,   133,    75,   227,   392,
     101,   107,    80,   596,    62,   588,   599,   113,   601,    53,
      68,   108,   149,   596,    30,     8,   599,    10,   601,   412,
      87,   100,    95,   186,   321,   322,   323,   289,   101,   107,
     108,   100,   101,   100,   112,   113,   133,    30,   451,   452,
     102,    44,   100,    18,    19,    20,    21,   233,    96,    68,
     128,   491,   100,   131,    73,   133,   128,   163,    77,    62,
     223,     5,     6,     7,   277,    68,   229,   525,    87,   232,
     528,   149,   465,   399,    98,   463,   237,   240,   102,   157,
     158,   159,   160,    58,   247,   163,   499,   165,   166,   167,
     483,   254,    98,   256,   379,    97,   393,   101,     0,   101,
     237,   360,     9,   240,   259,    95,     8,     9,    10,   100,
     100,   101,   505,   299,   300,   276,   504,    94,   304,   305,
      27,   276,   259,   286,    31,    27,    96,   288,    30,    31,
     588,    99,    44,   288,    51,   298,    98,    44,   596,   276,
      95,   599,    44,   601,    56,   100,   101,    44,    99,    95,
      62,   288,   315,   316,    51,   101,    68,    95,   571,   237,
      98,   128,   240,    60,    76,    62,    83,    44,   240,    86,
      87,    68,   565,    99,    95,   247,   461,   590,   475,    56,
     101,   259,   254,   289,   256,    62,    83,   259,   100,    86,
      87,    68,   580,     8,     9,    10,   333,   360,   276,    96,
      97,   387,    96,   100,   390,    94,   108,    99,   369,    98,
     288,   289,    95,   102,   443,    66,   379,    68,   101,   128,
      96,    95,    73,   100,    98,    94,    77,    44,   102,    95,
      54,   133,   369,    61,    51,   101,    87,    65,   485,   425,
     100,   101,   379,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   510,    46,    47,    83,    52,   247,    86,
      87,   500,   519,   240,   101,   254,    95,   256,    95,    95,
     247,   102,   101,   387,   102,   101,   390,   254,    95,   256,
      75,   369,   259,   102,   101,    80,   102,    87,   461,   546,
     463,   379,    92,    93,    94,    92,    93,   379,    98,    92,
      93,    95,   102,    44,   100,   393,   102,   101,   396,   100,
      51,   102,    98,   108,   461,   488,   463,   112,     3,     4,
     491,   240,   561,    44,    16,    17,   491,    68,   247,   502,
      51,   504,    96,   128,    98,   254,   131,   256,   133,   128,
     259,    44,    83,    11,   491,    86,    87,   389,    51,   391,
      12,    44,   525,    13,   149,   528,    14,   504,    51,   326,
     327,   328,    83,   536,    94,    86,    87,    94,   163,   451,
     452,    94,   167,   461,    95,   463,    94,   550,    94,   461,
      83,   463,    89,    86,    87,   100,   559,   475,   476,   100,
      83,   564,   100,    86,    87,    92,    93,   128,    94,   487,
      46,    47,   379,   491,    98,   578,   488,   580,    92,    93,
      94,    68,   559,    96,    98,   588,   504,   499,   102,    98,
      44,    94,   504,   596,    46,    47,   599,    51,   601,   324,
     325,   578,    95,   580,   334,   335,    60,    68,    62,    68,
      94,    97,   237,   525,    68,   240,   528,   329,   330,   331,
     332,   240,   100,   100,   536,   100,   100,    95,   247,    83,
     379,   101,    86,    87,   259,   254,    67,   256,   550,   101,
     259,   559,    96,    97,   451,   452,   100,   559,    94,   100,
      99,   276,   564,    94,   461,    99,   463,    89,    95,   571,
     578,    95,   580,   288,   100,    95,   578,    94,   580,   488,
      94,   100,   128,    95,    94,    94,   588,    95,   590,   240,
      96,   488,    99,    44,   596,    96,   247,   599,    96,   601,
      51,    94,   499,   254,    57,   256,   100,   504,   259,    60,
      57,    62,   451,   452,    95,    95,   525,    68,   333,   528,
      95,    94,   461,   100,   463,    89,   100,   536,   525,   100,
      95,   528,    83,   100,    89,    86,    87,   100,    95,   536,
     100,   550,    57,    95,     0,     0,    97,   333,    10,   488,
      46,    62,   128,   550,   369,   564,   117,   276,    45,   378,
     499,   133,   559,   131,   379,   504,    80,   564,   259,   557,
     379,   557,   259,   444,   571,   444,   300,   336,   338,   588,
     337,   578,   340,   580,   339,    -1,   525,   596,   344,   528,
     599,   588,   601,   590,   240,   487,    -1,   536,    -1,   596,
      -1,   247,   599,    -1,   601,    -1,     0,    -1,   254,    -1,
     256,   550,    87,   259,     8,     9,    10,    92,    93,    94,
     559,    -1,    -1,    98,    -1,   564,    -1,   102,   379,    -1,
      -1,    -1,   571,    27,    -1,    -1,    30,    31,    -1,   578,
      -1,   580,   451,   452,    -1,    -1,   461,    -1,   463,   588,
      44,   590,   461,    -1,   463,    -1,    -1,   596,    52,    -1,
     599,    -1,   601,    -1,   240,    -1,    -1,    -1,    -1,    -1,
     128,   247,    -1,    -1,    -1,    -1,   491,    -1,   254,   488,
     256,    44,    -1,   259,    -1,    -1,    80,    -1,    51,   504,
     499,    -1,    -1,    -1,    -1,   504,    -1,    60,    -1,    62,
     451,   452,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
     461,    -1,   463,    -1,   108,    -1,   525,    -1,    -1,   528,
      83,    -1,    -1,    86,    87,    -1,    -1,   536,    -1,    -1,
      -1,    -1,    -1,   379,    97,    -1,    -1,   488,    -1,   133,
      -1,   550,    -1,    -1,   559,    -1,    -1,    -1,   499,    -1,
     559,    -1,    44,   504,    -1,   564,    -1,    -1,    -1,    51,
      -1,    -1,   571,   578,    -1,   580,    -1,    -1,    60,   578,
      62,   580,    -1,    -1,   525,    -1,    68,   528,    -1,   588,
      -1,   590,   240,   118,    -1,   536,    -1,   596,    -1,   247,
     599,    83,   601,    -1,    86,    87,   254,    -1,   256,   550,
      -1,   259,    -1,   379,    -1,   451,   452,    -1,   559,    -1,
      -1,    -1,    -1,   564,    -1,   461,    -1,   463,    -1,    -1,
     571,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,   580,
      -1,    -1,   167,   168,    -1,    -1,    -1,   588,    -1,   590,
      -1,    -1,   488,    -1,    -1,   596,    -1,    -1,   599,    -1,
     601,    -1,    -1,   499,    -1,    -1,    -1,    -1,   504,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   451,   452,    -1,    -1,   525,
      -1,    -1,   528,    -1,    -1,   461,   221,   463,    -1,   224,
     536,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   550,    -1,    46,    47,    -1,    -1,
      -1,    51,   488,   559,    -1,    -1,    -1,    -1,   564,    -1,
      60,   379,    -1,   499,    -1,   571,    66,    -1,   504,    -1,
      -1,    -1,   578,    73,   580,    -1,    -1,    77,    -1,    -1,
      -1,    -1,   588,    83,   590,    -1,    86,    87,    -1,   525,
     596,    -1,   528,   599,    94,   601,    -1,    -1,    -1,    -1,
     536,    -1,    -1,   103,   104,   105,   106,    -1,    -1,   109,
     110,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,   314,
      -1,    -1,   317,   559,    -1,    -1,    -1,    -1,   564,    -1,
      -1,    -1,    -1,   451,   452,   571,    -1,    -1,    -1,    -1,
      -1,    -1,   578,   461,   580,   463,   341,    -1,    -1,    -1,
     345,    -1,   588,    -1,   590,    -1,   351,   352,    -1,    -1,
     596,    -1,    -1,   599,    -1,   601,   157,   158,   159,   160,
     488,    -1,    -1,    -1,   165,   166,    -1,    -1,    -1,   374,
     375,   499,    -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,
      -1,   386,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,    -1,    -1,    -1,   399,   165,   166,   525,    -1,    -1,
     528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   559,    -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,
      -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,    51,    -1,
     578,    -1,   580,    -1,    -1,    -1,    -1,    60,    -1,    -1,
     588,    -1,   590,    66,    -1,    -1,    -1,    -1,   596,    -1,
      73,   599,    -1,   601,    77,    -1,   481,    -1,    -1,    -1,
      83,    -1,    -1,    86,    87,    -1,    -1,    90,    91,    -1,
     495,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,    -1,   334,   335,   336,   337,   338,   339,   340,
      -1,    -1,    -1,     1,   549,     3,     4,    -1,   553,    -1,
     555,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,    -1,   334,   335,   336,   337,   338,   339,
     340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,   393,    51,    -1,   396,     3,     4,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,   393,    -1,    83,   396,    -1,    86,    87,
      -1,    -1,    90,    91,    -1,    -1,    94,    -1,    -1,    46,
      47,    -1,    -1,    -1,    51,   103,   104,   105,   106,    -1,
      -1,   109,   110,    60,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,     3,     4,    73,    -1,    -1,    -1,
      77,    -1,    -1,    -1,   475,   476,    83,    -1,    -1,    86,
      87,    -1,    -1,    90,    91,    -1,   487,    94,    -1,    96,
      97,    -1,    -1,    -1,   101,    -1,   103,   104,   105,   106,
      -1,    -1,   109,   110,    -1,   475,   476,    46,    47,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    60,    -1,    -1,    -1,     3,     4,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,
      -1,    90,    91,    -1,    -1,    94,    -1,    96,    97,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,    46,    47,
     109,   110,    -1,    51,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,
      -1,    -1,    90,    91,    -1,    -1,    94,    -1,    96,    46,
      47,    -1,    -1,    -1,    51,   103,   104,   105,   106,    -1,
      -1,   109,   110,    60,    -1,    -1,    -1,     3,     4,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,
      87,    -1,    -1,    90,    91,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,   103,   104,   105,   106,
      46,    47,   109,   110,    -1,    51,    -1,    -1,     3,     4,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      86,    87,    -1,    -1,    90,    91,    -1,    -1,    94,    95,
      -1,    46,    47,    -1,    -1,    -1,    51,   103,   104,   105,
     106,    -1,    -1,   109,   110,    60,    -1,    -1,    -1,     3,
       4,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    86,    87,    -1,    -1,    90,    91,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,   103,   104,
     105,   106,    46,    47,   109,   110,    -1,    51,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    86,    87,    -1,    -1,    90,    91,    -1,    -1,
      94,    -1,    -1,    46,    47,    -1,   100,    -1,    51,   103,
     104,   105,   106,    -1,    -1,   109,   110,    60,    -1,    -1,
      -1,     3,     4,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    86,    87,    -1,    -1,    90,    91,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,   105,   106,    46,    47,   109,   110,    -1,    51,
      -1,    -1,     3,     4,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    -1,    -1,    90,    91,
      -1,    -1,    94,    95,    -1,    46,    47,    -1,    -1,    -1,
      51,   103,   104,   105,   106,    -1,    -1,   109,   110,    60,
      -1,    -1,    -1,     3,     4,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,    90,
      91,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105,   106,    46,    47,   109,   110,
      -1,    51,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,
      90,    91,    -1,    -1,    94,    95,    -1,    46,    47,    -1,
      -1,    -1,    51,   103,   104,   105,   106,    -1,    -1,   109,
     110,    60,    -1,    -1,    -1,     3,     4,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,
      -1,    90,    91,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,    46,    47,
     109,   110,    -1,    51,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,
      -1,    -1,    90,    91,    -1,    -1,    94,    -1,    -1,    46,
      47,    -1,   100,    -1,    51,   103,   104,   105,   106,    -1,
      -1,   109,   110,    60,    -1,    -1,    -1,     3,     4,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,
      87,    -1,    -1,    90,    91,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,
      46,    47,   109,   110,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      86,    87,    -1,    -1,    90,    91,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,    -1,    -1,   109,   110,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      59,    60,    -1,    -1,    63,    -1,    -1,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,    -1,
      -1,   100,    -1,    -1,   103,   104,   105,   106,    -1,    -1,
     109,   110,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    -1,    -1,   100,    -1,
      -1,   103,   104,   105,   106,    -1,    -1,   109,   110,    44,
      -1,    46,    47,    -1,    49,    50,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    -1,    -1,   100,    -1,    -1,   103,   104,
     105,   106,    -1,    -1,   109,   110,    44,    -1,    46,    47,
      -1,    49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    97,
      -1,    -1,   100,    -1,    -1,   103,   104,   105,   106,    -1,
      -1,   109,   110,    44,    -1,    46,    47,    -1,    49,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    96,    97,    -1,    -1,   100,
      -1,    -1,   103,   104,   105,   106,    -1,    -1,   109,   110,
      44,    -1,    46,    47,    -1,    49,    50,    51,    52,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    -1,    -1,   100,    -1,    -1,   103,
     104,   105,   106,    -1,    -1,   109,   110,    44,    -1,    46,
      47,    -1,    49,    50,    51,    52,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    -1,    -1,   100,    -1,    -1,   103,   104,   105,   106,
      -1,    -1,   109,   110,    44,    -1,    46,    47,    -1,    49,
      50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    -1,    -1,
     100,    -1,    -1,   103,   104,   105,   106,    -1,    -1,   109,
     110,    44,    -1,    46,    47,    -1,    49,    50,    51,    52,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    -1,    -1,    -1,   100,    -1,    -1,
     103,   104,   105,   106,    -1,    -1,   109,   110,    44,    -1,
      46,    47,    -1,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    69,    -1,    71,    72,    73,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    -1,    -1,    -1,   100,    -1,    -1,   103,   104,   105,
     106,    -1,    -1,   109,   110,    44,    -1,    46,    47,    -1,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    -1,    71,    72,    73,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    44,    96,    46,    47,
      -1,   100,    -1,    51,   103,   104,   105,   106,    -1,    -1,
     109,   110,    60,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,    -1,
      -1,   109,   110
};
#define YYPURE 1

/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#ifdef __cplusplus
# define YYSTD(x) std::x
#else
# define YYSTD(x) x
#endif

#ifndef YYPARSE_RETURN_TYPE
#define YYPARSE_RETURN_TYPE int
#endif

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  ifdef __cplusplus
#   include <cstdlib> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T std::size_t
#  else
#   ifdef __STDC__
#    include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#    define YYSIZE_T size_t
#   endif
#  endif
#  define YYSTACK_ALLOC YYSTD (malloc)
#  define YYSTACK_FREE YYSTD (free)
# endif

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Relocate the TYPE STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Type, Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	yymemcpy ((char *) yyptr, (char *) (Stack),			\
		  yysize * (YYSIZE_T) sizeof (Type));			\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (Type) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# ifdef __cplusplus
#  include <cstddef> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T std::size_t
# else
#  ifdef __STDC__
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  ifdef __cplusplus
#   include <cstdio>  /* INFRINGES ON USER NAME SPACE */
#  else
#   include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYFPRINTF YYSTD (fprintf)
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace. [The following comment makes no
   sense to me.  Could someone clarify it?  --akim] Since this is
   uninitialized, it does not stop multiple parsers from coexisting.
   */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#if ! defined (yyoverflow) && ! defined (yymemcpy)
# if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#  define yymemcpy __builtin_memcpy
# else				/* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
#  if defined (__STDC__) || defined (__cplusplus)
yymemcpy (char *yyto, const char *yyfrom, YYSIZE_T yycount)
#  else
yymemcpy (yyto, yyfrom, yycount)
     char *yyto;
     const char *yyfrom;
     YYSIZE_T yycount;
#  endif
{
  register const char *yyf = yyfrom;
  register char *yyt = yyto;
  register YYSIZE_T yyi = yycount;

  while (yyi-- != 0)
    *yyt++ = *yyf++;
}
# endif
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 345 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# ifdef __cplusplus
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else /* !__cplusplus */
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif /* !__cplusplus */
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
YYPARSE_RETURN_TYPE yyparse (void *);
# else
YYPARSE_RETURN_TYPE yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

YYPARSE_RETURN_TYPE
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

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
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (short, yyss);
	YYSTACK_RELOCATE (YYSTYPE, yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (YYLTYPE, yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 10:
#line 211 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
		  /* use preset global here. FIXME */
		  yyval.node = xstrdup ("int");
		;
    break;}
case 11:
#line 216 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
		  /* use preset global here. FIXME */
		  yyval.node = xstrdup ("double");
		;
    break;}
case 12:
#line 221 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
		  /* use preset global here. FIXME */
		  yyval.node = xstrdup ("boolean");
		;
    break;}
case 18:
#line 246 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
	          while (bracket_count-- > 0) 
		    yyval.node = concat ("[", yyvsp[-1].node, NULL);
		;
    break;}
case 19:
#line 251 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
	          while (bracket_count-- > 0) 
		    yyval.node = concat ("[", yyvsp[-1].node, NULL);
		;
    break;}
case 23:
#line 269 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  yyval.node = concat (yyvsp[-2].node, ".", yyvsp[0].node, NULL);
		;
    break;}
case 37:
#line 301 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ package_name = yyvsp[-1].node; ;
    break;}
case 45:
#line 328 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  if (yyvsp[0].value == PUBLIC_TK)
		    modifier_value++;
                  if (yyvsp[0].value == STATIC_TK)
                    modifier_value++;
	          USE_ABSORBER;
		;
    break;}
case 46:
#line 336 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  if (yyvsp[0].value == PUBLIC_TK)
		    modifier_value++;
                  if (yyvsp[0].value == STATIC_TK)
                    modifier_value++;
		  USE_ABSORBER;
		;
    break;}
case 47:
#line 348 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  report_class_declaration(yyvsp[-2].node);
		  modifier_value = 0;
                ;
    break;}
case 49:
#line 354 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration(yyvsp[-2].node); ;
    break;}
case 55:
#line 368 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 56:
#line 370 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 57:
#line 375 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ pop_class_context (); ;
    break;}
case 58:
#line 377 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ pop_class_context (); ;
    break;}
case 70:
#line 403 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 71:
#line 405 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ modifier_value = 0; ;
    break;}
case 76:
#line 421 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ bracket_count = 0; USE_ABSORBER; ;
    break;}
case 77:
#line 423 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++bracket_count; ;
    break;}
case 81:
#line 438 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 83:
#line 441 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ modifier_value = 0; ;
    break;}
case 84:
#line 443 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
                  report_main_declaration (yyvsp[-1].declarator);
		  modifier_value = 0;
		;
    break;}
case 85:
#line 451 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  struct method_declarator *d;
		  NEW_METHOD_DECLARATOR (d, yyvsp[-2].node, NULL);
		  yyval.declarator = d;
		;
    break;}
case 86:
#line 457 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  struct method_declarator *d;
		  NEW_METHOD_DECLARATOR (d, yyvsp[-3].node, yyvsp[-1].node);
		  yyval.declarator = d;
		;
    break;}
case 89:
#line 468 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
		  yyval.node = concat (yyvsp[-2].node, ",", yyvsp[0].node, NULL);
		;
    break;}
case 90:
#line 475 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ 
		  USE_ABSORBER;
		  if (bracket_count)
		    {
		      int i;
		      char *n = xmalloc (bracket_count + 1 + strlen (yyval.node));
		      for (i = 0; i < bracket_count; ++i)
			n[i] = '[';
		      strcpy (n + bracket_count, yyval.node);
		      yyval.node = n;
		    }
		  else
		    yyval.node = yyvsp[-1].node;
		;
    break;}
case 91:
#line 490 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{
		  if (bracket_count)
		    {
		      int i;
		      char *n = xmalloc (bracket_count + 1 + strlen (yyval.node));
		      for (i = 0; i < bracket_count; ++i)
			n[i] = '[';
		      strcpy (n + bracket_count, yyval.node);
		      yyval.node = n;
		    }
		  else
		    yyval.node = yyvsp[-1].node;
		;
    break;}
case 94:
#line 511 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 95:
#line 513 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 99:
#line 528 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 101:
#line 539 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ modifier_value = 0; ;
    break;}
case 103:
#line 544 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ modifier_value = 0; ;
    break;}
case 104:
#line 551 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 105:
#line 553 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 112:
#line 570 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 113:
#line 572 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 116:
#line 584 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration (yyvsp[0].node); modifier_value = 0; ;
    break;}
case 118:
#line 587 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration (yyvsp[0].node); modifier_value = 0; ;
    break;}
case 120:
#line 590 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration (yyvsp[-1].node); modifier_value = 0; ;
    break;}
case 122:
#line 593 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration (yyvsp[-1].node); modifier_value = 0; ;
    break;}
case 126:
#line 604 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ pop_class_context (); ;
    break;}
case 127:
#line 606 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ pop_class_context (); ;
    break;}
case 150:
#line 665 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 151:
#line 667 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ modifier_value = 0; ;
    break;}
case 175:
#line 707 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 186:
#line 735 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 187:
#line 740 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 188:
#line 745 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 196:
#line 765 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 201:
#line 780 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 205:
#line 797 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 211:
#line 815 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 222:
#line 840 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 225:
#line 849 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 228:
#line 859 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 234:
#line 874 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 235:
#line 878 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 246:
#line 900 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 247:
#line 905 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 248:
#line 907 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 249:
#line 909 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 250:
#line 911 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 258:
#line 926 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration (NULL); ;
    break;}
case 260:
#line 929 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ report_class_declaration (NULL); ;
    break;}
case 262:
#line 935 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 276:
#line 967 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ bracket_count = 1; ;
    break;}
case 277:
#line 969 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ bracket_count++; ;
    break;}
case 280:
#line 982 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ++complexity; ;
    break;}
case 281:
#line 984 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ++complexity; ;
    break;}
case 282:
#line 985 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 283:
#line 986 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 284:
#line 987 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 285:
#line 988 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 286:
#line 993 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 289:
#line 1000 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
case 336:
#line 1096 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 338:
#line 1102 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 340:
#line 1108 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ ++complexity; ;
    break;}
case 344:
#line 1122 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"
{ USE_ABSORBER; ;
    break;}
}

#line 731 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

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

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 1140 "/home/gdr/gcc-3.2.2/gcc-3.2.2/gcc/java/parse-scan.y"


/* Create a new parser context */

void
java_push_parser_context ()
{
  struct parser_ctxt *new = 
    (struct parser_ctxt *) xcalloc (1, sizeof (struct parser_ctxt));

  new->next = ctxp;
  ctxp = new;
}  

static void
push_class_context (name)
    const char *name;
{
  /* If we already have CURRENT_CLASS set, we're in an inter
     class. Mangle its name. */
  if (current_class)
    {
      const char *p;
      char anonymous [3];
      int additional_length;
      
      /* NAME set to NULL indicates an anonymous class, which are named by
	 numbering them. */
      if (!name)
	{
	  sprintf (anonymous, "%d", ++anonymous_count);
	  p = anonymous;
	}
      else
	p = name;
      
      additional_length = strlen (p)+1; /* +1 for `$' */
      current_class = xrealloc (current_class, 
				current_class_length + additional_length + 1);
      current_class [current_class_length] = '$';
      strcpy (&current_class [current_class_length+1], p);
      current_class_length += additional_length;
    }
  else
    {
      if (!name)
	return;
      current_class_length = strlen (name);
      current_class = xmalloc (current_class_length+1);
      strcpy (current_class, name);
    }
}

static void
pop_class_context ()
{
  /* Go back to the last `$' and cut. */
  while (--current_class_length > 0
        && current_class [current_class_length] != '$')
    ;
  if (current_class_length)
    {
      current_class = xrealloc (current_class, current_class_length+1);
      current_class [current_class_length] = '\0';
    }
  else
    {
      current_class = NULL;
      anonymous_count = 0;
    }
}

/* Actions defined here */

static void
report_class_declaration (name)
     const char * name;
{
  extern int flag_dump_class, flag_list_filename;

  push_class_context (name);
  if (flag_dump_class)
    {
      if (!previous_output)
	{
	  if (flag_list_filename)
	    fprintf (out, "%s: ", input_filename);
	  previous_output = 1;
	}
	
      if (package_name)
	fprintf (out, "%s.%s ", package_name, current_class);
      else
	fprintf (out, "%s ", current_class);
    }
}

static void
report_main_declaration (declarator)
     struct method_declarator *declarator;
{
  extern int flag_find_main;

  if (flag_find_main
      && modifier_value == 2
      && !strcmp (declarator->method_name, "main") 
      && declarator->args 
      && declarator->args [0] == '[' 
      && (! strcmp (declarator->args+1, "String")
	  || ! strcmp (declarator->args + 1, "java.lang.String"))
      && current_class)
    {
      if (!previous_output)
	{
	  if (package_name)
	    fprintf (out, "%s.%s ", package_name, current_class);
	  else
	    fprintf (out, "%s", current_class);
	  previous_output = 1;
	}
    }
}

void
report ()
{
  extern int flag_complexity;
  if (flag_complexity)
    fprintf (out, "%s %d\n", input_filename, complexity);
}

/* Reset global status used by the report functions.  */

void reset_report ()
{
  previous_output = 0;
  package_name = NULL;
  current_class = NULL;
  complexity = 0;
}

void
yyerror (msg)
     const char *msg ATTRIBUTE_UNUSED;
{
  fprintf (stderr, "%s: %d: %s\n", input_filename, lineno, msg);
  exit (1);
}
