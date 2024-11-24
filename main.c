#include <stdio.h>
#include <math.h>
#include <float.h>

void BF_closest_pair(int n, double points[][2], int *index1, int *index2) {
    double dmin = DBL_MAX; // Initialize to a very large value
    double d;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate Euclidean distance
            d = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
            if (d < dmin) {
                dmin = d;
                *index1 = i;
                *index2 = j;
            }
        }
    }
}

int main() {
    int n, index1, index2;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    double points[n][2];
    printf("Enter the coordinates of the points (x y):\n");



    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }

    // Print the given points
    printf("The given points are:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: (%.2lf, %.2lf)\n", i, points[i][0], points[i][1]);
    }

    BF_closest_pair(n, points, &index1, &index2);

    printf("The closest pair of points are at indices: %d and %d\n", index1, index2);
    return 0;
}

