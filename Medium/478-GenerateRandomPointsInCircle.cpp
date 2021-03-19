
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 478: Generate Random Points In Circle
 *
 * Given the radius and x-y positions of the center of a circle, write a function
 * randPoint which generates a uniform random point in the circle.
 *
 * Note:
 *  1. input and output values are in floating-point.
 *  2. radius and x-y position of the center of the circle is passed into the class
 *     constructor.
 *  3. a point on the circumference of the circle is considered to be in the circle.
 *  4. randPoint returns a size 2 array containing x-position and y-position of the
 *     random point, in that order.
 *
 * Example 1:
 * Input: 
 * ["Solution","randPoint","randPoint","randPoint"]
 * [[1,0,0],[],[],[]]
 * Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]
 *
 * Example 2:
 * Input: 
 * ["Solution","randPoint","randPoint","randPoint"]
 * [[10,5,-7.5],[],[],[]]
 * Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]
 *
 * Explanation of Input Syntax:
 * The input is two lists: the subroutines called and their arguments. Solution's constructor
 * has three arguments, the radius, x-position of the center, and y-position of the center of
 * the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if
 * there aren't any.
*/
class Solution {
public:
    double r;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint() {
        /*
         * Logic followed is in polar coordinates, where distance, theta
         * are  calculated and are converted to cartesian coordinates as
         *  point x = x_center + distance * cos(theta)
         *  point y = y_center + distance * sin(theta)
         *
         * In order to find the theta which ranges in 0 ... 2pi, generate
         * a random number in the range of 0..1 and multiple by 2* pi
         *
         * In order to generate the distance, sqrt(rand() in rang of 0...1)
         * multiplied with radius
        */

        // sqrt makes uniform distribution
        double distance = sqrt((double)rand() / RAND_MAX) * r;
        // Generate the theta
        double theta = ((double)rand() / RAND_MAX) * 2 * M_PI;

        // Convert the polar coordinates to cartesian coordinates.
        return { x + distance * cos(theta), y + distance * sin(theta) };
    }
};
