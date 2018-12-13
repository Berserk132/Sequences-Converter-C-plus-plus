#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<bits/stdc++.h>
using namespace std;

extern map<string,char>aminoAcid;           //extern to tell the compiler that aminoAcid exist somewhere else
extern map<char,string>reversedAcid;        // so multiple definition error wont appear

//template <class T>

class Sequence
{
  	protected:
        char * seq;
        friend int Align(Sequence& s1, Sequence& s2,int x1,int x2);
    public:
 	 	// constructors and destructor
        //virtual bool valid(char* v);
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        void setSeq(char* seq);
        void setElement(char element,int idx);
        //void setSeq(T* seq);
        //void setElement(T element,int idx);
        void setSeqSize(int siz);
        char* getSeq()const;
        int getSeqSiz()const;
        char getElement(int idx)const;
        virtual ~Sequence();
        static void loadCodon();
        friend void save(Sequence* cont);
        friend void load(Sequence* s);
        friend ostream& operator<<(ostream& out,const Sequence& s);
        friend istream& operator>>(istream& in, Sequence *s);
        bool operator!= (Sequence* d);
        bool operator== (Sequence* d);
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()= 0;
        virtual bool valid(char* ch)=0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* LCS(Sequence *s1, Sequence *s2,int x1,int x2);
};

#endif // SEQUENCE_H
