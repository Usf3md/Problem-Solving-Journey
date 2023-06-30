
#include <bits/stdc++.h>

using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> cars;
    stack<double> fleet;
    for (int i = 0; i < position.size(); i++)
        cars.push_back({position[i], speed[i]});

    sort(cars.begin(), cars.end());
    for (int i = cars.size() - 1; i >= 0; i--)
    {
        if (!fleet.empty() && fleet.top() >= (double)(target - cars[i].first) / cars[i].second)
            continue;

        fleet.push((double)(target - cars[i].first) / cars[i].second);
    }
    return fleet.size();
}

int main()
{
    vector<int> positions{10, 8, 0, 5, 3};
    vector<int> speed{2, 4, 1, 1, 3};
    std::cout << carFleet(12, positions, speed);

    return 0;
}