#include <fstream>
#include <iostream>
#include <cmath>
#include <complex>
#include <iomanip>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <icrsint.h>
#include <atldbsch.h>
#include <atldbcli.h>

using namespace std;

LPCOLESTR lpcOleConnect = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\\Northwind 2007.accdb;User Id=admin;Password=;";

int main()
{
    CDataSource dbDataSource;
    CSession dbSession;

    USES_CONVERSION;

    HRESULT hr;
    const char* DAM = "ADO";
    hr = dbDataSource.OpenFromInitializationString(lpcOleConnect);
    if (FAILED(hr))
    {
        cout << DAM << ": Unable to connect to data source " << OLE2T(lpcOleConnect) << endl;
    }
    else
    {
        hr = dbSession.Open(dbDataSource);
        if (FAILED(hr))
        {
            cout << DAM << ": Couldn't create session on data source " << OLE2T(lpcOleConnect) << endl;
        }
        else
        {
            CComVariant var;
            hr = dbDataSource.GetProperty(DBPROPSET_DATASOURCEINFO, DBPROP_DATASOURCENAME, &var);
            if (FAILED(hr) || (var.vt == VT_EMPTY))
            {
                cout << DAM << ": No Data Source Name Specified." << endl;
            }
            else
            {
                cout << DAM << ": Successfully connected to database. Data source name:\n  "
                    << COLE2T(var.bstrVal) << endl;
            }
        }
    }

    dbDataSource.Close();
    dbSession.Close();
    cout << DAM << ": Cleanup. Done." << endl;

    return 0;
}