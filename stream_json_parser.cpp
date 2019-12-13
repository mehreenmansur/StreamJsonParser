#include <iostream>
#include <fstream>
#include <time.h>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/jsonpath/json_query.hpp>

using namespace std;
using namespace jsoncons;

int main()
{
    clock_t start_time = clock();

    std::ifstream is("data.json");
    json data = json::parse(is);

    string query;
    cout << "Enter query (Ex: A.B.C): ";
    cin >> query;

    json result = jsonpath::json_query(data, "$." + query);

    clock_t end_time = clock();
    int time_diff = end_time - start_time;

    cout << "-----------------------------------------------" <<endl;
    cout << "Parsed in " << time_diff/1000.0 << " second(s)." <<endl;
    cout << "-----------------------------------------------" <<endl;

    cout << query << " : " << result[0].as<std::string>() << endl<<endl;

    return 0;
}
