#include<conio.h>
#include<stdio.h>
#include<string.h>
main()
{ FILE*vf;
  int vnf;
  char sd,td;
  char ada;
  struct
  { int nf;
    char nb[15];
    long int hb;
    long int jp;
    char tgl[10];
  }vr;
td='y';
while (td=='y'||td=='Y')
{clrscr();
gotoxy(25,5);printf("Entry Data Pembelian Barang");
gotoxy(25,6);printf("---------------------------");
gotoxy(25,7);printf("Nomor Faktur      :");
gotoxy(25,8);printf("Nama Barang       :");
gotoxy(25,9);printf("Harga Beli        :");
gotoxy(25,10);printf("Jumlah Pembelian  :");
gotoxy(25,11);printf("Tanggal Beli      :");
gotoxy(25,12);printf("Simpan Data[Y/T]  :");
gotoxy(25,13);printf("Tambah Data[Y/T]  :");
gotoxy(44,7);scanf("%i", &vnf);fflush(stdin);
ada='t';
vf=fopen("barangff.dat","r");
if(vf==NULL)
{ vf=fopen("barangff.dat","w"); }
else
{ while (fread(&vr,sizeof(vr),1,vf)==1)
 { if(vr.nf==vnf)
  { gotoxy(44,8);printf("%s", vr.nb);
    gotoxy(44,9);printf("%li", vr.hb);
    gotoxy(44,10);printf("%li", vr.jp);
    gotoxy(44,11);printf("%s", vr.tgl);
    ada='y';
  }
 }
}
if (ada=='t')
{ fflush(stdin);
  gotoxy(44,8);scanf("%s", &vr.nb);fflush(stdin);
  gotoxy(44,9);scanf("%li", &vr.hb);fflush(stdin);
  gotoxy(44,10);scanf("%li", &vr.jp);fflush(stdin);
  gotoxy(44,11);scanf("%s", &vr.tgl);fflush(stdin);
  gotoxy(44,12);scanf("%c", &sd);fflush(stdin);
if(sd=='y'||sd=='Y')
   { fclose(vf);
     vf=fopen("barangff","a");
     vr.nf=vnf;
     fwrite(&vr,sizeof(vr),1,vf);
     fclose(vf);
   }
else
   { gotoxy(25,14);printf("Data Tidak Disimpan"); }
}
else
      { gotoxy(25,16);printf("Nomor Faktur Sudah Ada"); }
gotoxy(44,13);scanf("%c", &td);fflush(stdin);
}

{  int br;
   int th,hj,np;
   vf=fopen("barangff","r");


   if(vf==NULL)
    {
       printf("File Data Tidak Ada!");
       getch();
    }
    clrscr();
    gotoxy(1,1);printf("             Laporan Pembelian Barang\n");
    gotoxy(1,2);printf("-----------------------------------------------------------------------------------------------------\n");
    gotoxy(1,3);printf("|  NO  |     Nama      |   Harga    |  Jumlah   |   Tanggal  |   Total   |   Harga   |     Nilai    |\n");
    gotoxy(1,4);printf("|      |    Barang     |   Beli     | Pembelian |            |   Harga   |   Jual    |  Persediaan  |\n");
    gotoxy(1,5);printf("-----------------------------------------------------------------------------------------------------\n");

    br=6;
    while (fread(&vr,sizeof(vr),1,vf)==1)
    {
      hj=0.1*vr.hb+vr.hb;
      np=vr.jp*hj;
      th=vr.hb*vr.jp;

      gotoxy(1,br);printf("|%i", vr.nf);
      gotoxy(8,br); printf("| %s", vr.nb);
      gotoxy(24,br); printf("| %li", vr.hb);
      gotoxy(37,br);printf("|    %li", vr.jp);
      gotoxy(49,br);printf("| %s", vr.tgl);
      gotoxy(62,br);printf("| %i", th);
      gotoxy(74,br);printf("| %i", hj);
      gotoxy(86,br);printf("| %i", np);
      gotoxy(101,br);printf("|");
      br=br+1;
    }
    gotoxy(1,br);printf("-----------------------------------------------------------------------------------------------------\n");
    fclose(vf);
    getch();
}}

