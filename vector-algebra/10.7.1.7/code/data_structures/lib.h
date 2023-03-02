// Defining the Structure
typedef struct node {
    double data;
    struct node *next;
} Node;

// Function to create a new node
Node *createNode(double data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a matrix as a linked list of linked lists
Node **createMat(int m, int n) {
    Node **mat = (Node **) malloc(m * sizeof(Node *));
    int i;
    for (i = 0; i < m; i++) {
        mat[i] = NULL;
    }
    return mat;
}

// Function to load matrix from a .dat file
Node** loadtxt(char *filename, int m, int n) {
    Node** matrix = (Node**) malloc(m * sizeof(Node*));
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(1);
    }
    int i, j;
    double value;
    for (i = 0; i < m; i++) {
        matrix[i] = NULL;
        Node* current = NULL;
        for (j = 0; j < n; j++) {
            if (fscanf(fp, "%lf", &value) == 1) {
                Node* new_node = (Node*) malloc(sizeof(Node));
                new_node->data = value;
                new_node->next = NULL;
                if (matrix[i] == NULL) {
                    matrix[i] = new_node;
                    current = new_node;
                } else {
                    current->next = new_node;
                    current = current->next;
                }
            } else {
                printf("Error: Unable to read matrix from file '%s'\n", filename);
                exit(1);
            }
        }
    }
    fclose(fp);
    return matrix;
}

// Function for printing the matrix
void print(Node** matrix, int rows, int cols) {
    int i, j;
    Node* current;
    for (i = 0; i < rows; i++) {
        current = matrix[i];
        for (j = 0; j < cols; j++) {
            printf("%.2f ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function for Finding the norm of the matrix
double linalg_norm(Node **mat, int m, int n) {
    double sum = 0.0;
    int i, j;
    for (i = 0; i < m; i++) {
        Node *rowHead = mat[i];
        double rowSum = 0.0;
        for (j = 0; j < n; j++) {
            double value = rowHead->data;
            rowSum += value * value;
            rowHead = rowHead->next;
        }
        sum += rowSum;
    }
    return sqrt(sum);
}

// Function for finding the subtraction of the two matrices
void linalg_sub(Node **mat1, Node **mat2, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        Node *row1 = mat1[i];
        Node *row2 = mat2[i];
        for (j = 0; j < n; j++) {
            double value = row1->data - row2->data;
            row1->data = value;
            row1 = row1->next;
            row2 = row2->next;
        }
    }
}

// function to multiply two matrices

Node **matmul(Node **matrix1, int m1, int n1, Node **matrix2, int m2, int n2) {
    if (n1 != m2) {
        printf("Error: Invalid dimensions for matrix multiplication\n");
        exit(1);
    }

    Node **result = (Node **) malloc(m1 * sizeof(Node *));
    int i, j, k;
    for (i = 0; i < m1; i++) {
        result[i] = (Node *) malloc(n2 * sizeof(Node));
        for (j = 0; j < n2; j++) {
            result[i][j].data = 0.0;
            result[i][j].next = NULL;
        }
    }
    Node *p, *q;
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            p = &(result[i][j]);
            for (k = 0; k < n1; k++) {
                q = &(matrix2[k][j]);
                p->data += matrix1[i][k].data * q->data;
                if (k < n1-1) {
                    p->next = (Node *) malloc(sizeof(Node));
                    p = p->next;
                    p->data = 0.0;
                    p->next = NULL;
                }
            }
        }
    }
    return result;
}

// Function for finding the Transpose of the matrix
Node** transpose(Node** matrix, int rows, int cols) {
    Node** transpose = (Node**) malloc(cols * sizeof(Node*));
    int i, j;
    Node* current;
    for (i = 0; i < cols; i++) {
        transpose[i] = NULL;
        Node* current_transpose = NULL;
        for (j = 0; j < rows; j++) {
            current = matrix[j];
            int k;
            for (k = 0; k < i; k++) {
                current = current->next;
            }
            Node* new_node = (Node*) malloc(sizeof(Node));
            new_node->data = current->data;
            new_node->next = NULL;
            if (transpose[i] == NULL) {
                transpose[i] = new_node;
                current_transpose = new_node;
            } else {
                current_transpose->next = new_node;
                current_transpose = current_transpose->next;
            }
        }
    }
    return transpose;
}

// Function for multiplying the matrix with the float value
void mat_val(Node** matrix, int rows, int cols, float value) {
    int i, j;
    Node* current;
    for (i = 0; i < rows; i++) {
        current = matrix[i];
        for (j = 0; j < cols; j++) {
            current->data *= value;
            current = current->next;
        }
    }
}

// Function for saving the matrix into a .dat file
void save(char *filename, Node **matrix, int m, int n) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s' for writing\n", filename);
        exit(1);
    }
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            fprintf(fp, "%lf ", matrix[i][j].data);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

