#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "AplMainTest.h"
#include "AplMain.h"

//---------------------------------------------------------------------------
class AplMainTest
{
public:
	AplMainTest( ) {
		P_AplMain = new AplMain;
	}

	virtual ~AplMainTest( ) {
		delete P_AplMain;
	}

	void testRunMain( ) {
		char	argc;
		char*	argv[6];
		char	msg[128];

		argc = 0;
		memset( argv, 0, sizeof(argv) );
		argv[0] = "path";
		argv[1] = "1";
		argv[2] = "@";
		argv[3] = "2";
		argv[4] = "*";
		argv[5] = "3";

		for( argc=0; argc<4; argc++ )
		{
			sprintf( msg, "argc=%d", argc );
			ASSERT_EQUALM( msg, P_AplMain->RunMain(argc, (char **)&argv), (int)-1);
			ASSERT_EQUALM( msg, P_AplMain->GetRsltMsg(), "パラメタエラー");
		}

		argc = 4;
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)-1);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "演算記号エラー");

		argv[1] = "a";
		argv[2] = "+";
		argv[3] = "2";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)-1);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "数字エラー");

		argv[1] = "123456789";
		argv[2] = "+";
		argv[3] = "2";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)-1);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "数字オーバー");

		argv[1] = "99999999";
		argv[2] = "+";
		argv[3] = "1";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)-1);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "オーバーフロー");

		argv[1] = "1";
		argv[2] = "+";
		argv[3] = "2";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)0);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "3");


		argv[1] = "10";
		argv[2] = "-";
		argv[3] = "4";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)0);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "6");

		argv[1] = "60";
		argv[2] = "*";
		argv[3] = "8";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)0);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "480");

		argv[1] = "90";
		argv[2] = "/";
		argv[3] = "3";
		ASSERT_EQUAL( P_AplMain->RunMain(argc, (char **)&argv), (int)0);
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "30");
	}

	void testExec() {
		long data1    = 456;
		long data2    = 123;
		char calc_sym = '\0';

		calc_sym = '+';
		ASSERT_EQUAL( P_AplMain->Exec( data1, calc_sym, data2 ), 0 );
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "579" );

		calc_sym = '-';
		ASSERT_EQUAL( P_AplMain->Exec( data1, calc_sym, data2 ), 0 );
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "333" );

		calc_sym = '*';
		ASSERT_EQUAL( P_AplMain->Exec( data1, calc_sym, data2 ), 0 );
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "56088" );

		calc_sym = '/';
		ASSERT_EQUAL( P_AplMain->Exec( data1, calc_sym, data2 ), 0 );
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "3" );

		calc_sym = '*';
		data1    = 999999999;
		data2    = 999999999;
		ASSERT_EQUAL( P_AplMain->Exec( data1, calc_sym, data2 ), -1 );
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "オーバーフロー" );

		calc_sym = '@';
		ASSERT_EQUAL( P_AplMain->Exec( data1, calc_sym, data2 ), -1 );
		ASSERT_EQUAL( P_AplMain->GetRsltMsg(), "演算記号エラー" );
	}

	void testStrToInt() {
		 stringstream  ss;
		 long num;

		 for( num=-32768; num<=32767; num++ )
		 {
			 ss.clear();
			 ss.str("");
			 ss << num;
			 ASSERT_EQUAL( (long)P_AplMain->StrToInt( ss.str() ), (long)num );
		 }

		 ASSERT_EQUAL( P_AplMain->StrToInt( "-99999" ), -99999 );
		 ASSERT_EQUAL( P_AplMain->StrToInt( "99999" ),   99999 );
	}

	void testIntToStr() {
		 stringstream  ss;
		 long num;

		 for( num=-32768; num<=32767; num++ )
		 {
			 ss.clear();
			 ss.str("");
			 ss << num;
			 ASSERT_EQUAL( P_AplMain->IntToStr( num ), ss.str() );
		 }

		 ASSERT_EQUAL( P_AplMain->IntToStr( -99999999 ), "-99999999" );
		 ASSERT_EQUAL( P_AplMain->IntToStr(  99999999 ), "99999999"  );
	}

	void testIsDigit( ) {
		ASSERT_EQUAL( P_AplMain->IsDigit("0"), true );
		ASSERT_EQUAL( P_AplMain->IsDigit("1"), true );
		ASSERT_EQUAL( P_AplMain->IsDigit("99999999"), true );
		ASSERT_EQUAL( P_AplMain->IsDigit("-1"), true );
		ASSERT_EQUAL( P_AplMain->IsDigit("-99999999"), true );
		ASSERT_EQUAL( P_AplMain->IsDigit("a"), false );
		ASSERT_EQUAL( P_AplMain->IsDigit("@"), false );
		ASSERT_EQUAL( P_AplMain->IsDigit("1@"), false );
		ASSERT_EQUAL( P_AplMain->IsDigit("@1"), false );
		ASSERT_EQUAL( P_AplMain->IsDigit("1@1"), false );
		ASSERT_EQUAL( P_AplMain->IsDigit("@1@"), false );
	}

	AplMain*	P_AplMain;
};

//---------------------------------------------------------------------------
cute::suite make_suite_AplMainTest(){
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(AplMainTest, testRunMain));
	s.push_back(CUTE_SMEMFUN(AplMainTest, testExec));
	s.push_back(CUTE_SMEMFUN(AplMainTest, testStrToInt));
	s.push_back(CUTE_SMEMFUN(AplMainTest, testIntToStr));
	s.push_back(CUTE_SMEMFUN(AplMainTest, testIsDigit));
	return s;
}



