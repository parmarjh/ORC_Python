
#ifndef _ORC_NEON_H_
#define _ORC_NEON_H_

#include <orc/orc.h>
#include <orc/arm.h>

void orc_neon_loadb (OrcCompiler *compiler, int dest, int src1, int update, int is_aligned);
void orc_neon_loadw (OrcCompiler *compiler, int dest, int src1, int update, int is_aligned);
void orc_neon_loadl (OrcCompiler *compiler, int dest, int src1, int update, int is_aligned);
void orc_neon_neg (OrcCompiler *compiler, int dest);
void orc_neon_storeb (OrcCompiler *compiler, int dest, int update, int src1, int is_aligned);
void orc_neon_storew (OrcCompiler *compiler, int dest, int update, int src1, int is_aligned);
void orc_neon_storel (OrcCompiler *compiler, int dest, int update, int src1, int is_aligned);
void orc_neon_emit_loadib (OrcCompiler *p, int reg, int value);
void orc_neon_emit_loadiw (OrcCompiler *p, int reg, int value);
void orc_neon_emit_loadil (OrcCompiler *p, int reg, int value);
void orc_neon_emit_loadpb (OrcCompiler *p, int reg, int param);
void orc_neon_emit_loadpw (OrcCompiler *p, int reg, int param);
void orc_neon_emit_loadpl (OrcCompiler *p, int reg, int param);


#endif

