#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "AplParaChkTest.h"
#include "AplParaChk.h"

//---------------------------------------------------------------------------
class AplParaChkTest {
public :
	AplParaChkTest( ) {
		ParaChk = new AplParaChk(3);
	}

	virtual ~AplParaChkTest( ) {
		delete ParaChk;
	}

	void testSetPara() {
		char argc;
		char *argv1[6];
		char *argv2[6];

		argv1[0] = "path";
		argv1[1] = "1";
		argv1[2] = "+";
		argv1[3] = "2";
		argv1[4] = "*";
		argv1[5] = "3";

		argv2[0] = "PATH";
		argv2[1] = "10";
		argv2[2] = "-";
		argv2[3] = "20";
		argv2[4] = "/";
		argv2[5] = "30";

		for( argc=0; argc <=3; argc++ )
		{
			ParaChk->SetPara( argc, (char **)&argv1 );
			ASSERT_EQUAL( ParaChk->GetArgc(), 0 );
			ASSERT_EQUAL( ParaChk->GetArgv(0), "" );
			ASSERT_EQUAL( ParaChk->GetArgv(1), "" );
			ASSERT_EQUAL( ParaChk->GetArgv(2), "" );
			ASSERT_EQUAL( ParaChk->GetArgv(3), "" );
		}
		argc = 5;
		ParaChk->SetPara( argc, (char **)&argv1 );
		ASSERT_EQUAL( ParaChk->GetArgc(), 0 );
		ASSERT_EQUAL( ParaChk->GetArgv(0), "" );
		ASSERT_EQUAL( ParaChk->GetArgv(1), "" );
		ASSERT_EQUAL( ParaChk->GetArgv(2), "" );
		ASSERT_EQUAL( ParaChk->GetArgv(3), "" );

		argc = 4;
		ParaChk->SetPara( argc, (char **)&argv1 );
		ASSERT_EQUAL( (int)ParaChk->GetArgc(), (int)3 );
		ASSERT_EQUAL( ParaChk->GetArgv(0), "1" );
		ASSERT_EQUAL( ParaChk->GetArgv(1), "+" );
		ASSERT_EQUAL( ParaChk->GetArgv(2), "2" );
		ASSERT_EQUAL( ParaChk->GetArgv(3), "" );

		argc = 5;
		ParaChk->SetPara( argc, (char **)&argv2 );
		ASSERT_EQUAL( (int)ParaChk->GetArgc(), (int)3 );
		ASSERT_EQUAL( ParaChk->GetArgv(0), "1" );
		ASSERT_EQUAL( ParaChk->GetArgv(1), "+" );
		ASSERT_EQUAL( ParaChk->GetArgv(2), "2" );
		ASSERT_EQUAL( ParaChk->GetArgv(3), "" );

		argc = 4;
		ParaChk->SetPara( argc, (char **)&argv2 );
		ASSERT_EQUAL( (int)ParaChk->GetArgc(), (int)3 );
		ASSERT_EQUAL( ParaChk->GetArgv(0), "10" );
		ASSERT_EQUAL( ParaChk->GetArgv(1), "-" );
		ASSERT_EQUAL( ParaChk->GetArgv(2), "20" );
		ASSERT_EQUAL( ParaChk->GetArgv(3), "" );
	}

	void testIsValidNum( ) {
		 ASSERT_EQUAL( ParaChk->IsValidNum( 0 ), true );
		 ASSERT_EQUAL( ParaChk->IsValidNum( -99999999 ), true );
		 ASSERT_EQUAL( ParaChk->IsValidNum(  99999999 ), true );

		 ASSERT_EQUAL( ParaChk->IsValidNum( -100000000 ), false );
		 ASSERT_EQUAL( ParaChk->IsValidNum(  100000000 ), false );
	}

	void testIsValidSymbol( ) {
		ASSERT_EQUAL( ParaChk->IsValidSymbol("+"), true );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("-"), true );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("*"), true );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("/"), true );

		ASSERT_EQUAL( ParaChk->IsValidSymbol("!"), false );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("^"), false );

		ASSERT_EQUAL( ParaChk->IsValidSymbol("＋"), false );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("－"), false );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("＊"), false );
		ASSERT_EQUAL( ParaChk->IsValidSymbol("／"), false );
	}

	AplParaChk* ParaChk;
};

//---------------------------------------------------------------------------
cute::suite make_suite_AplParaChkTest(){
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(AplParaChkTest, testSetPara));
	s.push_back(CUTE_SMEMFUN(AplParaChkTest, testIsValidNum));
	s.push_back(CUTE_SMEMFUN(AplParaChkTest, testIsValidSymbol));
	return s;
}



