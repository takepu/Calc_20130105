#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "AplCalcTest.h"
#include "AplCalc.h"

//---------------------------------------------------------------------------
class AplCalcTest {
public :
	AplCalc Cal;

	void testAdd( ){
		ASSERT_EQUAL( (long)Cal.Add(0,0), (long)0 );
		ASSERT_EQUAL( (long)Cal.Add(1,1), (long)2 );
		ASSERT_EQUAL( (long)Cal.Add(99999998,1), (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Add(1,99999998), (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Add(99999999,1), (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Add(1,99999999), (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Add(99999999,99999999), (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Add(45000000,-40000000), (long)5000000 );
		ASSERT_EQUAL( (long)Cal.Add(40000000,-45000000), (long)-5000000 );
		ASSERT_EQUAL( (long)Cal.Add(99999999,-99999999), (long)0 );
		ASSERT_EQUAL( (long)Cal.Add(-99999999,99999999), (long)0 );
		ASSERT_EQUAL( (long)Cal.Add(-45000000,40000000), (long)-5000000 );
		ASSERT_EQUAL( (long)Cal.Add(-40000000,45000000), (long)5000000 );
		ASSERT_EQUAL( (long)Cal.Add(-99999999,-99999999), (long)0x80000000 );
	}

	void testSub( ) {
		ASSERT_EQUAL( (long)Cal.Sub(0,0), (long)0 );
		ASSERT_EQUAL( (long)Cal.Sub(1,1), (long)0 );
		ASSERT_EQUAL( (long)Cal.Sub(99999999,0),  (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(45000000,40000000),  (long)5000000 );
		ASSERT_EQUAL( (long)Cal.Sub(40000000,45000000),  (long)-5000000 );
		ASSERT_EQUAL( (long)Cal.Sub(-45000000,40000000),  (long)-85000000 );
		ASSERT_EQUAL( (long)Cal.Sub(-40000000,45000000),  (long)-85000000 );
		ASSERT_EQUAL( (long)Cal.Sub(45000000,-40000000),  (long)85000000 );
		ASSERT_EQUAL( (long)Cal.Sub(40000000,-45000000),  (long)85000000 );
		ASSERT_EQUAL( (long)Cal.Sub(0,99999999),  (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(-99999999,0), (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(0,-99999999), (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(1,-99999998), (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(-99999999,0), (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(-99999998,1), (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Sub(1,-99999999), (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Sub(-99999999,1), (long)0x80000000 );
	}
};

//---------------------------------------------------------------------------
cute::suite make_suite_AplCalcTest(){
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(AplCalcTest, testAdd));
	s.push_back(CUTE_SMEMFUN(AplCalcTest, testSub));
	return s;
}
