#include <iostream>
#include<climits>
#include <stdlib.h>
using namespace std;


struct Array{
    int A[20];
    int size;
    int length;
};
 

void Display(struct Array arr){
    int i;
    printf("The elements are: \n");
    for(i=0;i<arr.length;i++)
    printf("%d\n",arr.A[i]);
} 

void Append(struct Array *arr,int x){
    if(arr->size > arr->length)
    arr->A[arr->length++]=x;
    else{
        printf("The array is full");
    }
}

void Insert(struct Array *arr,int index,int x){
    int i;
    if(index>=0 && index<=arr->length){
        if(arr->size > arr->length){
            for(i=arr->length;i>index;i--)
             {arr->A[i]=arr->A[i-1];}
             arr->A[index]=x;
             arr->length++;
    
        }    
    }
 }

int Delete(struct Array *arr,int index){
    int x=0;
    if(index>=0 && index<arr->length)
        {
            x=arr->A[index];
            for(int i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
            arr->length--;
            return x;
            
        }
        return -1;
    
}

void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++)
    if(key==arr->A[i]){
        swap(&arr->A[i],&arr->A[0]);
        return 1;
    }
    return -1;
}

int BinarySearch(struct Array arr,int key){
    int l=0;
    int h=arr.length-1;
    while(l<=h){
        int mid=(l+h)/2;
        
        if(key==mid)
        return mid;
        
        else if(key<arr.A[mid])
        h=mid - 1;
        
        else l=mid + 1;
        
    }
    return -1;
}

int RBinarySearch(int a[],int l,int h,int key){
    int mid;
    if(l<=h){
        
        mid=(l+h)/2;
        
        if(key==a[mid])
        return mid;
        
        else if(key<a[mid])
        return RBinarySearch(a,l,mid-1,key);
        
        else  return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
}



int get(struct Array arr,int index){
    if(index>=0 && index<arr.length)
    return arr.A[index];
    return -1;
}



void set(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length)
    arr->A[index]=x;
}



int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
     if(arr.A[i]>max)
    max=arr.A[i];
    }
    return max;
}



int Min(struct Array arr){
    int min=INT_MAX;
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min;
    
}

int Sum(struct Array arr){
    int s=0;
    for(int i=0;i<arr.length;i++){
        s+=arr.A[i];
    }
    return s;
}


void Reverse(struct Array *arr){
    int *B;
    int i,j;
    
    B = (int *) malloc (arr->length*sizeof(int));
    
    for(i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]=arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->A[i]=B[i];
    }
}


void Reverse2(struct Array *arr){
    for(int i=arr->length,j=0;i>j;i--,j++){
        swap(&arr->A[j],&arr->A[i]);
    }
}

void InserSort(struct Array *arr,int x){
    int i=arr->length-1;
    if(arr->length==arr->size)
    return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
    
}


int IsSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}


void Rearrange(struct Array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}



int main()
{
    struct Array arr = { {10,20,30,-50,-70} , 20 , 5 };
    
   
//   printf("The size of the array is: ");
//   scanf("%d",&arr.size);
//   arr.A = (int *) malloc (arr.size * sizeof(int));
//   arr.length=0;
   
//   int i,n;
//   printf("Enter the length of the array: ");
//   scanf("%d",&n);
//   printf("Enter the elements of the arrays: ");
//   for(int i=0;i<n;i++)
//   scanf("%d",&arr.A[i]);
//   arr.length=n
   
  
 
   
    //Append(&arr,10);
//    Insert(&arr,0,69);
//   printf("%d\n",Delete(&arr,1));
   
//   printf("%d\n",LinearSearch(&arr,8));
   
//   printf("%d\n",BinarySearch(arr,4));
   
//    printf("index=%d\n",RBinarySearch(arr.A,0,arr.length,4));
 
//    printf("%d\n",get(arr,2));

//   set(&arr,2,1000);

//   printf("%d\n",Max(arr));

//   printf("%d\n",Min(arr));

//   printf("%d\n",Sum(arr));

//   Reverse(&arr);

//   Reverse2(&arr);

//   InserSort(&arr,3);

//   printf("%d\n",IsSorted(arr));

Rearrange(&arr);
     
     Display(arr);
   
    
    return 0;
}