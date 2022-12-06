// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 17 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"

    #include "driver.hpp"
    #include "node.hpp"
    namespace yy {parser::token_type yylex(parser::semantic_type* yylval, parser::location_type* location, Driver* driver);}

#line 52 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 144 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"

  /// Build a parser object.
  parser::parser (Driver* driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        value.copy< std::shared_ptr<glang::DeclarationFuncNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        value.copy< std::shared_ptr<glang::Node> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        value.copy< std::shared_ptr<glang::ScopeNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        value.move< std::shared_ptr<glang::DeclarationFuncNode> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        value.move< std::shared_ptr<glang::Node> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        value.move< std::shared_ptr<glang::ScopeNode> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        value.YY_MOVE_OR_COPY< std::shared_ptr<glang::DeclarationFuncNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        value.YY_MOVE_OR_COPY< std::shared_ptr<glang::Node> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        value.YY_MOVE_OR_COPY< std::shared_ptr<glang::ScopeNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        value.move< std::shared_ptr<glang::DeclarationFuncNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        value.move< std::shared_ptr<glang::Node> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        value.move< std::shared_ptr<glang::ScopeNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        value.copy< std::shared_ptr<glang::DeclarationFuncNode> > (that.value);
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        value.copy< std::shared_ptr<glang::Node> > (that.value);
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        value.copy< std::shared_ptr<glang::ScopeNode> > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        value.move< int > (that.value);
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        value.move< std::shared_ptr<glang::DeclarationFuncNode> > (that.value);
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        value.move< std::shared_ptr<glang::Node> > (that.value);
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        value.move< std::shared_ptr<glang::ScopeNode> > (that.value);
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_INTEGER32_t: // INTEGER32_t
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
        yylhs.value.emplace< std::shared_ptr<glang::DeclarationFuncNode> > ();
        break;

      case symbol_kind::S_FUNC_START: // FUNC_START
      case symbol_kind::S_ARGS: // ARGS
      case symbol_kind::S_actions: // actions
      case symbol_kind::S_action: // action
      case symbol_kind::S_graphic: // graphic
      case symbol_kind::S_print: // print
      case symbol_kind::S_assignment32: // assignment32
      case symbol_kind::S_value32: // value32
      case symbol_kind::S_exprLvl1: // exprLvl1
      case symbol_kind::S_exprLvl2: // exprLvl2
      case symbol_kind::S_exprLvl3: // exprLvl3
      case symbol_kind::S_FUNCCALL: // FUNCCALL
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_if: // if
      case symbol_kind::S_while: // while
      case symbol_kind::S_return: // return
        yylhs.value.emplace< std::shared_ptr<glang::Node> > ();
        break;

      case symbol_kind::S_global_scope: // global_scope
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_begin_scope: // begin_scope
      case symbol_kind::S_end_scope: // end_scope
        yylhs.value.emplace< std::shared_ptr<glang::ScopeNode> > ();
        break;

      case symbol_kind::S_VARIABLE: // VARIABLE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: global_scope
#line 89 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                     { driver->codegen(); }
#line 899 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 3: // global_scope: global_scope FUNC_START
#line 91 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                            { 
                                                        auto&& scope = driver->curscope;
                                                        scope->insert_node(yystack_[0].value.as < std::shared_ptr<glang::Node> > ());
                                                    }
#line 908 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 4: // global_scope: %empty
#line 95 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {}
#line 914 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 5: // FUNC_START: "func" FUNCTION actions end_scope
#line 97 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                                 {
                                                        auto&& scope = driver->curscope;
                                                        yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::FuncNode>(yystack_[0].value.as < std::shared_ptr<glang::ScopeNode> > (), yystack_[2].value.as < std::shared_ptr<glang::DeclarationFuncNode> > ());
                                                        auto&& fnName = yystack_[2].value.as < std::shared_ptr<glang::DeclarationFuncNode> > ()->get_name();

                                                        assert(scope->get_declaration(fnName) == nullptr); 
                                                        scope->insert_declaration(fnName, yystack_[2].value.as < std::shared_ptr<glang::DeclarationFuncNode> > ());
                                                    }
#line 927 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 6: // FUNCTION: VARIABLE "(" ARGS ")" "{"
#line 105 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                               {
                                                        auto&& scope = driver->curscope;
                                                        scope = std::make_shared<glang::ScopeNode>(scope);
                                                        auto&& cur_func_args = driver->cur_args;

                                                        for(const std::string& name : cur_func_args) {
                                                            auto&& node = std::make_shared<glang::DeclarationVarNode>();
                                                            scope->insert_declaration(name, node);
                                                        }

                                                        yylhs.value.as < std::shared_ptr<glang::DeclarationFuncNode> > () = std::make_shared<glang::DeclarationFuncNode>(yystack_[4].value.as < std::string > (), cur_func_args);
                                                        scope->set_parent_func(yylhs.value.as < std::shared_ptr<glang::DeclarationFuncNode> > ());
                                                        cur_func_args.clear();
                                                    }
#line 946 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 7: // ARGS: ARGS "," VARIABLE
#line 120 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {
                                                        auto&& cur_func_args = driver->cur_args;
                                                        cur_func_args.push_back(yystack_[0].value.as < std::string > ()); 
                                                    }
#line 955 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 8: // ARGS: VARIABLE
#line 124 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {
                                                        auto&& cur_func_args = driver->cur_args;
                                                        cur_func_args.push_back(yystack_[0].value.as < std::string > ()); 
                                                    }
#line 964 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 9: // ARGS: %empty
#line 128 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {}
#line 970 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 10: // scope: begin_scope actions end_scope
#line 130 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                              {yylhs.value.as < std::shared_ptr<glang::ScopeNode> > () = yystack_[0].value.as < std::shared_ptr<glang::ScopeNode> > ();}
#line 976 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 11: // begin_scope: "{"
#line 132 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                         {
                                                        auto&& scope = driver->curscope;
                                                        scope = std::make_shared<glang::ScopeNode>(scope);
                                                    }
#line 985 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 12: // end_scope: "}"
#line 137 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                      {
                                                        auto&& scope = driver->curscope;
                                                        yylhs.value.as < std::shared_ptr<glang::ScopeNode> > () = scope;
                                                        scope = scope->get_parent();
                                                    }
#line 995 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 13: // actions: action
#line 144 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          {
                                                        auto&& scope = driver->curscope;
                                                        scope->insert_node(yystack_[0].value.as < std::shared_ptr<glang::Node> > ());
                                                    }
#line 1004 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 14: // actions: actions action
#line 148 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                            {
                                                        auto&& scope = driver->curscope;
                                                        scope->insert_node(yystack_[0].value.as < std::shared_ptr<glang::Node> > ());
                                                    }
#line 1013 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 15: // action: assignment32
#line 154 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1019 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 16: // action: if
#line 155 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1025 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 17: // action: while
#line 156 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1031 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 18: // action: return
#line 157 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1037 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 19: // action: print
#line 158 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1043 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 20: // action: graphic
#line 159 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1049 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 21: // action: FUNCCALL ";"
#line 160 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[1].value.as < std::shared_ptr<glang::Node> > (); }
#line 1055 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 22: // graphic: "init" "(" ")" ";"
#line 166 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                           {   
                                                yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::GraphicNode>(glang::graphic_type::init);
                                            }
#line 1063 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 23: // graphic: "flush" "(" ")" ";"
#line 169 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                            {   
                                                yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::GraphicNode>(glang::graphic_type::flush);
                                            }
#line 1071 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 24: // graphic: "put_pixel" "(" exprLvl1 "," exprLvl1 "," exprLvl1 "," exprLvl1 "," exprLvl1 "," exprLvl1 ")" ";"
#line 175 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                                                                                            {   
                                                std::vector<std::shared_ptr<glang::Node>> args{yystack_[12].value.as < std::shared_ptr<glang::Node> > (), yystack_[10].value.as < std::shared_ptr<glang::Node> > (), yystack_[8].value.as < std::shared_ptr<glang::Node> > (), yystack_[6].value.as < std::shared_ptr<glang::Node> > (), yystack_[4].value.as < std::shared_ptr<glang::Node> > (), yystack_[2].value.as < std::shared_ptr<glang::Node> > ()};
                                                yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::GraphicNode>(glang::graphic_type::put_pixel, args);
                                            }
#line 1080 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 25: // print: "print" exprLvl1 ";"
#line 184 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                      { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::PrintNode>(yystack_[1].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1086 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 26: // assignment32: "int32" value32 "=" exprLvl1 ";"
#line 186 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                                   { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[3].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Assign32, yystack_[1].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1092 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 27: // assignment32: "int32" value32 "=" "get_time_milliseconds" "(" ")" ";"
#line 187 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                                                 { 
                                                auto&& get_time_node = std::make_shared<glang::GraphicNode>(glang::graphic_type::get_time);
                                                yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[5].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Assign32, get_time_node);
                                            }
#line 1101 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 28: // assignment32: "int32" value32 "=" "is_window_opened" "(" ")" ";"
#line 191 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                                            {      
                                                auto&& get_window_open = std::make_shared<glang::GraphicNode>(glang::graphic_type::is_window_open);
                                                yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[5].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Assign32, get_window_open);
                                            }
#line 1110 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 29: // value32: VARIABLE
#line 196 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                     {
                                                        auto&& scope = driver->curscope;
                                                        auto&& node = scope->get_declaration(yystack_[0].value.as < std::string > ());
                                                        if(!node) {
                                                            auto type_ = glang::my_int_type::t_32;
                                                            node = std::make_shared<glang::DeclarationVarNode>(type_);
                                                            scope->insert_declaration(yystack_[0].value.as < std::string > (), node);
                                                        }
                                                        yylhs.value.as < std::shared_ptr<glang::Node> > () = node;
                                                    }
#line 1125 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 30: // exprLvl1: exprLvl2 "+" exprLvl2
#line 207 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Plus, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1131 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 31: // exprLvl1: exprLvl2 "-" exprLvl2
#line 208 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Minus, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1137 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 32: // exprLvl1: exprLvl2
#line 209 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1143 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 33: // exprLvl2: exprLvl3 "*" exprLvl3
#line 211 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Mult, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1149 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 34: // exprLvl2: exprLvl3 "/" exprLvl3
#line 212 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Div, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1155 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 35: // exprLvl2: exprLvl3
#line 213 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1161 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 36: // exprLvl3: "(" exprLvl1 ")"
#line 215 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                       { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[1].value.as < std::shared_ptr<glang::Node> > (); }
#line 1167 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 37: // exprLvl3: VARIABLE
#line 217 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {
                                                        auto&& scope = driver->curscope;
                                                        auto&& node = scope->get_declaration(yystack_[0].value.as < std::string > ());

                                                        assert(node != nullptr);
                                                        yylhs.value.as < std::shared_ptr<glang::Node> > () = node;
                                                    }
#line 1179 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 38: // exprLvl3: INTEGER32_t
#line 224 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                        { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::ValueNode>(yystack_[0].value.as < int > ()); }
#line 1185 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 39: // exprLvl3: FUNCCALL
#line 225 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                   { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1191 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 40: // FUNCCALL: VARIABLE "(" ARGS ")"
#line 227 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                               { 
                                                        auto&& scope = driver->curscope;
                                                        auto&& cur_func_args = driver->cur_args;
                                                        auto&& node = scope->get_declaration(yystack_[3].value.as < std::string > ());
                                                        
                                                        yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::FuncCallNode>(node, scope, cur_func_args);
                                                        cur_func_args.clear();
                                                    }
#line 1204 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 41: // condition: exprLvl1 "&&" exprLvl1
#line 236 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::And, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1210 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 42: // condition: exprLvl1 "||" exprLvl1
#line 237 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Or, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1216 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 43: // condition: exprLvl1 "==" exprLvl1
#line 238 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Equal, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1222 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 44: // condition: exprLvl1 "!=" exprLvl1
#line 239 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::NotEqual, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1228 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 45: // condition: exprLvl1 ">" exprLvl1
#line 240 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Greater, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1234 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 46: // condition: exprLvl1 "<" exprLvl1
#line 241 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::Less, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1240 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 47: // condition: exprLvl1 ">=" exprLvl1
#line 242 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                          { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::GreaterOrEqual, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1246 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 48: // condition: exprLvl1 "<=" exprLvl1
#line 243 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                           { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::MathOpNode>(yystack_[2].value.as < std::shared_ptr<glang::Node> > (), glang::OperationType::LessOrEqual, yystack_[0].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1252 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 49: // condition: exprLvl1
#line 244 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                       { yylhs.value.as < std::shared_ptr<glang::Node> > () = yystack_[0].value.as < std::shared_ptr<glang::Node> > (); }
#line 1258 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 50: // if: "if" "(" condition ")" scope
#line 246 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {
                                                        auto&& scope = driver->curscope;
                                                        yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::IfNode>(yystack_[0].value.as < std::shared_ptr<glang::ScopeNode> > (), yystack_[2].value.as < std::shared_ptr<glang::Node> > (), scope);
                                                    }
#line 1267 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 51: // while: "while" "(" condition ")" scope
#line 251 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                    {
                                                        auto&& scope = driver->curscope;
                                                        yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::WhileNode>(yystack_[0].value.as < std::shared_ptr<glang::ScopeNode> > (), yystack_[2].value.as < std::shared_ptr<glang::Node> > (), scope);
                                                    }
#line 1276 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;

  case 52: // return: "return" exprLvl1 ";"
#line 255 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"
                                                       { yylhs.value.as < std::shared_ptr<glang::Node> > () = std::make_shared<glang::RetNode>(yystack_[1].value.as < std::shared_ptr<glang::Node> > ()); }
#line 1282 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"
    break;


#line 1286 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        report_syntax_error (yyctx);
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "VARIABLE", "INTEGER32_t",
  "while", "return", "if", "func", "int32", ";", "{", "}", "(", ")", "[",
  "]", ",", "=", "||", "&&", "!", "==", "!=", ">", "<", "<=", ">=", "+",
  "-", "*", "/", "print", "get_time_milliseconds", "flush", "put_pixel",
  "init", "is_window_opened", "$accept", "program", "global_scope",
  "FUNC_START", "FUNCTION", "ARGS", "scope", "begin_scope", "end_scope",
  "actions", "action", "graphic", "print", "assignment32", "value32",
  "exprLvl1", "exprLvl2", "exprLvl3", "FUNCCALL", "condition", "if",
  "while", "return", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }








  const signed char parser::yypact_ninf_ = -21;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
     -21,    11,    22,   -21,    30,   -21,     7,    20,    34,    28,
      29,     3,    32,    40,     3,    36,    38,    44,    12,   -21,
     -21,   -21,   -21,    43,   -21,   -21,   -21,   -21,    -4,    34,
       3,    28,   -21,     3,    58,   -20,     5,   -21,     3,   -21,
      60,    69,    66,     3,    67,   -21,   -21,   -21,   -21,    71,
      80,    14,    47,    70,    72,   -21,     3,     3,     3,     3,
      73,     1,   -21,    75,    74,    78,   -21,   -21,   -21,     3,
       3,     3,     3,     3,     3,     3,     3,    81,   -21,   -21,
     -21,   -21,   -21,    81,    76,    82,    83,   -21,     3,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
      20,   -21,    85,    87,   -21,    79,    12,    92,    94,     3,
     -21,   -21,   -21,    89,     3,    91,     3,    93,     3,    95,
     101,   -21
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     3,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      20,    19,    15,     0,    16,    17,    18,     8,     0,     9,
       0,    37,    38,     0,     0,    32,    35,    39,     0,    29,
       0,     0,     0,     0,     0,    12,     5,    14,    21,     0,
       0,     0,    49,     0,     0,    52,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     6,     7,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    30,
      31,    33,    34,     0,     0,     0,     0,    23,     0,    22,
      42,    41,    43,    44,    45,    46,    48,    47,    11,    51,
       0,    50,     0,     0,    26,     0,     0,     0,     0,     0,
      10,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    24
  };

  const signed char
  parser::yypgoto_[] =
  {
     -21,   -21,   -21,   -21,   -21,    68,    31,   -21,     6,    13,
     -16,   -21,   -21,   -21,   -21,   -11,   -17,    17,    -6,    77,
     -21,   -21,   -21
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,     5,     7,    28,    99,   100,    46,    18,
      19,    20,    21,    22,    40,    52,    35,    36,    37,    53,
      24,    25,    26
  };

  const signed char
  parser::yytable_[] =
  {
      34,    23,    47,    41,    31,    32,    31,    32,    56,    57,
      49,     3,    23,    50,    33,     9,    33,    10,    11,    12,
       8,    13,    54,     9,    45,    10,    11,    12,    68,    13,
       4,    50,    64,     6,    84,    58,    59,    27,    85,    79,
      80,    29,    30,    39,    14,    38,    15,    16,    17,    42,
      86,    43,    14,    48,    15,    16,    17,    44,    90,    91,
      92,    93,    94,    95,    96,    97,    69,    70,    55,    71,
      72,    73,    74,    75,    76,    81,    82,   105,    61,    62,
      63,    65,    66,    67,    77,    87,    78,    83,    89,   102,
      47,    88,    98,   104,    23,   103,   109,    51,   113,   107,
      23,   108,   111,   115,   112,   117,   114,   119,   116,   120,
     118,   121,   110,   106,   101,    60
  };

  const signed char
  parser::yycheck_[] =
  {
      11,     7,    18,    14,     3,     4,     3,     4,    28,    29,
      14,     0,    18,    17,    13,     3,    13,     5,     6,     7,
      13,     9,    33,     3,    12,     5,     6,     7,    14,     9,
       8,    17,    43,     3,    33,    30,    31,     3,    37,    56,
      57,    13,    13,     3,    32,    13,    34,    35,    36,    13,
      61,    13,    32,    10,    34,    35,    36,    13,    69,    70,
      71,    72,    73,    74,    75,    76,    19,    20,    10,    22,
      23,    24,    25,    26,    27,    58,    59,    88,    18,    10,
      14,    14,    11,     3,    14,    10,    14,    14,    10,    13,
     106,    17,    11,    10,   100,    13,    17,    29,   109,    14,
     106,    14,    10,   114,    10,   116,    17,   118,    17,    14,
      17,    10,   106,   100,    83,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,    39,    40,     0,     8,    41,     3,    42,    13,     3,
       5,     6,     7,     9,    32,    34,    35,    36,    47,    48,
      49,    50,    51,    56,    58,    59,    60,     3,    43,    13,
      13,     3,     4,    13,    53,    54,    55,    56,    13,     3,
      52,    53,    13,    13,    13,    12,    46,    48,    10,    14,
      17,    43,    53,    57,    53,    10,    28,    29,    30,    31,
      57,    18,    10,    14,    53,    14,    11,     3,    14,    19,
      20,    22,    23,    24,    25,    26,    27,    14,    14,    54,
      54,    55,    55,    14,    33,    37,    53,    10,    17,    10,
      53,    53,    53,    53,    53,    53,    53,    53,    11,    44,
      45,    44,    13,    13,    10,    53,    47,    14,    14,    17,
      46,    10,    10,    53,    17,    53,    17,    53,    17,    53,
      14,    10
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    38,    39,    40,    40,    41,    42,    43,    43,    43,
      44,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    50,    51,    51,    51,    52,
      53,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    59,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     4,     5,     3,     1,     0,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     4,     4,    15,     3,     5,     7,     7,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       5,     5,     3
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    89,    89,    91,    95,    97,   105,   120,   124,   128,
     130,   132,   137,   144,   148,   154,   155,   156,   157,   158,
     159,   160,   166,   169,   175,   184,   186,   187,   191,   196,
     207,   208,   209,   211,   212,   213,   215,   216,   224,   225,
     227,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     246,   251,   255
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
    };
    // Last valid token kind.
    const int code_max = 292;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1754 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.cc"

#line 257 "/mnt/c/Users/pc/Desktop/my_glang/parser/parser.y"


namespace yy {

    parser::token_type yylex (parser::semantic_type* yylval, parser::location_type* location, Driver* driver) {
		return driver->yylex (yylval, location);
	}

    void parser::error (const parser::location_type& location, const std::string& string) {
	    if (!(driver->IsGrammarError()))
	        driver->EmergencyExit(location, yy::Errors::syntax_error);
	}

    void parser::report_syntax_error (parser::context const& context) const {
        if (!(driver->IsGrammarError()))
		    driver->EmergencyExit(context.location (), yy::Errors::syntax_error);
	}
}
