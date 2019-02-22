#include <unistd.h>
#include "ocilib.h"

#define N 1000000

static void _oci_error_handler(OCI_Error *err) {
	const otext *sql;

	sql = OCI_GetSql(OCI_ErrorGetStatement(err));
	if (sql)
		printf("Error while executing SQL \"%s\"", sql);
	printf("ORA-%05i: %s", OCI_ErrorGetOCICode(err), OCI_ErrorGetString(err));
}

int main(void) {
	if (!OCI_Initialize(_oci_error_handler, NULL, OCI_ENV_DEFAULT)) {
		return EXIT_FAILURE;
	}

	otext *card_num = ""
				   "";

	OCI_Connection *cn = OCI_ConnectionCreate("ONLINE11g", "TCTDBS", "TCTDBS", OCI_SESSION_DEFAULT);

	OCI_Statement *st1 = OCI_StatementCreate(cn);
	OCI_Statement *st2 = OCI_StatementCreate(cn);

	OCI_Prepare(st1, OTEXT("begin DBMS_SESSION.SET_IDENTIFIER('xui'); dl_params_paymentschemes.get_binbycardno(:hCardNumber, :c_BinsCursor); end ;"));
	OCI_BindString(st1, OTEXT(":hCardNumber"), card_num, strlen(card_num));
	OCI_BindStatement(st1, OTEXT(":c_BinsCursor"), st2);

	for (int i = 0; i < N; i++) {


		OCI_Execute(st1);
		OCI_Resultset *rs = OCI_GetResultset(st2);

		printf("i: %d\n", i);
		while (OCI_FetchNext(rs)) {
			printf("serno: %d, desc: %s\n", OCI_GetInt(rs, 2), OCI_GetString(rs, 9));
			usleep(10000);
		}
	}

	OCI_StatementFree(st1);
	OCI_StatementFree(st2);

	OCI_ConnectionFree(cn);
	OCI_Cleanup();
	printf("exit success");
	return EXIT_SUCCESS;
}