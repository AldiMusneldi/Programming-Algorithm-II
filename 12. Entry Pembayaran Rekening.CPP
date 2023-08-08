#include<stdio.h>
#include<conio.h>
main ()
{
FILE*rkg;
char sd,td='y';
struct
{ int nbp;
  char nr[16];
  char nm[25];
  int dy;
  long int mbl;
  long int mbi;
}vr;

rkg=fopen("rekening.dat","w");
if (rkg==NULL)
{ clrscr();
gotoxy(20,22);printf("Data Tidak Dibuat");
getch();}
while (td=='y' || td=='Y')
{
clrscr();
gotoxy(30,1);printf("Entry Pembayaran Rekening");
gotoxy(30,2);printf("-------------------------");
gotoxy(30,3);printf("No. Bukti Pembayaran    :");
gotoxy(30,4);printf("No Rekening             :");
gotoxy(30,5);printf("Nama Pelanggan          :");
gotoxy(30,6);printf("Daya                    :");
gotoxy(30,7);printf("Meteran Bulan Lalu      :");
gotoxy(30,8);printf("Meteran Bulan Ini       :");
gotoxy(30,9);printf("Simpan Data [Y/T]       :");
gotoxy(30,10);printf("Tambah Data [Y/T]       :");
gotoxy(56,3);scanf("%i",&vr.nbp);fflush(stdin);
gotoxy(56,4);gets(vr.nr);
gotoxy(56,5);gets(vr.nm);
gotoxy(56,6);scanf("%i", &vr.dy);fflush(stdin);
gotoxy(56,7);scanf("%li", &vr.mbl);fflush(stdin);
gotoxy(56,8);scanf("%li", &vr.mbi);fflush (stdin);
gotoxy(56,9);scanf("%c", &sd);fflush(stdin);
 if (sd=='y' || sd=='Y')
 { fwrite(&vr, sizeof(vr),1,rkg);
 gotoxy(30,12);printf("Data Berhasil Disimpan");}
 else
 { gotoxy(30,12);printf("Data Tidak Disimpan");}
 gotoxy(56,10);scanf("%c",&td);fflush(stdin);
 }
 fclose(rkg);
 }


