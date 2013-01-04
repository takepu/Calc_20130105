/*
 * AplMain.cpp
 *
 *  Created on: 2013/01/02
 *      Author: takepu
 */

#include <sstream>
#include <iostream>
#include "AplMain.h"

AplMain::AplMain()
{
	P_Calc    = new AplCalc;
	P_ParaChk = new AplParaChk( APL_VALID_PARA_NUM );
}

AplMain::~AplMain()
{
	delete P_Calc;
	delete P_ParaChk;
}

char AplMain::RunMain( char argc, char **argv )
{
	long	data1;
	long	data2;
	char	calc_sym;

	P_ParaChk->SetPara( argc, argv );
	if( P_ParaChk->GetArgc() != APL_VALID_PARA_NUM )
	{
		OutputMsg( "パラメタエラー" );
		return -1;
	}

	if( ( IsDigit(P_ParaChk->GetArgv(0)) == false ) ||
		( IsDigit(P_ParaChk->GetArgv(2)) == false )    )
	{
		OutputMsg( "数字エラー" );
		return -1;
	}
	data1 = StrToInt( P_ParaChk->GetArgv(0) );
	data2 = StrToInt( P_ParaChk->GetArgv(2) );

	if( ( P_ParaChk->IsValidNum( data1 ) == false ) ||
		( P_ParaChk->IsValidNum( data2 ) == false )    )
	{
		OutputMsg( "数字オーバー" );
		return -1;
	}

	if( P_ParaChk->IsValidSymbol( P_ParaChk->GetArgv(1) ) == false )
	{
		OutputMsg( "演算記号エラー" );
		return -1;
	}
	calc_sym = P_ParaChk->GetArgv(1)[0];

	return Exec( data1, calc_sym, data2 );
}

char AplMain::Exec( long data1, char calc_sym, long data2 )
{
	long	rslt;
	char	ret;

	switch( calc_sym )
	{
	case '+' :
		rslt = P_Calc->Add( data1, data2 );
		break;
	case '-' :
		rslt = P_Calc->Sub( data1, data2 );
		break;
	case '*' :
		rslt = P_Calc->Multi( data1, data2 );
		break;
	case '/' :
		rslt = P_Calc->Div( data1, data2 );
		break;
	default :
		calc_sym = '\0';
		break;
	}

	if( calc_sym == '\0' )
	{
		OutputMsg( "演算記号エラー" );
		ret = -1;
	}
	else if( rslt == APLCALC_OVERFLOW )
	{
		OutputMsg( "オーバーフロー" );
		ret = -1;
	}
	else
	{
		OutputMsg( IntToStr( rslt ) );
		ret = 0;
	}

	return ret;
}

long AplMain::StrToInt( string str )
{
	 stringstream  ss;
	 long		   num;

	 ss << str;
	 ss >> num;
	 return num;
}

string AplMain::IntToStr( long num )
{
	 stringstream  ss;

	 ss << num;
	 return ss.str();
}

bool AplMain::IsDigit( string str )
{
	unsigned long idx;
	unsigned long st;

	st = 0;
	if( ( str.length() >= 2 ) && ( str[0] == '-' ) )
	{
		st = 1;
	}

	for( idx=st; idx<str.length(); idx++ )
	{
		if( isdigit( (int)str[idx] ) == false )
		{
			return false;
		}
	}
	return true;
}
