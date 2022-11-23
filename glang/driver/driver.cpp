#include "driver.hpp"

namespace yy {
    
    Driver::Driver(std::istream& in, std::ostream& out) {
        my_lexer_ = std::make_unique<MyLexer>();
        my_lexer_->switch_streams (in, out);
    }

    bool Driver::parse() {
        parser parser(this);
        bool result = parser.parse();
        if (result) {
            std::cerr<<"Compilation dead"<<std::endl;
            my_lexer_->PrintErrors();
            exit(0);
        }

        return !result;
    }

    parser::token_type Driver::yylex(parser::semantic_type* yylval, parser::location_type* location) {
        parser::token_type tt = static_cast<parser::token_type>(my_lexer_->yylex());
        switch (tt) {
            case yy::parser::token_type::INTEGER32_t: {

                yylval->as <int> () = std::stoi (my_lexer_->YYText ());
                break;
            }
            case yy::parser::token_type::VARIABLE: {

                std::string word(my_lexer_->YYText());
                parser::semantic_type tmp;
                tmp.as<std::string>() = word;
                yylval->swap< std::string >(tmp);
                break;
            }
            // case yy::parser::token_type::ERROR: {
            //     break;
            // }
            default: {
                break;
            }
        }


        *location = my_lexer_->GetLocation();

        return tt;
    }

    void Driver::EmergencyExit(const yy::parser::location_type& location, Errors err) {

        std::string message;

        switch (err) {
            case (Errors::non_existent_variable) : {

                message = std::string("Non existent variable {\n");
                break;
            }
            case (Errors::division_by_zero) : {
                message = std::string("Division by zero {\n");
                break;
            }
            case (Errors::syntax_error) : {
                message = std::string("Syntax Error {\n");
                break;
            }
        }

        message +=  std::string("\tOn line: ") + std::to_string(location.begin.line) +
                    std::string("\n\t") + my_lexer_->GetCurrentString() +
                    std::string("\n\t");
                    std::string err_location = {};

        for (int i = 0; i < location.begin.column - 1; ++i) {
            err_location += "-";
        }

        for (int i = 0; i < location.end.column - location.begin.column; ++i) {
            err_location += "^";
        }

        message += err_location;
        message += "\n}";

        throw std::invalid_argument(message);
    }

    void Driver::codegen() {
        curscope->codegen(IR_codegen);
    }

    void Driver::dumpIR(std::ostream& out) {
        std::string s;
        llvm::raw_string_ostream os(s);
        IR_codegen.m_module->print(os, nullptr);
        os.flush();
        out << s;
    }

}