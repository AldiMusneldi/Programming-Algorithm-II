#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
main()
{
FILE * pjn267;
int br,x;
int vc;
float kp,kpn;
char hdh[10];
struct
{char no[6] ;
 float tb;
}bln267;

pjn267=fopen("Penjualannnnn.dat","r");
clrscr();
gotoxy(1,1);printf("PROMOSI PENJUALAN BULAN");
gotoxy(1,2);printf("=======================");
gotoxy(1,3);printf("----------------------------------------------------");
gotoxy(1,4);printf("|  | NOMOR |  TOTAL  | VOUCHER  |  KUPON  | HADIAH |");
gotoxy(1,5);printf("|No|       |         |          |         |        |");
gotoxy(1,6);printf("|  | BON   | BELANJA |          |         |        |");
gotoxy(1,7);printf("----------------------------------------------------");

br=8;x=0;
while (fread(&bln267,sizeof(bln267),1,pjn267)==1)
{
     if (bln267.tb>=100000)
      { vc=0.1*bln267.tb;}
     else if (bln267.tb>50000)
      { vc=5000;}
     else
      { vc=0;}

     if (bln267.tb>=50000)
     { kp=bln267.tb/50000;
       kpn=ceil(kp);}
     else
     { kp=0;}

     if (kp>=5)
     {strcpy (hdh, "Tas");}
     else if (kp>=3)
     { strcpy (hdh, "Payung");}
     else if (kp>=1)
     { strcpy (hdh, "Tshirt");}


      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(4,br); printf("| %s", bln267.no);
      gotoxy(12,br);printf("| %.0f", bln267.tb);
      gotoxy(22,br);printf("| %i", vc);
      gotoxy(33,br);printf("| %.0f", kpn);
      gotoxy(43,br);printf("| %s", hdh);
      gotoxy(52,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("----------------------------------------------------");
fclose(pjn267);
getch();
}