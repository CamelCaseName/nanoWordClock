// nanoWordClock.cpp : Defines the entry point for the application.
//

#include "nanoWordClock.h"

using namespace std;

/*
const char words[80] = {
	'I','T','S','F','I','V','E','T',
	'E','N','Q','U','A','R','T','E',
	'R','T','O','H','A','L','F','T',
	'O','P','A','S','T','O','N','E',
	'T','W','O','T','H','R','E','E',
	'F','O','U','R','F','I','V','E',
	'S','I','X','S','E','V','E','N',
	'E','I','G','H','T','N','I','N',
	'E','T','E','N','E','L','E','V',
	'E','N','T','W','E','L','V','E'
};

	'I','T','S','F','I','V','E','T',
	'E','N','Q','U','A','R','T','E',
	'R','T','O','H','A','L','F','T',
	'O','P','A','S','T','O','N','E',
	'T','W','O','T','H','R','E','E',
	'F','O','U','R','F','I','V','E',
	'S','I','X','S','E','V','E','N',
	'E','I','G','H','T','N','I','N',
	'E','T','E','N','E','L','E','V',
	'E','N','T','W','E','L','V','E'
*/

int main() {
	cout << "please specify the port to use" << endl;

	std::string strtmp = "";

	std::getline(std::cin, strtmp); //get port
	const char* port = strtmp.c_str(); //convert
	char* white = new char[1];
	white[0] = 3;
	char* red = new char[1];
	white[0] = 0;
	char* cyan = new char[1];
	white[0] = 7;

	//open serial port
	try {
		std::ofstream of(port);

		//poll current time
		auto temptime = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(temptime);
		std::tm* tmtime = localtime(&time);
		uint8_t oldhours = tmtime->tm_hour % 12;
		uint8_t oldmins = tmtime->tm_min;

		while (true) {
			//poll time every 10 seconds
			temptime = std::chrono::system_clock::now();
			time = std::chrono::system_clock::to_time_t(temptime);
			tmtime = localtime(&time);
			
			//send minutes
			if (tmtime->tm_min - oldmins > 0) {
				if (tmtime->tm_min > 5){//FIVE PAST *hour
					if (tmtime->tm_min > 10) {//TEN PAST *hour
						if (tmtime->tm_min > 15) {//QUARTER PAST *hour
							if (tmtime->tm_min > 20) {//TWENTY PAST *hour
								if (tmtime->tm_min > 25) {//TWENTYFIVE PAST *hour
									if (tmtime->tm_min > 30) {//HALF PAST *hour
										if (tmtime->tm_min > 35) {//TWENTYFIVE TO *hour
											if (tmtime->tm_min > 40) {//TWENTY TO *hour
												if (tmtime->tm_min > 45) {//QUARTER TO *hour
													if (tmtime->tm_min > 50) {//TEN TO *hour
														if (tmtime->tm_min > 50) {//FIVE TO *hour
															of.write(white, 1);
															of << "ITS";
															of.write(red, 1); 
															of << "FIVE";
															of.write(cyan, 1); 
															of << "TENQUARTERTOHALF";
															of.write(white, 1); 
															of << "TO";
															of.write(cyan, 1);
															of << "PAST"; //3+4+3+7+2+4+2+4 = 29
															//cout of.write(white, 1); << "ITS" of.write(red, 1); << "FIVE" of.write(cyan, 1); << "TENQUARTERTOHALF" of.write(white, 1); << "TO" of.write(cyan, 1); << "PAST"; //3+4+3+7+2+4+2+4 = 29
														}
														else {
															of.write(white, 1); 
															of << "ITS";
															of.write(cyan, 1);
															of << "FIVE";
															of.write(red, 1);
															of << "TEN";
															of.write(cyan, 1); 
															of << "QUARTERTOHALF";
															of.write(white, 1); 
															of << "TO";
															of.write(cyan, 1);
															of << "PAST"; //3+4+3+7+2+4+2+4 = 29
															//cout of.write(white, 1); << "ITS" of.write(cyan, 1); << "FIVE" of.write(red, 1); << "TEN" of.write(cyan, 1); << "QUARTERTOHALF" of.write(white, 1); << "TO" of.write(cyan, 1); << "PAST"; //3+4+3+7+2+4+2+4 = 29
														}
													}
													else {
														of.write(white, 1); 
														of << "ITS";
															of.write(cyan, 1); 
														of << "FIVETEN";
															of.write(red, 1); 
														of << "QUARTER";
															of.write(cyan, 1);
														of << "TOHALF";
															of.write(white, 1); 
														of << "TO";
															of.write(cyan, 1); 
														of << "PAST"; //3+4+3+7+2+4+2+4 = 29
														//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETEN";of.write(red, 1); of << "QUARTER";of.write(cyan, 1); of << "TOHALF";of.write(white, 1); of << "TO";of.write(cyan, 1); of << "PAST"; //3+4+3+7+2+4+2+4 = 29
													}
												}
												else {
													of.write(white, 1); 
													of << "ITS";
													of.write(cyan, 1);
													of << "FIVETENQ";
													of.write(red, 1); 
													of << "TWENTY";
													of.write(cyan, 1); 
													of << "TOHALF";
													of.write(white, 1); 
													of << "TO";
													of.write(cyan, 1); 
													of << "PAST"; // = 29
													//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETENQ";of.write(red, 1); of << "TWENTY";of.write(cyan, 1); of << "TOHALF";of.write(white, 1); of << "TO";of.write(cyan, 1); of << "PAST"; // = 29
												}
											}
											else {
												of.write(white, 1); 
												of << "ITS";
												of.write(cyan, 1);
												of << "TENQ";
												of.write(red, 1);
												of << "TWENTYFIVE";
												of.write(cyan, 1); 
												of << "TOHALF";
												of.write(white, 1);
												of << "TO";
												of.write(cyan, 1); 
												of << "PAST"; // = 29
												//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "TENQ";of.write(red, 1); of << "TWENTYFIVE";of.write(cyan, 1); of << "TOHALF";of.write(white, 1); of << "TO";of.write(cyan, 1); of << "PAST"; // = 29
											}
										}
										else {
											of.write(white, 1); 
											of << "ITS";
											of.write(cyan, 1); 
											of << "FIVETENQUARTERTO";
											of.write(red, 1); 
											of << "HALF";
											of.write(cyan, 1);
											of << "TO";
											of.write(white, 1); 
											of << "PAST";
											of.write(cyan, 1);; // = 29
											//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETENQUARTERTO";of.write(red, 1); of << "HALF";of.write(cyan, 1); of << "TO";of.write(white, 1); of << "PAST";of.write(cyan, 1);; // = 29
										}
									}
									else {
										of.write(white, 1); 
										of << "ITS";
										of.write(cyan, 1); 
										of << "TENQ";
										of.write(red, 1); 
										of << "TWENTYFIVE";
										of.write(cyan, 1); 
										of << "TOHALFTO";
										of.write(white, 1); 
										of << "PAST";
										of.write(cyan, 1);; // = 29
										//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "TENQ";of.write(red, 1); of << "TWENTYFIVE";of.write(cyan, 1); of << "TOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);; // = 29
									}
								}
								else {
									of.write(white, 1);
									of << "ITS";
									of.write(cyan, 1); 
									of << "FIVETENQ";
									of.write(red, 1); 
									of << "TWENTY";
									of.write(cyan, 1);
									of << "TOHALFTO";
									of.write(white, 1);
									of << "PAST";
									of.write(cyan, 1); // = 29
									//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETENQ";of.write(red, 1); of << "TWENTY";of.write(cyan, 1); of << "TOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);; // = 29
								}
							}
							else {
								of.write(white, 1);
								of << "ITS";
								of.write(cyan, 1);
								of << "FIVETEN";
								of.write(red, 1);
								of << "QUARTER";
								of.write(cyan, 1); 
								of << "TOHALFTO";
								of.write(white, 1); 
								of << "PAST";
								of.write(cyan, 1);
								//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETEN";of.write(red, 1); of << "QUARTER";of.write(cyan, 1); of << "TOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);;
							}
						}
						else {
							of.write(white, 1);
							of << "ITS";
							of.write(cyan, 1);
							of << "FIVE";
							of.write(red, 1); 
							of << "TEN";
							of.write(cyan, 1); 
							of << "QUARTERTOHALFTO";
							of.write(white, 1);
							of << "PAST";
							of.write(cyan, 1);
							//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVE";of.write(red, 1); of << "TEN";of.write(cyan, 1); of << "QUARTERTOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);;
						}
					}
					else {
						of.write(white, 1);
						of << "ITS";
						of.write(red, 1);
						of << "FIVE";
						of.write(cyan, 1); 
						of << "TENQUARTERTOHALFTO";
						of.write(white, 1); 
						of << "PAST";
						of.write(cyan, 1);
						//cout of.write(white, 1); of << "ITS";of.write(red, 1); of << "FIVE";of.write(cyan, 1); of << "TENQUARTERTOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);;
					}
				}
				else {
					of.write(white, 1); 
					of << "ITS";
					of.write(cyan, 1); 
					of << "FIVETENQUARTERTOHALFTOPAST";
					//cout of.write(white, 1); << "ITS";of.write(cyan, 1); << "FIVETENQUARTERTOHALFTOPAST";
				}
				of << "                                                  ";
			}

			//send hour stuff

			of << "\n";
			oldhours = tmtime->tm_hour % 12;
			oldmins = tmtime->tm_min;
			Sleep(10000);
		}
		//only close port when needed
		of.close();
	}
	catch (const std::exception&) {
		cout << "Wrong port" << endl;
	}
	return 0;
}


/*
ITS FIVETENQUART
ERHALF TOPASTONE
TWOTHREEFOURFIVE
SIXSEVENEIGHTNIN
ETENELEVENTWELVE
5*16=80 chars
*/