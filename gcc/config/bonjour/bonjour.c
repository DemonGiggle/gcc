/* Output routines for BONJOUR processor.
   Copyright (C) 2012-2017 Free Software Foundation, Inc.
   Contributed by KPIT Cummins Infosystems Limited.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "tree.h"
#include "df.h"
#include "memmodel.h"
#include "tm_p.h"
#include "regs.h"
#include "emit-rtl.h"
#include "diagnostic-core.h"
#include "stor-layout.h"
#include "calls.h"
#include "conditions.h"
#include "output.h"
#include "expr.h"
#include "builtins.h"

/* This file should be included last.  */
#include "target-def.h"

#undef TARGET_LEGITIMATE_ADDRESS_P
#define TARGET_LEGITIMATE_ADDRESS_P bonjour_legitimate_address_p


/* Return nonzero if the current function being compiled is an interrupt
   function as specified by the "interrupt" attribute.  */
int
bonjour_interrupt_function_p (void)
{
    // FIXME: currently no intrrupt function support
  return 0;
}

/* Implements the macro INITIAL_ELIMINATION_OFFSET, return the OFFSET.  */
int
bonjour_initial_elimination_offset (int from, int to)
{
    // FIXME: xxxx
    return 0;
}

/* Implements the macro INIT_CUMULATIVE_ARGS defined in bonjour.h.  */
void
bonjour_init_cumulative_args (CUMULATIVE_ARGS * cum, tree fntype,
			   rtx libfunc ATTRIBUTE_UNUSED)
{
}

/* Implements the macro FUNCTION_ARG_REGNO_P defined in bonjour.h.
   Return nonzero if N is a register used for passing parameters.  */
int
bonjour_function_arg_regno_p (int n)
{
    // FIXME: this is a temp solution
    // Disable using register for passing parameters
  return 0;
}

int
bonjour_hard_regno_mode_ok (int regno, machine_mode mode)
{
    // FIXME: xxx
    return 1;
}

/* Return non-zero value if 'x' is legitimate PIC operand
   when generating PIC code.  */
int
legitimate_pic_operand_p (rtx x)
{
    return 1;
}

/* Return the class number of the smallest class containing reg number REGNO.
   This could be a conditional expression or could index an array.  */
    enum reg_class
bonjour_regno_reg_class (int regno)
{
    // FIXME: xxx
    return NO_REGS;
}

static rtx
bonjour_function_value (const_tree type,
        const_tree fn_decl_or_type ATTRIBUTE_UNUSED,
        bool outgoing ATTRIBUTE_UNUSED)
{
    return gen_rtx_REG (TYPE_MODE (type), 0);
}

/* A function that returns whether x (an RTX) is a legitimate memory
   address on the target machine for a memory operand of mode mode. */
static bool
bonjour_legitimate_address_p (machine_mode mode, rtx x, bool strict)
{
    return true;
}

struct gcc_target targetm = TARGET_INITIALIZER;
