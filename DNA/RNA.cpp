#include "RNA.h"

RNA::RNA()
{
    //ctor
}
RNA::RNA(char * seq, RNA_Type atype)
{
    this->seq=new char[strlen(seq)+1];
    strcpy(this->seq,seq);
    type=atype;
}
RNA::RNA(RNA& rhs):Sequence(rhs){
    type=rhs.type;
}
Protein RNA::ConvertToProtein(){
    Protein tmp;
    char* tmpChar = new char [strlen(seq)/3+1];
    std::string codon;
    for(int i=0,j=0;i<strlen(seq);i+=3,j++){
        codon+=seq[i]+seq[i+1]+seq[i+2];
        tmpChar[j]=mp[codon];
        if(tmpChar==' ') break;
        codon.clear();
    }
    strcpy(tmp.seq,tmpChar);
    tmp.type=3;
    return tmp;
}
DNA RNA::ConvertToDNA(){
    DNA tmp;
    tmp.seq=new char[strlen(seq)+1];
    strcpy(tmp.seq,seq);
    for(int i=0;i<strlen(seq);++i){
        if(tmp.seq[i]=='U') tmp.seq[i]='T';
    }
    tmp.BuildComplementaryStrand();
    strcpy(tmp.seq,tmp.complementary_strand->seq);
    return tmp;

}
RNA::~RNA()
    //dtor
}
