/*
Nama	: Giyaddy Ilmi Alavan
NIM		: 1708107010018
Kelas	: IF
Matkul	: Struktur Data dan Algoritma
tahun 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char heap[1000000];
int n = 0;
int parent = 0;

void insertHeap(char alphabet);
void displayHeap();
void deleteRoot();
void heapSort();
void swap(char *a, char *b);
void mainMenu();

int main(){
char alphabet;
int choice, stop = 0;
float begin, end;

	mainMenu();

	while (stop == 0){
	printf("\nEnter an option : ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("\nInput data : ");
			scanf(" %c", &alphabet);

				begin = clock(); //begin untuk memulai penghitungan waktu
				insertHeap(alphabet);
				end = clock();  //end untuk menghentikan penghitungan waktu

			printf("Execution time : %f ms\n", (end-begin));
		break;

			case 2:
			displayHeap();
			break;

				case 3:
					begin = clock();
					deleteRoot();
					end = clock();

				printf("Execution time : %f ms\n", (end-begin));
				break;

			case 4:
				begin = clock();
				heapSort();
				end = clock();

				printf("Execution time : %f ms\n", (end-begin));	
				stop = 1;
			break;

		case 5:
			stop = 1;
		break;

		default :
			printf("Your request is not available..\n");
	}
}
	return EXIT_SUCCESS;
}

void swap(char *first, char *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void insertHeap(char alphabet){

	//jika ternyata sudah ada data yang masuk sebelumnya, maka lakukan
	//prosedur ini
	if(n>0){
		heap[n] = alphabet;
		parent = (n - 1) / 2;
		int temporal = n;

				//jika data yang baru masuk masih lebih kecil dari parent, maka
				//tukar posisi terus menerus
				while(heap[temporal] < heap[parent]){
					swap(&heap[temporal], &heap[parent]);
					temporal = parent;
					parent = (temporal - 1) / 2;
				}
				n++;	
			}
	else{
		heap[n] = alphabet;
		n++;
	}
}

void displayHeap(){
	for(int i=0 ; i<n ; i++){
		printf("heap element %d = %c\n", i, heap[i]);			
	}
}

void mainMenu(){
	printf("---HEAP IMPLEMENTATION IN ARRAY--\n\n");
	printf("List of options: \n");
	printf("1. Insert N-data Into The Heap\n");
	printf("2. Delete The Heap's Root\n");
	printf("3. Sort your Input With Heap Sort\n");
	printf("4. Exit program\n");
}

void deleteRoot(){
	char last = heap[n-1];

	//pivot adalah indeks awal, left adalah indeks arah kiri, dan right adalah indeks arah kanan
	int pivot=0, left=2*pivot+1, right=2*(pivot+1);

	heap[pivot]=last;

	//selama indeks kiri lebih kecil atau sama dengan n, looping
	//akan berulang terus
	while (left < n-1){

		//jika child sebelah kiri lebih kecil dari sebelah kanan, maka
		//elemen root sementara akan ditukar dengan child
		if (heap[left] < heap[right]){

			swap(&heap[pivot], &heap[left]);
			pivot = left;
			left=2*pivot+1;
			right=2*(pivot+1);
		}
		else{
			swap(&heap[pivot], &heap[right]);
			pivot = right;
			left=2*pivot+1;
			right=2*(pivot+1);
		}
	}
	n-=1;
}
void heapSort(){
	printf("\nSorted Heap Sequence: \n\n");
	while(1){
		printf("%c ", heap[0]);
		deleteRoot(); //setiap kali root diambil maka ia dihapus dari heap
		if(n==0){
			break;
		}
	}
	printf("\n\nHeap Is Empty....\n");
}