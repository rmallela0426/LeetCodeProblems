
/*
 *  Author: Raghavendra Mallela
*/
/*
 * Leetcode 1108: Defanging An IP Address
 * 
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 * A defanged IP address replaces every period "." with "[.]".
 *
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 *
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 *
 * Constraints:
 * The given address is a valid IPv4 address.
*/
/*
 * Approach is to loop all the characters in the address
 * and replace with [.] if the char is '.'
*/
string defangIPaddr(string address) {
    // Loop all the characters of the address
    for (int i = 0; i < address.length(); i++) {
        if (address[i] == '.') {
            // Current char is '.', replace it with '[.]'
            address.replace(i, 1, "[.]");
            // Increment by 2 chars as we added 3 chars
            i += 2;
        }
    }
    // Return the defanged address
    return address;
}
