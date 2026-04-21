/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 02 - Data Manipulation dan External Files
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : Muhammad Azka Rahadian (13224036)
 *   Nama File           : soal1.c
 *   Deskripsi           : Mencetak warna lampu berdasarkan aturan prioritas tertentu
 * String hanya berisi huruf kecil, (, ), dan spasi tanpa spasi di awal/akhir.
 * string valid jika semua tanda kurung berpasangan dengan urutan benar
 * hanya karakter ( dan ) yang boleh dihapus
 * Jika ada banyak kemungkinan, keluarkan salah satu hasil valid dengan panjang maksimum
 * input -> a)b(c)d)
 * output -> ab(c)d
 */
#include <string.h>
#include <stdio.h>
int main (){
    char string[10];
    gets(string);
    /*input -> a)b(c)d); output -> ab(c)d*/
    /*input -> x(y(z)); output -> x(y(z))*/
    /*input -> (ab)c; output -> (ab)c*/
    int length = strlen(string);
    for(int i=0; i<length; i++){
        if(string[i] == '('){
            int j=1+1;
            int valid=0;
            while(j<length && string[j]!=')'){
                if(string[j]>='a' && string[j]<='z'){
                    valid = 1; //ada huruf didalam kurung
                }
                j++;
            }
            if(j<length && string[j]==')' && valid){ //cek kasus
                i=j; //melewati kurung yang valid
            }
            else{
                for(int k=i; string[k]!='\0'; k++){
                    string[k]=string[k+1];//shift kiri
                }
                i--;//indeks sblmnya
            }
        }
        else if(string[i]==')'){
            for(int j=i; string[j]!='\0';j++){
                string[j]= string[j+1];//shift left
            }
            i--;//indeks sblmnya
        }
    }
    printf("%s", string);
    return 0;
}

