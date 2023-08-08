#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
	char T[8],A[6],S[20],YA,SH;
   char td='y';
   float AF,AA,MD,IR,DA;

if (td==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak dibuat");
getch(); }
while (td=='y' || td=='Y')
{  clrscr();

		printf(" Nandi Hati Dept. Store\n");
		printf("Proses Penggajian Karyawan \n");
		printf("========================== \n");
		printf ("\n");
		printf("Bulan        :");
		scanf("%s", T);
		printf("Nomor Induk Karyawan               :");
		scanf("%s", A);
      printf("Nama Karyawan               :");
		scanf("%s", S);
      //Jika diminta menggunakan kondisi If Else dengan satu huruf gunakan scanf("%c" &) dengan syntax fflush(stdin) disamping input
		printf("Golongan [A/B/C/D]                  :");fflush(stdin);
		scanf("%c", &YA);
      printf("Status Karyawan [M/D/J/S]                  :");fflush(stdin);
		scanf("%c", &SH);
      printf("Jumlah Jam Kerja                  :");
		scanf("%f", &AF);

		//Ketentuan Proses
      //Untuk menggunakan kondisi dengan satu huruf gunakan tanda satu petik ' seperti contoh dibawah
	 	if (YA=='A')
       {
         IR=1500000;
		 }
		 else if (YA=='B')
       {
         IR=2000000;
		 } else if (YA=='C')
       {
         IR=2500000;
		 } else if (YA=='D')
       {
         IR=3000000;
		 }


       //Menghitung Gaji Lembur
      if (AF>150)
      {
        AA=(AF-150)*25000;
      }
      else
      {
        AA=0;
      }

      //Menghitung Tunjangan Istri/Suami
      if (SH=='M')
      {
        MD=0.3*IR;
      }
      else
      {
        MD=0;
      }

      DA=IR+AA+MD;

		printf("Gaji Pokok                    :Rp. %8.0f\n", IR);
		printf("Gaji Lembur                   :Rp. %8.0f\n", AA);
		printf("Tunjangan Suami/Istri         :Rp. %8.0f\n", MD);
		printf("Total Gaji Yang Diterima      :Rp. %8.0f\n", DA);
      printf ("\n");
      printf("Masih Ada Penggajian[Y/T]     :");fflush(stdin);scanf("%c",&td);
		getch();

		 }}