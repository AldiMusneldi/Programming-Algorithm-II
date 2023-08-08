#include<stdio.h>
#include<conio.h>

entry()
{
FILE * vf;
int vkb;
char sd,td;
char ada;
struct
{int kb;
 char nb[10];
 float ps;
 long int hb;
 int lp;
}vr;

td='y';
while (td=='y' || td=='Y')
{ clrscr();
  gotoxy(25,1) ;printf("Entry Data Penjualan Barang");
  gotoxy(25,2) ;printf("---------------------------");
  gotoxy(25,4) ;printf("Kode Barang         :");
  gotoxy(25,5) ;printf("Nama Barang         :");
  gotoxy(25,6) ;printf("Penjualan Sebelumnya:");
  gotoxy(25,7) ;printf("Harga Barang        :");
  gotoxy(25,8) ;printf("Lama Pesan          :    Hari");
  gotoxy(25,9) ;printf("Data Disimpan [Y/T] :[ ]");
  gotoxy(25,10);printf("Ada Data Lagi [Y/T] :[ ]");
   /*input variabel kunci*/
  gotoxy(47,4) ; scanf("%i",&vkb);fflush(stdin);
  /*Pencarian Kode Laptop*/
  /*Buka File Data Untuk Di Baca*/
  ada='t';
  vf=fopen("dpb2.dat","r");
  if (vf==NULL)
  {  /*=====Buat File Baru=====*/
  vf=fopen("dpb2.dat","w");
  }
  else
  { /*Cari Kode Ke File dengan cara membandingkan Kode */
	while (fread(&vr,sizeof(vr),1,vf)==1)
	{  if(vr.kb==vkb)
        { gotoxy(47,5) ;printf("%s",vr.nb);
 			 gotoxy(47,6) ;printf("%.0f",vr.ps);
 			 gotoxy(47,7) ;printf("%li",vr.hb);
 			 gotoxy(47,8) ;printf("%i",vr.lp);
          ada='y';
        }
   }
  }
/*Input Data Laptop Jika Kode Tidak Ada di File Data*/
     if (ada=='t')
     {  fflush(stdin);
 	     gotoxy(47,5); gets(vr.nb);fflush(stdin);
        gotoxy(47,6); scanf("%f", &vr.ps);fflush(stdin);
  	  	  gotoxy(47,7); scanf("%li",&vr.hb);fflush(stdin);
        gotoxy(47,8); scanf("%i",&vr.lp);fflush(stdin);
	     gotoxy(47,9); scanf("%c",&sd);fflush(stdin);
	     if (sd=='y'||sd=='Y')
           {
         /*Buka File Data Untuk Di Tulis*/
         	fclose(vf);
	         vf=fopen("dpb2.dat","a");
	         vr.kb=vkb;
            fwrite(&vr,sizeof(vr),1,vf);
            fclose(vf);
            gotoxy (25,13);printf("Data Berhasil Disimpan");
            }

     else
	  { gotoxy(25,14);printf("Data Tidak Disimpan");}

     }
     else
     { gotoxy(25,16);printf("Kode Barang Sudah Ada");}

     gotoxy(47,10);scanf("%c",&td);fflush(stdin);
  }
fclose(vf);
getch();
}

laporan()
{
FILE * vf;
int br,x;
float pc;
float np, bp, tb,tnp,tbp,ttb;
struct
{int kb;
 char nb[10];
 float ps;
 long int hb;
 int lp;
}vr;

vf=fopen("dpb2.dat","r");
if (vf==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak Ada");
getch(); }
clrscr();
gotoxy(35,1);printf("Tabel Persediaan Cadangan Barang-Barang Toko ABC");
gotoxy(1,2);printf("-------------------------------------------------------------------------------------------------------------------");
gotoxy(1,3);printf("| No | Kode   |  Nama    |  Penjualan   |  Harga   | Lama  |  Persediaan  |  Nilai        |   Biaya   |   Total   |");
gotoxy(1,4);printf("|    | Barang |  Barang  |  Sebelumnya  |  Barang  | Pesan |  Cadangan    |  Persediaan   |   Pesan   |   Biaya   |");
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
     else
     { pc=0.01*vr.ps;}

      np=pc*vr.hb;
      bp=0.01*vr.hb;
      tb=np+bp;
      tnp=tnp+np;
      tbp=tbp+bp;
      ttb=ttb+tb;

      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(6,br); printf("| %i", vr.kb);
      gotoxy(14,br); printf(" | %s", vr.nb);
      gotoxy(26,br);printf("| %7.1f", vr.ps);
      gotoxy(41,br);printf("| %li", vr.hb);
      gotoxy(52,br);printf("| %i", vr.lp);
      gotoxy(60,br);printf("| %7.1f", pc);
      gotoxy(75,br);printf("| %7.1f", np);
      gotoxy(91,br);printf("| %7.1f", bp);
      gotoxy(103,br);printf("| %7.1f", tb);
      gotoxy(115,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("-------------------------------------------------------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total                                                                   ");
gotoxy(75,br);printf("| %7.1f    |", tnp);
gotoxy(92,br);printf(" %7.1f  |", tbp);
gotoxy(104,br);printf(" %7.1f|", ttb);
br=br+1;
gotoxy(1,br);printf("-------------------------------------------------------------------------------------------------------------------");
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
