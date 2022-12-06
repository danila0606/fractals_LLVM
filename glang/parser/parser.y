%language "c++"

%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define parse.error custom
%param {Driver* driver}
%locations

%code requires {
    #include <string>
    #include <memory>
    namespace yy { class Driver; }
    namespace glang { class Node; class ScopeNode; class DeclarationFuncNode;}
}

%code {
    #include "driver.hpp"
    #include "node.hpp"
    namespace yy {parser::token_type yylex(parser::semantic_type* yylval, parser::location_type* location, Driver* driver);}
}

%token <std::string> VARIABLE 
%token <int>         INTEGER32_t
%token WHILE             "while"   
       RETURN            "return"
       IF                "if"
       FUNC              "func"
       MY_INT32_t        "int32"
       SCOLON            ";"
       LCB               "{"
       RCB               "}"
       LRB               "("
       RRB               ")"
       LAB               "["
       RAB               "]"
       COMMA             ","
       ASSIGN            "="
       OR                "||" 
       AND               "&&"
       NOT               "!"
       EQUAL             "=="
       NOT_EQUAL         "!="
       GREATER           ">"
       LESS              "<"
       LESS_OR_EQUAL     "<="
       GREATER_OR_EQUAL  ">="
       PLUS              "+"  
       MINUS             "-"
       MUL               "*"
       DIV               "/"
       PRINT                 "print"
       GET_TIME_MILLISECONDS "get_time_milliseconds"   
       FLUSH                 "flush"                   
       PUT_PIXEL             "put_pixel"            
       INIT                  "init"                    
       IS_WINDOW_OPENED      "is_window_opened" 

%nterm<std::shared_ptr<glang::ScopeNode>>     global_scope
%nterm<std::shared_ptr<glang::ScopeNode>>     begin_scope
%nterm<std::shared_ptr<glang::ScopeNode>>     scope
%nterm<std::shared_ptr<glang::ScopeNode>>     end_scope
%nterm<std::shared_ptr<glang::Node>>      FUNC_START
%nterm<std::shared_ptr<glang::DeclarationFuncNode>>  FUNCTION
%nterm<std::shared_ptr<glang::Node>>      FUNCCALL
%nterm<std::shared_ptr<glang::Node>>      ARGS
%nterm<std::shared_ptr<glang::Node>>      action
%nterm<std::shared_ptr<glang::Node>>      actions
%nterm<std::shared_ptr<glang::Node>>      assignment32
%nterm<std::shared_ptr<glang::Node>>      value32
%nterm<std::shared_ptr<glang::Node>>      if 
%nterm<std::shared_ptr<glang::Node>>      while
%nterm<std::shared_ptr<glang::Node>>      exprLvl1
%nterm<std::shared_ptr<glang::Node>>      exprLvl2
%nterm<std::shared_ptr<glang::Node>>      exprLvl3
%nterm<std::shared_ptr<glang::Node>>      condition
%nterm<std::shared_ptr<glang::Node>>      return
%nterm<std::shared_ptr<glang::Node>>      print
%nterm<std::shared_ptr<glang::Node>>      graphic
// %nterm<std::shared_ptr<glang::Node>>      GET_TIME_MILLISECONDS 
// %nterm<std::shared_ptr<glang::Node>>      FLUSH 
// %nterm<std::shared_ptr<glang::Node>>      PUT_PIXEL 
// %nterm<std::shared_ptr<glang::Node>>      INIT 
// %nterm<std::shared_ptr<glang::Node>>      IS_WINDOW_OPENED 
%start program

%%

program:        global_scope                         { driver->codegen(); };

global_scope:    global_scope FUNC_START                    { 
                                                        auto&& scope = driver->curscope;
                                                        scope->insert_node($2);
                                                    };
                |                                   {};

FUNC_START:           FUNC FUNCTION actions end_scope            {
                                                        auto&& scope = driver->curscope;
                                                        $$ = std::make_shared<glang::FuncNode>($4, $2);
                                                        auto&& fnName = $2->get_name();

                                                        assert(scope->get_declaration(fnName) == nullptr); 
                                                        scope->insert_declaration(fnName, $2);
                                                    };
FUNCTION:       VARIABLE LRB ARGS RRB LCB      {
                                                        auto&& scope = driver->curscope;
                                                        scope = std::make_shared<glang::ScopeNode>(scope);
                                                        auto&& cur_func_args = driver->cur_args;

                                                        for(const std::string& name : cur_func_args) {
                                                            auto&& node = std::make_shared<glang::DeclarationVarNode>();
                                                            scope->insert_declaration(name, node);
                                                        }

                                                        $$ = std::make_shared<glang::DeclarationFuncNode>($1, cur_func_args);
                                                        scope->set_parent_func($$);
                                                        cur_func_args.clear();
                                                    };

ARGS:        ARGS COMMA VARIABLE                    {
                                                        auto&& cur_func_args = driver->cur_args;
                                                        cur_func_args.push_back($3); 
                                                    };
              | VARIABLE                            {
                                                        auto&& cur_func_args = driver->cur_args;
                                                        cur_func_args.push_back($1); 
                                                    };
              |                                     {};

scope:          begin_scope actions end_scope                 {$$ = $3;};

begin_scope:         LCB                                 {
                                                        auto&& scope = driver->curscope;
                                                        scope = std::make_shared<glang::ScopeNode>(scope);
                                                    };

end_scope:        RCB                                 {
                                                        auto&& scope = driver->curscope;
                                                        $$ = scope;
                                                        scope = scope->get_parent();
                                                    };


actions:           action                                 {
                                                        auto&& scope = driver->curscope;
                                                        scope->insert_node($1);
                                                    };
                | actions action                            {
                                                        auto&& scope = driver->curscope;
                                                        scope->insert_node($2);
                                                    };
                

action:         assignment32                        { $$ = $1; };
              | if                                  { $$ = $1; };
              | while                               { $$ = $1; };
              | return                              { $$ = $1; };
              | print                               { $$ = $1; };
              | graphic                             { $$ = $1; };
              | FUNCCALL  SCOLON                    { $$ = $1; };

graphic : 
        // IS_WINDOW_OPENED LRB RRB SCOLON     {      
        //                                         $$ = std::make_shared<glang::GraphicNode>(glang::graphic_type::is_window_open);
        //                                     };
         INIT           LRB RRB SCOLON     {   
                                                $$ = std::make_shared<glang::GraphicNode>(glang::graphic_type::init);
                                            };
        | FLUSH          LRB RRB SCOLON     {   
                                                $$ = std::make_shared<glang::GraphicNode>(glang::graphic_type::flush);
                                            };
        // | GET_TIME_MILLISECONDS       LRB RRB SCOLON     { 
        //                                         $$ = std::make_shared<glang::GraphicNode>(glang::graphic_type::get_time);
        //                                     };
        | PUT_PIXEL      LRB exprLvl1 COMMA exprLvl1 COMMA exprLvl1 COMMA exprLvl1 COMMA exprLvl1 COMMA exprLvl1 RRB SCOLON {   
                                                std::vector<std::shared_ptr<glang::Node>> args{$3, $5, $7, $9, $11, $13};
                                                $$ = std::make_shared<glang::GraphicNode>(glang::graphic_type::put_pixel, args);
                                            };
        
                                            

        

print:      PRINT exprLvl1 SCOLON                     { $$ = std::make_shared<glang::PrintNode>($2); };

assignment32: MY_INT32_t value32 ASSIGN exprLvl1 SCOLON            { $$ = std::make_shared<glang::MathOpNode>($2, glang::OperationType::Assign32, $4); };
            | MY_INT32_t value32 ASSIGN GET_TIME_MILLISECONDS LRB RRB SCOLON     { 
                                                auto&& get_time_node = std::make_shared<glang::GraphicNode>(glang::graphic_type::get_time);
                                                $$ = std::make_shared<glang::MathOpNode>($2, glang::OperationType::Assign32, get_time_node);
                                            };
            | MY_INT32_t value32 ASSIGN IS_WINDOW_OPENED LRB RRB SCOLON     {      
                                                auto&& get_window_open = std::make_shared<glang::GraphicNode>(glang::graphic_type::is_window_open);
                                                $$ = std::make_shared<glang::MathOpNode>($2, glang::OperationType::Assign32, get_window_open);
                                            };

value32:           VARIABLE                          {
                                                        auto&& scope = driver->curscope;
                                                        auto&& node = scope->get_declaration($1);
                                                        if(!node) {
                                                            auto type_ = glang::my_int_type::t_32;
                                                            node = std::make_shared<glang::DeclarationVarNode>(type_);
                                                            scope->insert_declaration($1, node);
                                                        }
                                                        $$ = node;
                                                    };

exprLvl1:       exprLvl2 PLUS exprLvl2                    { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Plus, $3); };
              | exprLvl2 MINUS exprLvl2                   { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Minus, $3); };
              | exprLvl2                                  { $$ = $1; };

exprLvl2:       exprLvl3 MUL exprLvl3                     { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Mult, $3); };
              | exprLvl3 DIV exprLvl3                     { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Div, $3); };
              | exprLvl3                                  { $$ = $1; };

exprLvl3:       LRB exprLvl1 RRB                       { $$ = $2; }; 
              | VARIABLE                          
                                                    {
                                                        auto&& scope = driver->curscope;
                                                        auto&& node = scope->get_declaration($1);

                                                        assert(node != nullptr);
                                                        $$ = node;
                                                    };
              | INTEGER32_t                             { $$ = std::make_shared<glang::ValueNode>($1); };
              | FUNCCALL                           { $$ = $1; };

FUNCCALL:       VARIABLE LRB ARGS RRB          { 
                                                        auto&& scope = driver->curscope;
                                                        auto&& cur_func_args = driver->cur_args;
                                                        auto&& node = scope->get_declaration($1);
                                                        
                                                        $$ = std::make_shared<glang::FuncCallNode>(node, scope, cur_func_args);
                                                        cur_func_args.clear();
                                                    };

condition:    exprLvl1 AND exprLvl1                       { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::And, $3); };
            | exprLvl1 OR exprLvl1                        { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Or, $3); };      
            | exprLvl1 EQUAL exprLvl1                     { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Equal, $3); };  
            | exprLvl1 NOT_EQUAL exprLvl1                 { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::NotEqual, $3); };  
            | exprLvl1 GREATER exprLvl1                   { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Greater, $3); };  
            | exprLvl1 LESS exprLvl1                      { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::Less, $3); };  
            | exprLvl1 GREATER_OR_EQUAL exprLvl1          { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::GreaterOrEqual, $3); };  
            | exprLvl1 LESS_OR_EQUAL exprLvl1              { $$ = std::make_shared<glang::MathOpNode>($1, glang::OperationType::LessOrEqual, $3); };
            | exprLvl1                                 { $$ = $1; };

if:          IF LRB condition RRB scope             {
                                                        auto&& scope = driver->curscope;
                                                        $$ = std::make_shared<glang::IfNode>($5, $3, scope);
                                                    };

while:       WHILE LRB condition RRB scope          {
                                                        auto&& scope = driver->curscope;
                                                        $$ = std::make_shared<glang::WhileNode>($5, $3, scope);
                                                    };
return:      RETURN exprLvl1 SCOLON                    { $$ = std::make_shared<glang::RetNode>($2); };

%%

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