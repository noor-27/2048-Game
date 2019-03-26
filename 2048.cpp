#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int chekB(int **A){
	int flag=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(A[i][j]==0)
			flag=1;
			break;
		}
		if(flag==1)
		break;
	}
	return flag;
}
int chek(int **A,int n){
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if((A[i][j]==A[i][j+1])||(A[i][j]==0||A[i][j+1]==0)){
			 flag=1;
			break;}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			 if((A[i][j]==A[i+1][j])||(A[i+1][j]==0)){
			 flag=1;
			break;}
		}
	}
	//cout<<flag;
	return flag;
}
//function to insert random number
void insran(int **A){
	there:
	int y=rand()%15;
//	cout<<y;
	int f=chekB(A);
	if(f==0)
	return;
	switch(y){
		case 0:
			if(A[0][0]==0)
			A[0][0]=2;
			else 
			goto there;
			break;
			case 1:
			if(A[0][1]==0)
			A[0][1]=2;
			else 
			goto there;
			break;
			case 2:
			if(A[0][2]==0)
			A[0][2]=2;
			else 
			goto there;
			break;
			case 3:
			if(A[0][3]==0)
			A[0][3]=2;
			else 
			goto there;
			break;
			case 4:
			if(A[1][0]==0)
			A[1][0]=2;
			else 
			goto there;
			break;
			case 5:
			if(A[1][1]==0)
			A[1][1]=2;
			else 
			goto there;
			break;
			case 6:
			if(A[1][2]==0)
			A[1][2]=2;
			else 
			goto there;
			break;
			case 7:
			if(A[1][3]==0)
			A[1][3]=2;
			else 
			goto there;
			break;
			case 8:
			if(A[2][0]==0)
			A[2][0]=2;
			else 
			goto there;
			break;
			case 9:
			if(A[2][1]==0)
			A[2][1]=2;
			else 
			goto there;
			break;
			case 10:
			if(A[2][2]==0)
			A[2][2]=2;
			else 
			goto there;
			break;
			case 11:
			if(A[2][3]==0)
			A[2][3]=2;
			else 
			goto there;
			break;
			case 12:
			if(A[3][0]==0)
			A[3][0]=2;
			else 
			goto there;
			break;
			case 13:
			if(A[3][1]==0)
			A[3][1]=2;
			else 
			goto there;
			break;
			case 14:
			if(A[3][2]==0)
			A[3][2]=2;
			else 
			goto there;
			break;
			case 15:
			if(A[3][3]==0)
			A[3][3]=2;
			else 
			goto there;
			break;
	}
}
void print(int **A,int n){
		int u,v;
	for(u=0;u<n;u++){
		for(v=0;v<n;v++){
			cout<<A[u][v]<<"	";
		}
		cout<<"\n";
	}
	cout<<endl;
	
}
void backR(int **A,int m,int n){
	for(int s=n;s>0;s--){
		if(A[m][s-1]!=0){
			A[m][s]=A[m][s-1];
			A[m][s-1]=0;
		}
	}
}
void backU(int **A,int m,int n){
	for(int s=m;s<3;s++){
		if(A[s+1][n]!=0){
			A[s][n]=A[s+1][n];
			A[s+1][n]=0;
		}
	}
}
void backD(int **A,int m,int n){
	for(int s=m;s>0;s--){
		if(A[s-1][n]!=0){
			A[s][n]=A[s-1][n];
			A[s-1][n]=0;
		}
	}
}
void backL(int **A,int m,int n){
	for(int s=n;s<3;s++){
		if(A[m][s+1]!=0){
			A[m][s]=A[m][s+1];
			A[m][s+1]=0;
		}
	}
}
void fnR(int **A,int n){	//function to swipe right
	for(int i=0;i<n;i++){
		int z=0;
		for(int j=0;j<n;j++){
			if(A[i][j+1]==0){
				A[i][j+1]=A[i][j];
				A[i][j]=0;
				backR(A,i,j);
			}
			else if(A[i][j]==A[i][j+1]&&z==0){
				A[i][j+1]=A[i][j]+A[i][j+1];
				A[i][j]=0;
				backR(A,i,j);
				 z=1;
			}
		}
	}
	insran(A);
	print(A,n);
	int flag=chek(A,n);
	cout<<flag;
	if(flag==0){
	cout<<"Game Over";
	return;}
}
void fnL(int **A,int n){     //function to swipe left
	for(int i=0;i<n;i++){
		int z=0;
		for(int j=n-1;j>0;j--){
			if(A[i][j-1]==0){
				A[i][j-1]=A[i][j];
				A[i][j]=0;
				backL(A,i,j);
			}
			else if(A[i][j]==A[i][j-1]&&z==0){
				A[i][j-1]=A[i][j]+A[i][j-1];
				A[i][j]=0;
				backL(A,i,j);
				z=1;
			}
		}
	}
	insran(A);
	print(A,n);
	int flag=chek(A,n);
	cout<<flag;
	if(flag==0){
	cout<<"Game Over";
	return;}
}
void fnU(int **A,int n){	//function to swipe Upper

	for(int j=0;j<n;j++){
			int z=0;
		for(int i=n-1;i>0;i--){
			if(A[i-1][j]==0){
				A[i-1][j]=A[i][j];
				A[i][j]=0;
				backU(A,i,j);
			}
			else if(A[i][j]==A[i-1][j]&&z==0){
				A[i-1][j]=A[i-1][j]+A[i][j];
				A[i][j]=0;
				backU(A,i,j);
				z=1;
			}
		}
	}
	insran(A);
	print(A,n);
	int flag=chek(A,n);
   	cout<<flag;
	if(flag==0){
	cout<<"Game Over";
	return;}
}
void fnD(int **A,int n){		//function to swipe Down
	int z=0;
	for(int j=0;j<n;j++){
		for(int i=0;i<n-1;i++){
			if(A[i+1][j]==0){
				A[i+1][j]=A[i][j];
				A[i][j]=0;
				backD(A,i,j);
			}
			else if(A[i][j]==A[i+1][j]&&z==0){
				A[i+1][j]=A[i+1][j]+A[i][j];
				A[i][j]=0;
				backD(A,i,j);
				z=1;
			}
		}
	}
	insran(A);
	print(A,n);
	int flag=chek(A,n);
	cout<<flag;
	if(flag==0){
	cout<<"Game Over";
	return;
	}
}
void fn(int **A,int n){
	int p;
	char c;
	cout<<"enter Move:\nW for UP\nA for LEFT\nS for RIGHT\nZ for DOWN\n";
	do{
	cout<<"enter MOVE\n";
	c=getch();
	switch(c){
		case 's':
			fnR(A,n);
			break;
			case 'a':
				fnL(A,n);
				break;
				case 'w':
					fnU(A,n);
					break;
					case 'z':
						fnD(A,n);
						break;
	}
}while(c!='\0');
}
int main(){
	int **A,n=4,i,j;
//	cout<<"Enter the size";
//	cin>>n;
	A=(int**)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		A[i]=(int*)malloc(sizeof(int)*n);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=0;
		}
	}
	insran(A);
	insran(A);	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<A[i][j]<<"	";
		}
		cout<<"\n";
	}
	fn(A,n);
}
