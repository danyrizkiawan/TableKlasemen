#include<stdio.h>
#include<stdlib.h>

void inscore();
void updateklasmen();

int skor[100][100];
int klasmen [100][10];

int main(){
	int i;
	int maks=0;
	char klub [100][20];
	int skor[100][100];
	int s[100];
	
	printf("Masukan jumlah klub : ");
	scanf("%d",&maks);
	
	for(i=0;i<maks;i++)
	{
		printf("Tim ke %d : ",(i+1));
		scanf("%s",&klub[i]);
	}
	
	inscore(klub, klasmen, maks);
	klasemen(klub, klasmen, maks);
	
}

void inscore(char klub[100][20], int maks){
	int i;
	int j;
	int total=1;
	system("cls");
	
	for(i=0;i<maks;i++)
	{
		for(j=i+1;j<maks;j++)
		{
			printf("Pertandingan ke %d\t\tSKOR",total);
			printf("\nHOME\t%s\t\t\t",klub[i]);
			scanf("%d",&skor[j][i]);
			printf(" VS ");
			printf("\nAWAY\t%s\t\t\t",klub[j]);
			scanf("%d",&skor[i][j]);
			total++;
			updateklasmen (skor, i, j);
		}
	}
}

void updateklasmen(int skor[100][100], int home, int away){
	klasmen[home][0]++;	
	klasmen[home][4]+=skor[away][home];
	klasmen[home][5]+=skor[home][away];
	klasmen[home][6]=klasmen[home][4]-klasmen[home][5];
	klasmen[away][0]++;	
	klasmen[away][4]+=skor[home][away];
	klasmen[away][5]+=skor[away][home];
	klasmen[away][6]=klasmen[away][4]-klasmen[away][5];
	
	if (skor[away][home] > skor[home][away]) {
		klasmen[home][1]++;
		klasmen[home][7]+=3;
		klasmen[away][3]++;
		
	}
	else if (skor[away][home] < skor[home][away]) {
		klasmen[away][1]++;
		klasmen[away][7]+=3;
		klasmen[home][3]++;
	}
	else if (skor[away][home] == skor[home][away]) {
		klasmen[away][2]++;
	}
	
}

void klasemen(char klub[100][20], int klasmen[100][10], int maks) {
	
	int i,x;
	int hasil;
	system("cls");
	printf("Klasmen Sepak Bola");
	printf("\nNama Team\tMain\tM\tS\tK\tGM\tGK\tSG\tPoin");
		for(i=0;i<maks;i++){	
		printf("\n%s\t\t",klub[i]);
		
		hasil=0;
		for(x=(maks-1);x>0;x--){
			hasil=hasil+x;
			}
			printf("%d",hasil);
		}
}
