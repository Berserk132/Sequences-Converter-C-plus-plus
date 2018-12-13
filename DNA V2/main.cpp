#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
using namespace std;
const int N=1e2;
int memo[N][N];
ifstream in;
ofstream out;
//open codon.txt load codon in map
void loadCodon(){
    in.open("Codons.txt",ios::in);
    char sequenc[4];
    char equivlent;
    for(int i=0;i<64;++i){
        in>>sequenc;
        in.get();
        in.get(equivlent);
        aminoAcid[sequenc]=equivlent;
    }
    in.close();
}
int first,lst;
//get the longest common sequence length
int Align(Sequence* s1, Sequence* s2,int x1=0, int x2=0){
    int& ret=memo[x1][x2];                              //array to memorize the past changes
                                                        // reference to change the value in memo as ret changes
    if(x1==s1->getSeqSiz()-1 || x2==s2->getSeqSiz()-1){
        return ret=(s1->getElement(x1)==s2->getElement(x2))?1:0;        //return 1 if equal
    }
    if(s1->getElement(x1)==s2->getElement(x2)){
        if(~ret) return ret;
        else
            return ret=Align(s1,s2,x1+1,x2+1)+1;            //make the value of ret +1 the the longest other path

    }
    else {
        if(~ret) return ret;
        else{
            ret=max(Align(s1,s2,x1+1,x2),Align(s1,s2,x1,x2+1));     //try both the next char in the first sequence
                                                                    //and the second sequence and return the maximum between them
            return ret;
        }
    }
}
//get the longest common sequence array
char* LCS(Sequence* s1, Sequence* s2,int x1=0,int x2=0){
    char* seq=new char [s1->getSeqSiz()+1];
    int lcsNow=Align(s1,s2);                    //save the biggest path in lcsNow
    for(int i=0,k=0;i<s1->getSeqSiz();++i)
        for(int j=k;j<s2->getSeqSiz();++j){
            if(lcsNow==0) return seq;
            if(s1->seq[i]==s2->seq[j]&&lcsNow==Align(s1,s2,i,j)){       //if the two char equal and in the longest path
                seq[k]=s1->getElement(i),k++,--lcsNow;                  //add them to the array then - the path size
                break;
            }
        }
    return seq;
}

//save the sequence in save.txt
void save(Sequence* cont){
    out.open("save.txt",ios::out);
    out<<cont->seq;
    out.close();
}
//load sequence from save.txt
void load(Sequence* s){
    in.open("save.txt",ios::in);
    in>>s->seq;
    in.close();
}
//cout the sequence
ostream& operator<<(ostream& outt,const Sequence& s)
{
    outt<<s.seq<<endl;
    return outt;
}
//cin the sequence
istream& operator>>(istream& inn, Sequence *s)
{
    s->setSeqSize(100);
    inn >> s->seq;
    (s->valid(s->seq));
    return inn;
}
int main()
{
    try{
        memset(memo,-1,sizeof memo);
        loadCodon();
//        Sequence* c1=new DNA;
//        Sequence* c2=new RNA;
//        Sequence* c3=new Protein;
//        cin>>c1>>c2>>c3;

        DNA d1("TTACGCCAT",tail);
        cout<<"D1 = : ";
        d1.Print();
        d1.BuildComplementaryStrand();
        cout<<"complementary strand is : "<<d1.getComplementalStrand()<<endl;
        RNA r1;
        r1=d1.ConvertToRNA();
        cout<<"R1 = : ";
        r1.Print();
        DNA d2;
        d2=(r1.ConvertToDNA());
        cout<<"D2 = : ";
        d2.Print();
        Protein p1;
        cout<<"P1 = : ";
        p1=(r1.ConvertToProtein());
        p1.Print();
        DNA d4("TACCGCTTACGCCATATT",tail);
        DNA d3;
        d3=p1.GetDNAStrandsEncodingMe(d4);
        cout<<"DNA strand from protein ";
        d3.Print();
        cout<<endl<<endl;
        Sequence* v1=new DNA;
        Sequence* v2=new DNA;
        cout<<"enter the tow DNA to compare: ";
        cin>>v1>>v2;
        cout<<"The LCS is : "<<LCS(v1,v2)<<endl;
        cout<<"v1 = "<<(*v1)<<"v2 before loading = "<<(*v2);
        save(v1);
        load(v2);
        cout<<"V2 after loading = "<<(*v2)<<endl;
    }
    catch(string x){ cout<<x<<endl;}

}
