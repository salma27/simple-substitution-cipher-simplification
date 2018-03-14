#include <iostream>
#include <bits/stdc++.h>
using namespace std;
///Salma Essam Soliman 20170115
string alpha="abcdefghijklmnopqrstuvwxyz",beta="**************************",key,word,choice,sure,newword="";
int sum=0,e=0,valid=0,a=0,b=0,c=0;
string length(string& key){ ///to know if the key is more than 5 letters
    while(key.length()!=5)
        {
            cout<<"Please enter a valid key=5:"<<endl;
            cout<<">>";
            cin>>key;
            cout<<endl;
            b=0;    ///a,b,c are variables that make me know if key satisfies all conditions or no
            c=0;
        }
    a=1;    ///a=1 then it satisfies this condition
    return key;
}
string letters(string& key){    ///make sure that there is no repetition
    for(int i=0; i<5; i++)
        {
                for(int j=0; j<5; j++)  ///compares the letters with each other and if there is a repetition the value of sum changes
                {
                    if(j==i)
                    {
                        continue;
                    }
                    else
                    {
                        if(key[j]==key[i]&&i!=j)
                        {
                            sum=sum+1;

                        }
                    }
                    if(sum!=0)
                    {
                        break;

                    }
                }
                if(sum!=0)
                {
                    a=0;
                    c=0;
                    i=0;
                    sum=0;
                    cout<<"Please enter a valid key with no repeated letters:"<<endl;
                    cout<<">>";
                    cin>>key;
                    cout<<endl;
                }
            }
            b=1;
                return key;
}
string numbers(string& key){    ///make sure that it contains only letters
    int g=0;
    do{
        if((int (key[g])<97&&int (key[g])>90)||int(key[g])>122||int (key[g])<65){   ///comparing the key with the ascii of alphapet letters
            cout<<"Please enter a valid non-numeric key:"<<endl<<">>";
            cin>>key;
            cout<<endl;
            g=0;
        }
        else{
            g++;
        }
      }while(g<5);
    c=1;
    return key;
}

int main()
{
    cout<<"Ahlan ya user ya habibi"<<endl;
    cout<<endl;

    while(true)
    {
        cout<<"what do you like to do today?"<<endl;
        cout<<"1-Cipher a message"<<endl;
        cout<<"2-Decipher a message"<<endl;
        cout<<"3-End"<<endl;
        cout<<">>";
        cin>>choice;
        cout<<endl;
        while(choice!="1"&&choice!="2"&&choice!="3")
        {
            cout<<"Error,Please choose from 1, 2 or 3"<<endl;
            cout<<">>";
            cin>>choice;
            cout<<endl;

        }
        if(choice=="1")
        {
            cout<<"Please enter a key to continue:"<<endl;
            cout<<">>";
            cin>>key;
            cout<<endl;
            while(a==0||b==0||c==0){
                for(int k=0; k<key.length(); k++)
                {
                    if(int(key[k])>=65&&int(key[k]<=90))
                    {
                        key[k]=char(int(key[k]+32));
                    }
                }
                length(key);
                numbers(key);
                letters(key);
            }
            a=0;
            b=0;
            c=0;
            for(int w=0;w<5;w++){
                beta[w]=key[w];
            }
            for(int s=4;s<26;s++){
                while(e<26){
                    if(alpha[e]==key[0]||alpha[e]==key[1]||alpha[e]==key[2]||alpha[e]==key[3]||alpha[e]==key[4]){
                        e++;
                        continue;
                    }
                    else{
                        beta[s+1]=alpha[e];
                        e++;
                        break;
                    }
                }
            }
            cout<<"Please enter the message to cipher:"<<endl;  ///getting spaces from the user
            cout<<">>";
            cin.ignore();
            getline(cin,word);
            cout<<endl;
            newword=word;
            for(int k=0; k<word.length(); k++)
            {
                if(int(word[k])>=65&&int(word[k]<=90))
                {
                    word[k]=char(int(word[k]+32));
                }
            }
            for(int i=0; i<word.length(); i++)  ///completing my array
            {
                for(int j=0; j<alpha.length(); j++)
                {
                    if(word[i]==alpha[j])
                    {
                        newword[i]=beta[j];
                        break;
                    }
                    if(j==alpha.length()-1)
                    {
                        newword[i]=word[i];
                        break;
                    }
                }
            }
            cout<<"your cipher text is:"<<endl<<">>"<<newword<<endl;
            cout<<endl;
        }
        if(choice=="2") ///the same goes with decipher with some changes but the same concept
        {
            cout<<"Please enter a key to continue:"<<endl;
            cout<<">>";
            cin>>key;
            cout<<endl;
            while(a==0||b==0||c==0){
                for(int k=0; k<key.length(); k++)
                {
                    if(int(key[k])>=65&&int(key[k]<=90))
                    {
                        key[k]=char(int(key[k]+32));
                    }
                }
                length(key);
                numbers(key);
                letters(key);
            }
            a=0;
            b=0;
            c=0;
            for(int w=0;w<5;w++){
                beta[w]=key[w];
            }
            for(int s=4;s<26;s++){
                while(e<26){
                    if(alpha[e]==key[0]||alpha[e]==key[1]||alpha[e]==key[2]||alpha[e]==key[3]||alpha[e]==key[4]){
                        e++;
                        continue;
                    }
                    else{
                        beta[s+1]=alpha[e];
                        e++;
                        break;
                    }
                }
            }
            cout<<"Please enter the message to decipher:"<<endl<<">>";
            cin.ignore();
            getline(cin,word);
            cout<<endl;
            newword=word;
            for(int k=0; k<word.length(); k++)
            {
                if(int(word[k])>=65&&int(word[k]<=90))
                {
                    word[k]=char(int(word[k]+32));
                }
            }
            for(int i=0; i<word.length(); i++)
            {
                for(int j=0; j<beta.length(); j++)
                {
                    if(word[i]==beta[j])
                    {
                        newword[i]=alpha[j];
                        break;
                    }
                    if(j==alpha.length()-1)
                    {
                        newword[i]=word[i];
                        break;
                    }
                }
            }
            cout<<"your plain text is:"<<endl<<">>"<<newword<<endl;
            cout<<endl;
        }
        if(choice=="3")
        {
            cout<<"Are you sure that you want end this program?"<<endl;
            cout<<"1-Yes"<<endl;
            cout<<"2-No"<<endl;
            cout<<">>";
            cin>>sure;
            cout<<endl;
            while(sure!="2"&&sure!="1")
            {
                cout<<"please choose 1 or 2"<<endl;
                cout<<">>";
                cin>>sure;
                cout<<endl;
            }
            if(sure=="1")
            {
                cout<<"Thank you for using this program"<<endl;
                cout<<endl;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}
