#include<stdio.h>
#include<conio.h>
main()
{
FILE * brg;
char sd,td='y';
struct
{char nf[5] ;
 char nb[15];
 long int hg;
 long int jb;
 char tgl[10];
}vr;

brg=fopen("barang.dat","a");
if (brg==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch(); }
while (td=='y' || td=='Y')
{
  clrscr();
  gotoxy(25,1) ;printf("Entry Data Pembelian Barang");
  gotoxy(25,2) ;printf("---------------------------");
  gotoxy(25,4) ;printf("No. Faktur        :");
  gotoxy(25,5) ;printf("Nama Barang       :");
  gotoxy(25,6) ;printf("Harga Beli        :");
  gotoxy(25,7) ;printf("Jumlah Pembelian  :");
  gotoxy(25,8) ;printf("Tanggal Beli      :");
  gotoxy(25,9) ;printf("Simpan Data [Y/T] :");
  gotoxy(25,10);printf("Tambah Data [Y/T] :");
  gotoxy(45,4) ;gets(vr.nf);
  gotoxy(45,5) ;gets(vr.nb);
  gotoxy(45,6) ;scanf("%li",&vr.hg);
  gotoxy(45,7) ;scanf("%li",&vr.jb);fflush(stdin);
  gotoxy(45,8) ;gets(vr.tgl);fflush(stdin);
  gotoxy(45,9) ;scanf("%c",&sd);fflush(stdin);
  if (sd=='y' || sd=='Y')
  { fwrite(&vr,sizeof(vr),1,brg);
   gotoxy (25,13);printf("Data Berhasil Disimpan");}
  else
  { gotoxy(25,13);printf("DATA TIDAK DISIMPAN");}
  gotoxy(45,10);scanf("%c",&td);fflush(stdin);
}
fclose(brg);
}
