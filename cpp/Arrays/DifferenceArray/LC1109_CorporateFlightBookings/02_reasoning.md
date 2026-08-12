Learning Journal:
    Input:
        - n flights from 1 to n
        - array of flight bookings
        - bookings[i] = [first, last, seats]
    
    Output:
        - an array answer where answer[i] = total number of seats reserved for flight i+1

    Edge Cases:
        - first[i] == last[i]
        - n == 1
        - last == n
    
    Brute Force:
        - create an array flights of size n, which will store number of passengers in that flight
        - for each booking:
            - update number of passengers from flights[first - 1] to flights[last - 1] as:
                - flights[i] += passengers
        - finally return flights array

    Complexity:
        Time: O(books.length * n)
        Auxiliary Space: O(1)
        Total Space: O(n)

    Repeated Work:
        - continuously updating same index again ad again for overlapping bookings

    Information to Remember:
        - We just need to know from which flight x passengers started to board and the last flight x passengers didn't board
        - We can mark the first flight and last + 1 flight with +passengers and -passengers respectively
        - Later we can find total passengers with cumulative sum

    Pattern:
        - cumulative sum with range updates -> prefix sum + difference array
