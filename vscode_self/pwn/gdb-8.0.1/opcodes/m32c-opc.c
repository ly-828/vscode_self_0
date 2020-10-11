/* Instruction opcode table for m32c.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1996-2017 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#include "sysdep.h"
#include "ansidecl.h"
#include "bfd.h"
#include "symcat.h"
#include "m32c-desc.h"
#include "m32c-opc.h"
#include "libiberty.h"

/* -- opc.c */
static unsigned int
m32c_asm_hash (const char *mnem)
{
  unsigned int h;

  /* The length of the mnemonic for the Jcnd insns is 1.  Hash jsri.  */
  if (mnem[0] == 'j' && mnem[1] != 's')
    return 'j';

  /* Don't hash scCND  */
  if (mnem[0] == 's' && mnem[1] == 'c')
    return 's';

  /* Don't hash bmCND  */
  if (mnem[0] == 'b' && mnem[1] == 'm')
    return 'b';

  for (h = 0; *mnem && *mnem != ' ' && *mnem != ':'; ++mnem)
    h += *mnem;
  return h % CGEN_ASM_HASH_SIZE;
}

/* -- asm.c */
/* The hash functions are recorded here to help keep assembler code out of
   the disassembler and vice versa.  */

static int asm_hash_insn_p        (const CGEN_INSN *);
static unsigned int asm_hash_insn (const char *);
static int dis_hash_insn_p        (const CGEN_INSN *);
static unsigned int dis_hash_insn (const char *, CGEN_INSN_INT);

/* Instruction formats.  */

#define F(f) & m32c_cgen_ifld_table[M32C_##f]
static const CGEN_IFMT ifmt_empty ATTRIBUTE_UNUSED = {
  0, 0, 0x0, { { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff0f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff2f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff8f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff8f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_Rn_direct_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_RN_EXT_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_An_indirect_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_8_An_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_An_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_24_An_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_8_SB_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_SB_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_8_FB_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_FB_relative_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_absolute_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_w_16_ExtUnprefixed_dst32_16_24_absolute_ExtUnprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_Rn_direct_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_RN_EXT_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_An_indirect_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_8_An_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_An_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_24_An_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_8_SB_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_SB_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_8_FB_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_FB_relative_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_absolute_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts32_b_16_ExtUnprefixed_dst32_16_24_absolute_ExtUnprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_Rn_direct_Ext_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffd, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN_EXT) }, { F (F_15_1) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_An_indirect_Ext_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_16_8_An_relative_Ext_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_16_16_An_relative_Ext_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_16_8_SB_relative_Ext_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_16_16_SB_relative_Ext_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_16_8_FB_relative_Ext_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_exts16_b_16_Ext_dst16_16_16_absolute_Ext_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff2f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_HI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff2f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffec00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffec0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffc0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffc0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffcc, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffec, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffec, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffce, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffce, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffce00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffce0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffec00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_24_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { F (F_12_4) }, { F (F_DSP_24_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffec0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffc0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffc0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_32_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_8_4) }, { F (F_DSP_16_U16) }, { F (F_12_4) }, { F (F_DSP_32_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffcc, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffec, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffec, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffce, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffce, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffee, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffce00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffee00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffce0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffee0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_SRC16_RN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_4) }, { F (F_8_2) }, { F (F_10_1) }, { F (F_SRC16_AN) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_basic_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_basic_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_basic_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_w_imm_G_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_basic_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_basic_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_basic_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor32_b_imm_G_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_basic_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffc0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_basic_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_basic_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_16_8_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_16_8_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_16_8_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_16_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_16_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_w_imm_G_16_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_basic_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_basic_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_basic_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_16_8_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_16_8_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_16_8_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_16_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_16_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xor16_b_imm_G_16_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff3f, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff3f, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16w_r3_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_xchg16b_r1h_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_2) }, { F (F_10_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_imm_S_2_S_8_dst32_2_S_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_imm_S_2_S_8_dst32_2_S_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_imm_S_2_S_16_dst32_2_S_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff000000, { { F (F_0_2) }, { F (F_DSP_24_S16) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_imm_S_2_S_basic_dst32_2_S_R0_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_8_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_imm_S_2_S_8_dst32_2_S_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_imm_S_2_S_8_dst32_2_S_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_imm_S_2_S_16_dst32_2_S_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_imm_S_2_S_basic_dst32_2_S_R0l_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff0f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff2f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff2f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff8f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff8f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_HI_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_HI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_HI_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_w_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_HI_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U8) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U16) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_40_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff2f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff3f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffbf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_48_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_DSP_24_U24) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffff00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_2) }, { F (F_DSP_24_U24) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_48_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff0f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff2f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff2f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff8f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff8f, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffaf, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff8f00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffaf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffcf00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_SRC32_RN_PREFIXED_QI) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_direct_Prefixed_QI_dst32_24_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_tst32_b_basic_Prefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffef00, { { F (F_0_4) }, { F (F_9_3) }, { F (F_18_1) }, { F (F_SRC32_AN_PREFIXED) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_15_1) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff2f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_QI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_basic_Unprefixed_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_basic_Unprefixed_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_basic_Unprefixed_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_subx32_imm_G_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_16_HI_Imm_32_HI_basic_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xff3f0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_16_HI_Imm_32_HI_basic_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_16_HI_Imm_32_HI_basic_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_24_HI_Imm_40_HI_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_24_HI_Imm_40_HI_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_24_HI_Imm_40_HI_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_32_HI_Imm_48_HI_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_48_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_32_HI_Imm_48_HI_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_48_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_32_HI_Imm_48_HI_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_48_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_32_HI_Imm_48_HI_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_48_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_40_HI_Imm_56_HI_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_56_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_w_Imm_40_HI_Imm_56_HI_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_56_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S16) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_16_QI_Imm_24_QI_basic_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_16_QI_Imm_24_QI_basic_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_16_QI_Imm_24_QI_basic_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_24_QI_Imm_32_QI_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_24_QI_Imm_32_QI_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_24_QI_Imm_32_QI_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_32_QI_Imm_40_QI_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_32_QI_Imm_40_QI_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_32_QI_Imm_40_QI_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_32_QI_Imm_40_QI_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_40_QI_Imm_48_QI_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_48_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx32_b_Imm_40_QI_Imm_48_QI_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_48_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stz16_b_S_imm8_dst3_dst16_3_S_R0l_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_5_3) }, { F (F_4_1) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stz16_b_S_imm8_dst3_dst16_3_S_R0h_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_5_3) }, { F (F_4_1) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stz16_b_S_imm8_dst3_dst16_3_S_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_4) }, { F (F_5_3) }, { F (F_DSP_16_U8) }, { F (F_4_1) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stz16_b_S_imm8_dst3_dst16_3_S_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_4) }, { F (F_5_3) }, { F (F_DSP_16_S8) }, { F (F_4_1) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stz16_b_S_imm8_dst3_dst16_3_S_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_4) }, { F (F_5_3) }, { F (F_DSP_16_U16) }, { F (F_4_1) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff3f, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_l_dst_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff3f, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_dst_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff3f, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_dst_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_dst_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_dst_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff30, { { F (F_0_3) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_w_imm4_Q_16_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff30, { { F (F_0_3) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl32_b_imm4_Q_16_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0c, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_w_imm4_Q_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0c, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_shl16_b_imm4_Q_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff30, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sccnd_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_basic_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_basic_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_w_imm4_basic_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_basic_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_basic_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz32_b_imm4_basic_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_16_8_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_16_8_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_16_8_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_16_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0e0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_16_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_16_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_basic_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0c00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_basic_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_w_imm4_basic_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_16_8_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_16_8_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_16_8_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_16_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0e0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_16_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_16_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_basic_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0c00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_basic_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbjnz16_b_imm4_basic_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_basic_Prefixed_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_basic_Prefixed_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_basic_Prefixed_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_8_Prefixed_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_8_Prefixed_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_8_Prefixed_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_16_Prefixed_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_16_Prefixed_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_16_Prefixed_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_16_Prefixed_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_24_Prefixed_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_w_imm_G_24_24_Prefixed_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_basic_Prefixed_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff3f00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_basic_Prefixed_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_basic_Prefixed_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_8_Prefixed_dst32_24_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_8_Prefixed_dst32_24_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_8_Prefixed_dst32_24_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_16_Prefixed_dst32_24_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_16_Prefixed_dst32_24_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_16_Prefixed_dst32_24_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_16_Prefixed_dst32_24_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_24_Prefixed_dst32_24_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sbb32_b_imm_G_24_24_Prefixed_dst32_24_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_w_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_rorc16_b_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_An_indirect_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_8_An_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_16_An_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_24_An_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_8_SB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_16_SB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_8_FB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_16_FB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_16_absolute_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha32_16_Unprefixed_Mova_dst32_16_24_absolute_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_An_indirect_Mova_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_16_8_An_relative_Mova_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_16_16_An_relative_Mova_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_16_8_SB_relative_Mova_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_16_16_SB_relative_Mova_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_16_8_FB_relative_Mova_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_pusha16_16_Mova_dst16_16_16_absolute_Mova_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_push16_b_s_an_An16_push_S_derived ATTRIBUTE_UNUSED = {
  8, 8, 0xf7, { { F (F_0_4) }, { F (F_4_1) }, { F (F_5_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_push16_b_s_rn_Rn16_push_S_derived ATTRIBUTE_UNUSED = {
  8, 8, 0xf7, { { F (F_0_4) }, { F (F_4_1) }, { F (F_5_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_or16_b_S_r0l_r0h_srcdst16_r0l_r0h_S_derived ATTRIBUTE_UNUSED = {
  8, 8, 0xfb, { { F (F_0_4) }, { F (F_6_2) }, { F (F_5_1) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_or16_b_S_src2_src16_2_S_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfb00, { { F (F_0_4) }, { F (F_6_2) }, { F (F_DSP_8_U8) }, { F (F_4_1) }, { F (F_DST16_RN_QI_S) }, { 0 } }
};

static const CGEN_IFMT ifmt_or16_b_S_src2_src16_2_S_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfb00, { { F (F_0_4) }, { F (F_6_2) }, { F (F_DSP_8_S8) }, { F (F_4_1) }, { F (F_DST16_RN_QI_S) }, { 0 } }
};

static const CGEN_IFMT ifmt_or16_b_S_src2_src16_2_S_16_absolute_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfb0000, { { F (F_0_4) }, { F (F_6_2) }, { F (F_DSP_8_U16) }, { F (F_4_1) }, { F (F_DST16_RN_QI_S) }, { 0 } }
};

static const CGEN_IFMT ifmt_not16_b_s_dst16_3_S_R0l_direct_QI ATTRIBUTE_UNUSED = {
  8, 8, 0xff, { { F (F_0_4) }, { F (F_5_3) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_not16_b_s_dst16_3_S_R0h_direct_QI ATTRIBUTE_UNUSED = {
  8, 8, 0xff, { { F (F_0_4) }, { F (F_5_3) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_not16_b_s_dst16_3_S_8_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_5_3) }, { F (F_DSP_8_U8) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_not16_b_s_dst16_3_S_8_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_5_3) }, { F (F_DSP_8_S8) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_not16_b_s_dst16_3_S_8_16_absolute_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_4) }, { F (F_5_3) }, { F (F_DSP_8_U16) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulex_dst32_R3_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffff, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_Rn_direct_Prefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff3f, { { F (F_0_4) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_SI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_An_direct_Prefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffbf, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_An_indirect_Prefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffbf, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_8_An_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_16_An_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_24_An_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_8_SB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_16_SB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_8_FB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_16_FB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_16_absolute_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mulu_l_dst32_24_24_absolute_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff3f, { { F (F_0_4) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffbf, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffbf, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_movhh32_src_r0l_dst32_24_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_An_indirect_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffbf, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_8_An_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_16_An_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_24_An_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_8_SB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_16_SB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_8_FB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_16_FB_relative_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_16_absolute_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mova32_src_a1_dst32_16_24_absolute_Unprefixed_Mova_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_basic_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_basic_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst_dspsp_basic_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_DSP_40_S8) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_basic_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_basic_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst_dspsp_basic_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_16_8_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_16_8_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_16_8_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_16_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_16_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_16_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_basic_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_basic_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_dst_dspsp_basic_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_16_8_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_16_8_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_16_8_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_16_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_16_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_16_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_basic_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_basic_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_dst_dspsp_basic_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_sz_dst32_2_S_8_a1_dst32_2_S_8_SB_relative_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_sz_dst32_2_S_8_a1_dst32_2_S_8_FB_relative_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_sz_dst32_2_S_16_a1_dst32_2_S_16_absolute_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_r0_dst32_2_S_8_dst32_2_S_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_r0_dst32_2_S_8_dst32_2_S_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_r0l_dst32_2_S_8_dst32_2_S_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_r0l_dst32_2_S_8_dst32_2_S_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_r0_dst32_2_S_16_dst32_2_S_16_absolute_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_r0l_dst32_2_S_16_dst32_2_S_16_absolute_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_dst32_2_S_basic_r1_dst32_2_S_R0_direct_HI ATTRIBUTE_UNUSED = {
  8, 8, 0xff, { { F (F_0_2) }, { F (F_2_2) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_dst32_2_S_basic_r1l_dst32_2_S_R0l_direct_QI ATTRIBUTE_UNUSED = {
  8, 8, 0xff, { { F (F_0_2) }, { F (F_2_2) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff2f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffbf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_SI_dst32_24_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U8) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_SI_dst32_24_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_SI_dst32_24_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_24_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_32_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_SI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U16) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_SI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_SI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_S16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_SI_dst32_32_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_32_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xff2f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xff3f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffbf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_40_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_SI_dst32_40_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_DSP_16_U24) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_SI_dst32_40_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_2) }, { F (F_DSP_16_U24) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_40_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff2f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffaf, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8f00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffaf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xff8f0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffaf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffcf00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffef00, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_SI_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffcf0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_SRC32_RN_UNPREFIXED_SI) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_SI_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_SI_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffef0000, { { F (F_0_1) }, { F (F_1_3) }, { F (F_10_1) }, { F (F_SRC32_AN_UNPREFIXED) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_S_An_src16_2_S_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfb00, { { F (F_0_4) }, { F (F_6_2) }, { F (F_DSP_8_U8) }, { F (F_4_1) }, { F (F_DST16_RN_QI_S) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_S_An_src16_2_S_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xfb00, { { F (F_0_4) }, { F (F_6_2) }, { F (F_DSP_8_S8) }, { F (F_4_1) }, { F (F_DST16_RN_QI_S) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_S_An_src16_2_S_16_absolute_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfb0000, { { F (F_0_4) }, { F (F_6_2) }, { F (F_DSP_8_U16) }, { F (F_4_1) }, { F (F_DST16_RN_QI_S) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff30, { { F (F_0_3) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_w_imm4_Q_16_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff30, { { F (F_0_3) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_b_imm4_Q_16_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0c, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_imm4_Q_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0c, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff0e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_b_imm4_Q_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_basic_Unprefixed_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xff3f0000, { { F (F_0_4) }, { F (F_DSP_16_S32) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_basic_Unprefixed_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_16_S32) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_basic_Unprefixed_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_16_S32) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_24_S32) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S32) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_S32) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_32_S32) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S32) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S32) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 64, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_S32) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 72, 0xffbf0000, { { F (F_0_4) }, { F (F_DSP_40_S32) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_imm_G_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 72, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_40_S32) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_16_16_u20a0_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_16_16_u20a0_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_16_16_u20a0_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_16_8_u20a0_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_24_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_16_8_u20a0_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_U24) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_16_8_u20a0_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_U24) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_basic_u20a0_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffc0000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_basic_u20a0_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_w_basic_u20a0_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_16_16_u20a0_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_16_16_u20a0_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_16_16_u20a0_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_16_8_u20a0_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_24_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_16_8_u20a0_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_U24) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_16_8_u20a0_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_24_U24) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_basic_u20a0_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffc0000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_basic_u20a0_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_ste_b_basic_u20a0_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_Rn_direct_Prefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff38, { { F (F_0_4) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_SI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_An_direct_Prefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffb8, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_An_indirect_Prefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffb8, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_8_An_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_16_An_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_24_An_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_8_SB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_16_SB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_8_FB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_16_FB_relative_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_16_absolute_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr3_dst32_24_24_absolute_Prefixed_SI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff38, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb8, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb8, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr2_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff38, { { F (F_0_4) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffb8, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffffb8, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc32_src_cr1_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_1) }, { F (F_21_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8c, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff8e, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff8f00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_stc16_src_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_basic_SI_dst16_Rn_direct_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffc, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_basic_SI_dst16_An_direct_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_basic_SI_dst16_An_indirect_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_16_16sa_SI_dst16_16_16_SB_relative_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_16_16sa_SI_dst16_16_16_absolute_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_16_8_SI_dst16_16_8_An_relative_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_16_8_SI_dst16_16_8_SB_relative_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_16_8_SI_dst16_16_8_FB_relative_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16a_dst16_16_20ar_SI_dst16_16_20_An_relative_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U24) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jsri16w_dst16_16_20ar_HI_dst16_16_20_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U24) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmpi16_a_16_dst16_16_16_An_relative_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_cmp32_w_S_src2_r0_HI_src32_2_S_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_cmp32_w_S_src2_r0_HI_src32_2_S_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_cmp32_w_S_src2_r0_HI_src32_2_S_16_absolute_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_cmp32_b_S_src2_r0_QI_src32_2_S_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_cmp32_b_S_src2_r0_QI_src32_2_S_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_S8) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_cmp32_b_S_src2_r0_QI_src32_2_S_16_absolute_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_2) }, { F (F_2_2) }, { F (F_DSP_8_U16) }, { F (F_4_3) }, { F (F_7_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_24_HI_Imm_40_HI_basic_Prefixed_dst32_Rn_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffff3f00, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_HI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_24_HI_Imm_40_HI_basic_Prefixed_dst32_An_direct_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_24_HI_Imm_40_HI_basic_Prefixed_dst32_An_indirect_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_24_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_32_HI_Imm_48_HI_24_8_Prefixed_dst32_24_8_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_32_HI_Imm_48_HI_24_8_Prefixed_dst32_24_8_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_32_HI_Imm_48_HI_24_8_Prefixed_dst32_24_8_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_40_HI_Imm_56_HI_24_16_Prefixed_dst32_24_16_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_56_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_40_HI_Imm_56_HI_24_16_Prefixed_dst32_24_16_SB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_56_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_40_HI_Imm_56_HI_24_16_Prefixed_dst32_24_16_FB_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_56_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_40_HI_Imm_56_HI_24_16_Prefixed_dst32_24_16_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 72, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_56_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S16) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_48_HI_Imm_64_HI_24_24_Prefixed_dst32_24_24_An_relative_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 80, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_64_S16) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_w_Imm_48_HI_Imm_64_HI_24_24_Prefixed_dst32_24_24_absolute_Prefixed_HI ATTRIBUTE_UNUSED = {
  32, 80, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_64_S16) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S16) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_24_QI_Imm_32_QI_basic_Prefixed_dst32_Rn_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffff3f00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_24_QI_Imm_32_QI_basic_Prefixed_dst32_An_direct_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_24_QI_Imm_32_QI_basic_Prefixed_dst32_An_indirect_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_32_QI_Imm_40_QI_24_8_Prefixed_dst32_24_8_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffbf00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U8) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_32_QI_Imm_40_QI_24_8_Prefixed_dst32_24_8_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_32_QI_Imm_40_QI_24_8_Prefixed_dst32_24_8_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffffff00, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_40_QI_Imm_48_QI_24_16_Prefixed_dst32_24_16_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U16) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_40_QI_Imm_48_QI_24_16_Prefixed_dst32_24_16_SB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_40_QI_Imm_48_QI_24_16_Prefixed_dst32_24_16_FB_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_S16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_40_QI_Imm_48_QI_24_16_Prefixed_dst32_24_16_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 56, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U16) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_40_S8) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_48_QI_Imm_56_QI_24_24_Prefixed_dst32_24_24_An_relative_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffbf00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DSP_24_U24) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_56_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_clip32_b_Imm_48_QI_Imm_56_QI_24_24_Prefixed_dst32_24_24_absolute_Prefixed_QI ATTRIBUTE_UNUSED = {
  32, 64, 0xffffff00, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_DSP_24_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_DSP_48_S8) }, { F (F_18_2) }, { F (F_20_4) }, { F (F_DSP_56_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_Rn_direct_Prefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xffff38, { { F (F_0_4) }, { F (F_12_3) }, { F (F_DST32_RN_PREFIXED_QI) }, { F (F_BITNO32_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_An_direct_Prefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xffffb8, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_BITNO32_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_An_indirect_Prefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xffffb8, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_DST32_AN_PREFIXED) }, { F (F_BITNO32_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_11_An_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_BITBASE32_24_U11_PREFIXED) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_19_An_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_BITBASE32_24_U19_PREFIXED) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_27_An_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 48, 0xffffb800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_1) }, { F (F_BITBASE32_24_U27_PREFIXED) }, { F (F_DST32_AN_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_11_SB_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_BITBASE32_24_U11_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_19_SB_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_BITBASE32_24_U19_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_11_FB_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_BITBASE32_24_S11_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_19_FB_relative_Prefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_BITBASE32_24_S19_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_19_absolute_Prefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_BITBASE32_24_U19_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor32_X_bit32_24_Prefixed_bit32_24_27_absolute_Prefixed ATTRIBUTE_UNUSED = {
  32, 48, 0xfffff800, { { F (F_0_4) }, { F (F_12_3) }, { F (F_16_2) }, { F (F_BITBASE32_24_U27_PREFIXED) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_15_1) }, { F (F_18_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_Rn_direct ATTRIBUTE_UNUSED = {
  24, 24, 0xfffc00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_An_direct ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_An_indirect ATTRIBUTE_UNUSED = {
  16, 16, 0xfffe, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_16_8_An_relative ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_16_16_An_relative ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_16_8_SB_relative ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_16_16_SB_relative ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_16_8_FB_relative ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bxor16_X_bit16_16_bit16_16_16_absolute ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_Rn_direct_Unprefixed ATTRIBUTE_UNUSED = {
  16, 16, 0xff38, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_BITNO32_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_An_direct_Unprefixed ATTRIBUTE_UNUSED = {
  16, 16, 0xffb8, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_BITNO32_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_An_indirect_Unprefixed ATTRIBUTE_UNUSED = {
  16, 16, 0xffb8, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_BITNO32_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_11_An_relative_Unprefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xffb800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_BITBASE32_16_U11_UNPREFIXED) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_19_An_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xffb80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_BITBASE32_16_U19_UNPREFIXED) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_27_An_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xffb80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_BITBASE32_16_U27_UNPREFIXED) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_11_SB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xfff800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U11_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_19_SB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U19_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_11_FB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xfff800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_S11_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_19_FB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_S19_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_19_absolute_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U19_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btsts32_X_bit32_16_Unprefixed_bit32_16_27_absolute_Unprefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U27_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_btst16_S_bit16_11_S_bit16_11_SB_relative_S ATTRIBUTE_UNUSED = {
  16, 16, 0xf800, { { F (F_0_2) }, { F (F_BITBASE16_U11_S) }, { F (F_2_2) }, { F (F_4_1) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_basic_Unprefixed_cond32_16_bit32_Rn_direct_Unprefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xff3800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_BITNO32_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { F (F_DSP_16_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_basic_Unprefixed_cond32_16_bit32_An_direct_Unprefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xffb800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_BITNO32_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { F (F_DSP_16_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_basic_Unprefixed_cond32_16_bit32_An_indirect_Unprefixed ATTRIBUTE_UNUSED = {
  24, 24, 0xffb800, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_BITNO32_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { F (F_DSP_16_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_8_Unprefixed_cond32_24_bit32_16_11_An_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xffb80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_BITBASE32_16_U11_UNPREFIXED) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_8_Unprefixed_cond32_24_bit32_16_11_SB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U11_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_8_Unprefixed_cond32_24_bit32_16_11_FB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_S11_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_16_Unprefixed_cond32_32_bit32_16_19_An_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xffb80000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_BITBASE32_16_U19_UNPREFIXED) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_16_Unprefixed_cond32_32_bit32_16_19_SB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U19_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_16_Unprefixed_cond32_32_bit32_16_19_FB_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_S19_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_16_Unprefixed_cond32_32_bit32_16_19_absolute_Unprefixed ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U19_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_24_Unprefixed_cond32_40_bit32_16_27_An_relative_Unprefixed ATTRIBUTE_UNUSED = {
  32, 48, 0xffb80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_BITBASE32_16_U27_UNPREFIXED) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_U8) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_bit32_16_24_Unprefixed_cond32_40_bit32_16_27_absolute_Unprefixed ATTRIBUTE_UNUSED = {
  32, 48, 0xfff80000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_BITBASE32_16_U27_UNPREFIXED) }, { F (F_7_1) }, { F (F_DSP_40_U8) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_8_cond16_24_bit16_Rn_direct ATTRIBUTE_UNUSED = {
  32, 32, 0xfffc0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_8_cond16_24_bit16_An_direct ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_8_cond16_24_bit16_16_8_An_relative ATTRIBUTE_UNUSED = {
  32, 32, 0xfffe0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_8_cond16_24_bit16_16_8_SB_relative ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_8_cond16_24_bit16_16_8_FB_relative ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_24_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_16_cond16_32_bit16_16_16_An_relative ATTRIBUTE_UNUSED = {
  32, 40, 0xfffe0000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_16_cond16_32_bit16_16_16_SB_relative ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_16_cond16_32_bit16_16_16_absolute ATTRIBUTE_UNUSED = {
  32, 40, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_4) }, { F (F_8_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_bit16_16_basic_cond16_16_bit16_An_indirect ATTRIBUTE_UNUSED = {
  24, 24, 0xfffe00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_DSP_16_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_HI ATTRIBUTE_UNUSED = {
  32, 48, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_basic_Unprefixed_dst32_Rn_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_HI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_basic_Unprefixed_dst32_An_direct_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_w_imm4_basic_Unprefixed_dst32_An_indirect_Unprefixed_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xffb00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_QI ATTRIBUTE_UNUSED = {
  32, 48, 0xfff00000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_7_1) }, { F (F_LAB_40_8) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_basic_Unprefixed_dst32_Rn_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff3000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_QI) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_basic_Unprefixed_dst32_An_direct_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz32_b_imm4_basic_Unprefixed_dst32_An_indirect_Unprefixed_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_16_8_dst16_16_8_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_16_8_dst16_16_8_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_16_8_dst16_16_8_FB_relative_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_16_16_dst16_16_16_An_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0e0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_16_16_dst16_16_16_SB_relative_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_16_16_dst16_16_16_absolute_HI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_basic_dst16_Rn_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0c00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_basic_dst16_An_direct_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_w_imm4_basic_dst16_An_indirect_HI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_16_8_dst16_16_8_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0e0000, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U8) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_16_8_dst16_16_8_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_16_8_dst16_16_8_FB_relative_QI ATTRIBUTE_UNUSED = {
  32, 32, 0xff0f0000, { { F (F_0_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_24_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_16_16_dst16_16_16_An_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0e0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DSP_16_U16) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_16_16_dst16_16_16_SB_relative_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_16_16_dst16_16_16_absolute_QI ATTRIBUTE_UNUSED = {
  32, 40, 0xff0f0000, { { F (F_0_4) }, { F (F_LAB_32_8) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_basic_dst16_Rn_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0c00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_DST16_RN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_basic_dst16_An_direct_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_adjnz16_b_imm4_basic_dst16_An_indirect_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xff0e00, { { F (F_0_4) }, { F (F_12_2) }, { F (F_14_1) }, { F (F_DST16_AN) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_IMM_8_S4) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_s_imm1_S_an_dst32_1_S_A0_direct_HI ATTRIBUTE_UNUSED = {
  8, 8, 0xdf, { { F (F_0_2) }, { F (F_7_1) }, { F (F_IMM1_S) }, { F (F_3_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_s_imm1_S_an_dst32_1_S_A1_direct_HI ATTRIBUTE_UNUSED = {
  8, 8, 0xdf, { { F (F_0_2) }, { F (F_7_1) }, { F (F_IMM1_S) }, { F (F_3_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_Rn_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xff30, { { F (F_0_3) }, { F (F_4_3) }, { F (F_DST32_RN_UNPREFIXED_SI) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_An_direct_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_An_indirect_Unprefixed_SI ATTRIBUTE_UNUSED = {
  16, 16, 0xffb0, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_8_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xffb000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U8) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U16) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_24_An_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xffb00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_1) }, { F (F_DSP_16_U24) }, { F (F_DST32_AN_UNPREFIXED) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_8_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_8_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S8) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_S16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_16_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 32, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U16) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm4_Q_16_Unprefixed_dst32_16_24_absolute_Unprefixed_SI ATTRIBUTE_UNUSED = {
  32, 40, 0xfff00000, { { F (F_0_3) }, { F (F_4_3) }, { F (F_8_2) }, { F (F_DSP_16_U24) }, { F (F_3_1) }, { F (F_7_1) }, { F (F_10_2) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add16_wQ_sp ATTRIBUTE_UNUSED = {
  16, 16, 0xfff0, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_add16_b_G_sp ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_add16_w_G_sp ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_3) }, { F (F_7_1) }, { F (F_8_4) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm3_Q ATTRIBUTE_UNUSED = {
  8, 8, 0xce, { { F (F_0_2) }, { F (F_IMM3_S) }, { F (F_4_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm8_S ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_add32_l_imm16_G ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_dadc16_b_r0h_r0l ATTRIBUTE_UNUSED = {
  16, 16, 0xffff, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm16_c ATTRIBUTE_UNUSED = {
  16, 16, 0xfff0, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_COND16) }, { 0 } }
};

static const CGEN_IFMT ifmt_bm32_c ATTRIBUTE_UNUSED = {
  16, 16, 0xffb8, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_COND32) }, { F (F_10_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_brk16 ATTRIBUTE_UNUSED = {
  8, 8, 0xff, { { F (F_0_4) }, { F (F_4_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_btst_s ATTRIBUTE_UNUSED = {
  24, 24, 0xce0000, { { F (F_0_2) }, { F (F_IMM3_S) }, { F (F_4_3) }, { F (F_DSP_8_U16) }, { 0 } }
};

static const CGEN_IFMT ifmt_dec16_w ATTRIBUTE_UNUSED = {
  8, 8, 0xf7, { { F (F_0_4) }, { F (F_DST16_AN_S) }, { F (F_5_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_div32_b_Imm_16_QI ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_3) }, { F (F_11_1) }, { F (F_12_4) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_div32_w_Imm_16_HI ATTRIBUTE_UNUSED = {
  32, 32, 0xffff0000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_3) }, { F (F_11_1) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_enter16 ATTRIBUTE_UNUSED = {
  24, 24, 0xffff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_4) }, { F (F_DSP_16_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_enter32 ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_U8) }, { 0 } }
};

static const CGEN_IFMT ifmt_fclr16 ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_fclr ATTRIBUTE_UNUSED = {
  16, 16, 0xfff8, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_int16 ATTRIBUTE_UNUSED = {
  16, 16, 0xffc0, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_2) }, { F (F_DSP_10_U6) }, { 0 } }
};

static const CGEN_IFMT ifmt_int32 ATTRIBUTE_UNUSED = {
  16, 16, 0xff03, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_U6) }, { F (F_14_2) }, { 0 } }
};

static const CGEN_IFMT ifmt_jcnd16_5 ATTRIBUTE_UNUSED = {
  16, 16, 0xf800, { { F (F_0_4) }, { F (F_4_1) }, { F (F_COND16J_5) }, { F (F_LAB_8_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_jcnd16 ATTRIBUTE_UNUSED = {
  24, 24, 0xfff000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_COND16) }, { F (F_LAB_16_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_jcnd32 ATTRIBUTE_UNUSED = {
  16, 16, 0x8e00, { { F (F_0_1) }, { F (F_COND32J) }, { F (F_4_3) }, { F (F_LAB_8_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmp16_s ATTRIBUTE_UNUSED = {
  8, 8, 0xf8, { { F (F_0_4) }, { F (F_4_1) }, { F (F_LAB_5_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmp16_b ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_LAB_8_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmp16_w ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_LAB_8_16) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmp16_a ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_LAB_8_24) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmps16 ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_jmp32_s ATTRIBUTE_UNUSED = {
  8, 8, 0xce, { { F (F_0_2) }, { F (F_LAB32_JMP_S) }, { F (F_4_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldc16_imm16 ATTRIBUTE_UNUSED = {
  32, 32, 0xff8f0000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { F (F_12_4) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldc32_imm16_cr1 ATTRIBUTE_UNUSED = {
  32, 32, 0xfff80000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_13_3) }, { F (F_DSP_16_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldc32_imm16_cr2 ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldc32_imm16_cr3 ATTRIBUTE_UNUSED = {
  32, 40, 0xfff80000, { { F (F_0_4) }, { F (F_DSP_16_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldctx16 ATTRIBUTE_UNUSED = {
  32, 56, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_32_U24) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_4) }, { F (F_DSP_16_U16) }, { 0 } }
};

static const CGEN_IFMT ifmt_ldipl16_imm ATTRIBUTE_UNUSED = {
  16, 16, 0xfff8, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_IMM_13_U3) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov16_w_S_imm_a0 ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_S16) }, { 0 } }
};

static const CGEN_IFMT ifmt_mov32_l_a0 ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_S24) }, { 0 } }
};

static const CGEN_IFMT ifmt_popc16_imm16 ATTRIBUTE_UNUSED = {
  16, 16, 0xff8f, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_1) }, { F (F_9_3) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_popc32_imm16_cr1 ATTRIBUTE_UNUSED = {
  16, 16, 0xfff8, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_popc32_imm16_cr2 ATTRIBUTE_UNUSED = {
  16, 16, 0xfff8, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_1) }, { F (F_13_3) }, { 0 } }
};

static const CGEN_IFMT ifmt_popm16 ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_pushm16 ATTRIBUTE_UNUSED = {
  16, 16, 0xff00, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_8) }, { 0 } }
};

static const CGEN_IFMT ifmt_push32_l_imm ATTRIBUTE_UNUSED = {
  32, 48, 0xffff0000, { { F (F_0_4) }, { F (F_DSP_16_S32) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_12_4) }, { 0 } }
};

static const CGEN_IFMT ifmt_sha16_L_imm_r2r0 ATTRIBUTE_UNUSED = {
  16, 16, 0xfff0, { { F (F_0_4) }, { F (F_4_4) }, { F (F_8_4) }, { F (F_IMM_12_S4) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx16_imm8_imm8_r0h ATTRIBUTE_UNUSED = {
  24, 24, 0xff0000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_S8) }, { F (F_DSP_16_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx16_imm8_imm8_dsp8sb ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_S8) }, { F (F_DSP_16_U8) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx16_imm8_imm8_dsp8fb ATTRIBUTE_UNUSED = {
  32, 32, 0xff000000, { { F (F_0_4) }, { F (F_4_4) }, { F (F_DSP_8_S8) }, { F (F_DSP_16_S8) }, { F (F_DSP_24_S8) }, { 0 } }
};

static const CGEN_IFMT ifmt_stzx16_imm8_imm8_abs16 ATTRIBUTE_UNUSED = {
  32, 40, 0xff000000, { { F (F_0_4) }, { F (F_DSP_32_S8) }, { F (F_4_4) }, { F (F_DSP_8_S8) }, { F (F_DSP_16_U16) }, { 0 } }
};

#undef F

#define A(a) (1 << CGEN_INSN_##a)
#define OPERAND(op) M32C_OPERAND_##op
#define MNEM CGEN_SYNTAX_MNEMONIC /* syntax value for mnemonic */
#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))

/* The instruction table.  */

static const CGEN_OPCODE m32c_cgen_insn_opcode_table[MAX_INSNS] =
{
  /* Special null first entry.
     A `num' value of zero is thus invalid.
     Also, the special `invalid' insn resides here.  */
  { { 0, 0, 0, 0 }, {{0}}, 0, {0}},
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1980b00 }
  },
/* extz ${Dsp-24-u8}[sb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1982b00 }
  },
/* extz ${Dsp-24-s8}[fb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1983b00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1908b00 }
  },
/* extz ${Dsp-24-u8}[sb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x190ab00 }
  },
/* extz ${Dsp-24-s8}[fb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x190bb00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1900b00 }
  },
/* extz ${Dsp-24-u8}[sb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1902b00 }
  },
/* extz ${Dsp-24-s8}[fb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1903b00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI, { 0x1920b00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI, { 0x1922b00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI, { 0x1923b00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI, { 0x1940b00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI, { 0x1942b00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI, { 0x1943b00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI, { 0x1960b00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI, { 0x1962b00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI, { 0x1963b00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI, { 0x1928b00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI, { 0x192ab00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI, { 0x192bb00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI, { 0x1948b00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI, { 0x194ab00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI, { 0x194bb00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI, { 0x192cb00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI, { 0x192eb00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI, { 0x192fb00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI, { 0x194cb00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI, { 0x194eb00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI, { 0x194fb00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI, { 0x196cb00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI, { 0x196eb00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI, { 0x196fb00 }
  },
/* extz ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI, { 0x1968b00 }
  },
/* extz ${Dsp-24-u8}[sb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI, { 0x196ab00 }
  },
/* extz ${Dsp-24-s8}[fb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI, { 0x196bb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1a80b00 }
  },
/* extz ${Dsp-24-u16}[sb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1a82b00 }
  },
/* extz ${Dsp-24-s16}[fb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1a83b00 }
  },
/* extz ${Dsp-24-u16},$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1b83b00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1a08b00 }
  },
/* extz ${Dsp-24-u16}[sb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1a0ab00 }
  },
/* extz ${Dsp-24-s16}[fb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1a0bb00 }
  },
/* extz ${Dsp-24-u16},$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1b0bb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1a00b00 }
  },
/* extz ${Dsp-24-u16}[sb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1a02b00 }
  },
/* extz ${Dsp-24-s16}[fb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1a03b00 }
  },
/* extz ${Dsp-24-u16},[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1b03b00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a20b00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a22b00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a23b00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1b23b00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a40b00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a42b00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a43b00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1b43b00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a60b00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a62b00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a63b00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1b63b00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a28b00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a2ab00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a2bb00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1b2bb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a48b00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a4ab00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a4bb00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1b4bb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a2cb00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a2eb00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a2fb00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1b2fb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a4cb00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a4eb00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a4fb00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1b4fb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1a6cb00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1a6eb00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1a6fb00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1b6fb00 }
  },
/* extz ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1a68b00 }
  },
/* extz ${Dsp-24-u16}[sb],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1a6ab00 }
  },
/* extz ${Dsp-24-s16}[fb],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1a6bb00 }
  },
/* extz ${Dsp-24-u16},${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1b6bb00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1b80b00 }
  },
/* extz ${Dsp-24-u24},$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1b82b00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1b08b00 }
  },
/* extz ${Dsp-24-u24},$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1b0ab00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1b00b00 }
  },
/* extz ${Dsp-24-u24},[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1b02b00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_An_relative_Prefixed_HI, { 0x1b20b00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_An_relative_Prefixed_HI, { 0x1b22b00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_An_relative_Prefixed_HI, { 0x1b40b00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_An_relative_Prefixed_HI, { 0x1b42b00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_An_relative_Prefixed_HI, { 0x1b60b00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_An_relative_Prefixed_HI, { 0x1b62b00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_HI, { 0x1b28b00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_HI, { 0x1b2ab00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_HI, { 0x1b48b00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_HI, { 0x1b4ab00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_HI, { 0x1b2cb00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_HI, { 0x1b2eb00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_HI, { 0x1b4cb00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_HI, { 0x1b4eb00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_absolute_Prefixed_HI, { 0x1b6cb00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_absolute_Prefixed_HI, { 0x1b6eb00 }
  },
/* extz ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U24), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_absolute_Prefixed_HI, { 0x1b68b00 }
  },
/* extz ${Dsp-24-u24},${Dsp-48-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U24), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_absolute_Prefixed_HI, { 0x1b6ab00 }
  },
/* extz $Src32RnPrefixedQI,$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1c80b }
  },
/* extz [$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1880b }
  },
/* extz $Src32RnPrefixedQI,$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1c08b }
  },
/* extz [$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1808b }
  },
/* extz $Src32RnPrefixedQI,[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1c00b }
  },
/* extz [$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1800b }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_An_relative_Prefixed_HI, { 0x1c20b00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_An_relative_Prefixed_HI, { 0x1820b00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_An_relative_Prefixed_HI, { 0x1c40b00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_An_relative_Prefixed_HI, { 0x1840b00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_An_relative_Prefixed_HI, { 0x1c60b00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_An_relative_Prefixed_HI, { 0x1860b00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_HI, { 0x1c28b00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_HI, { 0x1828b00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_HI, { 0x1c48b00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_HI, { 0x1848b00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_HI, { 0x1c2cb00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_HI, { 0x182cb00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_HI, { 0x1c4cb00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_HI, { 0x184cb00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U16), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_absolute_Prefixed_HI, { 0x1c6cb00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_absolute_Prefixed_HI, { 0x186cb00 }
  },
/* extz $Src32RnPrefixedQI,${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U24), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_absolute_Prefixed_HI, { 0x1c68b00 }
  },
/* extz [$Src32AnPrefixed],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_absolute_Prefixed_HI, { 0x1868b00 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1980700 }
  },
/* exts.b ${Dsp-24-u8}[sb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1982700 }
  },
/* exts.b ${Dsp-24-s8}[fb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1983700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1908700 }
  },
/* exts.b ${Dsp-24-u8}[sb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x190a700 }
  },
/* exts.b ${Dsp-24-s8}[fb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x190b700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1900700 }
  },
/* exts.b ${Dsp-24-u8}[sb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1902700 }
  },
/* exts.b ${Dsp-24-s8}[fb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1903700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI, { 0x1920700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI, { 0x1922700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_An_relative_Prefixed_HI, { 0x1923700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI, { 0x1940700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI, { 0x1942700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_An_relative_Prefixed_HI, { 0x1943700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI, { 0x1960700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI, { 0x1962700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_An_relative_Prefixed_HI, { 0x1963700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI, { 0x1928700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI, { 0x192a700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_SB_relative_Prefixed_HI, { 0x192b700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI, { 0x1948700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI, { 0x194a700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_SB_relative_Prefixed_HI, { 0x194b700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI, { 0x192c700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI, { 0x192e700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_8_FB_relative_Prefixed_HI, { 0x192f700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI, { 0x194c700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI, { 0x194e700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_FB_relative_Prefixed_HI, { 0x194f700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI, { 0x196c700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI, { 0x196e700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_16_absolute_Prefixed_HI, { 0x196f700 }
  },
/* exts.b ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI, { 0x1968700 }
  },
/* exts.b ${Dsp-24-u8}[sb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI, { 0x196a700 }
  },
/* exts.b ${Dsp-24-s8}[fb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_extz32_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_QI_dst32_32_24_absolute_Prefixed_HI, { 0x196b700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1a80700 }
  },
/* exts.b ${Dsp-24-u16}[sb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1a82700 }
  },
/* exts.b ${Dsp-24-s16}[fb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1a83700 }
  },
/* exts.b ${Dsp-24-u16},$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1b83700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1a08700 }
  },
/* exts.b ${Dsp-24-u16}[sb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1a0a700 }
  },
/* exts.b ${Dsp-24-s16}[fb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1a0b700 }
  },
/* exts.b ${Dsp-24-u16},$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1b0b700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1a00700 }
  },
/* exts.b ${Dsp-24-u16}[sb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1a02700 }
  },
/* exts.b ${Dsp-24-s16}[fb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1a03700 }
  },
/* exts.b ${Dsp-24-u16},[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1b03700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a20700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a22700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a23700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_An_relative_Prefixed_HI, { 0x1b23700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a40700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a42700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a43700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_An_relative_Prefixed_HI, { 0x1b43700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a60700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a62700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a63700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_An_relative_Prefixed_HI, { 0x1b63700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a28700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a2a700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a2b700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1b2b700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a48700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a4a700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a4b700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1b4b700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a2c700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a2e700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a2f700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1b2f700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a4c700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a4e700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a4f700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1b4f700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1a6c700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1a6e700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1a6f700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_16_absolute_Prefixed_HI, { 0x1b6f700 }
  },
/* exts.b ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1a68700 }
  },
/* exts.b ${Dsp-24-u16}[sb],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1a6a700 }
  },
/* exts.b ${Dsp-24-s16}[fb],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1a6b700 }
  },
/* exts.b ${Dsp-24-u16},${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U16), ',', OP (DSP_40_U24), 0 } },
    & ifmt_extz32_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_QI_dst32_40_24_absolute_Prefixed_HI, { 0x1b6b700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1b80700 }
  },
/* exts.b ${Dsp-24-u24},$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1b82700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1b08700 }
  },
/* exts.b ${Dsp-24-u24},$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1b0a700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1b00700 }
  },
/* exts.b ${Dsp-24-u24},[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1b02700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_An_relative_Prefixed_HI, { 0x1b20700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_An_relative_Prefixed_HI, { 0x1b22700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_An_relative_Prefixed_HI, { 0x1b40700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_An_relative_Prefixed_HI, { 0x1b42700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_An_relative_Prefixed_HI, { 0x1b60700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_An_relative_Prefixed_HI, { 0x1b62700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_HI, { 0x1b28700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_SB_relative_Prefixed_HI, { 0x1b2a700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_HI, { 0x1b48700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_SB_relative_Prefixed_HI, { 0x1b4a700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_HI, { 0x1b2c700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_8_FB_relative_Prefixed_HI, { 0x1b2e700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_HI, { 0x1b4c700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_FB_relative_Prefixed_HI, { 0x1b4e700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_16_absolute_Prefixed_HI, { 0x1b6c700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_16_absolute_Prefixed_HI, { 0x1b6e700 }
  },
/* exts.b ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U24), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_QI_dst32_48_24_absolute_Prefixed_HI, { 0x1b68700 }
  },
/* exts.b ${Dsp-24-u24},${Dsp-48-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_24_U24), ',', OP (DSP_48_U24), 0 } },
    & ifmt_extz32_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_QI_dst32_48_24_absolute_Prefixed_HI, { 0x1b6a700 }
  },
/* exts.b $Src32RnPrefixedQI,$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x1c807 }
  },
/* exts.b [$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_Rn_direct_Prefixed_HI, { 0x18807 }
  },
/* exts.b $Src32RnPrefixedQI,$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x1c087 }
  },
/* exts.b [$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_direct_Prefixed_HI, { 0x18087 }
  },
/* exts.b $Src32RnPrefixedQI,[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x1c007 }
  },
/* exts.b [$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_An_indirect_Prefixed_HI, { 0x18007 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_An_relative_Prefixed_HI, { 0x1c20700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_An_relative_Prefixed_HI, { 0x1820700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_An_relative_Prefixed_HI, { 0x1c40700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_An_relative_Prefixed_HI, { 0x1840700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_An_relative_Prefixed_HI, { 0x1c60700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_An_relative_Prefixed_HI, { 0x1860700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_HI, { 0x1c28700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_SB_relative_Prefixed_HI, { 0x1828700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_HI, { 0x1c48700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_SB_relative_Prefixed_HI, { 0x1848700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_HI, { 0x1c2c700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_8_FB_relative_Prefixed_HI, { 0x182c700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_HI, { 0x1c4c700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_FB_relative_Prefixed_HI, { 0x184c700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U16), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_16_absolute_Prefixed_HI, { 0x1c6c700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_16_absolute_Prefixed_HI, { 0x186c700 }
  },
/* exts.b $Src32RnPrefixedQI,${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (SRC32RNPREFIXEDQI), ',', OP (DSP_24_U24), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_Rn_direct_Prefixed_QI_dst32_24_24_absolute_Prefixed_HI, { 0x1c68700 }
  },
/* exts.b [$Src32AnPrefixed],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_extz32_basic_ExtPrefixed_24_Prefixed_src32_An_indirect_Prefixed_QI_dst32_24_24_absolute_Prefixed_HI, { 0x1868700 }
  },
/* exts.w $Dst32RnExtUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DST32RNEXTUNPREFIXEDHI), 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_Rn_direct_ExtUnprefixed_HI, { 0xc99e }
  },
/* exts.w $Dst32AnUnprefixedSI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DST32ANUNPREFIXEDSI), 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_An_direct_Unprefixed_SI, { 0xc19e }
  },
/* exts.w [$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_An_indirect_ExtUnprefixed_HI, { 0xc11e }
  },
/* exts.w ${Dsp-16-u8}[$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U8), '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_8_An_relative_ExtUnprefixed_HI, { 0xc31e00 }
  },
/* exts.w ${Dsp-16-u16}[$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_An_relative_ExtUnprefixed_HI, { 0xc51e0000 }
  },
/* exts.w ${Dsp-16-u24}[$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U24), '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_24_An_relative_ExtUnprefixed_HI, { 0xc71e0000 }
  },
/* exts.w ${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_8_SB_relative_ExtUnprefixed_HI, { 0xc39e00 }
  },
/* exts.w ${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_SB_relative_ExtUnprefixed_HI, { 0xc59e0000 }
  },
/* exts.w ${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_8_FB_relative_ExtUnprefixed_HI, { 0xc3de00 }
  },
/* exts.w ${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_FB_relative_ExtUnprefixed_HI, { 0xc5de0000 }
  },
/* exts.w ${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_16_absolute_ExtUnprefixed_HI, { 0xc7de0000 }
  },
/* exts.w ${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U24), 0 } },
    & ifmt_exts32_w_16_ExtUnprefixed_dst32_16_24_absolute_ExtUnprefixed_HI, { 0xc79e0000 }
  },
/* exts.b $Dst32RnExtUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DST32RNEXTUNPREFIXEDQI), 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_Rn_direct_ExtUnprefixed_QI, { 0xc89e }
  },
/* exts.b $Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_An_direct_Unprefixed_HI, { 0xc09e }
  },
/* exts.b [$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_An_indirect_ExtUnprefixed_QI, { 0xc01e }
  },
/* exts.b ${Dsp-16-u8}[$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U8), '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_8_An_relative_ExtUnprefixed_QI, { 0xc21e00 }
  },
/* exts.b ${Dsp-16-u16}[$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_An_relative_ExtUnprefixed_QI, { 0xc41e0000 }
  },
/* exts.b ${Dsp-16-u24}[$Dst32AnExtUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U24), '[', OP (DST32ANEXTUNPREFIXED), ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_24_An_relative_ExtUnprefixed_QI, { 0xc61e0000 }
  },
/* exts.b ${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_8_SB_relative_ExtUnprefixed_QI, { 0xc29e00 }
  },
/* exts.b ${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_SB_relative_ExtUnprefixed_QI, { 0xc49e0000 }
  },
/* exts.b ${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_8_FB_relative_ExtUnprefixed_QI, { 0xc2de00 }
  },
/* exts.b ${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_FB_relative_ExtUnprefixed_QI, { 0xc4de0000 }
  },
/* exts.b ${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_16_absolute_ExtUnprefixed_QI, { 0xc6de0000 }
  },
/* exts.b ${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U24), 0 } },
    & ifmt_exts32_b_16_ExtUnprefixed_dst32_16_24_absolute_ExtUnprefixed_QI, { 0xc69e0000 }
  },
/* exts.b $Dst16RnExtQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DST16RNEXTQI), 0 } },
    & ifmt_exts16_b_16_Ext_dst16_Rn_direct_Ext_QI, { 0x7c60 }
  },
/* exts.b [$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', '[', OP (DST16AN), ']', 0 } },
    & ifmt_exts16_b_16_Ext_dst16_An_indirect_Ext_QI, { 0x7c66 }
  },
/* exts.b ${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_exts16_b_16_Ext_dst16_16_8_An_relative_Ext_QI, { 0x7c6800 }
  },
/* exts.b ${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_exts16_b_16_Ext_dst16_16_16_An_relative_Ext_QI, { 0x7c6c0000 }
  },
/* exts.b ${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_exts16_b_16_Ext_dst16_16_8_SB_relative_Ext_QI, { 0x7c6a00 }
  },
/* exts.b ${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_exts16_b_16_Ext_dst16_16_16_SB_relative_Ext_QI, { 0x7c6e0000 }
  },
/* exts.b ${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_exts16_b_16_Ext_dst16_16_8_FB_relative_Ext_QI, { 0x7c6b00 }
  },
/* exts.b ${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (DSP_16_U16), 0 } },
    & ifmt_exts16_b_16_Ext_dst16_16_16_absolute_Ext_QI, { 0x7c6f0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0x990900 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0x992900 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0x993900 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0x918900 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0x91a900 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0x91b900 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0x910900 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0x912900 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0x913900 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_8_An_relative_Unprefixed_HI, { 0x93090000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_8_An_relative_Unprefixed_HI, { 0x93290000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_8_An_relative_Unprefixed_HI, { 0x93390000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_An_relative_Unprefixed_HI, { 0x95090000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_An_relative_Unprefixed_HI, { 0x95290000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_An_relative_Unprefixed_HI, { 0x95390000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_24_An_relative_Unprefixed_HI, { 0x97090000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_24_An_relative_Unprefixed_HI, { 0x97290000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_24_An_relative_Unprefixed_HI, { 0x97390000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_8_SB_relative_Unprefixed_HI, { 0x93890000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_8_SB_relative_Unprefixed_HI, { 0x93a90000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_8_SB_relative_Unprefixed_HI, { 0x93b90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_SB_relative_Unprefixed_HI, { 0x95890000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_SB_relative_Unprefixed_HI, { 0x95a90000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_SB_relative_Unprefixed_HI, { 0x95b90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_8_FB_relative_Unprefixed_HI, { 0x93c90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_8_FB_relative_Unprefixed_HI, { 0x93e90000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_8_FB_relative_Unprefixed_HI, { 0x93f90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_FB_relative_Unprefixed_HI, { 0x95c90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_FB_relative_Unprefixed_HI, { 0x95e90000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_FB_relative_Unprefixed_HI, { 0x95f90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_16_absolute_Unprefixed_HI, { 0x97c90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_16_absolute_Unprefixed_HI, { 0x97e90000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_16_absolute_Unprefixed_HI, { 0x97f90000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_HI_dst32_24_24_absolute_Unprefixed_HI, { 0x97890000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_HI_dst32_24_24_absolute_Unprefixed_HI, { 0x97a90000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_xor32_w_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_HI_dst32_24_24_absolute_Unprefixed_HI, { 0x97b90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xa9090000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xa9290000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xa9390000 }
  },
/* xor.w${G} ${Dsp-16-u16},$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xb9390000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xa1890000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xa1a90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xa1b90000 }
  },
/* xor.w${G} ${Dsp-16-u16},$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xb1b90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xa1090000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xa1290000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xa1390000 }
  },
/* xor.w${G} ${Dsp-16-u16},[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xb1390000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI, { 0xa3090000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI, { 0xa3290000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI, { 0xa3390000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_8_An_relative_Unprefixed_HI, { 0xb3390000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI, { 0xa5090000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI, { 0xa5290000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI, { 0xa5390000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_An_relative_Unprefixed_HI, { 0xb5390000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI, { 0xa7090000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI, { 0xa7290000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI, { 0xa7390000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_24_An_relative_Unprefixed_HI, { 0xb7390000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI, { 0xa3890000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI, { 0xa3a90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI, { 0xa3b90000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_8_SB_relative_Unprefixed_HI, { 0xb3b90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI, { 0xa5890000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI, { 0xa5a90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI, { 0xa5b90000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_SB_relative_Unprefixed_HI, { 0xb5b90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI, { 0xa3c90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI, { 0xa3e90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI, { 0xa3f90000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_8_FB_relative_Unprefixed_HI, { 0xb3f90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI, { 0xa5c90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI, { 0xa5e90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI, { 0xa5f90000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_FB_relative_Unprefixed_HI, { 0xb5f90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI, { 0xa7c90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI, { 0xa7e90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI, { 0xa7f90000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_16_absolute_Unprefixed_HI, { 0xb7f90000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI, { 0xa7890000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI, { 0xa7a90000 }
  },
/* xor.w${G} ${Dsp-16-s16}[fb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI, { 0xa7b90000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_w_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_HI_dst32_32_24_absolute_Unprefixed_HI, { 0xb7b90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xb9090000 }
  },
/* xor.w${G} ${Dsp-16-u24},$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xb9290000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xb1890000 }
  },
/* xor.w${G} ${Dsp-16-u24},$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xb1a90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xb1090000 }
  },
/* xor.w${G} ${Dsp-16-u24},[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xb1290000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_8_An_relative_Unprefixed_HI, { 0xb3090000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_8_An_relative_Unprefixed_HI, { 0xb3290000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_An_relative_Unprefixed_HI, { 0xb5090000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_An_relative_Unprefixed_HI, { 0xb5290000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_24_An_relative_Unprefixed_HI, { 0xb7090000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_24_An_relative_Unprefixed_HI, { 0xb7290000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_8_SB_relative_Unprefixed_HI, { 0xb3890000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_8_SB_relative_Unprefixed_HI, { 0xb3a90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_SB_relative_Unprefixed_HI, { 0xb5890000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_SB_relative_Unprefixed_HI, { 0xb5a90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_8_FB_relative_Unprefixed_HI, { 0xb3c90000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_8_FB_relative_Unprefixed_HI, { 0xb3e90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_FB_relative_Unprefixed_HI, { 0xb5c90000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_FB_relative_Unprefixed_HI, { 0xb5e90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_16_absolute_Unprefixed_HI, { 0xb7c90000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U16), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_16_absolute_Unprefixed_HI, { 0xb7e90000 }
  },
/* xor.w${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_HI_dst32_40_24_absolute_Unprefixed_HI, { 0xb7890000 }
  },
/* xor.w${G} ${Dsp-16-u24},${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U24), 0 } },
    & ifmt_xor32_w_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_HI_dst32_40_24_absolute_Unprefixed_HI, { 0xb7a90000 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0xc909 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0x8929 }
  },
/* xor.w${G} [$Src32AnUnprefixed],$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_Rn_direct_Unprefixed_HI, { 0x8909 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0xc189 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0x81a9 }
  },
/* xor.w${G} [$Src32AnUnprefixed],$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_An_direct_Unprefixed_HI, { 0x8189 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0xc109 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0x8129 }
  },
/* xor.w${G} [$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_An_indirect_Unprefixed_HI, { 0x8109 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_8_An_relative_Unprefixed_HI, { 0xc30900 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_8_An_relative_Unprefixed_HI, { 0x832900 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_8_An_relative_Unprefixed_HI, { 0x830900 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_An_relative_Unprefixed_HI, { 0xc5090000 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_An_relative_Unprefixed_HI, { 0x85290000 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_An_relative_Unprefixed_HI, { 0x85090000 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_24_An_relative_Unprefixed_HI, { 0xc7090000 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_24_An_relative_Unprefixed_HI, { 0x87290000 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_24_An_relative_Unprefixed_HI, { 0x87090000 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_8_SB_relative_Unprefixed_HI, { 0xc38900 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_8_SB_relative_Unprefixed_HI, { 0x83a900 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_8_SB_relative_Unprefixed_HI, { 0x838900 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_SB_relative_Unprefixed_HI, { 0xc5890000 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_SB_relative_Unprefixed_HI, { 0x85a90000 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_SB_relative_Unprefixed_HI, { 0x85890000 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_8_FB_relative_Unprefixed_HI, { 0xc3c900 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_8_FB_relative_Unprefixed_HI, { 0x83e900 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_8_FB_relative_Unprefixed_HI, { 0x83c900 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_FB_relative_Unprefixed_HI, { 0xc5c90000 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_FB_relative_Unprefixed_HI, { 0x85e90000 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_FB_relative_Unprefixed_HI, { 0x85c90000 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_16_absolute_Unprefixed_HI, { 0xc7c90000 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_16_absolute_Unprefixed_HI, { 0x87e90000 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_16_absolute_Unprefixed_HI, { 0x87c90000 }
  },
/* xor.w${G} $Src32RnUnprefixedHI,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDHI), ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_HI_dst32_16_24_absolute_Unprefixed_HI, { 0xc7890000 }
  },
/* xor.w${G} $Src32AnUnprefixedHI,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDHI), ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_HI_dst32_16_24_absolute_Unprefixed_HI, { 0x87a90000 }
  },
/* xor.w${G} [$Src32AnUnprefixed],${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_w_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_HI_dst32_16_24_absolute_Unprefixed_HI, { 0x87890000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0x980900 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0x982900 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0x983900 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0x908900 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0x90a900 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0x90b900 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0x900900 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0x902900 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0x903900 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_QI, { 0x92090000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_QI, { 0x92290000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_An_relative_Unprefixed_QI, { 0x92390000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_QI, { 0x94090000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_QI, { 0x94290000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_An_relative_Unprefixed_QI, { 0x94390000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_QI, { 0x96090000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_QI, { 0x96290000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_24_An_relative_Unprefixed_QI, { 0x96390000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_QI, { 0x92890000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_QI, { 0x92a90000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_SB_relative_Unprefixed_QI, { 0x92b90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_QI, { 0x94890000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_QI, { 0x94a90000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_SB_relative_Unprefixed_QI, { 0x94b90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_QI, { 0x92c90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_QI, { 0x92e90000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_8_FB_relative_Unprefixed_QI, { 0x92f90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_QI, { 0x94c90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_QI, { 0x94e90000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_FB_relative_Unprefixed_QI, { 0x94f90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_QI, { 0x96c90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_QI, { 0x96e90000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_16_absolute_Unprefixed_QI, { 0x96f90000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src32AnUnprefixed],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_An_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_QI, { 0x96890000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_SB_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_QI, { 0x96a90000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U24), 0 } },
    & ifmt_xor32_b_16_8_Unprefixed_24_Unprefixed_src32_16_8_FB_relative_Unprefixed_QI_dst32_24_24_absolute_Unprefixed_QI, { 0x96b90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xa8090000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xa8290000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xa8390000 }
  },
/* xor.b${G} ${Dsp-16-u16},$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xb8390000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xa0890000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xa0a90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xa0b90000 }
  },
/* xor.b${G} ${Dsp-16-u16},$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xb0b90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xa0090000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xa0290000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xa0390000 }
  },
/* xor.b${G} ${Dsp-16-u16},[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xb0390000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI, { 0xa2090000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI, { 0xa2290000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI, { 0xa2390000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_An_relative_Unprefixed_QI, { 0xb2390000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI, { 0xa4090000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI, { 0xa4290000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI, { 0xa4390000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_An_relative_Unprefixed_QI, { 0xb4390000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI, { 0xa6090000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI, { 0xa6290000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI, { 0xa6390000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_24_An_relative_Unprefixed_QI, { 0xb6390000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI, { 0xa2890000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI, { 0xa2a90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI, { 0xa2b90000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_SB_relative_Unprefixed_QI, { 0xb2b90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI, { 0xa4890000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI, { 0xa4a90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI, { 0xa4b90000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_SB_relative_Unprefixed_QI, { 0xb4b90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI, { 0xa2c90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI, { 0xa2e90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI, { 0xa2f90000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_8_FB_relative_Unprefixed_QI, { 0xb2f90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI, { 0xa4c90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI, { 0xa4e90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI, { 0xa4f90000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_FB_relative_Unprefixed_QI, { 0xb4f90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI, { 0xa6c90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI, { 0xa6e90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI, { 0xa6f90000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_16_absolute_Unprefixed_QI, { 0xb6f90000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src32AnUnprefixed],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_An_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI, { 0xa6890000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_SB_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI, { 0xa6a90000 }
  },
/* xor.b${G} ${Dsp-16-s16}[fb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S16), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_FB_relative_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI, { 0xa6b90000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U24), 0 } },
    & ifmt_xor32_b_16_16_Unprefixed_32_Unprefixed_src32_16_16_absolute_Unprefixed_QI_dst32_32_24_absolute_Unprefixed_QI, { 0xb6b90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xb8090000 }
  },
/* xor.b${G} ${Dsp-16-u24},$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xb8290000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xb0890000 }
  },
/* xor.b${G} ${Dsp-16-u24},$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xb0a90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xb0090000 }
  },
/* xor.b${G} ${Dsp-16-u24},[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xb0290000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_An_relative_Unprefixed_QI, { 0xb2090000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_An_relative_Unprefixed_QI, { 0xb2290000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_An_relative_Unprefixed_QI, { 0xb4090000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_An_relative_Unprefixed_QI, { 0xb4290000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_24_An_relative_Unprefixed_QI, { 0xb6090000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_24_An_relative_Unprefixed_QI, { 0xb6290000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_SB_relative_Unprefixed_QI, { 0xb2890000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_SB_relative_Unprefixed_QI, { 0xb2a90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_SB_relative_Unprefixed_QI, { 0xb4890000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_SB_relative_Unprefixed_QI, { 0xb4a90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_8_FB_relative_Unprefixed_QI, { 0xb2c90000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_8_FB_relative_Unprefixed_QI, { 0xb2e90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_FB_relative_Unprefixed_QI, { 0xb4c90000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_FB_relative_Unprefixed_QI, { 0xb4e90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_16_absolute_Unprefixed_QI, { 0xb6c90000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U16), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_16_absolute_Unprefixed_QI, { 0xb6e90000 }
  },
/* xor.b${G} ${Dsp-16-u24}[$Src32AnUnprefixed],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_An_relative_Unprefixed_QI_dst32_40_24_absolute_Unprefixed_QI, { 0xb6890000 }
  },
/* xor.b${G} ${Dsp-16-u24},${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U24), ',', OP (DSP_40_U24), 0 } },
    & ifmt_xor32_b_16_24_Unprefixed_40_Unprefixed_src32_16_24_absolute_Unprefixed_QI_dst32_40_24_absolute_Unprefixed_QI, { 0xb6a90000 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0xc809 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0x8829 }
  },
/* xor.b${G} [$Src32AnUnprefixed],$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_Rn_direct_Unprefixed_QI, { 0x8809 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0xc089 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0x80a9 }
  },
/* xor.b${G} [$Src32AnUnprefixed],$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_An_direct_Unprefixed_QI, { 0x8089 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0xc009 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0x8029 }
  },
/* xor.b${G} [$Src32AnUnprefixed],[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_An_indirect_Unprefixed_QI, { 0x8009 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_QI, { 0xc20900 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_QI, { 0x822900 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_An_relative_Unprefixed_QI, { 0x820900 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_QI, { 0xc4090000 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_QI, { 0x84290000 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_An_relative_Unprefixed_QI, { 0x84090000 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_QI, { 0xc6090000 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_QI, { 0x86290000 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_24_An_relative_Unprefixed_QI, { 0x86090000 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_QI, { 0xc28900 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_QI, { 0x82a900 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_SB_relative_Unprefixed_QI, { 0x828900 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_QI, { 0xc4890000 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_QI, { 0x84a90000 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_SB_relative_Unprefixed_QI, { 0x84890000 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_QI, { 0xc2c900 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_QI, { 0x82e900 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_8_FB_relative_Unprefixed_QI, { 0x82c900 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_QI, { 0xc4c90000 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_QI, { 0x84e90000 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_FB_relative_Unprefixed_QI, { 0x84c90000 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_QI, { 0xc6c90000 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_QI, { 0x86e90000 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_16_absolute_Unprefixed_QI, { 0x86c90000 }
  },
/* xor.b${G} $Src32RnUnprefixedQI,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32RNUNPREFIXEDQI), ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_Rn_direct_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_QI, { 0xc6890000 }
  },
/* xor.b${G} $Src32AnUnprefixedQI,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC32ANUNPREFIXEDQI), ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_direct_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_QI, { 0x86a90000 }
  },
/* xor.b${G} [$Src32AnUnprefixed],${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC32ANUNPREFIXED), ']', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_b_basic_Unprefixed_16_Unprefixed_src32_An_indirect_Unprefixed_QI_dst32_16_24_absolute_Unprefixed_QI, { 0x86890000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_Rn_direct_HI, { 0x898000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_Rn_direct_HI, { 0x89a000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_Rn_direct_HI, { 0x89b000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_An_direct_HI, { 0x898400 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_An_direct_HI, { 0x89a400 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_An_direct_HI, { 0x89b400 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_An_indirect_HI, { 0x898600 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_An_indirect_HI, { 0x89a600 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_An_indirect_HI, { 0x89b600 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_8_An_relative_HI, { 0x89880000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_8_An_relative_HI, { 0x89a80000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_8_An_relative_HI, { 0x89b80000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_16_An_relative_HI, { 0x898c0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_16_An_relative_HI, { 0x89ac0000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_16_An_relative_HI, { 0x89bc0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_8_SB_relative_HI, { 0x898a0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_8_SB_relative_HI, { 0x89aa0000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_8_SB_relative_HI, { 0x89ba0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_16_SB_relative_HI, { 0x898e0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_16_SB_relative_HI, { 0x89ae0000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_16_SB_relative_HI, { 0x89be0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_8_FB_relative_HI, { 0x898b0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_8_FB_relative_HI, { 0x89ab0000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_8_FB_relative_HI, { 0x89bb0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_An_relative_HI_dst16_24_16_absolute_HI, { 0x898f0000 }
  },
/* xor.w${G} ${Dsp-16-u8}[sb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_SB_relative_HI_dst16_24_16_absolute_HI, { 0x89af0000 }
  },
/* xor.w${G} ${Dsp-16-s8}[fb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor16_w_16_8_24_src16_16_8_FB_relative_HI_dst16_24_16_absolute_HI, { 0x89bf0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_Rn_direct_HI, { 0x89c00000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_Rn_direct_HI, { 0x89e00000 }
  },
/* xor.w${G} ${Dsp-16-u16},$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_Rn_direct_HI, { 0x89f00000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_An_direct_HI, { 0x89c40000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_An_direct_HI, { 0x89e40000 }
  },
/* xor.w${G} ${Dsp-16-u16},$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_An_direct_HI, { 0x89f40000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_An_indirect_HI, { 0x89c60000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_An_indirect_HI, { 0x89e60000 }
  },
/* xor.w${G} ${Dsp-16-u16},[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_An_indirect_HI, { 0x89f60000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_8_An_relative_HI, { 0x89c80000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_8_An_relative_HI, { 0x89e80000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_8_An_relative_HI, { 0x89f80000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_16_An_relative_HI, { 0x89cc0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_16_An_relative_HI, { 0x89ec0000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_16_An_relative_HI, { 0x89fc0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_8_SB_relative_HI, { 0x89ca0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_8_SB_relative_HI, { 0x89ea0000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_8_SB_relative_HI, { 0x89fa0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_16_SB_relative_HI, { 0x89ce0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_16_SB_relative_HI, { 0x89ee0000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_16_SB_relative_HI, { 0x89fe0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_8_FB_relative_HI, { 0x89cb0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_8_FB_relative_HI, { 0x89eb0000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_8_FB_relative_HI, { 0x89fb0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_An_relative_HI_dst16_32_16_absolute_HI, { 0x89cf0000 }
  },
/* xor.w${G} ${Dsp-16-u16}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_SB_relative_HI_dst16_32_16_absolute_HI, { 0x89ef0000 }
  },
/* xor.w${G} ${Dsp-16-u16},${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor16_w_16_16_32_src16_16_16_absolute_HI_dst16_32_16_absolute_HI, { 0x89ff0000 }
  },
/* xor.w${G} $Src16RnHI,$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_Rn_direct_HI, { 0x8900 }
  },
/* xor.w${G} $Src16AnHI,$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_Rn_direct_HI, { 0x8940 }
  },
/* xor.w${G} [$Src16An],$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_Rn_direct_HI, { 0x8960 }
  },
/* xor.w${G} $Src16RnHI,$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_An_direct_HI, { 0x8904 }
  },
/* xor.w${G} $Src16AnHI,$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_An_direct_HI, { 0x8944 }
  },
/* xor.w${G} [$Src16An],$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_An_direct_HI, { 0x8964 }
  },
/* xor.w${G} $Src16RnHI,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_An_indirect_HI, { 0x8906 }
  },
/* xor.w${G} $Src16AnHI,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_An_indirect_HI, { 0x8946 }
  },
/* xor.w${G} [$Src16An],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_An_indirect_HI, { 0x8966 }
  },
/* xor.w${G} $Src16RnHI,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_8_An_relative_HI, { 0x890800 }
  },
/* xor.w${G} $Src16AnHI,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_8_An_relative_HI, { 0x894800 }
  },
/* xor.w${G} [$Src16An],${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_8_An_relative_HI, { 0x896800 }
  },
/* xor.w${G} $Src16RnHI,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_16_An_relative_HI, { 0x890c0000 }
  },
/* xor.w${G} $Src16AnHI,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_16_An_relative_HI, { 0x894c0000 }
  },
/* xor.w${G} [$Src16An],${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_16_An_relative_HI, { 0x896c0000 }
  },
/* xor.w${G} $Src16RnHI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_8_SB_relative_HI, { 0x890a00 }
  },
/* xor.w${G} $Src16AnHI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_8_SB_relative_HI, { 0x894a00 }
  },
/* xor.w${G} [$Src16An],${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_8_SB_relative_HI, { 0x896a00 }
  },
/* xor.w${G} $Src16RnHI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_16_SB_relative_HI, { 0x890e0000 }
  },
/* xor.w${G} $Src16AnHI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_16_SB_relative_HI, { 0x894e0000 }
  },
/* xor.w${G} [$Src16An],${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_16_SB_relative_HI, { 0x896e0000 }
  },
/* xor.w${G} $Src16RnHI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_8_FB_relative_HI, { 0x890b00 }
  },
/* xor.w${G} $Src16AnHI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_8_FB_relative_HI, { 0x894b00 }
  },
/* xor.w${G} [$Src16An],${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_8_FB_relative_HI, { 0x896b00 }
  },
/* xor.w${G} $Src16RnHI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNHI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_w_basic_16_src16_Rn_direct_HI_dst16_16_16_absolute_HI, { 0x890f0000 }
  },
/* xor.w${G} $Src16AnHI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANHI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_w_basic_16_src16_An_direct_HI_dst16_16_16_absolute_HI, { 0x894f0000 }
  },
/* xor.w${G} [$Src16An],${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_w_basic_16_src16_An_indirect_HI_dst16_16_16_absolute_HI, { 0x896f0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_Rn_direct_QI, { 0x888000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_Rn_direct_QI, { 0x88a000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_Rn_direct_QI, { 0x88b000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_An_direct_QI, { 0x888400 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_An_direct_QI, { 0x88a400 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_An_direct_QI, { 0x88b400 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_An_indirect_QI, { 0x888600 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_An_indirect_QI, { 0x88a600 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_An_indirect_QI, { 0x88b600 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_8_An_relative_QI, { 0x88880000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_8_An_relative_QI, { 0x88a80000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_8_An_relative_QI, { 0x88b80000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_16_An_relative_QI, { 0x888c0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_16_An_relative_QI, { 0x88ac0000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_16_An_relative_QI, { 0x88bc0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_8_SB_relative_QI, { 0x888a0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_8_SB_relative_QI, { 0x88aa0000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_8_SB_relative_QI, { 0x88ba0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_16_SB_relative_QI, { 0x888e0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_16_SB_relative_QI, { 0x88ae0000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_16_SB_relative_QI, { 0x88be0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_8_FB_relative_QI, { 0x888b0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_8_FB_relative_QI, { 0x88ab0000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_8_FB_relative_QI, { 0x88bb0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[$Src16An],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', OP (SRC16AN), ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_An_relative_QI_dst16_24_16_absolute_QI, { 0x888f0000 }
  },
/* xor.b${G} ${Dsp-16-u8}[sb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U8), '[', 's', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_SB_relative_QI_dst16_24_16_absolute_QI, { 0x88af0000 }
  },
/* xor.b${G} ${Dsp-16-s8}[fb],${Dsp-24-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_S8), '[', 'f', 'b', ']', ',', OP (DSP_24_U16), 0 } },
    & ifmt_xor16_b_16_8_24_src16_16_8_FB_relative_QI_dst16_24_16_absolute_QI, { 0x88bf0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_Rn_direct_QI, { 0x88c00000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_Rn_direct_QI, { 0x88e00000 }
  },
/* xor.b${G} ${Dsp-16-u16},$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_Rn_direct_QI, { 0x88f00000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_An_direct_QI, { 0x88c40000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_An_direct_QI, { 0x88e40000 }
  },
/* xor.b${G} ${Dsp-16-u16},$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_An_direct_QI, { 0x88f40000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_An_indirect_QI, { 0x88c60000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_An_indirect_QI, { 0x88e60000 }
  },
/* xor.b${G} ${Dsp-16-u16},[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_An_indirect_QI, { 0x88f60000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_8_An_relative_QI, { 0x88c80000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_8_An_relative_QI, { 0x88e80000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_8_An_relative_QI, { 0x88f80000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_16_An_relative_QI, { 0x88cc0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_16_An_relative_QI, { 0x88ec0000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_16_An_relative_QI, { 0x88fc0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_8_SB_relative_QI, { 0x88ca0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_8_SB_relative_QI, { 0x88ea0000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_8_SB_relative_QI, { 0x88fa0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_16_SB_relative_QI, { 0x88ce0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_16_SB_relative_QI, { 0x88ee0000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_16_SB_relative_QI, { 0x88fe0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_8_FB_relative_QI, { 0x88cb0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_8_FB_relative_QI, { 0x88eb0000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_8_FB_relative_QI, { 0x88fb0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[$Src16An],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', OP (SRC16AN), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_An_relative_QI_dst16_32_16_absolute_QI, { 0x88cf0000 }
  },
/* xor.b${G} ${Dsp-16-u16}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_SB_relative_QI_dst16_32_16_absolute_QI, { 0x88ef0000 }
  },
/* xor.b${G} ${Dsp-16-u16},${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_16_U16), ',', OP (DSP_32_U16), 0 } },
    & ifmt_xor16_b_16_16_32_src16_16_16_absolute_QI_dst16_32_16_absolute_QI, { 0x88ff0000 }
  },
/* xor.b${G} $Src16RnQI,$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_Rn_direct_QI, { 0x8800 }
  },
/* xor.b${G} $Src16AnQI,$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_Rn_direct_QI, { 0x8840 }
  },
/* xor.b${G} [$Src16An],$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_Rn_direct_QI, { 0x8860 }
  },
/* xor.b${G} $Src16RnQI,$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_An_direct_QI, { 0x8804 }
  },
/* xor.b${G} $Src16AnQI,$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_An_direct_QI, { 0x8844 }
  },
/* xor.b${G} [$Src16An],$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_An_direct_QI, { 0x8864 }
  },
/* xor.b${G} $Src16RnQI,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_An_indirect_QI, { 0x8806 }
  },
/* xor.b${G} $Src16AnQI,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_An_indirect_QI, { 0x8846 }
  },
/* xor.b${G} [$Src16An],[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_An_indirect_QI, { 0x8866 }
  },
/* xor.b${G} $Src16RnQI,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_8_An_relative_QI, { 0x880800 }
  },
/* xor.b${G} $Src16AnQI,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_8_An_relative_QI, { 0x884800 }
  },
/* xor.b${G} [$Src16An],${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_8_An_relative_QI, { 0x886800 }
  },
/* xor.b${G} $Src16RnQI,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_16_An_relative_QI, { 0x880c0000 }
  },
/* xor.b${G} $Src16AnQI,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_16_An_relative_QI, { 0x884c0000 }
  },
/* xor.b${G} [$Src16An],${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_16_An_relative_QI, { 0x886c0000 }
  },
/* xor.b${G} $Src16RnQI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_8_SB_relative_QI, { 0x880a00 }
  },
/* xor.b${G} $Src16AnQI,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_8_SB_relative_QI, { 0x884a00 }
  },
/* xor.b${G} [$Src16An],${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_8_SB_relative_QI, { 0x886a00 }
  },
/* xor.b${G} $Src16RnQI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_16_SB_relative_QI, { 0x880e0000 }
  },
/* xor.b${G} $Src16AnQI,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_16_SB_relative_QI, { 0x884e0000 }
  },
/* xor.b${G} [$Src16An],${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_16_SB_relative_QI, { 0x886e0000 }
  },
/* xor.b${G} $Src16RnQI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_8_FB_relative_QI, { 0x880b00 }
  },
/* xor.b${G} $Src16AnQI,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_8_FB_relative_QI, { 0x884b00 }
  },
/* xor.b${G} [$Src16An],${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_8_FB_relative_QI, { 0x886b00 }
  },
/* xor.b${G} $Src16RnQI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16RNQI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_b_basic_16_src16_Rn_direct_QI_dst16_16_16_absolute_QI, { 0x880f0000 }
  },
/* xor.b${G} $Src16AnQI,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (SRC16ANQI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_b_basic_16_src16_An_direct_QI_dst16_16_16_absolute_QI, { 0x884f0000 }
  },
/* xor.b${G} [$Src16An],${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '[', OP (SRC16AN), ']', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_b_basic_16_src16_An_indirect_QI_dst16_16_16_absolute_QI, { 0x886f0000 }
  },
/* xor.w${G} #${Imm-16-HI},$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_HI), ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_imm_G_basic_Unprefixed_dst32_Rn_direct_Unprefixed_HI, { 0x990e0000 }
  },
/* xor.w${G} #${Imm-16-HI},$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_HI), ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xor32_w_imm_G_basic_Unprefixed_dst32_An_direct_Unprefixed_HI, { 0x918e0000 }
  },
/* xor.w${G} #${Imm-16-HI},[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_HI), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_imm_G_basic_Unprefixed_dst32_An_indirect_Unprefixed_HI, { 0x910e0000 }
  },
/* xor.w${G} #${Imm-24-HI},${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_imm_G_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_HI, { 0x930e0000 }
  },
/* xor.w${G} #${Imm-24-HI},${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_imm_G_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_HI, { 0x938e0000 }
  },
/* xor.w${G} #${Imm-24-HI},${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_imm_G_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_HI, { 0x93ce0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_HI, { 0x950e0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_HI, { 0x958e0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_HI, { 0x95ce0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_w_imm_G_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_HI, { 0x97ce0000 }
  },
/* xor.w${G} #${Imm-40-HI},${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_40_HI), ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_w_imm_G_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_HI, { 0x970e0000 }
  },
/* xor.w${G} #${Imm-40-HI},${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_40_HI), ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_w_imm_G_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_HI, { 0x978e0000 }
  },
/* xor.b${G} #${Imm-16-QI},$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_QI), ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_imm_G_basic_Unprefixed_dst32_Rn_direct_Unprefixed_QI, { 0x980e00 }
  },
/* xor.b${G} #${Imm-16-QI},$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_QI), ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xor32_b_imm_G_basic_Unprefixed_dst32_An_direct_Unprefixed_QI, { 0x908e00 }
  },
/* xor.b${G} #${Imm-16-QI},[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_QI), ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_imm_G_basic_Unprefixed_dst32_An_indirect_Unprefixed_QI, { 0x900e00 }
  },
/* xor.b${G} #${Imm-24-QI},${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_imm_G_16_8_Unprefixed_dst32_16_8_An_relative_Unprefixed_QI, { 0x920e0000 }
  },
/* xor.b${G} #${Imm-24-QI},${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_imm_G_16_8_Unprefixed_dst32_16_8_SB_relative_Unprefixed_QI, { 0x928e0000 }
  },
/* xor.b${G} #${Imm-24-QI},${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_imm_G_16_8_Unprefixed_dst32_16_8_FB_relative_Unprefixed_QI, { 0x92ce0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_An_relative_Unprefixed_QI, { 0x940e0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_SB_relative_Unprefixed_QI, { 0x948e0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_FB_relative_Unprefixed_QI, { 0x94ce0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor32_b_imm_G_16_16_Unprefixed_dst32_16_16_absolute_Unprefixed_QI, { 0x96ce0000 }
  },
/* xor.b${G} #${Imm-40-QI},${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_40_QI), ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xor32_b_imm_G_16_24_Unprefixed_dst32_16_24_An_relative_Unprefixed_QI, { 0x960e0000 }
  },
/* xor.b${G} #${Imm-40-QI},${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_40_QI), ',', OP (DSP_16_U24), 0 } },
    & ifmt_xor32_b_imm_G_16_24_Unprefixed_dst32_16_24_absolute_Unprefixed_QI, { 0x968e0000 }
  },
/* xor.w${G} #${Imm-16-HI},$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_HI), ',', OP (DST16RNHI), 0 } },
    & ifmt_xor16_w_imm_G_basic_dst16_Rn_direct_HI, { 0x77100000 }
  },
/* xor.w${G} #${Imm-16-HI},$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_HI), ',', OP (DST16ANHI), 0 } },
    & ifmt_xor16_w_imm_G_basic_dst16_An_direct_HI, { 0x77140000 }
  },
/* xor.w${G} #${Imm-16-HI},[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_HI), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_imm_G_basic_dst16_An_indirect_HI, { 0x77160000 }
  },
/* xor.w${G} #${Imm-24-HI},${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_imm_G_16_8_dst16_16_8_An_relative_HI, { 0x77180000 }
  },
/* xor.w${G} #${Imm-24-HI},${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_imm_G_16_8_dst16_16_8_SB_relative_HI, { 0x771a0000 }
  },
/* xor.w${G} #${Imm-24-HI},${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_w_imm_G_16_8_dst16_16_8_FB_relative_HI, { 0x771b0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_w_imm_G_16_16_dst16_16_16_An_relative_HI, { 0x771c0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_w_imm_G_16_16_dst16_16_16_SB_relative_HI, { 0x771e0000 }
  },
/* xor.w${G} #${Imm-32-HI},${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_HI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_w_imm_G_16_16_dst16_16_16_absolute_HI, { 0x771f0000 }
  },
/* xor.b${G} #${Imm-16-QI},$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_QI), ',', OP (DST16RNQI), 0 } },
    & ifmt_xor16_b_imm_G_basic_dst16_Rn_direct_QI, { 0x761000 }
  },
/* xor.b${G} #${Imm-16-QI},$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_QI), ',', OP (DST16ANQI), 0 } },
    & ifmt_xor16_b_imm_G_basic_dst16_An_direct_QI, { 0x761400 }
  },
/* xor.b${G} #${Imm-16-QI},[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_16_QI), ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_imm_G_basic_dst16_An_indirect_QI, { 0x761600 }
  },
/* xor.b${G} #${Imm-24-QI},${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_imm_G_16_8_dst16_16_8_An_relative_QI, { 0x76180000 }
  },
/* xor.b${G} #${Imm-24-QI},${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_imm_G_16_8_dst16_16_8_SB_relative_QI, { 0x761a0000 }
  },
/* xor.b${G} #${Imm-24-QI},${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xor16_b_imm_G_16_8_dst16_16_8_FB_relative_QI, { 0x761b0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xor16_b_imm_G_16_16_dst16_16_16_An_relative_QI, { 0x761c0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xor16_b_imm_G_16_16_dst16_16_16_SB_relative_QI, { 0x761e0000 }
  },
/* xor.b${G} #${Imm-32-QI},${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', '#', OP (IMM_32_QI), ',', OP (DSP_16_U16), 0 } },
    & ifmt_xor16_b_imm_G_16_16_dst16_16_16_absolute_QI, { 0x761f0000 }
  },
/* xchg.w r3,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI, { 0xd90d }
  },
/* xchg.w r3,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI, { 0xd18d }
  },
/* xchg.w r3,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI, { 0xd10d }
  },
/* xchg.w r3,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI, { 0xd30d00 }
  },
/* xchg.w r3,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI, { 0xd50d0000 }
  },
/* xchg.w r3,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI, { 0xd70d0000 }
  },
/* xchg.w r3,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI, { 0xd38d00 }
  },
/* xchg.w r3,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI, { 0xd58d0000 }
  },
/* xchg.w r3,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI, { 0xd3cd00 }
  },
/* xchg.w r3,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI, { 0xd5cd0000 }
  },
/* xchg.w r3,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI, { 0xd7cd0000 }
  },
/* xchg.w r3,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI, { 0xd78d0000 }
  },
/* xchg.w r2,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI, { 0xd90c }
  },
/* xchg.w r2,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI, { 0xd18c }
  },
/* xchg.w r2,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI, { 0xd10c }
  },
/* xchg.w r2,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI, { 0xd30c00 }
  },
/* xchg.w r2,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI, { 0xd50c0000 }
  },
/* xchg.w r2,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI, { 0xd70c0000 }
  },
/* xchg.w r2,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI, { 0xd38c00 }
  },
/* xchg.w r2,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI, { 0xd58c0000 }
  },
/* xchg.w r2,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI, { 0xd3cc00 }
  },
/* xchg.w r2,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI, { 0xd5cc0000 }
  },
/* xchg.w r2,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI, { 0xd7cc0000 }
  },
/* xchg.w r2,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI, { 0xd78c0000 }
  },
/* xchg.w a1,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI, { 0xd90b }
  },
/* xchg.w a1,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI, { 0xd18b }
  },
/* xchg.w a1,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI, { 0xd10b }
  },
/* xchg.w a1,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI, { 0xd30b00 }
  },
/* xchg.w a1,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI, { 0xd50b0000 }
  },
/* xchg.w a1,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI, { 0xd70b0000 }
  },
/* xchg.w a1,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI, { 0xd38b00 }
  },
/* xchg.w a1,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI, { 0xd58b0000 }
  },
/* xchg.w a1,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI, { 0xd3cb00 }
  },
/* xchg.w a1,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI, { 0xd5cb0000 }
  },
/* xchg.w a1,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI, { 0xd7cb0000 }
  },
/* xchg.w a1,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI, { 0xd78b0000 }
  },
/* xchg.w a0,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI, { 0xd90a }
  },
/* xchg.w a0,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI, { 0xd18a }
  },
/* xchg.w a0,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI, { 0xd10a }
  },
/* xchg.w a0,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI, { 0xd30a00 }
  },
/* xchg.w a0,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI, { 0xd50a0000 }
  },
/* xchg.w a0,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI, { 0xd70a0000 }
  },
/* xchg.w a0,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI, { 0xd38a00 }
  },
/* xchg.w a0,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI, { 0xd58a0000 }
  },
/* xchg.w a0,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI, { 0xd3ca00 }
  },
/* xchg.w a0,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI, { 0xd5ca0000 }
  },
/* xchg.w a0,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI, { 0xd7ca0000 }
  },
/* xchg.w a0,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI, { 0xd78a0000 }
  },
/* xchg.w r1,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI, { 0xd909 }
  },
/* xchg.w r1,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI, { 0xd189 }
  },
/* xchg.w r1,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI, { 0xd109 }
  },
/* xchg.w r1,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI, { 0xd30900 }
  },
/* xchg.w r1,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI, { 0xd5090000 }
  },
/* xchg.w r1,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI, { 0xd7090000 }
  },
/* xchg.w r1,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI, { 0xd38900 }
  },
/* xchg.w r1,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI, { 0xd5890000 }
  },
/* xchg.w r1,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI, { 0xd3c900 }
  },
/* xchg.w r1,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI, { 0xd5c90000 }
  },
/* xchg.w r1,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI, { 0xd7c90000 }
  },
/* xchg.w r1,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI, { 0xd7890000 }
  },
/* xchg.w r0,$Dst32RnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DST32RNUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_Rn_direct_Unprefixed_HI, { 0xd908 }
  },
/* xchg.w r0,$Dst32AnUnprefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DST32ANUNPREFIXEDHI), 0 } },
    & ifmt_xchg32w_r3_dst32_An_direct_Unprefixed_HI, { 0xd188 }
  },
/* xchg.w r0,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_An_indirect_Unprefixed_HI, { 0xd108 }
  },
/* xchg.w r0,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_An_relative_Unprefixed_HI, { 0xd30800 }
  },
/* xchg.w r0,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_An_relative_Unprefixed_HI, { 0xd5080000 }
  },
/* xchg.w r0,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_An_relative_Unprefixed_HI, { 0xd7080000 }
  },
/* xchg.w r0,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_SB_relative_Unprefixed_HI, { 0xd38800 }
  },
/* xchg.w r0,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_SB_relative_Unprefixed_HI, { 0xd5880000 }
  },
/* xchg.w r0,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_8_FB_relative_Unprefixed_HI, { 0xd3c800 }
  },
/* xchg.w r0,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_FB_relative_Unprefixed_HI, { 0xd5c80000 }
  },
/* xchg.w r0,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32w_r3_dst32_16_16_absolute_Unprefixed_HI, { 0xd7c80000 }
  },
/* xchg.w r0,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32w_r3_dst32_16_24_absolute_Unprefixed_HI, { 0xd7880000 }
  },
/* xchg.b r1h,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI, { 0xd80d }
  },
/* xchg.b r1h,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI, { 0xd08d }
  },
/* xchg.b r1h,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI, { 0xd00d }
  },
/* xchg.b r1h,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI, { 0xd20d00 }
  },
/* xchg.b r1h,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI, { 0xd40d0000 }
  },
/* xchg.b r1h,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI, { 0xd60d0000 }
  },
/* xchg.b r1h,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI, { 0xd28d00 }
  },
/* xchg.b r1h,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI, { 0xd48d0000 }
  },
/* xchg.b r1h,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI, { 0xd2cd00 }
  },
/* xchg.b r1h,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI, { 0xd4cd0000 }
  },
/* xchg.b r1h,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI, { 0xd6cd0000 }
  },
/* xchg.b r1h,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI, { 0xd68d0000 }
  },
/* xchg.b r0h,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI, { 0xd80c }
  },
/* xchg.b r0h,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI, { 0xd08c }
  },
/* xchg.b r0h,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI, { 0xd00c }
  },
/* xchg.b r0h,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI, { 0xd20c00 }
  },
/* xchg.b r0h,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI, { 0xd40c0000 }
  },
/* xchg.b r0h,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI, { 0xd60c0000 }
  },
/* xchg.b r0h,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI, { 0xd28c00 }
  },
/* xchg.b r0h,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI, { 0xd48c0000 }
  },
/* xchg.b r0h,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI, { 0xd2cc00 }
  },
/* xchg.b r0h,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI, { 0xd4cc0000 }
  },
/* xchg.b r0h,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI, { 0xd6cc0000 }
  },
/* xchg.b r0h,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI, { 0xd68c0000 }
  },
/* xchg.b a1,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI, { 0xd80b }
  },
/* xchg.b a1,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI, { 0xd08b }
  },
/* xchg.b a1,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI, { 0xd00b }
  },
/* xchg.b a1,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI, { 0xd20b00 }
  },
/* xchg.b a1,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI, { 0xd40b0000 }
  },
/* xchg.b a1,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI, { 0xd60b0000 }
  },
/* xchg.b a1,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI, { 0xd28b00 }
  },
/* xchg.b a1,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI, { 0xd48b0000 }
  },
/* xchg.b a1,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI, { 0xd2cb00 }
  },
/* xchg.b a1,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI, { 0xd4cb0000 }
  },
/* xchg.b a1,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI, { 0xd6cb0000 }
  },
/* xchg.b a1,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '1', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI, { 0xd68b0000 }
  },
/* xchg.b a0,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI, { 0xd80a }
  },
/* xchg.b a0,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI, { 0xd08a }
  },
/* xchg.b a0,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI, { 0xd00a }
  },
/* xchg.b a0,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI, { 0xd20a00 }
  },
/* xchg.b a0,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI, { 0xd40a0000 }
  },
/* xchg.b a0,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI, { 0xd60a0000 }
  },
/* xchg.b a0,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI, { 0xd28a00 }
  },
/* xchg.b a0,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI, { 0xd48a0000 }
  },
/* xchg.b a0,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI, { 0xd2ca00 }
  },
/* xchg.b a0,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI, { 0xd4ca0000 }
  },
/* xchg.b a0,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI, { 0xd6ca0000 }
  },
/* xchg.b a0,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'a', '0', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI, { 0xd68a0000 }
  },
/* xchg.b r1l,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI, { 0xd809 }
  },
/* xchg.b r1l,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI, { 0xd089 }
  },
/* xchg.b r1l,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI, { 0xd009 }
  },
/* xchg.b r1l,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI, { 0xd20900 }
  },
/* xchg.b r1l,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI, { 0xd4090000 }
  },
/* xchg.b r1l,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI, { 0xd6090000 }
  },
/* xchg.b r1l,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI, { 0xd28900 }
  },
/* xchg.b r1l,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI, { 0xd4890000 }
  },
/* xchg.b r1l,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI, { 0xd2c900 }
  },
/* xchg.b r1l,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI, { 0xd4c90000 }
  },
/* xchg.b r1l,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI, { 0xd6c90000 }
  },
/* xchg.b r1l,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI, { 0xd6890000 }
  },
/* xchg.b r0l,$Dst32RnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DST32RNUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_Rn_direct_Unprefixed_QI, { 0xd808 }
  },
/* xchg.b r0l,$Dst32AnUnprefixedQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DST32ANUNPREFIXEDQI), 0 } },
    & ifmt_xchg32b_r1h_dst32_An_direct_Unprefixed_QI, { 0xd088 }
  },
/* xchg.b r0l,[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_An_indirect_Unprefixed_QI, { 0xd008 }
  },
/* xchg.b r0l,${Dsp-16-u8}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U8), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_An_relative_Unprefixed_QI, { 0xd20800 }
  },
/* xchg.b r0l,${Dsp-16-u16}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U16), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_An_relative_Unprefixed_QI, { 0xd4080000 }
  },
/* xchg.b r0l,${Dsp-16-u24}[$Dst32AnUnprefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U24), '[', OP (DST32ANUNPREFIXED), ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_An_relative_Unprefixed_QI, { 0xd6080000 }
  },
/* xchg.b r0l,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_SB_relative_Unprefixed_QI, { 0xd28800 }
  },
/* xchg.b r0l,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_SB_relative_Unprefixed_QI, { 0xd4880000 }
  },
/* xchg.b r0l,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_8_FB_relative_Unprefixed_QI, { 0xd2c800 }
  },
/* xchg.b r0l,${Dsp-16-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_FB_relative_Unprefixed_QI, { 0xd4c80000 }
  },
/* xchg.b r0l,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_16_absolute_Unprefixed_QI, { 0xd6c80000 }
  },
/* xchg.b r0l,${Dsp-16-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U24), 0 } },
    & ifmt_xchg32b_r1h_dst32_16_24_absolute_Unprefixed_QI, { 0xd6880000 }
  },
/* xchg.w r3,$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DST16RNHI), 0 } },
    & ifmt_xchg16w_r3_dst16_Rn_direct_HI, { 0x7b30 }
  },
/* xchg.w r3,$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DST16ANHI), 0 } },
    & ifmt_xchg16w_r3_dst16_An_direct_HI, { 0x7b34 }
  },
/* xchg.w r3,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_An_indirect_HI, { 0x7b36 }
  },
/* xchg.w r3,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_An_relative_HI, { 0x7b3800 }
  },
/* xchg.w r3,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_An_relative_HI, { 0x7b3c0000 }
  },
/* xchg.w r3,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_SB_relative_HI, { 0x7b3a00 }
  },
/* xchg.w r3,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_SB_relative_HI, { 0x7b3e0000 }
  },
/* xchg.w r3,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_FB_relative_HI, { 0x7b3b00 }
  },
/* xchg.w r3,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '3', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_absolute_HI, { 0x7b3f0000 }
  },
/* xchg.w r2,$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DST16RNHI), 0 } },
    & ifmt_xchg16w_r3_dst16_Rn_direct_HI, { 0x7b20 }
  },
/* xchg.w r2,$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DST16ANHI), 0 } },
    & ifmt_xchg16w_r3_dst16_An_direct_HI, { 0x7b24 }
  },
/* xchg.w r2,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_An_indirect_HI, { 0x7b26 }
  },
/* xchg.w r2,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_An_relative_HI, { 0x7b2800 }
  },
/* xchg.w r2,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_An_relative_HI, { 0x7b2c0000 }
  },
/* xchg.w r2,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_SB_relative_HI, { 0x7b2a00 }
  },
/* xchg.w r2,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_SB_relative_HI, { 0x7b2e0000 }
  },
/* xchg.w r2,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_FB_relative_HI, { 0x7b2b00 }
  },
/* xchg.w r2,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '2', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_absolute_HI, { 0x7b2f0000 }
  },
/* xchg.w r1,$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DST16RNHI), 0 } },
    & ifmt_xchg16w_r3_dst16_Rn_direct_HI, { 0x7b10 }
  },
/* xchg.w r1,$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DST16ANHI), 0 } },
    & ifmt_xchg16w_r3_dst16_An_direct_HI, { 0x7b14 }
  },
/* xchg.w r1,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_An_indirect_HI, { 0x7b16 }
  },
/* xchg.w r1,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_An_relative_HI, { 0x7b1800 }
  },
/* xchg.w r1,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_An_relative_HI, { 0x7b1c0000 }
  },
/* xchg.w r1,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_SB_relative_HI, { 0x7b1a00 }
  },
/* xchg.w r1,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_SB_relative_HI, { 0x7b1e0000 }
  },
/* xchg.w r1,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_FB_relative_HI, { 0x7b1b00 }
  },
/* xchg.w r1,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_absolute_HI, { 0x7b1f0000 }
  },
/* xchg.w r0,$Dst16RnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DST16RNHI), 0 } },
    & ifmt_xchg16w_r3_dst16_Rn_direct_HI, { 0x7b00 }
  },
/* xchg.w r0,$Dst16AnHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DST16ANHI), 0 } },
    & ifmt_xchg16w_r3_dst16_An_direct_HI, { 0x7b04 }
  },
/* xchg.w r0,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_An_indirect_HI, { 0x7b06 }
  },
/* xchg.w r0,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_An_relative_HI, { 0x7b0800 }
  },
/* xchg.w r0,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_An_relative_HI, { 0x7b0c0000 }
  },
/* xchg.w r0,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_SB_relative_HI, { 0x7b0a00 }
  },
/* xchg.w r0,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_SB_relative_HI, { 0x7b0e0000 }
  },
/* xchg.w r0,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16w_r3_dst16_16_8_FB_relative_HI, { 0x7b0b00 }
  },
/* xchg.w r0,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16w_r3_dst16_16_16_absolute_HI, { 0x7b0f0000 }
  },
/* xchg.b r1h,$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DST16RNQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_Rn_direct_QI, { 0x7a30 }
  },
/* xchg.b r1h,$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DST16ANQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_An_direct_QI, { 0x7a34 }
  },
/* xchg.b r1h,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_An_indirect_QI, { 0x7a36 }
  },
/* xchg.b r1h,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_An_relative_QI, { 0x7a3800 }
  },
/* xchg.b r1h,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_An_relative_QI, { 0x7a3c0000 }
  },
/* xchg.b r1h,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_SB_relative_QI, { 0x7a3a00 }
  },
/* xchg.b r1h,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_SB_relative_QI, { 0x7a3e0000 }
  },
/* xchg.b r1h,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_FB_relative_QI, { 0x7a3b00 }
  },
/* xchg.b r1h,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'h', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_absolute_QI, { 0x7a3f0000 }
  },
/* xchg.b r1l,$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DST16RNQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_Rn_direct_QI, { 0x7a20 }
  },
/* xchg.b r1l,$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DST16ANQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_An_direct_QI, { 0x7a24 }
  },
/* xchg.b r1l,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_An_indirect_QI, { 0x7a26 }
  },
/* xchg.b r1l,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_An_relative_QI, { 0x7a2800 }
  },
/* xchg.b r1l,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_An_relative_QI, { 0x7a2c0000 }
  },
/* xchg.b r1l,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_SB_relative_QI, { 0x7a2a00 }
  },
/* xchg.b r1l,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_SB_relative_QI, { 0x7a2e0000 }
  },
/* xchg.b r1l,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_FB_relative_QI, { 0x7a2b00 }
  },
/* xchg.b r1l,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '1', 'l', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_absolute_QI, { 0x7a2f0000 }
  },
/* xchg.b r0h,$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DST16RNQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_Rn_direct_QI, { 0x7a10 }
  },
/* xchg.b r0h,$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DST16ANQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_An_direct_QI, { 0x7a14 }
  },
/* xchg.b r0h,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_An_indirect_QI, { 0x7a16 }
  },
/* xchg.b r0h,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_An_relative_QI, { 0x7a1800 }
  },
/* xchg.b r0h,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_An_relative_QI, { 0x7a1c0000 }
  },
/* xchg.b r0h,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_SB_relative_QI, { 0x7a1a00 }
  },
/* xchg.b r0h,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_SB_relative_QI, { 0x7a1e0000 }
  },
/* xchg.b r0h,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_FB_relative_QI, { 0x7a1b00 }
  },
/* xchg.b r0h,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'h', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_absolute_QI, { 0x7a1f0000 }
  },
/* xchg.b r0l,$Dst16RnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DST16RNQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_Rn_direct_QI, { 0x7a00 }
  },
/* xchg.b r0l,$Dst16AnQI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DST16ANQI), 0 } },
    & ifmt_xchg16b_r1h_dst16_An_direct_QI, { 0x7a04 }
  },
/* xchg.b r0l,[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_An_indirect_QI, { 0x7a06 }
  },
/* xchg.b r0l,${Dsp-16-u8}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U8), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_An_relative_QI, { 0x7a0800 }
  },
/* xchg.b r0l,${Dsp-16-u16}[$Dst16An] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U16), '[', OP (DST16AN), ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_An_relative_QI, { 0x7a0c0000 }
  },
/* xchg.b r0l,${Dsp-16-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_SB_relative_QI, { 0x7a0a00 }
  },
/* xchg.b r0l,${Dsp-16-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_SB_relative_QI, { 0x7a0e0000 }
  },
/* xchg.b r0l,${Dsp-16-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_xchg16b_r1h_dst16_16_8_FB_relative_QI, { 0x7a0b00 }
  },
/* xchg.b r0l,${Dsp-16-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', 'r', '0', 'l', ',', OP (DSP_16_U16), 0 } },
    & ifmt_xchg16b_r1h_dst16_16_16_absolute_QI, { 0x7a0f0000 }
  },
/* tst.w${S} #${Imm-16-HI},${Dsp-8-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_16_HI), ',', OP (DSP_8_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_imm_S_2_S_8_dst32_2_S_8_SB_relative_HI, { 0x2d000000 }
  },
/* tst.w${S} #${Imm-16-HI},${Dsp-8-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_16_HI), ',', OP (DSP_8_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_imm_S_2_S_8_dst32_2_S_8_FB_relative_HI, { 0x3d000000 }
  },
/* tst.w${S} #${Imm-24-HI},${Dsp-8-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_24_HI), ',', OP (DSP_8_U16), 0 } },
    & ifmt_tst32_w_imm_S_2_S_16_dst32_2_S_16_absolute_HI, { 0x1d000000 }
  },
/* tst.w${S} #${Imm-8-HI},r0 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_8_HI), ',', 'r', '0', 0 } },
    & ifmt_tst32_w_imm_S_2_S_basic_dst32_2_S_R0_direct_HI, { 0xd0000 }
  },
/* tst.b${S} #${Imm-16-QI},${Dsp-8-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_16_QI), ',', OP (DSP_8_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_b_imm_S_2_S_8_dst32_2_S_8_SB_relative_QI, { 0x2c0000 }
  },
/* tst.b${S} #${Imm-16-QI},${Dsp-8-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_16_QI), ',', OP (DSP_8_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_b_imm_S_2_S_8_dst32_2_S_8_FB_relative_QI, { 0x3c0000 }
  },
/* tst.b${S} #${Imm-24-QI},${Dsp-8-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_24_QI), ',', OP (DSP_8_U16), 0 } },
    & ifmt_tst32_b_imm_S_2_S_16_dst32_2_S_16_absolute_QI, { 0x1c000000 }
  },
/* tst.b${S} #${Imm-8-QI},r0l */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (S), ' ', '#', OP (IMM_8_QI), ',', 'r', '0', 'l', 0 } },
    & ifmt_tst32_b_imm_S_2_S_basic_dst32_2_S_R0l_direct_QI, { 0xc00 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1990900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1992900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1993900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1918900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x191a900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x191b900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1910900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1912900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1913900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_8_An_relative_Prefixed_HI, { 0x1930900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_8_An_relative_Prefixed_HI, { 0x1932900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_8_An_relative_Prefixed_HI, { 0x1933900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_An_relative_Prefixed_HI, { 0x1950900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_An_relative_Prefixed_HI, { 0x1952900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_An_relative_Prefixed_HI, { 0x1953900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_24_An_relative_Prefixed_HI, { 0x1970900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_24_An_relative_Prefixed_HI, { 0x1972900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_24_An_relative_Prefixed_HI, { 0x1973900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_8_SB_relative_Prefixed_HI, { 0x1938900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_8_SB_relative_Prefixed_HI, { 0x193a900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_8_SB_relative_Prefixed_HI, { 0x193b900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_SB_relative_Prefixed_HI, { 0x1958900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_SB_relative_Prefixed_HI, { 0x195a900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_SB_relative_Prefixed_HI, { 0x195b900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_8_FB_relative_Prefixed_HI, { 0x193c900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_8_FB_relative_Prefixed_HI, { 0x193e900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_8_FB_relative_Prefixed_HI, { 0x193f900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_FB_relative_Prefixed_HI, { 0x195c900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_FB_relative_Prefixed_HI, { 0x195e900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_FB_relative_Prefixed_HI, { 0x195f900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_16_absolute_Prefixed_HI, { 0x197c900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_16_absolute_Prefixed_HI, { 0x197e900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U16), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_16_absolute_Prefixed_HI, { 0x197f900 }
  },
/* tst.w${G} ${Dsp-24-u8}[$Src32AnPrefixed],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_An_relative_Prefixed_HI_dst32_32_24_absolute_Prefixed_HI, { 0x1978900 }
  },
/* tst.w${G} ${Dsp-24-u8}[sb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U8), '[', 's', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_SB_relative_Prefixed_HI_dst32_32_24_absolute_Prefixed_HI, { 0x197a900 }
  },
/* tst.w${G} ${Dsp-24-s8}[fb],${Dsp-32-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S8), '[', 'f', 'b', ']', ',', OP (DSP_32_U24), 0 } },
    & ifmt_tst32_w_24_8_Prefixed_32_Prefixed_src32_24_8_FB_relative_Prefixed_HI_dst32_32_24_absolute_Prefixed_HI, { 0x197b900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1a90900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1a92900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1a93900 }
  },
/* tst.w${G} ${Dsp-24-u16},$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1b93900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1a18900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1a1a900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1a1b900 }
  },
/* tst.w${G} ${Dsp-24-u16},$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1b1b900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1a10900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1a12900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1a13900 }
  },
/* tst.w${G} ${Dsp-24-u16},[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1b13900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a30900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a32900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI, { 0x1a33900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_8_An_relative_Prefixed_HI, { 0x1b33900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a50900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a52900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI, { 0x1a53900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_An_relative_Prefixed_HI, { 0x1b53900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a70900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a72900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI, { 0x1a73900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_24_An_relative_Prefixed_HI, { 0x1b73900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a38900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a3a900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1a3b900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_8_SB_relative_Prefixed_HI, { 0x1b3b900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a58900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a5a900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1a5b900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_SB_relative_Prefixed_HI, { 0x1b5b900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a3c900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a3e900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1a3f900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_8_FB_relative_Prefixed_HI, { 0x1b3f900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a5c900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a5e900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1a5f900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_FB_relative_Prefixed_HI, { 0x1b5f900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI, { 0x1a7c900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI, { 0x1a7e900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U16), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI, { 0x1a7f900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U16), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_16_absolute_Prefixed_HI, { 0x1b7f900 }
  },
/* tst.w${G} ${Dsp-24-u16}[$Src32AnPrefixed],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_An_relative_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI, { 0x1a78900 }
  },
/* tst.w${G} ${Dsp-24-u16}[sb],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), '[', 's', 'b', ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_SB_relative_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI, { 0x1a7a900 }
  },
/* tst.w${G} ${Dsp-24-s16}[fb],${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_S16), '[', 'f', 'b', ']', ',', OP (DSP_40_U24), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_FB_relative_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI, { 0x1a7b900 }
  },
/* tst.w${G} ${Dsp-24-u16},${Dsp-40-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U16), ',', OP (DSP_40_U24), 0 } },
    & ifmt_tst32_w_24_16_Prefixed_40_Prefixed_src32_24_16_absolute_Prefixed_HI_dst32_40_24_absolute_Prefixed_HI, { 0x1b7b900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1b90900 }
  },
/* tst.w${G} ${Dsp-24-u24},$Dst32RnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DST32RNPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_Rn_direct_Prefixed_HI, { 0x1b92900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1b18900 }
  },
/* tst.w${G} ${Dsp-24-u24},$Dst32AnPrefixedHI */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DST32ANPREFIXEDHI), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_An_direct_Prefixed_HI, { 0x1b1a900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1b10900 }
  },
/* tst.w${G} ${Dsp-24-u24},[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_An_indirect_Prefixed_HI, { 0x1b12900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_8_An_relative_Prefixed_HI, { 0x1b30900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u8}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_U8), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_8_An_relative_Prefixed_HI, { 0x1b32900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_An_relative_Prefixed_HI, { 0x1b50900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u16}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_An_relative_Prefixed_HI, { 0x1b52900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_24_An_relative_Prefixed_HI, { 0x1b70900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u24}[$Dst32AnPrefixed] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_U24), '[', OP (DST32ANPREFIXED), ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_24_An_relative_Prefixed_HI, { 0x1b72900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_8_SB_relative_Prefixed_HI, { 0x1b38900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u8}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_U8), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_8_SB_relative_Prefixed_HI, { 0x1b3a900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_SB_relative_Prefixed_HI, { 0x1b58900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u16}[sb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), '[', 's', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_SB_relative_Prefixed_HI, { 0x1b5a900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_8_FB_relative_Prefixed_HI, { 0x1b3c900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-s8}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_S8), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_8_FB_relative_Prefixed_HI, { 0x1b3e900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_FB_relative_Prefixed_HI, { 0x1b5c900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-s16}[fb] */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_S16), '[', 'f', 'b', ']', 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_FB_relative_Prefixed_HI, { 0x1b5e900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U16), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_16_absolute_Prefixed_HI, { 0x1b7c900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u16} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), ',', OP (DSP_48_U16), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_absolute_Prefixed_HI_dst32_48_16_absolute_Prefixed_HI, { 0x1b7e900 }
  },
/* tst.w${G} ${Dsp-24-u24}[$Src32AnPrefixed],${Dsp-48-u24} */
  {
    { 0, 0, 0, 0 },
    { { MNEM, OP (G), ' ', OP (DSP_24_U24), '[', OP (SRC32ANPREFIXED), ']', ',', OP (DSP_48_U24), 0 } },
    & ifmt_tst32_w_24_24_Prefixed_48_Prefixed_src32_24_24_An_relative_Prefixed_HI_dst32_48_24_absolute_Prefixed_HI, { 0x1b78900 }
  },
/* tst.w${G} ${Dsp-24-u24},${Dsp-48-u24} */
 