#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct City
{
	int32_t gifted_fuel; // fuel gifted in this city
	int32_t price_of_fuel_per_liter; // price of fuel in this city
};

int fuel, cheapest;

vector<int32_t> costs;
vector<City> cities;

int make_travel_plan(int from, int to)
{
    int cost = 0;
    for(int i = from + 1; i < to; ++i)
    {
        City* current_city = &cities[i];
        fuel -= costs[i];
        if(fuel < 0) 
        { 
            cost -= cheapest * fuel;
            fuel = 0;
        }
        fuel += current_city->gifted_fuel;
        if(current_city->price_of_fuel_per_liter < cheapest ) {
            cheapest = current_city->price_of_fuel_per_liter;
        }
    }
    fuel -= costs[to];
        if(fuel < 0) 
        { 
            cost -= cheapest * fuel;
        }
    return cost;
}

int get_money_needed(int from, int to)
{
    City* current_city = &cities[from];
    fuel = current_city->gifted_fuel;
    cheapest = current_city->price_of_fuel_per_liter;
    return make_travel_plan(from, to);
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int32_t number_of_roads, number_of_queries, cost, from, to;
	cin >> number_of_roads >> number_of_queries;
	costs.push_back(0);
	costs.push_back(0);
	cities.push_back(City());
	for(int i = 0; i < number_of_roads-1; ++i)
	{
		cin >> cost;
		costs.push_back(cost);
	}
	City city_to_be_pushed;
	for(int i = 0; i < number_of_roads ; ++i)
	{
		cin >> city_to_be_pushed.gifted_fuel
			>> city_to_be_pushed.price_of_fuel_per_liter;
	   cities.push_back(city_to_be_pushed);
    }
	for(int i = 0; i < number_of_queries; ++i)
	{
		cin >> from >> to;
		cout << get_money_needed(from, to) << endl;
	}

	return 0;
}
