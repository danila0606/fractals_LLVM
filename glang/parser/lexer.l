%option c++
%option noyywrap debug
%option yylineno
%option yyclass="MyLexer"
%option nounput yylineno
%{

#include "parser.hh"
#include "MyLexer.hpp"
#define YY_USER_ACTION SetLocation ();

%}

WS [ \t\n\v]+
INTEGER32_t [0]|[1-9][0-9]*
NAME [a-zA-Z][a-zA-Z0-9_]*

%%
"return"    return yy::parser::token_type::RETURN;
"while"     return yy::parser::token_type::WHILE;
"if"        return yy::parser::token_type::IF;
"func"      return yy::parser::token_type::FUNC;
"int32"     return yy::parser::token_type::MY_INT32_t;

";"         return yy::parser::token_type::SCOLON;
"{"         return yy::parser::token_type::LCB;
"}"         return yy::parser::token_type::RCB;
"("         return yy::parser::token_type::LRB;
")"         return yy::parser::token_type::RRB;
"["         return yy::parser::token_type::LAB;
"]"         return yy::parser::token_type::RAB;
","         return yy::parser::token_type::COMMA;

">="        return yy::parser::token_type::GREATER_OR_EQUAL;
"<="        return yy::parser::token_type::LESS_OR_EQUAL;
">"         return yy::parser::token_type::GREATER;
"<"         return yy::parser::token_type::LESS;
"=="        return yy::parser::token_type::EQUAL;
"!="        return yy::parser::token_type::NOT_EQUAL;

"="         return yy::parser::token_type::ASSIGN;

"||"        return yy::parser::token_type::OR;
"&&"        return yy::parser::token_type::AND;
"!"         return yy::parser::token_type::NOT;

"+"         return yy::parser::token_type::PLUS;
"-"         return yy::parser::token_type::MINUS;

"*"         return yy::parser::token_type::MUL;
"/"         return yy::parser::token_type::DIV;

"print"     return yy::parser::token_type::PRINT;

{WS}        
{INTEGER32_t}   return yy::parser::token_type::INTEGER32_t;
{NAME}          return yy::parser::token_type::VARIABLE;
                
%%