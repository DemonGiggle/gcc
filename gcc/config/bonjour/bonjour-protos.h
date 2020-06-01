/* Prototypes for exported functions defined in bonjour.c
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

#ifndef GCC_BONJOUR_PROTOS_H
#define GCC_BONJOUR_PROTOS_H

/* Register usage.  */
extern enum reg_class bonjour_regno_reg_class (int);
extern int bonjour_hard_regno_mode_ok (int regno, machine_mode);

/* Passing function arguments.  */
extern int bonjour_function_arg_regno_p (int);

#ifdef TREE_CODE
#ifdef RTX_CODE

extern void bonjour_init_cumulative_args (CUMULATIVE_ARGS *, tree, rtx);

#endif /* RTX_CODE.  */
#endif /* TREE_CODE.  */

/* Enumeration giving the various data models we support.  */
enum data_model_type
{
  DM_DEFAULT,		/* Default data model (in BONJOURC/C+ - up to 16M).  */
  DM_NEAR,		/* Near data model    (in BONJOURC/C+ - up to 1M).  */
  DM_FAR,		/* Far data model     (in BONJOURC+   - up to 4G)
			   (in BONJOURC    - up to 16M).  */
  ILLEGAL_DM		/* Illegal data model.  */
};

#ifdef RTX_CODE

/* Addressing Modes.  */
struct bonjour_address
{
  rtx base;	 	/* Base register: Any register or register pair.  */
  rtx index;		/* Index register: If one is present.  */
  rtx disp;		/* Displacement or Absolute address.  */
  enum data_model_type data;	/* data ref type.  */
  int code;		/* Whether the address is code address. 
			   0 - data, 1 - code label, 2 - function label.  */
};

enum bonjour_addrtype
{
  BONJOUR_INVALID,
  BONJOUR_REG_REL,
  BONJOUR_REGP_REL,
  BONJOUR_INDEX_REGP_REL,
  BONJOUR_ABSOLUTE
};

extern void notice_update_cc (rtx);
extern int bonjour_operand_bit_pos (int val, int bitval);
extern void bonjour_decompose_const (rtx x, int *code,
				  enum data_model_type *data,
				  bool treat_as_const);
extern enum bonjour_addrtype bonjour_decompose_address (rtx addr,
						  struct bonjour_address *out,
						  bool debug_print,
						  bool treat_as_const);
extern int bonjour_const_double_ok (rtx op);
extern int legitimate_pic_operand_p (rtx);
extern rtx legitimize_pic_address (rtx, machine_mode, rtx);


/* Prologue/Epilogue functions.  */
extern int bonjour_initial_elimination_offset (int, int);
extern char *bonjour_prepare_push_pop_string (int);
extern void bonjour_expand_prologue (void);
extern void bonjour_expand_epilogue (void);
extern const char *bonjour_emit_add_sub_di (rtx *, enum rtx_code);
extern const char *bonjour_emit_logical_di (rtx *, enum rtx_code);

#endif /* RTX_CODE.  */

/* Handling the "interrupt" attribute.  */
extern int bonjour_interrupt_function_p (void);
extern bool bonjour_is_data_model (enum data_model_type);

#endif /* Not GCC_BONJOUR_PROTOS_H.  */ 
