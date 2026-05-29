#include <stdio.h>
#include <cblas.h>
#include <math.h>

int main()
{
printf("LEVEL 1 BLAS TESTS\n\n");
printf("AXPY test\n");
double x1[3]={1,2,3};
double y1[3]={1,1,1};
cblas_daxpy(3,2,x1,1,y1,1);
if(y1[0]==3 && y1[1]==5 && y1[2]==7)
printf("axpy ok\n");
else
printf("axpy fail\n");
printf("\nSCAL test\n");
double x2[3]={1,2,3};
cblas_dscal(3,2,x2,1);
if(x2[0]==2 && x2[1]==4 && x2[2]==6)
printf("scal ok\n");
else
printf("scal fail\n");
printf("\nCOPY test\n");
double x3[3]={5,6,7};
double y3[3]={0,0,0};
cblas_dcopy(3,x3,1,y3,1);
if(y3[0]==5 && y3[1]==6 && y3[2]==7)
printf("copy ok\n");
else
printf("copy fail\n");
printf("\nSWAP test\n");
double x4[2]={1,2};
double y4[2]={9,8};
cblas_dswap(2,x4,1,y4,1);
if(x4[0]==9 && x4[1]==8)
printf("swap ok\n");
else
printf("swap fail\n");
printf("\nDOT test\n");
double x5[3]={1,2,3};
double y5[3]={4,5,6};
double r1=cblas_ddot(3,x5,1,y5,1);
if(r1==32)
printf("dot ok\n");
else
printf("dot fail\n");
printf("\nNRM2 test\n");
double x6[2]={3,4};
double r2=cblas_dnrm2(2,x6,1);
if((int)r2==5)
printf("nrm2 ok\n");
else
printf("nrm2 fail\n");
printf("\nASUM test\n");
double x7[3]={-1,-2,3};
double r3=cblas_dasum(3,x7,1);
if(r3==6)
printf("asum ok\n");
else
printf("asum fail\n");
printf("\nIAMAX test\n");
double x8[3]={1,9,3};
int r4=cblas_idamax(3,x8,1);
if(r4==1)
printf("iamax ok\n");
else
printf("iamax fail\n");
printf("\nROTG test\n");
double a=3;
double b=4;
double c;
double s;
cblas_drotg(&a,&b,&c,&s);
if((int)a==5)
printf("rotg ok\n");
else
printf("rotg fail\n");
printf("\nROT test\n");
double x9[2]={1,0};
double y9[2]={0,1};
cblas_drot(2,x9,1,y9,1,0,-1);
printf("rot done\n");
printf("\nROTMG test\n");
double d1=1;
double d2=1;
double a1=1;
double b1=1;
double param[5];
cblas_drotmg(&d1,&d2,&a1,b1,param);
printf("rotmg done\n");
printf("\nROTM test\n");
double x10[2]={1,2};
double y10[2]={3,4};
cblas_drotm(2,x10,1,y10,1,param);
printf("rotm done\n");
printf("\nEND\n");
return 0;
}