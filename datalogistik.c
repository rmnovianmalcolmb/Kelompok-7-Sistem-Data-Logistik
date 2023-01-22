#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define s 1000

FILE *data;
time_t rawtime;
struct tm *info;
char a,menu;
char namaBarang[s][s],CjumlahBarang[s][s],CkodeBarang[s][s];
char namaPinjam[s][s],lamaPinjam[s][s],waktuPinjam[s][s],barangPinjam[s][s];
int kodeBarang[s][s],jumlahBarang[s][s],jumlahPinjam[s][s],kodePinjam[s][s];
int i=0,j=0,flag;

void menuAwal(){
    system("cls");
    printf("---- Sistem Data Logistik ITTS ----\n");
    printf("-------------- Menu ---------------\n");
    printf(" 1. Daftar Barang\n");
    printf(" 2. Tambah Barang\n");
    printf(" 3. Perbarui Jumlah Barang\n");
    printf(" 4. Hapus Barang\n");
    printf(" 5. Peminjaman\n");
    printf(" 6. Pengembalian\n");
    printf(" 7. Laporan Peminjaman\n");
    printf(" 8. Keluar Sistem\n");
    printf("------------------------------------\n");
    printf(" Masukkan pilihan anda [1 s.d. 6] = ");
}

void writeBarang()
{
    data = fopen("kodeBarang.txt","w");
    for(int i=0;i<s;i++){
        if (kodeBarang[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%i\n",kodeBarang[i][0]);
    }
    fclose(data);
    data = fopen("namaBarang.txt","w");
    for(int i=0;i<s;i++){
        if (namaBarang[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",namaBarang[i]);
    }
    fclose(data);
    data = fopen("jumlahBarang.txt","w");
    for(int i=0;i<s;i++){
        if (kodeBarang[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%i\n",jumlahBarang[i][0]);
    }
    fclose(data);
}

void readBarang()
{
    i = 0;
    data = fopen("kodeBarang.txt", "r");
    while(fgets(CkodeBarang[i], 100, data))
	{
        CkodeBarang[i][99] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("namaBarang.txt", "r");
    while(fgets(namaBarang[i], 100, data))
	{
        namaBarang[i][strlen(namaBarang[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("jumlahBarang.txt", "r");
    while(fgets(CjumlahBarang[i], 100, data))
	{
        CjumlahBarang[i][99] = '\0';
        i++;
    }
    fclose(data);
    for(int i=0;i<s;i++){
        sscanf(CkodeBarang[i],"%i",&kodeBarang[i]);
        sscanf(CjumlahBarang[i],"%i",&jumlahBarang[i]);
    }
}

void tambahBarang()
{
    menu2:
		printf("---------- Tambah Barang -----------\n");
        do{
            flag=1;
            printf(" Kode Barang\t: ");
            scanf(" %i",&i);
            if(kodeBarang[i][0] != '\0'){
                printf(" Kode ini sudah terpakai, masukkan kode lain\n\n");
                flag=0;
            }
            kodeBarang[i][0] = i;
        }while(flag==0);
        getchar();
        printf(" Nama Barang\t: ");
        scanf("%[^\n]s",&namaBarang[i]);
        printf(" Jumlah Barang\t: ");
        scanf("%i",&jumlahBarang[i][0]);
        printf(" Apakah Anda ingin menambahkan data lagi ? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu2;
        }
}

void updateBarang()
{
    printf(" Masukkan Kode Barang : ");
    scanf(" %i",&i);
    printf(" Kode Barang : %i\n",kodeBarang[i][0]);
    printf(" Nama Barang : %s\n",namaBarang[i]);
    printf(" Jumlah Barang Saat Ini : %i\n\n",jumlahBarang[i][0]);
    printf(" Jumlah Barang Baru : ");
    scanf(" %i",&jumlahBarang[i][0]);
}

void hapusBarang()
{
    menu4:
        printf(" Kode barang yang akan dihapus\t: ");
        scanf(" %i",&i);
        namaBarang[i][0] = '\0';
        kodeBarang[i][0] = '\0';
        jumlahBarang[i][0] = '\0';
        printf(" Barang berhasil dihapus dari daftar barang\n Apakah Anda ingin menghapus data lagi? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu4;
        }
}

void daftarBarang()
{
    printf("\n");
        printf("\t\t\tDaftar Barang\n");
        printf("------------------------------------------------------------------\n");
        printf(" Kode Barang\tNama Barang\t\tJumlah Barang\n");
        printf("------------------------------------------------------------------\n");
        for(i=0;i<s;i++){
            if(kodeBarang[i][0] == '\0' ){
                continue;
        }
        printf(" %i\t\t%s\t\t\t%i\n",kodeBarang[i][0],namaBarang[i],jumlahBarang[i][0]);
    }
        printf("\nKetik apa saja untuk kembali ke menu awal : ");
        getch();
        printf("\n");
}

void pinjamBarang()
{
    menu5:
    i = 1,j = 0;
    printf("\n---------- Peminjaman Barang -----------\n");
    for(i=1;i<s;i++){
        if (kodePinjam[i][0] == '\0')
            {break;}
        else continue;
    }
    kodePinjam[i][0] = i;
    printf(" Kode Pinjaman\t\t: %i\n",kodePinjam[i][0]);
    printf(" Nama Peminjam\t\t: ");
    scanf(" %[^\n]s",&namaPinjam[i]);
    do{
        flag=1;
        printf(" Kode barang\t\t: ");
        scanf(" %i",&j);
        if(kodeBarang[j][0] == '\0'){
            printf(" Kode salah, masukkan kode lain\n\n");
            flag=0;
        }
    }while(flag==0);
    getchar();
    printf(" Barang yang dipinjam\t: %s\n",namaBarang[j]);
    for(int z=0;z<s;z++){
        barangPinjam[i][z] = namaBarang[j][z];
    }
    menu52:
    printf(" Jumlah barang saat ini\t: %i\n",jumlahBarang[i][0]);
    printf(" Jumlah barang yang akan dipinjam : ");
    scanf(" %i",&jumlahPinjam[i][0]);
    if(jumlahPinjam[i][0] > jumlahBarang[i][0]){
        printf("\n Barang tidak mencukupi\n\n");
        goto menu52;
    }
    printf(" Lama pinjam : ");
    scanf(" %[^\n]s",lamaPinjam[i]);
    time(&rawtime);
    info = localtime(&rawtime);
    strftime (waktuPinjam[i], s,"%A, %d %B %Y (%X)",info);
    printf("\n--------------- Data Peminjaman Barang ---------------\n");
    printf(" Kode Pinjaman\t: %i\n",kodePinjam[i][0]);
    printf(" Nama Peminjam\t: %s\n",namaPinjam[i]);
    printf(" Kode Barang\t: %i\n",kodeBarang[i][0]);
    printf(" Nama Barang\t: %s\n",barangPinjam[i]);
    printf(" Jumlah barang\t: %i\n",jumlahPinjam[i][0]);
    printf(" Waktu Pinjam\t: %s\n",waktuPinjam[i]);
    printf(" Lama Pinjam\t: %s\n",lamaPinjam[i]);
    printf(" Ketik apa saja untuk kembali ke menu awal : ");
    getch();
    printf("\n");
}

void daftarPinjam()
{
    printf("\n");
    printf("\t\t\tDaftar Barang\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf(" Kode Pinjam\tNama Peminjam\tBarang\t\tJumlah yang dipinjam\tLama Pinjam\tStatus\n");
    printf("--------------------------------------------------------------------------------------\n");
    for(i=1;i<s;i++){
        if(kodePinjam[i][0] == '\0' ){
            continue;
    }
    printf(" %i\t\t%s\t\t%s\t%i\t\t\t%s",kodePinjam[i][0],namaPinjam[i],barangPinjam[i],jumlahPinjam[i][0],lamaPinjam[i]);
    }
    printf("\nKetik apa saja untuk kembali ke menu awal : ");
    getch();
    printf("\n");
}

int main(){
    start:
    readBarang();
    menuAwal();
    scanf(" %c",&menu);
    system("cls");
    switch(menu){
    case '1':
        daftarBarang();
        break;
    case '2':
        tambahBarang();
        writeBarang();
        break;
    case '3':
        updateBarang();
        writeBarang();
        break;
    case '4':
        hapusBarang();
        writeBarang();
        break;
    case '5':
        pinjamBarang();
        break;
    case '6':
        break;
    case '7':
        daftarPinjam();
        break;
    case '8':
        return 0;
    default :
        break;
    }
    printf("\n");
    goto start;
}
