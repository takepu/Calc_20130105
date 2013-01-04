/*
 * AplCalc.h
 *
 *  Created on: 2013/01/04
 *      Author: takepu
 */

#ifndef APLCALC_H_
#define APLCALC_H_

#define APLCALC_MAX			99999999
#define APLCALC_OVERFLOW	(long)0x80000000

class AplCalc {
public:
	AplCalc();
	virtual ~AplCalc();
	long Add(long data1,long data2);
	long Sub(long data1,long data2);
private:
	inline bool IsPlus( long num ) { return (num >= 0); }
	inline bool IsMinus( long num ){ return (num <  0); }
};

#endif /* APLCALC_H_ */
