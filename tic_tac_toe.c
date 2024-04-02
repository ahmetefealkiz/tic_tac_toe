#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* ---TIC TAC TOE---
1-- oyun tahtasını oluştur
2-- 1.kullanıcıdan hamle al
3-- hamle oynanabilir mi sorgula
4-- oyun bitti mi sorgula
5-- 2.kullanıcıdan hamle al
6-- hamle oynanabilir mi sorgulaM
7-- oyun bitti mi sorgula
8-- 
*/
int tahta[7][7];

void    tahtayiOlustur ();
void    tahtayiCiz();
void    oyuncuBirHamle();
void    oyuncuIkiHamle();
int     oyunBittiMi();
int    oyunSonu(int kim_kazandi);

int main(){
    int i=0;
    tahtayiOlustur();
    while (i==0)
    {
        oyuncuBirHamle();
        if (oyunBittiMi()!=0)
        {
            oyunSonu(oyunBittiMi());
            break;
        }
        oyuncuIkiHamle();
        if (oyunBittiMi()!=0)
        {
            oyunSonu(oyunBittiMi());
        }
    }
    return 0;
}

void    tahtayiOlustur (){
    system("cls");
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
           tahta[i][j]=0;
        }
        
    }
    for (int i = 1; i < 6; i=i+2)
    {
        for (int j = 1; j < 6; j=j+2)
        {
            tahta[i][j]=3;
        }
        
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tahta[i][j]==0)
            {
                if ((j==0 || j==2 || j==4 ||j==6) && (i==1 || i==3 || i==5))
                {
                    printf(" # ");
                }
                else
                    printf("####");
            }
            if (tahta[i][j]==3)
            {
                printf(" \t");
            }
        }
        printf("\n");
    } 
}
void    tahtayiCiz(){
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (tahta[i][j]==0)
            {
                if ((j==0 || j==2 || j==4 || j==6) && (i==1 || i==3 || i==5))
                {
                    printf("#");
                }
                else
                    printf("####");
            }
            if (tahta[i][j]==1)
            {
                printf("   X   ");
            }
            if (tahta[i][j]==2)
            {
                printf("   O   ");
            }
            if (tahta[i][j]==3)
            {
                printf(" \t");
            }
        }
        printf("\n");
    } 
}
void    oyuncuBirHamle(){
    int hamle_yeri_i=5;
    int hamle_yeri_j=1;
    int hamle_degeri;
    int gecici1=0;
    int gecici2=0;
    int tekrar=0;
    while (tekrar==0)
    {
        printf("\nX Koymak istediginiz yeri klavyedeki sayilar bolumunden seciniz :\n");
        scanf("%d",&hamle_degeri);
        if (hamle_degeri > 0 && hamle_degeri < 10)
        {
            system("cls");
            gecici1=0;
            gecici2=0;
            hamle_yeri_i=5;
            hamle_yeri_j=1;
            for (int z=1 ; z < hamle_degeri; z++)
            {
                gecici1++;
                gecici2++;
                if (gecici1==3)
                {
                    hamle_yeri_i=hamle_yeri_i-2;
                    gecici1=0;
                }
                if (gecici2!=3)
                {
                    hamle_yeri_j=hamle_yeri_j+2;
                }
                else
                {
                    gecici2=0;
                    hamle_yeri_j=1;
                } 
            }
            if (tahta[hamle_yeri_i][hamle_yeri_j]==1 || tahta[hamle_yeri_i][hamle_yeri_j]==2)
            {
                printf("\nX Koymak istediginiz yer dolu.\n");
            }
            else{
                tahta[hamle_yeri_i][hamle_yeri_j]=1;
                tahtayiCiz();
                tekrar++;
            }
        }
        else
            printf("\nLutfen girilebilir bir yer seciniz.\n");
    }
    tekrar=0;
}
void    oyuncuIkiHamle(){
    int hamle_yeri_i=5;
    int hamle_yeri_j=1;
    int hamle_degeri;
    int gecici1=0;
    int gecici2=0;
    int tekrar=0;
    while (tekrar==0)
    {
        printf("\nO Koymak istediginiz yeri klavyedeki sayilar bolumunden seciniz :\n");
        scanf("%d",&hamle_degeri);
        if (hamle_degeri >0 && hamle_degeri <10)
        {
            system("cls");
            gecici1=0;
            gecici2=0;
            hamle_yeri_i=5;
            hamle_yeri_j=1;
            for (int z=1 ; z < hamle_degeri; z++)
            {
                gecici1++;
                gecici2++;
                if (gecici1==3)
                {
                    hamle_yeri_i=hamle_yeri_i-2;
                    gecici1=0;
                }
                if (gecici2!=3)
                {
                    hamle_yeri_j=hamle_yeri_j+2;
                }
                else
                {
                    gecici2=0;
                    hamle_yeri_j=1;
                } 
            }
            if (tahta[hamle_yeri_i][hamle_yeri_j]==1 || tahta[hamle_yeri_i][hamle_yeri_j]==2)
            {
                printf("\nO Koymak istediginiz yer dolu.\n");
            }
            else{
                tahta[hamle_yeri_i][hamle_yeri_j]=2;
                tahtayiCiz();
                tekrar++;
            }
        }
        else
            printf("\nLutfen girilebilir bir yer seciniz.\n");
    }
    tekrar=0;
}
int     oyunBittiMi(){
    int bitti=0;
    int bitis1=0;
    int bitis2=0;
    int bitis3=0;
    int i;
    int j;

    //          1. Oyuncu Sıra
    bitis1=0;
    bitis2=0;
    bitis3=0;
    for (int i = 1; i < 6; i = i+2)
    {
        for (int j = 1; j < 6; j = j+2)
        {
            if (i==1)
            {
                if (tahta[i][j]==1)
                {
                    bitis1++;
                }
            }
            else if (i==3)
            {
                if (tahta[i][j]==1)
                {
                    bitis2++;
                }
            }
            else if (i==5)
            {
                if (tahta[i][j]==1)
                {
                    bitis3++;
                }
            }
        }
    }
    if (bitis1==3 || bitis2==3 || bitis3==3 )
    {
        bitti=1;
    }

    //          2. Oyuncu Sıra
    bitis1=0;
    bitis2=0;
    bitis3=0;
    for (int i = 1; i < 6; i = i+2)
    {
        for (int j = 1; j < 6; j = j+2)
        {
            if (i==1)
            {
                if (tahta[i][j]==2)
                {
                    bitis1++;
                }
            }
            else if (i==3)
            {
                if (tahta[i][j]==2)
                {
                    bitis2++;
                }
            }
            else if (i==5)
            {
                if (tahta[i][j]==2)
                {
                    bitis3++;
                }
            }
        }
    }
    if (bitis1==3 || bitis2==3 || bitis3==3 )
    {
        bitti=2;
    }
    
    //         1. Oyuncu Sütun
    bitis1=0;
    bitis2=0;
    bitis3=0;
    for (int j = 1; j < 6; j = j+2)
    {
        for (int i = 1; i < 6; i = i+2)
        {
            if (j==1)
            {
                if (tahta[i][j]==1)
                {
                    bitis1++;
                }
            }
            else if (j==3)
            {
                if (tahta[i][j]==1)
                {
                    bitis2++;
                }
            }
            else if (j==5)
            {
                if (tahta[i][j]==1)
                {
                    bitis3++;
                }
            }
        }
    }
    if (bitis1==3 || bitis2==3 || bitis3==3 )
    {
        bitti=1;
    }

    //          2. Oyuncu Sütun
    bitis1=0;
    bitis2=0;
    bitis3=0;
    for (int j = 1; j < 6; j = j+2)
    {
        for (int i = 1; i < 6; i = i+2)
        {
            if (j==1)
            {
                if (tahta[i][j]==2)
                {
                    bitis1++;
                }
            }
            else if (j==3)
            {
                if (tahta[i][j]==2)
                {
                    bitis2++;
                }
            }
            else if (j==5)
            {
                if (tahta[i][j]==2)
                {
                    bitis3++;
                }
            }
        }
    }
    if (bitis1==3 || bitis2==3 || bitis3==3 )
    {
        bitti=2;
    }

    //          1. Oyuncu Sol Çapraz
    bitis1=0;
    for (int i = 1; i < 6; i = i+2)
    {
        if (tahta[i][i]==1)
        {
            bitis1++;
        }
    }
    if (bitis1==3)
    {
        bitti=1;
    }

    //          2. Oyuncu Sol Çapraz
    bitis1=0;
    for (int i = 1; i < 6; i = i+2)
    {
        if (tahta[i][i]==2)
        {
            bitis1++;
        }
    }
    if (bitis1==3)
    {
        bitti=2;
    }

    //          1. Oyuncu Sağ Çapraz
    bitis1=0;
    i=1;
    j=5;
    for (int z = 0; z < 3; z++)
    {
        if (tahta[i][j]==1)
        {
            bitis1++;
        }
        i=i+2;
        j=j-2;
    }
    if (bitis1==3)
    {
        bitti=1;
    }
    
    //          2. Oyuncu Sağ Çapraz
    bitis1=0;
    i=1;
    j=5;
    for (int z = 0; z < 3; z++)
    {
        if (tahta[i][j]==2)
        {
            bitis1++;
        }
        i=i+2;
        j=j-2;
    }
    if (bitis1==3)
    {
        bitti=2;
    }
    
    //          Beraberlik
    bitis1=0;
    for (int i = 1; i < 6; i = i+2)
    {
        for (int j = 1; j < 6; j = j+2)
        {
            if (tahta[i][j]==1 || tahta[i][j]==2)
            {
                bitis1++;
            }
        }
    }
    if (bitti==0)
    {
        if (bitis1==9)
        {
            bitti=3;
        }
    }
    
    return bitti;
}
int    oyunSonu(int kim_kazandi){
    int cikis = 0;
    int deger = 0;
    if (kim_kazandi==1)
    {
        printf("\n\t*****\t1. Oyuncu Kazandi!\t*****\n");
    }
    if (kim_kazandi==2)
    {
        printf("\n\t*****\t2. Oyuncu Kazandi!\t*****\n");
    }
    if (kim_kazandi==3)
    {
        printf("\n\t*****\tBerabere!\t*****\n");
    }
    
    
    
}
