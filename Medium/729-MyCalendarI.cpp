
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 729: My Calendar I
 *
 * Implement a MyCalendar class to store your events. A new event can be added if
 * adding the event will not cause a double booking.
 *
 * Your class will have the method, book(int start, int end). Formally, this represents
 * a booking on the half open interval [start, end), the range of real numbers x such
 * that start <= x < end.
 *
 * A double booking happens when two events have some non-empty intersection (ie., there
 * is some time that is common to both events.)
 *
 * For each call to the method MyCalendar.book, return true if the event can be added to
 * the calendar successfully without causing a double booking. Otherwise, return false and
 * do not add the event to the calendar.
 *
 * Your class will be called like this: 
 *   MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
 *
 * Example 1:
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(15, 25); // returns false
 * MyCalendar.book(20, 30); // returns true
 *
 * E-xplanation: 
 * The first event can be booked.  The second can't because time 15 is already booked by
 * another event.
 * The third event can be booked, as the first event takes every time less than 20, but not
 * including 20.
 *
 * Note:
 * The number of calls to MyCalendar.book per test case will be at most 1000.
 * In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/
class MyCalendar {
    /*
     * Approach followed is Binary Search method
     *
     * Each event has a start and end, we need to save it in a
     * data structure that can sort it in ascending order of the
     * key which is start. That DS is map<int,int>, where search
     * operation can be done in logarthimic time of size of the
     * map.
     * Eg: [2,5) [9,12) [14,18) Now to add [4,8)
     * Initially the 3 events are in set now if we need to add
     * [4,8) we need to get the lower_bound of the key i.e..,
     * start from the map
     *              map.lower_bound({4,8}) which will return the
     * node that has start value >= 4 ie.., it returns node [9,12]
     * but we need to check the start to the prev node of it whether
     * it the start is in between that event range.
     *
    */
private:
    // Map to store the events
    map<int, int> mp;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        // Get the lower bound for the current event
        auto it = mp.lower_bound(start);

        // It returns the iterator that has the value greater or equal
        // to the current event. If not, it will return end

        // Check if the event start is in range of prev node, in order
        // to get the prev node the iterator should be not be in begin
        if (it != mp.begin() && prev(it)->second > start) {
            // current start value is in prev event range, can't book
            // this event
            return false;
        }

        // Now check whether end is greater than the start of current
        // node it is pointing only when current node it is not end
        if (it != mp.end() && end > it->first) {
            return false;
        }

        // Push it to the map
        mp[start] = end;

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */