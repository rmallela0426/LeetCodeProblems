
/*
 * Author: Raghavendra Mallela
*/

/*
 * LeetCode 1710: Maximum Units On Truck
 *
 * You are assigned to put some amount of boxes onto one truck. You are given
 * a 2D array boxTypes, where
 *        boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
 *    numberOfBoxesi is the number of boxes of type i.
 *    numberOfUnitsPerBoxi is the number of units in each box of the type i.
 *
 * You are also given an integer truckSize, which is the maximum number of boxes
 * that can be put on the truck. You can choose any boxes to put on the truck as
 * long as the number of boxes does not exceed truckSize.
 * Return the maximum total number of units that can be put on the truck.
 *
 * Example 1:
 * Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
 * Output: 8
 * Explanation: There are:
 *       - 1 box of the first type that contains 3 units.
 *       - 2 boxes of the second type that contain 2 units each.
 *       - 3 boxes of the third type that contain 1 unit each.
 * You can take all the boxes of the first and second types, and one box of the
 * third type.
 * The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
 *
 * Example 2:
 * Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
 * Output: 91
 *
 * Constraints:
 * 1 <= boxTypes.length <= 1000
 * 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
 * 1 <= truckSize <= 106
*/
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // Comparator that is used to sort the boxes with number of units
    auto comp = [&](vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    };

    // Sort the input boxTypes
    std::sort(boxTypes.begin(), boxTypes.end(), comp);

    int numUnits = 0;
    // Loop all the boxes
    for (vector<int>& boxType : boxTypes) {
        // Check numberofBoxes can fit in truck
        if (boxType[0] <= truckSize) {
            // Box can be fit in the truck
            numUnits += boxType[0] * boxType[1];
            // Reduce the boxes that are required to fit in car
            truckSize -= boxType[0];
        }
        else {
            // truckSize is smaller than current box
            numUnits += truckSize * boxType[1];
            break;
        }
    }

    // return maxUnits
    return numUnits;
}