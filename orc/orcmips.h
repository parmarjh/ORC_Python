#ifndef _ORC_MIPS_H_
#define _ORC_MIPS_H_

#include <orc/orcutils.h>
#include <orc/orcprogram.h>

ORC_BEGIN_DECLS

#ifdef ORC_ENABLE_UNSTABLE_API

typedef enum {
  ORC_MIPS_ZERO = ORC_GP_REG_BASE+0,
  ORC_MIPS_AT,
  ORC_MIPS_V0,
  ORC_MIPS_V1,
  ORC_MIPS_A0,
  ORC_MIPS_A1,
  ORC_MIPS_A2,
  ORC_MIPS_A3,
  ORC_MIPS_T0,
  ORC_MIPS_T1,
  ORC_MIPS_T2,
  ORC_MIPS_T3,
  ORC_MIPS_T4,
  ORC_MIPS_T5,
  ORC_MIPS_T6,
  ORC_MIPS_T7,
  ORC_MIPS_S0,
  ORC_MIPS_S1,
  ORC_MIPS_S2,
  ORC_MIPS_S3,
  ORC_MIPS_S4,
  ORC_MIPS_S5,
  ORC_MIPS_S6,
  ORC_MIPS_S7,
  ORC_MIPS_T8,
  ORC_MIPS_T9,
  ORC_MIPS_K0,
  ORC_MIPS_K1,
  ORC_MIPS_GP,
  ORC_MIPS_SP,
  ORC_MIPS_FP,
  ORC_MIPS_RA
} OrcMipsRegister;

void orc_mips_emit_label (OrcCompiler *compiler, unsigned int label);

void orc_mips_emit_nop (OrcCompiler *compiler);

void orc_mips_emit_sw (OrcCompiler *compiler, OrcMipsRegister reg,
                       OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_swr (OrcCompiler *compiler, OrcMipsRegister reg,
                        OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_swl (OrcCompiler *compiler, OrcMipsRegister reg,
                        OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_sh (OrcCompiler *compiler, OrcMipsRegister reg,
                       OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_sb (OrcCompiler *compiler, OrcMipsRegister reg,
                       OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_lw (OrcCompiler *compiler, OrcMipsRegister dest,
                       OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_lwr (OrcCompiler *compiler, OrcMipsRegister dest,
                        OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_lwl (OrcCompiler *compiler, OrcMipsRegister dest,
                        OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_lh (OrcCompiler *compiler, OrcMipsRegister dest,
                       OrcMipsRegister base, unsigned int offset);
void orc_mips_emit_lb (OrcCompiler *compiler, OrcMipsRegister dest,
                       OrcMipsRegister base, unsigned int offset);

void orc_mips_emit_jr (OrcCompiler *compiler, OrcMipsRegister address_reg);
void orc_mips_emit_conditional_branch (OrcCompiler *compiler, int condition,
                                       OrcMipsRegister rs, OrcMipsRegister rt,
                                       unsigned int label);

enum {
  ORC_MIPS_BEQ = 04,
  ORC_MIPS_BNE,
  ORC_MIPS_BLEZ,
  ORC_MIPS_BGTZ
};

#define orc_mips_emit_beqz(compiler, reg, label) \
    orc_mips_emit_conditional_branch(compiler, ORC_MIPS_BEQ, reg, ORC_MIPS_ZERO, label)
#define orc_mips_emit_bnez(compiler, reg, label) \
    orc_mips_emit_conditional_branch(compiler, ORC_MIPS_BNE, reg, ORC_MIPS_ZERO, label)
#define orc_mips_emit_blez(compiler, reg, label) \
    orc_mips_emit_conditional_branch(compiler, ORC_MIPS_BLEZ, reg, ORC_MIPS_ZERO, label)

void orc_mips_emit_addiu (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int value);
void orc_mips_emit_addi (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int value);
void orc_mips_emit_add (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source1, OrcMipsRegister source2);
void orc_mips_emit_addu (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source1, OrcMipsRegister source2);
void orc_mips_emit_addu_qb (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source1, OrcMipsRegister source2);
void orc_mips_emit_addu_ph (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source1, OrcMipsRegister source2);
void orc_mips_emit_move (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source);
void orc_mips_emit_sub (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source1, OrcMipsRegister source2);
void orc_mips_emit_srl (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int value);
void orc_mips_emit_sll (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int value);
void orc_mips_emit_andi (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int value);

void orc_mips_emit_append (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int shift_amount);

void orc_mips_emit_prepend (OrcCompiler *compiler, OrcMipsRegister dest, OrcMipsRegister source, int shift_amount);

void orc_mips_emit_align (OrcCompiler *compiler, int align_shift);

void orc_mips_do_fixups (OrcCompiler *compiler);

#endif /* ORC_ENABLE_UNSTABLE_API */

ORC_END_DECLS

#endif /* _ORC_MIPS_H_ */