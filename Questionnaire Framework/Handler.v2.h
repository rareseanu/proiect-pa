#include <fstream>
#include <iostream>
#include <cmath>
#include <complex>
#include <iomanip>
#include <vector>
#include <limits>

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

        _bstr_t query = "SELECT Customers.[Company], Customers.[First Name] FROM "
            "Customers;";
        cout << DAM << ": SQL query \n  " << query << endl;

        // Execute
        ADODB::_RecordsetPtr pRS("ADODB.Recordset");
        hr = pRS->Open(query,
            _variant_t((IDispatch*)pConn, true),
            ADODB::adOpenUnspecified,
            ADODB::adLockUnspecified,
            ADODB::adCmdText);

        if (SUCCEEDED(hr))
        {
            cout << DAM << ": Retrieve schema info for the given result set: " << endl;
            ADODB::Fields* pFields = NULL;
            hr = pRS->get_Fields(&pFields);
            if (SUCCEEDED(hr) && pFields && pFields->GetCount() > 0)
            {
                for (long nIndex = 0; nIndex < pFields->GetCount(); nIndex++)
                {
                    cout << " | " << _bstr_t(pFields->GetItem(nIndex)->GetName());
                }
                cout << endl;
            }
            else
            {
                cout << DAM << ": Error: Number of fields in the " <<
                    "result is set to zero." << endl;
            }
            cout << DAM << ": Fetch the actual data: " << endl;
            int rowCount = 0;
            while (!pRS->AdoNSEOF)
            {
                for (long nIndex = 0; nIndex < pFields->GetCount(); nIndex++)
                {
                    cout << " | " << _bstr_t(pFields->GetItem(nIndex)->GetValue());
                }
                cout << endl;
                pRS->MoveNext();
                rowCount++;
            }
            cout << DAM << ": Total Row Count:  " << rowCount << endl;
        }
        pRS->Close();
        pConn->Close();
        cout << DAM << ": Cleanup Done" << endl;
    }
    else
    {
        cout << DAM << " : Unable to connect to data source: " << bstrConnect << endl;
    }
    ::CoUninitialize();
    return 0;
}