/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Fri Jan 27 16:12:17 EST 2017 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cf.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 9 -name r2cfII_9 -dft-II -include r2cfII.h */

/*
 * This function contains 42 FP additions, 34 FP multiplications,
 * (or, 12 additions, 4 multiplications, 30 fused multiply/add),
 * 46 stack variables, 17 constants, and 18 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_9(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DK(KP879385241, +0.879385241571816768108218554649462939872416269);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DK(KP666666666, +0.666666666666666666666666666666666666666666667);
     DK(KP673648177, +0.673648177666930348851716626769314796000375677);
     DK(KP898197570, +0.898197570222573798468955502359086394667167570);
     DK(KP826351822, +0.826351822333069651148283373230685203999624323);
     DK(KP907603734, +0.907603734547952313649323976213898122064543220);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP420276625, +0.420276625461206169731530603237061658838781920);
     DK(KP315207469, +0.315207469095904627298647952427796244129086440);
     DK(KP203604859, +0.203604859554852403062088995281827210665664861);
     DK(KP152703644, +0.152703644666139302296566746461370407999248646);
     DK(KP726681596, +0.726681596905677465811651808188092531873167623);
     DK(KP968908795, +0.968908795874236621082202410917456709164223497);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(36, rs), MAKE_VOLATILE_STRIDE(36, csr), MAKE_VOLATILE_STRIDE(36, csi)) {
	       E To, T5, Tp, Ta, Ti, Tm, TB, Tq, Tt, Tf, Th;
	       {
		    E T1, T6, T4, Tb, Tk, T9, Tc, Td, Tl, Te;
		    {
			 E T2, T3, T7, T8;
			 T1 = R0[0];
			 T2 = R0[WS(rs, 3)];
			 T3 = R1[WS(rs, 1)];
			 T6 = R0[WS(rs, 1)];
			 T7 = R0[WS(rs, 4)];
			 T8 = R1[WS(rs, 2)];
			 T4 = T2 - T3;
			 To = T2 + T3;
			 Tb = R0[WS(rs, 2)];
			 Tk = T7 + T8;
			 T9 = T7 - T8;
			 Tc = R1[0];
			 Td = R1[WS(rs, 3)];
		    }
		    T5 = T1 + T4;
		    Tp = FNMS(KP500000000, T4, T1);
		    Ta = T6 + T9;
		    Tl = FNMS(KP500000000, T9, T6);
		    Te = Tc + Td;
		    Ti = Tc - Td;
		    Tm = FMA(KP968908795, Tl, Tk);
		    TB = FNMS(KP726681596, Tk, Tl);
		    Tq = FNMS(KP152703644, Tk, Tl);
		    Tt = FMA(KP203604859, Tl, Tk);
		    Tf = Tb - Te;
		    Th = FMA(KP500000000, Te, Tb);
	       }
	       {
		    E Ts, Tr, TA, Tj, Tg;
		    Ts = FMA(KP315207469, Ti, Th);
		    Tr = FNMS(KP420276625, Th, Ti);
		    TA = FMA(KP203604859, Th, Ti);
		    Tj = FNMS(KP152703644, Ti, Th);
		    Tg = Ta + Tf;
		    Ci[WS(csi, 1)] = KP866025403 * (Tf - Ta);
		    {
			 E Tu, Tx, TF, TC;
			 Tu = FNMS(KP907603734, Tt, Ts);
			 Tx = FNMS(KP826351822, Tr, Tq);
			 TF = FMA(KP898197570, TB, TA);
			 TC = FNMS(KP898197570, TB, TA);
			 {
			      E TE, Tn, Tv, Ty;
			      TE = FNMS(KP673648177, Tm, Tj);
			      Tn = FMA(KP673648177, Tm, Tj);
			      Cr[WS(csr, 4)] = T5 + Tg;
			      Cr[WS(csr, 1)] = FNMS(KP500000000, Tg, T5);
			      Tv = FNMS(KP666666666, Tu, Tr);
			      Ty = FNMS(KP666666666, Tx, Tt);
			      Cr[0] = FMA(KP852868531, TF, Tp);
			      {
				   E TG, TD, Tw, Tz;
				   TG = FMA(KP500000000, TF, TE);
				   Ci[0] = -(KP984807753 * (FMA(KP879385241, To, Tn)));
				   TD = FNMS(KP666666666, Tn, TC);
				   Tw = FMA(KP826351822, Tv, Tq);
				   Tz = FMA(KP907603734, Ty, Ts);
				   Cr[WS(csr, 3)] = FNMS(KP852868531, TG, Tp);
				   Ci[WS(csi, 3)] = -(KP866025403 * (FMA(KP852868531, TD, To)));
				   Cr[WS(csr, 2)] = FNMS(KP852868531, Tw, Tp);
				   Ci[WS(csi, 2)] = KP866025403 * (FNMS(KP939692620, Tz, To));
			      }
			 }
		    }
	       }
	  }
     }
}

static const kr2c_desc desc = { 9, "r2cfII_9", {12, 4, 30, 0}, &GENUS };

void X(codelet_r2cfII_9) (planner *p) {
     X(kr2c_register) (p, r2cfII_9, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 9 -name r2cfII_9 -dft-II -include r2cfII.h */

/*
 * This function contains 42 FP additions, 30 FP multiplications,
 * (or, 25 additions, 13 multiplications, 17 fused multiply/add),
 * 39 stack variables, 14 constants, and 18 memory accesses
 */
#include "r2cfII.h"

static void r2cfII_9(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP663413948, +0.663413948168938396205421319635891297216863310);
     DK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DK(KP556670399, +0.556670399226419366452912952047023132968291906);
     DK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DK(KP150383733, +0.150383733180435296639271897612501926072238258);
     DK(KP813797681, +0.813797681349373692844693217248393223289101568);
     DK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DK(KP296198132, +0.296198132726023843175338011893050938967728390);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(36, rs), MAKE_VOLATILE_STRIDE(36, csr), MAKE_VOLATILE_STRIDE(36, csi)) {
	       E T1, T4, To, Ta, Tl, Tk, Tf, Ti, Th, T2, T3, T5, Tg;
	       T1 = R0[0];
	       T2 = R1[WS(rs, 1)];
	       T3 = R0[WS(rs, 3)];
	       T4 = T2 - T3;
	       To = T2 + T3;
	       {
		    E T6, T7, T8, T9;
		    T6 = R0[WS(rs, 1)];
		    T7 = R1[WS(rs, 2)];
		    T8 = R0[WS(rs, 4)];
		    T9 = T7 - T8;
		    Ta = T6 - T9;
		    Tl = T7 + T8;
		    Tk = FMA(KP500000000, T9, T6);
	       }
	       {
		    E Tb, Tc, Td, Te;
		    Tb = R0[WS(rs, 2)];
		    Tc = R1[0];
		    Td = R1[WS(rs, 3)];
		    Te = Tc + Td;
		    Tf = Tb - Te;
		    Ti = FMA(KP500000000, Te, Tb);
		    Th = Tc - Td;
	       }
	       Ci[WS(csi, 1)] = KP866025403 * (Tf - Ta);
	       T5 = T1 - T4;
	       Tg = Ta + Tf;
	       Cr[WS(csr, 1)] = FNMS(KP500000000, Tg, T5);
	       Cr[WS(csr, 4)] = T5 + Tg;
	       {
		    E Tr, Tt, Tw, Tv, Tu, Tp, Tq, Ts, Tj, Tm, Tn;
		    Tr = FMA(KP500000000, T4, T1);
		    Tt = FMA(KP296198132, Th, KP939692620 * Ti);
		    Tw = FNMS(KP813797681, Th, KP342020143 * Ti);
		    Tv = FNMS(KP984807753, Tk, KP150383733 * Tl);
		    Tu = FMA(KP173648177, Tk, KP852868531 * Tl);
		    Tp = FNMS(KP556670399, Tl, KP766044443 * Tk);
		    Tq = FMA(KP852868531, Th, KP173648177 * Ti);
		    Ts = Tp + Tq;
		    Tj = FNMS(KP984807753, Ti, KP150383733 * Th);
		    Tm = FMA(KP642787609, Tk, KP663413948 * Tl);
		    Tn = Tj - Tm;
		    Ci[0] = FNMS(KP866025403, To, Tn);
		    Cr[0] = Tr + Ts;
		    Ci[WS(csi, 3)] = FNMS(KP500000000, Tn, KP866025403 * ((Tp - Tq) - To));
		    Cr[WS(csr, 3)] = FMA(KP866025403, Tm + Tj, Tr) - (KP500000000 * Ts);
		    Ci[WS(csi, 2)] = FMA(KP866025403, To - (Tu + Tt), KP500000000 * (Tw - Tv));
		    Cr[WS(csr, 2)] = FMA(KP500000000, Tt - Tu, Tr) + (KP866025403 * (Tv + Tw));
	       }
	  }
     }
}

static const kr2c_desc desc = { 9, "r2cfII_9", {25, 13, 17, 0}, &GENUS };

void X(codelet_r2cfII_9) (planner *p) {
     X(kr2c_register) (p, r2cfII_9, &desc);
}

#endif				/* HAVE_FMA */
