#include <bits/stdc++.h>
#include "DNA.h"
#include "RNA.h"
using namespace std;

DNA::DNA()
{

}

DNA::DNA(char * seq, DNA_Type atype)
{
	set_sequence(seq);
	set_type(atype);
}

DNA::DNA(DNA& rhs)
{
	if (rhs.seq != nullptr)
	{
		seq = new char[strlen(rhs.seq)];
		strcpy(seq, rhs.seq);
	}
}

void DNA::Print()
{
	if (seq != NULL)
	{
		cout << "--> First Strand: ";
		Sequence::Print();
		cout << endl << "--> Type: ";

		switch (type)
		{
		case promoter:
			cout << "promoter" << endl;
			break;
		case motif:
			cout << "motif" << endl;
			break;
		case tail:
			cout << "tail" << endl;
			break;
		case noncoding:
			cout << "noncoding" << endl;
			break;
		}
	}

	if (complementary_strand != NULL)
	{

		cout << "--> Second Strand: ";
		complementary_strand->Sequence::Print();
		cout << endl;
	}
}

RNA* DNA::ConvertToRNA()
{
	char* RSeq;
	RSeq = new char[strlen(seq)];
	for (int i = 0; i < strlen(seq); i++)
	{
		if (seq[i] == 'T')
			RSeq[i] = 'U';
		else
			RSeq[i] = seq[i];
		RSeq[i + 1] = '\0';
	}
	RNA* r = new RNA(RSeq, mRNA);
	return r;
}

void DNA::BuildComplementaryStrand()
{
	char* sStrand;
	sStrand = new char[strlen(seq)];
	for (int i = 0; i < strlen(seq); i++)
	{
		if (seq[i] == 'T')
			sStrand[i] = 'A';

		if (seq[i] == 'A')
			sStrand[i] = 'T';

		if (seq[i] == 'C')
			sStrand[i] = 'G';

		if (seq[i] == 'G')
			sStrand[i] = 'C';

		sStrand[i + 1] = '\0';
	}
	complementary_strand = new DNA(sStrand, type);
}

void DNA::set_type(DNA_Type T)
{
	type = T;
}

DNA_Type DNA::get_type() const
{
	return type;
}

DNA& DNA::operator+(const DNA& add)
{
	int size = strlen(seq) + strlen(add.seq);
	//char* concatenate = new char [size+1];
	int index = 0;

	char* sum = new char[size+1];
	for (int i = 0; i < size ; i++)
	{
		if (i < strlen(seq))
			sum[i] = seq[i];
		else
			sum[i] = add.seq[index++];
		sum[i+1] = '\0';
	}
	DNA* D = new DNA(sum, type);
	return *D;
}

bool DNA::operator==(const DNA & add)
{
	bool same = true;
	if (strlen(seq) != strlen(add.seq))
		same = false;
	else
	{
		for (int i = 0; i < strlen(seq); i++)
			if (seq[i] != add.seq[i])
				same = false;
	}
	return same;
}

bool DNA::operator!=(const DNA & add)
{
	return ! (*this == add);
}



