

# Vector & Matrix caculator

## Input Format

**Vector**
```cpp
// V {dimention} {value}
V 3 1 2 3
```
**Matrix**
```cpp
// M {row} {col} {value}
M 3 2 0 1 2 3 4 5
```

## Vector Function
+ a, b is expression, for example `v[0]+v[1]*(v[2]-v[3])`

|Command|Description|Example| Output |
|-|-| -| -|
|`printv(a)`|Print vector.|`printv(v[0])`| Vector|
|`norm(a)`|Norm of Vector.|`norm(v[0])`| Double value|
|`normal(a)`|Vector normalization.|`normal(v[0])`| Vector|
|`cross(a, b)`|Cross product.|`cross(v[0],v[1]+v[2])`| Vector|
|`com(a, b)`|Component of a along b.|`com(v[0],v[1])`| Double value|
|`proj(a, b)`|Projection of a on b.|`proj(v[0],v[1])`| Vector|
|`Area(a, b)`|Area of triangle formed by vector a and vector b. |`area(a,b)`| Double value|
|`angle(a, b)`|Angle between two vectors.|`angle(v[0],v[1])`| Double value|
|`pn(a, b)`|The plane normal that is produced by two vectors|`pn(v[0],v[1])`| Vector|
|`ob(a, b, c ...)`|Use Gram-schmidt to find orthonormal basis|`ob($v[0],$v[1],$v[2]`| Vector array|
## Vector judgement
|Command|Description|Example| Output |
|-|-| -| -|
|`isparallel(a,b)`|Parallel judgement.|`isparallel(v[0],v[1])`|Yes,No|
|`isorthogonal(a,b)`|Orthogonal judgement.|`isorthogonal(v[0],v[1])`|Yes,No|
|`isli(a, b)`|Linear independent judgement|`isli(v[0], v[1])`| Yes, No|
## Vector Operator
|Command|Description|Example|
|-|-| -|
|+|向量相加|`printv (v[0]+v[1]+v[2])`|
|-|向量相減|`printv (v[0]-v[1]-v[2])`|
|\*|向量 dot product| `printv (v[0]*v[1])`|

# Matrix
### printM
```
printM ($m[0])
```
### calM() 
* Matrix addition & subtraction(2%)
* Matrix Multiplication(2%)
```
calM $m[0]+$m[1]
```
### Rank(m) 
* Rank of Matrix(5%)
### Trans(m)
Matrix Transpose(2%)
###  Sol (a,b)
Solve Linear System(5%)
```
Sol ($m[0],$m[1])
```
### det(m)
Determinants of Matrix(3%)
### Inverse(m)
Inverse Matrix(6%)
```
Inverse ($m[0])
```
### Adj(m)
Adjoint of Matrix(3%)
```
Adj ($m[0])
```
### eigen(a)
Eigen Vector and Eigen Value(10%)
```
eigen ($m[0])
eigen ($m[1])
eigen ($m[2])
```
### PM(m)
Power Method of Eigen value(6%)
```
PM ($m[0])
```
### LeastSquare(m1,m2)
Method of Least Square(6%)
```
LeastSquare ($m[0],$m[1])
LeastSquare ($m[2],$m[3])
LeastSquare ($m[4],$m[5])
LeastSquare ($m[6],$m[7])
```
### rref(M)
```
rref ($m[0])
```

