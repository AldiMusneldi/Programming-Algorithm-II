#include<stdio.h>
#include<conio.h>
entry()
{
/*Deklarasi Pointer File*/
FILE*vf;
int vkb;
char td ='Y',sd='y';
char ada;
/*Deklarasi data buku bertipe struktur*/
struct
{int kb;
 char jb[25];
 char pg[20];
 char pn[20];
 int jml_b;
 }vr;

td='y';
 while(td=='y'||td=='Y')
 {clrscr();
 /*Cetak Disain Input data buku*/
 gotoxy(25,5);printf("Input Data Buku");
 gotoxy(25,6);printf("---------------");
 gotoxy(25,7);printf("Kode buku         :");
 gotoxy(25,8);printf("Judul buku        :");
 gotoxy(25,9);printf("Pengarang buku    :");
 gotoxy(25,10);printf("Penerbit          :");
 gotoxy(25,11);printf("Jumlah buku       :");
 gotoxy(25,12);printf("Simpan Data[Y/T?] :");
 gotoxy(25,13);printf("Tambah Data[T/T?] :");
 gotoxy(25,14);printf("----------------------");
 /*input variabel kunci*/
 gotoxy(45,7);scanf("%i", &vkb);fflush(stdin);
 /*Pencarian Kode Buku*/
 /*Buka File Data Untuk Di Baca*/
 ada='t';
 vf=fopen("dbukud.dat","r");
 if (vf==NULL)
 { /*=====Buat File Baru=====*/
   vf=fopen("dbukud.dat","w");}
 else
 {  /*Cari Kode Ke File dengan cara membandingkan Kode */
   while(fread(&vr,sizeof(vr),1,vf)==1)
 	  { if (vr.kb==vkb)
        {  gotoxy(45,8) ;printf("%s", vr.jb);
 		     gotoxy(45,9) ;printf("%s", vr.pg);
 			  gotoxy(45,10) ;printf("%s", vr.pn);
 			  gotoxy(45,11) ;printf("%i",vr.jml_b);
           ada='y';
        }
     }
 }
/*Input Data Buku Jika Kode Tidak Ada di File Data*/
if(ada=='t')
 { fflush(stdin);
 	gotoxy(45,8);gets(vr.jb);fflush(stdin);
 	gotoxy(45,9);gets(vr.pg);fflush(stdin);
 	gotoxy(45,10);gets(vr.pn);fflush(stdin);
   gotoxy(45,11);scanf("%i",&vr.jml_b);fflush(stdin);
 	gotoxy(45,12);scanf("%c",&sd);fflush(stdin);
 	/*Simpan data buku*/
 	if(sd=='Y'||sd=='y')
   { /*Tutup File*/
     fclose(vf);
     /*Buka File Data Untuk Di Tulis*/
     vf=fopen("dbukud.dat","a");
     vr.kb=vkb;
     fwrite(&vr,sizeof(vr),1,vf);
     fclose(vf);
     gotoxy(40,16);printf("Data Berhasil Disimpan"); }
   else
   { gotoxy(40,16);printf("Data Tidak Disimpan");}

   }
   else
   { gotoxy(40,16);printf("Kode Buku Sudah Ada");}

   gotoxy(45,13);scanf("%c",&td);fflush(stdin);
 }
 /*tutup file data*/
 fclose(vf);
}

laporan()
{
FILE*vf;
int br;
struct
{ int kb;
  char jb[25];
  char pg[20];
  char pn[20];
  int jml_b;
}vr;
vf=fopen("dbukud.dat","r");
if (vf==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak Ada");
getch(); }
clrscr();
gotoxy(35,1);printf("LAPORAN DATA BUKU");
gotoxy(1,2);printf("----------------------------------------------------------------------------------");
gotoxy(1,3);printf("| Kode |       Judul Buku      |     Pengarang     |       Penerbit     | Jumlah |");
gotoxy(1,4);printf("----------------------------------------------------------------------------------");
                  /*12345678901234567890123456789012345678901234567890123456789012345678901234567890 */
                  /*         1         2         3         4         5         6         7         8 */
br=5;
while(fread(&vr,sizeof(vr),1,vf)==1)
{
      gotoxy(1,br); printf("| %i", vr.kb);
      gotoxy(8,br); printf("| %s", vr.jb);
      gotoxy(32,br);printf("| %s", vr.pg);
      gotoxy(52,br);printf("| %s", vr.pn);
      gotoxy(73,br);printf("| %i", vr.jml_b);
      gotoxy(80,br);printf("  |");
      br=br+1;
}
gotoxy(1,br);printf("----------------------------------------------------------------------------------");
fclose(vf);
getch();
}

main ()
{
  int pil=0;
  while(pil<3)
   {
       clrscr();
       gotoxy(20,5);printf("Menu Pilihan Yang Tersedia");
       gotoxy(20,6);printf("[1] Entry (Untuk Megisi Data)");
       gotoxy(20,7);printf("[2] Laporan (Untuk Menampilkan Data)");
       gotoxy(20,8);printf("[3] Exit (Keluar Dari Menu Program)");
       gotoxy(20,10);printf("Silahkan Masukkan Pilihan Anda : ");scanf("%i", &pil);
       if (pil==1)
       { entry(); continue; }
       else if (pil==2)
       {laporan(); continue;}
   }
}