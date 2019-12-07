#include <iostream>
#include <fstream>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/jsonpath/json_query.hpp>

using namespace std;
using namespace jsoncons;

int main()
{
    std::ifstream is("data.json");
    json data = json::parse(is);

    string query;
    cout << "Enter query (Ex: A.B.C): ";
    cin >> query;

    json result = jsonpath::json_query(data, "$." + query);
    cout << result[0].as<std::string>() << endl;

    return 0;
}
