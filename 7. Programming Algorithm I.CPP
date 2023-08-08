#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
	char kode[4][10];
	char nmbarang[15][10];
   int harga[10];
	int jml[10];
	char adl='y';
	int jd=1,x,baris;
	long int total,diskon,bayar,tp;
	while((adl=='y'||adl=='Y')&&jd<=10)
	{
		clrscr();
		gotoxy(20,5);printf("ENTRY DATA PEMBELIAN");
		gotoxy(20,6);printf("----------------------------");
      gotoxy(20,7);printf("									 ");
		gotoxy(20,8);printf("Kode Barang        =");gets(kode[jd]);fflush(stdin);
		gotoxy(20,9);printf("Nama Barang        =");gets(nmbarang[jd]);fflush(stdin);
		gotoxy(20,10);printf("Harga              =");scanf("%i",&harga[jd]);fflush(stdin);
		gotoxy(20,11);printf("Jumlah             =");scanf("%i",&jml[jd]) ;fflush(stdin);
		jd=jd+1;
		gotoxy(20,12);printf("Ada Data Lagi [Y/T]?");scanf("%c",&adl);fflush(stdin);
	}
	clrscr();
	gotoxy(25,1);printf("LAPORAN PEMBELIAN BARANG");
	gotoxy(1,2);printf("--------------------------------------------------------------------------------");
	gotoxy(1,3);printf("| NO | KODE  |   NAMA BARANG   | HARGA |  JUMLAH |  TOTAL  | DISKON |PEMBAYARAN|");
	gotoxy(1,4);printf("--------------------------------------------------------------------------------");
					      /*12345678901234567890123456789012345678901234567890123456789012345678901234567890*/
					      /*         1         2         3         4         5         6			  7			8*/
		baris = 5;tp=0;
		for (x=1;x<=jd-1;x++)
		{
      	total=jml[x]*harga[x];

			if (total>500000)
			{ diskon= 20*total/100;}
			else
			if(total>250000 && total<=500000)
			{ diskon=15*total/100;}
			else
			if(total>100000 && total<=250000)
			{ diskon=10*total/100;}
			else
			{ diskon=0;}

         bayar=total-diskon;
         tp=tp+bayar;
			gotoxy(1,baris);printf("|");
			gotoxy(2,baris);printf("%i",x);
			gotoxy(6,baris);printf("|");
			gotoxy(7,baris);printf("%s",kode[x]);
			gotoxy(14,baris);printf("|");
			gotoxy(15,baris);printf("%s",nmbarang[x]);
			gotoxy(32,baris);printf("|");
			gotoxy(33,baris);printf("%i",harga[x]);
			gotoxy(40,baris);printf("|");
			gotoxy(41,baris);printf("%i",jml[x]);
			gotoxy(50,baris);printf("|");
			gotoxy(51,baris);printf("%6i",total);
			gotoxy(60,baris);printf("|");
			gotoxy(61,baris);printf("%5li",diskon);
			gotoxy(69,baris);printf("|");
			gotoxy(70,baris);printf("%7li",bayar);
			gotoxy(80,baris);printf("|");
			baris++;
		}
		gotoxy(1,baris);printf("--------------------------------------------------------------------------------");
      baris++;
      gotoxy(1,baris);printf("Total Pembayaran                                                      ");printf("%7li",tp);
		getch();
}
