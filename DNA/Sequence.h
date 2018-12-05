#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<bits/stdc++.h>
/*
std::map<std::string,char>mp;
std::map<char,std::string>reversed;
freopen("Codons",'r',stdin);
std::string sequenc;
char equivelent;
for(int i=0;i<64;++i){
    cin>>sequenc>>equivelent;
    mp[sequenc]=equivelent;
    reversed[equivelent]=sequenc;
}*/
class Sequence
{
  	public:
        char * seq;
    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
       // virtual void Print()= 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2);
};

#endif // SEQUENCE_H
