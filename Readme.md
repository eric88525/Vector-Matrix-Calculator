

# 工程數學 PJ1
[GIT](https://github.com/eric88525/PJ1)

# ==Vector==
### printV
```
    printV ($v[0])
```
### 1-4. calV a*b
1. Dot of Vector(1%) OK
1. Vector addition(1%) OK
1. Scalar Multiplication with vector (1%) OK
```
    calV ($v[0]+$v[1]+$v[2]+$v[3])
    calV ($v[4]+$v[5])*$v[6]*$v[7]
    calV ($v[8]+$v[9]+$v[10]+$v[11]+$v[12])*$v[13]
    calV ($v[0]*$v[1]
```
### 5. Norm(a)
* Norm of Vector (2%)
### 6. Normal(a) 
* Vector normalization (2%)
### 7. Cross(a,b)
* Cross product (2%)
```
    Cross ($v[0],$v[1])
```
### 8. Com(a,b)
* Component of a on b (2%)
```
    Com ($v[0],$v[1])
```
### 9. Proj(a,b) 
* Projection of a on b (2%)
```
    Proj ($v[0],$v[1])
    Proj ($v[2],$v[3])
```
### 10. Area(a,b)
* Triangle area (2%)
```
    Area($v[0],$v[1])
```
### 11. isParallel(a,b)
* Parallel judgement(2%)
```
    isParallel ($v[0],$v[1])
    isParallel ($v[2],$v[3])
    isParallel ($v[4],$v[5])
    isParallel ($v[6],$v[7])
```
### 12. isOrthogonal(a,b)
* Orthogonal judgement(5%)
```
    isOrthogonal ($v[0],$v[1])
    isOrthogonal ($v[2],$v[3])
    isOrthogonal ($v[4],$v[5])
    isOrthogonal ($v[6],$v[7])
```
### 13. angle(a,b) 
* The angle between two vectors(degree) (3%)
```
    angle ($v[0],$v[1])
    angle ($v[2],$v[3])
    angle ($v[4],$v[5])
    angle ($v[6],$v[7])
```
### 14. pN OK 
* The plane normal that is produced by two vectors (5%)
```
    PN ($v[0],$v[1])
    PN ($v[2],$v[3])
    PN ($v[4],$v[5])
```
### 15. IsLI(a,b)
* Linear independent judgement(10%)
```

```
### 16. Ob(a,b,c,d....)
* Use Gram-schmidt to find orthonormal basis(10%)
```
    Ob ($v[0],$v[1],$v[2])
    Ob ($v[3],$v[4],$v[5],$v[6],$v[7])
```

# ==Matrix==
### printM
```
    printM ($m[0])
```
### 1-2. calM() 
* Matrix addition & subtraction(2%)
* Matrix Multiplication(2%)
```
    calM $m[0]+$m[1]
```
### 3. Rank(m) 
* Rank of Matrix(5%)
### 4. Trans(m)
Matrix Transpose(2%)
### 5. Sol (a,b)
Solve Linear System(5%)
```
    Sol ($m[0],$m[1])
```
### 6. det(m)
Determinants of Matrix(3%)
### 7. Inverse(m)
Inverse Matrix(6%)
```
    Inverse ($m[0])
```
### 8. Adj(m)
Adjoint of Matrix(3%)
```
    Adj ($m[0])
```
### 9. eigen(a)
Eigen Vector and Eigen Value(10%)
```
    eigen ($m[0])
    eigen ($m[1])
    eigen ($m[2])
```
### 10. PM(m)
Power Method of Eigen value(6%)
```
    PM ($m[0])
```
### 11. LeastSquare(m1,m2)
Method of Least Square(6%)
```
    LeastSquare ($m[0],$m[1])
    LeastSquare ($m[2],$m[3])
    LeastSquare ($m[4],$m[5])
    LeastSquare ($m[6],$m[7])
```
### 12 rref(M)
```
    rref ($m[0])
```

