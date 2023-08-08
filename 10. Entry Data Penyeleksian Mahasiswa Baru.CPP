#include<stdio.h>
#include<conio.h>
main()
{
FILE * mhs;
char sd,td='y';
struct
{char np[8] ;
 char ncm[15];
 char kpp[6];
 int nat;
 int nkd;
}vr;

mhs=fopen("mahasiswa.dat","a");
if (mhs==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch(); }
while (td=='y' || td=='Y')
{
  clrscr();
  gotoxy(25,5) ;printf("Entry Data Penyeleksian Mahasiswa Baru");
  gotoxy(25,6) ;printf("--------------------------------------");
  gotoxy(25,7) ;printf("No. Pendaftaran            :");
  gotoxy(25,8) ;printf("Nama Calon Mahasiswa       :");
  gotoxy(25,9) ;printf("Kode Pilihan Program Studi :");
  gotoxy(25,10) ;printf("Nilai Aptitude Test        :");
  gotoxy(25,11) ;printf("Nilai Kemampuan Dasar      :");
  gotoxy(25,13) ;printf("Data Disimpan [Y/T]        :");
  gotoxy(25,14);printf("Ada Data Lagi [Y/T]        :");
  gotoxy(54,7) ;gets(vr.np);
  gotoxy(54,8) ;gets(vr.ncm);
  gotoxy(54,9) ;gets(vr.kpp);
  gotoxy(54,10) ;scanf("%i",&vr.nat);fflush(stdin);
  gotoxy(54,11) ;scanf("%i",&vr.nkd);fflush(stdin);
  gotoxy(54,13) ;scanf("%c",&sd);fflush(stdin);
  if (sd=='y' || sd=='Y')
  { fwrite(&vr,sizeof(vr),1,mhs);
   gotoxy (25,17);printf("Data Berhasil Disimpan");}
  else
  { gotoxy(25,17);printf("DATA TIDAK DISIMPAN");}
  gotoxy(54,14);scanf("%c",&td);fflush(stdin);
}
fclose(mhs);
}