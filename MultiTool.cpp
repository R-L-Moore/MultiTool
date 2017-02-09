#include <iostream>
#include <iomanip>
#include <string>

void displayMenu()
{
	std::cout << "Menu options : " << std::endl;
	std::cout << "==================" << std::endl;
	std::cout << "1) KB conversion (Remote)" << std::endl;
	std::cout << "2) autoPing (Remote)" << std::endl;
	std::cout << "3) processKill (Remote)" << std::endl;
	std::cout << "4) Offline files fix (Local)" << std::endl;
	std::cout << "5) Exit" << std::endl;
}

double conversion(int i)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	double result = i / 1000.0;
	return result;
}

void autoPing(std::string address)
{
	bool pinging = true;
	char decision;
	
	std::string pingStr = "ping -n 6 " + address;
	
	while (pinging)
	{
		system(pingStr.c_str());
		std::cout << "\n Do you want to continue pinging? (y/n) : ";
		std::cin >> decision;
		
		system("cls");
		
		if (decision == 'n')
		{
			pinging = false;
		}
		else
		{
			pinging = true;
		}
	}
}

void processKill()
{
	std::string target = "";
	std::cout << "Enter the computer name : ";
	std::cin >> target;
	
	std::string process = "";
	std::cout << "Enter the process name : ";
	std::cin >> process;
	
	std::string username = "";
	std::cout << "Enter your admin account : ";
	std::cin >> username;
	
	std::string killStr = "taskkill /S " + target 
	                    + " /U " + username 
						+ " /FI " + "\"IMAGENAME eq " 
						+ process + "\"";
	
	system(killStr.c_str());	
}

void offlineFiles()
{
	char decision;
	
	std::string offlineStr = "REG ADD HKLM\\SYSTEM\\CurrentControlSet\\services\\CSC\\Parameters /f /v FormatDatabase /t REG_DWORD /d 1";
	system(offlineStr.c_str());
	std::cout << "\n The computer must be restarted for this change to take effect";
	std::cout << "\n Do you want to restart the computer now? (y/n): ";
	std::cin >> decision;
	
	if(decision == 'y' || decision == 'Y')
	{
		std::cout << "\n Ensure all programs are saved/closed, and ";
		system("pause");
		std::cout << "\n If you continue, the computer will restart in 10 seconds" << std::endl;
		std::cout << " To cancel this, and return to the menu, enter 'n' : ";
		std::cin >> decision;
		
		if(decision == 'y' || decision == 'Y')
		{
			std::cout << "shutting down..." << std::endl;
			//system("shutdown /R /t 10");
		}
	}
	
}

int main()
{
	system("TITLE MultiTool");

	int kb;
	int choice = 152658945;
	bool running = true;
	std::string address = "";
	
	while (running)
	{
		displayMenu();
		std::cout << "\n Enter a value to make a selection : ";
		std::cin >> choice;
		
		switch (choice)
		{
			case 1:
				system("cls");
				system("TITLE MultiTool - KB conversion");
				
				std::cout << "KB conversion: " << std::endl;
				std::cout << "=====================" << std::endl;
				std::cout << "\n Enter a value to convert : ";	  	  	  	  
				std::cin >> kb;
				
				if (conversion(kb) >= 1000)	 	 
				{
					std::cout << kb << "kb is equal to " << conversion(conversion(kb)) << "gb" << std::endl;
				}
				
				else
				{
					std::cout << kb << "kb is equal to " << conversion(kb) << "mb" << std::endl;	
				}
				
				system("pause");
				system("cls");
				system("TITLE MultiTool");
				break;
				
			case 2:
				system("cls");
				system("TITLE MultiTool - AutoPing");
				
				std::cout << "AutoPing: " << std::endl;
				std::cout << "=====================" << std::endl;
				std::cout << "\n Enter a computer name or IP address to ping : ";
				std::cin >> address;
				
				autoPing (address);
				
				system("cls");
				system("TITLE MultiTool");
				break;
			
			case 3:
				system("cls");
				system("TITLE MultiTool - processKill");
				
				std::cout << "processKill: " << std::endl;
				std::cout << "=====================" << std::endl;
				
				std::cout << "WARNING : Running this can cause your admin account to be locked out" << std::endl;
				
				char decision;
				std::cout << "Do you want to run this process? (y/n) : ";
				std::cin >> decision;
				
				if (decision == 'n')
				{
					system("cls");
					system("TITLE MultiTool");
					break;
				}
				else
				{
					system("cls");
					processKill();
				}
				
				system("pause");
				system("cls");
				system("TITLE MultiTool");
				break;
				
			case 4:
				system("cls");
				system("TITLE MultiTool - Offline Files Fix");
				
				std::cout << "Offline Files Fix: " << std::endl;
				std::cout << "=====================" << std::endl;
				
				offlineFiles();
				
				system("pause");
				system("cls");
				system("TITLE MultiTool");
				break;
			
			case 5:
				system("cls");
				running = false;
				std::cout << "Exiting..." << std::endl;
				system("pause");
				system("cls");
				break;
			
			default:
				system("cls");
				running = false;
				std::cout << "Exiting..." << std::endl;
				system("pause");
				system("cls");
				break;
		}
	}
		
	return 0;
}

