
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1344: Angle Between Hands Of Clock
 *
 * Given two numbers, hour and minutes. Return the smaller angle (in degrees)
 * formed between the hour and the minute hand.
 *
 * Example 1:
 * Input: hour = 12, minutes = 30
 * Output: 165
 *
 * Example 2:
 * Input: hour = 3, minutes = 30
 * Output: 75
 *
 * Example 3:
 * Input: hour = 3, minutes = 15
 * Output: 7.5
 *
 * Example 4:
 * Input: hour = 4, minutes = 50
 * Output: 155
 *
 * Constraints:
 * 1 <= hour <= 12
 * 0 <= minutes <= 59
 * Answers within 10^-5 of the actual value will be accepted as correct.
*/

/*
 * Solution is to find the angle between hours hand and
 * minutes hand, need to see how much hours hand will
 * deviate with respect to minute hand.
 *
 * The hours hand will complete angle of 360 only when it
 * completes 12 hours i.e..,
 *       360degrees -> 12 hours
 *        30degrees -> 1 hour
 *
 * As we can see tha there is a 30degree deviation in the
 * hour hand which corresponds to 0.5degree in 1 minute
 *        30degrees -> 1 hour
 *        30degress -> 60 minutes
 *        0.5degree -> 1 minute
 *
 * Now lets check the minutes hand, the minutes hand will
 * complete 360degree in 60 minutes
 *        360degree -> 60 minutes
 *         60degree -> 1 minute
 *
 * Absolute difference of both hours angle and minutes angle
 * will give the result.
 *
 * Base Case:
 * If the hour is 12, then hour hand is at 0
 * If the hour, minutes < 0 or hour > 12 or min > 60, invalid
*/
double angleClock(int hour, int minutes) {
    if (hour < 0 || minutes < 0 || hour > 12 || minutes > 60) {
        // Invalid input
        return 0.0;
    }

    // Check if the hour is 12, then hour hand is at 0
    if (hour == 12) {
        // Replace with zero
        hour = 0;
    }

    // As minutes hand effects the hours hand, calculate the hour
    // angle by including the minutes hand. As angle between the
    // hours hand for a minute is known(0.5), hours hand needs
    // to be converted to minutes and multiply with 0.5 so that we
    // get the total angle
    //       (h*60 + m) >> 1
    double hoursAngle = (hour * 60 + minutes) * 0.5;

    // Calculate the minutes angle, as we know the angle at each
    // minute directly multiple with 6
    double minutesAngle = minutes * 6;

    // Get the absolute difference and return
    double angle = abs(hoursAngle - minutesAngle);

    // Return the smaller angle of two possible angles
    angle = min(360 - angle, angle);

    return angle;
}
