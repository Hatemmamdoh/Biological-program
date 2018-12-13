#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include <bits/stdc++.h>
using namespace std;


RNA::RNA()
{
	//ctor
}

RNA::~RNA()
{
//	delete[] seq;
}

RNA::RNA(char * seq, RNA_Type atype)
{
	this->seq = new char[strlen(seq)];
	strcpy(this->seq, seq);
	type = atype;
}
/*
RNA::RNA(RNA& rhs)
{
	set_sequence(seq);
	type = rhs.type;
}
*/
RNA :: RNA(const RNA& p)
{
    if(p.seq != nullptr)
    {
      seq = new char[strlen(p.seq)+1];
	  strcpy(seq, p.seq);
      type = p.type;
    }
}

DNA* RNA::ConvertToDNA()
{
	char* RSeq;
	RSeq = new char[strlen(seq)];
	for (int i = 0; i < strlen(seq); i++)
	{
		if (seq[i] == 'U')
			RSeq[i] = 'T';
		else
			RSeq[i] = seq[i];
		RSeq[i + 1] = '\0';
	}
	DNA* d = new DNA(RSeq, motif);
	return d;
}

RNA_Type RNA::get_type()
{
	return type;
}

void RNA::Print()
{
	cout << "--> RNA Sequence :";
	for (int i = 0; i < strlen(seq); i++)
	{
		cout << this->seq[i];
	}
	cout << endl << "--> Type: ";

	switch (type)
	{
	case mRNA:
		cout << "mRNA" << endl;
		break;
	case pre_mRNA:
		cout << "pre_mRNA" << endl;
		break;
	case mRNA_exon:
		cout << "mRNA_exon" << endl;
		break;
	case mRNA_intron:
		cout << "mRNA_intron" << endl;
		break;
	}
}

bool RNA::operator== (const RNA& R1)
{
  bool Equal = true ;
  if (strlen(this-> seq )> strlen (R1.seq) ||strlen(this-> seq )< strlen (R1.seq))
    Equal = false ;
  for (int i = 0 ; i < strlen (R1.seq) ; i++ )
  {
    if (R1.seq[i] != this -> seq[i])
    {
        Equal = false ;
        break ;
    }
  }
  return Equal ;

}

bool RNA::operator!= (const RNA& R1)
{
bool NotEqual = false ;
if (strlen(this-> seq )> strlen (R1.seq) ||strlen(this-> seq )< strlen (R1.seq))
    NotEqual = true ;
for (int i = 0 ; i < strlen (R1.seq) ; i++ )
{
    if (R1.seq[i] != this -> seq[i])
    {
        NotEqual = true ;
        break ;
    }
}
return NotEqual ;

}

RNA RNA::operator+ (const RNA& R)
{
    /*char* temp = new char[strlen(seq)+strlen(p.seq)+1];
    for(int i = 0 ; i < strlen(seq)+strlen(p.seq);i++)
    {
        if(i < strlen(seq))
            temp[i] = seq[i];
        else
            temp[i] = p.seq[i - strlen(seq)];
    }
    temp[strlen(seq)+strlen(p.seq)] = '\0';
    return RNA(temp,type);
    */
    int s1 , s2 ;
    s1 = strlen (this-> seq ) ;
    s2 = strlen (R.seq) ;
    char* concatenate = new char [s1+s2+1] ;
    for (int i = 0 ; i < s1 ; i++)
        concatenate[i] = this -> seq[i] ;
    for (int i = s1 ; i < s1+s2 ; i++)
        concatenate[i] = R.seq[i-s1] ;

    concatenate [s1+s2] = '\0' ;
    return RNA (concatenate,type) ;
}


Protein* RNA::ConvertToProtein(CodonsTable & table)
{
	char* RSeq ;
	char *r = new char[4];
	RSeq = new char[strlen(seq)/ 3];
	int counter =0 ,i = 0 ;
	RSeq[strlen(seq) / 3] = '\0';
	Codon store;
	for (int j = 0 ; j < strlen(seq)/3 ; j++)
	{
		for (i = counter ; i < strlen(seq)+1 ; i++)
		{
		if (i - counter > 2)
		{

			store = table.getAminoAcid(r);
			if (store.AminoAcid == '*')
			{
				RSeq[j] = '\0';
				delete[] r;
				Protein* p = new Protein(RSeq, Cellular_Function);
				return p;
			}
			RSeq[j] = store.AminoAcid;
			i-- ;
			delete[]r;
			r = new char[4];
			break ;
		}
		else
		{
			r[i%3] = seq[i] ;
			r[i%3 + 1] = '\0';
		}
		}
		counter = i+1 ;
	}

	Protein* p = new Protein(RSeq, Cellular_Function) ;
	return p ;
}

