#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> booking_seat_size(n);

        for (vector<int> booking : bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int k = booking[2];

            while (i <= j) {
                booking_seat_size[i] += k;
                i++;
            }
        }

        return booking_seat_size;
    }
};

int main()
{
    Solution sol;
    sol.corpFlightBookings();
    return 0;
}