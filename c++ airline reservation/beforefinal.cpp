#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<string.h>
#include<fstream>


using namespace std;

struct seat_data{
	string row;
	string type;
	string seats;
};//create structure array
int number_of_flights;

class flight{
	private:
		string flight_number;
		string date;
		string seats_available;
		string departure, arrival;
		string row,type,seats;//private variables
		
		
		
	public:
		struct seat_data arr[60];
		void insert_flight(string );
		string put_flight();
		
		void insert_date(string );
		string put_date();
		
		void arrival_airport(string );
		string put_arrival();
		
		void departure_airport(string );
		string put_departure();//public variables
		
		
		
};
//end of the flight class
void flight::insert_flight(string flight_number)
{
			this->flight_number=flight_number;
			
		}

string flight:: put_flight()
		{
			return flight_number;
		}
void flight::insert_date(string date)
{
			this->date=date;
			
		}

string flight:: put_date()
		{
			return date;
		}
void flight::arrival_airport(string arrival)
{
			this->arrival=arrival;
			
		}

string flight:: put_arrival()
		{
			return arrival;
		}
void flight::departure_airport(string departure)
{
			this->departure=departure;
			
		}

string flight:: put_departure()
		{
			return departure;
		}
		
		

int main()
{
	ofstream file3 ("Flights.dat");//crate data file to exit function
	
	//file reading for read object count
	string str;
        int c = 0;
        string line;
       ifstream file; 
       file.open("Flights.txt"); 
    
	// Check if object is valid
       if(!file.is_open()){
    	cout<<"cannot open the file"<<file<<endl;
    	return false;}
else{

    while (getline(file,line)) { 
         if(line.empty()){
         	c++;	//inceremt object count by 1
	 }
 
    
    } 
    } //****************************************** count OK
    
        file.close();//close the file
        flight f[c];
        ifstream file1; 
	file1.open("Flights.txt"); //again open the file
	//while()

  	int again_count=0;//get another count to read the row,type and seat letter
	int i=0;

	int object=0;
//	
	while(getline(file1,line))
	{
		again_count++;
		if(again_count==1)
		{
			f[object].insert_flight(line);//read the flight number
		}
		else if(again_count==2)
		{
			f[object].insert_date(line);//go to second line and read the date and time
		}
		else if(again_count==3)
		{
			f[object].arrival_airport(line);//then read the ariival airport
		}
		else if(again_count==4)
		{
			f[object].departure_airport(line);//read the departure airport
		}
		else 
		{
			if(line.empty())//in here i checked whether the line is empty or not
			{
				again_count=0;//if line is empty then increment the object and reset the again_count and the i
			
				object++;
				i=0;
				
			}
			else 
			{
				stringstream ss(line);
				ss>>f[object].arr[i].row>>f[object].arr[i].type>>f[object].arr[i].seats;
			
				i++;
			}
			
		}
		
		
	}
	/*int j,k;
	//cout<<f[4].arr[4].seats<<endl;
	for(j=0;j<c;j++)
	{
		f[j].put_flight();
		f[j].put_date();
		f[j].put_arrival();
		f[j].put_departure();
		
		for(k=0;k<60;k++)
		{
		if(f[j].arr[k].row!="\0")
			cout<<f[j].arr[k].row<<" "<<f[j].arr[k].type<<"  "<<f[j].arr[k].seats<<endl;
		else
		break;	
		}
		
	}*/
	
	int n,h;
	int m,p,count1=0;
	int Ecount=0;
	int Bcount=0;
	int flag=0,flag1=0,input_seat;
	string input_flight,input_srow;
	string str1;
	char input_sletter;
	//string str;
	do
	{
		cout << "\t\t-----------------------------\n";
		cout << "\n\t\t~-~-~-~-Virgin Airlines-~-~-~-~\n";
                cout << "\t\t-----------------------------\n";
		        cout << "\t1. Display available flights\n";
		        cout << "\t2. View flight list\n";
		        cout << "\t3. View Available flights\n";
		        cout << "\t4. Seat Booking\n";
		        cout << "\t5. Exit\n";
		        

		        cout << "Please Input Your Choice Number :-  ";
        		cin >> n;
        		cout<<endl;
		        switch (n)
                {
                    case 1:
                    		cout<<"---Display available flights in Virgin Airlines--- "<<endl;
                        	for(p=0;p<c;p++)
					{
					
						
						for(m=0;m<60;m++)
						{
						str1=f[p].arr[m].seats;
						
						if(f[p].arr[m].type=="E")
						{
							Ecount=Ecount+str1.size();//get the count of economics class seats
						}
						else
						{
							Bcount=Bcount+str1.size();//get the count of business class seats
						}
					}
						if(Ecount>=0 || Bcount>=0)//
						{
							
							cout<<"Flight Number   :"<<f[p].put_flight()<<endl;
							cout<<endl;
							cout<<"Departure Date & time   :"<<f[p].put_date()<<endl;
							cout<<"Arrival place   :"<<f[p].put_arrival()<<endl;
							cout<<"Departure place   :"<<f[p].put_departure()<<endl;
							cout<<"Available seats :business class->"<<Bcount<<endl;
							cout<<"Available seats :Economic class->"<<Ecount<<endl;
							cout<<endl;
							
							

							Ecount=0;
							Bcount=0;
							
					}
						else
						{	cout<<f[p].put_flight()<<endl;
							cout<<f[p].put_date()<<endl;
							cout<<f[p].put_arrival()<<endl;
							cout<<f[p].put_departure()<<endl;
							cout<<"Available seats :No available seats"<<endl; 
						
							
							}	
						
				
					}
			
			break;
		case 2:
			cout<<"-----View flight-----"<<endl;
			cout<<endl;
			cout<<"Enter the flight number  :"<<endl;
			cin>>input_flight;
			
			for(p=0;p<c;p++)
			{
			
				if(f[p].put_flight()==input_flight)
				{
					flag=1;
					cout<<"Flight is found"<<endl;
					for(m=0;m<60;m++)
					{
						str1=f[p].arr[m].seats;
						str1=f[p].arr[m].row;
						str1=f[p].arr[m].type;
						
						if(f[p].arr[m].type=="E")
						{
							Ecount=Ecount+str1.size();
						}
						else
						{
							Bcount=Bcount+str1.size();
						}
					}
					                cout<<"Flight Number   :"<<f[p].put_flight()<<endl;
							cout<<endl;
							cout<<"Departure Date & time   :"<<f[p].put_date()<<endl;
							cout<<"Arrival place   :"<<f[p].put_arrival()<<endl;
							cout<<"Departure place   :"<<f[p].put_departure()<<endl;
							cout<<"Available seats :business class->"<<Bcount<<endl;
							cout<<"Available seats :Economic class->"<<Ecount<<endl;
							cout<<endl;
					for(m=0;m<60;m++)
					{
						cout<<"    "<<f[p].arr[m].row<<"   "<<f[p].arr[m].type<<"    "<<f[p].arr[m].seats<<endl;
						
						if(f[p].arr[m].row=="\0")
						{
							break;
						}
					}
					cout<<endl;
					Ecount=0;
					Bcount=0;
				}
			}
						if(flag==0)
						{
							cout<<"flight is not found"<<endl;
						}
			break;			
					
				
			case 3:
			
				cout<<"------Seats Availability-----"<<endl;
				cout<<"Enter the flight number   :"<<endl;
				cin>>input_flight;
				cout<<"Enter Number of seats that you want to book  :"<<endl;
				cin>>input_seat;
				
				for(p=0;p<c;p++)
				{
					for(m=0;m<60;m++)
					{
					
					 str1=f[p].arr[m].seats;
						if(f[p].arr[m].type=="E")
						{
							Ecount=Ecount+str1.size();
						}
						else
						{
							Bcount=Bcount+str1.size();
						}
					}
				
				if(f[p].put_flight()==input_flight)
				{
					if((Ecount+Bcount) >= input_seat)
					{
						cout<<"seats available  "<<endl;
							cout<<"Available seats :business class->"<<Bcount<<endl;
							cout<<"Available seats :Economic class->"<<Ecount<<endl;
							cout<<endl;
						
					}
					else
					{
						cout<<"No any available seats "<<endl;
					}
				}
				Ecount=0;
				Bcount=0;
			}
			break;
			
			case 4:
				cout<<"-----Seat Booking-----"<<endl;
				cout<<"Enter the flight number   :"<<endl;
				cin>>input_flight;
				cout<<"Enter the row number of seat  :"<<endl;
				cin>>input_srow;
				cout<<"Enter the letter of the seat  :"<<endl;
				cin>>input_sletter;
				
				
				for(p=0;p<c;p++)
				{
					if(f[p].put_flight()==input_flight)
					{
						for(m=0;m<60;m++)
						{
							if(f[p].arr[m].row==input_srow)
							{
								flag=1;
								for(h=0;h<f[p].arr[m].seats.length();h++)
								{
									if(f[p].arr[m].seats[h]==input_sletter)
									{
										flag1=1;
										f[p].arr[m].seats.erase(h,1);
										cout<<"Your seat has booked"<<endl;
									}
									
									
								}
								
							}
						}
					}
				}
				if(flag==0||flag1==0)
				{
					cout<<"This row hasn't a seat like this'"<<endl;
				}
				break;
			case 5:	
				cout<<"------Exit-----"<<endl;
				for(int y=0;y<c;y++)
				{
					file3<<f[y].put_flight()<<endl;
					file3<<f[y].put_date()<<endl;
					file3<<f[y].put_arrival()<<endl;
					file3<<f[y].put_departure()<<endl;
					
					for(int w=0;w<60;w++)
					{
							file3<<"    "<<f[y].arr[w].row<<"   "<<f[y].arr[w].type<<"    "<<f[y].arr[w].seats<<endl;
							if(f[y].arr[w].row=="\0")
							{
								file3<<endl;
							}
					}
				}
				cout<<"Thank you for dealing with us"<<endl;
				cout<<"Have a safe flight"<<endl;
				break;
				
			default:
				cout<<"Invalid option, Please check the Menu & Enter the valid option"<<endl;
				
				
				
			
			        
                    
	    
}
}while(n!=5);

}
	    

		
	























































