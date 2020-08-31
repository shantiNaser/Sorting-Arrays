#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define arrsize 25000

class Heap
{
private:
	int num;
	int size;
	int *Array;
public:
	
	Heap(int newsize) // constructer 
	{
		num=0;
		size=newsize;
		Array= new int [size];
	}
	int getNum() //geters for number
	{
		return num;
	}
	void insert(int val)
	{
		num++; // because the array began from 1
		int i=num; // 
		while(i>1 && val>Array[i/2])
		{
			Array[i]=Array[i/2];
			i=i/2;
		}
		Array[i]=val;
	}
	void shiftdown(int i,int size)
	{
		int x=num;
		num=size;
		int temp=Array[i];
		int flag=0;
		int child;
		while(2*i <= num && !flag)
		{
			child=2*i;
			if(child+1<num && Array[child] < Array[child+1])//find max child
			{
				child=child+1;
			}
			if(Array[child]> temp)
			{
				int t=Array[i];
				Array[i]=Array[child];
				Array[child]=t;
				i=child;
				
			}
			else
			{
				flag=1;
			}
		}
		num=x;
	}
	void remove()
	{
		Array[1]=Array[num];
		num--;
		shiftdown(1,num);
	}
	void sort()
	{
		int i, temp;
		for (i = num; i >= 2; i--)
		{
			temp = Array[i];
			Array[i] = Array[1];
			Array[1] = temp;
			shiftdown(1,i-1);
		}

	}
	void print() 
	{
		for(int i=1;i<=num;i++)
		{
			cout<<Array[i]<<" ";
		}
		cout<<endl;
	}
}; //end of class heap


int FindMax(int *a,int size)
{
	int max=a[1];
	for(int i=1 ; i<size ; i++)
	{
		if(a[i] > max)
			max=a[i];
	}
	return max;
}
void Counting_Sort(int *a,int n)
{
	int m=FindMax(a,n);
	int x=m;
	m++;
	int *c=new int [m];
	int *b=new int [n];

	for(int k=0 ; k<m ; k++)
		c[k]=0;

	for(int i=1 ; i<=n ; i++)
		c[a[i]]=c[a[i]]+1;


	for(int k=1 ; k<m ; k++)
		c[k]=c[k]+c[k-1];


	for(int i=n ; i>1 ; i--)
	{
		b[c[a[i]]]=a[i];
		c[a[i]]--;
	}

	b[n]=x;

	for(int i=1 ; i<=n ; i++)
		a[i]=b[i];

	
}
void Insertion_Sort(int *a,int size)
{
	int key;
	int j;
	for(int i=2;i<size;i++)
	{
		key=a[i];
		j=i-1;
		while(j>0 && a[j]> key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}


void merge(int *a,int p, int mid, int q)
 	{
 		int *B=new int[q];
 		int i,j,k;
 		i=p;   j=mid+1;   k=i;
 		while(i<=mid&&j<=q)
 		{
 			if(a[i]<=a[j])
 			{
 				B[k]=a[i];
 				i++;
 				k++;
 			}
 			else if(a[i]>a[j])
 			{
 				B[k]=a[j];
 				k++;
 				j++;
 			}
 
 		}
 		while(i<=mid)
 		{
 			B[k]=a[i];
 			i++;
 			k++;
 		}
 
 		while(j<=q)
 		{
 			B[k]=a[j];
 			k++;
 			j++;
 		}
 
 		for(k=p;k<=q;k++)
 			a[k]=B[k];
 
 }
void MergeSort(int *a,int l, int r)
	{
		if(l<r)
		{
			int mid = floor(static_cast<double>((l+r)/2));
			MergeSort(a,l,mid);
			MergeSort(a,mid+1,r);
			merge(a,l,mid,r);				
		}
	}

void Swap(int &a,int &b) //passing by refrence
{
	int t=a;
	a=b;
	b=t;
}

int Partition(int A[], int l, int r) {
int p = A[l];
int i = l+1;
int j = r;
	while (1)
	{
		while (A[i] <= p && i < r) ++i;
		while (A[j] >= p && j > l) --j;
		if (i >= j)
		{
			Swap(A[j],A[l]);
			return j;
		}
		else Swap(A[i],A[j]);
   	}
}
void Quicksort(int *A, int l, int r)
{
	if (l < r)
	{
		int h = Partition(A, l, r);
		Quicksort(A, l, h-1);
		Quicksort(A, h+1, r);
	}
}

void Selection_Sort(int *a,int size)
{
	int temp;
	int i,j;

	for(i=0 ; i<size ; i++)
	{
		for(j=i+1 ; j<size ; j++)
		{
			if(a[i]>=a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
// end of all Sorting-code

void main()
{
	int choice;
	char p;

	do
	{
		cout<<"-------------------------------------------"<<endl;
		cout<<"plesee select the sort you want"<<endl;
		cout<<"1.Counting Sort"<<endl;
	    cout<<"2.Heap Sort"<<endl;
	    cout<<"3.Insertion Sort"<<endl;
	    cout<<"4.Merge Sort"<<endl;
	    cout<<"5.Quick Sort"<<endl;
	    cout<<"6.Selection Sort"<<endl;
	    cout<<"7.Exit"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cin>>choice;
		
		if(choice==1)
		{

			int a[arrsize];
			srand(time(NULL));
			for( long i=1 ; i<arrsize ; i++)
				a[i]=rand() % 100+ 1; // to implemant the array randoumly between[0,100]

			clock_t begin = clock();

			Counting_Sort(a,arrsize-1);
			clock_t end = clock();
			

			printf("The time required to sort the array is : %f\n",((float)end-begin)/CLOCKS_PER_SEC);
			
			cout<<"if you want to print the array please enter p "<<endl;
			cin>>p;
			if(p=='p')
			{
				for(long i=1 ; i<arrsize ; i++l)
					cout<<a[i]<<"  ";
				cout<<endl;


			}
			else
				continue;

			
		}
		if(choice==2)
		{
			
			Heap a(arrsize);

			srand(time(NULL));

			for(long i=0 ; i<arrsize ; i++)
				a.insert(rand() % 100 + 1);

			clock_t begin = clock();
	
			a.sort();

		clock_t end = clock();

			printf("The time required to sort the array is : %f\n",((float)end-begin)/CLOCKS_PER_SEC);
			cout<<"if you want to print the array please enter p "<<endl;
			cin>>p;
			if(p=='p')
			{
				a.print();

			}
			else
				continue;
	
         
		}
		if(choice==3)
		{

             int *a=new int[arrsize];
			 srand(time(NULL));

			for(long i=1 ; i<=arrsize ; i++)
				a[i]=rand()%100+1;	
              clock_t begin = clock();

			Insertion_Sort(a,arrsize);
			clock_t end = clock();

			

			printf("The time required to sort the array is : %f\n",((float)end-begin)/CLOCKS_PER_SEC);
			cout<<"if you want to print the array please enter p "<<endl;
			cin>>p;
			if(p=='p')
			{
				for(long i=1 ; i<=arrsize ; i++)
					cout<<a[i]<<"  ";
				cout<<endl;


			}
			else
				continue;

		}
		if(choice==4)
		{
			int *a=new int[arrsize];
			srand(time(NULL));

			for(long i=1 ; i<=arrsize ; i++)
				a[i]=rand()%100+1;	
			clock_t begin = clock();
			MergeSort(a,1,arrsize-1);
			clock_t end = clock();

			

			printf("The time required to sort the array is : %f\n",((float)end-begin)/CLOCKS_PER_SEC);
			cout<<"if you want to print the array please enter p "<<endl;
			cin>>p;
			if(p=='p')
			{
				for(long i=1 ; i<=arrsize ; i++)
					cout<<a[i]<<"  ";
				cout<<endl;


			}
			else
				continue;

		}
		if(choice==5)
		{
			int *a= new int [arrsize];
			srand(time(NULL));


			for(long i=1 ; i<=arrsize ; i++)
				a[i]=rand()%100+1;
			clock_t begin = clock();
			Quicksort(a,0,arrsize-1);
			clock_t end = clock();

			

			printf("The time required to sort the array is : %f\n",((float)end-begin)/CLOCKS_PER_SEC);
			cout<<"if you want to print the array please enter p "<<endl;
			cin>>p;
			if(p=='p')
			{
				for(long i=1 ; i<=arrsize ; i++)
					cout<<a[i]<<"  ";
				cout<<endl;


			}
			else
				continue;

         
		}
		if(choice == 6)
		{

         int *a=new int [arrsize];
		 srand(time(NULL));

			
			for(long i=1 ; i<=arrsize ; i++)
				a[i]=rand()%100+1;
			clock_t begin = clock();
			Selection_Sort(a,arrsize);
			clock_t end = clock();

			

			printf("The time required to sort the array is : %f\n",((float)end-begin)/CLOCKS_PER_SEC);
			cout<<"if you want to print the array please enter p "<<endl;
			cin>>p;
			if(p=='p')
			{
				for(long i=1 ; i<=arrsize ; i++)
					cout<<a[i]<<"  ";
				cout<<endl;


			}
			else
				continue;

		}





	}while(choice!=7);

}