
#include <iostream>
#include <string>
#include <fstream>
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

int main()
{
    llvm::LLVMContext context;
    llvm::Module *module = new llvm::Module("main.c", context);
    llvm::IRBuilder<> builder(context);


    // creating funcs
    auto &&mainTy = llvm::FunctionType::get(builder.getInt32Ty(), false);
    auto &&mainFunc = llvm::Function::Create(mainTy, llvm::Function::ExternalLinkage, "main", module);
    mainFunc->setDSOLocal(true);

    auto &&initTy = llvm::FunctionType::get(builder.getVoidTy(), true);
    auto &&initF = llvm::Function::Create(initTy, llvm::Function::ExternalLinkage, "init", module);
    initF->setDSOLocal(true);

    auto &&sdl_draw_mandelbrotTy = llvm::FunctionType::get(builder.getVoidTy(), {builder.getInt32Ty()}, false);
    auto &&sdl_draw_mandelbrotF = llvm::Function::Create(sdl_draw_mandelbrotTy, llvm::Function::ExternalLinkage, "sdl_draw_mandelbrot", module);
    sdl_draw_mandelbrotF->setDSOLocal(true);

    auto &&flushTy = llvm::FunctionType::get(builder.getVoidTy(), true);
    auto &&flushF = llvm::Function::Create(flushTy, llvm::Function::ExternalLinkage, "flush", module);
    flushF->setDSOLocal(true);

    auto &&is_window_openedTy = llvm::FunctionType::get(builder.getInt32Ty(), true);
    auto &&is_window_openedF = llvm::Function::Create(is_window_openedTy, llvm::Function::ExternalLinkage, "is_window_opened", module);
    is_window_openedF->setDSOLocal(true);

    auto &&get_time_millisecondsTy = llvm::FunctionType::get(builder.getInt64Ty(), true);
    auto &&get_time_millisecondsF = llvm::Function::Create(get_time_millisecondsTy, llvm::Function::ExternalLinkage, "get_time_milliseconds", module);
    get_time_millisecondsF->setDSOLocal(true);

    auto &&put_pixelTy = llvm::FunctionType::get(builder.getVoidTy(), {builder.getInt32Ty(), builder.getInt32Ty(), builder.getInt8Ty(), builder.getInt8Ty(), builder.getInt8Ty(), builder.getInt8Ty()}, false);
    auto &&put_pixelF = llvm::Function::Create(put_pixelTy, llvm::Function::ExternalLinkage, "put_pixel", module);
    put_pixelF->setDSOLocal(true);
    
    // define dso_local void @sdl_draw_mandelbrot(i32 noundef %0)

    llvm::BasicBlock *draw_entryBB = llvm::BasicBlock::Create(context, "draw_mandelbrot_block", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_13 = llvm::BasicBlock::Create(context, "13", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_16 = llvm::BasicBlock::Create(context, "16", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_17 = llvm::BasicBlock::Create(context, "17", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_20 = llvm::BasicBlock::Create(context, "20", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_31 = llvm::BasicBlock::Create(context, "31", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_35 = llvm::BasicBlock::Create(context, "35", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_41 = llvm::BasicBlock::Create(context, "41", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_43 = llvm::BasicBlock::Create(context, "43", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_66 = llvm::BasicBlock::Create(context, "66", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_70 = llvm::BasicBlock::Create(context, "70", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_71 = llvm::BasicBlock::Create(context, "71", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_77 = llvm::BasicBlock::Create(context, "77", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_83 = llvm::BasicBlock::Create(context, "83", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_86 = llvm::BasicBlock::Create(context, "86", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_87 = llvm::BasicBlock::Create(context, "87", sdl_draw_mandelbrotF);
    llvm::BasicBlock *draw_entry_90 = llvm::BasicBlock::Create(context, "90", sdl_draw_mandelbrotF);
{
    builder.SetInsertPoint(draw_entryBB);
//   %2 = alloca i32, align 4
    auto &&a2 = builder.CreateAlloca(builder.getInt32Ty());
    a2->setAlignment(llvm::Align(4));
//   %3 = alloca i32, align 4
    auto &&a3 = builder.CreateAlloca(builder.getInt32Ty());
    a3->setAlignment(llvm::Align(4));
//   %4 = alloca i32, align 4
    auto &&a4 = builder.CreateAlloca(builder.getInt32Ty());
    a4->setAlignment(llvm::Align(4));
//   %5 = alloca i32, align 4
    auto &&a5 = builder.CreateAlloca(builder.getInt32Ty());
    a5->setAlignment(llvm::Align(4));
//   %6 = alloca i32, align 4
    auto &&a6 = builder.CreateAlloca(builder.getInt32Ty());
    a6->setAlignment(llvm::Align(4));
//   %7 = alloca i32, align 4
    auto &&a7 = builder.CreateAlloca(builder.getInt32Ty());
    a7->setAlignment(llvm::Align(4));
//   %8 = alloca i32, align 4
    auto &&a8 = builder.CreateAlloca(builder.getInt32Ty());
    a8->setAlignment(llvm::Align(4));
//   %9 = alloca i32, align 4
    auto &&a9 = builder.CreateAlloca(builder.getInt32Ty());
    a9->setAlignment(llvm::Align(4));
//   %10 = alloca i32, align 4
    auto &&a10 = builder.CreateAlloca(builder.getInt32Ty());
    a10->setAlignment(llvm::Align(4));
//   %11 = alloca i32, align 4
    auto &&a11 = builder.CreateAlloca(builder.getInt32Ty());
    a11->setAlignment(llvm::Align(4));
//   %12 = alloca i8, align 1
    auto &&a12 = builder.CreateAlloca(builder.getInt8Ty());
    a12->setAlignment(llvm::Align(1));
//   store i32 %0, i32* %2, align 4
    builder.CreateStore(sdl_draw_mandelbrotF->getArg(0), a2)->setAlignment(llvm::Align(4));
//   store i32 0, i32* %3, align 4
    builder.CreateStore(builder.getInt32(0), a3)->setAlignment(llvm::Align(4));
//   br label %13
    builder.CreateBr(draw_entry_13);
// 13:                                               ; preds = %87, %1
    builder.SetInsertPoint(draw_entry_13);
//   %14 = load i32, i32* %3, align 4
    auto &&a14 = builder.CreateLoad(builder.getInt32Ty(), a3);
    a14->setAlignment(llvm::Align(4));
//   %15 = icmp ult i32 %14, 1920
    auto &&a15 = builder.CreateICmpULT(a14, builder.getInt32(1920));
//   br i1 %15, label %16, label %90
    builder.CreateCondBr(a15, draw_entry_16, draw_entry_90);
// 16:                                               ; preds = %13
    builder.SetInsertPoint(draw_entry_16);
//   store i32 0, i32* %4, align 4
    builder.CreateStore(builder.getInt32(0), a4)->setAlignment(llvm::Align(4));
//   br label %17
    builder.CreateBr(draw_entry_17);
// 17:                                               ; preds = %83, %16
    builder.SetInsertPoint(draw_entry_17);
//   %18 = load i32, i32* %4, align 4
    auto &&a18 = builder.CreateLoad(builder.getInt32Ty(), a4);
    a18->setAlignment(llvm::Align(4));
//   %19 = icmp ult i32 %18, 1080
    auto &&a19 = builder.CreateICmpULT(a18, builder.getInt32(1080));
//   br i1 %19, label %20, label %86
    builder.CreateCondBr(a19, draw_entry_20, draw_entry_86);
// 20:                                               ; preds = %17
    builder.SetInsertPoint(draw_entry_20);
//   store i32 0, i32* %5, align 4
    builder.CreateStore(builder.getInt32(0), a5)->setAlignment(llvm::Align(4));
//   store i32 0, i32* %6, align 4
    builder.CreateStore(builder.getInt32(0), a6)->setAlignment(llvm::Align(4));
//   %21 = load i32, i32* %3, align 4
    auto &&a21 = builder.CreateLoad(builder.getInt32Ty(), a3);
    a21->setAlignment(llvm::Align(4));
//   %22 = mul i32 2, %21
    auto &&a22 = builder.CreateNSWMul(builder.getInt32(2), a21);
//   %23 = mul i32 %22, 1000
    auto &&a23 = builder.CreateNSWMul(a22, builder.getInt32(1000));
//   %24 = udiv i32 %23, 1920
    auto &&a24 = builder.CreateUDiv(a23, builder.getInt32(1920));
//   %25 = sub i32 %24, 1000
    auto &&a25 = builder.CreateNSWSub(a24, builder.getInt32(1000));
//   store i32 %25, i32* %7, align 4
    builder.CreateStore(a25, a7)->setAlignment(llvm::Align(4));
//   %26 = load i32, i32* %4, align 4
    auto &&a26 = builder.CreateLoad(builder.getInt32Ty(), a4);
    a26->setAlignment(llvm::Align(4));
//   %27 = mul i32 2, %26
    auto &&a27 = builder.CreateNSWMul(a26, builder.getInt32(2));
//   %28 = mul i32 %27, 1000
    auto &&a28 = builder.CreateNSWMul(a27, builder.getInt32(1000));
//   %29 = udiv i32 %28, 1080
    auto &&a29 = builder.CreateUDiv(a28, builder.getInt32(1080));
//   %30 = sub i32 %29, 1000
    auto &&a30 = builder.CreateNSWSub(a29, builder.getInt32(1000));
//   store i32 %30, i32* %8, align 4
    builder.CreateStore(a30, a8)->setAlignment(llvm::Align(4));
//   store i32 0, i32* %9, align 4
    builder.CreateStore(builder.getInt32(0), a9)->setAlignment(llvm::Align(4));
//   store i32 0, i32* %10, align 4
    builder.CreateStore(builder.getInt32(0), a10)->setAlignment(llvm::Align(4));
//   store i32 0, i32* %11, align 4
    builder.CreateStore(builder.getInt32(0), a11)->setAlignment(llvm::Align(4));
//   br label %31
    builder.CreateBr(draw_entry_31);
// 31:                                               ; preds = %43, %20
    builder.SetInsertPoint(draw_entry_31);
//   %32 = load i32, i32* %11, align 4
    auto &&a32 = builder.CreateLoad(builder.getInt32Ty(), a11);
    a32->setAlignment(llvm::Align(4));
//   %33 = load i32, i32* %2, align 4
    auto &&a33 = builder.CreateLoad(builder.getInt32Ty(), a2);
    a33->setAlignment(llvm::Align(4));
//   %34 = icmp ult i32 %32, %33
    auto &&a34 = builder.CreateICmpULT(a32, a33);
//   br i1 %34, label %35, label %41
    builder.CreateCondBr(a34, draw_entry_35, draw_entry_41);
// 35:                                               ; preds = %31
    builder.SetInsertPoint(draw_entry_35);
//   %36 = load i32, i32* %5, align 4
    auto &&a36 = builder.CreateLoad(builder.getInt32Ty(), a5);
    a36->setAlignment(llvm::Align(4));
//   %37 = load i32, i32* %6, align 4
    auto &&a37 = builder.CreateLoad(builder.getInt32Ty(), a6);
    a37->setAlignment(llvm::Align(4));
//   %38 = add nsw i32 %36, %37
    auto &&a38 = builder.CreateNSWAdd(a36, a37);
//   %39 = sdiv i32 %38, 1000
    auto &&a39 = builder.CreateSDiv(a38, builder.getInt32(1000));
//   %40 = icmp slt i32 %39, 4000
    auto &&a40 = builder.CreateICmpSLT(a39, builder.getInt32(4000));
//   br label %41
    builder.CreateBr(draw_entry_41);
// 41:                                               ; preds = %35, %31
    builder.SetInsertPoint(draw_entry_41);
//   %42 = phi i1 [ false, %31 ], [ %40, %35 ]
    auto&& a42 = builder.CreatePHI(builder.getInt1Ty(), 2);
    a42->addIncoming(builder.getInt1(0), draw_entry_31);
    a42->addIncoming(a40, draw_entry_35);
//   br i1 %42, label %43, label %66
    builder.CreateCondBr(a42, draw_entry_43, draw_entry_66);
// 43:                                               ; preds = %41
    builder.SetInsertPoint(draw_entry_43);
//   %44 = load i32, i32* %9, align 4
    auto &&a44 = builder.CreateLoad(builder.getInt32Ty(),a9);
    a44->setAlignment(llvm::Align(4));
//   %45 = load i32, i32* %9, align 4
    auto &&a45 = builder.CreateLoad(builder.getInt32Ty(), a9);
    a45->setAlignment(llvm::Align(4));
//   %46 = mul nsw i32 %44, %45
    auto&& a46 = builder.CreateNSWMul(a44, a45);
//   store i32 %46, i32* %5, align 4
    builder.CreateStore(a46, a5)->setAlignment(llvm::Align(4));
//   %47 = load i32, i32* %10, align 4
    auto &&a47 = builder.CreateLoad(builder.getInt32Ty(), a10);
    a47->setAlignment(llvm::Align(4));
//   %48 = load i32, i32* %10, align 4
    auto &&a48 = builder.CreateLoad(builder.getInt32Ty(), a10);
    a48->setAlignment(llvm::Align(4));
//   %49 = mul nsw i32 %47, %48
    auto&& a49 = builder.CreateNSWMul(a47, a48);
//   store i32 %49, i32* %6, align 4
    builder.CreateStore(a49, a6)->setAlignment(llvm::Align(4));
//   %50 = load i32, i32* %9, align 4
    auto &&a50 = builder.CreateLoad(builder.getInt32Ty(), a9);
    a50->setAlignment(llvm::Align(4));
//   %51 = mul nsw i32 2, %50
    auto&& a51 = builder.CreateNSWMul(builder.getInt32(2), a50);
//   %52 = load i32, i32* %10, align 4
    auto &&a52 = builder.CreateLoad(builder.getInt32Ty(), a10);
    a52->setAlignment(llvm::Align(4));
//   %53 = mul nsw i32 %51, %52
    auto&& a53 = builder.CreateNSWMul(a51, a52);
//   %54 = sdiv i32 %53, 1000
    auto &&a54 = builder.CreateSDiv(a53, builder.getInt32(1000));
//   %55 = load i32, i32* %8, align 4
    auto &&a55 = builder.CreateLoad(builder.getInt32Ty(), a8);
    a55->setAlignment(llvm::Align(4));
//   %56 = add nsw i32 %54, %55
    auto &&a56 = builder.CreateNSWAdd(a54, a55);
//   store i32 %56, i32* %10, align 4
    builder.CreateStore(a56, a10)->setAlignment(llvm::Align(4));
//   %57 = load i32, i32* %5, align 4
    auto &&a57 = builder.CreateLoad(builder.getInt32Ty(), a5);
    a57->setAlignment(llvm::Align(4));
//   %58 = sdiv i32 %57, 1000
    auto &&a58 = builder.CreateSDiv(a57, builder.getInt32(1000));
//   %59 = load i32, i32* %6, align 4
    auto &&a59 = builder.CreateLoad(builder.getInt32Ty(), a6);
    a59->setAlignment(llvm::Align(4));
//   %60 = sdiv i32 %59, 1000
    auto &&a60 = builder.CreateSDiv(a59, builder.getInt32(1000));
//   %61 = sub nsw i32 %58, %60
    auto &&a61 = builder.CreateNSWSub(a58, a60);
//   %62 = load i32, i32* %7, align 4
    auto &&a62 = builder.CreateLoad(builder.getInt32Ty(), a7);
    a62->setAlignment(llvm::Align(4));
//   %63 = add nsw i32 %61, %62
    auto &&a63 = builder.CreateNSWAdd(a61, a62);
//   store i32 %63, i32* %9, align 4
    builder.CreateStore(a63, a9)->setAlignment(llvm::Align(4));
//   %64 = load i32, i32* %11, align 4
    auto &&a64 = builder.CreateLoad(builder.getInt32Ty(), a11);
    a64->setAlignment(llvm::Align(4));
//   %65 = add i32 %64, 1
    auto &&a65 = builder.CreateNSWAdd(a64, builder.getInt32(1));
//   store i32 %65, i32* %11, align 4
    builder.CreateStore(a65, a11)->setAlignment(llvm::Align(4));
//   br label %31
    builder.CreateBr(draw_entry_31);

// 66:                                               ; preds = %41
    builder.SetInsertPoint(draw_entry_66);
//   store i8 0, i8* %12, align 1
    builder.CreateStore(builder.getInt8(0), a12)->setAlignment(llvm::Align(1));
//   %67 = load i32, i32* %11, align 4
    auto &&a67 = builder.CreateLoad(builder.getInt32Ty(), a11);
    a67->setAlignment(llvm::Align(4));
//   %68 = load i32, i32* %2, align 4
    auto &&a68 = builder.CreateLoad(builder.getInt32Ty(), a2);
    a68->setAlignment(llvm::Align(4));
//   %69 = icmp uge i32 %67, %68
    auto &&a69 = builder.CreateICmpUGE(a67, a68);
//   br i1 %69, label %70, label %71
    builder.CreateCondBr(a69, draw_entry_70, draw_entry_71);

// 70:                                               ; preds = %66
    builder.SetInsertPoint(draw_entry_70);
//   store i8 -1, i8* %12, align 1
    builder.CreateStore(builder.getInt8(-1), a12)->setAlignment(llvm::Align(1));
//   br label %77
    builder.CreateBr(draw_entry_77);
// 71:                                               ; preds = %66
    builder.SetInsertPoint(draw_entry_71);
//   %72 = load i32, i32* %11, align 4
    auto &&a72 = builder.CreateLoad(builder.getInt32Ty(), a11);
    a72->setAlignment(llvm::Align(4));
//   %73 = mul i32 255, %72
    auto &&a73 = builder.CreateMul(builder.getInt32(255), a72);
//   %74 = load i32, i32* %2, align 4
    auto &&a74 = builder.CreateLoad(builder.getInt32Ty(), a2);
    a74->setAlignment(llvm::Align(4));
//   %75 = udiv i32 %73, %74
    auto&& a75 = builder.CreateUDiv(a73, a74);
//   %76 = trunc i32 %75 to i8
    auto&& a76 = builder.CreateTrunc(a75, builder.getInt8Ty());
//   store i8 %76, i8* %12, align 1
    builder.CreateStore(a76, a12)->setAlignment(llvm::Align(1));
//   br label %77
    builder.CreateBr(draw_entry_77);
// 77:                                               ; preds = %71, %70
    builder.SetInsertPoint(draw_entry_77);
//   %78 = load i32, i32* %3, align 4
    auto &&a78 = builder.CreateLoad(builder.getInt32Ty(), a3);
    a78->setAlignment(llvm::Align(4));
//   %79 = load i32, i32* %4, align 4
    auto &&a79 = builder.CreateLoad(builder.getInt32Ty(), a4);
    a79->setAlignment(llvm::Align(4));
//   %80 = load i8, i8* %12, align 1
    auto &&a80 = builder.CreateLoad(builder.getInt8Ty(), a12);
    a80->setAlignment(llvm::Align(1));
//   %81 = load i8, i8* %12, align 1
    auto &&a81 = builder.CreateLoad(builder.getInt8Ty(), a12);
    a81->setAlignment(llvm::Align(1));
//   %82 = load i8, i8* %12, align 1
    auto &&a82 = builder.CreateLoad(builder.getInt8Ty(), a12);
    a82->setAlignment(llvm::Align(1));
//   call void @put_pixel(i32 noundef %78, i32 noundef %79, i8 noundef zeroext %80, i8 noundef zeroext %81, i8 noundef zeroext %82, i8 noundef zeroext -1)
    builder.CreateCall(put_pixelF, {a78, a79, a80, a81, a82, builder.getInt8(-1)});
//   br label %83
    builder.CreateBr(draw_entry_83);

// 83:                                               ; preds = %77
    builder.SetInsertPoint(draw_entry_83);
//   %84 = load i32, i32* %4, align 4
    auto &&a84 = builder.CreateLoad(builder.getInt32Ty(), a4);
    a72->setAlignment(llvm::Align(4));
//   %85 = add i32 %84, 1
    auto&& a85 = builder.CreateAdd(a84, builder.getInt32(1));
//   store i32 %85, i32* %4, align 4
    builder.CreateStore(a85, a4)->setAlignment(llvm::Align(4));
//   br label %17, 
    builder.CreateBr(draw_entry_17);

// 86:                                               ; preds = %17
    builder.SetInsertPoint(draw_entry_86);
//   br label %87
    builder.CreateBr(draw_entry_87);

// 87:                                               ; preds = %86
    builder.SetInsertPoint(draw_entry_87);
//   %88 = load i32, i32* %3, align 4
    auto &&a88 = builder.CreateLoad(builder.getInt32Ty(), a3);
    a72->setAlignment(llvm::Align(4));
//   %89 = add i32 %88, 1
    auto&& a89 = builder.CreateAdd(a88, builder.getInt32(1));
//   store i32 %89, i32* %3, align 4
    builder.CreateStore(a89, a3)->setAlignment(llvm::Align(4));
//   br label %13
    builder.CreateBr(draw_entry_13);

// 90:                                               ; preds = %13
    builder.SetInsertPoint(draw_entry_90);
//   ret void
    builder.CreateRetVoid();
// }
}

{
// declare void @put_pixel(i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

    llvm::BasicBlock *main_entryBB = llvm::BasicBlock::Create(context, "main_block", mainFunc);
    llvm::BasicBlock *main_BB_3 = llvm::BasicBlock::Create(context, "3", mainFunc);
    llvm::BasicBlock *main_BB_6 = llvm::BasicBlock::Create(context, "6", mainFunc);
    llvm::BasicBlock *main_BB_14 = llvm::BasicBlock::Create(context, "14", mainFunc);

    // ; Function Attrs: noinline nounwind optnone uwtable
    // define dso_local i32 @main() #0 {
        builder.SetInsertPoint(main_entryBB);
    //   %1 = alloca i32, align 4
        auto &&a1 = builder.CreateAlloca(builder.getInt32Ty());
        a1->setAlignment(llvm::Align(4));
    //   %2 = alloca i32, align 4
        auto &&a2 = builder.CreateAlloca(builder.getInt32Ty());
        a2->setAlignment(llvm::Align(4));
    //   store i32 0, i32* %1, align 4
        builder.CreateStore(builder.getInt32(0), a1)->setAlignment(llvm::Align(4));
    //   call void (...) @init()
        builder.CreateCall(initF);
    //   store i32 1, i32* %2, align 4
        builder.CreateStore(builder.getInt32(1), a2)->setAlignment(llvm::Align(4));
    //   br label %3
        builder.CreateBr(main_BB_3);
    // 3:                                                ; preds = %6, %0
        builder.SetInsertPoint(main_BB_3);
    //   %4 = call i32 (...) @is_window_opened()
        auto&& a4 = builder.CreateCall(is_window_openedF);
    //   %5 = icmp ne i32 %4, 0
        auto &&a5 = builder.CreateICmpNE(a4, builder.getInt32(0));
    //   br i1 %5, label %6, label %14
        builder.CreateCondBr(a5, main_BB_6, main_BB_14);

    // 6:                                                ; preds = %3
        builder.SetInsertPoint(main_BB_6);
    //   %7 = call i64 (...) @get_time_milliseconds()
        auto&& a7 = builder.CreateCall(get_time_millisecondsF);
    //   %8 = sdiv i64 %7, 1000
        auto &&a8 = builder.CreateSDiv(a7, builder.getInt64(1000));
        
    //   %9 = load i32, i32* %2, align 4
        auto &&a9 = builder.CreateLoad(builder.getInt32Ty(), a2);
        a9->setAlignment(llvm::Align(4));
    //   %10 = zext i32 %9 to i64
        auto &&a10 = builder.CreateZExt(a9, builder.getInt64Ty());
    //   %11 = add nsw i64 %10, %8
        auto&& a11 = builder.CreateNSWAdd(a10, a8);
    //   %12 = trunc i64 %11 to i32
        auto&& a12 = builder.CreateTrunc(a11, builder.getInt32Ty());
    //   store i32 %12, i32* %2, align 4
        builder.CreateStore(a12, a2)->setAlignment(llvm::Align(4));
    //   %13 = load i32, i32* %2, align 4
        auto &&a13 = builder.CreateLoad(builder.getInt32Ty(), a2);
        a13->setAlignment(llvm::Align(4));
    //   call void @sdl_draw_mandelbrot(i32 noundef %13)
        builder.CreateCall(sdl_draw_mandelbrotF, {a13});
    //   call void (...) @flush()
        builder.CreateCall(flushF);
    //   br label %3
        builder.CreateBr(main_BB_3);

    // 14:                                               ; preds = %3
        builder.SetInsertPoint(main_BB_14);
    //   ret i32 0
        builder.CreateRet(builder.getInt32(0));
    // }
}

// declare void @init(...) #1

// declare i32 @is_window_opened(...) #1

// declare i64 @get_time_milliseconds(...) #1

// declare void @flush(...) #1



    std::string foutName = "main_gen.ll";
    std::cout << "Dump to: " << foutName << std::endl;
    std::error_code EC;
    llvm::raw_fd_ostream file(foutName, EC);
    std::cout << "Dump status: " << EC.message() << std::endl;
    module->print(file, nullptr);
    file.close();

    return 0;
}   