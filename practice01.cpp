#include<stdio.h>
#include<stdlib.h>
int main(){
	float number[100];
	int currentIndex=0,sum=0;
	float max=number[0];
	float min=number[0];
	int uoc=0,n,count=0,updateIndex;
	int x=1;
	float newNumber[100+x],updateNumber;
	do{
		printf("MENU\n");
		printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
		printf("2.In ra gia tri cac phan tu dang quan ly\n");
		printf("3.In ra cac phan tu co gia tri chan va tinh tong\n");
		printf("4.In ra gia tri lon nhat va nho nhat trong mang\n");
		printf("5.In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
		printf("6.Nhap vao 1 so va thong ke trong mang co bao nhieu phan tu co gia tri nhu vay\n");
		printf("7.Them 1 phan tu vao vi tri chi dinh\n");
		printf("8.Sap xep mang vua nhap thu tu tang dan\n");
		printf("9.Thoat\n");
		int choice;
		printf("Lua chon cua ban la: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap vao so phan tu muon nhap: ");
				int n;
				scanf("%d",&n);
				currentIndex+=n;
				for(int i=currentIndex-n;i<currentIndex;i++){
					printf("Gia tri phan tu muon nhap: ");
					scanf("%f",&number[i]);
					printf("number[%d]=%.0f\n",i,number[i]);
				}
				break;
			case 2:
				for(int i=0;i<currentIndex;i++){
					printf("number[%d]=%f\n",i,number[i]);
				}
				break;
			case 3: 
				for(int i=0;i<currentIndex;i++){
					if((int)number[i]%2==0){
						printf("So chan trong mang la: %.0f\n",number[i]);
						sum+=number[i];
					}
				}
				printf("Tong cac so chan trong mang la: %d\n",sum);
				break;
			case 4:
				for(int i=0;i<currentIndex;i++){
					max=(max>number[i])?max:number[i];
					min=(min<number[i])?min:number[i];
				}
				printf("Gia tri lon nhat la: %f\n",max);
				printf("Gia tri nho nhat la: %f\n",min);
				break;
			case 5:
				for(int i=0;i<currentIndex;i++){
					uoc=0;
					for(int n=1;n<=number[i];n++){
						if((int)number[i]%n==0){
							uoc++;
						}
					}
					if(uoc==2){
						printf("number[%d] la so nguyen to\n",i);
					}
				}
				break;
			case 6:
				printf("Nhap vao 1 so: ");
				scanf("%d",&n);
				for(int i=0;i<currentIndex;i++){
					if((int)number[i]==n){
						count++;
					}
				}
				printf("Co %d so giong voi so vua nhap trong mang\n",count);
				break;
			case 7: 
					printf("Nhap so can them: ");
					scanf("%f",&updateNumber);
					printf("Nhap vi tri can them: ");
					scanf("%d",&updateIndex);
					for(int i=0;i<n+1;i++){
						if(i<updateIndex){
							newNumber[i]=number[i];
						}else if(i==updateIndex){
							newNumber[i]=updateNumber;
						}else if(i>updateIndex){
							newNumber[i]=number[i-1];
						}
					}
					for(int i=0;i<=n;i++){
						printf("Number[%d]=%.1f\n",i,newNumber[i]);
					}
			case 8: 
				printf("Xep theo thu tu tang dan: ");
				for(int i=0;i<currentIndex-1;i++){
					for(int j=i+1;j<currentIndex;j++){
						if(number[i]>number[j]){
							int temp=number[i];
							number[i]=number[j];
							number[j]=temp;
					}
					}
				}
				for(int i=0;i<currentIndex;i++){
					printf("number[%d] = %.1f\n",i,number[i]);
				}
				break;
			case 9:
				exit(0);
	}
}while("Nhap so");
}
