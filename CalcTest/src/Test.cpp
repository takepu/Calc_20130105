#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "AplCalcTest.h"
#include "AplParaChkTest.h"
#include "AplMainTest.h"

#define RUN_SUITE( name ) runSuite( #name, name );

//---------------------------------------------------------------------------
void runSuite( char* name, const cute::suite& s ){
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, name);
}

//---------------------------------------------------------------------------
void runTest(){
	RUN_SUITE( make_suite_AplCalcTest() );
	RUN_SUITE( make_suite_AplParaChkTest() );
	RUN_SUITE( make_suite_AplMainTest() );
}

//---------------------------------------------------------------------------
int main(){
	runTest();
    return 0;
}
