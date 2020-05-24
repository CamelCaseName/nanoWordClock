// nanoWordClock.cpp : Defines the entry point for the application.
//

#include "nanoWordClock.h"

#pragma warning(disable : 4996)

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
*/
std::ofstream of;

//CSytemTray tray;

int main() {


	ShowWindow(GetConsoleWindow(), SW_SHOW);

	cout << "please specify the port to use" << endl;

	std::string strtmp = "";

	std::getline(std::cin, strtmp); //get port
	const char* port = strtmp.c_str(); //convert
	char* white = new char[1];
	white[0] = 3;
	char* red = new char[1];
	red[0] = 0;
	char* cyan = new char[1];
	cyan[0] = 7;
	char* clear = new char[1];
	clear[0] = 12;

	//open serial port
	try {
		//poll current time
		auto temptime = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(temptime);
		std::tm* tmtime;
		tmtime = localtime(&time);
		uint8_t oldhours = tmtime->tm_hour % 12 - 1;
		uint8_t oldmins = tmtime->tm_min - 1;

		of.open(port);

		Sleep(7000);

		cout << "Starting..." << endl;

		cout << "hiding window" << endl; 
		//tray.Create(hInstance, NULL, WM_MY_NOTIFY,"Click here", hIcon, nID);

		//static void MinimiseToTray(CWnd* GetConsoleWindow());

		//ShowWindow(GetConsoleWindow(), SW_HIDE);

		while (true) {

			/*
			for (char i = 0; i < 20; i++) {
				char* j = new char[1];
				j[0] = i;
				of.write(j, 1);
				of << "ABab" << endl;
				cout << j[0] << endl;
			}
			*/
			
			//poll time every 10 seconds
			temptime = std::chrono::system_clock::now();
			time = std::chrono::system_clock::to_time_t(temptime);
			localtime_s(tmtime, &time);
			
			//send minutes
			if (tmtime->tm_min - oldmins > 0 || tmtime->tm_min == 0) {

				//ShowWindow(GetConsoleWindow(), SW_SHOW);
				cout << "clearing screen..." << endl;
				//ShowWindow(GetConsoleWindow(), SW_HIDE);
				of.write(clear, 1);
				of.write(clear, 1);
				of.write(clear, 1);
				Sleep(5000);
				if (tmtime->tm_min >= 5) {//FIVE PAST *hour
					if (tmtime->tm_min >= 10) {//TEN PAST *hour
						if (tmtime->tm_min >= 15) {//QUARTER PAST *hour
							if (tmtime->tm_min >= 20) {//TWENTY PAST *hour
								if (tmtime->tm_min >= 25) {//TWENTYFIVE PAST *hour
									if (tmtime->tm_min >= 30) {//HALF PAST *hour
										if (tmtime->tm_min >= 35) {//TWENTYFIVE TO *hour
											if (tmtime->tm_min >= 40) {//TWENTY TO *hour
												if (tmtime->tm_min >= 45) {//QUARTER TO *hour
													if (tmtime->tm_min >= 50) {//TEN TO *hour
														if (tmtime->tm_min >= 55) {//FIVE TO *hour
															of.write(white, 1);
															of << "ITS" << endl;
															of.write(red, 1);
															of << "FIVE" << endl;
															Sleep(300);
															of.write(cyan, 1);
															of << "TENQUARTERTOHALF" << endl;
															Sleep(500);
															of.write(white, 1);
															of << "TO" << endl;
															of.write(cyan, 1);
															of << "PAST" << endl; //3+4+3+7+2+4+2+4 = 29
															//cout << ctime(&time) << endl;
															tmtime->tm_hour += 1;
															//cout of.write(white, 1); << "ITS" of.write(red, 1); << "FIVE" of.write(cyan, 1); << "TENQUARTERTOHALF" of.write(white, 1); << "TO" of.write(cyan, 1); << "PAST"; //3+4+3+7+2+4+2+4 = 29
														}
														else {
															of.write(white, 1);
															of << "ITS" << endl;
															of.write(cyan, 1);
															of << "FIVE" << endl;
															of.write(red, 1);
															of << "TEN" << endl;
															Sleep(500);
															of.write(cyan, 1);
															of << "QUARTERTOHALF" << endl;
															Sleep(300);
															of.write(white, 1);
															of << "TO" << endl;
															of.write(cyan, 1);
															of << "PAST" << endl; //3+4+3+7+2+4+2+4 = 29
															//cout << ctime(&time) << endl;
															tmtime->tm_hour += 1;
															//cout of.write(white, 1); << "ITS" of.write(cyan, 1); << "FIVE" of.write(red, 1); << "TEN" of.write(cyan, 1); << "QUARTERTOHALF" of.write(white, 1); << "TO" of.write(cyan, 1); << "PAST"; //3+4+3+7+2+4+2+4 = 29
														}
													}
													else {
														of.write(white, 1);
														of << "ITS" << endl;
														of.write(cyan, 1);
														of << "FIVETEN" << endl;
														of.write(red, 1);
														of << "QUARTER" << endl;
														Sleep(500);
														of.write(cyan, 1);
														of << "TOHALF" << endl;
														of.write(white, 1);
														of << "TO" << endl;
														of.write(cyan, 1);
														of << "PAST" << endl; //3+4+3+7+2+4+2+4 = 29
														//cout << ctime(&time) << endl;
														tmtime->tm_hour += 1;
														//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETEN";of.write(red, 1); of << "QUARTER";of.write(cyan, 1); of << "TOHALF";of.write(white, 1); of << "TO";of.write(cyan, 1); of << "PAST"; //3+4+3+7+2+4+2+4 = 29
													}
												}
												else {
													of.write(white, 1);
													of << "ITS" << endl;
													of.write(cyan, 1);
													of << "FIVETENQ" << endl;
													of.write(red, 1);
													of << "TWENTY" << endl;
													Sleep(500);
													of.write(cyan, 1);
													of << "TOHALF" << endl;
													of.write(white, 1);
													of << "TO" << endl;
													of.write(cyan, 1);
													of << "PAST" << endl; // = 29
													//cout << ctime(&time) << endl;
													tmtime->tm_hour += 1;
													//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETENQ";of.write(red, 1); of << "TWENTY";of.write(cyan, 1); of << "TOHALF";of.write(white, 1); of << "TO";of.write(cyan, 1); of << "PAST"; // = 29
												}
											}
											else {
												of.write(white, 1);
												of << "ITS" << endl;
												of.write(cyan, 1);
												of << "TENQ" << endl;
												of.write(red, 1);
												of << "TWENTYFIVE" << endl;
												Sleep(500);
												of.write(cyan, 1);
												of << "TOHALF" << endl;
												Sleep(500);
												of.write(white, 1);
												of << "TO" << endl;
												of.write(cyan, 1);
												of << "PAST" << endl; // = 29
												//cout << ctime(&time) << endl;
												tmtime->tm_hour += 1;
												//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "TENQ";of.write(red, 1); of << "TWENTYFIVE";of.write(cyan, 1); of << "TOHALF";of.write(white, 1); of << "TO";of.write(cyan, 1); of << "PAST"; // = 29
											}
										}
										else {
											of.write(white, 1);
											of << "ITS" << endl;
											of.write(cyan, 1);
											of << "FIVETENQUARTERTO" << endl;
											Sleep(500);
											of.write(red, 1);
											of << "HALF" << endl;
											of.write(cyan, 1);
											of << "TO" << endl;
											of.write(white, 1);
											of << "PAST" << endl;
											of.write(cyan, 1); // = 29
											//cout << ctime(&time) << endl;
											//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETENQUARTERTO";of.write(red, 1); of << "HALF";of.write(cyan, 1); of << "TO";of.write(white, 1); of << "PAST";of.write(cyan, 1);; // = 29
										}
									}
									else {
										of.write(white, 1);
										of << "ITS" << endl;
										of.write(cyan, 1);
										of << "TENQ" << endl;
										of.write(red, 1);
										of << "TWENTYFIVE" << endl;
										Sleep(500);
										of.write(cyan, 1);
										of << "TOHALFTO" << endl;
										of.write(white, 1);
										of << "PAST" << endl;
										of.write(cyan, 1); // = 29
										//cout << ctime(&time) << endl;
										//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "TENQ";of.write(red, 1); of << "TWENTYFIVE";of.write(cyan, 1); of << "TOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);; // = 29
									}
								}
								else {
									of.write(white, 1);
									of << "ITS" << endl;
									of.write(cyan, 1);
									of << "FIVETENQ" << endl;
									of.write(red, 1);
									of << "TWENTY" << endl;
									Sleep(500);
									of.write(cyan, 1);
									of << "TOHALFTO" << endl;
									of.write(white, 1);
									of << "PAST" << endl;
									of.write(cyan, 1); // = 29
									//cout << ctime(&time) << endl;
									//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETENQ";of.write(red, 1); of << "TWENTY";of.write(cyan, 1); of << "TOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);; // = 29
								}
							}
							else {
								of.write(white, 1);
								of << "ITS" << endl;
								of.write(cyan, 1);
								of << "FIVETEN" << endl;
								of.write(red, 1);
								of << "QUARTER" << endl;
								Sleep(500);
								of.write(cyan, 1);
								of << "TOHALFTO" << endl;
								of.write(white, 1);
								of << "PAST" << endl;
								of.write(cyan, 1);
								//cout << ctime(&time) << endl;
								//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVETEN";of.write(red, 1); of << "QUARTER";of.write(cyan, 1); of << "TOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);;
							}
						}
						else {
							of.write(white, 1);
							of << "ITS" << endl;
							of.write(cyan, 1);
							of << "FIVE" << endl;
							of.write(red, 1);
							of << "TEN" << endl;
							of.write(cyan, 1);
							Sleep(300);
							of << "QUARTERTOHALFTO" << endl;
							Sleep(500);
							of.write(white, 1);
							of << "PAST" << endl;
							of.write(cyan, 1);
							//cout << ctime(&time) << endl;
							//cout of.write(white, 1); of << "ITS";of.write(cyan, 1); of << "FIVE";of.write(red, 1); of << "TEN";of.write(cyan, 1); of << "QUARTERTOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);;
						}
					}
					else {
						of.write(white, 1);
						of << "ITS" << endl;
						of.write(red, 1);
						of << "FIVE" << endl;
						of.write(cyan, 1);
						Sleep(300);
						of << "TENQUARTERTOHALFTO" << endl;
						Sleep(500);
						of.write(white, 1);
						of << "PAST" << endl;
						of.write(cyan, 1);
						//cout << ctime(&time) << endl;
						//cout of.write(white, 1); of << "ITS";of.write(red, 1); of << "FIVE";of.write(cyan, 1); of << "TENQUARTERTOHALFTO";of.write(white, 1); of << "PAST";of.write(cyan, 1);;
					}
				}
				else {
					of.write(white, 1);
					of << "ITS" << endl;
					of.write(cyan, 1);
					of << "FIVETENQUART" << endl;
					Sleep(500);
					of << "ERTOHALFTOPAST" << endl;
					Sleep(500);
					//cout << ctime(&time) << endl;
					//cout of.write(white, 1); << "ITS";of.write(cyan, 1); << "FIVETENQUARTERTOHALFTOPAST";
				}

				//send hour stuff
				Sleep(700);
				if (tmtime->tm_hour % 12 == 0) {

					//ShowWindow(GetConsoleWindow(), SW_SHOW);
					//cout << ctime_s(&time) << endl;
					//ShowWindow(GetConsoleWindow(), SW_HIDE);
					of << "ONE" << endl;
					of << "TWO" << endl;
					of << "THREE" << endl;
					Sleep(300);
					of << "FOUR" << endl;
					of << "FIVE" << endl;
					Sleep(500);
					of << "SIX" << endl;
					Sleep(300);
					of << "SEVEN" << endl;
					Sleep(300);
					of << "EIGHT" << endl;
					Sleep(500);
					of << "NINE" << endl;
					Sleep(300);
					of << "TEN" << endl;
					Sleep(300);
					of << "ELEVEN" << endl;
					Sleep(300);
					of.write(red, 1);
					Sleep(300);
					of << "TWELVE" << endl;
				}
				else {
					if (tmtime->tm_hour % 12 == 1) {
						of.write(red, 1);
						of << "ONE" << endl;
						of.write(cyan, 1);
						of << "TWO" << endl;
						of << "THREE" << endl;
						Sleep(300);
						of << "FOUR" << endl;
						Sleep(500);
						of << "FIVE" << endl;
						of << "SIX" << endl;
						Sleep(500);
						of << "SEVEN" << endl;
						Sleep(500);
						of << "EIGHT" << endl;
						Sleep(500);
						of << "NINE" << endl;
						Sleep(500);
						of << "TEN" << endl;
						Sleep(500);
						of << "ELEVEN" << endl;
						Sleep(500);
						of << "TWELVE" << endl;
					}
					else {
						if (tmtime->tm_hour % 12 == 2) {
							of << "ONE" << endl;
							of.write(red, 1);
							of << "TWO" << endl;
							of.write(cyan, 1);
							Sleep(500);
							of << "THREE" << endl;
							of << "FOUR" << endl;
							Sleep(300);
							of << "FIVE" << endl;
							Sleep(500);
							of << "SIX" << endl;
							of << "SEVEN" << endl;
							Sleep(500);
							of << "EIGHT" << endl;
							of << "NINE" << endl;
							Sleep(300);
							of << "TEN" << endl;
							Sleep(500);
							of << "ELEVEN" << endl;
							Sleep(500);
							of << "TWELVE" << endl;
						}
						else {
							if (tmtime->tm_hour % 12 == 3) {
								of << "ONE" << endl;
								of << "TWO" << endl;
								of.write(red, 1);
								of << "THREE" << endl;
								of.write(cyan, 1);
								Sleep(500);
								of << "FOUR" << endl;
								of << "FIVE" << endl;
								Sleep(500);
								of << "SIX" << endl;
								of << "SEVEN" << endl;
								Sleep(500);
								of << "EIGHT" << endl;
								of << "NINE" << endl;
								Sleep(300);
								of << "TEN" << endl;
								Sleep(500);
								of << "ELEVEN" << endl;
								Sleep(500);
								of << "TWELVE" << endl;
							}
							else {
								if (tmtime->tm_hour % 12 == 4) {
									of << "ONE" << endl;
									of << "TWO" << endl;
									of << "THREE" << endl;
									of.write(red, 1);
									of << "FOUR" << endl;
									Sleep(500);
									of.write(cyan, 1);
									of << "FIVE" << endl;
									of << "SIX" << endl;
									Sleep(300);
									of << "SEVEN" << endl;
									Sleep(500);
									of << "EIGHT" << endl;
									of << "NINE" << endl;
									Sleep(300);
									of << "TEN" << endl;
									Sleep(500);
									of << "ELEVEN" << endl;
									Sleep(500);
									of << "TWELVE" << endl;
								}
								else {
									if (tmtime->tm_hour % 12 == 5) {
										of << "ONE" << endl;
										of << "TWO" << endl;
										of << "THREE" << endl;
										Sleep(300);
										of << "FOUR" << endl;
										of.write(red, 1);
										of << "FIVE" << endl;
										Sleep(500);
										of.write(cyan, 1);
										of << "SIX" << endl;
										of << "SEVEN" << endl;
										Sleep(500);
										of << "EIGHT" << endl;
										Sleep(300);
										of << "NINE" << endl;
										Sleep(500);
										of << "TEN" << endl;
										of << "ELEVEN" << endl;
										Sleep(500);
										of << "TWELVE" << endl;
									}
									else {
										if (tmtime->tm_hour % 12 == 6) {
											of << "ONE" << endl;
											of << "TWO" << endl;
											of << "THREE" << endl;
											Sleep(500);
											of << "FOUR" << endl;
											of << "FIVE" << endl;
											Sleep(500);
											of.write(red, 1);
											of << "SIX" << endl;
											of.write(cyan, 1);
											of << "SEVEN" << endl;
											Sleep(300);
											of << "EIGHT" << endl;
											Sleep(500);
											of << "NINE" << endl;
											of << "TEN" << endl;
											Sleep(500);
											of << "ELEVEN" << endl;
											Sleep(500);
											of << "TWELVE" << endl;
										}
										else {
											if (tmtime->tm_hour % 12 == 7) {
												of << "ONE" << endl;
												of << "TWO" << endl;
												of << "THREE" << endl;
												Sleep(300);
												of << "FOUR" << endl;
												of << "FIVE" << endl;
												Sleep(500);
												of << "SIX" << endl;
												of.write(red, 1);
												of << "SEVEN" << endl;
												of.write(cyan, 1);
												Sleep(500);
												of << "EIGHT" << endl;
												of << "NINE" << endl;
												Sleep(500);
												of << "TEN" << endl;
												of << "ELEVEN" << endl;
												Sleep(500);
												of << "TWELVE" << endl;
											}
											else {
												if (tmtime->tm_hour % 12 == 8) {
													of << "ONE" << endl;
													of << "TWO" << endl;
													of << "THREE" << endl;
													Sleep(300);
													of << "FOUR" << endl;
													Sleep(500);
													of << "FIVE" << endl;
													of << "SIX" << endl;
													of << "SEVEN" << endl;
													of.write(red, 1);
													of << "EIGHT" << endl;
													Sleep(500);
													of.write(cyan, 1);
													of << "NINE" << endl;
													of << "TEN" << endl;
													Sleep(500);
													of << "ELEVEN" << endl;
													Sleep(500);
													of << "TWELVE" << endl;
												}
												else {
													if (tmtime->tm_hour % 12 == 9) {
														of << "ONE" << endl;
														of << "TWO" << endl;
														Sleep(300);
														of << "THREE" << endl;
														of << "FOUR" << endl;
														Sleep(500);
														of << "FIVE" << endl;
														of << "SIX" << endl;
														Sleep(300);
														of << "SEVEN" << endl;
														Sleep(300);
														of << "EIGHT" << endl;
														Sleep(500);
														of.write(red, 1);
														of << "NINE" << endl;
														Sleep(500);
														of.write(cyan, 1);
														of << "TEN" << endl;
														Sleep(500);
														of << "ELEVEN" << endl;
														Sleep(500);
														of << "TWELVE" << endl;
													}
													else {
														if (tmtime->tm_hour % 12 == 10) {
															of << "ONE" << endl;
															of << "TWO" << endl;
															Sleep(300);
															of << "THREE" << endl;
															of << "FOUR" << endl;
															Sleep(500);
															of << "FIVE" << endl;
															of << "SIX" << endl;
															Sleep(300);
															of << "SEVEN" << endl;
															Sleep(500);
															of << "EIGHT" << endl;
															Sleep(300);
															of << "NINE" << endl;
															Sleep(500);
															of.write(red, 1);
															of << "TEN" << endl;
															Sleep(500);
															of.write(cyan, 1);
															of << "ELEVEN" << endl;
															Sleep(500);
															of << "TWELVE" << endl;
														}
														else {
															if (tmtime->tm_hour % 12 == 11) {
																of << "ONE" << endl;
																of << "TWO" << endl;
																of << "THREE" << endl;
																of << "FOUR" << endl;
																Sleep(500);
																of << "FIVE" << endl;
																of << "SIX" << endl;
																of << "SEVEN" << endl;
																Sleep(500);
																of << "EIGHT" << endl;
																Sleep(300);
																of << "NINE" << endl;
																of << "TEN" << endl;
																Sleep(500);
																of.write(red, 1);
																of << "ELEVEN" << endl;
																Sleep(500);
																of.write(cyan, 1);
																of << "TWELVE" << endl;
																Sleep(500);
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
			//set old time
			oldhours = tmtime->tm_hour % 12;
			oldmins = tmtime->tm_min;
			Sleep(5000);
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