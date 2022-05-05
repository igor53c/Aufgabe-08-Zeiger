// Aufgabe 08 Zeiger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
	 Schreiben Sie Deklarationen für einen Zeiger,

	 (a) der auf eine Variable vom Datentyp 'char' zeigen soll
	 (b) der auf ein Feld von 10 int-Elementen zeigen soll
	 (c) der auf einen konstanten int-Wert zeigen soll
	 (d) der konstant ist und auf eine int-Variable zeigen soll
	 (e) der auf einen Zeiger vom Typ 'char' zeigen soll

	 Initialisieren Sie diese Zeiger jeweils und geben Sie die Werte
	 aus.

 */

 /*
  * Aufgabe 1: Deklarieren Sie ein leeres int-Feld mit 10 Werten. Schreiben Sie
  *            in einer Schleife mit Hilfe eines Zeigers die Quadrate der Zahlen
  *            von 1 bis 10 in dieses Feld. Benutzen Sie für den Zugriff auf ein
  *            einzelnes Element die Zeigerverstellung mit dem '++'-Operator.
  *
  *            Geben Sie die Werte des Feldes anschließend mit einer Schleife aus,
  *            die den Zeiger rückwärts durch das Feld bewegt, also mittels des
  *            Dekrement-Operators.
  *
  *
  * Aufgabe 2: Gegeben sei folgendes Feld von Buchstaben:
  *
  *               char text[] = "alfatraining Bildungszentrum Karlsruhe";
  *
  *            Deklarieren Sie einen Zeiger der auf dieses Feld zeigt, und geben
  *            Sie die Buchstaben einzeln mit Hilfe dieses Zeigers aus, bis ein
  *            Buchstabe mit dem Wert 0 kommt ('\0').
  *
  *            Hinweis: Denken Sie dabei daran, daß C++ leider (aber hier zu Ihrem
  *                     Vorteil) keine wirklichen logischen Werte hat, sondern 0
  *                     und nicht 'false' (0 wird bei Schleifenbedingungen jedoch
  *                     als falsch interpretiert, und in diesem Fall soll die Schleife
  *                     auch abbrechen). Verwenden Sie eine 'while'-Schleife.
  *
  *            Definieren Sie dann eine Funktion 'strLength()',
  *            welche die Länge eines solchen Textes bestimmt:
  *
  *                    int strLength(char *p)
  *
  */

#include <iostream>

using namespace std;

void aufgabe1();
void aufgabe2();

int strLength(char*);

int main()
{
	char ch = 'A';
	int i = 50;
	const int iConst = 100;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << "ch: " << ch << endl;
	cout << "i: " << i << endl;
	cout << "iConst: " << iConst << endl << endl;

	char* pChar = &ch;
	int* pIntArr = arr;
	int const* pIntToConst = &iConst;
	int* const pConstToInt = &i;
	char** ppChar = &pChar;

	cout << "*pChar: " << *pChar << endl;

	cout << "*pIntArr = { ";

	for (int i = 0; i < size(arr); i++)
		cout << *(pIntArr + i) << " ";

	cout << "}" << endl;

	cout << "*pIntToConst: " << *pIntToConst << endl;
	cout << "*pConstToInt: " << *pConstToInt << endl;
	cout << "**ppChar: " << **ppChar << endl;

	aufgabe1();

	aufgabe2();

	return EXIT_SUCCESS;
}

void aufgabe1()
{
	int arr2[10]{};

	int* pIntArr = arr2;

	for (int i = 0; i < size(arr2); i++)
		*pIntArr++ = (i + 1) * (i + 1);
	
	cout << endl << "arr2 = { ";

	for (int i = 0; i < size(arr2); i++)
		cout << *--pIntArr << " ";
	
	cout << "}" << endl;
}

void aufgabe2()
{
	char text[] = "alfatraining Bildungszentrum Karlsruhe";

	char* pChar = text;

	cout << endl << "text: '";

	while (*pChar)	
		cout << *pChar++;
	
	cout << "'" << endl;

	pChar = text;

	cout << endl << "strLength(text): " << strLength(pChar) << endl;
}

int strLength(char* p)
{
	int retValue = 0;

	while (*p)
	{
		p++;
		retValue++;
	}

	return retValue;
}
