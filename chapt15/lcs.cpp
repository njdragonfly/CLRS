#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

char * LCS(const char *a,const char *b)  {
	char * ret=NULL;
	int len=0;
	int m=strlen(a);
	int n=strlen(b);
	int ** mat;
	mat=new int *[m+1];
	for(int i=0;i<=m;i++) {
		mat[i]=new int [n+1];
		memset(mat[i],0,sizeof(int)*(n+1));
	}

	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i-1]==b[j-1]) {
				mat[i][j]=mat[i-1][j-1]+1;
			}
			else {
				mat[i][j]=mat[i-1][j];
				if(mat[i][j-1]>mat[i][j])
					mat[i][j]=mat[i][j-1];
			}
		}
	}
	len=mat[m][n];
	ret=new char[len+1];
	ret[len--]=0;
	int i=m,j=n;
	while(len>=0) {
		while(a[i-1]!=b[j-1]||mat[i][j]!=mat[i-1][j-1]+1) {
			if(mat[i-1][j]>mat[i][j-1])
				i--;
			else
				j--;
		}
		assert(a[i-1]==b[j-1]);
		ret[len--]=a[i-1];
		i--,j--;
	}
	for(int i=0;i<=m;i++) {
		delete []mat[i];
	}
	delete [] mat;
	return ret;
}

int main() {
	char a[]="abcdefg";
	char b[]="acdebf";
	char * ret=LCS(a,b);
	cout<<strlen(ret)<<"\n"<<ret<<endl;
	delete ret;
	return 0;
}
