#include <bits/stdc++.h>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
using namespace std;

Sequence* BioData[100];
int index = 0;

string out = "1- Enter Data (>>) \n2- Perform a conversion \n3- Display Data (<<) \n4- Save to File  \n5- Load From File \n6- Concatenate (+) \n7- Equal (==) \n8- Not Equal (!=) \n9- Align \n10- Get DNA strands Encoding \n0- END \n";


void load_data_from_file();
void enter_data_to_file();
void print_only_DNA();
void print_only_RNA();
void print_only_Protein();

int main()
{
	short choice;

	while (cout << out && cin >> choice && choice)
	{
		if (choice == 1)
		{
			cout << "1- DNA \n2- RNA \n3- Protein \n";
			short choice1_1;
			cin >> choice1_1;
			if (choice1_1 == 1)
			{
				DNA d;
				cin >> d;
			}
			else if (choice1_1 == 2)
			{
				RNA r;
				cin >> r;
			}
			else if (choice1_1 == 3)
			{
				Protein p;
				cin >> p;
			}
		}
		else if (choice == 2)
		{
			short choice_2;
			cout << "1- Convert DNA to RNA \n2- Convert RNA to DNA \n3- Convert RNA to Protein \n4- Build DNA Complementary \n";
			cin >> choice_2;
			if (choice_2 == 1 || choice_2 == 4)
			{
				print_only_DNA();
				cout << "Enter The No. of RNA :";
				int D_Index;
				cin >> D_Index;
				D_Index--;
				if (choice_2 == 1)
				{
					Sequence* obj;
					obj = ((DNA*)BioData[D_Index])->ConvertToRNA();
					BioData[D_Index] = new RNA;
					BioData[D_Index] = obj;

				}
				else if (choice_2 == 4)
				{
					((DNA*)BioData[D_Index])->BuildComplementaryStrand();
				}

			}
			if (choice_2 == 2)
			{
				print_only_RNA();
				cout << "Enter The No. of RNA :";
				int R_Index;
				cin >> R_Index;
				R_Index--;
				BioData[R_Index];
				Sequence* obj;
				obj = ((RNA*)BioData[R_Index])->ConvertToDNA();
				BioData[R_Index] = new DNA;
				BioData[R_Index] = obj;
			}
			if (choice_2 == 3)
			{
				print_only_RNA();
				cout << "Enter The No. of RNA :";
				int R_Index;
				cin >> R_Index;
				R_Index--;
				Sequence* obj;
				CodonsTable T("RNA_codon_table.txt");
				obj = ((RNA*)BioData[R_Index])->ConvertToProtein(T);
				BioData[R_Index] = new Protein;
				BioData[R_Index] = obj;
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < index; i++)
				BioData[i]->Print(), cout << endl;
		}
		else if (choice == 4)
		{
		enter_data_to_file();
		}
		else if (choice == 5)
		{
		load_data_from_file();
		}
		else if (choice == 6 || choice == 7 || choice == 8)
		{
			short choice_3;
			cout << "1- DNA \n2- RNA \n3- Protein \n";
			cin >> choice_3;
			if (choice_3 == 1)
			{
				print_only_DNA();
				cout << "Enter Two Numbers of DNAs :";
				int index_1 , index_2;
				cin >> index_1 >> index_2;
				index_1--; index_2--;

				string x, y;
				for (int i = 0; i < strlen(BioData[index_1]->get_sequence()); i++)
					x += BioData[index_1]->get_sequence()[i];
				for (int i = 0; i < strlen(BioData[index_2]->get_sequence()); i++)
					y += BioData[index_2]->get_sequence()[i];

				char* Fstring = new char[x.length()+1];
				char* Sstring = new char[y.length()+1];

				for (int i = 0; i < x.length(); i++)
				{
					Fstring[i] = x[i];
					Fstring[i + 1] = '\0';
				}
				for (int i = 0; i < y.length(); i++)
				{
					Sstring[i] = y[i];
					Sstring[i + 1] = '\0';
				}
				DNA_Type my_type = ((DNA*)BioData[index_1])->get_type();
				DNA First(Fstring, my_type);
				DNA Second(Sstring, my_type);
				if (choice == 6)
				{
					BioData[index++] = new DNA(First + Second);
				}
				else if (choice == 7)
				{
					bool equal = (First == Second);
					cout << ((equal) ? "True : Equal\n" : "False : NotEqual\n");
				}
				else if (choice == 8)
				{
					bool NotEqual = (First != Second);
					cout << ((NotEqual) ? "True : NotEqual\n" : "False : Equal\n");
				}


			}
			if (choice_3 == 2)
			{
			    print_only_RNA();
				cout << "Enter Two Numbers of RNAs :";
				int index_1 , index_2;
				cin >> index_1 >> index_2;
				index_1--; index_2--;

				string x, y;
				for (int i = 0; i < strlen(BioData[index_1]->get_sequence()); i++)
					x += BioData[index_1]->get_sequence()[i];
				for (int i = 0; i < strlen(BioData[index_2]->get_sequence()); i++)
					y += BioData[index_2]->get_sequence()[i];

				char* Fstring = new char[x.length()+1];
				char* Sstring = new char[y.length()+1];

				for (int i = 0; i < x.length(); i++)
				{
					Fstring[i] = x[i];
					Fstring[i + 1] = '\0';
				}
				for (int i = 0; i < y.length(); i++)
				{
					Sstring[i] = y[i];
					Sstring[i + 1] = '\0';
				}
				RNA_Type my_type = ((RNA*)BioData[index_1])->get_type();
				RNA First(Fstring, my_type);
				RNA Second(Sstring, my_type);
				if (choice == 6)
				{
					BioData[index++] = new RNA(First + Second);
				}
				else if (choice == 7)
				{
					bool equal = (First == Second);
					cout << ((equal) ? "True : Equal\n" : "False : NotEqual\n");
				}
				else if (choice == 8)
				{
					bool NotEqual = (First != Second);
					cout << ((NotEqual) ? "True : NotEqual\n" : "False : Equal\n");
				}

			}
			if (choice_3 == 3)
            {
                print_only_Protein();
				cout << "Enter Two Numbers of Proteins:";
				int index_1 , index_2;
				cin >> index_1 >> index_2;
				index_1--; index_2--;

				string x, y;
				for (int i = 0; i < strlen(BioData[index_1]->get_sequence()); i++)
					x += BioData[index_1]->get_sequence()[i];
				for (int i = 0; i < strlen(BioData[index_2]->get_sequence()); i++)
					y += BioData[index_2]->get_sequence()[i];

				char* Fstring = new char[x.length()+1];
				char* Sstring = new char[y.length()+1];

				for (int i = 0; i < x.length(); i++)
				{
					Fstring[i] = x[i];
					Fstring[i + 1] = '\0';
				}
				for (int i = 0; i < y.length(); i++)
				{
					Sstring[i] = y[i];
					Sstring[i + 1] = '\0';
				}
				Protein_Type my_type = ((Protein*)BioData[index_1])->get_type();
				Protein First(Fstring, my_type);
				Protein Second(Sstring, my_type);
				if (choice == 6)
				{
					BioData[index++] = new Protein(First + Second);
				}
				else if (choice == 7)
				{
					bool equal = (First == Second);
					cout << ((equal) ? "True : Equal\n" : "False : NotEqual\n");
				}
				else if (choice == 8)
				{
					bool NotEqual = (First != Second);
					cout << ((NotEqual) ? "True : NotEqual\n" : "False : Equal\n");
				}

            }
		}
		else if (choice == 9)
		{
			short choice_9;
			cout << "1- DNA \n2- RNA \n3- Protein \n";
			cin >> choice_9;
			if (choice_9 == 1)
			{
				print_only_DNA();
				cout << "Enter Two Numbers of DNAs :";
				int index_1, index_2;
				cin >> index_1 >> index_2;
				index_1--; index_2--;
				cout << "Longest Common Subsequence : ";
				cout << Align(BioData[index_1], BioData[index_2]) << endl;
			}
		}
		else if (choice == 10)
		{
			print_only_Protein();
			cout << "Enter The No. of Protein :";
			int P_Index;
			cin >> P_Index;
			P_Index--;

			print_only_DNA();
			cout << "Enter The No. of DNA :";
			int D_Index;
			cin >> D_Index;
			D_Index--;

			DNA_Type my_type = ((DNA*)BioData[D_Index])->get_type();
			char * n = new char(strlen(BioData[D_Index]->get_sequence()));
			strcpy(n, BioData[D_Index]->get_sequence());
			DNA First(n, my_type);
			DNA* Strands = ((Protein*)BioData[P_Index])->GetDNAStrandsEncodingMe(First);
			for (int i=0 ; true ; i++)
            {
                if (Strands[i].get_sequence() == nullptr)
                    break;
                Strands[i].Print();
            }

		}
		cout << endl;
		system("PAUSE");
		system("CLS");
	}
	return 0;
}



istream & operator>>(istream & in, DNA enter)
{
	bool Done = false;
	string seq;
	while(!Done)
	{
		try
		{
			cout << "Enter DNA" << endl;
			cin >> seq;
			string error = "DNA Sequence must have only letters { A, C, G, T }\n";
			for (int i = 0; i < seq.length(); i++)
			{
				seq[i] = toupper(seq[i]);
				if (seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'T')
					throw error;
			}
			Done = true;
		}
		catch (string x)
		{
			cout << x;
		}
	}
	char* mySeq = new char[seq.length()];
	for (int i = 0; i < seq.length(); i++)
		mySeq[i] = seq[i], mySeq[i + 1] = '\0';
	cout << "Enter DNA Type : \n";
	DNA_Type type;
	cout << "1- promoter \n2- motif \n3- tail \n4- noncoding \n";
	int type_choice;
	cin >> type_choice;
	if (type_choice == 1)
		type = promoter;
	else if (type_choice == 2)
		type = motif;
	else if (type_choice == 3)
		type = tail;
	else if (type_choice == 4)
		type = noncoding;
	BioData[index++] = new DNA(mySeq, type);
	return in;
}

istream & operator>>(istream & in, RNA enter)
{
	bool Done = false;
	string seq;
	while (!Done)
	{
		try
		{
			cout << "Enter RNA" << endl;
			cin >> seq;
			string error = "RNA Sequence must have only letters { A, C, G, U }\n";
			for (int i = 0; i < seq.length(); i++)
			{
				seq[i] = toupper(seq[i]);
				if (seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'U')
					throw error;
			}
			Done = true;
		}
		catch (string x)
		{
			cout << x;
		}
	}
	char* mySeq = new char[seq.length()];
	for (int i = 0; i < seq.length(); i++)
		mySeq[i] = seq[i], mySeq[i + 1] = '\0';
	cout << "Enter RNA Type : \n";
	RNA_Type type;
	cout << "1- mRNA \n2- pre_mRNA \n3- mRNA_exon \n4- mRNA_intron \n";
	int type_choice;
	cin >> type_choice;
	if (type_choice == 1)
		type = mRNA;
	else if (type_choice == 2)
		type = pre_mRNA;
	else if (type_choice == 3)
		type = mRNA_exon;
	else if (type_choice == 4)
		type = mRNA_intron;
	BioData[index++] = new RNA(mySeq, type);
	return in;
}

istream & operator>>(istream & in, Protein enter)
{
	bool Done = false;
	string seq;
	while (!Done)
	{
		try
		{
			cout << "Enter Protein" << endl;
			cin >> seq;
			string error = "Invalid Protein Characters\n";
			for (int i = 0; i < seq.length(); i++)
			{
				seq[i] = toupper(seq[i]);
				if (seq[i]>='A' && seq[i]<='Z')
					if (seq[i] == 'B' || seq[i] == 'J' || seq[i] == 'O' ||
						seq[i] == 'U' || seq[i] == 'X' || seq[i] == 'Z'  )
							throw error;
			}
			Done = true;
		}
		catch (string x)
		{
			cout << x;
		}
	}
	char* mySeq = new char[seq.length()];
	for (int i = 0; i < seq.length(); i++)
		mySeq[i] = seq[i], mySeq[i + 1] = '\0';
	cout << "Enter Protein Type : \n";
	Protein_Type type;

	cout << "1- Hormon \n2- Enzyme \n3- TF \n4- Cellular_Function \n";
	int type_choice;
	cin >> type_choice;
	if (type_choice == 1)
		type = Hormon;
	else if (type_choice == 2)
		type = Enzyme;
	else if (type_choice == 3)
		type = TF;
	else if (type_choice == 4)
		type = Cellular_Function;
	BioData[index++] = new Protein(mySeq, type);
	return in;
}

void load_data_from_file()
{
	string file;
	cout << "Enter File Name :";
	cin.ignore();
	getline(cin, file);
	file += ".txt";
	ifstream my_file;
	my_file.open(file);
	if (!my_file)
	{
		cout << "Opening Error !\n";
		return;
	}
	if (my_file.eof()) cout << "Warning : File 1 is empty !" << endl;

	enum Current_Type_of_Sequence { dna, rna, protein };
	Current_Type_of_Sequence TOS = dna;

	while (!my_file.eof())
	{
		string sequence;
		my_file >> sequence;
		if (sequence == "DNA") { TOS = dna; continue; }
		if (sequence == "RNA") { TOS = rna; continue; }
		if (sequence == "Protein") { TOS = protein; continue; }

		int num;
		my_file >> num;

		char* mySeq = new char[sequence.length()];
		for (int i = 0; i < sequence.length(); i++)
			mySeq[i] = sequence[i], mySeq[i + 1] = '\0';

		if (TOS == dna)
		{
			DNA_Type D_Type;
			if (num == 1) D_Type = promoter;
			else if (num == 2) D_Type = motif;
			else if (num == 3) D_Type = tail;
			else if (num == 4) D_Type = noncoding;
			BioData[index++] = new DNA(mySeq, D_Type);
		}
		else if (TOS == rna)
		{

			RNA_Type R_Type;
			if (num == 1) R_Type = mRNA;
			else if (num == 2) R_Type = pre_mRNA;
			else if (num == 3) R_Type = mRNA_exon;
			else if (num == 4) R_Type = mRNA_intron;
			BioData[index++] = new RNA(mySeq, R_Type);
		}
		else if (TOS == protein)
		{

		}
	}
	my_file.close();
}

void enter_data_to_file()
{
	char filename[80];
	double arr1[200], counter = 0;
	cout << "Enter The File Name : ";
	cin.ignore();
	cin.getline(filename, 80);
	strcat(filename, ".txt");
	ofstream myfile;
	myfile.open(filename);
	if (!myfile) cout << "opening error !";
	else
	{
		myfile << "DNA";
		myfile << "\n";
		map<int, string> DNA_map;  DNA_map[0] = "Promoter\n";  DNA_map[1] = "Motif\n";  DNA_map[2] = "Tail\n";  DNA_map[3] = "NonCoding\n";
		map<int, string> RNA_map;  RNA_map[0] = "mRNA\n";  RNA_map[1] = "pre_mRNA\n";  RNA_map[2] = "mRNA_exon\n";  RNA_map[3] = "mRNA_intron\n";

		for (int i = 0; i < index; i++)
		{
			Sequence* pointer = dynamic_cast<DNA *> (BioData[i]);
			if (pointer != nullptr)
				myfile << ((DNA*)BioData[i])->get_sequence() << " " << DNA_map[((DNA*)BioData[i])->get_type()];
		}
		myfile << "RNA";
		myfile << "\n";
		for (int i = 0; i < index; i++)
		{
			Sequence* pointer = dynamic_cast<RNA *> (BioData[i]);
			if (pointer != nullptr)
				myfile << ((RNA*)BioData[i])->get_sequence() << " " << RNA_map[((RNA*)BioData[i])->get_type()];
		}
	}
	cin.clear();
	myfile.close();
}

void print_only_DNA()
{
	for (int i = 0; i < index; i++)
	{
		Sequence* pointer = nullptr;
		pointer = dynamic_cast<DNA *> (BioData[i]);
		if (pointer != nullptr)
		{
			cout << i + 1 << " ",
				BioData[i]->Print();
		}
	}
}

void print_only_RNA()
{
	for (int i = 0; i < index; i++)
	{
		Sequence* pointer = nullptr;
		pointer = dynamic_cast<RNA *> (BioData[i]);
		if (pointer != nullptr)
		{
			cout << i + 1 << " ",
				BioData[i]->Print();
		}
	}
}

void print_only_Protein()
{
	for (int i = 0; i < index; i++)
	{
		Sequence* pointer = nullptr;
		pointer = dynamic_cast<Protein *> (BioData[i]);
		if (pointer != nullptr)
		{
			cout << i + 1 << " ",
				BioData[i]->Print();
		}
	}
}
