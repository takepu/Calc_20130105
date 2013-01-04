/*
 * AplParaChk.cpp
 *
 *  Created on: 2013/01/02
 *      Author: takepu
 */

#include <sstream>
#include "AplParaChk.h"

AplParaChk::AplParaChk( char valid_num) : ValidNum(valid_num)
{
	Argc = 0;
	Argv.resize( ValidNum );
}

AplParaChk::~AplParaChk()
{
}

void AplParaChk::SetPara( char argc, char **argv )
{
	char idx;

	if( (argc -1) != ValidNum )
	{
		return;
	}

	Argc = argc - 1;
	for( idx=0; idx<ValidNum; idx++ )
	{
		Argv[idx] = argv[(idx+1)];
	}
}

bool AplParaChk::IsValidSymbol( string str )
{
	if(    ( str == "+" )
		|| ( str == "-" )
		|| ( str == "*" )
		|| ( str == "/" ) )
	{
		return true;
	}
	return false;
}
