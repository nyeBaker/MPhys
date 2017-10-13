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
/* Generated on Fri Jan 27 16:10:48 EST 2017 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 9 -name t1fv_9 -include t1f.h */

/*
 * This function contains 54 FP additions, 54 FP multiplications,
 * (or, 20 additions, 20 multiplications, 34 fused multiply/add),
 * 67 stack variables, 19 constants, and 18 memory accesses
 */
#include "t1f.h"

static void t1fv_9(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP826351822, +0.826351822333069651148283373230685203999624323);
     DVK(KP879385241, +0.879385241571816768108218554649462939872416269);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP666666666, +0.666666666666666666666666666666666666666666667);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP907603734, +0.907603734547952313649323976213898122064543220);
     DVK(KP420276625, +0.420276625461206169731530603237061658838781920);
     DVK(KP673648177, +0.673648177666930348851716626769314796000375677);
     DVK(KP898197570, +0.898197570222573798468955502359086394667167570);
     DVK(KP347296355, +0.347296355333860697703433253538629592000751354);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP439692620, +0.439692620785908384054109277324731469936208134);
     DVK(KP203604859, +0.203604859554852403062088995281827210665664861);
     DVK(KP152703644, +0.152703644666139302296566746461370407999248646);
     DVK(KP586256827, +0.586256827714544512072145703099641959914944179);
     DVK(KP968908795, +0.968908795874236621082202410917456709164223497);
     DVK(KP726681596, +0.726681596905677465811651808188092531873167623);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 16)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 16), MAKE_VOLATILE_STRIDE(9, rs)) {
	       V T1, T3, T5, T9, Th, Tb, Td, Tj, Tl, TD, T6;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       {
		    V T2, T4, T8, Tg;
		    T2 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    T4 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    T8 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    Tg = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    {
			 V Ta, Tc, Ti, Tk;
			 Ta = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 Tc = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Ti = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 Tk = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 T3 = BYTWJ(&(W[TWVL * 4]), T2);
			 T5 = BYTWJ(&(W[TWVL * 10]), T4);
			 T9 = BYTWJ(&(W[0]), T8);
			 Th = BYTWJ(&(W[TWVL * 2]), Tg);
			 Tb = BYTWJ(&(W[TWVL * 6]), Ta);
			 Td = BYTWJ(&(W[TWVL * 12]), Tc);
			 Tj = BYTWJ(&(W[TWVL * 8]), Ti);
			 Tl = BYTWJ(&(W[TWVL * 14]), Tk);
		    }
	       }
	       TD = VSUB(T5, T3);
	       T6 = VADD(T3, T5);
	       {
		    V Tt, Te, Tu, Tm, Tr, T7;
		    Tt = VSUB(Tb, Td);
		    Te = VADD(Tb, Td);
		    Tu = VSUB(Tl, Tj);
		    Tm = VADD(Tj, Tl);
		    Tr = VFNMS(LDK(KP500000000), T6, T1);
		    T7 = VADD(T1, T6);
		    {
			 V Tv, Tf, Ts, Tn;
			 Tv = VFNMS(LDK(KP500000000), Te, T9);
			 Tf = VADD(T9, Te);
			 Ts = VFNMS(LDK(KP500000000), Tm, Th);
			 Tn = VADD(Th, Tm);
			 {
			      V TG, TK, Tw, TJ, TF, TA, To, Tq;
			      TG = VFNMS(LDK(KP726681596), Tt, Tv);
			      TK = VFMA(LDK(KP968908795), Tv, Tt);
			      Tw = VFNMS(LDK(KP586256827), Tv, Tu);
			      TJ = VFNMS(LDK(KP152703644), Tu, Ts);
			      TF = VFMA(LDK(KP203604859), Ts, Tu);
			      TA = VFNMS(LDK(KP439692620), Tt, Ts);
			      To = VADD(Tf, Tn);
			      Tq = VMUL(LDK(KP866025403), VSUB(Tn, Tf));
			      {
				   V TQ, TH, TL, TN, TB, Tp, Ty, TI, Tx;
				   Tx = VFNMS(LDK(KP347296355), Tw, Tt);
				   TQ = VFNMS(LDK(KP898197570), TG, TF);
				   TH = VFMA(LDK(KP898197570), TG, TF);
				   TL = VFMA(LDK(KP673648177), TK, TJ);
				   TN = VFNMS(LDK(KP673648177), TK, TJ);
				   TB = VFNMS(LDK(KP420276625), TA, Tu);
				   ST(&(x[0]), VADD(T7, To), ms, &(x[0]));
				   Tp = VFNMS(LDK(KP500000000), To, T7);
				   Ty = VFNMS(LDK(KP907603734), Tx, Ts);
				   TI = VFMA(LDK(KP852868531), TH, Tr);
				   {
					V TO, TR, TM, TC, Tz, TP, TS, TE;
					TO = VFNMS(LDK(KP500000000), TH, TN);
					TR = VFMA(LDK(KP666666666), TL, TQ);
					TM = VMUL(LDK(KP984807753), VFNMS(LDK(KP879385241), TD, TL));
					TC = VFNMS(LDK(KP826351822), TB, Tv);
					ST(&(x[WS(rs, 6)]), VFNMSI(Tq, Tp), ms, &(x[0]));
					ST(&(x[WS(rs, 3)]), VFMAI(Tq, Tp), ms, &(x[WS(rs, 1)]));
					Tz = VFNMS(LDK(KP939692620), Ty, Tr);
					TP = VFMA(LDK(KP852868531), TO, Tr);
					TS = VMUL(LDK(KP866025403), VFMA(LDK(KP852868531), TR, TD));
					ST(&(x[WS(rs, 8)]), VFMAI(TM, TI), ms, &(x[0]));
					ST(&(x[WS(rs, 1)]), VFNMSI(TM, TI), ms, &(x[WS(rs, 1)]));
					TE = VMUL(LDK(KP984807753), VFMA(LDK(KP879385241), TD, TC));
					ST(&(x[WS(rs, 4)]), VFMAI(TS, TP), ms, &(x[0]));
					ST(&(x[WS(rs, 5)]), VFNMSI(TS, TP), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 7)]), VFMAI(TE, Tz), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 2)]), VFNMSI(TE, Tz), ms, &(x[0]));
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 9, XSIMD_STRING("t1fv_9"), twinstr, &GENUS, {20, 20, 34, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fv_9) (planner *p) {
     X(kdft_dit_register) (p, t1fv_9, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 9 -name t1fv_9 -include t1f.h */

/*
 * This function contains 54 FP additions, 42 FP multiplications,
 * (or, 38 additions, 26 multiplications, 16 fused multiply/add),
 * 38 stack variables, 14 constants, and 18 memory accesses
 */
#include "t1f.h"

static void t1fv_9(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP296198132, +0.296198132726023843175338011893050938967728390);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DVK(KP556670399, +0.556670399226419366452912952047023132968291906);
     DVK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DVK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DVK(KP663413948, +0.663413948168938396205421319635891297216863310);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP150383733, +0.150383733180435296639271897612501926072238258);
     DVK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DVK(KP813797681, +0.813797681349373692844693217248393223289101568);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 16)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 16), MAKE_VOLATILE_STRIDE(9, rs)) {
	       V T1, T6, TA, Tt, Tf, Ts, Tw, Tn, Tv;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       {
		    V T3, T5, T2, T4;
		    T2 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    T3 = BYTWJ(&(W[TWVL * 4]), T2);
		    T4 = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    T5 = BYTWJ(&(W[TWVL * 10]), T4);
		    T6 = VADD(T3, T5);
		    TA = VMUL(LDK(KP866025403), VSUB(T5, T3));
	       }
	       {
		    V T9, Td, Tb, T8, Tc, Ta, Te;
		    T8 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    T9 = BYTWJ(&(W[0]), T8);
		    Tc = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
		    Td = BYTWJ(&(W[TWVL * 12]), Tc);
		    Ta = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    Tb = BYTWJ(&(W[TWVL * 6]), Ta);
		    Tt = VSUB(Td, Tb);
		    Te = VADD(Tb, Td);
		    Tf = VADD(T9, Te);
		    Ts = VFNMS(LDK(KP500000000), Te, T9);
	       }
	       {
		    V Th, Tl, Tj, Tg, Tk, Ti, Tm;
		    Tg = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    Th = BYTWJ(&(W[TWVL * 2]), Tg);
		    Tk = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
		    Tl = BYTWJ(&(W[TWVL * 14]), Tk);
		    Ti = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Tj = BYTWJ(&(W[TWVL * 8]), Ti);
		    Tw = VSUB(Tl, Tj);
		    Tm = VADD(Tj, Tl);
		    Tn = VADD(Th, Tm);
		    Tv = VFNMS(LDK(KP500000000), Tm, Th);
	       }
	       {
		    V Tq, T7, To, Tp;
		    Tq = VBYI(VMUL(LDK(KP866025403), VSUB(Tn, Tf)));
		    T7 = VADD(T1, T6);
		    To = VADD(Tf, Tn);
		    Tp = VFNMS(LDK(KP500000000), To, T7);
		    ST(&(x[0]), VADD(T7, To), ms, &(x[0]));
		    ST(&(x[WS(rs, 3)]), VADD(Tp, Tq), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 6)]), VSUB(Tp, Tq), ms, &(x[0]));
	       }
	       {
		    V TI, TB, TC, TD, Tu, Tx, Ty, Tr, TH;
		    TI = VBYI(VSUB(VFNMS(LDK(KP342020143), Tv, VFNMS(LDK(KP150383733), Tt, VFNMS(LDK(KP984807753), Ts, VMUL(LDK(KP813797681), Tw)))), TA));
		    TB = VFNMS(LDK(KP642787609), Ts, VMUL(LDK(KP663413948), Tt));
		    TC = VFNMS(LDK(KP984807753), Tv, VMUL(LDK(KP150383733), Tw));
		    TD = VADD(TB, TC);
		    Tu = VFMA(LDK(KP766044443), Ts, VMUL(LDK(KP556670399), Tt));
		    Tx = VFMA(LDK(KP173648177), Tv, VMUL(LDK(KP852868531), Tw));
		    Ty = VADD(Tu, Tx);
		    Tr = VFNMS(LDK(KP500000000), T6, T1);
		    TH = VFMA(LDK(KP173648177), Ts, VFNMS(LDK(KP296198132), Tw, VFNMS(LDK(KP939692620), Tv, VFNMS(LDK(KP852868531), Tt, Tr))));
		    ST(&(x[WS(rs, 7)]), VSUB(TH, TI), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 2)]), VADD(TH, TI), ms, &(x[0]));
		    {
			 V Tz, TE, TF, TG;
			 Tz = VADD(Tr, Ty);
			 TE = VBYI(VADD(TA, TD));
			 ST(&(x[WS(rs, 8)]), VSUB(Tz, TE), ms, &(x[0]));
			 ST(&(x[WS(rs, 1)]), VADD(TE, Tz), ms, &(x[WS(rs, 1)]));
			 TF = VFMA(LDK(KP866025403), VSUB(TB, TC), VFNMS(LDK(KP500000000), Ty, Tr));
			 TG = VBYI(VADD(TA, VFNMS(LDK(KP500000000), TD, VMUL(LDK(KP866025403), VSUB(Tx, Tu)))));
			 ST(&(x[WS(rs, 5)]), VSUB(TF, TG), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 4)]), VADD(TF, TG), ms, &(x[0]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 9, XSIMD_STRING("t1fv_9"), twinstr, &GENUS, {38, 26, 16, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fv_9) (planner *p) {
     X(kdft_dit_register) (p, t1fv_9, &desc);
}
#endif				/* HAVE_FMA */
