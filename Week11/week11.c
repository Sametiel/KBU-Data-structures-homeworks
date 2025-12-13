#include <stdio.h>
#include <math.h>


typedef struct {
    double x;
    double y;
    int cluster_id; 
} Node;


double calculate_distance(Node p1, double x2, double y2) {
    return sqrt(pow(p1.x - x2, 2) + pow(p1.y - y2, 2));
}

int main() {
    
    Node data[] = {
        {1.0, 1.0, 0},
        {1.5, 2.0, 0},
        {8.0, 7.0, 0},
        {9.0, 8.0, 0},
        {2.0, 1.5, 0}
    };
    int N = sizeof(data) / sizeof(Node);

    double centroid1_x = 1.0, centroid1_y = 1.0; 
    double centroid2_x = 9.0, centroid2_y = 9.0; 

    printf("--- Simple Clustering Started ---\n");

    
    for (int i = 0; i < N; i++) {
        double d1 = calculate_distance(data[i], centroid1_x, centroid1_y);
        double d2 = calculate_distance(data[i], centroid2_x, centroid2_y);

    
        if (d1 < d2) {
            data[i].cluster_id = 1; 
            printf("Point (%.1f, %.1f): Assigned to Centroid 1 (Distance: %.2f)\n", data[i].x, data[i].y, d1);
        } else {
            data[i].cluster_id = 2; 
            printf("Point (%.1f, %.1f): Assigned to Centroid 2 (Distance: %.2f)\n", data[i].x, data[i].y, d2);
        }
    }

    printf("\n--- Final Clustering Result ---\n");
    
    for (int i = 0; i < N; i++) {
        printf("Node (%.1f, %.1f) -> Cluster %d\n", data[i].x, data[i].y, data[i].cluster_id);
    }
    
    return 0;
}