#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<exception>
#include<algorithm>
#include<map>
#include "classification.h"
using namespace std;

classification cls1,cls2,cls3,cls4;
void classification::ClassificationRead(string fname1,string fname2,string fname3,string fname4)
{
	ifstream inf1(fname1.c_str());
	if(!inf1){
		cerr<<fname1<<" Not available"<<endl;
		exit(0);
	}
	else{
		
			int row = 0;
		    string csvLine, val;
		    double dval;
		    while (inf1) {
		        getline(inf1, csvLine);
		        istringstream  stream(csvLine);
		        cls1.ClassData.resize(row+1);
		     	while(getline(stream, val, ',')) { 
					dval = atof(val.c_str());
					cls1.ClassData[row].push_back(dval); 
		    	}
		        row++;		       
		    }
		    if(cls1.ClassData[cls1.ClassData.size()-1].size() == 0) {
				cls1.ClassData.resize(cls1.ClassData.size()-1);
			}
			cout<<fname1<<" read successfully"<<endl;
	}
	ifstream inf2(fname2.c_str());
	if(!inf2){
		cerr<<fname2<<" Not available"<<endl;
		exit(0);
	}
	else{
			int row = 0;
		    string csvLine, val;
		    double dval;
		    while (inf2) {
		        getline(inf2, csvLine);
		        istringstream  stream(csvLine);
		        cls2.ClassData.resize(row+1);
		     	while(getline(stream, val, ',')) { 
					dval = atof(val.c_str());
					cls2.ClassData[row].push_back(dval); 
		    	}
		        row++;		       
		    }
		    if(cls2.ClassData[cls2.ClassData.size()-1].size() == 0) {
				cls2.ClassData.resize(cls2.ClassData.size()-1);
			}
			cout<<fname2<<" read successfully"<<endl;
	}
	ifstream inf3(fname3.c_str());
	if(!inf3){
		cerr<<fname3<<" Not available"<<endl;
		exit(0);
	}
	else{
			int row = 0;
		    string csvLine, val;
		    double dval;
		    while (inf3) {
		        getline(inf3, csvLine);
		        istringstream  stream(csvLine);
		        cls3.ClassData.resize(row+1);
		     	while(getline(stream, val, ',')) { 
					dval = atof(val.c_str());
					cls3.ClassData[row].push_back(dval); 
		    	}
		        row++;		       
		    }
		    if(cls3.ClassData[cls3.ClassData.size()-1].size() == 0) {
				cls3.ClassData.resize(cls3.ClassData.size()-1);
			}
			cout<<fname3<<" read successfully"<<endl;
	}
	ifstream inf4(fname4.c_str());
	if(!inf4){
		cerr<<fname4<<" Not available"<<endl;
		exit(0);
	}
	else{
			int row = 0;
		    string csvLine, val;
		    double dval;
		    while (inf4) {
		        getline(inf4, csvLine);
		        istringstream  stream(csvLine);
		        cls4.ClassData.resize(row+1);
		     	while(getline(stream, val, ',')) { 
					dval = atof(val.c_str());
					cls4.ClassData[row].push_back(dval); 
		    	}
		        row++;		       
		    }
		    if(cls4.ClassData[cls4.ClassData.size()-1].size() == 0) {
				cls4.ClassData.resize(cls4.ClassData.size()-1);
			}
			cout<<fname4<<" read successfully"<<endl;
	}
}
void classification::PrintFiles()
{
	cout<<"\t\t\t================================================"<<endl<<endl;
	for( int i=0; i<cls1.ClassData.size(); i++) {
				
				
				for(int j=0; j<cls1.ClassData[i].size(); j++) {
				//	cout << data[i][j] <<"|";	 
				if(cls1.ClassData[i][j]<0)
					cout<<"|"<<setiosflags(ios::fixed)<<setprecision(4)<<cls1.ClassData[i][j];
				else
					cout<<"| "<<setiosflags(ios::fixed)<<setprecision(4)<<cls1.ClassData[i][j];
				}
			cout<<endl;
			}	
	cout<<"\t\t\t================================================"<<endl<<endl;
	for( int i=0; i<cls2.ClassData.size(); i++) {
				
				
				for(int j=0; j<cls2.ClassData[i].size(); j++) {
				//	cout << data[i][j] <<"|";	 
				if(cls2.ClassData[i][j]<0)
					cout<<"|"<<setiosflags(ios::fixed)<<setprecision(4)<<cls2.ClassData[i][j];
				else
					cout<<"| "<<setiosflags(ios::fixed)<<setprecision(4)<<cls2.ClassData[i][j];
				}
			cout<<endl;
			}	
	cout<<"\t\t\t================================================"<<endl<<endl;
	for( int i=0; i<cls3.ClassData.size(); i++) {
				
				
				for(int j=0; j<cls3.ClassData[i].size(); j++) {
				//	cout << data[i][j] <<"|";	 
				if(cls3.ClassData[i][j]<0)
					cout<<"|"<<setiosflags(ios::fixed)<<setprecision(4)<<cls3.ClassData[i][j];
				else
					cout<<"| "<<setiosflags(ios::fixed)<<setprecision(4)<<cls3.ClassData[i][j];
				}
			cout<<endl;
			}	
			
	cout<<"\t\t\t================================================"<<endl<<endl;
	for( int i=0; i<cls4.ClassData.size(); i++) {
				
				
				for(int j=0; j<cls4.ClassData[i].size(); j++) {
				//	cout << data[i][j] <<"|";	 
				if(cls4.ClassData[i][j]<0)
					cout<<"|"<<setiosflags(ios::fixed)<<setprecision(4)<<cls4.ClassData[i][j];
				else
					cout<<"| "<<setiosflags(ios::fixed)<<setprecision(4)<<cls4.ClassData[i][j];
				}
			cout<<endl;
			}	
}
void classification::checkvalidations()
{
	int Data_col,Learning_Data_col,Learning_Data_Rows,Learning_Data_Labels_Rows;
	Data_col=cls1.ClassData[0].size();
	Learning_Data_col = cls3.ClassData[0].size();
	Learning_Data_Rows = cls3.ClassData.size();
	Learning_Data_Labels_Rows = cls4.ClassData.size();
	if(Data_col == Learning_Data_col)
	{
		cout<<"Colomns of Data And Learning Data are same"<<endl;
	}
	else
	{
		cout<<"Colomns Does Not Match"<<endl;	
	}
	if(Learning_Data_Rows == Learning_Data_Labels_Rows)
	{
		cout<<"Rows of Learning Data And Learning Data Labels Match..."<<endl;
	}
	else
	{
		cout<<"Rows Does Not Match.."<<endl;
	}
	if(!cls4.ClassData[0].size()==1)
	{
		cout<<"Learning Data Labels Has More then one Row"<<endl;
	}
	else
	{
		cout<<"Condition Match..Learning Data Labes Has one Row"<<endl;
	}		
}
int classification::classificationAlgo(int k)
{
		vector<vector<double> > data_labels;
		int acc=0;
		int accuracy ; 
if(k>cls3.ClassData.size())
{
throw string("Invalid k");
}
else
{
	//=============step 2(A)of classification Algorithm========//
	int row=0,col=0;
	double distance;long double temp1;
	map<double, unsigned int> my_map;			         //using Map In Order to Finding the Closest Distance ...
	vector<double> my_vec;								//MY_VECTOR in order to populate Sorted Data
	vector<int> temp;								   //temporary Vector 
	vector<vector<double> > learning_data_label_vec;   //temorary vector for Learning Data Labels file
	
	data_labels.resize(cls1.ClassData.size());			
	for(int x = 0 ; x<cls1.ClassData.size();x++)     // Main Loop ---  DO NOT GET OUT OF IT.... until the finding the value of K...
	{	
		my_vec.clear(); 							//clearing vector Everytime
		my_map.clear();								//clearing vector Everytime
		for(row=0;row<cls3.ClassData.size();row++)
		{
			temp1=0;								//temp1 : for Calculatin of Euclidian Distance
			for(col=0;col<cls3.ClassData[0].size();col++)
			{
				temp1 += pow((cls1.ClassData[x][col] - cls3.ClassData[row][col]),2);	
			}
			distance = sqrt(temp1);
			my_map.insert(pair<double, unsigned int>(distance , row));
		}												
		map<double, unsigned int>::iterator it=my_map.begin();
		for (int j=0; j<k ; j++)
 			{
 				my_vec.resize(j);
 				double temp2;							//temp2 : temp2 in order to store ROW Number of sorted Data.
		 		temp2 = it->second;
		 		it++;
		 		my_vec.push_back(temp2);									
			 }
			learning_data_label_vec.clear();
			learning_data_label_vec.resize(k);
				for(int b=0;b<learning_data_label_vec.size();b++)
				{
					int temp4;
					temp4 = cls4.ClassData[my_vec[b]][0];
					learning_data_label_vec[b].push_back(temp4); 
					
				}
				temp.clear();
		
			//==== step 2(B) learing data labels=====//
				for(int b=0;b<learning_data_label_vec.size();b++)
				{
					temp.push_back(learning_data_label_vec[b][0]);
				}
			//==== step 2(C) learing data labels=====//
				int max = 0;
				int max_val;
				for(int b=0;b < temp.size() ; b++)
				{	
					 if(max<count(temp.begin(),temp.end(),temp[b])){
						max = count(temp.begin(),temp.end(),temp[b]);
						max_val = temp[b];
					}
					else if(max == count(temp.begin(),temp.end(),temp[b]) && rand() % 100 > 50)
					{
						max = count(temp.begin(),temp.end(),temp[b]);
						max_val = temp[b];
					}		
				}
			//==== step 2(D) learing data labels=====//
				data_labels[x].push_back(max_val);
	}	
}
for(int a=0 ; a<data_labels.size();a++)
{
	if(data_labels[a][0]==cls2.ClassData[a][0])
		{
			acc = acc + 1;
		}	
}
accuracy = (100 * acc) / data_labels.size();       	
return accuracy ;
}

	
