#include<stdio.h>
#include<conio.h>
main()
{
FILE * vf;
int br,x;
int pc;
long int np, bp, tb,tnp,tbp,ttb;
struct
{int kb;
 char nb[10];
 int ps;
 long int hb;
 int lp;
}vr;

vf=fopen("dpb.dat","r");
if (vf==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak Ada");
getch(); }
clrscr();
gotoxy(35,1);printf("Tabel Persediaan Cadangan Barang-Barang Toko ABC");
gotoxy(1,2);printf("-------------------------------------------------------------------------------------------------------------------");
gotoxy(1,3);printf("| No | Kode   |  Nama    |  Penjualan   |  Harga   | Lama  |  Persediaan  |  Nilai        |   Biaya   |   Total   |");
gotoxy(1,4);printf("|    | Barang |  Barang  |  Sebelumnya  |  Barang  | Pesan |  Cadangan    |  SPersediaan  |   Pesan   |   Biaya   |");
gotoxy(1,5);printf("-------------------------------------------------------------------------------------------------------------------");

br=6;x=0; tnp=0;tbp=0;ttb=0;
while (fread(&vr,sizeof(vr),1,vf)==1)
{
     if (vr.ps>1000 && vr.lp>10)
      { pc=0.05*vr.ps;}
     else if (vr.ps>1000 && vr.lp>5)
      { pc=0.03*vr.ps;}
     else if (vr.ps>500 && vr.lp>10)
      { pc=0.04*vr.ps;}
     else if (vr.ps>500 && vr.lp>5)
		{ pc=0.02*vr.ps;}

      np=pc*vr.hb;
      bp=0.01*vr.hb;
      tb=np+bp;

      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(6,br); printf("| %i", vr.kb);
      gotoxy(14,br); printf(" | %s", vr.nb);
      gotoxy(26,br);printf("| %i", vr.ps);
      gotoxy(41,br);printf("| %li", vr.hb);
      gotoxy(52,br);printf("| %i", vr.lp);
      gotoxy(60,br);printf("| %i", pc);
      gotoxy(75,br);printf("| %li", np);
      gotoxy(91,br);printf("| %li", bp);
      gotoxy(103,br);printf("| %li", tb);
      gotoxy(115,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("-------------------------------------------------------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total                                                                   ");printf(" | %li             |", tnp);printf(" %li         |", tbp);printf(" %li         |", ttb);
br=br+1;
gotoxy(1,br);printf("-------------------------------------------------------------------------------------------------------------------");
fclose(vf);
getch();
}