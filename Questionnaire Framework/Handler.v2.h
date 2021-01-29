#include <fstream>
#include <iostream>

using namespace std;

#import C:\\Program Files\\Common Files\\system\\ado\\msado15.dll rename("EOF",
"AdoNSEOF")

_bstr_t bstrConnect = "Provider=Microsoft.ACE.OLEDB.12.0;Data "
"Source=C:\\Users\\lriley\\Documents\\Northwind 2007.mdb;";

HRESULT hr;

int main()
{
    ::CoInitialize(NULL);
    const char* DAM = "ADO";

    ADODB::_ConnectionPtr pConn("ADODB.Connection");
    hr = pConn->Open(bstrConnect, "admin", "", ADODB::adConnectUnspecified);
    if (SUCCEEDED(hr))
    {
        cout << DAM << ": Successfully connected to database. Data source name:\n  "
            << pConn->GetConnectionString() << endl;
    }
    else
    {
        cout << DAM << " : Unable to connect to data source: " << bstrConnect << endl;
    }
    ::CoUninitialize();
    return 0;
}