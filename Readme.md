

# Vector & Matrix Calculator 🚀

## 🖥️ Overview 
This project is a C++ library that implements data types for vectors and matrices, offering a comprehensive set of mathematical operations commonly used in various applications.
#### Usage
1. Click on the **Option** button in the UI.
2. Select **Load Data** to load a text file containing vectors and/or matrices.
3. Input the desired operation in the Command column.
4. Press the **Execute** button to perform the operation.

![](./demo/overview.png)


#### Data Format
The input text file can contain two data types: vectors and matrices. Each row in the text file represents a vector or a matrix in the following format:

#### - Vector
To represent a vector, use the following format:
- `{dimension}`: The dimension of the vector (number of elements).
- `{value1} {value2} ... {valueN}`: The values of the vector's elements.
```cpp
// V {dimention} {value}
V 3 1 2 3
```
$$
v=\begin{bmatrix} 1 \\ 2 \\ 3 \end{bmatrix}
$$

#### - Matrix
To represent a matrix, use the following format:
- `{rows}`: The number of rows in the matrix.
- `{cols}`: The number of columns in the matrix.
- `{value1} {value2} ... {valueN}`: The values of the matrix elements in row-major order.
```cpp
// M {rows} {cols} {value}
M 3 2 0 1 2 3 4 5 // row=3, col=2
```
$$
m=
\begin{bmatrix}
0 & 1 \\
2 & 3 \\
4 & 5 \\
\end{bmatrix}
$$

## 📄 Vector Library 

#### ➕ Operators 
This section introduces vector operator functions that perform element-wise operations on vectors. If one of the input vectors is 1D, the operation will be a **scalar operation**.

| Operator | Description | Input | Output |
|---|---|---|---|
| `+` | Element-wise addition of vectors. | $\vec{a}, \vec{b} \in \mathbb{R}^n$ | $\vec{v} \in \mathbb{R}^n$ |
| `-` | Element-wise subtraction of vectors. | $\vec{a}, \vec{b} \in \mathbb{R}^n$ | $\vec{v} \in \mathbb{R}^n$ |
| `*` | Element-wise product of vectors. | $\vec{a}, \vec{b} \in \mathbb{R}^n$ | $\vec{v} \in \mathbb{R}^n$ |


#### 🔧 Functions 
The following functionalities have been implemented in the vector functions:

|Function|Description|Input|Output|
|-|-|-|-|
|`dot(a, b)`|[Compute the dot product of two vectors.](https://en.wikipedia.org/wiki/Dot_product)|$\vec{a}, \vec{b} \in \mathbb{R}^n$| $\vec{v} \in \mathbb{R}^n$|
|`norm(a)`|Calculate the norm (magnitude) of a vector.|$\vec{a} \in \mathbb{R}^n$| $\vec{v} \in \mathbb{R}^1$|
|`normal(a)`|Normalize a vector to a unit vector.|$\vec{a} \in \mathbb{R}^n$| $\vec{v} \in \mathbb{R}^n$|
|`cross(a, b)`|Compute the cross product of two 3D vectors.|$\vec{a}, \vec{b} \in \mathbb{R}^3$| $\vec{v} \in \mathbb{R}^3$|
|`com(a, b)`|Find the component of vector a along vector b.|$\vec{a}, \vec{b} \in \mathbb{R}^n$| $\vec{v} \in \mathbb{R}^1$|
|`proj(a, b)`|Compute the projection of vector a onto vector b.|$\vec{a}, \vec{b} \in \mathbb{R}^n$| $\vec{v} \in \mathbb{R}^n$|
|`area(a, b)`|Calculate the area of the triangle formed by vectors a and b.|$\vec{a}, \vec{b} \in \mathbb{R}^n, n\in\{2,3\}$| $\vec{v} \in \mathbb{R}^1$|
|`angle(a, b)`|Determine the angle (in radians) between two vectors.|$\vec{a}, \vec{b} \in \mathbb{R}^n$| $\vec{v} \in \mathbb{R}^1$|
|`pn(a, b)`|Compute the normal vector of the plane formed by two 3D vectors.|$\vec{a}, \vec{b} \in \mathbb{R}^3$| $\vec{v} \in \mathbb{R}^3$|
|`ob(a, b, c ...)`|Use Gram-Schmidt process to find orthonormal basis from multiple vectors.|$\vec{a}, \vec{b}, \vec{c}, \ldots  \in \mathbb{R}^n$| String `Vector array (not for operation)`|

**Judgement Functions 🔧**
This section includes functions to assess the relationship between two vectors.
|Function|Description|Input|Output|
|-|-|-|-|
|`isparallel(a, b)`|Checks if vectors a and b are parallel.|$\vec{a}, \vec{b} \in \mathbb{R}^n$|String: `Yes` or `No`|
|`isorthogonal(a, b)`|Checks if vectors a and b are orthogonal.|$\vec{a}, \vec{b} \in \mathbb{R}^n$|String: `Yes` or `No`|
|`isli(a, b)`|Checks if vectors a and b are linearly independent.|$\vec{a}, \vec{b} \in \mathbb{R}^n$|String: `Yes` or `No`|


## 📄 Matrix Library 

#### ➕ Operators 
If one of the matrices has a size of 1x1, the library will perform a **scalar product**, which is a special operation that treats the matrix as a scalar value.

| Operator | Description | Input | Output |
|---|---|---|---|
| `+` | Element-wise addition. | $\mathbf{A} \in \mathbb{R}^{n \times m}$, $\mathbf{B} \in \mathbb{R}^{n \times m}$ | $\mathbf{C} \in \mathbb{R}^{n \times m}$ |
| `-` | Element-wise subtraction. | $\mathbf{A} \in \mathbb{R}^{n \times m}$, $\mathbf{B} \in \mathbb{R}^{n \times m}$ | $\mathbf{C} \in \mathbb{R}^{n \times m}$ |
| `*` | [Element-wise product.](https://en.wikipedia.org/wiki/Hadamard_product_(matrices)) | $\mathbf{A} \in \mathbb{R}^{n \times m}$, $\mathbf{B} \in \mathbb{R}^{n \times m}$ | $\mathbf{C} \in \mathbb{R}^{n \times m}$ |

#### 🔧 Functions 
|Function|Description|Input|Output|
|-|-|-|-|
|`matmul(A, B)`| Performs [matrix multiplication](https://en.wikipedia.org/wiki/Matrix_multiplication) between two matrices A and B. | $A \in \mathbb{R}^{l \times m}$, $B \in \mathbb{R}^{m \times n}$ | $C \in \mathbb{R}^{l \times n}$ |
|`rank(A)`| Calculates the [rank of a matrix](https://byjus.com/jee/rank-of-a-matrix-and-special-matrices/). | $A \in \mathbb{R}^{m \times n}$ | $C \in \mathbb{R}^{1 \times 1}$ |
|`trans(A)`| Computes the [transpose of a matrix](https://en.wikipedia.org/wiki/Transpose) A. | $A \in \mathbb{R}^{m \times n}$ | $C ^\mathrm{T}\in \mathbb{R}^{m \times n}$ |
|`solve(A, B)`| Solves a [linear system of equations](https://www.mathsisfun.com/algebra/systems-linear-equations-matrices.html) of the form $Ax = B$. | $A \in \mathbb{R}^{n \times n}$, $B \in \mathbb{R}^{n \times 1}$  | $x \in \mathbb{R}^{n \times 1}$ |
|`det(A)`|Calculates the [determinant of a Matrix](https://www.mathsisfun.com/algebra/matrix-determinant.html)|$A \in \mathbb{R}^{n \times n}$|$C \in \mathbb{R}^{1 \times 1}$|
|`inverse(A)`|Finds the [inverse matrix](https://www.mathsisfun.com/algebra/matrix-inverse.html) of a square matrix A.|$A \in \mathbb{R}^{n \times n}$|$C \in \mathbb{R}^{n \times n}$ |
|`adj(A)`|Computes the [adjoint of a matrix](https://en.wikipedia.org/wiki/Adjugate_matrix)|$A \in \mathbb{R}^{n \times n}$| $C \in \mathbb{R}^{n \times n}$|
|`pm(A)`|Finds Largest Eigenvalue and Eigenvector by using the [power method](https://youtu.be/EGNuu2LFeeM)|$A \in \mathbb{R}^{n \times n}$| String: `Eigenvalue` and `Eigenvector`|
|`leastq`|Applies [The Method of Least Squares](https://math.libretexts.org/Bookshelves/Linear_Algebra/Interactive_Linear_Algebra_(Margalit_and_Rabinoff)/06%3A_Orthogonality/6.5%3A_The_Method_of_Least_Squares)|$A \in \mathbb{R}^{n \times n}$, $B \in \mathbb{R}^{n \times 1}$   |  $x \in \mathbb{R}^{n \times 1}$  |
|`rref(A)`|Converts matrix A to its [reduced row echelon form.](https://www.statlect.com/matrix-algebra/reduced-row-echelon-form)|$A \in \mathbb{R}^{m \times n}$| $C \in \mathbb{R}^{m \times n}$|


## 🔍 Customization Guide

#### Adding or Modifying Functions

To add a new function or change the usage of existing functions, follow these steps:

**1. Implement a Subclass of `ICommand` in Command.h**
+ Create a new subclass of `ICommand` in the `Command.h` file. Make sure to override the `operate` method to define the functionality of your command. For example:

```cpp
class YourCommand : public ICommand {
public:
    YourCommand() {
        operand_count_ = 2;
        return_type_ = ReturnType::Operand; // or ReturnType::String
    }

    Vector operate(std::vector<Vector>& operands) override;
};
```

**2. Register Your Command**

In the `WindowsForm.h` file, locate the `InitializeCommands()` function, and register your newly implemented command using the `command_factory->RegisterCommand()` method. This step ensures that your command becomes available in the application. For example:

```cpp
void InitializeCommands() {
    command_factory = new CommandFactory();
    // Existing vector commands
    command_factory->RegisterCommand("dot", std::make_shared<DotCommand>());
    // ...
    // Register your custom command
    command_factory->RegisterCommand("yourcommand", std::make_shared<YourCommand>());
}
```

By following these steps, you can easily add new mathematical functions or modify the behavior of existing functions within the application.