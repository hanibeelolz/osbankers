#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char** argv) {
    int rank, size;
    int local_sum = 0, global_sum = 0;
    int numbers[ARRAY_SIZE];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Initialize random numbers
    srand(rank); // Using rank to get different random numbers for each process
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % 100; // Generating random numbers between 0 and 99
    }

    // Calculate local sum of odd numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (numbers[i] % 2 != 0) {
            local_sum += numbers[i];
        }
    }

    // Reduce local sums to get global sum
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Output global sum from rank 0
    if (rank == 0) {
        printf("The sum of all odd random numbers is: %d\n", global_sum);
    }

    MPI_Finalize();

    return 0;
}
