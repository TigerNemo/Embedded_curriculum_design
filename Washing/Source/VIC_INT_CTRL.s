;/****************************************  2015-05-28  **************************************************
;**                               
;**                               				XY Embeded Lib.
;**                               
;**
;**--------------File Info-------------------------------------------------------------------------------
;** File name:			VIC_INT_CTRL.h
;** Last modified Date:  2015-05-28
;** Last Version:		1.0
;** Descriptions:		Define the extern Functions can be used in user's code for CPU INT control.
;********************************************************************************************************/
; Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs

Mode_USR        EQU     0x10
Mode_FIQ        EQU     0x11
Mode_IRQ        EQU     0x12
Mode_SVC        EQU     0x13
Mode_ABT        EQU     0x17
Mode_UND        EQU     0x1B
Mode_SYS        EQU     0x1F

I_Bit           EQU     0x80            ; when I bit is set, IRQ is disabled
F_Bit           EQU     0x40            ; when F bit is set, FIQ is disabled

                AREA    CPU_INT_CTRL, CODE, READONLY
                ARM
				
; Add belowe code by XY ZQL 2015-05-28 PM
	EXPORT	IRQDisable
	EXPORT	IRQEnable
	EXPORT	FIQDisable
	EXPORT	FIQEnable

IRQDisable
        ;Disable CPU IRQ
        MRS     R0, SPSR
        ORR     R0, R0, #I_Bit
        MSR     SPSR_c, R0
        MOVS    PC, LR

IRQEnable
        ;Enable CPU IRQ
        MRS   R0, SPSR
        BIC   R0, R0, #I_Bit
        MSR   SPSR_c, R0
        MOVS    PC, LR
        
FIQDisable
        ;Disable CPU FIQ
        MRS     R0, SPSR
        ORR     R0, R0, #F_Bit
        MSR     SPSR_c, R0
        MOVS    PC, LR

FIQEnable
        ;Enable CPU FIQ
        MRS   R0, SPSR
        BIC   R0, R0, #F_Bit
        MSR   SPSR_c, R0
        MOVS    PC, LR
		
                END