#include <iostream>
#include<random>
using namespace std;

string global="";

class info{
    public:
    string s;
    string arr;
    int size;
    public:

    info(string inc){
        this->size=inc.size();
        s=inc;

        char put='0';
        for(int i=0;i<size;i++){
            arr+=put;
            if(put=='0'){
                put='1';
            }
            else{
                put='0';
            }

        }


    }
    info(){
        this->size=0;
        s="";

       arr="";

    }
    void add(char c,char ack){
        s+=c;
        arr+=ack;

    }
    void display(){
        cout<<s<<endl;
        // for(int i=0;i<size;i++){
        // cout<<arr[i]<<" ";
        // }
    }
    void display2(){
        cout<<"Sequence no is "<<endl;
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }
};


char receiver(char c,info &ans,int pt,int cas,char ack){
    if(cas==1){
       if(ans.s.size() == pt )
        ans.add(c,ack);
        cout<<"(Receiver) - Receiver received "<<c<<" with seq no "<<ack<<endl;
          cout<<"(Receiver)- Msg status "<<endl;
        ans.display();


        char temp;
        if(ack=='1'){
            temp='0';
        }
        else{
            temp='1';
        }
        cout<<"(Receiver) - send ack with seq no "<<temp<<endl;
        return temp;
    }
    else if(cas==2){
        cout<<"(Receiver)- Frame receeived with error "<<endl;

        return -1;
    }
   else if(cas==3){
       //cout<<"(Receiver) - Frame Lost"<<endl;

        return -1;
    }
    else {
        cout<<"(Receiver)- receeived "<<c<<" with seq no "<<ack<<endl;
        if(ans.s.size()<=pt && ans.s[pt]!=c){
            ans.add(c,ack);
            cout<<"(Receiver)- Saved "<<c<<" at seq no "<<pt<<" in the Receiver end"<<endl;
        }
          cout<<"(Receiver)- Msg status "<<endl;
        ans.display();


       char temp;
        if(ack=='1'){
            temp='0';
        }
        else{
            temp='1';
        }

        cout<<"(Receiver)- Acknowledgement sent with seq no "<<temp<<endl;

        return -1;
    }
}


info communicate(info send){
    //info send(msg);
    string msg=send.s;

    info ans;

    send.display();
    send.display2();
    //receive.display();

    int pt=0;
    while(pt<msg.length()){
        int cas=1+rand()%4;

        char sack=send.arr[pt];


        cout<<"case is "<<cas<<endl;


        cout<<"(Sender)- sent "<<send.s[pt]<<" with sequence no "<<sack<<endl;

        char rack;
        if(cas==1){
            rack=receiver(send.s[pt],ans,pt,cas,sack);
            cout<<"(Sender)- Acknowledgement Received with seq no "<<rack<<endl;
            //pt++;
        }
        if(cas==2){
            rack=receiver(send.s[pt],ans,pt,cas,sack);
            cout<<"(Sender) -timer expired"<<endl;
        }
        if(cas==3){
            rack=receiver(send.s[pt],ans,pt,cas,sack);
            cout<<"(Sender) -timer expired"<<endl;
        }
        if(cas==4){
            rack=receiver(send.s[pt],ans,pt,cas,sack);

            cout<<"(Sender) -timer expired"<<endl;

        }

         cout<<endl;

        if(sack!=rack && rack!=-1){
            pt++;
        }
    }

   // ans.display();
    cout<<endl;
    cout<<endl;
    ans.size=ans.s.size();
    return ans;


}

void RnetworkLayer(string s){
   cout<<"Here in Network layer of Receiver and collecting the frames to convert into complete msg "<<endl;
    global+=s;
    global+=" ";

}


void RdataLinkLayer(info get){
   cout<<"Here in Data link layer of Receiver and sending frames to the network layer"<<endl;
   RnetworkLayer(get.s);
}


void  RphysicalLayer(info get){
   cout<<"At Receiver's physical layer "<<endl;
   RdataLinkLayer(get);

}


void SphysicalRlayer(info send){
    cout<<"Actual communication between physical layer of sender and receiver"<<endl;
   info receive=communicate(send);
   RphysicalLayer(receive);
}


void SphyscialLayer(info &send){

    cout<<"Here in Sender's Physical Layer"<<endl;

    SphysicalRlayer(send);



}

void SdataLinkLayer(string msg){

    cout<<"Here in the Sender's Data link Layer"<<endl;

    info send(msg);

    SphyscialLayer(send);
}

void SnetworkLayer(string input){
    cout<<"Here in Network Layer of Sender"<<endl;
    int id=0;
   while(id<input.length()){
    int tempid=id;
    string temp="";
    while(tempid<input.length() && input[tempid]!=' '){
        temp+=input[tempid];
        tempid++;
    }
    cout<<"Now sender working on word "<<temp<<endl;

    SdataLinkLayer(temp);


    id=tempid+1;
   }

}







void sender(string input){
     SnetworkLayer(input);
}


int main()
{

     string input;

     string output="";
   cout<<"Enter the line"<<endl;
   getline(cin,input);

  sender(input);

    cout<<global<<endl;

    return 0;
}


