/*
 * AplMain.h
 *
 *  Created on: 2013/01/02
 *      Author: takepu
 */

#ifndef APLMAIN_H_
#define APLMAIN_H_

#include <iostream>
#include <string>
#include "AplCalc.h"
#include "AplParaChk.h"

#define APL_VALID_PARA_NUM	3

using namespace std;

class AplMain {
friend class AplMainTest;
public:
	AplMain();

	virtual ~AplMain();

	char RunMain( char argc, char **argv );

	char Exec( long data, char calc_sym, long data2 );

	inline string GetRsltMsg( )
	{
		return RsltMsg;
	}

protected:
	string		RsltMsg;
	AplCalc*	P_Calc;
	AplParaChk*	P_ParaChk;

	long StrToInt( string str );
	string IntToStr( long num );
	bool IsDigit( string str );

	inline void OutputMsg( string msg ) { RsltMsg=msg; cout << RsltMsg << endl; }
};

#endif /* APLMAIN_H_ */
