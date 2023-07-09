#include <stdio.h>
#define MAX 50
void swap(int *y,int *z){  //iki de�i�kenin de�erlerini de�i�tiren fonksiyon
	int a;
	a=*z;
	*z=*y;
	*y=a;
}
void dalMax(int dizi[MAX],int n,int pozisyon,int zaman[MAX],int x){  //verilen pozisyondaki 3 elemanli kismi en ustte en buyuk olacak �ekilde ayarlayan fonksiyon,, heapify
	int enbuyuk=pozisyon,sol=2*pozisyon+1,sag=2*pozisyon+2;
	zaman[x]=zaman[x]+1; //heapify ka� kere d�nd���n� hesaplayarak zaman karma��kl��� tablosu olu�turmada kullan�l�r
	if(sag<n && dizi[sag]>dizi[enbuyuk]){ //bo�lukla kontrol yap�lmamas� i�in �nce sag<n kontrol� yap�l�r.
		enbuyuk=sag;
	} 
	if(sol<n && dizi[sol]>dizi[enbuyuk]){
		enbuyuk=sol;
	}
	if(enbuyuk!=pozisyon){          
		swap(&dizi[enbuyuk],&dizi[pozisyon]);
		dalMax(dizi,n,enbuyuk,zaman,x); //rek�rsif bir fonksiyon. b�y�k olan� yukar� ta��d���m�zda sol veya sa� alt�ndaki de�i�tirdi�imiz en b�y�k olmayabilir. Onlar� da ayarlar.
	}
}
void HeapSort(int dizi[MAX],int n,int tip,int x,int zaman[MAX]){
	int i,sayac=0;
	 for (i = (n/2) - 1; i >= 0; i--){//Diziyi Max heap haline getirir. Her ��l� de k�k en b�y�k olacak.
      dalMax(dizi, n, i,zaman,x);}
      for(i=n-1;i>=0;i--){
      	swap(&dizi[i],&dizi[0]);
      	dalMax(dizi,i,0,zaman,x);
	  }
	  if(tip==2){
	  	for(i=0;i<n/2;i++){
	  		swap(&dizi[i],&dizi[n-1-i]);
		  }
	  }
}
int main(){
	int n,tip,dizi[MAX],i,control=1,x=0,zaman[MAX]={0},j;
	printf("                              Heap Sort Algoritmasi        Yavuz Cetin 21011004\n");
    while(control==1){
	printf("\nDizinizin boyutunu giriniz:");
	scanf("%d",&n);
	printf("Dizinizin elemanlarini giriniz.\n");
	for(i=0;i<n;i++){
		printf("%d. eleman:",i+1);
		scanf("%d",&dizi[i]);
	}
	printf("Girdiginiz dizi asagidaki gibidir:\n");
	for(i=0;i<n;i++){
		printf("%d ",dizi[i]);
	}
	printf("\n");
	tip=0;
	while(tip!=1 && tip!=2){
	printf("Kucukten buyuge sirala:1      Buyukten kucuge sirala:2\nGirdi:");
	scanf("%d",&tip);}
	HeapSort(dizi,n,tip,x,zaman);
	printf("Dizinizin siralanmis hali asagidaki gibidir:\n");
	for(i=0;i<n;i++){
		printf("%d ",dizi[i]);
	}
	printf("\nYeni bir dizi girip siralamak icin 1 Zaman karmasikligi tablosu icin 2 giriniz:");
	scanf("%d",&control);
	x=++x;
}
    printf("Zaman karmasigligi grafigi asagidaki gibidir(Girdiginiz sirayla yukaridan asagiya):\n\n");
    i=0;
    while(zaman[i]!=0){
    	printf("%d. dizinin aldigi zaman: ",i+1);
    	for(j=0;j<zaman[i];j++){
    		printf("*");
		}
		printf("\n");
    	i=++i;
	}
	return 1;
}
