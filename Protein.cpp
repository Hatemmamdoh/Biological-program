#include "Protein.h"
#include "RNA.h"
Protein::Protein()
{
    //ctor
}

Protein::Protein(char * p,Protein_Type atype)
{
	set_sequence(p);
    type = atype;
    /*switch (type)
    {
    case Hormon:
        cout << "Hormon" << endl;
        break;
    case Enzyme:
        cout << "Enzyme" << endl;
        break;
    case TF:
        cout << "TF" << endl;
        break;
    case Cellular_Function:
        cout << "Cellular_Function" << endl;
        break;
    }*/
}

Protein :: Protein(const Protein& p)
{
    if(p.seq != nullptr)
    {
      seq = new char[strlen(p.seq)+1];
	  strcpy(seq, p.seq);
      type = p.type;
    }
}

void Protein :: Print()
{
    cout << "Protein Sequence: " << seq << endl;
    cout << "Type : ";
    switch (type)
    {
    case Hormon:
        cout << "Hormon" << endl;
        break;
    case Enzyme:
        cout << "Enzyme" << endl;
        break;
    case TF:
        cout << "TF" << endl;
        break;
    case Cellular_Function:
        cout << "Cellular_Function" << endl;
        break;
    }

}
Protein_Type Protein::get_type (){
return type; }

Protein Protein::operator+ (const Protein& p)
{
    char* temp = new char[strlen(seq)+strlen(p.seq)+1];
    for(int i = 0 ; i < strlen(seq)+strlen(p.seq);i++)
    {
        if(i < strlen(seq))
            temp[i] = seq[i];
        else
            temp[i] = p.seq[i - strlen(seq)];
    }
    temp[strlen(seq)+strlen(p.seq)] = '\0';
    return Protein(temp,type);
}

bool Protein::operator== (const Protein& p)
{
    if(type == p.type && strlen(seq) == strlen(p.seq))
    {
        for(int i = 0;i<strlen(seq); i++)
        {
            if(seq[i] != p.seq[i])
                return false;
        }
        return true;
    }
    else
        return false;
}

bool Protein::operator!= (const Protein& p)
{
    return !Protein::operator==(p);
}


DNA* Protein::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{
	try {
		vector<string> DNAs;
		string strand;
		int strand_len = strlen(seq) * 3;
		char* bigDNA_seq = bigDNA.get_sequence();

		if (strand_len > strlen(bigDNA_seq))
			throw "Invalid Size!";

		else
		{
			int Count = 0;
			//char** DNAs = new char*[strlen(bigDNA_seq)/strand_len];
			//int i = strand_len;
			CodonsTable T("RNA_codon_table.txt");
			while (true)
			{
				strand = "";
				for (int i = Count; i < strand_len+Count; i++)
				{
					strand += bigDNA_seq[i];
				}
				char* cStrand = new char(strand.length());
				strcpy(cStrand, strand.c_str());

				//Converting to RNA
				Sequence* d = new DNA(cStrand, motif);
				Sequence* r;
				r = ((DNA*)d)->ConvertToRNA();

				//Convert to Protein
				r = ((RNA*)r)->ConvertToProtein(T);

				char* CurrentProtein = new char[strlen(r->get_sequence())];
				strcpy(CurrentProtein, r->get_sequence());
				bool is_Protein_equal = true;
				for (int i = 0; i < strlen(CurrentProtein); i++)
				{
					if (seq[i] != CurrentProtein[i])
					{
						is_Protein_equal = false;
						break;
					}
				}
				if (is_Protein_equal)
				{
					DNAs.push_back(strand);
					Count += strand_len;
				}
				else
				{
					Count++;
				}
				if ((strlen(bigDNA_seq) - Count) < strand_len)
					break;
			}
		}
		DNA * d = new DNA [ DNAs.size() ] ;
		for (int i = 0; i < DNAs.size(); i++)
		{
			char* p = new char(DNAs[i].length());
			strcpy(p, DNAs[i].c_str());
			d[i].set_sequence(p);
			d[i].set_type(bigDNA.get_type());
			d[i+1].set_sequence(nullptr);
		}
		return d;
	}

	catch (const char x)
	{
		cout << x << endl;
		return nullptr;
	}
}


Protein::~Protein()
{
    delete seq;
}


