#include "DNA.h"
#include "Sequence.h"
#include <iostream>
using namespace std;
// Default Constructor
DNA::DNA()
{
    type=promoter;
}
// copy constructor to create a DNA sequence equal to another one
bool DNA::valid(char* ch){
    for(int i=0;i<strlen(ch);++i)
        if((char)ch[i]=='A'||(char)ch[i]=='T'||(char)ch[i]=='C'||(char)ch[i]=='G'){
            continue;
        }
        else{
            string x="invalid input for DNA ";
            throw x;
        }
    return 1;
}
// copy constructor to create a DNA sequence equal to another one
DNA::DNA(DNA* rhs){
    (valid(rhs->seq));
    seq=new char[strlen(rhs->seq)+1];
    seq=rhs->seq;
    type=rhs->type;
}
// Constructor to create a new DNA Sequence
DNA ::DNA(int length):Sequence(length){}
DNA :: DNA(char * s, DNA_Type atype)
{
    valid(s);
    seq=new char[strlen(s)+1];
    strcpy(seq,s);
    type = atype;
}
// copy constructor to create a DNA sequence equal to another one
DNA :: DNA(const DNA& rhs)
{
    valid(rhs.seq);
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;

}
// getter to get a DNA Sequence
char* DNA :: getDNA()
{
    return seq;
}

void DNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}
// Function to invert the DNA Sequence to get it's Complement
void DNA ::  BuildComplementaryStrand()
{
    startIndex=0;
    endIndex=strlen(seq);
    complementary_strand= new char[strlen(seq)+1];
    //cout<<complementary_strand<<" btngan"<<strlen(seq)+1<<endl;
    for(int j=0,i=endIndex-1;i>=0;--i,++j){
        complementary_strand[j]=seq[i];
        if(seq[i]=='A') complementary_strand[j]='T';
        else if(seq[i]=='T') complementary_strand[j]='A';
        else if(seq[i]=='C') complementary_strand[j]='G';
        else if(seq[i]=='G') complementary_strand[j]='C';
    }
    //cout<<complementary_strand<<" btngan2"<<endl;
    //complementary_strand;
}
// getter to return the complementary strand
char* DNA::getComplementalStrand(){
    return complementary_strand;
}
// operator equal to create a DNA sequence equal to another one
void DNA::operator=(DNA rhs){
    valid(rhs.seq);
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}
// Function to Convert the DNA Sequence to RNA Sequence
RNA DNA :: ConvertToRNA(){
    BuildComplementaryStrand();
    RNA tmp ;
    tmp.setSeq(complementary_strand);
    for(int i=0;i<strlen(complementary_strand);++i){
        if(tmp.getElement(i)=='T') tmp.setElement('U',i);
    }
    return  tmp;
}

// cout Operator to print the content of DNA Object
ostream& operator<<(ostream& out, DNA &s)
{
    out << "The DNA Sequence: ";
    for(int i=0 ; i<strlen(s.seq) ;i++)
    {
        out<<s.seq[i];
    }
    out << endl;
    out << "The DNA Type = ";
    if (s.type == 0)
    {
        out << "promoter";
    }
    else if (s.type == 1)
    {
        out << "motif";
    }
    else if (s.type == 2)
    {
        out << "tail";
    }
    else if (s.type == 3)
    {
        out << "noncoding";
    }
    out << endl;
    return out;
}
// cin Operator to take from user the content of DNA Object
istream& operator>>(istream& in, DNA& obj)
{
    in >> obj.seq;
    return in;
}


// plus operator to add a DNA sequence to another DNA sequence
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
// not equal operator to check if two DNA sequences not equal to each other
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
