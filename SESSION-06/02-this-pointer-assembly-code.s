	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 26, 0	sdk_version 26, 0
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	2                               ; -- Begin function __cxx_global_var_init
___cxx_global_var_init:                 ; @__cxx_global_var_init
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, _myDate@PAGE
	add	x0, x0, _myDate@PAGEOFF
	mov	w1, #24                         ; =0x18
	mov	w2, #5                          ; =0x5
	mov	w3, #2023                       ; =0x7e7
	bl	__ZN4DateC1Eiii
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__ZN4DateC1Eiii                 ; -- Begin function _ZN4DateC1Eiii
	.weak_def_can_be_hidden	__ZN4DateC1Eiii
	.p2align	2
__ZN4DateC1Eiii:                        ; @_ZN4DateC1Eiii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	str	w2, [sp, #16]
	str	w3, [sp, #12]
	ldur	x0, [x29, #-8]
	str	x0, [sp]                        ; 8-byte Folded Spill
	ldur	w1, [x29, #-12]
	ldr	w2, [sp, #16]
	ldr	w3, [sp, #12]
	bl	__ZN4DateC2Eiii
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0                          ; =0x0
	str	w8, [sp, #8]                    ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	adrp	x0, _myDate@PAGE
	add	x0, x0, _myDate@PAGEOFF
	mov	w1, #25                         ; =0x19
	mov	w2, #6                          ; =0x6
	mov	w3, #2024                       ; =0x7e8
	bl	__ZN4Date9setValuesEiii
	ldr	w0, [sp, #8]                    ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN4Date9setValuesEiii         ; -- Begin function _ZN4Date9setValuesEiii
	.weak_definition	__ZN4Date9setValuesEiii
	.p2align	2
__ZN4Date9setValuesEiii:                ; @_ZN4Date9setValuesEiii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	w1, [sp, #20]
	str	w2, [sp, #16]
	str	w3, [sp, #12]
	ldr	x9, [sp, #24]
	ldr	w8, [sp, #20]
	str	w8, [x9]
	ldr	w8, [sp, #16]
	str	w8, [x9, #4]
	ldr	w8, [sp, #12]
	str	w8, [x9, #8]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	__ZN4DateC2Eiii                 ; -- Begin function _ZN4DateC2Eiii
	.weak_def_can_be_hidden	__ZN4DateC2Eiii
	.p2align	2
__ZN4DateC2Eiii:                        ; @_ZN4DateC2Eiii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	w1, [sp, #20]
	str	w2, [sp, #16]
	str	w3, [sp, #12]
	ldr	x0, [sp, #24]
	ldr	w8, [sp, #20]
	str	w8, [x0]
	ldr	w8, [sp, #16]
	str	w8, [x0, #4]
	ldr	w8, [sp, #12]
	str	w8, [x0, #8]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	2                               ; -- Begin function _GLOBAL__sub_I_02_this_pointer_assembly_code.cpp
__GLOBAL__sub_I_02_this_pointer_assembly_code.cpp: ; @_GLOBAL__sub_I_02_this_pointer_assembly_code.cpp
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	bl	___cxx_global_var_init
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_myDate                         ; @myDate
.zerofill __DATA,__common,_myDate,12,2
	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3, 0x0
	.quad	__GLOBAL__sub_I_02_this_pointer_assembly_code.cpp
.subsections_via_symbols
