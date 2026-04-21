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
    int length = strlen(string);
    for(int i=0; i<length; i++){
        if(string[i] == '('){
            if(i+2<length && string[i+1]>='a' && string[i+1]<='z' && string[i+2]==')'){//cek kasus
                i+=2; //melewati kurung yang valid
            }
            else{
                for(int j=i; string[j]!='\0'; j++){
                    string[j]=string[j+1];//shift kiri
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
