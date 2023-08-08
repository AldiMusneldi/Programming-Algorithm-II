#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
	char T[4],A[2],YA[10],SH[15];
   char td='y';
	float AF, IR, AA, MD;
	int S;
if (td==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch(); }
while (td=='y' || td=='Y')
{  clrscr();

		printf("LARIS JAYA MOTOR\n");
		printf("Transaksi Penjualan Mobil \n");
		printf("========================= \n");
		printf ("\n");
		printf("Tahun Penjualan        :");
		scanf("%s", T);
      //Jika diminta menggunakan kondisi If Else dengan dua huruf gunakan scanf("%s" )
		printf("Kode Asal               :");
		scanf("%s", A);
		printf("Jumlah Penjualan                  :");
		scanf("%i", &S);

		//Ketentuan Proses
      //Untuk menggunakan kondisi dengan dua huruf gunakan strcmp dan tanda dua petik " dilanjutkan dengan nilai 0 seperti contoh dibawah
      //Gunakan string jika ingin menggunakan syntax strcmp
	 	if ((strcmp(A,"AS")==0)||(strcmp(A,"as")==0))
       { strcpy(YA, "USA");
         strcpy(SH, "General Motor");
			AF=60000;
		 }
		 else if ((strcmp(A,"JP")==0)||(strcmp(A,"jp")==0))
       { strcpy(YA, "Jepang");
         strcpy(SH, "Honda Motor");
			AF=12000;
		 }
		 else if ((strcmp(A,"JR")==0)||(strcmp(A,"jr")==0))
       { strcpy(YA, "Jerman");
         strcpy(SH, "Volkswagen AG");
			AF=10000;
		 }
		 else if ((strcmp(A,"FR")==0)||(strcmp(A,"fr")==0))
       { strcpy(YA, "Francis");
         strcpy(SH, "Pigout-Citroen");
			AF=20000;
		 }

		 IR=S*AF;

		 //Komisi Distributor
		 if (YA=="Jepang")
		 {
		 	AA=0.25*IR;
		 }
		 else
		 {
		 	AA=0.38*IR;
		 }

		MD=IR-AA;

		printf("Negara Asal                    :%s\n", YA);
		printf("Nama Pabrik                    :%s\n", SH);
		printf("Laba Per Unit                  :%8.0f\n", AF);
		printf("Total Laba                     :%8.0f\n", IR);
      printf("Komisi Distributor             :%8.0f\n", AA);
      printf("Laba Bersih                    :%8.0f\n", MD);
      printf ("\n");
      printf("Masih Ada Transaksi            :");fflush(stdin);scanf("%c",&td);
      //Note Untuk memasukkan input satu huruf gunakan fflush(stdin); dengan scanf("%c", &nama_variabel)
		getch();

		 }}
