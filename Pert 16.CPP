#include<stdio.h>
#include<conio.h>
entry()
{
FILE * vf;
int vkd;
char sd,td;
char ada;
struct
{int kd;
 char nd[10];
 char nb[10];
 float ps;
 long int hb;
}vr;

td='y';
while (td=='y' || td=='Y')
{ clrscr();
  gotoxy(25,1) ;printf("Entry Data Penjualan Barang");
  gotoxy(25,2) ;printf("---------------------------");
  gotoxy(25,4) ;printf("Kode Distribusi     :");
  gotoxy(25,5) ;printf("Nama Daerah         :");
  gotoxy(25,6) ;printf("Nama Barang         :");
  gotoxy(25,7) ;printf("Penjualan Sebelumnya:");
  gotoxy(25,8) ;printf("Harga Beli          :");
  gotoxy(25,9) ;printf("Data Disimpan [Y/T] :[ ]");
  gotoxy(25,10);printf("Ada Data Lagi [Y/T] :[ ]");
   /*input variabel kunci*/
  gotoxy(47,4) ; scanf("%i",&vkd);fflush(stdin);
  /*Pencarian Kode Laptop*/
  /*Buka File Data Untuk Di Baca*/
  ada='t';
  vf=fopen("dpps.dat","r");
  if (vf==NULL)
  {  /*=====Buat File Baru=====*/
  vf=fopen("dpps.dat","w");
  }
  else
  { /*Cari Kode Ke File dengan cara membandingkan Kode */
	while (fread(&vr,sizeof(vr),1,vf)==1)
	{  if(vr.kd==vkd)
        { gotoxy(47,5) ;printf("%s",vr.nd);
 			 gotoxy(47,6) ;printf("%s",vr.nb);
 			 gotoxy(47,7) ;printf("%7.1f",vr.ps);
 			 gotoxy(47,8) ;printf("%li",vr.hb);
          ada='y';
        }
   }
  }
/*Input Data Laptop Jika Kode Tidak Ada di File Data*/
     if (ada=='t')
     {  fflush(stdin);
 	     gotoxy(47,5); gets(vr.nd);fflush(stdin);
        gotoxy(47,6); gets(vr.nb);fflush(stdin);
  	  	  gotoxy(47,7); scanf("%f",&vr.ps);fflush(stdin);
        gotoxy(47,8); scanf("%li",&vr.hb);fflush(stdin);
	     gotoxy(47,9); scanf("%c",&sd);fflush(stdin);
	     if (sd=='y'||sd=='Y')
           {
         /*Buka File Data Untuk Di Tulis*/
         	fclose(vf);
	         vf=fopen("dpps.dat","a");
	         vr.kd=vkd;
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
float pd,jd,pk,hj,tps,tjd,tpk,thj,t;
struct
{int kd;
 char nd[10];
 char nb[10];
 float ps;
 long int hb;
}vr;

vf=fopen("dpps.dat","r");
if (vf==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak Ada");
getch(); }
clrscr();
gotoxy(35,1);printf("Tabel Pendistribusian Barang PT.AZFIRAZ");
gotoxy(1,2);printf("--------------------------------------------------------------------------------------------------------------");
gotoxy(1,3);printf("| No | Kode       |  Nama    |  Nama    |  Penjualan   |  Harga | Persentase |  Jumlah    |  Persentase |   Harga   |");
gotoxy(1,4);printf("|    | Distribusi |  Daerah  |  Barang  |  Sebelumnya  |  Beli  | Distribusi |  Distribusi|  Keuntungan |   Jual    |");
gotoxy(1,5);printf("--------------------------------------------------------------------------------------------------------------");

br=6;x=0; tps=0;tjd=0;tpk=0;thj=0;t=0;
while (fread(&vr,sizeof(vr),1,vf)==1)
{
     if (vr.ps>10000)
      { pd=0.1*vr.ps;
        pk=0.15*vr.hb;}
     else if (vr.ps>7500)
      { pd=0.75*vr.ps;
        pk=0.125*vr.hb;}
     else if (vr.ps>5000)
      { pd=0.05*vr.ps;
        pk=0.1*vr.hb;}
     else if (vr.ps>1000)
		{ pd=0.025*vr.ps;
        pk=0.05*vr.hb;}


      jd=pd*vr.ps+vr.ps;
      hj=pk*vr.hb+vr.hb;
      tps=tps+vr.ps;
      t=t+tjd+jd+tpk+pk+thj+hj;

      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(6,br); printf("| %i", vr.kd);
      gotoxy(18,br); printf(" | %s", vr.nd);
      gotoxy(30,br);printf("| %s", vr.nb);
      gotoxy(41,br);printf("| %7.1f", vr.ps);
      gotoxy(56,br);printf("| %li", vr.hb);
      gotoxy(65,br);printf("| %7.1f", pd);
      gotoxy(78,br);printf("| %7.1f", jd);
      gotoxy(91,br);printf("| %7.1f", pk);
      gotoxy(105,br);printf("| %7.1f", hj);
      gotoxy(117,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("-------------------------------------------------------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total                                                                   ");
gotoxy(41,br);printf("| %7.1f    ", tps);
gotoxy(56,br);printf("|");
gotoxy(78,br);printf("|");
gotoxy(92,br);printf(" %7.1f  ", t);
gotoxy(117,br);printf("|");
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
