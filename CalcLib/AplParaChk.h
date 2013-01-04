/*
 * AplParaChk.h
 *
 *  Created on: 2013/01/02
 *      Author: takepu
 */
#include <vector>
#include <string>

#ifndef APLPARACHK_H_
#define APLPARACHK_H_

using namespace std;
class AplParaChk
{
public:
	AplParaChk( char valid_num );

	virtual ~AplParaChk();

	void SetPara( char argc, char **argv );

	bool IsValidSymbol( string str );

	inline char GetArgc( )
	{
		return Argc;
	}

	inline string GetArgv( char idx )
	{
		if( ( idx < 0 ) || ( idx >= ValidNum ) )
		{
			return std::string( "" );
		}
		return Argv[idx];
	}

	inline bool IsValidNum( long num )
	{
		return ( (num>=-99999999) && (num<=99999999) );
	}

protected:
	char			ValidNum;
	char			Argc;
	vector<string>	Argv;
};

#endif /* APLPARACHK_H_ */
