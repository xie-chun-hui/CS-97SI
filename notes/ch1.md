# Mathematics

## Algebra

### Sum of Powers 

$$
\sum_{k=1}^{n} k^2 = \frac{1}{6}n(n+1)(2n+1) \\
\sum_{k=1}^{n} k^3 = (\sum_{k=1}^{n} k)^2=(\frac{1}{2}n(n+1))^2
$$

### Fast Exponentiation

$$
a^n = 
\left\{\begin{matrix}
1  & n=0\\
a & n=1\\
(a^{n/2})^2  & \text{n is even}\\
 a(a^{(n-1)/2})^2 & \text{n is odd}&
\end{matrix}\right.
$$



```cpp
// recursive
double pow(double a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    double t = pow(a, n / 2);
    return t * t * pow(a, n % 2);
}
// non-recursive
double pow2(double a, int n)
{
    double ret = 1;
    while (n)
    {
        if (n % 2 == 1)
            ret *= a;
        a *= a;
        n /= 2;
    }
    return ret;
}
```

Running time: $O(\log n)$

## Number Theory

### Greatest Common Divisor (GCD)

 $gcd(a, b)$: greatest integer divides both $a$ and $b$

* $\gcd(a, b) = \gcd(a, b − a)$
* $\gcd(a, 0) = a$
* $\gcd(a, b)$ is the smallest positive number in $\{ax + by|x,y \in Z\}$

```cpp
int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
```

Running time: $O(\log(a + b))$

### Congruence & Modulo Operation

* $x \equiv y \pmod{n}$ means $x$ and $y$ have the same remainder when divided by $n$

* Multiplicative inverse
  * $x^{-1}$ is the inverse of x modulo n if $xx^{-1} \equiv 1\pmod{n}$
  * May not exist
  * Exists if and only if $gcd(x,n)=1$
  
  ```cpp
  int modInverse(int a, int m)
  {
      int m0 = m;
      int y = 0, x = 1;
      if(m == 1)
          return 0;
      while (a > 1)
      { 
          int q = a / m; 
          int t = m; 
          m = a % m, a = t; 
          t = y;   
          y = x - q * y; 
          x = t; 
      }
      if (x < 0)
          x += m0; 
      return x; 
  }
  ```

### Extended Euclidean Algorithm

keep the original algorithm, but write all intermediate numbers as integer combinations of a and b.
$$
ax + by = \gcd(a, b)
$$

```cpp
int gcdExtended(int a,int b, int* x, int * y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;  
    *y = x1;
    return gcd;  
}
```

### Chinese Remainder Theorem

* Given $a,b,m,n$ with $gcd(m,n)=1$
* Find $x$ with $x \equiv a(mod\ m)$ and $a \equiv b(mod\ n)$
* Solution:
  * Let $n^{-1}$ be the inverse of $n$ modulo $m$
  * Let $m^{-1}$ be the inverse of $m$ modulo n
  * Set $x=ann^{-1} + bmm^{-1}$

```cpp
int CRT(int num[], int rem[], int k)
{
    long long prod = 1;
    for (int i = 0; i < k; i++)
    {
        prod *= num[i];
    }
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        long long pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}
```

## Combinatorics

$\begin{pmatrix} p\\\ x \end{pmatrix}$ is the number of ways to choose $k$ objects out of $n$ distinguishable objects.

* Compute using the following formula

$$
\begin{pmatrix} 
p\\ 
x 
\end{pmatrix}
=\frac{n(n-1)\dots (n-k+1)}{k!}
$$

* Use Pascal’s triangle

### Fibonacci Sequence

Definition:

* $F_0 = 0, F_1 = 1$
* $F_n = F_{n-1} + F_{n-2}$

Closed Form:
$$
F_n = \frac{1}{\sqrt{5}}(\varphi^n -\bar{\varphi }^n)\\
\varphi = \frac{1+\sqrt{5}}{2} \\
\bar{\varphi} = \frac{1-\sqrt{5}}{2}
$$
Matrix Form:
$$
\begin{bmatrix}
F_{n+1} \\
F_n
\end{bmatrix} = 
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}
\begin{bmatrix}
F_{n} \\
F_{n-1}
\end{bmatrix} =
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}^n
\begin{bmatrix}
F_{n} \\
F_{n-1}
\end{bmatrix}
$$

## Geometry

### 2D Vector Operations

* Vector : $(x,y)$

* Norm : $\sqrt{x^2+y^2}$

* Counterclockwise rotation by $\theta$ :
  $$
  \begin{bmatrix}
  \cos\theta & -\sin\theta \\
  \sin\theta & \cos\theta
  \end{bmatrix}
  \begin{bmatrix}
  x \\
  y
  \end{bmatrix}
  $$

### Line-Line Intersection

* Have two lines : $ax+by+c=0$ and $dx+ey+f=0$
  $$
  \begin{bmatrix}
  a & b \\
  d & e
  \end{bmatrix}
  \begin{bmatrix}
  x \\
  y
  \end{bmatrix} = -
  \begin{bmatrix}
  c \\
  f
  \end{bmatrix}
  $$

* Left-multiply by matrix inverse
  $$
  \begin{bmatrix}
  a & b \\
  d & e
  \end{bmatrix}^{-1}=
  \frac{1}{ae-bd}
  \begin{bmatrix}
  e & -b \\
  -d & a
  \end{bmatrix}
  $$

* Edge case: $ae = bd$

### Circumcircle of a Triangle

* Have three points $A, B, C$

* Want to compute the area $S$ of triangle $ABC$
  $$
  2S = |(B-A)\times (C-A)|
  $$

* Cross product:
  $$
  (x_1,y_1)\times (x_2,y_2)=
  \begin{bmatrix}
  x_1 & x_2 \\
  y_1 & y_2
  \end{bmatrix} = x_1y_2 - x_2y_1
  $$
  

### Area of a Simple Polygon

* Given vertices $P_1, P_2,\dots, P_n$ of polygon $P$

* If $P$ is convex, we can decompose $P$ into triangles:
  $$
  2S=|\sum_{i=2}^{n-1}(P_{i+1}-P_1)\times(P_i - P_1)|
  $$
  