#include<stdio.h>
#include<conio.h>
main()
{
FILE * pjn;
int br,x;
long int th,tth,bsd,tpsd;
int tjj;
float dsc;
struct
{char no[4] ;
 char tp[10];
 char lp[25];
 long int hj;
 int jj;
}lpt;

pjn=fopen("Penjualan.dat","r");
clrscr();
gotoxy(35,1);printf("Laporan Data Penjualan");
gotoxy(1,2);printf("-------------------------------------------------------------------------------------------");
gotoxy(1,3);printf("|  |  No. |  Tanggal  |      Nama Laptop       |  Harga  | Jumlah |  Total   |  Bayar     |");
gotoxy(1,4);printf("|No|      |           |                        |         |        |          |  Setelah   |");
gotoxy(1,5);printf("|  |Faktur| Penjualan |                        |  Jual   |  Jual  |  Harga   |  Diskon    |");
gotoxy(1,6);printf("-------------------------------------------------------------------------------------------");

br=7;x=0; tjj=0;tth=0;tpsd=0;
while (fread(&lpt,sizeof(lpt),1,pjn)==1)
{    th=lpt.hj*lpt.jj;
     if (th>30000000)
      { dsc=0.1*th;}
     else if (th>25000000)
      { dsc=0.075*th;}
     else if (th>20000000)
      { dsc=0.05*th;}
     else if (th>15000000)
		{ dsc=0.02*th;}

      bsd=th-dsc;
      tjj=lpt.jj+tjj;
      tth=th+tth;
      tpsd=bsd+tpsd;

      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(4,br); printf("| %s", lpt.no);
      gotoxy(10,br); printf(" | %s", lpt.tp);
      gotoxy(23,br);printf("| %s", lpt.lp);
      gotoxy(48,br);printf("| %li", lpt.hj);
      gotoxy(58,br);printf("| %i", lpt.jj);
      gotoxy(67,br);printf("| %li", th);
      gotoxy(78,br);printf("| %li", bsd);
      gotoxy(91,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("-------------------------------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total                                                  ");printf(" | %i     |", tjj);printf(" %li|", tth);printf(" %li   |", tpsd);
br=br+1;
gotoxy(1,br);printf("-------------------------------------------------------------------------------------------");
fclose(pjn);
getch();
}