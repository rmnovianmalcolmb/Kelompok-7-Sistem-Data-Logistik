#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define s 1000

FILE *data;
char a,menu;
char namaBarang[s][s],CjumlahBarang[s][s],CkodeBarang[s][s];
int kodeBarang[s][s],jumlahBarang[s][s];
int i=0,j=0,flag;

void menuAwal(){
    system("cls");
    printf("---- Sistem Data Logistik ITTS ----\n");
    printf("-------------- Menu ---------------\n");
    printf(" 1. Daftar Barang\n");
    printf(" 2. Tambah Barang\n");
    printf(" 3. Hapus Barang\n");
    printf(" 4. Peminjaman\n");
    printf(" 5. Pengembalian\n");
    printf(" 6. Laporan\n");
    printf(" 7. Keluar Sistem\n");
    printf("------------------------------------\n");
    printf(" Masukkan pilihan anda [1 s.d. 6] = ");
}

void writeBarang(int kodeBarang[s][s],char namaBarang[s][s],int jumlahBarang[s][s])
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
        fprintf(data,"%s",namaBarang[i]);
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
}

void tambahBarang(int kodeBarang[s][s],char namaBarang[s][s],int jumlahBarang[s][s])
{
    menu1:
		printf("\n---------- Tambah Barang -----------\n");
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
            goto menu1;
        }
}

void hapusBarang(int kodeBarang[s][s],char namaBarang[s][s],int jumlahBarang[s][s])
{
    menu2:
        printf(" Kode barang yang akan dihapus\t: ");
        scanf(" %i",&i);
        namaBarang[i][0] = '\0';
        kodeBarang[i][0] = '\0';
        jumlahBarang[i][0] = '\0';
        printf(" Barang berhasil dihapus dari daftar barang\n Apakah Anda ingin menghapus data lagi? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu2;
        }
}

void daftarBarang(int kodeBarang[s][s],char namaBarang[s][s],int jumlahBarang[s][s])
{
    printf("\n");
        printf("\t\t\tDaftar Barang\n");
        printf("------------------------------------------------------------------\n");
        printf(" Kode Barang\tNama Barang\tJumlah Barang\n");
        printf("------------------------------------------------------------------\n");
        for(i=0;i<s;i++){
            if(kodeBarang[i][0] == '\0' ){
                continue;
        }
        printf(" %i\t\t%s\t\t%i\n",kodeBarang[i][0],namaBarang[i],jumlahBarang[i][0]);
    }
        printf("\nKetik apa saja untuk kembali ke menu awal : ");
        getch();
        printf("\n");
}

void waktu(){
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime (buffer, 80,"%A, %d %B %Y (%X)",info);
    printf("%s",buffer);
}

int main(){
    start:
    readBarang();
    for(int i=0;i<s;i++){
        sscanf(CkodeBarang[i],"%i",&kodeBarang[i]);
        sscanf(CjumlahBarang[i],"%i",&jumlahBarang[i]);
    }
    menuAwal();
    scanf(" %c",&menu);
    system("cls");
    switch(menu){
    case '1':
        daftarBarang(kodeBarang,namaBarang,jumlahBarang);
        break;
    case '2':
        tambahBarang(kodeBarang,namaBarang,jumlahBarang);
        writeBarang(kodeBarang,namaBarang,jumlahBarang);
        break;
    case '3':
        hapusBarang(kodeBarang,namaBarang,jumlahBarang);
        writeBarang(kodeBarang,namaBarang,jumlahBarang);
        break;
    case '7':
        return 0;
    default :
        break;
    }
    printf("\n");
    goto start;
}
