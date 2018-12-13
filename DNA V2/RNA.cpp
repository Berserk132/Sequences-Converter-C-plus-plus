#include "RNA.h"

RNA::RNA()
{
    //ctor
}
bool RNA::valid(char* ch){
    for(int i=0;i<strlen(ch);++i)
        if((char)ch[i]=='A'||(char)ch[i]=='U'||(char)ch[i]=='C'||(char)ch[i]=='G')
                continue;
        else{
            string x="invalid input for RNA ";
            throw x;
        }
    return 1;
}
RNA::RNA(char * seq, RNA_Type atype)
{
    valid(seq);
    this->seq=new char[strlen(seq)+1];
    strcpy(this->seq,seq);
    type=atype;
}
RNA::RNA(const RNA& rhs){
    valid(rhs.seq);
    seq=new char[strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
    type=rhs.type;
}
void RNA::Print(){
    for(int i=0 ; i<strlen(seq) ;i++)
        cout<<seq[i];
    cout<<endl;
}

Protein RNA::ConvertToProtein(){
    Protein tmp;
    char* tmpChar = new char [(strlen(seq)/3)+1];
    char codon[4];
    for(int i=0,j=0;i<strlen(seq);i+=3,j++){
        codon[0]=seq[i],codon[1]=seq[i+1],codon[2]=seq[i+2];
        tmpChar[j]=aminoAcid[codon];
        if(tmpChar[j]==' ') break;
    }
    tmp.setSeq(tmpChar);
    return tmp;
}

DNA RNA::ConvertToDNA()const{
    RNA temp;
    DNA tmp;
    temp.seq=new char[strlen(seq)+1];
    strcpy(temp.seq,seq);
    for(int i=0;i<strlen(seq);++i){
        if(temp.seq[i]=='U') temp.seq[i]='T';
    }
    tmp.setSeq(temp.seq);
    tmp.BuildComplementaryStrand();
    tmp.setSeq(tmp.getComplementalStrand());
    return tmp;

}

RNA::~RNA(){
    //dtor
}
