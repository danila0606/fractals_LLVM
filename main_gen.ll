; ModuleID = 'main.c'
source_filename = "main.c"

define dso_local i32 @main() {
main_block:
  %0 = alloca i32, align 4
  %1 = alloca i32, align 4
  store i32 0, i32* %0, align 4
  call void (...) @init()
  store i32 1, i32* %1, align 4
  br label %"3"

"3":                                              ; preds = %"6", %main_block
  %2 = call i32 (...) @is_window_opened()
  %3 = icmp ne i32 %2, 0
  br i1 %3, label %"6", label %"14"

"6":                                              ; preds = %"3"
  %4 = call i64 (...) @get_time_milliseconds()
  %5 = sdiv i64 %4, 1000
  %6 = load i32, i32* %1, align 4
  %7 = zext i32 %6 to i64
  %8 = add nsw i64 %7, %5
  %9 = trunc i64 %8 to i32
  store i32 %9, i32* %1, align 4
  %10 = load i32, i32* %1, align 4
  call void @sdl_draw_mandelbrot(i32 %10)
  call void (...) @flush()
  br label %"3"

"14":                                             ; preds = %"3"
  ret i32 0
}

declare dso_local void @init(...)

define dso_local void @sdl_draw_mandelbrot(i32 %0) {
draw_mandelbrot_block:
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i8, align 1
  store i32 %0, i32* %1, align 4
  store i32 0, i32* %2, align 4
  br label %"13"

"13":                                             ; preds = %"87", %draw_mandelbrot_block
  %12 = load i32, i32* %2, align 4
  %13 = icmp ult i32 %12, 1920
  br i1 %13, label %"16", label %"90"

"16":                                             ; preds = %"13"
  store i32 0, i32* %3, align 4
  br label %"17"

"17":                                             ; preds = %"83", %"16"
  %14 = load i32, i32* %3, align 4
  %15 = icmp ult i32 %14, 1080
  br i1 %15, label %"20", label %"86"

"20":                                             ; preds = %"17"
  store i32 0, i32* %4, align 4
  store i32 0, i32* %5, align 4
  %16 = load i32, i32* %2, align 4
  %17 = mul nsw i32 2, %16
  %18 = mul nsw i32 %17, 1000
  %19 = udiv i32 %18, i64 1920
  %20 = sub nsw i32 %19, i64 1000
  store i32 %20, i32* %6, align 4
  %21 = load i32, i32* %3, align 4
  %22 = mul nsw i32 %21, 2
  %23 = mul nsw i32 %22, 1000
  %24 = udiv i32 %23, i64 1080
  %25 = sub nsw i32 %24, i64 1000
  store i32 %25, i32* %7, align 4
  store i32 0, i32* %8, align 4
  store i32 0, i32* %9, align 4
  store i32 0, i32* %10, align 4
  br label %"31"

"31":                                             ; preds = %"43", %"20"
  %26 = load i32, i32* %10, align 4
  %27 = load i32, i32* %1, align 4
  %28 = icmp ult i32 %26, %27
  br i1 %28, label %"35", label %"41"

"35":                                             ; preds = %"31"
  %29 = load i32, i32* %4, align 4
  %30 = load i32, i32* %5, align 4
  %31 = add nsw i32 %29, %30
  %32 = sdiv i32 %31, 1000
  %33 = icmp slt i32 %32, 4000
  br label %"41"

"41":                                             ; preds = %"35", %"31"
  %34 = phi i1 [ false, %"31" ], [ %33, %"35" ]
  br i1 %34, label %"43", label %"66"

"43":                                             ; preds = %"41"
  %35 = load i32, i32* %8, align 4
  %36 = load i32, i32* %8, align 4
  %37 = mul nsw i32 %35, %36
  store i32 %37, i32* %4, align 4
  %38 = load i32, i32* %9, align 4
  %39 = load i32, i32* %9, align 4
  %40 = mul nsw i32 %38, %39
  store i32 %40, i32* %5, align 4
  %41 = load i32, i32* %8, align 4
  %42 = mul nsw i32 2, %41
  %43 = load i32, i32* %9, align 4
  %44 = mul nsw i32 %42, %43
  %45 = sdiv i32 %44, i64 1000
  %46 = load i32, i32* %7, align 4
  %47 = add nsw i32 %45, %46
  store i32 %47, i32* %9, align 4
  %48 = load i32, i32* %4, align 4
  %49 = sdiv i32 %48, i64 1000
  %50 = load i32, i32* %5, align 4
  %51 = sdiv i32 %50, i64 1000
  %52 = sub nsw i32 %49, %51
  %53 = load i32, i32* %6, align 4
  %54 = add nsw i32 %52, %53
  store i32 %54, i32* %8, align 4
  %55 = load i32, i32* %10, align 4
  %56 = add nsw i32 %55, 1
  store i32 %56, i32* %10, align 4
  br label %"31"

"66":                                             ; preds = %"41"
  store i8 0, i8* %11, align 1
  %57 = load i32, i32* %10, align 4
  %58 = load i32, i32* %1, align 4
  %59 = icmp uge i32 %57, %58
  br i1 %59, label %"70", label %"71"

"70":                                             ; preds = %"66"
  store i8 -1, i8* %11, align 1
  br label %"77"

"71":                                             ; preds = %"66"
  %60 = load i32, i32* %10, align 4
  %61 = mul i32 255, %60
  %62 = load i32, i32* %1, align 4
  %63 = udiv i32 %61, %62
  %64 = trunc i32 %63 to i8
  store i8 %64, i8* %11, align 1
  br label %"77"

"77":                                             ; preds = %"71", %"70"
  %65 = load i32, i32* %2, align 4
  %66 = load i32, i32* %3, align 4
  %67 = load i32, i8* %11, align 1
  %68 = load i32, i8* %11, align 1
  %69 = load i32, i8* %11, align 1
  call void @put_pixel(i32 %65, i32 %66, i32 %67, i32 %68, i32 %69, i8 -1)
  br label %"83"

"83":                                             ; preds = %"77"
  %70 = load i32, i32* %3, align 4
  %71 = add i32 %70, 1
  store i32 %71, i32* %3, align 4
  br label %"17"

"86":                                             ; preds = %"17"
  br label %"87"

"87":                                             ; preds = %"86"
  %72 = load i32, i32* %2, align 4
  %73 = add i32 %72, 1
  store i32 %73, i32* %2, align 4
  br label %"13"

"90":                                             ; preds = %"13"
  ret void
}

declare dso_local void @flush(...)

declare dso_local i32 @is_window_opened(...)

declare dso_local i64 @get_time_milliseconds(...)

declare dso_local void @put_pixel(i32, i32, i8, i32, i32, i32)
