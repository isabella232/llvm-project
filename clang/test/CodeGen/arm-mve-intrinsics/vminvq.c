// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-arm-none-eabi -target-feature +mve.fp -mfloat-abi hard -O0 -disable-O0-optnone -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
// RUN: %clang_cc1 -triple thumbv8.1m.main-arm-none-eabi -target-feature +mve.fp -mfloat-abi hard -O0 -disable-O0-optnone -DPOLYMORPHIC -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s

#include <arm_mve.h>

// CHECK-LABEL: @test_vminvq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i8 [[A:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.minv.s.v16i8(i32 [[TMP0]], <16 x i8> [[B:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i8
// CHECK-NEXT:    ret i8 [[TMP2]]
//
int8_t test_vminvq_s8(int8_t a, int8x16_t b)
{
#ifdef POLYMORPHIC
    return vminvq(a, b);
#else /* POLYMORPHIC */
    return vminvq_s8(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vminvq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[A:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.minv.s.v8i16(i32 [[TMP0]], <8 x i16> [[B:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i16
// CHECK-NEXT:    ret i16 [[TMP2]]
//
int16_t test_vminvq_s16(int16_t a, int16x8_t b)
{
#ifdef POLYMORPHIC
    return vminvq(a, b);
#else /* POLYMORPHIC */
    return vminvq_s16(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vminvq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.arm.mve.minv.s.v4i32(i32 [[A:%.*]], <4 x i32> [[B:%.*]])
// CHECK-NEXT:    ret i32 [[TMP0]]
//
int32_t test_vminvq_s32(int32_t a, int32x4_t b)
{
#ifdef POLYMORPHIC
    return vminvq(a, b);
#else /* POLYMORPHIC */
    return vminvq_s32(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vminvq_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i8 [[A:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.minv.u.v16i8(i32 [[TMP0]], <16 x i8> [[B:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i8
// CHECK-NEXT:    ret i8 [[TMP2]]
//
uint8_t test_vminvq_u8(uint8_t a, uint8x16_t b)
{
#ifdef POLYMORPHIC
    return vminvq(a, b);
#else /* POLYMORPHIC */
    return vminvq_u8(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vminvq_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[A:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.minv.u.v8i16(i32 [[TMP0]], <8 x i16> [[B:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i16
// CHECK-NEXT:    ret i16 [[TMP2]]
//
uint16_t test_vminvq_u16(uint16_t a, uint16x8_t b)
{
#ifdef POLYMORPHIC
    return vminvq(a, b);
#else /* POLYMORPHIC */
    return vminvq_u16(a, b);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vminvq_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call i32 @llvm.arm.mve.minv.u.v4i32(i32 [[A:%.*]], <4 x i32> [[B:%.*]])
// CHECK-NEXT:    ret i32 [[TMP0]]
//
uint32_t test_vminvq_u32(uint32_t a, uint32x4_t b)
{
#ifdef POLYMORPHIC
    return vminvq(a, b);
#else /* POLYMORPHIC */
    return vminvq_u32(a, b);
#endif /* POLYMORPHIC */
}
