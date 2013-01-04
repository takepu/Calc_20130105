#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "AplCalcTest.h"
#include "AplCalc.h"

//---------------------------------------------------------------------------
class AplCalcTest {
public :
	AplCalc Cal;

	AplCalcTest() {
	}

	virtual ~AplCalcTest() {
	}

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

	void testMulti( ) {
		ASSERT_EQUAL( (long)Cal.Multi(0,0), (long)0 );
		ASSERT_EQUAL( (long)Cal.Multi(1,1), (long)1 );
		ASSERT_EQUAL( (long)Cal.Multi(99999999,0),  (long)0 );
		ASSERT_EQUAL( (long)Cal.Multi(0,99999999),  (long)0 );
		ASSERT_EQUAL( (long)Cal.Multi(-99999999,0), (long)0 );
		ASSERT_EQUAL( (long)Cal.Multi(0,-99999999), (long)0 );
		ASSERT_EQUAL( (long)Cal.Multi(33333333,3),          (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Multi(3,33333333),          (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Multi(33333333,-3),         (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Multi(3,-33333333),         (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Multi(-33333333,3),         (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Multi(-3,33333333),         (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Multi(33333333,4),          (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(4,33333333),          (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(33333333,-4),         (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(4,-33333333),         (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(-33333333,4),         (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(-4,33333333),         (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(-99999999,-99999999), (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(99999999,99999999),   (long)0x80000000 );
		ASSERT_EQUAL( (long)Cal.Multi(-99999999,-99999999), (long)0x80000000 );
	}

	void testDiv( ) {
		ASSERT_EQUAL( (long)Cal.Div(0,0), (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(1,0), (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(0,1), (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(99999999,1),  (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Div(99999999,10), (long)9999999  );
		ASSERT_EQUAL( (long)Cal.Div(1,99999999),  (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(1,9999999),   (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(-1,0),   (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(0,-1),   (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(-99999999,-1),  (long)99999999 );
		ASSERT_EQUAL( (long)Cal.Div(-99999999,-10), (long)9999999 );
		ASSERT_EQUAL( (long)Cal.Div(-1,-99999999),  (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(-1,-99999999),  (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(99999999,-1),   (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Div(99999999,-10),  (long)-9999999 );
		ASSERT_EQUAL( (long)Cal.Div(1,-99999999),   (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(1,-9999999),    (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(-99999999,1),   (long)-99999999 );
		ASSERT_EQUAL( (long)Cal.Div(-99999999,10),  (long)-9999999 );
		ASSERT_EQUAL( (long)Cal.Div(-1,99999999),   (long)0 );
		ASSERT_EQUAL( (long)Cal.Div(-1,9999999),    (long)0 );
	}
};

//---------------------------------------------------------------------------
cute::suite make_suite_AplCalcTest(){
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(AplCalcTest, testAdd));
	s.push_back(CUTE_SMEMFUN(AplCalcTest, testSub));
	s.push_back(CUTE_SMEMFUN(AplCalcTest, testMulti));
	s.push_back(CUTE_SMEMFUN(AplCalcTest, testDiv));
	return s;
}



