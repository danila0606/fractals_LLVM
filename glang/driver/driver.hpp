#pragma once

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

#include <string>
#include <fstream>
#include <sstream>
#include <memory>

#include "MyLexer.hpp"

#include "parser.hh"
#include "node.hpp"

namespace yy {

enum class Errors {
        non_existent_variable,
        division_by_zero,
        syntax_error
};

class Driver final {
public:
    ~Driver() = default;
    Driver(std::istream& in, std::ostream& out);

    parser::token_type yylex(parser::semantic_type* yylval, parser::location_type* location);
    void EmergencyExit(const parser::location_type& location, Errors err);
    bool IsGrammarError() const {return my_lexer_->IsError();};

    //std::shared_ptr<glang::ScopeNode> get_cur_scope() { return curscope;};


    bool parse();
    void codegen();
    void dumpIR(std::ostream& out);

    friend parser;
private:
    std::unique_ptr<MyLexer> my_lexer_ = nullptr;

    glang::CodeGenCtx IR_codegen;
    std::shared_ptr<glang::ScopeNode> curscope = std::make_shared<glang::ScopeNode>();
    std::vector<std::string> cur_args;
};

} // namespace yy
