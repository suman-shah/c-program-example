// Cyclic Sort:
// ------------

// Cyclic sort is a sorting technique which performs sorting in O(n) i.e., in liner time complexity.
// Thus making it one of the most efficient sorting alogrithm and one which you're going to use during
// interview exams.

// Q) Where can we apply cyclic sort?
// Sol) We can apply this sorting technique only when the given array of elements is range within 0 to n
//      elements (or) 1 to n-1 elements.

// Q) What is cyclic sort ?
// Sol) Since the array of elements are range from 0 to n elements ( it can 1 to n-1 elements too ),
//      the resultant/sorted array will satisfy the condition:

//                                 array[ element-1 ] = element

//      So, by using the same principal we can sort the whole array in Linear Time complexity and Constant
//      Space complexity.

// Say what if the condition for an element in "Unsorted Array" fails ? We just swap the element into its
// rightful place using the same principal.