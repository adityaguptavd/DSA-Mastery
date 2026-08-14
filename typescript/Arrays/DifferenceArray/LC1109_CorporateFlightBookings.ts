function corpFlightBookings(bookings: number[][], n: number): number[] {
    const answer: number[] = Array(n + 1).fill(0);
    for(const [firstFlight, lastFlight, seats] of bookings) {
        answer[firstFlight - 1] += seats;
        answer[lastFlight] -= seats;
    }
    for(let i = 1; i < n; ++i) {
        answer[i] += answer[i - 1];
    }
    return answer.slice(0, n);
};