#ifndef RC_MATRIX_H_INCLUDED
#define RC_MATRIX_H_INCLUDED

#include <iostream>
#include <vector>
#ifndef RC_WEB
#ifndef RC_ANDROID
#ifndef RC_IOS
    #include <bits/stdc++.h>
#endif
#endif
#endif
#include <cstdlib>
#include <ctime>

#include <irrlicht.h>

using namespace std;


int64_t rand_int(int64_t vmin, int64_t vmax) {
    return std::rand() % (vmax - vmin + 1) + vmin;
}


struct rc_matrix_type
{
	bool active = false;
    uint32_t r = 0;
    uint32_t c = 0;
    vector<double> data;
};

std::vector<rc_matrix_type> rc_matrix(64);


#define NEW_MATRIX -1

int DimMatrix(int m, uint32_t m_rows, uint32_t m_cols, bool preserve_flag=false)
{
	if(m < 0)
	{
		for(int i = 0; i < rc_matrix.size(); i++)
		{
			if(!rc_matrix[i].active)
			{
				m = i;
				break;
			}
		}

		if(m < 0)
		{
			rc_matrix_type mat;
			mat.active = true;
			m = rc_matrix.size();
			rc_matrix.push_back(mat);
		}
	}

	if(!preserve_flag)
		rc_matrix[m].data.clear();

    rc_matrix[m].data.resize(m_rows*m_cols);

    if(rc_matrix[m].c != m_cols && preserve_flag)
    {
        vector<double> old_data = rc_matrix[m].data;
        uint32_t old_offset = 0;
        uint32_t new_offset = 0;
        for(uint32_t row = 0; row < m_rows; row++)
        {
            old_offset = row * rc_matrix[m].c;
            new_offset = row * m_cols;
            for(uint32_t col = 0; col < m_cols; col++)
            {
                rc_matrix[m].data[new_offset + col] = old_data[old_offset + col];
            }
        }
    }

    rc_matrix[m].r = m_rows;
    rc_matrix[m].c = m_cols;
    rc_matrix[m].active = true;

    return m;
}

int rc_dimMatrix(uint32_t m_rows, uint32_t m_cols)
{
	return DimMatrix(NEW_MATRIX, m_rows, m_cols, false);
}

void rc_deleteMatrix(int mA)
{
	if(mA < 0 || mA >= rc_matrix.size())
		return;
	rc_matrix[mA].data.clear();
	rc_matrix[mA].c = 0;
	rc_matrix[mA].r = 0;
	rc_matrix[mA].active = false;
}

//Adds Matrix A() to Matrix B(), answer is Matrix C()
bool rc_addMatrix(int mA, int mB, int mC)
{
    if( (rc_matrix[mA].r != rc_matrix[mB].r) || (rc_matrix[mA].c != rc_matrix[mB].c) )
    {
        std::cout << "AddMatrix Error: Matrix sizes don't match" << std::endl;
        return false;
    }

    DimMatrix(mC, rc_matrix[mA].r, rc_matrix[mA].c);

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mC].data[ row_offset + col ] = rc_matrix[mA].data[ row_offset + col] + rc_matrix[mB].data[ row_offset + col];
        }
    }

    return true;
}

//Concatenates matrix A() and B(), output is matrix C()
bool rc_augmentMatrix (int mA, int mB, int mC)
{
    if(rc_matrix[mA].r != rc_matrix[mB].r)
    {
        std::cout << "AugmentMatrix Error: Row Counts don't match" << std::endl;
        return false;
    }

    DimMatrix(mC, rc_matrix[mA].r, rc_matrix[mA].c + rc_matrix[mB].c);

    uint32_t row_offset = 0;
    uint32_t ab_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        ab_offset = row * rc_matrix[mA].c;
        row_offset = row * rc_matrix[mC].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mC].data[ row_offset + col ] = rc_matrix[mA].data[ ab_offset + col ];
        }
    }

    for(uint32_t row = 0; row < rc_matrix[mB].r; row++)
    {
        ab_offset = row * rc_matrix[mB].c;
        row_offset = row * rc_matrix[mC].c;
        for(uint32_t col = 0; col < rc_matrix[mB].c; col++)
        {
            rc_matrix[mC].data[ row_offset + col + rc_matrix[mA].c] = rc_matrix[mB].data[ ab_offset + col ];
        }
    }

    return true;
}

//Copies contents of matrix A() to B()
void rc_copyMatrix(int mA, int mB)
{
    DimMatrix(mB, rc_matrix[mA].r, rc_matrix[mA].c);

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mB].data[row_offset + col] = rc_matrix[mA].data[row_offset + col];
        }
    }
}

//Inserts specified number of columns in matrix A before c and shifts values to the right
bool rc_insertMatrixColumns(int mA, uint32_t c, uint32_t num_cols)
{
    if(c >= rc_matrix[mA].c)
    {
        std::cout << "InsertMatrixColumn Error: Can't insert past the last column" << std::endl;
        return false;
    }

    vector<double> old_data = rc_matrix[mA].data;
    uint32_t old_c = rc_matrix[mA].c;
    uint32_t old_r = rc_matrix[mA].r;

    DimMatrix(mA, rc_matrix[mA].r, rc_matrix[mA].c + num_cols);

    uint32_t old_offset = 0;
    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        old_offset = row * old_c;
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            if(col >= c)
            {
                if(col < (c+num_cols))
                    rc_matrix[mA].data[row_offset + col] = 0;

                if(col < old_c)
                    rc_matrix[mA].data[row_offset + col + num_cols] = old_data[old_offset + col];
            }
            else
                rc_matrix[mA].data[row_offset + col] = old_data[old_offset + col];
        }
    }

    return true;
}

//Creates new zero row M% in matrix A(), moves values down
bool rc_insertMatrixRows(int mA, uint32_t r, uint32_t num_rows)
{
    if(r >= rc_matrix[mA].r)
    {
        std::cout << "InsertMatrixRow Error: Can't insert past the last row" << std::endl;
        return false;
    }

    DimMatrix(mA, rc_matrix[mA].r + num_rows, rc_matrix[mA].c);

    uint32_t row_offset = 0;
    uint32_t new_offset = 0;
    bool shift_row = true;
    for(uint32_t row = r; row < (r + num_rows); row++)
    {
        row_offset = row * rc_matrix[mA].c;
        if((row + num_rows) < rc_matrix[mA].r)
        {
            shift_row = true;
            new_offset = (row+num_rows) * rc_matrix[mA].c;
        }
        else
            shift_row = false;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            if(shift_row)
                rc_matrix[mA].data[new_offset + col] = rc_matrix[mA].data[row_offset + col];
            rc_matrix[mA].data[row_offset + col] = 0;
        }
    }

    return true;
}

//Multiplies Matrix A() with Matrix B(), answer is Matrix C()
bool rc_multiplyMatrix (int mA, int mB, int mC)
{
    if( rc_matrix[mA].c != rc_matrix[mB].r )
    {
        std::cout << "MultiplyMatrix Error: matrix A rows and matrix B columns must be equal." << std::endl;
        return false;
    }

    DimMatrix( mC, rc_matrix[mA].r, rc_matrix[mB].c);

    double total = 0;
    uint32_t a_offset = 0;
    uint32_t b_offset = 0;
    uint32_t c_offset = 0;
    for(uint32_t a_row = 0; a_row < rc_matrix[mA].r; a_row++) //I
    {
        a_offset = a_row * rc_matrix[mA].c;
        for(uint32_t b_col = 0; b_col < rc_matrix[mB].c; b_col++) //J
        {
            for(uint32_t a_col = 0; a_col < rc_matrix[mA].c; a_col++) //N
            {
                b_offset = a_col * rc_matrix[mB].c;
                total = total + rc_matrix[mA].data[a_offset + a_col] * rc_matrix[mB].data[b_offset + b_col];
            }
            c_offset = a_row * rc_matrix[mB].c;
            rc_matrix[mC].data[c_offset + b_col] = total;
            total = 0;
        }
    }

    return true;
}

//Multiplies matrix A() * A() * A(), returns matrix B()
bool rc_cubeMatrix(int mA, int mB)
{
    if(rc_matrix[mA].r != rc_matrix[mA].c)
    {
        std::cout << "CubeMatrix Error: matrix A is not a square matrix." << std::endl;
        return false;
    }

    int tmp_mat1 = DimMatrix(NEW_MATRIX, rc_matrix[mA].r, rc_matrix[mA].c);
    rc_multiplyMatrix(mA, mA, tmp_mat1);
    rc_multiplyMatrix(tmp_mat1, mA, mB);

    rc_deleteMatrix(tmp_mat1);
    return true;
}

// Deletes column N% from matrix
bool rc_deleteMatrixColumns(int mA, uint32_t c, uint32_t num_cols)
{
    if(c >= rc_matrix[mA].c)
    {
        std::cout << "DeleteMatrixColumn Error: column is outside of matrix" << std::endl;
        return false;
    }

    if((c + num_cols) > rc_matrix[mA].c)
        num_cols = rc_matrix[mA].c - c;

    int tmp_mat1 = DimMatrix( NEW_MATRIX, rc_matrix[mA].r, rc_matrix[mA].c - num_cols);

    uint32_t old_offset = 0;
    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        old_offset = row * rc_matrix[mA].c;
        row_offset = row * rc_matrix[tmp_mat1].c;
        for(uint32_t col = 0; col < rc_matrix[tmp_mat1].c; col++)
        {
            if(col >= c)
            {
                rc_matrix[tmp_mat1].data[row_offset + col] = rc_matrix[mA].data[old_offset + col + num_cols];
            }
            else
                rc_matrix[tmp_mat1].data[row_offset + col] = rc_matrix[mA].data[old_offset + col];
        }
    }
    rc_copyMatrix(tmp_mat1, mA);
    rc_deleteMatrix(tmp_mat1);
    return true;
}

//Deletes row M% from matrix
bool rc_deleteMatrixRows(int mA, uint32_t r, uint32_t num_rows)
{
    if(r >= rc_matrix[mA].r)
    {
        std::cout << "DeleteMatrixRow Error: row is outside of matrix." << std::endl;
        return false;
    }

    if((r + num_rows) > rc_matrix[mA].r)
        num_rows = rc_matrix[mA].r - r;

    uint32_t new_row_count = rc_matrix[mA].r - num_rows;

    uint32_t old_offset = 0;
    uint32_t row_offset = 0;

    for(uint32_t row = r; row < new_row_count; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        old_offset = (row+num_rows) * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mA].data[row_offset + col] = rc_matrix[mA].data[old_offset + col];
        }
    }

    DimMatrix( mA, rc_matrix[mA].r - num_rows, rc_matrix[mA].c);

    return true;
}

//Clears contents of matrix A()
void rc_clearMatrix(int mA)
{
    for(int i = 0; i < rc_matrix[mA].data.size(); i++)
        rc_matrix[mA].data[i] = 0;
}

//Fills column J% of matrix A() with zeros
bool rc_clearMatrixColumns (int mA, uint32_t c, uint32_t num_cols)
{
    if(c >= rc_matrix[mA].c)
    {
        std::cout << "ClearMatrixColumn Error: column is outside of matrix A" << std::endl;
        return false;
    }

    if( (c+num_cols) > rc_matrix[mA].c)
        num_cols = rc_matrix[mA].c - c;

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = c; col < (c+num_cols); col++)
            rc_matrix[mA].data[row_offset + col] = 0;
    }

    return true;
}

// Fills row I% of matrix A() with zeros
bool rc_clearMatrixRows(int mA, uint32_t r, uint32_t num_rows)
{
    if(r >= rc_matrix[mA].r)
    {
        std::cout << "ClearMatrixRow Error: row is outside of matrix A" << std::endl;
        return false;
    }

    if((r + num_rows) > rc_matrix[mA].r)
        num_rows = rc_matrix[mA].r - r;

    uint32_t row_offset = 0;

    for(uint32_t row = r; row < (r+num_rows); row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mA].data[row_offset + col] = 0;
        }
    }

    return true;
}

// Fills matrix A() with value V
void rc_fillMatrix(int mA, double v)
{
    for(uint32_t i = 0; i < rc_matrix[mA].data.size(); i++)
        rc_matrix[mA].data[i] = v;
}

// Fills matrix A() column J% with value V
bool rc_fillMatrixColumns(int mA, uint32_t c, uint32_t num_cols, double v)
{
    if(c >= rc_matrix[mA].c)
    {
        std::cout << "FillMatrixColumns Error: column is outside of matrix A" << std::endl;
        return false;
    }

    if( (c+num_cols) >= rc_matrix[mA].c)
        num_cols = rc_matrix[mA].c - c;

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = c; col < (c+num_cols); col++)
            rc_matrix[mA].data[row_offset + col] = v;
    }

    return true;
}

// Fills matrix A() row I% with value V
bool rc_fillMatrixRows(int mA, uint32_t r, uint32_t num_rows, double v)
{
    if(r >= rc_matrix[mA].r)
    {
        std::cout << "FillMatrixRows Error: row is outside of matrix A" << std::endl;
        return false;
    }

    if( (r+num_rows) > rc_matrix[mA].r)
        num_rows = rc_matrix[mA].r - r;

    uint32_t row_offset = 0;

    for(uint32_t row = r; row < (r+num_rows); row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mA].data[row_offset + col] = v;
        }
    }

    return true;
}

// Copies A() column J% to column matrix B()
bool rc_copyMatrixColumns(uint32_t mA, uint32_t mB, uint32_t c, uint32_t num_cols)
{
    if(c >= rc_matrix[mA].c)
    {
        std::cout << "GetMatrixColumn Error: column outside of matrix A" << std::endl;
        return false;
    }

    if( (c+num_cols) >= rc_matrix[mA].c)
        num_cols = rc_matrix[mA].c - c;

    DimMatrix(mB, rc_matrix[mA].r, num_cols);

    int row_offset = 0;
    int b_offset = 0;
    for(int row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        b_offset = row * num_cols;
        for(uint32_t col = c; col < (c+num_cols); col++)
            rc_matrix[mB].data[b_offset + (col-c)] = rc_matrix[mA].data[row_offset + c];
    }

    return true;
}

// Copies A() row I% to row matrix B()
bool rc_copyMatrixRows (uint32_t mA, uint32_t mB, uint32_t r, uint32_t num_rows)
{

    if(r > rc_matrix[mA].r)
    {
        std::cout << "GetMatrixRow Error: row outside of matrix A" << std::endl;
        return false;
    }

    if( (r+num_rows) > rc_matrix[mA].r)
        num_rows = rc_matrix[mA].r - r;

    DimMatrix( mB, num_rows, rc_matrix[mA].c);

    uint32_t row_offset = 0;

    for(uint32_t row = r; row < (r+num_rows); row++)
    {
        row_offset = row * rc_matrix[mA].c;

        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mB].data[row_offset + col] = rc_matrix[mA].data[row_offset + col];
        }
    }

    return true;
}

// Creates Identity Matrix A() of order N%
void rc_setIdentityMatrix(uint32_t mA, uint32_t n)
{
    DimMatrix(mA, n, n);
    for(int i = 0; i < n; i++)
        rc_matrix[mA].data[i*(n+1)] = 1;
}

bool GaussianElimination(vector< vector<double> > &A, vector<double> &b, uint32_t mC) {
    int n = b.size();

    for (int p = 0; p < n; p++) {
        int max_index = p;
        for (int i = p + 1; i < n; i++) {
            if (abs(A[i][p]) > abs(A[max_index][p])) {
                max_index = i;
            }
        }

        swap(A[p], A[max_index]);
        swap(b[p], b[max_index]);

        for (int i = p + 1; i < n; i++) {
            if(A[p][p] == 0)
                return false;
            double alpha = A[i][p] / A[p][p];
            b[i] -= alpha * b[p];
            for (int j = p; j < n; j++) {
                A[i][j] -= alpha * A[p][j];
            }
        }
    }

    vector<double> x(n);
    DimMatrix(mC, n, 1);
    rc_clearMatrix(mC);

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * rc_matrix[mC].data[j];
        }
        if(A[i][i] == 0)
            return false;
        rc_matrix[mC].data[i] = (b[i] - sum) / A[i][i];
    }

    return true;
}

// Solve the system that has A as coefficient matrix and B is the right hand side of the equation
// Solution will be stored in C
bool rc_solveMatrix(uint32_t mA, uint32_t mB, uint32_t mC)
{
    if(rc_matrix[mA].r != rc_matrix[mA].c || rc_matrix[mA].r != rc_matrix[mB].r || rc_matrix[mB].c != 1)
        return false;

    vector< vector<double> > A(rc_matrix[mA].r);
    vector<double> b;

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            A[row].push_back(rc_matrix[mA].data[row_offset + col]);
        }
    }

    for(int i = 0; i < rc_matrix[mB].data.size(); i++)
        b.push_back(rc_matrix[mB].data[i]);

    return GaussianElimination(A, b, mC);
}

double d_abs(double n)
{
    return (n < 0) ? n * -1 : n;
}

//Determines if matrix A() is equal (within Tol constant) to matrix B()
bool rc_isEqualMatrix(uint32_t mA, uint32_t mB, double tolerance)
{
    if( (rc_matrix[mA].r != rc_matrix[mB].r) || (rc_matrix[mA].c != rc_matrix[mB].c) )
        return false;

    uint32_t row_offset = 0;

    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            if(d_abs( rc_matrix[mA].data[row_offset + col] - rc_matrix[mB].data[row_offset + col] ) > tolerance)
                return false;
        }
    }
    return true;
}

// Function to get cofactor of A[p][q] in temp[][]. n is
// current dimension of A[][]
void getCofactor(uint32_t A_dim, double* A, double* temp, int p, int q,
				int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			// Copying into temporary matrix only those
			// element which are not in given row and
			// column
			if (row != p && col != q) {
				temp[i*A_dim + j++] = A[row*A_dim + col];

				// Row is filled, so increase row index and
				// reset col index
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

void rc_cofactorMatrix(uint32_t mA, int p, int q, int n)
{

    uint32_t m_size = rc_matrix[mA].c;
    double temp[m_size*rc_matrix[mA].r];
    getCofactor(m_size, rc_matrix[mA].data.data(), temp, p, q, n);
    DimMatrix(mA, m_size-1, m_size-1);
    uint32_t row_offset = 0;
    uint32_t temp_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        temp_offset = row * m_size;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mA].data[row_offset + col] = temp[temp_offset + col];
        }
    }
}

/* Recursive function for finding determinant of matrix.
n is current dimension of A[][]. */
double determinant(double* A, int n, uint32_t m_size)
{
	double D = 0; // Initialize result

	// Base case : if matrix contains single element
	if (n == 1)
		return A[0];

	double temp[m_size*m_size]; // To store cofactors

	int sign = 1; // To store sign multiplier

	// Iterate for each element of first row
	for (int f = 0; f < n; f++) {
		// Getting Cofactor of A[0][f]
		getCofactor(m_size, A, temp, 0, f, n);
		D += sign * A[f] * determinant(temp, n - 1, m_size);

		// terms are to be added with alternate sign
		sign = -sign;
	}

	return D;
}

double rc_determinant(uint32_t mA)
{
    uint32_t m_size = rc_matrix[mA].r;
    if(rc_matrix[mA].c != m_size)
    {
        cout << "Determinant Error: matrix must be square" << endl;
        return 0;
    }
    return determinant(rc_matrix[mA].data.data(), m_size, m_size);
}


// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(double* A, double* adj, uint32_t n, uint32_t m_size)
{
	if (n == 1) {
		adj[0] = 1;
		return;
	}

	// temp is used to store cofactors of A[][]
	int sign = 1;
	double temp[n*n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Get cofactor of A[i][j]
			getCofactor(n, A, temp, i, j, n);

			// sign of adj[j][i] positive if sum of row
			// and column indexes is even.
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the
			// transpose of the cofactor matrix
			adj[j*n+i] = (sign) * (determinant(temp, n - 1, m_size));
		}
	}
}

bool rc_adjointMatrix(uint32_t mA, uint32_t mB)
{
    uint32_t m_size = rc_matrix[mA].r;
    if(rc_matrix[mA].c != m_size)
    {
        cout << "MatrixAdjoint Error: matrix must be square" << endl;
        return false;
    }
    DimMatrix(mB, m_size, m_size);
    adjoint(rc_matrix[mA].data.data(), rc_matrix[mB].data.data(), m_size, m_size);
    return true;
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(double* A, double* inv, uint32_t n)
{
	// Find determinant of A[][]
	double det = determinant(A, n, n);
	if (det == 0) {
		return false;
	}

	// Find adjoint
	double adj[n*n];
	adjoint(A, adj, n, n);

	// Find Inverse using formula "inverse(A) =
	// adj(A)/det(A)"
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inv[i*n+j] = adj[i*n+j] / det;

	return true;
}

bool rc_invertMatrix(uint32_t mA, uint32_t mB)
{
    uint32_t m_size = rc_matrix[mA].r;
    if(rc_matrix[mA].c != m_size)
    {
        cout << "InvertMatrix Error: matrix must be square" << endl;
        return false;
    }
    DimMatrix(mB, m_size, m_size);
    if(!inverse(rc_matrix[mA].data.data(), rc_matrix[mB].data.data(), m_size))
    {
        cout << "InvertMatrix Error: Singular matrix, can't find its inverse" << endl;
        return false;
    }
    return true;
}


//Loads contents of FileName$ into matrix A()
void rc_matrixFromBuffer(uint32_t mA, uint32_t r, uint32_t c, double* buffer)
{
    uint32_t row_offset = 0;
    DimMatrix(mA, r, c);

    for(uint32_t row = 0; row < r; row++)
    {
        row_offset = row*c;
        for(uint32_t col = 0; col < c; col++)
        {
            rc_matrix[mA].data[row_offset + col] = buffer[row_offset + col];
        }
    }
}

//Loads contents of FileName$ into matrix A()
void rc_bufferFromMatrix(double* buffer, uint32_t mA)
{
    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row*rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            buffer[row_offset + col] = rc_matrix[mA].data[row_offset + col];
        }
    }
}

//Fills matrix A() with random values ranging from VMin to VMax
void rc_randomizeMatrix(uint32_t mA, double vmin, double vmax)
{
    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mA].data[row_offset + col] = rand_int(vmin, vmax);
        }
    }
}

//get value from matrix A
double rc_matrixValue(uint32_t mA, uint32_t r, uint32_t c)
{
    uint32_t pos = r*rc_matrix[mA].c + c;
    if(pos >= rc_matrix[mA].data.size())
        return 0;

    return rc_matrix[mA].data[pos];
}

//set value at (r, c) in matrix
void rc_setMatrixValue(uint32_t mA, uint32_t r, uint32_t c, double v)
{
    uint32_t pos = r*rc_matrix[mA].c + c;
    if(pos >= rc_matrix[mA].data.size())
        return;

    rc_matrix[mA].data[pos] = v;
}

//Multiplies matrix A() by scalar, output matrix B()
void rc_scalarMatrix (uint32_t mA, uint32_t mB, double s_value)
{
    uint32_t row_offset = 0;
    DimMatrix(mB, rc_matrix[mA].r, rc_matrix[mA].c);
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mB].data[row_offset + col] = s_value * rc_matrix[mA].data[row_offset + col];
        }
    }
}

// Multiplies matrix A() by scalar S at column J%, output matrix B()
bool rc_scalarMatrixColumns(uint32_t mA, uint32_t mB, uint32_t c, uint32_t num_cols, double s_value)
{
    if(c >= rc_matrix[mA].c)
    {
        std::cout << "ScalarMatrixColumn Error: column outside of matrix A" << std::endl;
        return false;
    }

    if( (c+num_cols) >= rc_matrix[mA].c)
        num_cols = rc_matrix[mA].c - c;

    rc_copyMatrix(mA, mB);

    int row_offset = 0;
    for(int row = 0; row < rc_matrix[mB].r; row++)
    {
        row_offset = row * rc_matrix[mB].c;
        for(uint32_t col = c; col < (c+num_cols); col++)
            rc_matrix[mB].data[row_offset + col] *= s_value;
    }

    return true;
}

//Multiplies matrix A() by scalar S at row I%, output matrix B()
bool rc_scalarMatrixRows(uint32_t mA, uint32_t mB, uint32_t r, uint32_t num_rows, double s_value)
{

    if(r > rc_matrix[mA].r)
    {
        std::cout << "ScalarMatrixRows Error: row outside of matrix A" << std::endl;
        return false;
    }

    if( (r+num_rows) > rc_matrix[mA].r)
        num_rows = rc_matrix[mA].r - r;

    rc_copyMatrix(mA, mB);

    uint32_t row_offset = 0;

    for(uint32_t row = r; row < (r+num_rows); row++)
    {
        row_offset = row * rc_matrix[mA].c;

        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mB].data[row_offset + col] = s_value * rc_matrix[mA].data[row_offset + col];
        }
    }

    return true;
}

// Multiplies matrix A() * A(), returns matrix B()
bool rc_squareMatrix(uint32_t mA, uint32_t mB)
{
    if(rc_matrix[mA].r != rc_matrix[mA].c)
    {
        std::cout << "SquareMatrix Error: must be a square matrix" << std::endl;
        return false;
    }

    return rc_multiplyMatrix(mA, mA, mB);
}

// Deletes row r and column c from matrix A
void rc_subMatrix(uint32_t mA, uint32_t r, uint32_t c)
{
    rc_cofactorMatrix(mA, r, c, rc_matrix[mA].c);
}

// Subtracts Matrix B() from Matrix A(), answer is Matrix C()
bool rc_subtractMatrix (uint32_t mA, uint32_t mB, uint32_t mC)
{
    if(rc_matrix[mA].r != rc_matrix[mB].r || rc_matrix[mA].c != rc_matrix[mB].c)
    {
        std::cout << "SubtractMatrix Error: matrix A and B differ in size" << std::endl;
        return false;
    }

    DimMatrix(mC, rc_matrix[mA].r, rc_matrix[mA].c);

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            rc_matrix[mC].data[row_offset + col] = rc_matrix[mA].data[row_offset + col] - rc_matrix[mB].data[row_offset + col];
        }
    }

    return true;
}

// Swaps contents of Matrix A() with Matrix B()
void rc_swapMatrix(uint32_t mA, uint32_t mB)
{
    int tmp_mat1 = DimMatrix(NEW_MATRIX, rc_matrix[mA].r, rc_matrix[mA].c);
    rc_copyMatrix(mB, tmp_mat1);
    rc_copyMatrix(mA, mB);
    rc_copyMatrix(tmp_mat1, mA);
    rc_deleteMatrix(tmp_mat1);
}

// Swaps columns C1% and C2% in matrix A()
bool rc_swapMatrixColumn(uint32_t mA, uint32_t C1, uint32_t C2)
{
    if(C1 >= rc_matrix[mA].c || C2 >= rc_matrix[mA].c)
    {
        std::cout << "SwapMatrixColumn Error: C1 or C2 refers to column outside of A" << std::endl;
        return false;
    }

    double tmp = 0;

    uint32_t row_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        tmp = rc_matrix[mA].data[row_offset + C1];
        rc_matrix[mA].data[row_offset + C1] = rc_matrix[mA].data[row_offset + C2];
        rc_matrix[mA].data[row_offset + C2] = tmp;
    }

    return true;
}

// Swaps rows R1% and R2% in matrix A()
bool rc_swapMatrixRow(uint32_t mA, uint32_t R1, uint32_t R2)
{
    if(R1 >= rc_matrix[mA].r || R2 >= rc_matrix[mA].r)
    {
        std::cout << "SwapMatrixRow Error: R1 or R2 refers to row outside of A" << std::endl;
        return false;
    }

    double tmp = 0;
    uint32_t r1_offset = R1 * rc_matrix[mA].c;
    uint32_t r2_offset = R2 * rc_matrix[mA].c;

    for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
    {
        tmp = rc_matrix[mA].data[r1_offset + col];
        rc_matrix[mA].data[r1_offset + col] = rc_matrix[mA].data[r2_offset + col];
        rc_matrix[mA].data[r2_offset + col] = tmp;
    }

    return true;
}

// Transposes matrix A(), output matrix B()
bool rc_transposeMatrix(uint32_t mA, uint32_t mB)
{
    DimMatrix(mB, rc_matrix[mA].c, rc_matrix[mA].r);

    uint32_t row_offset = 0;
    uint32_t trans_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mA].r; row++)
    {
        row_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mA].c; col++)
        {
            trans_offset = col * rc_matrix[mB].c;
            rc_matrix[mB].data[trans_offset + row] = rc_matrix[mA].data[row_offset + col];
        }
    }
    return true;
}


// Splits matrix A() into square Coefficient B() and remaining Augment C()
bool rc_unAugmentMatrix(uint32_t mA, uint32_t mB, uint32_t mC)
{
    if(rc_matrix[mA].c <= rc_matrix[mA].r)
    {
        std::cout << "UnAugmentMatrix Error:  matrix A must have more columns than rows" << std::endl;
        return false;
    }

    //Br% = Ar%:
    //Bc% = Ar%:
    DimMatrix(mB, rc_matrix[mA].r, rc_matrix[mA].r);

    //Cr% = Ar%:
    //Cc% = Ac% - Bc%:
    DimMatrix(mC, rc_matrix[mA].r, rc_matrix[mA].c - rc_matrix[mB].c);

    uint32_t row_offset = 0;
    uint32_t a_offset = 0;
    for(uint32_t row = 0; row < rc_matrix[mB].r; row++)
    {
        row_offset = row*rc_matrix[mB].c;
        a_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mB].c; col++)
        {
            rc_matrix[mB].data[row_offset + col] = rc_matrix[mA].data[a_offset + col];
        }
    }

    for(uint32_t row = 0; row < rc_matrix[mC].r; row++)
    {
        row_offset = row*rc_matrix[mC].c;
        a_offset = row * rc_matrix[mA].c;
        for(uint32_t col = 0; col < rc_matrix[mC].c; col++)
        {
            rc_matrix[mC].data[row_offset + col] = rc_matrix[mA].data[a_offset + (col + rc_matrix[mB].c)];
        }
    }

    return true;
}


// Clears contents of matrix A().
void rc_zeroMatrix (uint32_t mA)
{
    rc_clearMatrix(mA);
}

void rc_getMatrixSize(uint32_t mA, double* r, double* c)
{
    *r = rc_matrix[mA].r;
    *c = rc_matrix[mA].c;
}

void rc_incrementMatrixRows(uint32_t mA, uint32_t mB, uint32_t r, uint32_t num_rows, double value)
{
    if(num_rows < 0)
        return;

    if( r >= rc_matrix[mA].r )
        r = rc_matrix[mA].r -1;

    if( (r+num_rows) >= rc_matrix[mA].r )
        num_rows = rc_matrix[mA].r - r;

    rc_copyMatrix(mA, mB);

    for(int mr = r; mr < (r+num_rows); mr++)
    {
        for(int mc = 0; mc < rc_matrix[mA].c; mc++)
        {
            double mv = rc_matrixValue(mA, mr, mc) + value;
            rc_setMatrixValue(mB, mr, mc, mv);
        }
    }
}

void rc_incrementMatrixColumns(uint32_t mA, uint32_t mB, uint32_t c, uint32_t num_cols, double value)
{
    if(num_cols < 0)
        return;

    if( c >= rc_matrix[mA].c )
        c = rc_matrix[mA].c -1;

    if( (c+num_cols) >= rc_matrix[mA].c )
        num_cols = rc_matrix[mA].c - c;

    rc_copyMatrix(mA, mB);

    for(int mr = 0; mr < rc_matrix[mA].r; mr++)
    {
        for(int mc = c; mc < (c+num_cols); mc++)
        {
            double mv = rc_matrixValue(mA, mr, mc) + value;
            rc_setMatrixValue(mB, mr, mc, mv);
        }
    }
}

void rc_joinMatrixRows(uint32_t mA, uint32_t mB, uint32_t mC)
{
    if(rc_matrix[mA].r != rc_matrix[mB].r)
        return;

    uint32_t num_cols = rc_matrix[mA].c + rc_matrix[mB].c;
    uint32_t num_rows = rc_matrix[mA].r;

    DimMatrix(mC, num_rows, num_cols, false);

    for(int c = 0; c < rc_matrix[mA].c; c++)
    {
        for(int r = 0; r < num_rows; r++)
        {
            double mv = rc_matrixValue(mA, r, c);
            rc_setMatrixValue(mC, r, c, mv);
        }
    }

    for(int c = 0; c < rc_matrix[mB].c; c++)
    {
        for(int r = 0; r < num_rows; r++)
        {
            double mv = rc_matrixValue(mB, r, c);
            rc_setMatrixValue(mC, r, rc_matrix[mA].c + c, mv);
        }
    }
}

void rc_joinMatrixColumns(uint32_t mA, uint32_t mB, uint32_t mC)
{
    if(rc_matrix[mA].c != rc_matrix[mB].c)
        return;

    uint32_t num_cols = rc_matrix[mA].c;
    uint32_t num_rows = rc_matrix[mA].r + rc_matrix[mB].r;

    DimMatrix(mC, num_rows, num_cols, false);

    for(int c = 0; c < num_cols; c++)
    {
        for(int r = 0; r < rc_matrix[mA].r; r++)
        {
            double mv = rc_matrixValue(mA, r, c);
            rc_setMatrixValue(mC, r, c, mv);
        }
    }

    for(int c = 0; c < num_cols; c++)
    {
        for(int r = 0; r < rc_matrix[mB].r; r++)
        {
            double mv = rc_matrixValue(mB, r, c);
            rc_setMatrixValue(mC, rc_matrix[mA].r + r, c, mv);
        }
    }
}



void rc_clipMatrix(int mA, int r, int c, int num_rows, int num_cols, int mB)
{
	int mA_rows = rc_matrix[mA].r;
	int mA_cols = rc_matrix[mA].c;

	int mB_rows = num_rows;
	int mB_cols = num_cols;

	if((r + num_rows) > mA_rows)
		mB_rows = mA_rows - r;

	if(mB_rows < 0)
	{
		DimMatrix(mB, mA_rows, mA_cols, false);
		rc_clearMatrix(mB);
		return;
	}

	if((c + num_cols) > mA_cols)
		mB_cols = mA_cols - c;

	if(mB_cols < 0)
	{
		DimMatrix(mB, mA_rows, mA_cols, false);
		rc_clearMatrix(mB);
		return;
	}

	DimMatrix(mB, mB_rows, mB_cols, false);

	for(int row = r; row < (r+num_rows); row++)
		for(int col = c; col < (c+num_cols); col++)
			rc_setMatrixValue( mB, row-r, col-c, rc_matrixValue(mA, row, col));
}

int rc_convertFromIrrMatrix(irr::core::matrix4 irr_mat, int mB = -1)
{
	int mA = DimMatrix(NEW_MATRIX, 4, 4);

	if(mB < 0)
		mB = DimMatrix(NEW_MATRIX, 4, 4);
	else
		DimMatrix(mB, 4, 4);

	for(int i = 0; i < 4; i++)
	{
		rc_matrix[mA].data[i*4] = irr_mat[i*4];
		rc_matrix[mA].data[i*4+1] = irr_mat[i*4+1];
		rc_matrix[mA].data[i*4+2] = irr_mat[i*4+2];
		rc_matrix[mA].data[i*4+3] = irr_mat[i*4+3];
	}

	rc_transposeMatrix(mA, mB);
	rc_deleteMatrix(mA);
	return mB;
}

irr::core::matrix4 rc_convertToIrrMatrix(int mA)
{
	int mB = DimMatrix(NEW_MATRIX, 4, 4);
	rc_transposeMatrix(mA, mB);

	irr::core::matrix4 irr_mat;

	for(int i = 0; i < 4; i++)
	{
		irr_mat[i*4] = rc_matrix[mB].data[i*4];
		irr_mat[i*4+1] = rc_matrix[mB].data[i*4+1];
		irr_mat[i*4+2] = rc_matrix[mB].data[i*4+2];
		irr_mat[i*4+3] = rc_matrix[mB].data[i*4+3];
	}

	rc_deleteMatrix(mB);
	return irr_mat;
}

void printRCMatrix(int m)
{
	for(int i = 0; i < 4; i++)
		std::cout << "[ " << rc_matrix[m].data[i*4] << ", " << rc_matrix[m].data[i*4+1] << ", " << rc_matrix[m].data[i*4+2] << ", " << rc_matrix[m].data[i*4+3] << " ]" << std::endl;
}


void rc_setMatrixTranslation(int mA, double x, double y, double z)
{
	irr::core::matrix4 m = rc_convertToIrrMatrix(mA);
	m.setTranslation(irr::core::vector3df(x, y, z));
	rc_convertFromIrrMatrix(m, mA);
}

void rc_setMatrixRotation(int mA, double x, double y, double z)
{
	irr::core::matrix4 m = rc_convertToIrrMatrix(mA);
	m.setRotationDegrees(irr::core::vector3df(x, y, z));
	rc_convertFromIrrMatrix(m, mA);
}

void rc_setMatrixScale(int mA, double x, double y, double z)
{
	irr::core::matrix4 m = rc_convertToIrrMatrix(mA);
	m.setScale(irr::core::vector3df(x, y, z));
	rc_convertFromIrrMatrix(m, mA);
}

void rc_getMatrixTranslation(int mA, double* x, double* y, double* z)
{
	irr::core::matrix4 m = rc_convertToIrrMatrix(mA);
	*x = m.getTranslation().X;
	*y = m.getTranslation().Y;
	*z = m.getTranslation().Z;
}

void rc_getMatrixRotation(int mA, double* x, double* y, double* z)
{
	irr::core::matrix4 m = rc_convertToIrrMatrix(mA);
	*x = m.getRotationDegrees().X;
	*y = m.getRotationDegrees().Y;
	*z = m.getRotationDegrees().Z;
}

void rc_getMatrixScale(int mA, double* x, double* y, double* z)
{
	irr::core::matrix4 m = rc_convertToIrrMatrix(mA);
	*x = m.getScale().X;
	*y = m.getScale().Y;
	*z = m.getScale().Z;
}

#endif // RC_MATRIX_H_INCLUDED
