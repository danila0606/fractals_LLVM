#include "node.hpp"

namespace glang {

    CodeGenCtx::CodeGenCtx() {
        m_context = std::make_unique<llvm::LLVMContext>();
        m_module = std::make_unique<llvm::Module>("main", *m_context);
        m_builder = std::make_unique<llvm::IRBuilder<>>(*m_context);

        // __glang_print
        llvm::FunctionType* glangPrintTy = llvm::FunctionType::get(m_builder->getVoidTy(), {m_builder->getInt32Ty()}, false);
        auto* glangPrint = llvm::Function::Create(glangPrintTy, llvm::Function::ExternalLinkage, "__glang_print", *m_module);

        // auto &&initTy = llvm::FunctionType::get(m_builder->getVoidTy(), true);
        // auto &&initF = llvm::Function::Create(initTy, llvm::Function::ExternalLinkage, "init", *m_module);
        // initF->setDSOLocal(true);

        // auto &&flushTy = llvm::FunctionType::get(m_builder->getVoidTy(), true);
        // auto &&flushF = llvm::Function::Create(flushTy, llvm::Function::ExternalLinkage, "flush", *m_module);
        // flushF->setDSOLocal(true);

        // auto &&is_window_openedTy = llvm::FunctionType::get(m_builder->getInt32Ty(), true);
        // auto &&is_window_openedF = llvm::Function::Create(is_window_openedTy, llvm::Function::ExternalLinkage, "is_window_opened", *m_module);
        // is_window_openedF->setDSOLocal(true);

        // auto &&get_time_millisecondsTy = llvm::FunctionType::get(m_builder->getInt32Ty(), true);
        // auto &&get_time_millisecondsF = llvm::Function::Create(get_time_millisecondsTy, llvm::Function::ExternalLinkage, "get_time_milliseconds", *m_module);
        // get_time_millisecondsF->setDSOLocal(true);

        // auto &&put_pixelTy = llvm::FunctionType::get(m_builder->getVoidTy(), {m_builder->getInt32Ty(), m_builder->getInt32Ty(), m_builder->getInt32Ty(), m_builder->getInt32Ty(), m_builder->getInt32Ty(), m_builder->getInt32Ty()}, false);
        // auto &&put_pixelF = llvm::Function::Create(put_pixelTy, llvm::Function::ExternalLinkage, "put_pixel", *m_module);
        // put_pixelF->setDSOLocal(true);

        


    }

    std::shared_ptr<DeclarationNode> ScopeNode::get_declaration(const std::string& name) const {

        std::shared_ptr<DeclarationNode> ret = nullptr;
        auto&& var = variables_table_.find(name);
        if (var != variables_table_.end()) {
            return var->second;
        }
        if (parent_scope_) {
            return parent_scope_->get_declaration(name);
        }
        return ret;
    }

    llvm::Value* ScopeNode::codegen(CodeGenCtx& ctx) {
        for(auto&& node : nodes_) {
            node->codegen(ctx);
        }
        return nullptr;
    }

    llvm::Value* ValueNode::codegen(CodeGenCtx& ctx) {
        return ctx.m_builder->getInt32(value_);
    }

    llvm::Value* DeclarationVarNode::codegen(CodeGenCtx& ctx) {
        if (!m_alloca) {
            m_alloca = ctx.m_builder->CreateAlloca(ctx.m_builder->getInt32Ty());
        }
        return ctx.m_builder->CreateLoad(ctx.m_builder->getInt32Ty(), m_alloca);
    }

    void DeclarationVarNode::store(CodeGenCtx& ctx, llvm::Value* val) {
        ctx.m_builder->CreateStore(val, m_alloca);
    }

    llvm::Value* MathOpNode::codegen(CodeGenCtx& ctx) {

        llvm::Value* lhsCodeGen = lhs_->codegen(ctx);
        llvm::Value* rhsCodeGen = rhs_->codegen(ctx);
        switch (type_) {
            case OperationType::Plus:
                return ctx.m_builder->CreateAdd(lhsCodeGen, rhsCodeGen);
            case OperationType::Minus:
                return ctx.m_builder->CreateSub(lhsCodeGen, rhsCodeGen);
            case OperationType::Div:
                return ctx.m_builder->CreateSDiv(lhsCodeGen, rhsCodeGen);
            case OperationType::Mult:
                return ctx.m_builder->CreateMul(lhsCodeGen, rhsCodeGen);
            case OperationType::And:
                return ctx.m_builder->CreateAnd(lhsCodeGen, rhsCodeGen);
            case OperationType::Or:
                return ctx.m_builder->CreateOr(lhsCodeGen, rhsCodeGen);
            case OperationType::Equal:
                return ctx.m_builder->CreateICmpEQ(lhsCodeGen, rhsCodeGen);
            case OperationType::NotEqual:
                return ctx.m_builder->CreateICmpNE(lhsCodeGen, rhsCodeGen);
            case OperationType::Greater:
                return ctx.m_builder->CreateICmpSGT(lhsCodeGen, rhsCodeGen);
            case OperationType::Less:
                return ctx.m_builder->CreateICmpSLT(lhsCodeGen, rhsCodeGen);
            case OperationType::GreaterOrEqual:
                return ctx.m_builder->CreateICmpSGE(lhsCodeGen, rhsCodeGen);
            case OperationType::LessOrEqual:
                return ctx.m_builder->CreateICmpSLE(lhsCodeGen, rhsCodeGen);
            case OperationType::Assign32: {

                if (std::shared_ptr<DeclarationVarNode> decl = std::dynamic_pointer_cast<DeclarationVarNode>(lhs_)) {
                    decl->store(ctx, rhsCodeGen);
                } 
                return nullptr;
            }
        }

        assert(0);
        return nullptr;
    }

    llvm::Value* IfNode::codegen(CodeGenCtx& ctx) {
        auto* func = ctx.m_module->getFunction(curscope->get_parent_func()->get_name());
        assert(func);

        llvm::BasicBlock *taken = llvm::BasicBlock::Create(*ctx.m_context, "", func);
        llvm::BasicBlock *not_taken = llvm::BasicBlock::Create(*ctx.m_context, "", func);

        ctx.m_builder->CreateCondBr(condition_node_->codegen(ctx), taken, not_taken);
        ctx.m_builder->SetInsertPoint(taken);

        if_scope_->codegen(ctx);

        ctx.m_builder->CreateBr(not_taken);
        ctx.m_builder->SetInsertPoint(not_taken);

        return nullptr;
    }

    llvm::Value* WhileNode::codegen(CodeGenCtx& ctx) {

        auto* func = ctx.m_module->getFunction(curscope->get_parent_func()->get_name());
        assert(func);

        llvm::BasicBlock *taken = llvm::BasicBlock::Create(*ctx.m_context, "", func);
        llvm::BasicBlock *not_taken = llvm::BasicBlock::Create(*ctx.m_context, "", func);
        llvm::BasicBlock *condition = llvm::BasicBlock::Create(*ctx.m_context, "", func);

        ctx.m_builder->CreateBr(condition);
        ctx.m_builder->SetInsertPoint(condition);
        ctx.m_builder->CreateCondBr(condition_node_->codegen(ctx), taken, not_taken);

        ctx.m_builder->SetInsertPoint(taken);
        auto* while_code_gen = while_scope_->codegen(ctx);
        ctx.m_builder->CreateBr(condition);

        ctx.m_builder->SetInsertPoint(not_taken);

        return nullptr;
    }

    llvm::Value* DeclarationFuncNode::codegen(CodeGenCtx& ctx) {
        if (!llvm_func_) {


            std::vector<llvm::Type*> art_types;
            for (size_t i = 0; i < args_.size(); ++i) {
                art_types.push_back(ctx.m_builder->getInt32Ty());
            }

            llvm::FunctionType* functTy = llvm::FunctionType::get(ctx.m_builder->getInt32Ty(), art_types, false);
            llvm_func_ = llvm::Function::Create(functTy, llvm::Function::ExternalLinkage, name_, *ctx.m_module);
        }

        return llvm_func_;
    }

    llvm::Value* FuncNode::codegen(CodeGenCtx& ctx) {
        decl_node_->codegen(ctx);

        auto* func = ctx.m_module->getFunction(decl_node_->get_name());

        llvm::BasicBlock *initBB = llvm::BasicBlock::Create(*ctx.m_context, "entry", func);
        ctx.m_builder->SetInsertPoint(initBB);

        auto&& args = decl_node_->get_args();
        auto&& var_table = func_scope_->get_var_table();

        for(size_t i = 0; i < args.size(); ++i) {

            auto&& it = var_table.find(args[i]);
            if(it != var_table.end()) {
                auto&& decl = std::dynamic_pointer_cast<DeclarationVarNode>(it->second);
                std::dynamic_pointer_cast<DeclarationVarNode>(it->second)->codegen(ctx);
                decl->store(ctx, func->getArg(i));
            }
        }

        func_scope_->codegen(ctx);
        return nullptr;
    }

    llvm::Value* RetNode::codegen(CodeGenCtx& ctx) {
        return ctx.m_builder->CreateRet(ret_value_->codegen(ctx));
    }

    llvm::Value* FuncCallNode::codegen(CodeGenCtx& ctx) {
        auto&& var_table = cur_scope_->get_var_table();

        auto* funcDecl = llvm::dyn_cast<llvm::Function>(func_decl_node_->codegen(ctx));
        auto* funcTy = funcDecl->getFunctionType();

        std::vector<llvm::Value*> args;
        for (auto&& name : params_) {
            auto&& it = var_table.find(name);
            assert(it != var_table.end());
            args.push_back(it->second->codegen(ctx));
        }

        auto* ret = ctx.m_builder->CreateCall(funcTy, funcDecl, args);
        return ret;
    }

    llvm::Value* PrintNode::codegen(CodeGenCtx& ctx) {
        llvm::Value* args[] = { node_->codegen(ctx) };
        return ctx.m_builder->CreateCall(ctx.m_module->getFunction("__glang_print"), args);
    }

    llvm::Value* GraphicNode::codegen(CodeGenCtx& ctx) {
        
        std::vector<llvm::Value*> args;
        for (auto&& node : nodes_) {
            args.push_back(node->codegen(ctx));
        }

        switch (type_) {
            case graphic_type::flush : return ctx.m_builder->CreateCall(ctx.m_module->getFunction("flush"), args);
            case graphic_type::init : return ctx.m_builder->CreateCall(ctx.m_module->getFunction("init"), args);
            case graphic_type::put_pixel : return ctx.m_builder->CreateCall(ctx.m_module->getFunction("put_pixel"), args);
            case graphic_type::is_window_open : return ctx.m_builder->CreateCall(ctx.m_module->getFunction("is_window_opened"), args);
            case graphic_type::get_time : return ctx.m_builder->CreateCall(ctx.m_module->getFunction("get_time_milliseconds"), args);
        }
    }

}