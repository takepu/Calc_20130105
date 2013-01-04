#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "AplCalcTest.h"

#define RUN_SUITE( name ) runSuite( #name, name );

//---------------------------------------------------------------------------
void runSuite( char* name, const cute::suite& s ){
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, name);
}

//---------------------------------------------------------------------------
void runTest(){
//	RUN_SUITE( xxxxxxxxxx() );
	RUN_SUITE( make_suite_AplCalcTest() );
}

//---------------------------------------------------------------------------
int main(){
	runTest();
    return 0;
}
