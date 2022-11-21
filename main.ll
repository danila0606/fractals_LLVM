; ModuleID = 'main.c'
source_filename = "main.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @sdl_draw_mandelbrot(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i8, align 1
  store i32 %0, i32* %2, align 4
  store i32 0, i32* %3, align 4
  br label %13

13:                                               ; preds = %87, %1
  %14 = load i32, i32* %3, align 4
  %15 = icmp ult i32 %14, 1920
  br i1 %15, label %16, label %90

16:                                               ; preds = %13
  store i32 0, i32* %4, align 4
  br label %17

17:                                               ; preds = %83, %16
  %18 = load i32, i32* %4, align 4
  %19 = icmp ult i32 %18, 1080
  br i1 %19, label %20, label %86

20:                                               ; preds = %17
  store i32 0, i32* %5, align 4
  store i32 0, i32* %6, align 4
  %21 = load i32, i32* %3, align 4
  %22 = mul i32 2, %21
  %23 = mul i32 %22, 1000
  %24 = udiv i32 %23, 1920
  %25 = sub i32 %24, 1000
  store i32 %25, i32* %7, align 4
  %26 = load i32, i32* %4, align 4
  %27 = mul i32 2, %26
  %28 = mul i32 %27, 1000
  %29 = udiv i32 %28, 1080
  %30 = sub i32 %29, 1000
  store i32 %30, i32* %8, align 4
  store i32 0, i32* %9, align 4
  store i32 0, i32* %10, align 4
  store i32 0, i32* %11, align 4
  br label %31

31:                                               ; preds = %43, %20
  %32 = load i32, i32* %11, align 4
  %33 = load i32, i32* %2, align 4
  %34 = icmp ult i32 %32, %33
  br i1 %34, label %35, label %41

35:                                               ; preds = %31
  %36 = load i32, i32* %5, align 4
  %37 = load i32, i32* %6, align 4
  %38 = add nsw i32 %36, %37
  %39 = sdiv i32 %38, 1000
  %40 = icmp slt i32 %39, 4000
  br label %41

41:                                               ; preds = %35, %31
  %42 = phi i1 [ false, %31 ], [ %40, %35 ]
  br i1 %42, label %43, label %66

43:                                               ; preds = %41
  %44 = load i32, i32* %9, align 4
  %45 = load i32, i32* %9, align 4
  %46 = mul nsw i32 %44, %45
  store i32 %46, i32* %5, align 4
  %47 = load i32, i32* %10, align 4
  %48 = load i32, i32* %10, align 4
  %49 = mul nsw i32 %47, %48
  store i32 %49, i32* %6, align 4
  %50 = load i32, i32* %9, align 4
  %51 = mul nsw i32 2, %50
  %52 = load i32, i32* %10, align 4
  %53 = mul nsw i32 %51, %52
  %54 = sdiv i32 %53, 1000
  %55 = load i32, i32* %8, align 4
  %56 = add nsw i32 %54, %55
  store i32 %56, i32* %10, align 4
  %57 = load i32, i32* %5, align 4
  %58 = sdiv i32 %57, 1000
  %59 = load i32, i32* %6, align 4
  %60 = sdiv i32 %59, 1000
  %61 = sub nsw i32 %58, %60
  %62 = load i32, i32* %7, align 4
  %63 = add nsw i32 %61, %62
  store i32 %63, i32* %9, align 4
  %64 = load i32, i32* %11, align 4
  %65 = add i32 %64, 1
  store i32 %65, i32* %11, align 4
  br label %31, !llvm.loop !6

66:                                               ; preds = %41
  store i8 0, i8* %12, align 1
  %67 = load i32, i32* %11, align 4
  %68 = load i32, i32* %2, align 4
  %69 = icmp uge i32 %67, %68
  br i1 %69, label %70, label %71

70:                                               ; preds = %66
  store i8 -1, i8* %12, align 1
  br label %77

71:                                               ; preds = %66
  %72 = load i32, i32* %11, align 4
  %73 = mul i32 255, %72
  %74 = load i32, i32* %2, align 4
  %75 = udiv i32 %73, %74
  %76 = trunc i32 %75 to i8
  store i8 %76, i8* %12, align 1
  br label %77

77:                                               ; preds = %71, %70
  %78 = load i32, i32* %3, align 4
  %79 = load i32, i32* %4, align 4
  %80 = load i8, i8* %12, align 1
  %81 = load i8, i8* %12, align 1
  %82 = load i8, i8* %12, align 1
  call void @put_pixel(i32 noundef %78, i32 noundef %79, i8 noundef zeroext %80, i8 noundef zeroext %81, i8 noundef zeroext %82, i8 noundef zeroext -1)
  br label %83

83:                                               ; preds = %77
  %84 = load i32, i32* %4, align 4
  %85 = add i32 %84, 1
  store i32 %85, i32* %4, align 4
  br label %17, !llvm.loop !8

86:                                               ; preds = %17
  br label %87

87:                                               ; preds = %86
  %88 = load i32, i32* %3, align 4
  %89 = add i32 %88, 1
  store i32 %89, i32* %3, align 4
  br label %13, !llvm.loop !9

90:                                               ; preds = %13
  ret void
}

declare void @put_pixel(i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void (...) @init()
  store i32 1, i32* %2, align 4
  br label %3

3:                                                ; preds = %6, %0
  %4 = call i32 (...) @is_window_opened()
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %14

6:                                                ; preds = %3
  %7 = call i64 (...) @get_time_milliseconds()
  %8 = sdiv i64 %7, 1000
  %9 = load i32, i32* %2, align 4
  %10 = zext i32 %9 to i64
  %11 = add nsw i64 %10, %8
  %12 = trunc i64 %11 to i32
  store i32 %12, i32* %2, align 4
  %13 = load i32, i32* %2, align 4
  call void @sdl_draw_mandelbrot(i32 noundef %13)
  call void (...) @flush()
  br label %3, !llvm.loop !10

14:                                               ; preds = %3
  ret i32 0
}

declare void @init(...) #1

declare i32 @is_window_opened(...) #1

declare i64 @get_time_milliseconds(...) #1

declare void @flush(...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
