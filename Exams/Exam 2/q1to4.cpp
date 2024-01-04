//Everett Bowline eb111

/*

    1.  Theorem: 1 + 3 + 9 + 27 + ⋯ + 3^n = (3^(n+1) − 1)/2 whenever n ≥ 0.

        Base Case: The smallest non-negative integer is 0, so
        3^0 = (3^(0+1) - 1)/2
        1 = (3^1 - 1)/2
        1 = (3 - 1)/2
        1 = 2/2
        1 = 1

        Thus 3^n = (3^(n+1) − 1)/2 is proven for n = 0.

        Inductive Hypothesis: Let 1 + 3 + 9 + 27 + ⋯ + 3^n = (3^(n+1) − 1)/2 be P(n)
        
        Assume that for the non-negative integer k, 
        P(k) = 1 + 3 + 9 + 27 + ⋯ + 3^k = (3^(k+1) − 1)/2
        We will prove that P(k + 1) = 1 + 3 + 9 + 27 + ⋯ + 3^(k+1) = (3^((k+1)+1) − 1)/2

        1 + 3 + 9 + 27 + ⋯ + 3^(k+1) = (3^((k+1)+1) − 1)/2

        1 + 3 + 9 + 27 + ⋯ + 3^k + 3^(k+1)                         Working on the left-hand side

        1 + 3 + 9 + 27 + ⋯ + 3^k = (3^(k+1) − 1)/2                 From inductive hypothesis

        ((3^(k+1) − 1)/2) + 3^(k+1) = (3^((k+1)+1) − 1)/2           The full equation

        (3*3^k - 1)/2) + 3*3^k                                      Working on the left-hand side
        3(((3^k - 1)/2) + 3^k) = 3(((3^k - 1)/2) + 2*3^k/2)
        3(((3^k - 1)/2) + 2*3^k/2) = 3((3*3^k - 1)/2)
        3((3*3^k - 1)/2) = (9*3^k - 1)/2
        (9*3^k -1)/2 = (3^(k+2) - 1)/2

        (3^((k+1)+1) − 1)/2 = (3^k+2 - 1)/2                         Working on the right-hand side

        (3^(k+2) - 1)/2 = (3^(k+2) - 1)/2                           The left-hand side and right-hand side together

        Thus if P(k) is true, P(k + 1) is true.

    2.  a)  Since there are multiple ways for five people to stand in a row, order matters here.
            Out of 9 people, 5 are taking a picture, so 9 * 8 * 7 * 6 * 5. However, we are specifically looking at
            the number of options where both of them are not included.

            Start with selecting Hal or Ida, which is 2! in any of the 5 positions. 
            There are four more slots, but cannot be filled by the non-selected Hal-Ida pair,
            so P(7, 4) for the remaining members.

            2 * 5 * (7!/((7 - 4)!)) = 8400
        
        b)  Subsets of five elements from S = {1, 2, 3, . . . , 10} would normally be C(10,5) since order
            does not matter. However, there are definitely two elements already part of the subset, 3 and 4,
            or C(2,2) = 1. That leaves us 8 more options and 3 more elements to select, so C(8,3).
            C(2,2) * C(8,3) = 1 * 56 = 56

    3.  a)  To solve this problem, we can use the concept of conditional probability. Initially, there are 10
            freshmen out of 30 students. When one freshman is picked, there are now 29 students left, with 9
            freshmen remaining. The probability that the first student picked is a freshman is 10/30 or 1/3,
            but since we know that the first student picked is already a freshman, we focus on the probability
            of picking a freshman as the second student from the remaining students.

            The probability that the second student is a freshman, given that the first is a freshman, is calculated as follows:
            P(2nd is freshman | 1st is freshman)= Number of remaining freshmen/Total number of remaining students
            
            We have 9 remaining freshmand and 29 remaining students, so 9/29.

        b)  For a bit string of length eight, there are 2^8=256 possible strings, since each bit can be either 0 or 1.

            To have more 0s than 1s, a string can have either 5, 6, 7, or 8 0s. We calculate the probability for each
            case and sum them up:

            5 zeroes and 3 ones: The number of ways to choose 5 positions out of 8 for the zeroes is C(8, 5).
            6 zeroes and 2 ones: The number of ways to choose 6 positions out of 8 for the zeroes is C(8, 6).
            7 zeroes and 1 one: The number of ways to choose 7 positions out of 8 for the zeroes is C(8, 7).
            8 zeroes: There is only 1 way for all bits to be zero.

            The probability is then calculated by adding the probabilities of these four scenarios:
            
            P(more 0s than 1s) = (C(8, 5) + C(8, 6) + C(8, 7) + C(8, 8)) / 2^8.

    4.  int function1(int n){
            int i, j;
            int total = 0;
            f   or (i = 1; i <= n; i *= 5)          O(logn) 5 + 25 + 125 + ... for log5n.
                    for (j = 1; j <= n; j += 1)     O(n)    1 + 1 + 1 + ... + 1 for a total of n times
                        total += (i+j);

            if(n%5 == 0){
                for (i = 1; i <= n; i++)            O(n)    1 + 1 + 1 + ... + 1 for a total of n times
                    for (j = 1; j <= n; j += 1)     O(n)    1 + 1 + 1 + ... + 1 for a total of n times
                        total += (i+j);
            }

            return total;
        }

        So we have n(logn) or n^2. n^2 is greater, so T(function1) = theta(n).

        int function2(int n){
            int i, j;
            int total = 0;
            for (i = 1; i <= n; i *= 5){            O(logn)   5 + 25 + 125 + ... for log5n.
                j = i;
                while (j > 1){                      O(logn)   This decremebts the same way log5n ... 125 + 25 + 5
                    total += 1;
                    j /= 5;
                }
            }
            return total;
        }

        So ultimately we get logn * logn. T(function2) = theata(log^2n)
*/