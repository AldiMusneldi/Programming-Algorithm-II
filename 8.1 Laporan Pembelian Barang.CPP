#include<stdio.h>
#include<conio.h>
main()
{
FILE * brg;
 float hj,np,th;
 int br,x;
struct
{char nf[5] ;
 char nb[15];
 long int hg;
 long int jb;
 char tgl[10];
}vr;

brg= fopen("barang.dat","r");
if (brg==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch();
}
clrscr();
gotoxy(30,1);printf("Laporan Pembelian Barang");
gotoxy(1,2);printf("--------------------------------------------------------------------------------");
gotoxy(1,3);printf("|NO|  Nama Barang  |   Harga  |Jumlah| Tanggal  | Total  |  Harga   |Nilai     |");
gotoxy(1,4);printf("|  |               |   Beli   |      |          | Harga  |  Jual    |Persediaan|");
gotoxy(1,5);printf("--------------------------------------------------------------------------------");
		 /* 123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
			     1         2         3         4         5         6         7         8*/
br=6;x=0;
while (fread(&vr,sizeof(vr),1,brg))
{
  hj=0.1*vr.hg+vr.hg;
  np=vr.jb*hj;
  th=vr.hg*vr.jb;
  x=x+1;
  gotoxy(1,br);printf("| %i",x);
  gotoxy(4,br);printf("| %s",vr.nb);
  gotoxy(20,br);printf("| %li",vr.hg);
  gotoxy(31,br);printf("| %li",vr.jb);
  gotoxy(38,br);printf("| %s",vr.tgl);
  gotoxy(49,br);printf("| %8.1f",th);
  gotoxy(58,br);printf("| %8.1f",hj);
  gotoxy(69,br);printf("| %5.1f",np);
  gotoxy(80,br);printf("|");
  br=br+1;
}
gotoxy(1,br);printf("--------------------------------------------------------------------------------");
fclose(brg);
getche();
}
