#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
FILE*kjw;
char sd,td ='y';
struct
 { char no[5];
   char np[15];
   int kh;
   char ku;
 }wst;

kjw=fopen("wisata.dat","a");
if (kjw==NULL)
	{clrscr();
   printf("File data tidak dapat dibuat !");
	getch(); }
while(td=='y'||td=='Y')
 { clrscr();
 gotoxy(6,1);printf("Entry Kunjungan Wisata");
 gotoxy(6,2);printf("----------------------");
 gotoxy(6,3);printf("Nomor Pengunjung     :");
 gotoxy(6,4);printf("Nama Pengunjung      :");
 gotoxy(6,5);printf("Kode Hari            :");
 gotoxy(6,6);printf("Kelompok Umur[A,D]   :");
 gotoxy(6,7);printf("Simpan Data[Y/T]     :");
 gotoxy(6,8);printf("Tambah Data[Y/T]     :");

 gotoxy(29,3);gets(wst.no);
 gotoxy(29,4);gets(wst.np);
 gotoxy(29,5);scanf("%i", &wst.kh);fflush(stdin);
 gotoxy(29,6);scanf("%c", &wst.ku);fflush(stdin);
 gotoxy(29,7);scanf("%c", &sd);fflush(stdin);
 if (sd=='y' || sd=='Y')
 {  fwrite (&wst,sizeof(wst),1,kjw);
    gotoxy(29,10);printf("Data Berhasil Disimpan!!");}
 else
  {  gotoxy(29,11);printf("Data Tidak Berhasil Disimpan!!");}
 gotoxy(29,8);scanf("%c", &td);fflush(stdin);
 }

 fclose(kjw);
}
