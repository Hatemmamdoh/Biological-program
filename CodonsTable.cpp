#include "CodonsTable.h"
#include <bits/stdc++.h>
using namespace std;

CodonsTable::CodonsTable(string codonsFileName)
{
    LoadCodonsFromFile(codonsFileName);
}
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    ifstream codons_data;
	codons_data.open(codonsFileName);
    if(codons_data.fail() == false)
    {
        int i = 0;
        string reader;
        bool Is_stop_codon = false;
        while(codons_data >> reader)
        {
            /*switch (i % 4)
            {
                case 0:
                    codons[i/4].value[0] = reader;
                    break;
                case 1:
                    codons[i/4].value[1] = reader;
                    break;
                case 2:
                    codons[i/4].value[2] = reader;
                    break;
                case 3:
                    if(codons[i].value == "UAA" || codons[i].value == "UAG" || codons[i].value == "UGA")
                    {
                        codons[i/4].AminoAcid = '*';
                        i++;
                        codons[i/4].value[0] = reader;
                    }
                    else
                    codons[i/4].AminoAcid = reader;
                    break;
            }*/
            if(i % 2 == 0)
            {
                strcpy(codons[i/2].value,reader.c_str());
                if(reader == "UAA" || reader == "UAG" || reader == "UGA")
                    Is_stop_codon = true;
            }
            else
            {
                if(Is_stop_codon)
                {
                    codons[i/2].AminoAcid = '*';
                    i++;
                    strcpy(codons[i/2].value,reader.c_str());
                    Is_stop_codon = false;
                }
                else
                codons[i/2].AminoAcid = reader[0];
            }
            i++;
        }
    }
    codons_data.close();

}
Codon CodonsTable::getAminoAcid(char * value) 
{
    for(int i = 0 ;i < 64; i++)
    {
		bool x = true;
		for (int j = 0; j < 3; j++)
		{

			if (codons[i].value[j] != value[j])
				x = false;
			if (!x)
				break;
		}
		if (x)
			return codons[i];
    }
    return codons[56];
}
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    codons[index].AminoAcid = AminoAcid;
    strcpy(codons[index].value,value);
}
CodonsTable::~CodonsTable()
{
    //dtor
}
