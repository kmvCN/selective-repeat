#include<iostream>
using namespace std;

class checksum
{
public:
    int dataword[20],csize,dsize,l,temp[20],tsize;
    void get()
    {
        cout<<"\nEnter the length of Dataword : ";
        cin>>dsize;
        cout<<"\nEnter Dataword: ";
        for(int i=0;i<dsize;i++)
        {
            cin>>dataword[i];
        }
        cout<<"Enter length of Checksum: ";
        cin>>csize;
    }

    void check()
    {
        if(dsize%csize!=0)
        {
            l=csize-dsize%csize;
            cout<<l;
            tsize=l+dsize;
            for(int i=0;i<l;i++)
            {
                temp[i]=0;
            }
            for(int i=l,j=0;i<tsize;j++,i++)
            {
                temp[i]=dataword[j];
            }
        }
        else
        {
            tsize=dsize;
            for(int i=0;i<tsize;i++)
            {
                temp[i]=dataword[i];
            }
        }
        cout<<endl;
        for(int i=0;i<tsize;i++)
        {
            cout<<temp[i];
        }
    }
    void generator()
    {
        int res[csize];
        for(int i=0;i<csize;i++)
        {
            res[i]=0;
        }
        for(int i=csize-1;i>=0;i--)
        {
            int j=tsize-1;
            while(j>=i)
            {
                res[i]=res[i] | temp[j];
                j=j-csize;
            }
        }
        cout<<"\nOutput";
        for(int i=0;i<csize;i++)
        {
            cout<<!res[i];
        }
    }
};

int main()
{
    checksum obj;
    obj.get();
    obj.check();
    obj.generator();
    return 0;
}
