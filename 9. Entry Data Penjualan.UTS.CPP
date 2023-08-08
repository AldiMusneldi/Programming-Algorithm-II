#include<stdio.h>
#include<conio.h>
main()
{
FILE * pjn;
char sd,td='y';
struct
{char no[4] ;
 char tp[10];
 char lp[25];
 long int hj;
 int jj;
}lpt;

pjn=fopen("Penjualan.dat","a");
if (pjn==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch(); }
while (td=='y' || td=='Y')
{
  clrscr();
  gotoxy(25,1) ;printf("Entry Data Penjualan");
  gotoxy(25,2) ;printf("--------------------");
  gotoxy(25,4) ;printf("No. Faktur          :");
  gotoxy(25,5) ;printf("Tanggal Penjualan   :");
  gotoxy(25,6) ;printf("Nama Laptop         :");
  gotoxy(25,7) ;printf("Harga Jual          :");
  gotoxy(25,8) ;printf("Jumlah Jual         :");
  gotoxy(25,9) ;printf("Data Disimpan [Y/T] :");
  gotoxy(25,10);printf("Ada Data Lagi [Y/T] :");
  gotoxy(46,4) ;gets(lpt.no);
  gotoxy(46,5) ;gets(lpt.tp);
  gotoxy(46,6) ;gets(lpt.lp);
  gotoxy(46,7) ;scanf("%li",&lpt.hj);fflush(stdin);
  gotoxy(46,8) ;scanf("%i",&lpt.jj);fflush(stdin);
  gotoxy(46,9) ;scanf("%c",&sd);fflush(stdin);
  if (sd=='y' || sd=='Y')
  { fwrite(&lpt,sizeof(lpt),1,pjn);
   gotoxy (25,13);printf("Data Berhasil Disimpan");}
  else
  { gotoxy(25,13);printf("DATA TIDAK DISIMPAN");}
  gotoxy(46,10);scanf("%c",&td);fflush(stdin);
}
fclose(pjn);
}