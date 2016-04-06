      SUBROUTINE ZNME2PXX
     I(MEND1,MNWAV,JEQUH,
     O PNM  ,HNM  ,
     W PPNM ,HHNM)
C
C     THIS SUBROUTINE COMPUTES LEGENDRE FUNCTION VALUES ON HEMISPHERIC
C     EQUIDISTANT GRIDS
C
C    NOTE1: THE ORDER OF WAVE COMPONENTS IS COLUMNWISE
C
      IMPLICIT REAL*8(A-H,O-Z)
Crizvi      REAL*4 PNM (MNWAV,JEQUH),HNM (MNWAV,JEQUH)
      REAL PNM (MNWAV,JEQUH),HNM (MNWAV,JEQUH)
      REAL*8 PPNM(MNWAV      ),HHNM(MNWAV      )
C
      NLATH=JEQUH-1
      FLIV =1.E0/DFLOAT(NLATH)
      FLAT =2.E0*ATAN(1.E0)
      DLAT =FLAT*FLIV
C
      DO 100 J=1,JEQUH
cch      SL=DSIN(FLAT)
      SL=SIN(FLAT)
      CALL LGNDR1(SL,MEND1,PPNM,HHNM)
      DO 120 L=1,MNWAV
cch      PNM (L,J)=SNGL(PPNM(L))
cch      HNM (L,J)=SNGL(HHNM(L))
      PNM (L,J)=PPNM(L)
      HNM (L,J)=HHNM(L)
  120 CONTINUE
      FLAT=FLAT-DLAT
  100 CONTINUE
C
C
      RETURN
      END SUBROUTINE ZNME2PXX
