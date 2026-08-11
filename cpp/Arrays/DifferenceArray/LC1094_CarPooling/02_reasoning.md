Learning Journal:
    Input:
        - Given capacity of the car
        - The car only drives east
        - an array trips with each trip having value as [num_of_passengers, from, to]
        - from and to are in kms due east from car's initial position
        - from is always less than to

    Output:
        - boolean result based on whether all trips are possible or not
        - single value
    
    Brute Force:
        - create a num_of_passengers array of size 1001 with default value 0
        - in this array index will represent number of kms from car's initial position and value will represent number of passengers in the car after boarding and leaving the car at that location
        - for each trip in trips:
            - update from num_of_passengers[from] to num_of_passengers[to] by adding trip[passengers]

        - now scan the array to check if any value exceeds capacity
        - return true if no, else false

    Complexity:
        Time: O(n * q), where q is total trips and n is constant 1000
        Space: O(n), where n is constant 1000

    Repeated Work:
        - We are updating same index if it exists between "from" and "to" in multiple trips

    Information to Remember:
        - We can mark the starting location with how many passengers are boarding at that location and an ending location with how many passengers are deboarding
        - Finally find cumulative passengers and check if at any point cumulative passengers exceeds capacity, return false
        - finally return true

    Pattern: 
        - Cumulative range sum -> Prefix Sum + Difference Array