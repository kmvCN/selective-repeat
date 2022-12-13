#include<iostream>
          using namespace std;
          int hamming(int *data,int *redundant,int n,int r)
           {
               int hammcode[n],count=0,k=0,r1=r;
               for(int i=n;i>=1;i--)
                {
                  if(redundant[r1-1]!=i)
                    {
                       hammcode[i]=data[k]; ////initializing the hamming code with r bits=0 and data bits as given.
                       ++k;
                     }
                  else
                    {
                      hammcode[i]=0;
                      --r1;
                    }    
           }     
     for(int i=0;i<r;i++)
     {
         for(int j=1;j<=n;j++)
         {
             if((1<<i)&j)          ////searching for numbers with (n+1)th bit position=1
             {
                   if(hammcode[j]==1)
                   {
                       ++count;          ///for even parity.
                   }
             }
         }
         if(count%2==0)          ////if bit position=1,update the redundant bit position according to even parity.
         {
             hammcode[redundant[i]]=0;
         }
         else
         {
           hammcode[redundant[i]]=1;
         }
         count=0;
    }
    cout<<"HAMMING CODE:";
    for(int i=n;i>=1;i--)
    {
         cout<<hammcode[i];
    }
}
int main()
{
    int size,a=2,r=1;
   cout<<"enter size of the data :";
   cin>>size;
   while(1)
   {   
        if(a>=(size+1+r))   //2^r>=d+r+1
        {
           break;
        }
        ++r;
        a=a*2;
   }
   int data[size];
   int redundant[5]={1,2,4,8,16},j=r;
   cout<<"enter data :";
   for(int i=0;i<size;i++)
   {
      cin>>data[i];
   }
   if(data[0]==0){cout<<"Inappropriate data entered";
    exit(0);}
   hamming(data,redundant,size+r,r);
   return 0;
 }