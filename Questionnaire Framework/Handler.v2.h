#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;

int main()
{

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLHANDLE sqlEnvHandle;
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

    sqlConnHandle = NULL;
    sqlStmtHandle = NULL;

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
    {
        goto COMPLETED;
    }

    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
    {
        goto COMPLETED;
    }

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
    {
        goto COMPLETED;
    }

    cout << "Attempting connection to SQL Server...";
    cout << "\n";

    switch (SQLDriverConnect(sqlConnHandle,
        NULL,
        (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;Trusted=true;",
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_NOPROMPT)) {
    case SQL_SUCCESS:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;
    case SQL_SUCCESS_WITH_INFO:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;
    case SQL_INVALID_HANDLE:
        cout << "Could not connect to SQL Server";
        cout << "\n";
        goto COMPLETED;
    case SQL_ERROR:
        cout << "Could not connect to SQL Server";
        cout << "\n";
        goto COMPLETED;

    default:
        break;
    }

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
        goto COMPLETED;

    cout << "\n";
    cout << "Executing T-SQL query...";
    cout << "\n";

    if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT @@VERSION", SQL_NTS))
    {
        cout << "Error querying SQL Server";
        cout << "\n";
        goto COMPLETED;
    }
    else 
    {
        SQLCHAR sqlVersion[SQL_RESULT_LEN];
        SQLINTEGER ptrSqlVersion;

        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
        {
            SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

            cout << "\nQuery Result:\n\n";
            cout << sqlVersion << endl;
        }
    }

COMPLETED:
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);

    cout << "\nPress any key to exit...";
    getchar();
}   