#include "DNA.h"
#include "Sequence.h"
#include <bits/stdc++.h>
using namespace std;

DNA::DNA()
{
    type=promoter;
}

DNA::DNA(DNA* rhs){
    seq=new char[strlen(rhs->seq)+1];
    seq=rhs->seq;
    type=rhs->type;
}

DNA :: DNA(char * s, DNA_Type atype)
{
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}

DNA :: DNA(const DNA& rhs)
{
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;

}

char* DNA :: getDNA()
{
    return seq;
}

void DNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}

void DNA ::  BuildComplementaryStrand()
{
    startIndex=0;
    endIndex=strlen(seq);
    complementary_strand= new char[strlen(seq)+1];
    for(int i=endIndex-1,j=0;i>=0;--i,j++){
        complementary_strand[j]=seq[i];
        if(seq[i]=='A') complementary_strand[j]='T';
        else if(seq[i]=='T') complementary_strand[j]='A';
        else if(seq[i]=='C') complementary_strand[j]='G';
        else if(seq[i]=='G') complementary_strand[j]='C';
    }
    //complementary_strand;
}

char* DNA::getComplementalStrand(){
    return complementary_strand;
}
void DNA::operator=(DNA rhs){
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
RNA DNA :: ConvertToRNA(){
    BuildComplementaryStrand();
    RNA tmp ;
    tmp.setSeq(complementary_strand);
    for(int i=0;i<strlen(complementary_strand);++i){
        if(tmp.getElement(i)=='T') tmp.setElement('U',i);
    }
    return  tmp;
}
ostream& operator<<(ostream& out, DNA &s)
{
    out << "The DNA Sequence: ";
    for(int i=0 ; i<strlen(s.seq) ;i++)
    {
        out<<s.seq[i];
    }
    out << endl;
    //out << "The Sequence Type = ";
    //out << endl;
    //out << s(DNA)->type << endl;
    return out;
}

istream& operator>>(istream& in, DNA& obj)
{
    in >> obj.seq;
    return in;
}

DNA DNA:: operator+(DNA& d2)
{
    DNA tmp;
    int length2 = strlen(d2.seq);
    int length1 = strlen(seq);
    tmp.seq = new char [length1+length2+2];
    for (int i=0; i<length1; i++)
    {
        tmp.seq[i] = seq[i];
    }
    for (int i=length1; i<length1+length2; i++)
    {
        tmp.seq[i] = d2.seq[i-length1];
    }

    return tmp;
}

bool DNA ::  operator!= (DNA& d)
{
    if (strcmp(seq,d.seq))
        return true;
    else
        return false;
}

DNA::~DNA()
{
}
