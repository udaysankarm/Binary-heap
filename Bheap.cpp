#include<iostream>
using namespace std;

class Binary_heap
{
	public:
	int M_size,C_size;		            // maximum size and current size of array
	int *AR;			           // pointer to the array
	int *root;			          // root to point to array
	Binary_heap(int Max)		         //Default constructor
	{				
		AR=new int[Max];	        //creating a array in heap		
		M_size=Max;		       // getting the max size 
		C_size=0;// making cirrent size zero
		root=AR;      		      //makking root point to array
	}
	void Insert(int val)		     //insert function
	{
		if(C_size<M_size)	    //checking the condition for checking insertion
		{                          //
			AR[C_size]=val;   //storing the value at the position
			C_size++;	 //increamenting the current size
			//sort();	// sortpping the elements
			heapify();
		}
		else
		{
			cout<<"\n!!!!insertion not permitted!!!!";		//out put to user insertion not possible
		}
	}
	void sort()							  // sort function for checking the condition of binary tree
	{
		int i,j;
		for(i=C_size-1;i>=0;i--)
		if(AR[i]<AR[P(i)])				      // condition comparing the values of parent and children
		swap(AR+i,AR+P(i));
	
	
	}
	void display()						//display function
	{
		if(C_size==0)					//if the size of array is zero then print empty
		cout<<"\n the binary heap is empty\n";
		else
		{
			cout<<endl;
			for(int j=0;j<C_size;j++)				//loop to go through the array to print the array
			cout<<AR[j]<<endl;
		}
	}
	int P(int j)								// parent function
	{
		return (j-1)/2;
	}
	int LC(int j)								// left child function
	{
		return 2*j+1;
	}
	int RC(int j)							//right child function
	{
		return 2*j+2;
	}
	int Getmin(int *sub)
	{
		
	}
	void Delete(int A)							//delete function
	{
		for(int i=0;i<C_size;i++)				// going through the array
		if(AR[i]==A)
		{
			AR[i]=AR[C_size-1];				//storing the last element in the needed position
			AR[C_size-1]=0;
			C_size--;
			heapM(i);
		}
		
	} 
	void heapify()		//heapify function
	{

		if(C_size!=0)
		for(int i=C_size-1;i>=0;i--)
		heapM(i);
		
	}
	void heapM(int i)			// heapification function
	{
		int l=LC(i),r=RC(i);
		if(AR[l]<AR[i]&&l<C_size)	// if left side is less than parent
		{
			if(r<C_size)		// if right element is within the array
			{
				if(AR[l]<AR[r])	//if right side is greater than left 
				{
					swap(&AR[l],&AR[i]);	//replace with left
					heapM(l);					//recursieve call
				}
			}
			else
			{
				swap(&AR[l],&AR[i]);		//if right is outside range og binary heap
				heapM(l);			// caling the function again
			}
		}
		if(AR[r]<AR[i]&&r<C_size)
		{						// if rigt is less than parent
				if(AR[r]<AR[l])			//right is lower than left 
				{
					swap(&AR[r],&AR[i]);	//swap
					heapM(r);
				}
		}
	}
	void swap(int *a, int *b)		// swap function
	{
		int temp=*a;
		*a=*b;
		*b=temp;
	}
	int extractM()	// extract minimum function
	{
		if(C_size==0)		// base case
		{
			cout<<"Empty";	// if the array is empty
		}
		else if(C_size==1)	// if it has only one element
		{
			return *root;	// returing the root element
		}
		else			// if the there are more than one element
		{
			int temp=AR[0];		//storing minimum in temp
			AR[0]=AR[C_size-1];	//copiying last to root
			C_size--;		//decreasing current size
			heapM(0);		//calling heap function on root
			return temp;		//returing the min value
		}
	}
	int getmin()			//get minimum function
	{
		return AR[0];		//returing the minimum which is the root 
	}
	void decrekey(int p,int new_val)	//decrease function
	{
		AR[p]=new_val;		// storing the new value
		sort();			// sort function to correct property 2;
	}
	void deletekeyat(int i)
	{
		decrekey(i,AR[0]); 	//making the element in the needed  position the minimum element and sorting
		extractM();		// deleting the minimum
	}
};

int main()
{
	Binary_heap A(15);
	for(int i=50;i>39;i--)
	{
		A.Insert(i);
	}
	A.Insert(37);
	A.Insert(39);
	A.Insert(55);
	A.Insert(28);
	A.Insert(45);
	A.Insert(41);
	A.display();
	A.deletekeyat(5);
	cout<<"\n&^&$^@$%@#\n";
	A.display();
	cout<<"size:"<<A.C_size<<endl;
	cout<<"\n!!!!!!"<<A.extractM()<<"\n";
	A.display();
	cout<<"size:"<<A.C_size<<endl;
	return 0;
}
