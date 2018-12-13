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
// Function to Open The Codon File To Convert the RNA to Protein
void loadCodon(){
    in.open("Codons.txt",ios::in);
    string sequenc;
    char equivlent;
    for(int i=0;i<64;++i){
        in>>sequenc;
        in.get();
        in.get(equivlent);
        reversedAcid[equivlent]=sequenc;
        aminoAcid[sequenc]=equivlent;
    }
    in.close();
}
int first,lst;
// Function to Open The Codon File To Convert the RNA to Protein
int Align(Sequence* s1, Sequence* s2,int x1=0, int x2=0){
    int& ret=memo[x1][x2];
    if(x1==s1->getSeqSiz()-1 || x2==s2->getSeqSiz()-1){
        return ret=(s1->getElement(x1)==s2->getElement(x2))?1:0;
    }
    if(s1->getElement(x1)==s2->getElement(x2)){
        if(~ret) return ret;
        else
            return ret=Align(s1,s2,x1+1,x2+1)+1;

    }
    else {
        if(~ret) return ret;
        else{
            ret=max(Align(s1,s2,x1+1,x2),Align(s1,s2,x1,x2+1));
            return ret;
        }
    }
}

char* LCS(Sequence* s1, Sequence* s2,int x1=0,int x2=0){
    char* seq=new char [s1->getSeqSiz()+1];
    int lcsNow=Align(s1,s2);
    for(int i=0,k=0;i<s1->getSeqSiz();++i)
        for(int j=k;j<s2->getSeqSiz();++j){
            if(lcsNow==0) return seq;
            if(s1->seq[i]==s2->seq[j]&&lcsNow==Align(s1,s2,i,j)){
                seq[k]=s1->getElement(i),k++,--lcsNow;
                break;
            }
        }
    return seq;
}


void save(Sequence* cont){
    out.open("save.txt",ios::out);
    out<<cont->seq;
    out.close();
}
void load(Sequence* s){
    in.open("save.txt",ios::in);
    in>>s->seq;
    in.close();
}
ostream& operator<<(ostream& outt,const Sequence& s)
{
    outt<<s.seq<<endl;
    return outt;
}
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
        Sequence* d1=new DNA;
        Sequence* d2=new RNA;
        Sequence* d3=new Protein;
        cin>>d1>>d2>>d3;
        cout << *d1<<*d2<<*d3;
        d1->valid(d1->getSeq());

        /*cout<<aminoAcid["AAA"]<<" amino "<<endl;
        DNA d1("AAA",tail);
        DNA d4("TACCGCTTACGCCATATT",tail);
        DNA d2;
        d1.BuildComplementaryStrand();
        RNA r1;
        cout<<"D1 = : ";
        d1.Print();
        cout<<"R1 = : ";
        r1=d1.ConvertToRNA();
        r1.Print();
        cout<<"D2 = : ";
        d2=(r1.ConvertToDNA());
        d2.Print();
        Protein p1;
        cout << endl;
        cout<<"P1 = : ";
        p1=(r1.ConvertToProtein());
        p1.Print();
        DNA d3;
        d3=p1.GetDNAStrandsEncodingMe(d4);
        cout<<endl<<endl;
        d3.Print();
        Sequence* v1=new DNA;
        Sequence* v2=new DNA;
        cin>>v1>>v2;
        cout<<LCS(v1,v2)<<endl;
        cout<<"v1 = "<<(*v1)<<"\nv2 = "<<(*v2);
        if((*v1)!=v2) cout<<"hehehehehe"<<endl;
        save(v1);
        load(v2);
        cout<<"V2 = "<<(*v2)<<endl;*/
    }
    catch(string x){ cout<<x<<endl;}

}
