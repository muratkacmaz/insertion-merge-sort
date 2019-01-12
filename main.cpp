
/* @Author
* Student Name:Murat Kaçmaz
* Student ID : 150140052
* Date:  */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <ctime>

using namespace std;

class Card{
	private:	
		string Name ;
		string Class ;
		string Rarity;
		string Set;
		string Type;
		int Cost ;
	public:
		friend class CardManager;
		Card(){ };
		Card(string, string , string , string , string ,int);
		~Card(){ };	
};

Card::Card(string name, string clas, string rarity, string set, string type, int cost){
	Name = name;
	Class = clas ;
	Rarity = rarity;
	Set = set;
	Type = type ;
	Cost = cost;
}


class CardManager {
	public :
	
		void writeToFile (vector<Card>&,string);
		vector<Card> fullSort(vector<Card>&,string);
		vector<Card> filterSort(vector<Card>&,string);
	 	vector<Card> insertionSort(vector<Card>&,string);
		vector<Card> mergeSort(vector<Card>&,int,int,string);
		void merge(vector<Card>&,int,int,int,string);
		
};
int c=0;
void CardManager::merge(vector<Card>& objs,int l,int m ,int h,string member)
{
	if(member=="Type")
	{
		int i, j, k;
	    int n1 = m - l + 1;
    	int n2 =  h - m;
  
	   
    	Card* L = new Card[n1+1];
 		Card* H = new Card[n2+1];
     
    	for (i = 0; i < n1; i++)
    	{
    		L[i] = objs[l + i];
		}
        
    	for (j = 0; j < n2; j++)
		{
    		H[j] = objs[m + 1+ j];
 
		}
    	L[n1].Type = "ÿ";
   		H[n2].Type = "ÿ";
    
    	i = 0; 
    	j = 0; 
    	k = l; 
    	while (i < n1 && j < n2)
    	{	
    	    if (strcmp(L[i].Type.c_str(),H[j].Type.c_str()) <=0)
    	    {
    	        objs[k] = L[i];
    	        i++;
    	    }
    	    else
    	    {
    	        objs[k] = H[j];
    	        j++;
    	    }
    	    k++;
		}
	}
	
	else if (member=="Class")
	{	
		int i, j, k;
	    int n1 = m - l + 1;
    	int n2 =  h - m;
 
	   
    	Card* L = new Card[n1+1];
 		Card* H = new Card[n2+1];
     
    	for (i = 0; i < n1; i++)
    	{
    		L[i] = objs[l + i];
		}
        
    	for (j = 0; j < n2; j++)
		{
    		H[j] = objs[m + 1+ j];
 
		}
    	L[n1].Class = "ÿ";
   		H[n2].Class = "ÿ";
    
    	i = 0; 
    	j = 0; 
    	k = l; 
    	while (i < n1 && j < n2)
    	{	
    	    if (strcmp(L[i].Class.c_str(),H[j].Class.c_str()) <=0)
    	    {
    	    	if(strcmp(L[i].Class.c_str(),H[j].Class.c_str())==0)
    	    	{
    	    		if(L[i].Cost==H[j].Cost)
    	    		{
    	    			if(strcmp(L[i].Name.c_str(),H[j].Name.c_str()) ==0)
    	    			{
    	    				objs[k] = L[i];
    	        			i++;
						}
						else if(strcmp(L[i].Name.c_str(),H[j].Name.c_str()) <0)
						{
							objs[k] = L[i];
    	        			i++;
						}
						else
						{
							objs[k] = H[j];
    	        			j++;
						}
					}
					else if(L[i].Cost< H[j].Cost)
					{
						objs[k] = L[i];
    	        		i++;
					}
					else
					{
						objs[k] = H[j];
    	        		j++;
					}
				}
				else
				{
					objs[k] = L[i];
    	        	i++;	
				}
    	        
    	    }
    	    else
    	    {	
    	        objs[k] = H[j];
    	        j++;
    	    }
    	    k++;
		}
		
	}
}
vector<Card> CardManager::mergeSort(vector<Card>& objs,int l ,int h,string member)
{	
	if(member=="Type")
	{
		if(l<h)
		{
			int m = (l+h)/2;
			mergeSort(objs, l, m,"Type");
        	mergeSort(objs, m+1, h,"Type");
	        merge(objs, l, m, h,"Type");
		}
	}
	else if(member=="Class")
	{
			int m = (l+h)/2;
			mergeSort(objs, l, m,"Type");
        	mergeSort(objs, m+1, h,"Type");
	        merge(objs, l, m, h,"Type");
	}
	return objs;
}

vector<Card> CardManager::insertionSort(vector<Card>& objs,string member)
{
	Card temp ;
	int size = objs.size();

	
	if(member=="Type")
	{	 
		for(int i = 1; i < size; i++)
		{
			temp = objs[i];
			int move = i ;
			while((move>0)&& strcmp(objs[move-1].Type.c_str(),temp.Type.c_str())>0)
			{
				objs[move]=objs[move-1];
				move--;
				
			}
			objs[move]=temp;
		}	
	}
	
	else
	{ 
		int i,j;
		
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && strcmp(objs[j-1].Class.c_str(),objs[j].Class.c_str())>=0) {
            if(strcmp(objs[j-1].Class.c_str(),objs[j].Class.c_str())==0)
            {
            	if(objs[j-1].Cost == objs[j].Cost)
            	{	
            		if(strcmp(objs[j-1].Name.c_str(),objs[j].Name.c_str())==0)
            		{
            			break;
					}
            		else if(strcmp(objs[j-1].Name.c_str(),objs[j].Name.c_str())>0)
            		{
            			temp = objs[j];
           		 		objs[j] = objs[j - 1];
            			objs[j - 1] = temp;
           		 		j--;
					}
					else break;
				}
				else if(objs[j-1].Cost > objs[j].Cost)
				{
					temp = objs[j];
           		 	objs[j] = objs[j - 1];
            		objs[j - 1] = temp;
           		 	j--;
				}
				else break;
				
			}
			else
			{
				temp = objs[j];
            	objs[j] = objs[j - 1];
            	objs[j - 1] = temp;
            	j--;
			}
		
        }
    }
		
	}	
	return objs;
} 

vector<Card> CardManager:: filterSort(vector<Card>& objs,string IorM){
	int size = objs.size();
	
	if(IorM=="-i")
	{
		objs= insertionSort(objs,"Type");
	}
	else if (IorM=="-m")
	{
		 mergeSort(objs,0,size-1,"Type");
	}
	return objs;
}

vector<Card> CardManager :: fullSort(vector<Card>& objs,string IorM){
	int size = objs.size();
	
	if(IorM=="-i")
	{
		objs= insertionSort(objs,"Class");
	}
	else if (IorM=="-m")
	{
		mergeSort(objs,0,size-1,"Class");
	}
	return objs;
}


void CardManager::writeToFile(vector<Card>& objs,string file){
	int size = objs.size();
	ofstream writing;
	writing.open((file.c_str()));
	
	for(int i = 0; i<size;i++)
	{	
			writing << objs[i].Name << "\t"  << objs[i].Class << "\t"  << objs[i].Rarity << "\t"  << objs[i].Set << "\t"  << objs[i].Type << "\t"  << objs[i].Cost << endl ;
	}
	
}

int main(int argc, char *argv[]) {
	vector<Card> object_array;
	CardManager cm;
	string n,c,r,s,t,cos;
 
	ifstream fileRead;
	fileRead.open(argv[3]);
	string lineRead ;
	while(getline(fileRead,lineRead))
	{	
		istringstream iss(lineRead);
		
		getline(iss,n,'\t');
		getline(iss,c,'\t');
		getline(iss,r,'\t');
		getline(iss,s,'\t');
		getline(iss,t,'\t');	
		getline(iss,cos,'\n');
		
		int real_cost = atoi(cos.c_str());
		
		Card newHeartstone(n,c,r,s,t,real_cost);
		object_array.push_back(newHeartstone);
	}
	
	if(strcmp(argv[1],"-filter")==0)
	{	
		clock_t begin = clock();
		object_array = cm.filterSort(object_array,argv[2]);
		clock_t end = clock();
  		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  		cout << "Time elapsed : " << elapsed_secs <<endl; 
	}
	else if(strcmp(argv[1],"-full")==0)
	{
		clock_t begin = clock();
		object_array = cm.fullSort(object_array,argv[2]);
	 	clock_t end = clock();
  		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  		cout << "Time elapsed : " << elapsed_secs  <<endl; 
	}
	

	cm.writeToFile(object_array,argv[4]);
 
	
 	return 0;
}



//m.exe –full –i hs–set–10k.txt hs–set–10k-fuKK.txt
 //–filter –i hs–set–10k.txt hs–set–10k-full.txt
