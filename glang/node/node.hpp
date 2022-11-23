#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <memory>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/raw_ostream.h"

namespace glang {

    struct CodeGenCtx {
        CodeGenCtx();
        std::unique_ptr<llvm::LLVMContext> m_context = nullptr;
        std::unique_ptr<llvm::Module> m_module = nullptr;
        std::unique_ptr<llvm::IRBuilder<>> m_builder = nullptr;
    };

    enum class my_int_type {
        t_8, // later
        t_32
    };

    enum class OperationType {
        Plus,
        Minus,
        Div,
        Mult,
        And,
        Or,
        Equal,
        NotEqual,
        Greater,
        Less,
        GreaterOrEqual,
        LessOrEqual,

        Assign32,
        Assign8 //later
    };

    enum class graphic_type {
        init,
        flush,
        is_window_open,
        get_time,
        put_pixel
    };

    struct Node {
        virtual llvm::Value* codegen(CodeGenCtx& ctx) = 0;
        virtual ~Node() {}
    };

    class ValueNode : public Node {
    public:
        ValueNode(std::int32_t value) : value_{value} {}
        int32_t get() const { return value_; }
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private: 
        int32_t value_;
    };

    class MathOpNode : public Node {
    public:
        MathOpNode(std::shared_ptr<Node> lhs, OperationType op, std::shared_ptr<Node> rhs) : lhs_{lhs}, rhs_{rhs}, type_{op} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::shared_ptr<Node> lhs_, rhs_;
        OperationType type_;
    };

    struct DeclarationNode : public Node {
        virtual llvm::Value* codegen(CodeGenCtx& ctx) override = 0;
    };

    class DeclarationVarNode : public DeclarationNode {
    public:
        
        DeclarationVarNode(my_int_type t = glang::my_int_type::t_32) : type_(t) {};

        llvm::Value* codegen(CodeGenCtx& ctx) override;
        void store(CodeGenCtx& ctx, llvm::Value* val);
    private:
        
        my_int_type type_ = my_int_type::t_32;
        llvm::Value* m_alloca = nullptr;
    };

    class DeclarationFuncNode : public DeclarationNode {
    public:
        DeclarationFuncNode(const std::string& name, const std::vector<std::string>& argNames = {}) : args_{argNames}, name_{name} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
        const std::vector<std::string>& get_args() const { return args_; }
        const std::string& get_name() const { return name_; }
    private:
        std::vector<std::string> args_;
        std::string name_;
        llvm::Function* llvm_func_ = nullptr;
    };

    class ScopeNode : public Node {
    public:
        ScopeNode() = default;
        ScopeNode(std::shared_ptr<ScopeNode> parent_scope) : parent_scope_{parent_scope} {}

        void insert_node(std::shared_ptr<Node> node) { nodes_.push_back(node); }
        std::shared_ptr<ScopeNode> get_parent() const { return parent_scope_; }
        std::shared_ptr<DeclarationNode> get_declaration(const std::string& name) const;

        void insert_declaration(const std::string& name, std::shared_ptr<DeclarationNode> decl) { variables_table_[name] = decl; }
        llvm::Value* codegen(CodeGenCtx& ctx) override;

        void set_parent_func(std::shared_ptr<DeclarationFuncNode> parentFunc) { parent_function_ = parentFunc; }
        std::shared_ptr<DeclarationFuncNode> get_parent_func() const { return parent_function_; }

        const std::unordered_map<std::string, std::shared_ptr<DeclarationNode>>& get_var_table() const { return variables_table_; } 
    private:
        std::unordered_map<std::string, std::shared_ptr<DeclarationNode>> variables_table_;
        std::vector<std::shared_ptr<Node>> nodes_;

        std::shared_ptr<DeclarationFuncNode> parent_function_ = nullptr;
        std::shared_ptr<ScopeNode> parent_scope_ = nullptr;
    };

    class IfNode : public Node {
    public:
        IfNode(std::shared_ptr<ScopeNode> block, std::shared_ptr<Node> condition, std::shared_ptr<ScopeNode> current_scope) : 
            if_scope_{block},
            condition_node_{condition},
            curscope{current_scope} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::shared_ptr<Node> condition_node_;
        std::shared_ptr<ScopeNode> if_scope_;

        std::shared_ptr<ScopeNode> curscope;
    };

    class WhileNode : public Node {
    public:
        WhileNode(std::shared_ptr<ScopeNode> block, std::shared_ptr<Node> condition, std::shared_ptr<ScopeNode> current_scope) : 
            while_scope_{block}, 
            condition_node_{condition},
            curscope{current_scope} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::shared_ptr<ScopeNode> while_scope_;
        std::shared_ptr<Node> condition_node_;
        
        std::shared_ptr<ScopeNode> curscope;
    };

    class FuncNode : public Node {
    public:
        FuncNode(std::shared_ptr<ScopeNode> scope, std::shared_ptr<DeclarationFuncNode> decl_node) : func_scope_{scope}, decl_node_{decl_node} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::shared_ptr<ScopeNode> func_scope_;
        std::shared_ptr<DeclarationFuncNode> decl_node_;
    };

    class RetNode : public Node {
    public:
        RetNode(std::shared_ptr<Node> value) : ret_value_{value} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::shared_ptr<Node> ret_value_;
    };

    class FuncCallNode : public Node {
    public:
        FuncCallNode(std::shared_ptr<Node> func_decl, std::shared_ptr<ScopeNode> cur_scope, const std::vector<std::string>& params = {}) :
            cur_scope_{cur_scope},
            params_{params},
            func_decl_node_{func_decl} {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::vector<std::string> params_;
        std::shared_ptr<Node> func_decl_node_;

        std::shared_ptr<ScopeNode> cur_scope_;
    };

    class PrintNode : public Node {
    public:
        PrintNode(std::shared_ptr<Node> node) : node_(node) {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        std::shared_ptr<Node> node_;
    };

    class GraphicNode : public Node {
    public:
        GraphicNode(std::vector<std::shared_ptr<Node>> nodes, graphic_type type) : nodes_(nodes), type_(type) {}
        llvm::Value* codegen(CodeGenCtx& ctx) override;
    private:
        graphic_type type_;
        std::vector<std::shared_ptr<Node>> nodes_; //args
    };

}