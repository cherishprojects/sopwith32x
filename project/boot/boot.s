! SEGA 32X support code for SH2
! by Chilly Willy
! Rom header and SH2 init/exception code - must be first in object list

        .text

! Standard MD Header at 0x000
M68K_CRT0:
        .incbin "out/m68k_crt0.bin", 0, 0x3C0

! Standard Mars Header at 0x3C0
MARS_HEADER:
        .ascii  "32X Helloworld  "              /* module name (16 chars) */
        .long   0x00000000                      /* version */
        .long   _stext                          /* Source (in ROM) */
        .long   0x00000000                      /* Destination (in SDRAM) */
        .long   _sdata                          /* Size */
        .long   mstart                      /* Main SH2 Jump */
        .long   sstart                      /* Secondary SH2 Jump */
        .long   main_vbr                      /* Main SH2 VBR */
        .long   secondary_vbr                      /* Secondary SH2 VBR */

! Standard MD startup code at 0x3F0
M68K_CRT1:
        .incbin "out/m68k_crt1.bin"


        .data

! Main Vector Base Table at 0x06000000
main_vbr:
        .long   mstart      /* Cold Start PC */
        .long   0x0603F000  /* Cold Start SP 0x0603F000*/
        .long   mstart      /* Manual Reset PC */
        .long   0x0603F000  /* Manual Reset SP */
        .long   main_err    /* Illegal instruction */
        .long   0x00000000  /* reserved */
        .long   main_err    /* Invalid slot instruction */
        .long   0x20100400  /* reserved */
        .long   0x20100420  /* reserved */
        .long   main_err    /* CPU address error */
        .long   main_err    /* DMA address error */
        .long   main_err    /* NMI vector */
        .long   main_err    /* User break vector */
        .space  76          /* reserved */
        .long   main_err    /* TRAPA #32 */
        .long   main_err    /* TRAPA #33 */
        .long   main_err    /* TRAPA #34 */
        .long   main_err    /* TRAPA #35 */
        .long   main_err    /* TRAPA #36 */
        .long   main_err    /* TRAPA #37 */
        .long   main_err    /* TRAPA #38 */
        .long   main_err    /* TRAPA #39 */
        .long   main_err    /* TRAPA #40 */
        .long   main_err    /* TRAPA #41 */
        .long   main_err    /* TRAPA #42 */
        .long   main_err    /* TRAPA #43 */
        .long   main_err    /* TRAPA #44 */
        .long   main_err    /* TRAPA #45 */
        .long   main_err    /* TRAPA #46 */
        .long   main_err    /* TRAPA #47 */
        .long   main_err    /* TRAPA #48 */
        .long   main_err    /* TRAPA #49 */
        .long   main_err    /* TRAPA #50 */
        .long   main_err    /* TRAPA #51 */
        .long   main_err    /* TRAPA #52 */
        .long   main_err    /* TRAPA #53 */
        .long   main_err    /* TRAPA #54 */
        .long   main_err    /* TRAPA #55 */
        .long   main_err    /* TRAPA #56 */
        .long   main_err    /* TRAPA #57 */
        .long   main_err    /* TRAPA #58 */
        .long   main_err    /* TRAPA #59 */
        .long   main_err    /* TRAPA #60 */
        .long   main_err    /* TRAPA #61 */
        .long   main_err    /* TRAPA #62 */
        .long   main_err    /* TRAPA #63 */
        .long   main_irq    /* Level 1 IRQ */
        .long   main_irq    /* Level 2 & 3 IRQ's */
        .long   main_irq    /* Level 4 & 5 IRQ's */
        .long   main_irq    /* PWM interupt */
        .long   main_irq    /* Command interupt */
        .long   main_irq    /* H Blank interupt */
        .long   main_irq    /* V Blank interupt */
        .long   main_irq    /* Reset Button */
        .long   main_frt      /* FRT overflow */

! Secondary Vector Base Table at 0x06000120
secondary_vbr:
        .long   sstart      /* Cold Start PC */
        .long   0x06040000  /* Cold Start SP */
        .long   sstart      /* Manual Reset PC */
        .long   0x06040000  /* Manual Reset SP */
        .long   secondary_err    /* Illegal instruction */
        .long   0x00000000  /* reserved */
        .long   secondary_err    /* Invalid slot instruction */
        .long   0x20100400  /* reserved */
        .long   0x20100420  /* reserved */
        .long   secondary_err    /* CPU address error */
        .long   secondary_err    /* DMA address error */
        .long   secondary_err    /* NMI vector */
        .long   secondary_err    /* User break vector */
        .space  76          /* reserved */
        .long   secondary_err    /* TRAPA #32 */
        .long   secondary_err    /* TRAPA #33 */
        .long   secondary_err    /* TRAPA #34 */
        .long   secondary_err    /* TRAPA #35 */
        .long   secondary_err    /* TRAPA #36 */
        .long   secondary_err    /* TRAPA #37 */
        .long   secondary_err    /* TRAPA #38 */
        .long   secondary_err    /* TRAPA #39 */
        .long   secondary_err    /* TRAPA #40 */
        .long   secondary_err    /* TRAPA #41 */
        .long   secondary_err    /* TRAPA #42 */
        .long   secondary_err    /* TRAPA #43 */
        .long   secondary_err    /* TRAPA #44 */
        .long   secondary_err    /* TRAPA #45 */
        .long   secondary_err    /* TRAPA #46 */
        .long   secondary_err    /* TRAPA #47 */
        .long   secondary_err    /* TRAPA #48 */
        .long   secondary_err    /* TRAPA #49 */
        .long   secondary_err    /* TRAPA #50 */
        .long   secondary_err    /* TRAPA #51 */
        .long   secondary_err    /* TRAPA #52 */
        .long   secondary_err    /* TRAPA #53 */
        .long   secondary_err    /* TRAPA #54 */
        .long   secondary_err    /* TRAPA #55 */
        .long   secondary_err    /* TRAPA #56 */
        .long   secondary_err    /* TRAPA #57 */
        .long   secondary_err    /* TRAPA #58 */
        .long   secondary_err    /* TRAPA #59 */
        .long   secondary_err    /* TRAPA #60 */
        .long   secondary_err    /* TRAPA #61 */
        .long   secondary_err    /* TRAPA #62 */
        .long   secondary_err    /* TRAPA #63 */
        .long   secondary_irq    /* Level 1 IRQ */
        .long   secondary_irq    /* Level 2 & 3 IRQ's */
        .long   secondary_irq    /* Level 4 & 5 IRQ's */
        .long   secondary_irq    /* PWM interupt */
        .long   secondary_irq    /* Command interupt */
        .long   secondary_irq    /* H Blank interupt */
        .long   secondary_irq    /* V Blank interupt */
        .long   secondary_irq    /* Reset Button */

! The main SH2 starts here at 0x06000240

mstart:
        bra     mcont
        nop

! The secondary SH2 starts here at 0x06000244

sstart:
        bra     scont
        nop

! Each section of code below has its own data table so that the code
! can be extended without worrying about the offsets becoming too big.
! This results in duplicate entries, but not so many that we care. :)

mcont:
! clear interrupt flags
        mov.l   _main_int_clr,r1
        mov.w   r0,@-r1     /* PWM INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* CMD INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* H INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* V INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* VRES INT clear */
        mov.w   r0,@r1

        mov.l   _main_stk,r15
! purge cache and turn it off
        mov.l   _main_cctl,r0
        mov     #0x10,r1
        mov.b   r1,@r0

! clear bss
        mov     #0,r0
        mov.l   _main_bss_start,r1
        mov.l   _main_bss_end,r2
0:
        mov.l   r0,@r1
        cmp/eq  r1,r2
        bf/s    0b
        add     #4,r1

! wait for 68000 to finish init
        mov.l   _main_sts,r0
        mov.l   _main_ok,r1
1:
        mov.l   @r0,r2
        nop
        nop
        cmp/eq  r1,r2
        bt      1b

! do all initializers
        mov.l   _main_do_init,r0
        jsr     @r0
        nop

! let Secondary SH2 run
        mov     #0,r1
        mov.l   r1,@(4,r0)  /* clear secondary status */

        mov     #0x80,r0
        mov.l   _main_adapter,r1
        mov.b   r0,@r1      /* set FM */
        mov     #0x00,r0
        mov.b   r0,@(1,r1)  /* set int enables */
        mov     #0x20,r0
        ldc     r0,sr       /* allow ints */

! purge cache, turn it on, and run main()
        mov.l   _main_cctl,r0
        mov     #0x11,r1
        mov.b   r1,@r0
        mov.l   _main_go,r0
        jsr     @r0
        nop

! do all finishers
        mov.l   _main_do_fini,r0
        jsr     @r0
        nop
2:
        bra     2b
        nop

        .align   2
_main_int_clr:
        .long   0x2000401E  /* one word passed last int clr reg */
_main_stk:
        .long   0x0603F000  /* Cold Start SP */
_main_sts:
        .long   0x20004020
_main_ok:
        .ascii  "M_OK"
_main_adapter:
        .long   0x20004000
_main_cctl:
        .long   0xFFFFFE92
_main_go:
        .long   _main

_main_bss_start:
        .long   __bss_start
_main_bss_end:
        .long   __end
_main_do_init:
        .long   __INIT_SECTION__
_main_do_fini:
        .long   __FINI_SECTION__

scont:
! clear interrupt flags
        mov.l   _secondary_int_clr,r1
        mov.w   r0,@-r1     /* PWM INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* CMD INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* H INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* V INT clear */
        mov.w   r0,@r1
        mov.w   r0,@-r1     /* VRES INT clear */
        mov.w   r0,@r1

        mov.l   _secondary_stk,r15
! wait for Main SH2 and 68000 to finish init
        mov.l   _secondary_sts,r0
        mov.l   _secondary_ok,r1
1:
        mov.l   @r0,r2
        nop
        nop
        cmp/eq  r1,r2
        bt      1b

        mov.l   _secondary_adapter,r1
        mov     #0x00,r0
        mov.b   r0,@(1,r1)  /* set int enables (different from main despite same address!) */
        mov     #0x20,r0
        ldc     r0,sr       /* allow ints */

! purge cache, turn it on, and run secondary()
        mov.l   _secondary_cctl,r0
        mov     #0x11,r1
        mov.b   r1,@r0
        mov.l   _secondary_go,r0
        jmp     @r0
        nop

        .align   2
_secondary_int_clr:
        .long   0x2000401E  /* one word passed last int clr reg */
_secondary_stk:
        .long   0x06040000  /* Cold Start SP */
_secondary_sts:
        .long   0x20004024
_secondary_ok:
        .ascii  "S_OK"
_secondary_adapter:
        .long   0x20004000
_secondary_cctl:
        .long   0xFFFFFE92
_secondary_go:
        .long   _secondary

! Main exception handler

main_err:
        rte
        nop

! Main IRQ handler

main_irq:
        mov.l   r0,@-r15

        stc     sr,r0       /* SR holds IRQ level in I3-I0 */
        shlr2   r0
        and     #0x38,r0
        cmp/eq  #0x28,r0
        bt      main_h_irq
        cmp/eq  #0x18,r0
        bt      main_pwm_irq
        cmp/eq  #0x30,r0
        bt      main_v_irq
        cmp/eq  #0x20,r0
        bt      main_cmd_irq
        cmp/eq  #0x38,r0
        bt      main_vres_irq

        mov.l   @r15+,r0
        rte
        nop

!-----------------------------------------------------------------------
! Main FRT Overflow IRQ handler
!-----------------------------------------------------------------------

main_frt:
        mov.l   r0,@-r15
        mov.l   r1,@-r15

        mov.l   sh2_frt_ftcsr,r1
        mov.b	@r1,r0
        tst     #2,r0
        bt      9f
        /* overflow */
        mov     #0,r0
        mov.w   r0,@r1  /* clear OVF IRQ */

        mov.l   frt_ovf_count_ptr,r1
        mov.l   @r1,r0
        add     #1,r0
        mov.l   r0,@r1
9:
        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
sh2_frt_ftcsr:
        .long   0xFFFFFE11

frt_ovf_count_ptr:
        .long   _frt_ovf_count


main_v_irq:
        mov.l   r1,@-r15

        mov.l   mvi_mars_adapter,r1
        mov.w   r0,@(0x16,r1)   /* clear V IRQ */
        nop
        nop
        nop
        nop

        ! handle V IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
mvi_mars_adapter:
        .long   0x20004000

main_h_irq:
        mov.l   r1,@-r15

        mov.l   mhi_mars_adapter,r1
        mov.w   r0,@(0x18,r1)   /* clear H IRQ */
        nop
        nop
        nop
        nop

        ! handle H IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
mhi_mars_adapter:
        .long   0x20004000

main_cmd_irq:
        mov.l   r1,@-r15

        mov.l   mci_mars_adapter,r1
        mov.w   r0,@(0x1A,r1)   /* clear CMD IRQ */
        nop
        nop
        nop
        nop

        ! handle CMD IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
mci_mars_adapter:
        .long   0x20004000

main_pwm_irq:
        mov.l   r1,@-r15

        mov.l   mpi_mars_adapter,r1
        mov.w   r0,@(0x1C,r1)   /* clear PWM IRQ */
        nop
        nop
        nop
        nop

        ! handle PWM IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
mpi_mars_adapter:
        .long   0x20004000

main_vres_irq:
        mov.l   mvri_mars_adapter,r1
        mov.w   r0,@(0x14,r1)   /* clear VRES IRQ */
        nop
        nop
        nop
        nop

        mov     #0x0F,r0
        shll2   r0
        shll2   r0
        ldc     r0,sr       /* disallow ints */

        mov.l   mvri_main_stk,r15
        mov.l   mvri_main_vres,r0
        jmp     @r0
        nop

        .align  2
mvri_mars_adapter:
        .long   0x20004000
mvri_main_stk:
        .long   0x0603F000  /* Cold Start SP */
mvri_main_vres:
        .long   main_reset

! Secondary exception handler

secondary_err:
        rte
        nop

! Secondary IRQ handler

secondary_irq:
        mov.l   r0,@-r15

        stc     sr,r0       /* SR holds IRQ level I3-I0 */
        shlr2   r0
        and     #0x38,r0
        cmp/eq  #0x28,r0
        bt      secondary_h_irq
        cmp/eq  #0x18,r0
        bt      secondary_pwm_irq
        cmp/eq  #0x30,r0
        bt      secondary_v_irq
        cmp/eq  #0x20,r0
        bt      secondary_cmd_irq
        cmp/eq  #0x38,r0
        bt      secondary_vres_irq

        mov.l   @r15+,r0
        rte
        nop

secondary_v_irq:
        mov.l   r1,@-r15

        mov.l   svi_mars_adapter,r1
        mov.w   r0,@(0x16,r1)   /* clear V IRQ */
        nop
        nop
        nop
        nop

        ! handle V IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
svi_mars_adapter:
        .long   0x20004000

secondary_h_irq:
        mov.l   r1,@-r15

        mov.l   shi_mars_adapter,r1
        mov.w   r0,@(0x18,r1)   /* clear H IRQ */
        nop
        nop
        nop
        nop

        ! handle H IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
shi_mars_adapter:
        .long   0x20004000

secondary_cmd_irq:
        mov.l   r1,@-r15

        mov.l   sci_mars_adapter,r1
        mov.w   r0,@(0x1A,r1)   /* clear CMD IRQ */
        nop
        nop
        nop
        nop

        ! handle CMD IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
sci_mars_adapter:
        .long   0x20004000

secondary_pwm_irq:
        mov.l   r1,@-r15

        mov.l   spi_mars_adapter,r1
        mov.w   r0,@(0x1C,r1)   /* clear PWM IRQ */
        nop
        nop
        nop
        nop

        ! handle PWM IRQ

        mov.l   @r15+,r1
        mov.l   @r15+,r0
        rte
        nop

        .align  2
spi_mars_adapter:
        .long   0x20004000

secondary_vres_irq:
        mov.l   svri_mars_adapter,r1
        mov.w   r0,@(0x14,r1)   /* clear VRES IRQ */
        nop
        nop
        nop
        nop

        mov     #0x0F,r0
        shll2   r0
        shll2   r0
        ldc     r0,sr       /* disallow ints */

        mov.l   svri_secondary_stk,r15
        mov.l   svri_secondary_vres,r0
        jmp     @r0
        nop

        .align  2
svri_mars_adapter:
        .long   0x20004000
svri_secondary_stk:
        .long   0x06040000  /* Cold Start SP */
svri_secondary_vres:
        .long   secondary_reset


! Fast memcpy function - copies longs, runs from sdram for speed
! On entry: r4 = dst, r5 = src, r6 = len (in longs)

        .align  4
        .global _fast_memcpy
_fast_memcpy:
        mov.l   @r5+,r3
        mov.l   r3,@r4
        dt      r6
        bf/s    _fast_memcpy
        add     #4,r4
        rts
        nop
		
! Fast wmemcpy function - copies words, runs from sdram for speed
! On entry: r4 = dst, r5 = src, r6 = len (in words)

        .align  4
        .global _fast_wmemcpy
_fast_wmemcpy:
        mov.w   @r5+,r3
        mov.w   r3,@r4
        dt      r6
        bf/s    _fast_wmemcpy
        add     #2,r4
        rts
        nop
		
		

! void word_8byte_copy(short *dst, short *src, int count)
        .align  4
        .global _word_8byte_copy
_word_8byte_copy:
        mov.w   @r5+,r0
        dt      r6
        mov.w   @r5+,r1
        !wasted cycle here
        mov.w   @r5+,r2
        !wasted cycle here
        mov.w   @r5+,r3
        !wasted cycle here
        mov.w   r0,@r4
        add     #2,r4
        mov.w   r1,@r4
        add     #2,r4
        mov.w   r2,@r4
        add     #2,r4
        mov.w   r3,@r4
        bf/s    _word_8byte_copy
        add     #2,r4
        rts
        nop 
		
! void _word_8byte_copy_bytereverse(short *dst, short *src, int count)
        .align  4
        .global _word_8byte_copy_bytereverse
_word_8byte_copy_bytereverse:
        mov     r6,r0   !adjust the dst pointer so we start at the end
        shll2   r0
        shll    r0
        add     r0,r4   !dst = dst + count * 8
1:      mov.w   @r5+,r0
        dt      r6
        mov.w   @r5+,r1
        mov.w   @r5+,r2
        mov.w   @r5+,r3
        swap.b  r0,r0
        mov.w   r0,@-r4
        swap.b  r1,r1
        mov.w   r1,@-r4
        swap.b  r2,r2
        mov.w   r2,@-r4
        swap.b  r3,r3
        bf/s    1b
        mov.w   r3,@-r4
        rts
        nop 		

		
! int _get_stack_pointer()
		.align  4
		.global _get_stack_pointer
_get_stack_pointer:	
		mov     r15,r0   !copy stack pointer to return value
		rts
		nop
		
! Cache clear line function
! On entry: r4 = ptr - should be 16 byte aligned

        .align  4
        .global _CacheClearLine
_CacheClearLine:
        mov.l   _cache_flush,r0
        or      r0,r4
        mov     #0,r0
        mov.l   r0,@r4
        rts
        nop

        .align  2

_cache_flush:
        .long   0x40000000

! Cache control function
! On entry: r4 = cache mode => 0x10 = CP, 0x08 = TW, 0x01 = CE

        .align  4
        .global _CacheControl
_CacheControl:
        mov.l   _sh2_cctl,r0
        mov.b   r4,@r0
        rts
        nop

        .align  2

_sh2_cctl:
        .long   0xFFFFFE92

! void ScreenStretch(int src, int width, int height, int interp);
! On entry: r4 = src pointer, r5 = width, r6 = height, r7 = interpolate

        .align  4
        .global _ScreenStretch
_ScreenStretch:
        cmp/pl  r7
        bt      ss_interp

! stretch screen without interpolation

0:
        mov     r5,r3
        shll    r3
        mov     r3,r2
        shll    r2
        add     r4,r3
        add     r4,r2
1:
        add     #-2,r3
        mov.w   @r3,r0
        extu.w  r0,r1
        shll16  r0
        or      r1,r0
        mov.l   r0,@-r2
        cmp/eq  r3,r4
        bf      1b

        /* next line */
        mov.w   ss_pitch,r0
        dt      r6
        bf/s    0b
        add     r0,r4
        rts
        nop

ss_interp:

! stretch screen with interpolation

0:
        mov     r5,r3
        shll    r3
        mov     r3,r2
        shll    r2
        add     r4,r3
        add     r4,r2
        mov     #0,r7
1:
        add     #-2,r3
        mov.w   @r3,r0
        mov.w   ss_mask,r1
        and     r0,r1               /* masked curr pixel */
        shll16  r0
        add     r1,r7               /* add to masked prev pixel */
        shlr    r7                  /* blended pixel */
        or      r7,r0               /* curr pixel << 16 | blended pixel */
        mov     r1,r7               /* masked prev pixel = masked curr pixel */
        mov.l   r0,@-r2
        cmp/eq  r3,r4
        bf      1b

        /* next line */
        mov.w   ss_pitch,r0
        dt      r6
        bf/s    0b
        add     r0,r4
        rts
        nop

ss_mask:
        .word   0x7BDE
ss_pitch:
        .word   640

        .align  2

        .text

main_reset:
! do any main SH2 specific reset code here

        mov.l   secondary_st,r0
        mov.l   secondary_ok,r1
0:
        mov.l   @r0,r2
        nop
        nop
        cmp/eq  r1,r2
        bf      0b          /* wait for secondary */

        ! recopy rom data to sdram

        mov.l   rom_header,r1
        mov.l   @r1,r2      /* src relative to start of rom */
        mov.l   @(4,r1),r3  /* dst relative to start of sdram */
        mov.l   @(8,r1),r4  /* size (longword aligned) */
        mov.l   rom_start,r1
        add     r1,r2
        mov.l   sdram_start,r1
        add     r1,r3
        shlr2   r4          /* number of longs */
        add     #-1,r4
1:
        mov.l   @r2+,r0
        mov.l   r0,@r3
        add     #4,r3
        dt      r4
        bf      1b

        mov.l   main_st,r0
        mov.l   main_ok,r1
        mov.l   r1,@r0      /* tell everyone reset complete */

        mov.l   main_go,r0
        jmp     @r0
        nop

secondary_reset:
! do any secondary SH2 specific reset code here

        mov.l   secondary_st,r0
        mov.l   secondary_ok,r1
        mov.l   r1,@r0      /* tell main to start reset */

        mov.l   main_st,r0
        mov.l   main_ok,r1
0:
        mov.l   @r0,r2
        nop
        nop
        cmp/eq  r1,r2
        bf      0b          /* wait for main to do the work */

        mov.l   secondary_go,r0
        jmp     @r0
        nop

        .align  2
main_st:
        .long   0x20004020
main_ok:
        .ascii  "M_OK"
main_go:
        .long   mstart
rom_header:
        .long   0x220003D4
rom_start:
        .long   0x22000000
sdram_start:
        .long   0x26000000

secondary_st:
        .long   0x20004024
secondary_ok:
        .ascii  "S_OK"
secondary_go:
        .long   sstart


        .global _start
_start:
