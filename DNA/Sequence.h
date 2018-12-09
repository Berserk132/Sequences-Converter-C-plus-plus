#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<bits/stdc++.h>
using namespace std;

extern map<string,char>aminoAcid;           //extern to tell the compiler that aminoAcid exist somewhere else
extern map<char,string>reversedAcid;        // so multiple definition error wont appear

class Sequence
{
  	protected:
        char * seq;
    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        void setSeq(char seq[]);
        void setSeqSize(int siz);
        char* getSeq()const;
        int getSeqSiz()const;
        char getElement(int idx)const;
        void setElement(char element,int idx);
        virtual ~Sequence();
        static void loadCodon();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
       // virtual void Print()= 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2);
};

#endif // SEQUENCE_H
