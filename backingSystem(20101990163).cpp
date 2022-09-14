
#include <bits/stdc++.h>
#include <fstream>
#include <typeinfo>
#include <cstdlib>
using namespace std;



class user{
	public:
	string uName;
	long long int uPhone;
	string uAddress;
	string uMail;
};

class customer:public user{
	public:
		string custID;
		long long int custBal;
};

class employee: public user{
	public:
		string empID;
		string password;
};

class transaction{
	public:
		string transID;
		int tAmount;
		string tDate;
		int custID;
};

int main()
{
	while(true)
	{
		int check;
		cout<<"Please Enter \n1 for Customer \n2 for Employee"<<endl;
		cin>>check;
		if(check==1)
		{
			while(true)
			{
				int val;
				cout<<"Enter Operation to perform \n1.Create Account \n2.Perform Operation"<<endl;
				cin>>val;
				if(val==1)
				{
					int countCheck;
					cout<<"enter number of account to create : "<<endl;
					cin>>countCheck;
					customer li[countCheck];
					
					for(int i=0;i<countCheck;i++)
					{
						
						
						string name1,add,mail,userid,custid;
						long long int ph,initBal;
				      	
				        cout<<"Enter your name: ";
				        cin.ignore();
				        getline(cin,name1);
				        
				        cout<<"Enter your phone: ";
				        cin.ignore();
				        cin>>ph;
				        
				        cout<<"Enter your initial Balance: ";
				        cin>>initBal;
				        
				        cout<<"Enter your address: ";
				        cin.ignore();
				        getline(cin,add);
				        
				        cout<<"Enter your mail: ";
				        getline(cin,mail);
				        
				        cout<<"Enter your CustID: ";
				        getline(cin,custid);
								
						
						
						li[i].custID=custid;
						li[i].uName=name1;
						li[i].uAddress=add;
						li[i].uPhone=ph;
						li[i].custBal=initBal;
						li[i].uMail=mail;
						
										
					  	cout<<"---------------********-------------"<<endl;
					  	cout<<"    Account  Created    "<<endl;
					  	cout<<"---------------********--------------"<<endl<<endl;
					  	
					}
					
					ofstream customerData;
	  				customerData.open ("customerData.txt", ios::app);
					for(int i=0;i<countCheck;i++)
					{
						string ans=li[i].custID+","+li[i].uName +","+to_string(li[i].custBal)+","+to_string(li[i].uPhone)+","+li[i].uAddress+","+li[i].uMail+"\n";
						customerData<<ans;
						ans="";
					}
					customerData.close();
					customerData.flush();
				}
				else if(val==2)
				{
					string checker_id;
		    		cin.ignore();
		    		cout<<"Enter custid: "<<endl;
		    		cin>>checker_id;
		    		
		    		fstream getCustomerData;
		    		getCustomerData.open("customerData.txt",ios::in);
		    		if(getCustomerData.is_open())
					{
		    		  	string getData;
		    		  	int flag=0;
		    		  	vector<vector<string>> lis;
		    		  	while(getline(getCustomerData, getData))
						{
		    		  		vector<string> lis1;
		    		  		string word="";
		    		  		int count=0;
		    		  		for(int i=0;i<getData.length();i++)
		    		  		{
		    		  			if(getData[i]==',')
		    					{
		    						lis1.push_back(word);
		    						word="";
		    					}	
		    					else
		    					{
		    						word+=getData[i];
		    					}
		    				}
		    				lis1.push_back(word);
		    				lis.push_back(lis1);
		    			}
		    			for(int i=0;i<lis.size();i++)
		    			{
		    				if(lis[i][0]==checker_id)
		    				{
		    					flag=1;
		    					int val3;
		    					while(true)
								{
		                            cout<<"Enter Operation to perform \n1.Check Balance \n2.Make Transanction \n3.Check your details"<<endl;
		    					    cin>>val3;
		    					    srand((unsigned) time(NULL));
		    					    switch(val3)
									{
			    					    case 1:{
			    					        cout<<"Account Balance: "<<lis[i][2]<<endl;
			    					        break;
			    					    }
			    					    case 2:
										{
											int random = rand();
			    					        int tid=random;
			    					        cout<<"Enter transId: ";
			    					        cout<<tid<<endl;
			    					        
			    					        long long int amount;
			    					        cout<<"Enter amount to withdraw: ";
			    					        cin.ignore();
			    					        cin>>amount;
			    					        long long int bank_amount=stoi(lis[i][2]);
			    					        
			    					        if(amount<=bank_amount)
											{
			    					            cout<<"\nTransanction ID: "<<"#"<<tid<<endl;
			    					            time_t t = time(0);
			                                    tm* now = localtime(&t);
			                                    string date=to_string((now->tm_year+1900))+'-'+to_string((now->tm_mon+1))+'-'+to_string(now->tm_mday);
			                                    long long int new_balance=bank_amount-amount;
			                                    lis[i][2]=to_string(new_balance);
			                                    cout<<"Transanction Date: "<<date;
			                                    cout<<"\nAccount Balance: "<<new_balance<<endl;
			    					            
			    					            ofstream transactionData;
			                        		  	transactionData.open ("transactionData.txt", ios::app);
			                        		  	
			                        			string ans='#'+to_string(tid)+","+lis[i][0]+","+lis[i][1]+","+date+","+to_string(amount)+","+to_string(new_balance)+"\n";
			                        			transactionData<<ans;
			                        			tid++;
			                        			ans="";
			                        			
			                        		  	cout<<"---------------********-------------"<<endl;
											  	cout<<"    Successful Transaction    "<<endl;
											  	cout<<"---------------********--------------"<<endl<<endl;
											  	
			                        		  	transactionData.close();
			    					        }
											else
											{
			    					            cout<<"Not enough Balance"<<endl;
			    					        }
			    					        break;
			    					    }
			    					    case 3:
										{
			    					        cout<<"\nName: "<<lis[i][1]<<endl;
			    					        cout<<"Phone: "<<lis[i][3]<<endl;
			    					        cout<<"Address: "<<lis[i][4]<<endl;
			    					        cout<<"Mail: "<<lis[i][5]<<endl;
			    					    }
		    						}
		    						cout<<"1. want to continue :"<<endl;
		    						int check_application;
		    						cin>>check_application;
		    						if(check_application==1)
		    						{
		    							continue;
									}
									else
									{
										ofstream customerData;
										customerData.open ("customerData.txt", ios::trunc);
										customerData.close();
						  				customerData.open ("customerData.txt", ios::app);
										for(int i=0;i<lis.size();i++)
										{
											string ans=lis[i][0]+","+lis[i][1] +","+lis[i][2]+","+lis[i][3]+","+lis[i][4]+","+lis[i][5]+"\n";
											customerData<<ans;
											ans="";
										}
										customerData.close();
										customerData.flush();
										break;
									}
		    					}
		    				}
						}
		    		}
				}
				
				
				
				
				
				
				
				int ele;
				cout<<"1 go back to customer operations"<<endl;
				cin>>ele;
				if(ele==1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else if(check==2)
		{
			while(true)
			{
				int ex;
				cin.ignore();
				cout<<"\nEnter Operation to perform \n1.Create Employee Account \n2.Perform Employee Operation"<<endl;
				cin>>ex;
				if(ex==1)
				{
					
					int ecountCheck;
					cout<<"enter number of account to create : "<<endl;
					cin>>ecountCheck;
					employee eli[ecountCheck];
					
					
					for(int i=0;i<ecountCheck;i++)
					{
						string name1,add,mail,empid,password;
				      	long int ph;
				        cout<<"Enter your name: ";
				        cin.ignore();
				        getline(cin,name1);
				        
				        cout<<"Enter your phone: ";
				        cin.ignore();
				        cin>>ph;
				        
				        cout<<"Enter your address: ";
				        cin.ignore();
				        getline(cin,add);
				        
				        cout<<"Enter your mail: ";
				        getline(cin,mail);
				        
				        cout<<"Enter your EmpID: ";
				        getline(cin,empid);
				        
				        cout<<"Enter your password: ";
				        getline(cin,password);
						
						
						eli[i].empID=empid;
						eli[i].uName=name1;
						eli[i].uAddress=add;
						eli[i].uPhone=ph;
						eli[i].uMail=mail;
						eli[i].password=password;
										
					  	cout<<"---------------********-------------"<<endl;
					  	cout<<"   Employee Account  Created    "<<endl;
					  	cout<<"---------------********--------------"<<endl<<endl;
					  	
					}
					
			        ofstream employeeData;
	  				employeeData.open ("employeeData.txt", ios::app);
					for(int i=0;i<ecountCheck;i++)
					{
						string ans=eli[i].empID+","+eli[i].uName +","+to_string(eli[i].uPhone)+","+eli[i].uAddress+","+eli[i].uMail+","+eli[i].password+"\n";
						employeeData<<ans;
						ans="";
					}
					employeeData.close();
					employeeData.flush();
			        
			        
			        
				}
				else if(ex==2)
				{
					string echecker_id;
		    		cin.ignore();
		    		cout<<"Enter empId: "<<endl;
		    		cin>>echecker_id;
		    		
		    		string echecker_pass;
		    		cout<<"Enter empPass: "<<endl;
		    		cin>>echecker_pass;
		    		
		    		
		    		
		    		
		    		fstream getEmployeeData;
		    		getEmployeeData.open("employeeData.txt",ios::in);
		    		if(getEmployeeData.is_open())
					{
		    		  	string egetData;
		    		  	int flag=0;
		    		  	vector<vector<string>> elis;
		    		  	while(getline(getEmployeeData, egetData))
						{
		    		  		vector<string> elis1;
		    		  		string word="";
		    		  		int count=0;
		    		  		for(int i=0;i<egetData.length();i++)
		    		  		{
		    		  			if(egetData[i]==',')
		    					{
		    						elis1.push_back(word);
		    						word="";
		    					}	
		    					else
		    					{
		    						word+=egetData[i];
		    					}
		    				}
		    				elis1.push_back(word);
		    				elis.push_back(elis1);
		    			}
		    			for(int i=0;i<elis.size();i++)
		    			{
		    				if(elis[i][0]==echecker_id)
		    				{
		    					if(elis[i][5]==echecker_pass)
		    					{
		    						int eval3;
		    						cout<<"Enter Operation to perform \n1.Check Customer Date \n2.Check Transaction Date \n3.Update Customer Data \n4.Check Interest"<<endl;
		    					    cin>>eval3;
		    					    switch(eval3)
									{
										case 1:
										{
											fstream getCustomerData;
								    		getCustomerData.open("customerData.txt",ios::in);
								    		if(getCustomerData.is_open())
											{
								    		  	string getData;
								    		  	int flag=0;
								    		  	vector<vector<string>> lis;
								    		  	while(getline(getCustomerData, getData))
												{
								    		  		vector<string> lis1;
								    		  		string word="";
								    		  		int count=0;
								    		  		for(int i=0;i<getData.length();i++)
								    		  		{
								    		  			if(getData[i]==',')
								    					{
								    						lis1.push_back(word);
								    						word="";
								    					}	
								    					else
								    					{
								    						word+=getData[i];
								    					}
								    				}
								    				lis1.push_back(word);
								    				lis.push_back(lis1);
								    			}
								    			
								    			for(int i=0;i<lis.size();i++)
									    		{
									    			cout<<"Id : "<<lis[i][0]<<endl;
									    			cout<<"Name : "<<lis[i][1]<<endl;
									    			cout<<"Balance : "<<lis[i][2]<<endl;
									    			cout<<"Phone : "<<lis[i][3]<<endl;
									    			cout<<"Address : "<<lis[i][4]<<endl;
									    			cout<<"Email : "<<lis[i][5]<<endl<<endl;
									    		}
								    		}
								    	
											break;
										}
										case 2:
										{
											fstream getTransactionData;
								    		getTransactionData.open("transactionData.txt",ios::in);
								    		if(getTransactionData.is_open())
											{
								    		  	string getData;
								    		  	int flag=0;
								    		  	vector<vector<string>> lis;
								    		  	while(getline(getTransactionData, getData))
												{
								    		  		vector<string> lis1;
								    		  		string word="";
								    		  		int count=0;
								    		  		for(int i=0;i<getData.length();i++)
								    		  		{
								    		  			if(getData[i]==',')
								    					{
								    						lis1.push_back(word);
								    						word="";
								    					}	
								    					else
								    					{
								    						word+=getData[i];
								    					}
								    				}
								    				lis1.push_back(word);
								    				lis.push_back(lis1);
								    			}
								    			
								    			for(int i=0;i<lis.size();i++)
									    		{
									    			cout<<"Transaction Id : "<<lis[i][0]<<endl;
									    			cout<<"Customer Id : "<<lis[i][1]<<endl;
									    			cout<<"Date : "<<lis[i][3]<<endl;
									    			cout<<"Amount deducted : "<<lis[i][4]<<endl;
									    			cout<<"Balance : "<<lis[i][5]<<endl<<endl;
									    		}
								    		}
										}
										case 3:
										{
											fstream getCustomerData;
								    		getCustomerData.open("customerData.txt",ios::in);
								    		if(getCustomerData.is_open())
											{
								    		  	string getData;
								    		  	int flag=0;
								    		  	vector<vector<string>> lis;
								    		  	while(getline(getCustomerData, getData))
												{
								    		  		vector<string> lis1;
								    		  		string word="";
								    		  		int count=0;
								    		  		for(int i=0;i<getData.length();i++)
								    		  		{
								    		  			if(getData[i]==',')
								    					{
								    						lis1.push_back(word);
								    						word="";
								    					}	
								    					else
								    					{
								    						word+=getData[i];
								    					}
								    				}
								    				lis1.push_back(word);
								    				lis.push_back(lis1);
								    			}
								    			
									    		while(true)
									    		{
									    			int change_data_emp;
						    						cout<<"Enter Operation to perform \n1.Change Customer Name \n2.Check Customer Address"<<endl;
						    					    cin>>change_data_emp;
						    					    
												    if(change_data_emp==1)
												    {
												    	string change_cust_id;
												    	cout<<"Enter User id to change Name: "<<endl;
												    	cin>>change_cust_id;
												    	int flag=0;
												    	for(int i=0;i<lis.size();i++)
												    	{
															
												    		if(stoi(lis[i][0])==stoi(change_cust_id))
												    		{
												    			string new_name;
													    		cout<<"Enter Name: "<<endl;
													    		cin.ignore();
													    		getline(cin,new_name);
												    			lis[i][1]=new_name;
												    			cout<<"Name updated"<<endl;
												    			flag=1;
												    			break;
															}
														}
														if(flag==0)
														{
															cout<<"wrong id added"<<endl;
														}
													}
													else if(change_data_emp==2)
												    {
												    	string change_cust_id;
												    	cout<<"Enter User id to change Address: "<<endl;
												    	cin>>change_cust_id;
												    	int flag=0;
												    	for(int i=0;i<lis.size();i++)
												    	{
															
												    		if(stoi(lis[i][0])==stoi(change_cust_id))
												    		{
												    			string new_address;
													    		cout<<"Enter Address: "<<endl;
													    		cin.ignore();
													    		getline(cin,new_address);
												    			lis[i][4]=new_address;
												    			cout<<"Address updated"<<endl;
												    			flag=1;
												    			break;
															}
														}
														if(flag==0)
														{
															cout<<"wrong id added"<<endl;
														}
													}
													int ele;
													cout<<"1 go back to choose to update"<<endl;
													cin>>ele;
													if(ele==1)
													{
														continue;
													}
													else
													{
														break;
													}
												}
												
												ofstream customerData;
												customerData.open ("customerData.txt", ios::trunc);
												customerData.close();
								  				customerData.open ("customerData.txt", ios::app);
												for(int i=0;i<lis.size();i++)
												{
													string ans=lis[i][0]+","+lis[i][1] +","+lis[i][2]+","+lis[i][3]+","+lis[i][4]+","+lis[i][5]+"\n";
													customerData<<ans;
													ans="";
												}
												customerData.close();
												customerData.flush();
								    		}
											break;
										}
										case 4:
										{
											cout<<"not completed"<<endl;
										}
									}
								}
		    				}
						}
		    		}
				}
				
				
				
				
				
				
				int ele;
				cout<<"1 go back to employee operations"<<endl;
				cin>>ele;
				if(ele==1)
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		int ele;
		cout<<"1 go back to back options"<<endl;
		cin>>ele;
		if(ele==1)
		{
			continue;
		}
		else
		{
			cout<<"thank you for choosing our back"<<endl;
			break;
		}
	}
	return 0;
}
