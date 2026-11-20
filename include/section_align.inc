/*
 * Forced in front of every assembly file (-include, see ASFLAGS in the Makefile).
 *
 * The gas of Linux-hosted MIPS toolchains (mips-linux-gnu and the like) gives
 * .text, .data and .bss a 16-byte alignment by default; bare-metal toolchains
 * (mips64-elf and the like) do not, which shifts the link. Aligning each
 * section here, while it is still empty, emits no bytes and only raises the
 * alignment, so every toolchain produces the same layout.
 */
.section .data
.balign 16
.section .bss
.balign 16
.section .text
.balign 16
