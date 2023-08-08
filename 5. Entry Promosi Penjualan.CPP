#include<stdio.h>
#include<conio.h>
main()
{
FILE * pjn267;
char sd,td='y';
struct
{char no[6] ;
 float tb;
}bln267;

pjn267=fopen("Penjualannnnn.dat","a");
if (pjn267==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch(); }
while (td=='y' || td=='Y')
{
  clrscr();
  gotoxy(25,1) ;printf("Promosi Penjualan Bulan");
  gotoxy(25,2) ;printf("-----------------------");
  gotoxy(25,3) ;printf("NOMOR BON          :");
  gotoxy(25,4) ;printf("TOTAL BELANJA      :");
  gotoxy(25,5) ;printf("Data Disimpan [Y/T] :");
  gotoxy(25,6);printf("Ada Data Lagi [Y/T] :");
  gotoxy(46,3) ;gets(bln267.no);
  gotoxy(46,4) ;scanf("%f",&bln267.tb);fflush(stdin);
  gotoxy(46,5) ;scanf("%c",&sd);fflush(stdin);
  if (sd=='y' || sd=='Y')
  { fwrite(&bln267,sizeof(bln267),1,pjn267);
   gotoxy (25,13);printf("Data Berhasil Disimpan");}
  else
  { gotoxy(25,13);printf("DATA TIDAK DISIMPAN");}
  gotoxy(46,6);scanf("%c",&td);fflush(stdin);
}
fclose(pjn267);
}