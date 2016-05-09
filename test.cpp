#include<iostream>
#include<string>
#include<exception>
#include "table.h"
#include "classification.h"
using namespace std;

int main()
{
	table tbl;
	classification cls;
	int select;
	main:
	cout<<"=============== Main Menu ============"<<endl;
	cout<<"Enter 1 for Table Class"<<endl;
	cout<<"Enter 2 for Classification Class"<<endl;
	cout<<"Enter 0 for Exit"<<endl;
	cout<<"=============== Main Menu ============"<<endl;
	cin>>select;
	if(select==1)
		{
			
			int rowno,colno;
			int choice;
			string filename;
			vector<double> addrow;
			vector<double> addcol;
			
			do{
			cout<<"\n";
			cout<<"==============Table Class::Please Enter Your Choice==============="<<endl;
			cout<<"1  . Read CSV file"<<endl;
			cout<<"2  . For Get the Average of Perticular Colomn:"<<endl;
			cout<<"3  . For Get the Corrected sample Standard Deviation of Colomn:"<<endl;
			cout<<"4  . For Get the Number of Rows in a Table:"<<endl;
			cout<<"5  . For Get the Number of Colomns in a Table:"<<endl;
			cout<<"6  . For Get the Value of Perticular Cell:"<<endl;
			cout<<"7  . For Change the value of Perticular Cell::"<<endl;
			cout<<"8  . For the Data Standardization"<<endl;
			cout<<"9  . For Remove the Specific Row From the table:"<<endl;
			cout<<"10 . For Remove the Specific Colomn From the table:"<<endl;
			cout<<"11 . For Add the new Row"<<endl;
			cout<<"12 . For Add the new Colomn"<<endl;
			cout<<"13 . For Overload the operator '<<'"<<endl;
			cout<<"14 . For Exit"<<endl;
			cout<<"=================================================================="<<endl;
			cin>>choice;
			
			switch(choice)
			{
				case 1 :
					cout<<"ENTER FILE NAME::";
					//	cin>>filename;
					filename="Data.csv";				
					cout<<"Read Sccessfully";
					tbl.CSVreadData(filename);
					break;		
				case 2 :
					double avg;
					try{
					cout<<"Enter Colomn No : "<<endl;
					cin>>colno;
					avg = tbl.CSVavg(colno);				
					cout<<"Average of Colomn No :: "<<colno<<" is "<<avg<<endl;
					}
					catch(string e){
						cout<<e;
					}
					
					break;
				case 3 :
					try{
					double std_dev;
					cout<<"Enter Colomn No : "<<endl;
					cin>>colno;	
					std_dev = tbl.CSVstd_dev(colno);
					cout<<"Corrected Standerd Daviation of Colomn "<<colno<<" is "<<std_dev<<endl;
					}
					catch(string e)
					{
						cout<<e;
					}
				
					break;
				case 4 : 
					cout<<"There are "<<tbl.CSVNoRows()<<" rows in a Table"<<endl;
					break;
				case 5:
					cout<<"There are "<<tbl.CSVNoCols()<<" colomns in a Table"<<endl;
					break;
				case 6:
					try{
					cout<<"Enter Row No:"<<endl;
					cin>>rowno;
					cout<<"Enter Col No:"<<endl;
					cin>>colno;
					cout<<"Value of CELL for Row:: "<<rowno<<" Col "<<colno<<" is "<<tbl.CSVcell(rowno,colno);
					}
					catch(string e)
					{
						cout<<e;
					}
					break;
				case 7:
					try{
						int row,col;
						double val;
						cout<<"Enter Row No:"<<endl;
						cin>>row;
						cout<<"Enter Col No:"<<endl;
						cin>>col;
						cout<<"Enter New Value::"<<endl;
						cin>>val;
						cout<<"New Value of Row: "<<row<<" Col: "<<col<<" is "<<tbl.CSVcellval(row,col,val);	
					}
					catch(string e)
					{
						cout<<e;
					}
				
					break;
				case 8:
					tbl.CSVdata_std();
					break;
				case 9 :
					try{
						cout<<"Enter Row No::";
						cin>>rowno;
						cout<<"Removed Row No: "<<tbl.CSVremove_row(rowno)+1<<endl;
					}
					catch(string e)
					{
						cout<<e;
					}
					
					break;
				case 10:
					try{
						cout<<"Enter Colomn No::";
						cin>>colno;
						cout<<"Removed Colomn Number:"<<tbl.CSVremove_col(colno)+1<<endl;
					}
					catch(string e)
					{
						cout<<e;
					}
					
					break;
				case 11:
					int i;
					double newval;
					cout<<"Enter " << tbl.CSVNoCols() << " Values For Adding Row "<<endl;
					do{
						cin>>newval;
						addrow.push_back(newval);
						i++;
					}while(i<tbl.CSVNoCols());
					tbl.CSVadd_row(addrow);
					break;
				case 12:
					int j;
					j=0;
					double newvalcol;
					cout<<"Enter " << tbl.CSVNoRows() << " Values For Adding Col "<<endl;
					do{
						cin>>newvalcol;
						addcol.push_back(newvalcol);
						j++;
					}while(j<=tbl.CSVNoRows());
					tbl.CSVadd_col(addcol);
					break;
				case 13:
					cout << tbl;
					break;
				case 14 :
					goto main;
				default : 
					cout<<"Enter Valid Choice";
					break;
			}
			}while(choice!=14);
	}
	else if(select==2)
	{
		int choice;
		string fname1,fname2,fname3,fname4;
		do{
		cout<<"==Classification::Please Enter Your Choice==="<<endl;
		cout<<"1 . For Read Files::"<<endl;
		cout<<"2 . For Finding Accuracy of K::"<<endl;
		cout<<"3 . For Exit::"<<endl;
		cout<<"Enter Choice:"<<endl;
		cout<<"============================================="<<endl;
		cin>>choice;
		switch(choice)
		{
			
			case 1 :
				cout<<"Reading Files"<<endl;
				fname1="Data.csv";
				fname2="Correct_Data_Labels.csv";
				fname3="Learning_Data.csv";
				fname4="Learning_Data_Labels.csv";
				try {
				
					cls.ClassificationRead(fname1,fname2,fname3,fname4);
					cls.checkvalidations();
				
				} catch (string e) {
					cout << e;
				}
				break;
			case 2 :
				int k;
				cout<<"Enter Value of K ::";
				cin>>k;
				try{
					int acc = cls.classificationAlgo(k);
					cout<<endl<<"********* ACCURACY FOR K="<<k<<" IS "<<acc<<" % **********"<<endl<<endl; 
				}
				catch(string e)
				{
					cout<< e <<endl;					
				}
				
			break;
			case 3 :
				goto main;
			default:
				cout<<"Enter Valid choice"<<endl;
		}
		}while(choice!=-1);
		
}
	return 0;
}
