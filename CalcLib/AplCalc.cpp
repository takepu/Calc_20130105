/*
 * AplCalc.cpp
 *
 *  Created on: 2013/01/04
 *      Author: takepu
 */

#include <complex>
#include "AplCalc.h"

AplCalc::AplCalc() {
	// TODO 自動生成されたコンストラクター・スタブ

}

AplCalc::~AplCalc() {
	// TODO Auto-generated destructor stub
}

long AplCalc::Add( long data1, long data2 )
{
	if( ( IsPlus(data1)  && IsPlus(data2)  ) ||
		( IsMinus(data1) && IsMinus(data2) )    )
	{
		if( (APLCALC_MAX - abs(data1)) < abs(data2) )
		{
			return APLCALC_OVERFLOW;
		}
	}
	return ( data1 + data2 );
}

long AplCalc::Sub( long data1, long data2 )
{
	if( ( IsPlus(data1)  && IsMinus(data2)  ) ||
		( IsMinus(data1) && IsPlus(data2) )    )
	{
		if( (APLCALC_MAX - abs(data1)) < abs(data2) )
		{
			return APLCALC_OVERFLOW;
		}
	}
	return ( data1 - data2 );
}

