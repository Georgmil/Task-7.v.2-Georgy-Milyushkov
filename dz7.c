#include <stdio.h>
#include <stdlib.h>
#define maxsize 250


int func(int[], int, int, int);
int* somefunction(int* lena1, int* lenb1, int lena, int lenb);



void task3() {
	int c, o;
	printf("In this task we are going to delete, repeated elements\n");

	printf("How many elements do you want in the array:\n");
	scanf_s("%d", &o);

	int list[maxsize];

	for (int a=0; a<o; a++) {
		printf("Please type the %d st number in array", a+1);
		scanf_s("%d", &c);
		list[a] = c;

	}


	for (int i = 0; i < o; i++) {
		for (int n =0; n < o; n++) {


			if (list[i] == list[n] && n!=i) {
				for (int k = n; k < o-1; k++) {
					list[k] = list[k+1];
					list[k+1] = 0;
				}
			}
		}
	}
// Dopolnitelnaja chast, tak kak, esli bloshe 5 elementov, i vse odinkaovie, moszhet propustit odno chislo. 
	for (int d = 1; d < o; d++) {
		if (list[d - 1] == list[d]) {
			for (int k = d; k < o - 1; k++) {
				list[k] = list[k + 1];
				list[k + 1] = 0;
			}
		}
	}


	printf("\n");
	printf("Our new array is:\n");
	for (int z = 0; z < o; z++) {

		printf("%d\n",list[z]);
	}



}
void task5() {


	int w,b,number,start,end;
	printf("In this task we are going to, find the position of a number in an array\n");

	printf("How many elements do you want in the array:\n");
	scanf_s("%d", &w);
	
	int chisla[maxsize];

	printf("Please type the 1 st number in array\n");
	scanf_s("%d", &chisla[0]);
	for (int a=1; a<w; a++) {
		printf("Please type the %d st number in array, the number must be bigger than previus\n", a+1);
		scanf_s("%d", &b);
		chisla[a] = b;
	}
	start = 0;
	end = w-1;

	printf("\n\n");
	printf("Witch number do you want to find:\n");
	scanf_s("%d", &number);

	
	printf("This number is stored as number %d in the array", func(chisla, start, end, number));

}

void task6() { 

	printf("In this task we are going to merge two arrays\n");
	int b,lena,a,lenb,y,*A,*B,*C;



	// Adding elements to first array
	printf("How many elements do you want in the first array:\n");
	scanf_s("%d", &lena);

	A = malloc(lena * sizeof(int));



	printf("please type the 1 st number in array\n");
	scanf_s("%d", &A[0]);

	for (int v = 1; v < lena; v++) {
		printf("please type the %d st number in array, the number must be bigger than previus\n", v+1);
		scanf_s("%d", &a);
		A[v] = a;
	}

	// Adding elements to second array
	printf("\n");
	printf("How many elements do you want in the second array:\n");
	scanf_s("%d", &lenb);

	B = malloc(lenb*sizeof(int));

	printf("please type the 1 st number in array\n");
	scanf_s("%d", &B[0]);

	for (int r = 1; r < lenb; r++) {
		printf("please type the %d st number in array, the number must be bigger than previus\n", r+1);
		scanf_s("%d", &b);
		B[r] = b;
	}

	// Calling function and printing
	C = somefunction(A, B, lena, lenb);
	printf("\n\n");

	printf("Our new array is:\n");
	for (int y = 0; y < lena + lenb; y++) {
		printf("%d\n", C[y]);

	}

}

 //Glavnaja chast, uprovlenie vsemi zadanijami
int main() {
	int n = 1;
	while (n) {
		printf("\n\n");
		printf("Which task do you want to slove, task 3, 5 or 6. (Type 0 to exit):\n");
		scanf_s("%d", &n);
		printf("\n");
		switch (n) {
		case 3: task3(); break;
		case 5: task5(); break;
		case 6: task6(); break;

		}
	}


	return 0;
}

// Functii kotorije ispolzovalis v 5 i 6 zadanii
// Binarnij poisk, dla 5 zadanija
int func(int chisla[],int start, int end, int number) {
	int mid;
	mid = (start + end) / 2;




	 if (number < chisla[mid]) {
		end = mid - 1;
		return func(chisla,start,end,number);
	}
	else if (number > chisla[mid]) {
		start = mid + 1;
		return func(chisla,start,end,number);
	}
	else if (number == chisla[mid]) {
		 return mid;
	}
}

// Functija kotoraja skladivaet massivi A i B v novij massiv.Otdelno ne sortiruem. 
int* somefunction(int *a, int *b,int lena,int lenb) {
	int g, h;

	g = h = 0;
	
	int* C;
	C = malloc((lena + lenb) * sizeof(int));


	for (int i = 0; i < lena + lenb; i++) {
		if (g < lena && h < lenb) {
			if (a[g] < b[h]) {
				C[i] = a[g];
				g++;
			}
			else {
				C[i] = b[h];
				h++;
			}
		}
		else if(g==lena){
			for (i; i < lena + lenb; i++) {
				C[i] = b[h];
				h++;
			}
		}
		else {
			for (i; i < lena + lenb; i++) {
				C[i] = a[g];
				g++;
			}
		}
	}
	return C;
}
